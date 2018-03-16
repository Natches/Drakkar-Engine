#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace video {

enum class EDepthMode : U8 {
	LESS,
	LEQUAL,
	EQUAL,
	GEQUAL,
	GREATER
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