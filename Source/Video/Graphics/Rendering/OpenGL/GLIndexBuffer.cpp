#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLIndexBuffer::~GLIndexBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLIndexBuffer::create(const GLushort* pIndices, GLsizei indexCount) {
	m_indexCount = indexCount;
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		sizeof(GLushort) * m_indexCount,
		pIndices,
		GL_MAP_WRITE_BIT);
}

} // namespace gl
} // namespace gfx
} // namespace drak