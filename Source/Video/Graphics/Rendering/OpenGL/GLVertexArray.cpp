#include <PrecompiledHeader/pch.hpp>

#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>

using namespace drak::geom;

namespace drak {
namespace gfx {
namespace gl {

GLVertexArray::~GLVertexArray() {
	if (m_glID != GL_INVALID)
		glDeleteVertexArrays(1, &m_glID);
}

void GLVertexArray::create(GLVertexBuffer* pVBO, GLIndexBuffer* pIBO, GLenum prim) {
	if (pVBO == nullptr)
		return;

	m_pVBO = pVBO;
	m_pIBO = pIBO;
	m_prim = prim;

	if (pVBO)
		m_vertexCount = pVBO->vertexCount();

	glCreateVertexArrays(1, &m_glID);
	glVertexArrayVertexBuffer(
		m_glID, m_pVBO->bindIndex(), m_pVBO->glID(), 0, m_pVBO->vertexSize());
	
	const VertexAttribDesc*	attribDescs = m_pVBO->attribDescs();
	U32	attribOffset = 0u;
	for (U32 i = 0u; i < m_pVBO->attribCount(); ++i) {
		glVertexArrayAttribFormat(
			m_glID, 
			attribDescs[i].attrib,
			attribDescs[i].count,
			attribDescs[i].type + GL_BYTE,
			attribDescs[i].normalized,
			attribOffset);
		glVertexArrayAttribBinding(m_glID, attribDescs[i].attrib, m_pVBO->bindIndex());
		glEnableVertexArrayAttrib(m_glID, attribDescs[i].attrib);

		attribOffset += VertexAttribSize(attribDescs[i].type, attribDescs[i].count);
	}

	if (m_pIBO)
		glVertexArrayElementBuffer(m_glID, m_pIBO->glID());
}

/*
	TODO (Simon
*/
void GLVertexArray::render() {
	glBindVertexArray(m_glID);
	if (m_pIBO) {
		if (m_instanced) 
			m_pIBO->drawElementsInstanced(m_prim);
		else			 
			m_pIBO->drawElements(m_prim);
	}
	else
		glDrawArrays(m_prim, 0, m_vertexCount);
}

} // namespace gl
} // namespace gfx
} // namespace drak