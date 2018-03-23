#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace video {

enum class EDepthMode : U8 {
	NEVER,
	LESS,
	EQUAL,
	LEQUAL,
	GREATER,
	GEQUAL,
	NOT_EQUAL,
	ALWAYS,
};

enum class EFaceSide : U8 {
	FRONT,
	BACK,
	BOTH
};

enum class EPrimitiveType : U8 {
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