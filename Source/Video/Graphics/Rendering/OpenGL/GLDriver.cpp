#include <GL/glew.h>

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLDriver.hpp>

namespace drak {
namespace gfx {
namespace gl {

#pragma region Macro Utils
#define DK_GL_TOGGLE(on, mode)	on ? glEnable(mode) : glDisable(mode);
#pragma endregion

bool GLDriver::init() {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		DK_GL_TOGGLE(true, GL_DEBUG_OUTPUT);
		glDebugMessageCallback((GLDEBUGPROC)errorCallback, 0);

		depthTest(true /* read option from .ini*/);
		blendTest(true /* read option from .ini*/);
		cullTest(true  /* read option from .ini*/);
	}
	return true;
}

void GLDriver::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLDriver::clearColorValue(const Color3& color) {
	clearColorValue({ color, 1.f });
}

void GLDriver::clearColorValue(const Color4& color) {
	glClearColor(color.r, color.g, color.b, color.a);
}

void GLDriver::clearDepthValue(F32 depth) {
	glClearDepthf(depth);
}

void GLDriver::clearDepthValue(F32 depth) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLDriver::depthTest(bool on, EDepthMode mode) {
	DK_GL_TOGGLE(on, GL_DEPTH_TEST)
	DK_SELECT(mode)
		DK_CASE(EDepthMode::NEVER, glDepthFunc(GL_NEVER))
		DK_CASE(EDepthMode::LESS, glDepthFunc(GL_LESS))
		DK_CASE(EDepthMode::EQUAL, glDepthFunc(GL_EQUAL))
		DK_CASE(EDepthMode::LEQUAL, glDepthFunc(GL_LEQUAL))
		DK_CASE(EDepthMode::GREATER, glDepthFunc(GL_GREATER))
		DK_CASE(EDepthMode::NOT_EQUAL, glDepthFunc(GL_NOTEQUAL))
		DK_CASE(EDepthMode::GEQUAL, glDepthFunc(GL_GEQUAL))
		DK_CASE(EDepthMode::ALWAYS, glDepthFunc(GL_ALWAYS))
	DK_END
}

void GLDriver::blendTest(bool on, EBlendMode srcFactor, EBlendMode dstFactor) {
	DK_GL_TOGGLE(on, GL_BLEND)
		glBlendFunc((GLenum)srcFactor, (GLenum)dstFactor);
}

void GLDriver::cullTest(bool on, ECullMode mode) {
	DK_GL_TOGGLE(on, GL_CULL_FACE)
	DK_SELECT(mode)
		DK_CASE(ECullMode::FRONT, glCullFace(GL_FRONT))
		DK_CASE(ECullMode::BACK, glCullFace(GL_BACK))
		DK_CASE(ECullMode::BOTH, glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

void GLDriver::windingOrder(EWindingOrder order) {
	glFrontFace(order == EWindingOrder::CLOCKWISE ? GL_CW : GL_CCW);
}

#pragma region Logging/Error-handling
void GLDriver::info() {
	fprintf(stderr, "Renderer: %s\nVersion: %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
}

void GLDriver::errorCallback(
	GLenum			source,
	GLenum			type,
	GLuint			id,
	GLenum			severity,
	GLsizei			length,
	const GLchar*	message,
	const GLvoid*	userParam) {
	fprintf(stderr, "%s\n", message);
}
#pragma endregion

} // namespace gl
} // namespace gfx
} // namespace drak