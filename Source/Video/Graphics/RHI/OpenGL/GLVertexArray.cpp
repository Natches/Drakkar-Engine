#include <GL/glew.h>

#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>

namespace drak {
namespace video {
namespace gl {

GLVertexArray::~GLVertexArray() {
	glDeleteVertexArrays(1, &m_glID);
}

void GLVertexArray::create(const std::vector<GLVertex>& verts) {
	glCreateVertexArrays(1, &m_glID);

	GLuint vbo;
	GLuint binding = 0u;

	glCreateBuffers(1, &vbo);

	glNamedBufferStorage(
		vbo,
		verts.size() * sizeof(GLVertex),
		verts.data(),
		GL_MAP_WRITE_BIT | GL_MAP_COHERENT_BIT | GL_MAP_PERSISTENT_BIT);
	
	glVertexArrayAttribFormat(m_glID, GL_VERT_ATTR_POS, 3, GL_FLOAT, GL_FALSE, 0);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_POS);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_POS, binding);

	glVertexArrayAttribFormat(m_glID, GL_VERT_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, 12);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_COLOR);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_COLOR, binding);
	
	glVertexArrayVertexBuffer(m_glID, binding, vbo, 0, sizeof(GLVertex));
}

void GLVertexArray::draw() {
	glBindVertexArray(m_glID);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void GLVertexArray::bindVertexBuffer(GLuint bindIndex, const GLVertexBuffer* const vbo) {
	glVertexArrayAttribFormat(m_glID, GL_VERT_ATTR_POS, 3, GL_FLOAT, GL_FALSE, 0);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_POS);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_POS, bindIndex);

	glVertexArrayAttribFormat(m_glID, GL_VERT_ATTR_COLOR, 4, GL_FLOAT, GL_FALSE, 12);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_COLOR);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_COLOR, bindIndex);

	glVertexArrayVertexBuffer(m_glID, bindIndex, vbo->glID(), 0, sizeof(GLVertex));

	/*
	 *	TODO (Simon):
	 *		- refactor attribute binding/enabling to loop on a attrib desc. container	
	 *		- rethink VBO binding
	 */
	/*
	const GLVertexAttribDesc& desc = vbo.desc();

	GLuint binding = 0u;
	
	glVertexArrayAttribFormat(
		m_glID,
		GL_VERT_ATTR_POS,
		3,
		GL_FLOAT,
		GL_FALSE,
		desc.offset);

	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_POS,	binding);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_COLOR,	binding);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_NORMAL, binding);
	glVertexArrayAttribBinding(m_glID, GL_VERT_ATTR_UV,		binding);

	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_POS);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_COLOR);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_NORMAL);
	glEnableVertexArrayAttrib(m_glID, GL_VERT_ATTR_UV);

	glVertexArrayVertexBuffer(m_glID, binding, vbo.glID(), 0, 0);


	//glVertexArrayElementBuffer

	//glVertexArrayBindingDivisor(m_glID, desc.attrib, 0u);
	glVertexArrayAttribFormat(
		m_glID, 
		desc.attrib, 
		desc.size, 
		desc.type, 
		desc.normalized, 
		desc.offset);
	
	//glVertexArrayAttribIFormat(m_glID, 

	*/
}

} // namespace gl
} // namespace video
} // namespace drak