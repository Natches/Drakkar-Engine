#include <Video/Graphics/Rendering/RenderSystem.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>

namespace drak {
namespace gfx {

bool RenderSystem::startup(IRenderer* pRenderer) {
	m_pRenderer = pRenderer;
	m_pRenderer->info();

	m_pRenderer->depthTest(true);
	m_pRenderer->blendTest(true);
	m_pRenderer->cullTest(true);

	m_mainCam.view({ 0.f, 10.f, -10.f }, { 0.f, -5.f, 0.f }, { 0.f, 1.f, 0.f });
	m_mainCam.perspective(60.f, 16.f / 9.f, 0.1f, 1000.f);

	return loadResources("Resources/");
}

void RenderSystem::shutdown() {
	// ...
	// delete resources
}

bool RenderSystem::loadResources(const std::string& dir) {
	return (m_pRenderer->loadShaders	(dir + "Shaders/", m_shaderMap) &&
			m_pRenderer->loadRenderables(dir + "Models/cube.obj",  m_pUnitCube));
}

void RenderSystem::forwardRender(
	std::vector<components::Model>* models,
	std::vector<components::Transform>* xforms) {

	m_shaderMap["DefaultShader"]->use();
	m_shaderMap["DefaultShader"]->setUniform("viewPrsp", m_mainCam.viewPerspective());

	for (size_t i = 0, n = models->size(); i < n; ++i) {
		math::Mat4f modelMx =
			math::Translate((*xforms)[i].position) *
			math::Rotation((*xforms)[i].rotation) *
			math::Scale((*xforms)[i].scale);

		m_shaderMap["DefaultShader"]->setUniform("model", modelMx);
		m_shaderMap["DefaultShader"]->setUniform("albedo", (*models)[i].albedo);
		
		// (*models)[i].pModel->render();
		m_pUnitCube->render();
	}
}

void RenderSystem::startFrame() {
	m_pRenderer->clear();

	// opaquePass();
	// transparentPass();
}

void RenderSystem::opaquePass() {
	// for each pass (color, depth ...)
	//	 for each shader
	//		for each material (textures, uniforms ...)
	//	

	// m_pRenderer->depthTest(true);
	// m_shaderMap["DefaultShader"]->use();

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
	/*m_pRenderer->bindWindowFrameBuffer();
	m_pRenderer->clear();

	m_pRenderer->depthTest(false);
	m_shaderMap["FrameDraw"]->use();*/

	// TODO (Simon): abstract the GL code shown below (E Z P Z)
	// glBindVertexArray(quadVAO);
	// glBindTexture(GL_TEXTURE_2D, textureColorbuffer);
	// glDrawArrays(GL_TRIANGLES, 0, 6);
}


} // namespace gfx
} // namespace drak