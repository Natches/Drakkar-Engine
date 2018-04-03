#include <GL/glew.h>

#include <Core/Core.hpp>

#include <Video/Graphics/Geometry/Mesh.hpp>
#include <Video/Graphics/Tools/OBJLoader.hpp>

#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLShader.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLRenderer.hpp>

namespace drak {
namespace gfx {
namespace gl {

#pragma region Macro Utils
#define DK_GL_TOGGLE(on, mode)	on ? glEnable(mode) : glDisable(mode);
#pragma endregion

bool GLRenderer::init() {
	glewExperimental = true;
	if (glewInit() == GLEW_OK) {
		DK_GL_TOGGLE(true, GL_DEBUG_OUTPUT);
		glDebugMessageCallback((GLDEBUGPROC)errorCallback, 0);

		clearColorValue(Color3(0.1f, 0.1f, 0.1f));

		return true;
	}
	return false;
}

bool GLRenderer::loadShaders(const std::string& dir, ShaderMap& outMap) {
	GLShader* pGridShader = new GLShader;
	if (pGridShader->loadFromFile(dir + "grid.vert", dir + "grid.frag"))
		outMap["GridShader"] = pGridShader;
	else {
		delete pGridShader;
		return false;
	}

	GLShader* pDefaultShader = new GLShader;
	if (pDefaultShader->loadFromFile(dir + "default.vert", dir + "default.frag"))
		outMap["DefaultShader"] = pDefaultShader;
	else {
		delete pDefaultShader;
		return false;
	}

	GLShader* pFrameShader = new GLShader;
	if (pFrameShader->loadFromFile(dir + "FrameDraw.vert", dir + "FrameDraw.frag"))
		outMap["FrameDraw"] = pFrameShader;
	else {
		delete pFrameShader;
		return false;
	}
	
	return true;
}

bool GLRenderer::loadRenderables(const std::string& dir, RenderArray& outArr) {
	tools::OBJLoader loader;

	geom::Mesh mesh;
	if (loader.load(dir, mesh)) {
		const std::vector<geom::Vertex>& verts = mesh.vertices();
		GLVertexBuffer vbo;
		vbo.create(verts.data(), (U32)verts.size());

		const std::vector<U16>& indices = mesh.indices();
		GLIndexBuffer ibo;
		ibo.create(indices.data(), (I32)indices.size());

		GLVertexArray* pVao = new GLVertexArray;
		pVao->create(vbo, ibo);

		outArr.push_back(pVao);
		return true;
	}
	return false;
}

void GLRenderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLRenderer::clearColorValue(const Color3& color) {
	clearColorValue({ color, 1.f });
}

void GLRenderer::clearColorValue(const Color4& color) {
	glClearColor(color.r, color.g, color.b, color.a);
}

void GLRenderer::clearDepthValue(F32 depth) {
	glClearDepthf(depth);
}

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
		glBlendFunc((GLenum)srcFactor, (GLenum)dstFactor);
}

void GLRenderer::cullTest(bool on, ECullMode mode) {
	DK_GL_TOGGLE(on, GL_CULL_FACE)
	DK_SELECT(mode)
		DK_CASE(ECullMode::FRONT,	glCullFace(GL_FRONT))
		DK_CASE(ECullMode::BACK,	glCullFace(GL_BACK))
		DK_CASE(ECullMode::BOTH,	glCullFace(GL_FRONT_AND_BACK))
	DK_END
}

void GLRenderer::windingOrder(EWindingOrder order) {
	glFrontFace(order == EWindingOrder::CLOCKWISE ? GL_CW : GL_CCW);
}

void GLRenderer::bindWindowFrameBuffer() {
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

#pragma region Logging/Error-handling
void GLRenderer::info() {
	fprintf(stderr, "Renderer: %s\nVersion: %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));
}

void GLRenderer::errorCallback(
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