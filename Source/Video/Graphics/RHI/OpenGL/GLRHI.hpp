#pragma once

#include <Video/Graphics/RHI/RHIDefinitions.hpp>
#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>
#include <Video/Graphics/RHI/OpenGL/GLShader.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLRHI
* \ingroup DrakVideo
* \brief
*
*/
class GLRHI final {
public:
	static bool s_ready;

public:
	GLRHI()	= delete;
	~GLRHI() = delete;

public:
	static bool Init(bool debug = false);
	static void GraphicsInfo();

	static void DepthFunc(bool on, EDepthMode mode);
	static void CullFunc(bool on, EFaceSide side);

private:
	static void ErrorHandler(
		GLenum			source,
		GLenum			type,
		GLuint			id,
		GLenum			severity,
		GLsizei			length,
		const GLchar*	message,
		const GLvoid*	userParam);

private:
	static GLShader s_defaultShader;
};

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
