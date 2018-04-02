#pragma once

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
class GLVertexBuffer final : public GLObject {
public:
	GLVertexBuffer() = default;
	~GLVertexBuffer();

	void create(
		const geom::Vertex* const pVerts,
		const GLuint vertCount,
		const GLuint bindIndex = 0u);

	DK_GETTER_C(GLuint, bindIndex, m_bindIndex)

private:
	GLuint	m_bindIndex;
};

} // namespace gl
} // namespace gfx
} // namespace drak