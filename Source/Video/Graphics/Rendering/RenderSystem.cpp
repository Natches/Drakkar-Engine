#include <Video/Graphics/Rendering/RenderSystem.hpp>

namespace drak {
namespace gfx {

bool RenderSystem::startup(IRenderer* pRenderer) {
	m_pRenderer = pRenderer;

	m_pRenderer->depthTest(true /* + read option from .ini */);
	m_pRenderer->blendTest(true /* + read option from .ini */);
	m_pRenderer->cullTest(true  /* + read option from .ini */);

	return loadResources("Resources/");
}

void RenderSystem::shutdown() {
	// ...
	// delete resources
}

bool RenderSystem::loadResources(const std::string& dir) {
	return (m_pRenderer->loadShaders	(dir + "Shaders/", m_shaderMap) &&
			m_pRenderer->loadRenderables(dir + "Models/",  m_opaqueArr));
}

void RenderSystem::startFrame() {
	m_pRenderer->clear();

	opaquePass();
	transparentPass();
}

void RenderSystem::opaquePass() {
	// for each pass (color, depth ...)
	//	 for each shader
	//		for each material (textures, uniforms ...)

	m_pRenderer->depthTest(true);

	for (auto pOpaque : m_opaqueArr)
		pOpaque->render();
}

void RenderSystem::transparentPass() {
	// sort back-to-front

	// for each pass (... blending ...)
	//	 for each shader
	//		for each material (...)

	for (auto pTransp : m_transpArr)
		pTransp->render();
}

void RenderSystem::endFrame() {
	m_pRenderer->bindWindowFrameBuffer();
	m_pRenderer->clear();

	m_pRenderer->depthTest(false);
	//m_shaderMap["FrameDraw"]->use();

	// TODO (Simon): abstract the GL code shown below (E Z P Z)
	// glBindVertexArray(quadVAO);
	// glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	// glDrawArrays(GL_TRIANGLES, 0, 6);
}


} // namespace gfx
} // namespace drak