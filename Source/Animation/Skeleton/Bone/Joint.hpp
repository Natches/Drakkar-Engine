#pragma once

#include <Math/Quaternion.hpp>

namespace drak {
namespace animation {

struct Joint final {
	math::Vec3f pos;
	math::Vec3f scale;
	math::Quat  rot;
};

} // namespace animation
} // namespace drak