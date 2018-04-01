#pragma once

#include <unordered_map>

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IColorBuffer.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>

namespace drak {
namespace gfx {

/*!
* \class RenderSystem
* \ingroup Graphics
* \brief
*
*/
class RenderSystem final
{
	DK_NONMOVABLE_NONCOPYABLE(RenderSystem)
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	bool startup(IRenderer* pRenderer);
	void shutdown();

	void startFrame();
	void endFrame();

private:
	bool loadResources(const std::string& dir);

	void opaquePass();
	void transparentPass();

private:
	ShaderMap		m_shaderMap;
	RenderArray		m_opaqueArr;
	RenderArray		m_transpArr;
	
	IRenderer*		m_pRenderer;
	IColorBuffer*	m_pColorBuffer;
};

} // namespace gfx
} // namespace drak
