#pragma once

#include <Video/Graphics/RHI/OpenGL/GLObject.hpp>
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
class GLVertexBuffer final : public GLObject {
public:
	GLVertexBuffer() = default;
	~GLVertexBuffer();

	void create(
		const GLVertex*	const pVerts,
		const GLuint byteSize, 
		const GLuint bindIndex = 0u);

	DK_GETTER(GLuint, bindIndex, m_bindIndex)

private:
	GLuint	m_bindIndex;
	GLuint	m_byteSize;
};

} // namespace gl
} // namespace video
} // namespace drak