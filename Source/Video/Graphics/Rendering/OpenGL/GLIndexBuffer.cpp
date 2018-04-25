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

void GLIndexBuffer::drawElements() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glID);
	glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, 0);
}

void GLIndexBuffer::drawElementsInstanced() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glID);
	glDrawElementsInstanced(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_SHORT, 0, 1);
}

} // namespace gl
} // namespace gfx
} // namespace drak