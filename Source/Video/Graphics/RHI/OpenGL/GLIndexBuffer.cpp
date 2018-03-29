#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLIndexBuffer.hpp>

namespace drak {
namespace video {
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
		GL_MAP_WRITE_BIT | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT);
}

} // namespace gl
} // namespace video
} // namespace drak