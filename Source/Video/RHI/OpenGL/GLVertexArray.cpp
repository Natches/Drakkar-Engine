#include <GL/glew.h>
#include <Video/RHI/OpenGL/GLVertexArray.hpp>

namespace drak {
namespace video {
namespace gl {

GLVertexArray::GLVertexArray() {

}

GLVertexArray::~GLVertexArray() {

}

void GLVertexArray::create() {
	glGenVertexArrays(1, &m_glID);

}

void GLVertexArray::bind() {
	glBindVertexArray(m_glID);
	//glVertexArrayVertexBuffers()
}

} // namespace gl
} // namespace gfx
} // namespace drak