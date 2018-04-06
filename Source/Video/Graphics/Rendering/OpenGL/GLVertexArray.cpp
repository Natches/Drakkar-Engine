#include <GL/glew.h>

#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexAttrib.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

GLVertexArray::~GLVertexArray() {
	glDeleteVertexArrays(1, &m_glID);
}

void GLVertexArray::create(GLVertexBuffer* pVBO, GLIndexBuffer* pIBO) {
	m_pVBO = pVBO;
	m_pIBO = pIBO;

	glCreateVertexArrays(1, &m_glID);
	glVertexArrayVertexBuffer(m_glID, m_pVBO->bindIndex(), m_pVBO->glID(), 0, sizeof(Vertex));
	for (U32 i = VERT_ATTR_POS; i < VERT_ATTR_COUNT; ++i) {
		glVertexArrayAttribFormat(
			m_glID, 
			i,
			g_VertexAttribDescArray[i].size,
			g_VertexAttribDescArray[i].type,
			g_VertexAttribDescArray[i].normalized,
			g_VertexAttribDescArray[i].offset);
		glVertexArrayAttribBinding(m_glID, i, m_pVBO->bindIndex());
		glEnableVertexArrayAttrib(m_glID, i);
	}
	glVertexArrayElementBuffer(m_glID, m_pIBO->glID());
}

void GLVertexArray::render() {
	glBindVertexArray(m_glID);
	m_pIBO->drawElements();
}

} // namespace gl
} // namespace gfx
} // namespace drak