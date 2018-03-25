#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertexBuffer.hpp>

using namespace drak::video::geom;

namespace drak {
namespace video {
namespace gl {

GLVertexBuffer::~GLVertexBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLVertexBuffer::create(
	const Vertex* const pVerts,
	const GLuint vertCount,
	const GLuint bindIndex) {

	m_bindIndex	= bindIndex;

	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID, 
		vertCount * sizeof(Vertex),
		pVerts,
		GL_MAP_WRITE_BIT);
}

} // namespace gl
} // namespace video
} // namespace drak