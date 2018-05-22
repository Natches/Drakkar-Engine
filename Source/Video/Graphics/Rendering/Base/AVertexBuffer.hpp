#pragma once

#include <Core/Utils/ClassUtils.hpp>

namespace drak {

#pragma region Forward Declarations
namespace geom {
struct VertexAttribDesc;
}
#pragma endregion

namespace gfx {

/*!
* \class IVertexBuffer
* \ingroup DrakVideo
* \brief
*
*/
class AVertexBuffer {
public:
	AVertexBuffer() : 
		m_attribDescs(nullptr), 
		m_attribCount(0u),
		m_vertexCount(0u), 
		m_vertexSize(0u) {};
	virtual ~AVertexBuffer() = default;

	virtual void create(
		const void*						pVerts,
		const geom::VertexAttribDesc*	attribDescs,
		const U32						attribCount,
		const U32						vertexCount,
		const U32						vertexSize) = 0;

	DK_GETTER_C(const geom::VertexAttribDesc*,	attribDescs,	m_attribDescs)
	DK_GETTER_C(U32,							attribCount,	m_attribCount)
	DK_GETTER_C(U32,							vertexCount,	m_vertexCount)
	DK_GETTER_C(U32,							vertexSize,		m_vertexSize)

protected:
	const geom::VertexAttribDesc*	m_attribDescs;
	U32								m_attribCount;
	U32								m_vertexCount;
	U32								m_vertexSize;
};

} // namespace gfx
} // namespace drak