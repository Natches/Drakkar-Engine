#pragma once

#include <vector>
#include <Animation/Joint.hpp>

namespace drak {
namespace animation {

struct Bone final {
	Bone* parent;
	std::vector<Bone> children;
	Joint joint;
	math::Mat4f invTPose;
};

} // namespace animation
} // namespace drak
