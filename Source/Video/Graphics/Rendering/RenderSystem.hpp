#pragma once

#include <unordered_map>

#include <Core/Core.hpp>
#include <Engine/Components/Components.hpp>
#include <Video/Graphics/Rendering/Camera.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>

#include <Video/Graphics/Rendering/OpenGL/GLTexture.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLUniformBuffer.hpp>

namespace drak {
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

	void forwardRender(
		std::vector<components::Model>& models, 
		std::vector<components::Transform>& xforms);

	void startFrame();
	void endFrame();

private:
	bool loadResources(const std::string& dir);

	void opaquePass();
	void transparentPass();

private:
	void onKeyUp(const events::Event* pEvt);

private:
	Camera			m_mainCam;

	ShaderMap		m_shaderMap;
	RenderArray		m_opaqueArr;
	RenderArray		m_transpArr;

	IRenderable*	m_pUnitCube;
	IRenderable*	m_pGrid;

	// Tests
	gl::GLTexture	m_gridTex;
	gl::GLUniformBuffer	m_modelUBO;
	
	IRenderer*		m_pRenderer;
	IFrameBuffer*	m_pFrame;
};

} // namespace gfx
} // namespace drak
