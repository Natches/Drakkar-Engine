#pragma once

#include <Video/Graphics/Common/Color.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>
#include <Video/Graphics/Rendering/Base/RenderFunctions.hpp>

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

	virtual bool loadShaders(ShaderMap& shaderMap) = 0;
	virtual void useShader(const std::string& shaderName) = 0;

	virtual void clear() = 0;
	virtual void clearColorValue(const Color3& color) = 0;
	virtual void clearColorValue(const Color4& color) = 0;
	virtual void clearDepthValue(F32 depth) = 0;

	virtual void depthTest(bool on, EDepthMode mode) = 0;
	virtual void blendTest(bool on, EBlendMode srcFactor, EBlendMode dstFactor) = 0;
	virtual void cullTest(bool on, ECullMode mode) = 0;
	virtual void windingOrder(EWindingOrder order) = 0;

	//virtual void bindFrameBuffer() = 0;
	virtual void useWindowFrameBuffer() = 0;
};

enum ERenderer {
	OPENGL
};

} // namespace gfx
} // namespace drak

