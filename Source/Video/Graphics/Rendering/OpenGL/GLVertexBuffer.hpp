#pragma once

#include <Video/Graphics/Rendering/Base/AVertexBuffer.hpp>
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
class GLVertexBuffer final : public GLObject, public AVertexBuffer {
public:
	GLVertexBuffer();
	~GLVertexBuffer();

	void create(
		const void*	pVerts,
		const U32	vertexCount,
		const U32	vertexSize);

	DK_GETTER_C(GLuint, bindIndex, m_bindIndex)

private:
	GLuint	m_bindIndex;
};

} // namespace gl
} // namespace gfx
} // namespace drak