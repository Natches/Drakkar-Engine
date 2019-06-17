#pragma once

#include <string>
#include <vector>
#include <Animation/Skeleton/Bone/Joint.hpp>

namespace drak {
namespace animation {

struct Bone final {
	std::string name;
	std::vector<std::string> children;
	Joint joint;
	math::Mat4f offsetMatrix;
};

} // namespace animation
} // namespace drak
