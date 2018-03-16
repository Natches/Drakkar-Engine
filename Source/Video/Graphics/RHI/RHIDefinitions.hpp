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

enum class PrimitiveType : U8 {
	POINTS,
	LINES,
	LINE_LOOP,
	LINE_STRIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN
	//...
};

} // namespace video
} // namespace drak