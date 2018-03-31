#pragma once

#include <Video/Graphics/Common/Color.hpp>
#include <Video/Graphics/Rendering/Base/RenderFunctions.hpp>

namespace drak {
namespace gfx {

/*!
* \class IGraphicsDriver
* \ingroup Graphics
* \brief
*
*/
class IGraphicsDriver {
public:
	IGraphicsDriver() = default;
	virtual ~IGraphicsDriver() = default;

public:
	virtual bool init() = 0;
	virtual void info() = 0;

	virtual void clear() = 0;
	virtual void clearColorValue(const Color3& color) = 0;
	virtual void clearColorValue(const Color4& color) = 0;
	virtual void clearDepthValue(F32 depth) = 0;

	virtual void depthTest(bool on, EDepthMode mode) = 0;
	virtual void blendTest(bool on, EBlendMode srcFactor, EBlendMode dstFactor) = 0;
	virtual void cullTest(bool on, ECullMode mode) = 0;
	virtual void windingOrder(EWindingOrder order) = 0;
};

enum EGraphicsDriver {
	OPENGL
};

} // namespace gfx
} // namespace drak

