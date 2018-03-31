#pragma once

#include <Video/Graphics/Rendering/Base/RenderDefinitions.hpp>
#include <Video/Graphics/Rendering/Base/RenderFunctions.hpp>

namespace drak {
namespace gfx {

/*!
* \class IRenderDriver
* \ingroup Graphics
* \brief
*
*/
class IRenderDriver {
public:
	IRenderDriver() = default;
	virtual ~IRenderDriver() = default;

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

} // namespace gfx
} // namespace drak

