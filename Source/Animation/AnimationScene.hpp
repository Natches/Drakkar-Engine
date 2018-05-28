#pragma once

#include <vector>
#include <mutex>
#include <Core/Utils/ClassUtils.hpp>
#include <Core/Engine/Types.hpp>
#include <Math/Matrix4x4.fwd>
#include <Math/Vec3.fwd>
#include <Threading/Task/TaskGroup.hpp>

#define HIGH_TIME 1 //in Update
#define MIDDLE_TIME 4
#define LOW_TIME 8
#define LOWER_TIME 24
#define HIGH_DISTANCE 40
#define MIDDLE_DISTANCE 80
#define LOW_DISTANCE 120
#define LOWER_DISTANCE 200

namespace drak {
class LevelSystem;
namespace components {
struct Animator;
} //namespace components
namespace animation {
class Animator;

class AnimationScene final {
	DK_SERIALIZED_OBJECT(AnimationScene)
	friend class LevelSystem;
	using func = typename function::MemberFunction<AnimationScene, void, const std::vector<U32>>;
public:
	AnimationScene();
	void update(const F32 deltatime, const math::Vec3f& camPos, const math::Vec3f& camDir);
	DK_GETTER_REF_C(std::vector<components::Animator>, animators, m_components)
	DK_GETTER_REF_C(std::vector<std::vector<math::Mat4f>>, matricies, m_lastFrameMatricies)
private:
	~AnimationScene() = default;

	void CheckDistance(const math::Vec3f& camPos, const math::Vec3f& camDir);

	void UpdateMatrix(const std::vector<U32> priority);

private:
	LevelSystem& m_level;
	std::vector<components::Animator>& m_components;
	std::vector<U32> m_highPriority, m_middlePriority, m_lowPriority, m_lowerPriority;
	std::vector<std::vector<math::Mat4f>> m_lastFrameMatricies;
	U8 m_updateCount;
	U8 m_highPriorityUpdateTime   = HIGH_TIME;
	U8 m_middlePriorityUpdateTime = MIDDLE_TIME;
	U8 m_lowPriorityUpdateTime    = LOW_TIME;
	U8 m_lowerPriorityUpdateTime  = LOWER_TIME;
	U16 m_highDistance            = HIGH_DISTANCE;
	U16 m_middleDistance          = MIDDLE_DISTANCE;
	U16 m_lowDistance             = LOW_DISTANCE;
	U16 m_lowerDistance           = LOWER_DISTANCE;
	thread::task::TaskGroup<thread::task::Task<func>> m_grp;
	F32 m_time;
};

} // namespace animation
} // namespace drak

DK_METADATA_BEGIN(drak::animation::AnimationScene)
DK_PUBLIC_FIELDS(m_highPriority, m_middlePriority, m_lowPriority, m_lowerPriority,
	m_updateCount, m_highPriorityUpdateTime, m_middlePriorityUpdateTime, m_lowPriorityUpdateTime, m_lowerPriorityUpdateTime,
	m_highDistance, m_middleDistance, m_lowDistance, m_lowerDistance);
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END