#pragma once

#include <vector>

#include <Video/Graphics/Rendering/OpenGL/GLVertexBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLIndexBuffer.hpp>

namespace drak {
namespace gfx {
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
} // namespace gfx
} // namespace drak
