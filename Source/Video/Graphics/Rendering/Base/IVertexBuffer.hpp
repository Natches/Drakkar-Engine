#pragma once

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
class IVertexBuffer {
public:
	IVertexBuffer() = default;
	virtual ~IVertexBuffer() = default;

	virtual void create(
		const void*	pData,
		const U32	vertexCount,
		const U32	attribCount) = 0;
};

} // namespace gfx
} // namespace drak