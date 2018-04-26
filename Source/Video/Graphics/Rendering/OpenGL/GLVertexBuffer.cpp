#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLVertexBuffer.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

GLVertexBuffer::GLVertexBuffer()
:	m_bindIndex(0u) {

}

GLVertexBuffer::~GLVertexBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLVertexBuffer::create(
	const void*				pData,
	const U32				vertexCount,
	const U32				attribCount) {
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		vertexCount * elemSize,
		pData,
		GL_MAP_WRITE_BIT);
}

void GLVertexBuffer::create(
	const Vertex1P*	pVerts,
	const U32		vertexCount) {
	VertexAttribDesc desc[] = {}
	create(pVerts, vertexCount, )
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		vertexCount * sizeof(Vertex1P),
		pVerts,
		GL_MAP_WRITE_BIT);
}

void GLVertexBuffer::create(
	const void*				pData,
	const U32				vertexCount
	const U32				attribCount) {
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		vertexCount * elemSize,
		pData,
		GL_MAP_WRITE_BIT);
}

} // namespace gl
} // namespace gfx
} // namespace drak