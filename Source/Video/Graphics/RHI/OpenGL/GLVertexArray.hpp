#pragma once

#include <vector>

#include <Video/Graphics/RHI/OpenGL/GLVertexBuffer.hpp>
#include <Video/Graphics/RHI/OpenGL/GLIndexBuffer.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLVertexArray
* \ingroup DrakVideo
* \brief
*
*/
class GLVertexArray final : public GLObject {
public:
	GLVertexArray() = default;
	~GLVertexArray();

	void create(const GLVertexBuffer& vbo, const GLIndexBuffer& ibo);
	void draw();

private:
	GLuint	m_iboID;
	GLsizei	m_vertCount;
};

} // namespace gl
} // namespace video
} // namespace drak
