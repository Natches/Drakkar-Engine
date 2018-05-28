#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace gfx {

enum class EDepthMode : U32 {
	NEVER,
	LESS,
	EQUAL,
	LEQUAL,
	GREATER,
	GEQUAL,
	NOT_EQUAL,
	ALWAYS,
};

enum class EBlendMode : U32 {
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA_SATURATE
};

enum class ECullMode : U32 {
	FRONT,
	BACK,
	BOTH
};

enum class EPolygonMode : U32 {
	POINT,
	LINE,
	FILL
};

enum class EWindingOrder : U32 {
	CLOCKWISE,
	COUNTERCLOCKWISE
};

enum class EPrimitiveType : U32 {
	POINTS,
	LINES,
	LINE_LOOP,
	LINE_STRIP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN
};

} // namespace gfx
} // namespace drak