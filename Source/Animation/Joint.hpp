#pragma once

#include <Math/Quaternion.hpp>

namespace drak {
namespace animation {

struct Joint final {
	math::Vec3f pos;
	math::Quat rot;
	std::string name;
};

} // namespace animation
} // namespace drak