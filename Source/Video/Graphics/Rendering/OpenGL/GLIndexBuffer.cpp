#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLIndexBuffer::~GLIndexBuffer() {
	if (m_glID != GL_INVALID)
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

void GLIndexBuffer::drawElements(GLenum prim) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glID);
	glDrawElements(prim, m_indexCount, GL_UNSIGNED_SHORT, nullptr);
}

void GLIndexBuffer::drawElementsInstanced(GLenum prim) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glID);
	glDrawElementsInstanced(prim, m_indexCount, GL_UNSIGNED_SHORT, nullptr, 1024);
}

} // namespace gl
} // namespace gfx
} // namespace drak