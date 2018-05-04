#pragma once

#include <unordered_map>

#include <Core/Core.hpp>
#include <Engine/Components/Components.hpp>
#include <Video/Graphics/Rendering/Camera.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTexture.hpp>

namespace drak {

	struct Scene;

namespace gfx {

/*!
* \class RenderSystem
* \ingroup Graphics
* \brief
*
*/
class RenderSystem final {
	DK_NONMOVABLE_NONCOPYABLE(RenderSystem)
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	bool startup(IRenderer* pRenderer);
	void shutdown();

	void forwardRender(Scene& scene);

	void startFrame();
	void endFrame();

private:
	bool loadResources(const std::string& dir);

	void opaquePass();
	void transparentPass();

private:
	Camera			m_mainCam;

	ShaderMap		m_shaderMap;
	RenderArray		m_opaqueArr;
	RenderArray		m_transpArr;

	IRenderable*	m_pUnitCube;
	IRenderable*	m_pGrid;
	gl::GLTexture	m_gridTex;
	
	IRenderer*		m_pRenderer;
	IFrameBuffer*	m_pFrame;
};

} // namespace gfx
} // namespace drak
