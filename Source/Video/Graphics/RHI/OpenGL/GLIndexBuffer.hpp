#pragma once

#include <Video/Graphics/RHI/OpenGL/GLObject.hpp>

namespace drak {
namespace video {
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

	void create(const GLushort* pIndices, GLsizei indexCount);

	DK_GETTER(GLushort, indexCount, m_indexCount)

private:
	GLsizei m_indexCount;
};

} // namespace gl
} // namespace video
} // namespace drak