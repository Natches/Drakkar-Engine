#pragma once

#include <Video/RHI/OpenGL/GLTypes.hpp>
#include <Video/RHI/OpenGL/GLVertex.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLVertexBuffer
* \ingroup DrakVideo
* \brief
*
*/
class GLVertexBuffer final
{
public:
	GLVertexBuffer() = default;
	~GLVertexBuffer();

	void create(const void* data, U32 size);

	DK_GET(GLuint, glID, m_glID)
	DK_GET(GLuint, binding, m_binding)
	DK_GET_REF_C(GLVertexAttribDesc, desc, m_desc)

private:
	GLuint				m_glID;
	GLuint				m_binding;
	GLVertexAttribDesc	m_desc;
};

} // namespace gl
} // namespace gfx
} // namespace drak