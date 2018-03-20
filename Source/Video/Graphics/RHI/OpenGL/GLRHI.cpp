#include <GL/glew.h>

#include <Core/Core.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>

namespace drak {
namespace video {
namespace gl {

#pragma region Macro Utils
#define DK_GL_TOGGLE(on, mode)	on ? glEnable(mode) : glDisable(mode);
#pragma endregion

#pragma region Static Initialization
bool		GLRHI::s_ready = false;
GLShader	GLRHI::s_defaultShader;
#pragma endregion

bool GLRHI::Init(bool debug) {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		if (debug) {
			GraphicsInfo();
			DK_GL_TOGGLE(debug, GL_DEBUG_OUTPUT);
			glDebugMessageCallback((GLDEBUGPROC)ErrorHandler, 0);
		}

		if (!s_defaultShader.loadFromFile("default.vs", "default.fs"))
			return false;
		s_defaultShader.use();

		DepthFunc(true, EDepthMode::LESS);
		CullFunc(true, EFaceSide::BACK);
	}
	s_ready = true;
	return true;
}

#pragma region Logging/Error-handling
void GLRHI::GraphicsInfo() {
}

void GLRHI::ErrorHandler(
	GLenum			source,
	GLenum			type,
	GLuint			id,
	GLenum			severity,
	GLsizei			length,
	const GLchar*	message,
	const GLvoid*	userParam) {
}
#pragma endregion

void GLRHI::DepthFunc(bool on, EDepthMode mode) {
	DK_GL_TOGGLE(on, GL_DEPTH_TEST)
	DK_SELECT(mode)
		DK_CASE(EDepthMode::LESS,		glDepthFunc(GL_LESS))
		DK_CASE(EDepthMode::LEQUAL,		glDepthFunc(GL_LEQUAL))
		DK_CASE(EDepthMode::EQUAL,		glDepthFunc(GL_EQUAL))
		DK_CASE(EDepthMode::GEQUAL,		glDepthFunc(GL_GEQUAL))
		DK_CASE(EDepthMode::GREATER,	glDepthFunc(GL_GREATER))
	DK_END
}

void GLRHI::CullFunc(bool on, EFaceSide side) {
	DK_GL_TOGGLE(on, GL_CULL_FACE)
	DK_SELECT(side)
		DK_CASE(EFaceSide::FRONT,	glCullFace(GL_FRONT))
		DK_CASE(EFaceSide::BACK,	glCullFace(GL_BACK))
		DK_CASE(EFaceSide::BOTH,	glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

} // namespace gl
} // namespace gfx
} // namespace drak