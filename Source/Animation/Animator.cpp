#include <PrecompiledHeader/pch.hpp>
#include <Animation/Animator.hpp>

namespace drak {
namespace animation {

Animator::Animator() : m_time(0.f), m_frame(0) {
}


void Animator::advance(const F32 deltaTime, const components::Animator& animator,
	const Skeleton& skeleton) {
	m_time += deltaTime * animator.speed;
	const Animation* anim = skeleton.animationByName(animator.animation());
	if (anim) {
		if (animator.dirty())
			m_timeBetweenTwoFrame = (F32)anim->frameCount() / anim->animationDuration();
		m_normalizedTime = m_time / m_timeBetweenTwoFrame;
		while (m_time > m_timeBetweenTwoFrame) {
			m_time -= m_timeBetweenTwoFrame;
			++m_frame;
		}
		m_frame %= anim->frameCount();
	}
}

std::vector<math::Mat4f> Animator::frameMatricies(const std::string& animation, const Skeleton& skeleton) {
	std::vector<math::Mat4f> finalMatricies;
	finalMatricies.resize(skeleton.boneCount(), skeleton.invGlobal());
	const Animation* anim = skeleton.animationByName(animation);
	if (anim) {
		buildGlobalTransformation(finalMatricies, skeleton.root(),
			anim, math::Identity<F32>(), skeleton);
	}
	return finalMatricies;
}

void Animator::buildGlobalTransformation(std::vector<math::Mat4f>& transformation, const Bone& b,
	const Animation* animation, const math::Mat4f& parentTransform, const Skeleton& skeleton) {
	Joint j1, j2;

	if (animation->frames()[m_frame].jointByName(b.name, j1) != DK_OK)
		skeleton.jointByName(b.name, j1);
	if (animation->frames()[m_frame + 1 == animation->frameCount() ? 0 : m_frame + 1].jointByName(b.name, j2) != DK_OK)
		skeleton.jointByName(b.name, j2);

	//j1 = interpolateJoints(j1, j2, m_normalizedTime);

	math::Mat4f Global = parentTransform * (j1.rot.matrix() * math::Translate(j1.pos));

	U32 temp;
	skeleton.idxByName(b.name, temp);
	transformation[temp] = Transpose(skeleton.invGlobal() * Global * b.offsetMatrix);

	for (auto& child : b.children) {
		skeleton.idxByName(child, temp);
		buildGlobalTransformation(transformation, skeleton.bone(temp), animation, Global, skeleton);
	}
}

Joint Animator::interpolateJoints(const Joint& j1, const Joint& j2, const F32 time) {
	return Joint{ math::Lerp(j1.pos, j2.pos, time),
		math::SLerp(j1.rot, j2.rot, time) };
}

} // namespace animation
} // namespace drak