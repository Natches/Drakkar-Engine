#pragma once

#include <vector>
#include <Animation/Skeleton/Bone/Joint.hpp>

namespace drak {
namespace animation {

struct Bone final {
	Bone* parent;
	std::vector<Bone> children;
	Joint joint;
	std::string name;
	math::Mat4f invTPose;
};

} // namespace animation
} // namespace drak
