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

	static void DepthFunc	(bool on, EDepthMode mode);
	static void CullFunc	(bool on, EFaceSide side);
	static void BlendFunc	(bool on, EBlendMode srcFactor, EBlendMode dstFactor);

private:
	static bool LoadShaders();

	static void ErrorHandler(
		GLenum			source,
		GLenum			type,
		GLuint			id,
		GLenum			severity,
		GLsizei			length,
		const GLchar*	message,
		const GLvoid*	userParam);

public:
	static GLShader s_defaultShader;
	static GLShader s_gridShader;
};


} // namespace gl
} // namespace video
} // namespace drak
