#include <GL/glew.h>

#include <Video/RHI/OpenGL/GLVertexBuffer.hpp>

namespace drak {
namespace video {
namespace gl {

GLVertexBuffer::~GLVertexBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLVertexBuffer::create(const GLVertex* vertData, U32 size) {
	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID, 
		size, 
		vertData,
		GL_MAP_WRITE_BIT | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT);
}

} // namespace gl
} // namespace video
} // namespace drak