#include <PrecompiledHeader/pch.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

#pragma region Macro Utils
#define DK_GL_TOGGLE(on, mode)	on ? glEnable(mode) : glDisable(mode);
#pragma endregion

bool GLRenderer::init() {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		#ifdef _DEBUG
			DK_GL_TOGGLE(true, GL_DEBUG_OUTPUT);
		#endif
		glDebugMessageCallback((GLDEBUGPROC)debugLog, 0);

		clearColorValue(Color3(0.1f, 0.1f, 0.1f));

		return true;
	}
	return false;
}

void GLRenderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLRenderer::clearColorValue(const Color3& k)	{ clearColorValue({ k, 1.f }); }
void GLRenderer::clearColorValue(const Color4& k)	{ glClearColor(k.r, k.g, k.b, k.a); }
void GLRenderer::clearDepthValue(F32 depth)			{ glClearDepthf(depth); }

void GLRenderer::depthTest(bool on, EDepthMode mode) {
	DK_GL_TOGGLE(on, GL_DEPTH_TEST)
	DK_SELECT(mode)
		DK_CASE(EDepthMode::NEVER,		glDepthFunc(GL_NEVER))
		DK_CASE(EDepthMode::LESS,		glDepthFunc(GL_LESS))
		DK_CASE(EDepthMode::EQUAL,		glDepthFunc(GL_EQUAL))
		DK_CASE(EDepthMode::LEQUAL,		glDepthFunc(GL_LEQUAL))
		DK_CASE(EDepthMode::GREATER,	glDepthFunc(GL_GREATER))
		DK_CASE(EDepthMode::NOT_EQUAL,	glDepthFunc(GL_NOTEQUAL))
		DK_CASE(EDepthMode::GEQUAL,		glDepthFunc(GL_GEQUAL))
		DK_CASE(EDepthMode::ALWAYS,		glDepthFunc(GL_ALWAYS))
	DK_END
}

void GLRenderer::blendTest(bool on, EBlendMode srcFactor, EBlendMode dstFactor) {
	DK_GL_TOGGLE(on, GL_BLEND)
	glBlendFunc(GL_SRC_COLOR + (GLenum)srcFactor, GL_SRC_COLOR + (GLenum)dstFactor);
}

void GLRenderer::cullTest(bool on, ECullMode mode) {
	DK_GL_TOGGLE(on, GL_CULL_FACE)
	DK_SELECT(mode)
		DK_CASE(ECullMode::FRONT,	glCullFace(GL_FRONT))
		DK_CASE(ECullMode::BACK,	glCullFace(GL_BACK))
		DK_CASE(ECullMode::BOTH,	glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

void GLRenderer::polygonMode(ECullMode cull, EPolygonMode poly) {
	GLenum face;
	DK_SELECT(cull)
		DK_CASE(ECullMode::FRONT,	face = GL_FRONT)
		DK_CASE(ECullMode::BACK,	face = GL_BACK)
		DK_CASE(ECullMode::BOTH,	face = GL_FRONT_AND_BACK)
	DK_END
	glPolygonMode(face, GL_POINT + (GLenum)poly);
}

void GLRenderer::windingOrder(EWindingOrder order) {
	glFrontFace(order == EWindingOrder::CLOCKWISE ? GL_CW : GL_CCW);
}

void GLRenderer::multisampling(bool on) {
	DK_GL_TOGGLE(on, GL_MULTISAMPLE)
}

void GLRenderer::bindWindowFrameBuffer() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

#pragma region Logging/Error-handling
void GLRenderer::info() {
	fprintf(stderr,
		"Renderer: %s\nVersion: %s\n",
		glGetString(GL_RENDERER), glGetString(GL_VERSION));
}

void GLRenderer::debugLog(
	GLenum			source,
	GLenum			type,
	GLuint			id,
	GLenum			severity,
	GLsizei			length,
	const GLchar*	message,
	const GLvoid*	userParam) {

	std::string errLvl = "Unknown";
	if		(severity == GL_DEBUG_SEVERITY_HIGH)		errLvl = "High";
	else if (severity == GL_DEBUG_SEVERITY_MEDIUM)		errLvl = "Medium";
	else if (severity == GL_DEBUG_SEVERITY_LOW)			errLvl = "Low";

	std::string errSrc = "Unknown";
	if		(source == GL_DEBUG_SOURCE_API)				errSrc = "API";
	else if (source == GL_DEBUG_SOURCE_WINDOW_SYSTEM)	errSrc = "OS";
	else if (source == GL_DEBUG_SOURCE_SHADER_COMPILER)	errSrc = "Shader Compiler";
	else if (source == GL_DEBUG_SOURCE_THIRD_PARTY)		errSrc = "Third Party";
	else if (source == GL_DEBUG_SOURCE_APPLICATION)		errSrc = "Application";

	std::string errType = "Unknown";
	if		(type == GL_DEBUG_TYPE_ERROR)				errType = "Error";
	else if (type == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR)	errType = "Deprecated Behavior";
	else if (type == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR)	errType = "Undefined Behavior";
	else if (type == GL_DEBUG_TYPE_PORTABILITY)			errType = "Portability";
	else if (type == GL_DEBUG_TYPE_PERFORMANCE)			errType = "Performance";

	fprintf(stderr,
		"============ GLRenderer Log ============\n"
		"| Level.... %s\n"
		"| Source... %s\n"
		"| Type..... %s\n|\n"
		"| Message: %s"
		"========================================\n",
		errLvl.c_str(), errSrc.c_str(), errType.c_str(), message);
}
#pragma endregion

} // namespace gl
} // namespace gfx
} // namespace drak