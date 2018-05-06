#pragma once

#include <string>
#include <vector>
#include <Core/Utils/ClassUtils.hpp>
#include <Animation/Animation/KeyFrame/KeyFrame.hpp>

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
	DK_GETTER_REF_C(std::vector<KeyFrame>, frames, m_frames)
	DK_GETTER_C(I32, frameNumber, m_frames.size())
	DK_GETTER_C(F32, time, m_time)

private:
	std::string m_name;
	std::vector<KeyFrame> m_frames;
	F32 m_time;
};

} // namespace animation
} // namespace drak
