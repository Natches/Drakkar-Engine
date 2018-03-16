#pragma once

#include <Core/Types.hpp>

namespace drak {
namespace video {

enum class DepthMode : U8 {
	LESS,
	LEQUAL,
	EQUAL,
	GEQUAL,
	GREATER
};

enum class FaceSide : U8 {
	FRONT,
	BACK,
	BOTH
};

} // namespace video
} // namespace drak