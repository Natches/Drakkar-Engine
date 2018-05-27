#pragma once

#include <string>
#include <vector>
#include <Core/Utils/ClassUtils.hpp>
#include <Animation/KeyFrame/KeyFrame.hpp>

namespace drak {
namespace animation {

class Skeleton;

class Animation final {

	DK_NOMOVE_NOCOPY_OP(Animation)

public:
	Animation() = delete;
	Animation(const Animation& anim);
	Animation(Animation&& anim);

	DK_GETTER_REF_C(std::string, name, m_name)
	DK_GETTER_REF_C(std::vector<Keyframe>, frames, m_frames)
	DK_GETTER_C(U32, frameNumber, (U32)m_frames.size())
	DK_GETTER_C(F32, animationDuration, m_animationDuration)
	DK_GETTER_C(F32, tickPerSecond, m_tickPerSecond)

private:
	std::string m_name;
	std::vector<Keyframe> m_frames;
	F32 m_animationDuration;
	F32 m_tickPerSecond;
};

} // namespace animation
} // namespace drak
