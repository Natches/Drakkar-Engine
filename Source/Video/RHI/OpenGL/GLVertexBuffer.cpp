#include <GL/glew.h>
#include <Video/RHI/OpenGL/GLVertexBuffer.hpp>

namespace drak {
namespace video {
namespace gl {

GLVertexBuffer::GLVertexBuffer() {

}

GLVertexBuffer::~GLVertexBuffer() {

}

void GLVertexBuffer::create() {
	glGenBuffers(1, &m_glID);
	//glBindVertexBuffer()
}

void GLVertexBuffer::bind() {
	glBindVertexArray(m_glID);
}

} // namespace gl
} // namespace gfx
} // namespace drak