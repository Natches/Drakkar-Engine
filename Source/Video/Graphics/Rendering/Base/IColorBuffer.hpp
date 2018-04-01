#pragma once

namespace drak {
namespace gfx {

/*!
* \class IColorBuffer
* \ingroup Graphics
* \brief
*
*/
class IColorBuffer {
public:
	IColorBuffer() = default;
	virtual ~IColorBuffer() = default;

public:
	virtual void attach() = 0;
	virtual void create(I32 dimX, I32 dimY) = 0;
};

} // namespace gfx
} // namespace drak
