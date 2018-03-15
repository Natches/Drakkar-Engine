#pragma once

#include <vector>

#include <Video/RHI/OpenGL/GLTypes.hpp>
#include <Video/RHI/OpenGL/GLVertexBuffer.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLVertexArray
* \ingroup DrakVideo
* \brief
*
*/
class GLVertexArray final
{
public:
	GLVertexArray() = default;
	~GLVertexArray();

	void create(const std::vector<GLVertex>& verts);
	void bindVertexBuffer(const GLVertexBuffer& vbo);
	void draw();

private:
	GLuint m_glID;
};

} // namespace gl
} // namespace gfx
} // namespace drak
