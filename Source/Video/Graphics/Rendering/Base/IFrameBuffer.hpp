#pragma once

namespace drak {
namespace gfx {

/*!
* \class IFrameBuffer
* \ingroup Graphics
* \brief
*
*/
class IFrameBuffer {
public:
	IFrameBuffer() = default;
	virtual ~IFrameBuffer() = default;

public:
	virtual void bind() = 0;
	virtual void create(I32 dimX, I32 dimY) = 0;
};

} // namespace gfx
} // namespace drak
