#pragma once

#include <Video/Graphics/Rendering/Base/IVertexBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLVertexBuffer
* \ingroup DrakVideo
* \brief 
*
*/
class GLVertexBuffer final : public GLObject, public IVertexBuffer {
public:
	GLVertexBuffer() = default;
	~GLVertexBuffer();

	void create(
		const void*	pData,
		const U32	vertexCount
		const U32	attribCount) override;

	DK_GETTER_C(GLuint, bindIndex, m_bindIndex)
	DK_GETTER_C(GLuint, elemCount, m_elemCount)
	DK_GETTER_C(GLuint, elemSize,  m_elemSize)

private:
	GLuint	m_bindIndex;
	GLuint	m_elemCount;
	GLuint	m_elemSize;
};

} // namespace gl
} // namespace gfx
} // namespace drak