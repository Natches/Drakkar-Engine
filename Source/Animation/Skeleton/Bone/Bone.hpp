#pragma once

#include <vector>
#include <Animation/Skeleton/Bone/Joint.hpp>

namespace drak {
namespace animation {

struct Bone final {
	std::string name;
	std::vector<Bone> children;
	Joint joint;
};

} // namespace animation
} // namespace drak
