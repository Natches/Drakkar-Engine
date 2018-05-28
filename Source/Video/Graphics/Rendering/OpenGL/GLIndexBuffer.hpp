#pragma once

#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLIndexBuffer
* \ingroup DrakVideo
* \brief
*
*/
class GLIndexBuffer final : public GLObject {
public:
	GLIndexBuffer() = default;
	~GLIndexBuffer();

	void create(const GLuint* pIndices, GLsizei indexCount);

	void drawElements(GLenum prim);
	void drawElementsInstanced(GLenum prim);

	DK_GETTER_C(GLuint, indexCount, m_indexCount)

private:
	GLsizei m_indexCount;
};

} // namespace gl
} // namespace gfx
} // namespace drak