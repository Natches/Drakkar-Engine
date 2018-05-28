#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {
namespace gl {

GLStorageBuffer::~GLStorageBuffer() {
	if (m_glID != GL_INVALID) {
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		glDeleteBuffers(1, &m_glID);
	}
}

void GLStorageBuffer::create(U64 bytes, void* pData) {
	glGenBuffers(1, &m_glID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_glID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, bytes, pData, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void GLStorageBuffer::write(U64 offset, U64 bytes, void* pData) {
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_glID);
	glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, bytes, pData);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void GLStorageBuffer::bind() {
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, m_glID);
}

} // namespace gl
} // namespace gfx
} // namespace drak