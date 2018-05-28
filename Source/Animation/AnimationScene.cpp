#include <PrecompiledHeader/pch.hpp>
#include <Animation/Animator.hpp>
#include <Animation/AnimationScene.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Animation/Geometry/SkinnedMesh.hpp>
#include <Engine/GameObject.hpp>

namespace drak {
namespace animation {

AnimationScene::AnimationScene() : m_grp(core::Engine::Get().m_pool),
	m_level(core::Engine::Get().currentLevel()), m_time(0.f),
	m_components(m_level.getComponentContainerByType<components::Animator>()) {
}

void AnimationScene::update(const F32 deltatime, const math::Vec3f& camPos, const math::Vec3f& camDir) {
	bool firstUpdate = !m_time;
	if(firstUpdate)
		CheckDistance(camPos, camDir);
	++m_updateCount;
	m_lastFrameMatricies.resize(m_components.size());
	for (auto& cmp : m_components) {
		const components::Model* mdl =
			m_level.getGameObjects()[cmp.GameObjectID].getComponent<components::Model>();
		SkinnedMeshPtr skMesh = m_level.m_resourceManager->loadOrGet<geom::SkinnedMesh>(mdl->name);
		cmp.animator.advance(deltatime, cmp, skMesh->resource().skeleton());
	}
	if (!(m_updateCount % m_highPriorityUpdateTime) || firstUpdate)
		m_grp.registerTask(thread::task::Task<func>(func(this, &AnimationScene::UpdateMatrix,
		(const std::vector<U32>)m_highPriority)));

	if (!(m_updateCount % m_middlePriorityUpdateTime) || firstUpdate)
		m_grp.registerTask(thread::task::Task<func>(func(this, &AnimationScene::UpdateMatrix,
		(const std::vector<U32>)m_middlePriority)));

	if (!(m_updateCount % m_lowPriorityUpdateTime) || firstUpdate)
		m_grp.registerTask(thread::task::Task<func>(func(this, &AnimationScene::UpdateMatrix,
		(const std::vector<U32>)m_lowPriority)));

	if (!(m_updateCount % m_lowerPriorityUpdateTime) || firstUpdate) {
		m_grp.registerTask(thread::task::Task<func>(func(this, &AnimationScene::UpdateMatrix,
			(const std::vector<U32>)m_lowerPriority)));
		m_updateCount = 0;
	}
	m_grp.sendGroupToThreadPool();
	if(!firstUpdate)
		CheckDistance(camPos, camDir);
	m_grp.waitForTasks();
	m_grp.clearGroup<false>();
}

void AnimationScene::CheckDistance(const math::Vec3f& camPos, const math::Vec3f& camDir) {
	m_highPriority.clear();
	m_middlePriority.clear();
	m_lowPriority.clear();
	m_lowerPriority.clear();
	std::vector<GameObject>& gameObjects = m_level.getGameObjects();
	U32 i = 0;
	for (auto& cmp : m_components) {
		const math::Vec3f& pos = gameObjects.at(cmp.GameObjectID).
			getComponent<components::Transform>()->getGlobalPosition();
		bool opposed = math::AreOpposed(camDir, math::Direction(camPos, pos));
		if (!opposed) {
			F32 dist = math::Distance(camPos, pos);
			if (dist < m_highDistance)
				m_highPriority.emplace_back(i);
			else if (dist > m_highDistance && dist < m_middleDistance)
				m_middlePriority.emplace_back(i);
			else if (dist > m_middleDistance && dist < m_lowDistance)
				m_lowPriority.emplace_back(i);
			else if (dist > m_lowDistance && dist < m_lowerDistance)
				m_lowerPriority.emplace_back(i);
		}
		++i;
	}
}

void AnimationScene::UpdateMatrix(const std::vector<U32> priority) {
	for (auto& pr : priority) {
		components::Animator& anim = m_components[pr];
		const components::Model* mdl =
			m_level.getGameObjects()[anim.GameObjectID].getComponent<components::Model>();
		SkinnedMeshPtr skMesh = m_level.m_resourceManager->loadOrGet<geom::SkinnedMesh>(mdl->name);
		m_lastFrameMatricies[pr] = anim.animator.frameMatricies
		(anim.animation(), skMesh->resource().skeleton());
	}
}

} // namespace animation
} // namespace drak