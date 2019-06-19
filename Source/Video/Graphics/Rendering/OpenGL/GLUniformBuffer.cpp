#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLUniformBuffer::~GLUniformBuffer() {
	/*if (m_glID != GL_INVALID) {
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glDeleteBuffers(1, &m_glID);
	}*/
}

void GLUniformBuffer::create(U64 bytes, void* pData) {
	/*glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID,
		bytes,
		pData,
		GL_MAP_WRITE_BIT);*/

	glGenBuffers(1, &m_glID);
	glBindBuffer(GL_UNIFORM_BUFFER, m_glID);
	glBufferData(GL_UNIFORM_BUFFER, (GLsizeiptr)bytes, pData, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void GLUniformBuffer::write(U64 offset, U64 bytes, void* pData) {
	/*void* pBuff = glMapNamedBufferRange(
		m_glID,
		offset,
		bytes,
		GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

	if (pBuff) {
		memcpy(pBuff, pData, bytes);
		glUnmapNamedBuffer(m_glID);
	}*/

	glBindBuffer(GL_UNIFORM_BUFFER, m_glID);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, (GLsizeiptr)bytes, pData);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void GLUniformBuffer::bind() {
	glBindBufferBase(GL_UNIFORM_BUFFER, 4, m_glID);
}

} // namespace gl
} // namespace gfx
} // namespace drak



