#pragma once

#include <Core/Core.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLUniformBuffer.hpp>

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
	void render();
	void endFrame();

private:
	void opaquePass();
	void transparentPass();

private:
	void onKeyUp(const events::Event* pEvt);

private:
	RenderQueue		m_opaqueQueue;
	RenderQueue		m_transpQueue;
	
	IRenderer*		m_pRenderer;
	IFrameBuffer*	m_pFrame;

	// Tests
	IRenderable*		 m_pUnitCube;
	gl::GLTexture		 m_gridTex;
	gl::GLUniformBuffer	 m_modelUBO;
};

} // namespace gfx
} // namespace drak
