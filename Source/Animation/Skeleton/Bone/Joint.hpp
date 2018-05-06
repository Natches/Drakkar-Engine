#pragma once

#include <Math/Quaternion.hpp>

namespace drak {
namespace animation {

struct Joint final {
	math::Vec3f pos;
	math::Quat rot;
};

} // namespace animation
} // namespace drak