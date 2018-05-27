#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace animation {

class Skeleton;

class Animator final {
public:
	Animator() = delete;
	Animator(const Skeleton& skeleton, const std::string& anim);
	Animator(const Skeleton& skeleton, const std::string& anim, const F32 speed);
	~Animator() = default;

	void advance(const F32 deltaTime);
	std::vector<math::Mat4f> frameMatricies();

	DK_SETTER_REF_C(std::string, animation,
		const Animation* anim = m_skeleton.animationByName(m_animation);
		if (anim)
			m_timeBetweenTwoFrame = (F32)anim->frameCount() / anim->animationDuration();
		m_animation)
	DK_SETTER(F32, speed, m_speed)
private:
	void buildGlobalTransformation(std::vector<math::Mat4f>& transformation, const Bone& b,
		const Animation* animation, I32 i, const math::Mat4f& parentTransform);
	Joint interpolateJoints(const Joint& j1, const Joint& j2, const F32 time);

private:
	std::string m_animation;
	const Skeleton& m_skeleton;
	F32 m_speed;
	F32 m_time;
	F32 m_timeBetweenTwoFrame;
	U32 m_frame;
};

} // namespace animation
} // namespace drak