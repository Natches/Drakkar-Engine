#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace components {
struct Animator;
} //namespace components
namespace animation {

class Skeleton;


class Animator final {
	DK_SERIALIZED_OBJECT(Animator)
public:
	Animator();
	~Animator() = default;

	void advance(const F32 deltaTime, const components::Animator& animator, const Skeleton& skeleton);
	std::vector<math::Mat4f> frameMatricies(const std::string& animation, const Skeleton& skeleton);

private:
	void buildGlobalTransformation(std::vector<math::Mat4f>& transformation, const Bone& b,
		const Animation* animation, const math::Mat4f& parentTransform,
		const Skeleton& skeleton);
	Joint interpolateJoints(const Joint& j1, const Joint& j2, const F32 time);

private:
	F32 m_time;
	F32 m_normalizedTime;
	F32 m_timeBetweenTwoFrame;
	U32 m_frame;
};

} // namespace animation
} // namespace drak

DK_METADATA_BEGIN(drak::animation::Animator)
DK_PUBLIC_FIELDS(m_time, m_timeBetweenTwoFrame, m_frame)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END