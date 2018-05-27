#include <PrecompiledHeader/pch.hpp>
#include <Animation/Animator.hpp>

namespace drak {
namespace animation {

Animator::Animator(const Skeleton& skeleton, const std::string& anim) : m_skeleton(skeleton),
	m_animation(anim), m_speed(1.f), m_time(0.f), m_frame(0) {
}

Animator::Animator(const Skeleton& skeleton, const std::string& anim, const F32 speed)
	: m_skeleton(skeleton), m_animation(anim), m_speed(speed), m_time(0.f), m_frame(0) {
}

void Animator::advance(const F32 deltaTime) {
	m_time += deltaTime * m_speed;
	const Animation* anim = m_skeleton.animationByName(m_animation);
	if (anim) {
		while (m_time > m_timeBetweenTwoFrame) {
			m_time -= m_timeBetweenTwoFrame;
			++m_frame;
		}
		m_frame % anim->frameCount();
	}
}

std::vector<math::Mat4f> Animator::frameMatricies() {
	std::vector<math::Mat4f> finalMatricies;
	finalMatricies.resize(m_skeleton.boneCount(), m_skeleton.invGlobal());
	const Animation* anim = m_skeleton.animationByName(m_animation);
	if (anim) {
		buildGlobalTransformation(finalMatricies, m_skeleton.base(),
			anim, 0, math::Identity<F32>());
	}
	return finalMatricies;
}

void Animator::buildGlobalTransformation(std::vector<math::Mat4f>& transformation, const Bone& b,
	const Animation* animation, I32 i, const math::Mat4f& parentTransform) {
	Joint j1, j2;

	if (animation->frames[m_frame].jointByName(b.name, j1) != DK_OK)
		m_skeleton.jointByName(b.name, j1);
	if (animation->frames[m_frame + 1 == animation->frameCount() ? 0 : m_frame + 1].jointByName(b.name, j2) != DK_OK)
		m_skeleton.jointByName(b.name, j2);

	j1 = interpolateJoints(j1, j2, m_time);

	m_skeleton.jointByName(b.name, j2);

	math::Mat4f Global = parentTransform *
		(math::Translate(j1.pos) * j1.rot.matrix() * math::Scale(j1.scale));

		transformation[i] *= (Global *
			(math::Translate(j2.pos) * j2.rot.matrix() * math::Scale(j2.scale)));

	for (auto& child : b.children)
		buildGlobalTransformation(transformation, child, animation, ++i, Global);
}

Joint Animator::interpolateJoints(const Joint& j1, const Joint& j2, const F32 time) {
	return Joint{ math::Lerp(j1.pos, j2.pos, time),
		math::Lerp(j1.scale, j2.scale, time),
		math::SLerp(j1.rot, j2.rot, time) };
}

} // namespace animation
} // namespace drak