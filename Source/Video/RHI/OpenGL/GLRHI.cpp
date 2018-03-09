#include <cstdio>
#include <GL/glew.h>

#include <Video/RHI/OpenGL/GLRHI.hpp>

namespace drak {
namespace video {
namespace ogl {

#pragma region Macro Utils
#define DK_SELECT(query)		switch(query) {
#define DK_CASE(cond, line)		case cond: line; break;
#define DK_END					}

#define DK_GL_TOGGLE(on, mode)	on ? glEnable(mode) : glDisable(mode);
#pragma endregion

#pragma region Static Initialization
bool s_ready = false;
#pragma endregion


bool Init(bool debug) {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		if (debug) {
			GraphicsInfo();
			DK_GL_TOGGLE(true, GL_DEBUG_OUTPUT);
			glDebugMessageCallback((GLDEBUGPROC)ErrorHandler, 0);
		}

		s_ready = true;
	}
	return s_ready;
}

#pragma region Logging/Error-handling
void GraphicsInfo() {
	fprintf(stderr, "%s%s\n%s%s\n%s",
		"\n--------- GLRHI Information ---------\n"
		"Renderer: ", glGetString(GL_RENDERER),
		"Version:  ", glGetString(GL_VERSION),
		"-------------------------------------\n");
}

void ErrorHandler(
	GLenum			source,
	GLenum			type,
	GLuint			id,
	GLenum			severity,
	GLsizei			length,
	const GLchar*	message,
	const void*		userParam) {
	fprintf(stderr, "OpenGL error: %s\n", message);
}
#pragma endregion

void DepthFunc(bool on, DepthMode mode) {
	DK_GL_TOGGLE(on, GL_DEPTH_TEST)
	DK_SELECT(mode)
		DK_CASE(DepthMode::LESS,	glDepthFunc(GL_LESS))
		DK_CASE(DepthMode::LEQUAL,	glDepthFunc(GL_LEQUAL))
		DK_CASE(DepthMode::EQUAL,	glDepthFunc(GL_EQUAL))
		DK_CASE(DepthMode::GEQUAL,	glDepthFunc(GL_GEQUAL))
		DK_CASE(DepthMode::GREATER, glDepthFunc(GL_GREATER))
	DK_END
}

void CullFunc(bool on, FaceSide side) {
	DK_GL_TOGGLE(on, GL_CULL_FACE)
	DK_SELECT(side)
		DK_CASE(FaceSide::FRONT, glCullFace(GL_FRONT))
		DK_CASE(FaceSide::BACK,	 glCullFace(GL_BACK))
		DK_CASE(FaceSide::BOTH,	 glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

} // namespace ogl
} // namespace gfx
} // namespace drak