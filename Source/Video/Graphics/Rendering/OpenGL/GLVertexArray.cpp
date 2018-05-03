#include <PrecompiledHeader/pch.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

GLVertexArray::~GLVertexArray() {
	if (m_glID != GL_INVALID)
		glDeleteVertexArrays(1, &m_glID);
}

void GLVertexArray::create(GLVertexBuffer* pVBO, GLIndexBuffer* pIBO) {
	if (pVBO == nullptr)
		return;

	m_pVBO = pVBO;
	m_pIBO = pIBO;
	m_prim = GL_TRIANGLES;

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

	if (m_pIBO)
		glVertexArrayElementBuffer(m_glID, m_pIBO->glID());
}

void GLVertexArray::render() {
	glBindVertexArray(m_glID);
	if (m_pIBO) {
		if (m_instanced) m_pIBO->drawElementsInstanced(m_prim);
		else			 m_pIBO->drawElements(m_prim);
	}
	else
		glDrawArrays(m_prim, 0, m_vertexCount);
}

} // namespace gl
} // namespace gfx
} // namespace drak