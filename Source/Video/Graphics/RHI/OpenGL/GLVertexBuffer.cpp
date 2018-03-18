#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertexBuffer.hpp>

namespace drak {
namespace video {
namespace gl {

GLVertexBuffer::~GLVertexBuffer() {
	glDeleteBuffers(1, &m_glID);
}

void GLVertexBuffer::create(
	const GLVertex*	const pVerts,
	const GLuint vertCount,
	const GLuint bindIndex) {

	m_byteSize	= sizeof(GLVertex) * vertCount;
	m_bindIndex	= bindIndex;

	glCreateBuffers(1, &m_glID);
	glNamedBufferStorage(
		m_glID, 
		m_byteSize,
		pVerts,
		GL_MAP_WRITE_BIT | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT);
}

} // namespace gl
} // namespace video
} // namespace drak