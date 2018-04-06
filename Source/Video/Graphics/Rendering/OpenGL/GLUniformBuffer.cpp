#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLUniformBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLUniformBuffer::~GLUniformBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLUniformBuffer::create(U64 bytes, void* pData) {
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		bytes,
		pData,
		GL_MAP_WRITE_BIT);
}

void GLUniformBuffer::write(U64 offset, U64 bytes, void* pData) {
	bind();

	void* pBuff = glMapNamedBufferRange(
		m_glID,
		offset,
		bytes,
		GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

	if (pBuff) {
		memcpy(pBuff, pData, bytes);
		glUnmapNamedBuffer(m_glID);
	}
}

void GLUniformBuffer::bind() {
	glBindBuffer(GL_UNIFORM_BUFFER, m_glID);
}

} // namespace gl
} // namespace gfx
} // namespace drak



