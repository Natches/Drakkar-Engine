#pragma once

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/HighLevel/Camera.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLUniformBuffer.hpp>
#include <ResourceManager/Manager/ShaderManager.hpp>
#include <Engine/Components/ModelComponent.hpp>

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
	void renderGrid();

	void startFrame();
	void endFrame();

	inline Camera& mainCamera() { return m_mainCam; }

private:
	bool loadShaders();
	void convertModelToRenderable(const std::vector<components::Model>& models,
		ResourceSystem& manager);

	void opaquePass();
	void transparentPass();

private:
	void onKeyUp(const events::Event* pEvt);
	void onMouseEvent(const events::Event* pEvt);

private:
	Camera				m_mainCam;

	RenderQueue			m_opaqueArr;
	RenderQueue			m_transpArr;

	IRenderable*		m_pGrid;
	gl::GLTexture		m_gridTex;

	std::map<std::string, IRenderable*> m_renderable;
	std::map<std::string, gl::GLTexture> m_texture;

	IRenderer*			m_pRenderer;
	IFrameBuffer*		m_pFrame;

	gl::GLUniformBuffer	 m_modelUBO;

	ShaderManager		 m_shaderManager;
};

} // namespace gfx
} // namespace drak