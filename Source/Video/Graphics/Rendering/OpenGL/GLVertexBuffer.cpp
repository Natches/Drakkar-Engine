#include <PrecompiledHeader/pch.hpp>

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
	const void* pVerts,
	const U32	vertexCount,
	const U32	vertexSize) {
	if (m_glID == GL_INVALID) {
		m_vertexCount = vertexCount;
		m_vertexSize  = vertexSize;
		glCreateBuffers(1, &m_glID);
		glNamedBufferStorage(
			m_glID,
			vertexCount * m_vertexSize,
			pVerts,
			GL_MAP_WRITE_BIT);
	}
}

} // namespace gl
} // namespace gfx
} // namespace drak