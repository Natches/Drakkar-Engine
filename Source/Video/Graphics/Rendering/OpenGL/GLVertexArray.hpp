#pragma once

#include <Video/Graphics/Rendering/Base/IRenderable.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLIndexBuffer.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLVertexArray
* \ingroup Graphics
* \brief
*
*/
class GLVertexArray final : public GLObject, public IRenderable {
public:
	GLVertexArray() = default;
	~GLVertexArray();

	void create(GLVertexBuffer* pVBO, GLIndexBuffer* pIBO);
	void render() override;

	bool			m_instanced = false;
private:
	GLVertexBuffer* m_pVBO;
	GLIndexBuffer*	m_pIBO;
	
	U32				m_vertexCount;
	GLenum			m_prim;

};

} // namespace gl
} // namespace gfx
} // namespace drak
