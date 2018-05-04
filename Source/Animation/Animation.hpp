#pragma once

#include <string>
#include <vector>
#include <Core/Utils/ClassUtils.hpp>
#include <Animation/KeyFrame.hpp>

namespace drak {
namespace animation {

class Skeleton;

class Animation final {
	DK_NOMOVE_NOCOPY_OP(Animation)
public:
	Animation() = delete;
	Animation(Skeleton& skTon);
	Animation(const Animation& anim);
	Animation(Animation&& anim);

	DK_GETTER_REF_C(std::string, name, m_name)
	DK_GETTER_REF_C(Skeleton, skeleton, m_skel)
	DK_GETTER_REF_C(std::vector<KeyFrame>, frames, m_frames)
	DK_GETTER_C(I32, frameNumber, m_frames.size())

private:
	Skeleton& m_skel; // in T-Pose
	std::string m_name;
	std::vector<KeyFrame> m_frames;
};

} // namespace animation
} // namespace drak
