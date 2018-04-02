#include <cassert>
#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexAttrib.hpp>

using namespace drak::geom;

namespace drak {
namespace video {
namespace gl {

GLVertexArray::~GLVertexArray() {
	glDeleteVertexArrays(1, &m_glID);
}

void GLVertexArray::create(const GLVertexBuffer& vbo, const GLIndexBuffer& ibo) {
	glCreateVertexArrays(1, &m_glID);
	glVertexArrayVertexBuffer(m_glID, vbo.bindIndex(), vbo.glID(), 0, sizeof(Vertex));
	for (U32 i = VERT_ATTR_POS; i < VERT_ATTR_COUNT; ++i) {
		glVertexArrayAttribFormat(
			m_glID, 
			i,
			g_VertexAttribDescArray[i].size,
			g_VertexAttribDescArray[i].type,
			g_VertexAttribDescArray[i].normalized,
			g_VertexAttribDescArray[i].offset);
		glVertexArrayAttribBinding(m_glID, i, vbo.bindIndex());
		glEnableVertexArrayAttrib(m_glID, i);
	}
	m_vertCount = ibo.indexCount();
	m_iboID = ibo.glID();
	glVertexArrayElementBuffer(m_glID, m_iboID);
}

void GLVertexArray::draw() {
	glBindVertexArray(m_glID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iboID);
	glDrawElements(GL_TRIANGLES, m_vertCount, GL_UNSIGNED_SHORT, 0);
}

} // namespace gl
} // namespace video
} // namespace drak