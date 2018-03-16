#pragma once

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertex.hpp>

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

	void create(const GLVertex* vertData, U32 size);

	DK_GETTER(GLuint, glID, m_glID)
	DK_GETTER_REF_C(GLVertexAttribDesc, desc, m_desc)

private:
	GLuint				m_glID;
	GLVertexAttribDesc	m_desc;
};

} // namespace gl
} // namespace gfx
} // namespace drak