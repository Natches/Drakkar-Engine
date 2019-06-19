#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLStorageBuffer::~GLStorageBuffer() {
	if (m_glID != GL_INVALID) {
		glUnmapNamedBuffer(m_glID);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		glDeleteBuffers(1, &m_glID);
	}
}

void GLStorageBuffer::create(U64 bytes, void* pData) {
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(m_glID, (GLsizeiptr)bytes, pData, GL_MAP_WRITE_BIT | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT);
}

void GLStorageBuffer::write(U64 offset, U64 bytes, void* pData) {
	if (!m_pMappedBufferData) {
		m_pMappedBufferData = glMapNamedBuffer(m_glID, GL_WRITE_ONLY);
	}
	memcpy(m_pMappedBufferData, pData, (size_t)bytes);
}

void GLStorageBuffer::bind() {
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, m_glID);
}

} // namespace gl
} // namespace gfx
} // namespace drak