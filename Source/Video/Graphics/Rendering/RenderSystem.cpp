#include <Video/Graphics/Rendering/RenderSystem.hpp>

namespace drak {
namespace gfx {

bool RenderSystem::startup(IRenderer* pRenderer) {
	m_pRenderer = pRenderer;
	return true;
}

void RenderSystem::shutdown() {

}

void RenderSystem::startFrame() {
	m_pRenderer->clear();
}

void RenderSystem::endFrame() {
	m_pRenderer->useWindowFrameBuffer();
	m_pRenderer->clear();
	
	// screenShader.use();
	// glBindVertexArray(quadVAO);
	// glDisable(GL_DEPTH_TEST);
	// glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	// glDrawArrays(GL_TRIANGLES, 0, 6);

	// draw frame to window-sized quad
}


} // namespace gfx
} // namespace drak