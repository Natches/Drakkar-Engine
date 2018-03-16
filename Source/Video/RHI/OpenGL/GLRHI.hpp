#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

extern bool s_Ready;

bool Init(bool debug = false);
void GraphicsInfo();

void ErrorHandler(
	GLenum			source,
	GLenum			type,
	GLuint			id,
	GLenum			severity,
	GLsizei			length,
	const GLchar*	message,
	const void*		userParam
);

enum class DepthMode : byte {
	LESS, 
	LEQUAL, 
	EQUAL, 
	GEQUAL, 
	GREATER
};
void DepthFunc(bool on, DepthMode mode);

enum class FaceSide : byte {
	FRONT,
	BACK, 
	BOTH 
};
void CullFunc(bool on, FaceSide side);

/*
enum class BlendMode : byte {
	ZERO,
	ONE,
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	CONST_COLOR,
	ONE_MINUS_CONST_COLOR,
	CONST_ALPHA,
	ONE_MINUS_CONST_ALPHA,
	SRC_ALPHA_SATURATE,
	SRC1_COLOR,
	ONE_MINUS_SRC_COLOR,
	ONE_MINUS_SRC_ALPHA
};
void BlendFunc(bool on, BlendMode mode);
*/

} // namespace gl
} // namespace gfx
} // namespace drak
