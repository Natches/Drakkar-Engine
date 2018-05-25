#pragma once

#include <Video/Graphics/Common/Color.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>
#include <Video/Graphics/Rendering/Base/IRenderable.hpp>
#include <Video/Graphics/Rendering/Base/RenderDefinitions.hpp>

namespace drak {
namespace gfx {

/*!
* \class IRenderer
* \ingroup Graphics
* \brief
*
*/
class IRenderer {
public:
	IRenderer() = default;
	virtual ~IRenderer() = default;

public:
	virtual bool init() = 0;
	virtual void info() = 0;

	//virtual void bindFrameBuffer() = 0;
	virtual void bindWindowFrameBuffer() = 0;

	virtual void clear() = 0;
	virtual void clearColorValue(const Color3& k) = 0;
	virtual void clearColorValue(const Color4& k) = 0;
	virtual void clearDepthValue(F32 depth) = 0;

	virtual void depthTest(bool on, EDepthMode mode = EDepthMode::LEQUAL) = 0;

	virtual void blendTest(bool on,
		EBlendMode srcFactor = EBlendMode::SRC_ALPHA,
		EBlendMode dstFactor = EBlendMode::ONE_MINUS_SRC_ALPHA) = 0;

	virtual void cullTest(bool on, ECullMode mode = ECullMode::BACK) = 0;
	virtual void windingOrder(EWindingOrder order) = 0;

	virtual void multisampling(bool on) = 0;
};

enum ERenderer {
	OPENGL
};

} // namespace gfx
} // namespace drak