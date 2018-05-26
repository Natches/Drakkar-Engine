#pragma once

#include <Animation/Skeleton/Bone/Bone.hpp>

namespace drak {
namespace animation {

class Skeleton final {

	DK_NONCOPYABLE(Skeleton)

public:
	Skeleton() = delete;
	Skeleton(const Bone& b) = delete;
	Skeleton(Bone&& b);
	Skeleton(Skeleton&& skTon);

	Skeleton& operator=(Skeleton&& skTon);

	core::EError jointByName(const std::string& name, Joint& j) const;

private:
	Bone m_base;
	std::unordered_map<std::string, Bone> m_boneList;
	std::vector<Animation> m_animList;
};

} // namespace animation
} // namespace drak