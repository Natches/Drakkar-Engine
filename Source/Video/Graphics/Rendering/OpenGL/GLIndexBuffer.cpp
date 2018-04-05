#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLIndexBuffer.hpp>

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

void GLIndexBuffer::drawElements(GLenum primType) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glID);
	glDrawElements(primType, m_indexCount, GL_UNSIGNED_SHORT, 0);
}

} // namespace gl
} // namespace gfx
} // namespace drak