#include <PrecompiledHeader/pch.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>
#include <ResourceManager/Resource/Resource.hpp>

#define BATCH_SIZE 1024u

using namespace drak::events;
using namespace drak::function;
using namespace drak::components;
using namespace drak::math;

namespace drak {
namespace gfx {

bool RenderSystem::startup(IRenderer* pRenderer) {
	Keyboard::Get().addEventListener(
		KeyEvent::KEY_UP,
		new MemberFunction<RenderSystem, void, const Event*>
		(this, &RenderSystem::onKeyUp, &Keyboard::Get().event()));

	m_pRenderer = pRenderer;
	m_pRenderer->info();

	m_pRenderer->depthTest(true);
	m_pRenderer->blendTest(true);
	m_pRenderer->cullTest(true);

	m_mainCam.view({ 0.f, 0.f, 10.f }, { 0.f, 0.f, 0.f }, { 0.f, 1.f, 0.f });
	m_mainCam.perspective(60.f, 16.f / 9.f, 1.f, 2048.f);

	//m_gridTex.loadFromFile("Resources/Textures/grid_cell.png");
	m_modelUBO.create(BATCH_SIZE * sizeof(math::Mat4f));

	return loadShaders();
}

void RenderSystem::shutdown() {
	for (auto& model : m_renderables)
		delete model.second;
}

//void RenderSystem::toggleWireframe() {
	//m_pRenderer->
//}

void RenderSystem::forwardRender(Scene& scene) {
	convertModelToRenderable(scene.models, scene.resourceManager);
	m_pRenderer->cullTest(true);
	IShader* pShader = m_shaderManager.get("DefaultShader")->resource();
	pShader->use();
	pShader->uniform("viewPrsp", m_mainCam.viewPerspective());

	const Transform* pXform;
	Quaternion	quat;
	Mat4f		modelMx;
	m_pRenderer->polygonMode(ECullMode::BOTH, EPolygonMode::FILL);
	pShader->uniform("lightColor", { 1.f, 1.f, 1.f });
	for (auto& model : scene.models) {
		const gfx::Model& mdl = scene.resourceManager.loadOrGet<Model>(model.name)->resource();
		if (mdl.isSkinned())
			continue;

		pXform	= scene.gameObjects[model.GameObjectID].getComponent<Transform>();
		quat	= pXform->getGlobalRotation();
		modelMx =
			Translate(pXform->getGlobalPosition()) *
			quat.matrix() *
			Scale(pXform->getGlobalScale());

		auto& mat = scene.resourceManager.loadOrGet<Material>(mdl.materialName)->resource();

		pShader->uniform("model",			modelMx);
		pShader->uniform("ambientColor",	mat.ambientColor);
		pShader->uniform("diffuseColor",	mat.diffuseColor);
		pShader->uniform("specularColor",	mat.specularColor);
		pShader->uniform("shininess",		mat.shininess);

		m_renderables[model.name]->render();
	}

	/*m_pRenderer->polygonMode(ECullMode::BOTH, EPolygonMode::LINE);
	pShader->uniform("lightColor", { 0.f, 0.f, 0.f });
	for (auto& box : scene.hitBoxes) {
		pXform = scene.gameObjects[box.GameObjectID].getComponent<Transform>();
		quat = pXform->getGlobalRotation();
		modelMx =
			Translate(pXform->getGlobalPosition()) *
			quat.matrix() *
			Scale(pXform->getGlobalScale());

		Mat4f boxMx =
			Translate(box.localPosition) *
			Rotation(box.localRotation) *
			Scale(Vec3f(box.width, box.height, box.depth));

		pShader->uniform("model", modelMx * boxMx);
		pShader->uniform("ambientColor", {0.f, 1.f, 0.f});

		m_renderables["pCube1"]->render();
	}*/

	/*U32 flag = 1u << ComponentType<components::Model>::id;
	std::vector<math::Mat4f> modelBatch;
	for (size_t B = 0u, n = scene.models.size(); B < n; B += BATCH_SIZE) {
		modelBatch.reserve(BATCH_SIZE);
		for (size_t b = B; b < BATCH_SIZE && b < n; ++b) {
			Transform& t = *scene.gameObjects[scene.models[b].GameObjectID].getComponent<Transform>();
			math::Quaternion q = t.getGlobalRotation();
			math::Mat4f model =
				math::Translate(t.getGlobalPosition()) *
				q.matrix() *
				math::Scale(t.getGlobalScale());
			modelBatch.push_back(model);
		}
		m_modelUBO.write(0, modelBatch.size() * sizeof(math::Mat4f), modelBatch.data());
		m_modelUBO.bind();
		modelBatch.clear();
	}*/
	//renderGrid();
	renderSkinnedMeshes(scene);
}

void RenderSystem::renderGrid() {
	m_pRenderer->cullTest(false);

	math::Mat4f mvp = m_mainCam.viewPerspective()
		* math::Translate<F32>({ 0.f, -100.f, 0.f })
		* math::Scale<F32>({ 2048.f, 1.f, 2048.f });

	ShaderPtr shader = m_shaderManager.get("GridShader");
	shader->resource()->use();

	m_gridTex.bind();
	shader->resource()->uniform("tex", 0);
	shader->resource()->uniform("MVP", mvp);
	shader->resource()->uniform("resolution", math::Vec2f{ 64.f, 64.f });
	shader->resource()->uniform("tint", math::Vec4f{ 0.259f, 0.957f, 0.843f, 1.f });
	m_pGrid->render();
}

void RenderSystem::startFrame() {
	m_pRenderer->clear();

	// opaquePass();
	// transparentPass();
}

bool drak::gfx::RenderSystem::loadShaders() {
	m_shaderManager.preload("InstanceShader");
	m_shaderManager.preload("DefaultShader");
	m_shaderManager.preload("GridShader");
	m_shaderManager.preload("SkinningShader");
	return m_shaderManager.load("InstanceShader", "instanced.vert", "default.frag") &&
		m_shaderManager.load("DefaultShader", "default.vert", "default.frag") &&
		m_shaderManager.load("GridShader", "grid.vert", "grid.frag") &&
		m_shaderManager.load("SkinningShader", "skinning.vert", "default.frag");
}

void RenderSystem::convertModelToRenderable(const std::vector<components::Model>& models,
	ResourceSystem& manager) {
	for (auto& model : models) {
		if (m_renderables.find(model.name) == m_renderables.end() &&
			m_skinnedRenderables.find(model.name) == m_skinnedRenderables.end()) {
			ModelPtr modelPtr = manager.loadOrGet<gfx::Model>(model.name);
			if (modelPtr->loadState() == Resource<geom::Mesh>::ELoadState::READY) {
				if (!modelPtr->resource().isSkinned()) {
					MeshPtr mesh = manager.loadOrGet<geom::Mesh>(model.name);
					gl::GLVertexBuffer* vertBuffer = new gl::GLVertexBuffer();
					vertBuffer->create(mesh->resource().vertices().data(), geom::g_VertexAttribDesc, 3,
						(U32)mesh->resource().vertices().size(), (U32)(sizeof(geom::Vertex1P1N1UV)));
					gl::GLIndexBuffer* indexBuffer = new gl::GLIndexBuffer();
					indexBuffer->create(mesh->resource().indices().data(), (U32)mesh->resource().indices().size());
					gl::GLVertexArray* vertexArray = new gl::GLVertexArray();
					vertexArray->create(vertBuffer, indexBuffer);
					m_renderables[model.name] = vertexArray;
				}
				else {
					SkinnedMeshPtr& mesh = manager.loadOrGet<geom::SkinnedMesh>(model.name);
					gl::GLVertexBuffer* vertBuffer = new gl::GLVertexBuffer();
					vertBuffer->create(mesh->resource().vertices().data(), geom::g_SkinnedVertexAttribDesc, 5,
						(U32)mesh->resource().vertices().size(), (U32)(sizeof(geom::Vertex1P1N1UV1B1W)));
					gl::GLIndexBuffer* indexBuffer = new gl::GLIndexBuffer();
					indexBuffer->create(mesh->resource().indices().data(),
						(U32)mesh->resource().indices().size());
					gl::GLVertexArray* vertexArray = new gl::GLVertexArray();
					vertexArray->create(vertBuffer, indexBuffer);
					m_skinnedRenderables[model.name] = vertexArray;
				}
			}
		}
	}
}

void RenderSystem::renderSkinnedMeshes(Scene& scene) {
	IShader* pShader = m_shaderManager.get("SkinningShader")->resource();
	pShader->use();
	pShader->uniform("viewPrsp", m_mainCam.viewPerspective());

	const Transform* pXform;
	Quaternion	quat;
	Mat4f		modelMx;
	m_pRenderer->polygonMode(ECullMode::BOTH, EPolygonMode::FILL);
	pShader->uniform("lightColor", { 1.f, 1.f, 1.f });
	U32 i = 0;
	for (auto& model : scene.models) {
		const gfx::Model& mdl = scene.resourceManager.loadOrGet<Model>(model.name)->resource();
		if (mdl.isSkinned()) {
			Animator* animator = scene.gameObjects[model.GameObjectID].getComponent<Animator>();
			U32 matriceCount = static_cast<U32>(animator ? scene.animationScene.matricies()[i].size() : scene.resourceManager.loadOrGet<geom::SkinnedMesh>(model.name)->resource().skeleton().boneCount());
			const std::vector<math::Mat4f>& matricies = animator ? scene.animationScene.matricies()[i] : scene.resourceManager.loadOrGet<geom::SkinnedMesh>(model.name)->resource().skeleton().bindPose();
			if (m_buffers.find(mdl.meshName) == m_buffers.end()) {
				m_buffers[mdl.meshName].create(matriceCount * sizeof(math::Mat4f), (void*)matricies.data());
			}
			m_buffers[mdl.meshName].bind();
			m_buffers[mdl.meshName].write(0, matriceCount * sizeof(math::Mat4f),
				(void*)matricies.data());

			pXform = scene.gameObjects[model.GameObjectID].getComponent<Transform>();
			quat = pXform->getGlobalRotation();
			modelMx =
				Translate(pXform->getGlobalPosition()) *
				quat.matrix() *
				Scale(pXform->getGlobalScale());

			auto& mat = scene.resourceManager.loadOrGet<Material>(mdl.materialName)->resource();

			pShader->uniform("model", modelMx);
			pShader->uniform("ambientColor", mat.ambientColor);
			pShader->uniform("diffuseColor", mat.diffuseColor);
			pShader->uniform("specularColor", mat.specularColor);
			pShader->uniform("shininess", mat.shininess);

			m_skinnedRenderables[mdl.meshName]->render();
		}
	}
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
}

void RenderSystem::onKeyUp(const events::Event* pEvt) {
	static bool toggle = false;

	auto k = static_cast<const KeyEvent*>(pEvt);
	DK_SELECT(k->key)
		DK_CASE(Key::KEY_0, m_pRenderer->multisampling(toggle); toggle = !toggle)
	DK_END
}

void RenderSystem::onMouseEvent(const events::Event* pEvt) {
	auto m = static_cast<const MouseEvent*>(pEvt);
	std::cout << m->xPos << "; " << m->yPos << "\n";
	//DK_SELECT(m->btn)
	//	DK_CASE(MouseEvent::MOUSE_LEFT, std::cout << "Left\n")
	//	DK_CASE(MouseEvent::MOUSE_RIGHT, std::cout << "Right\n")
	//DK_END
}

} // namespace gfx
} // namespace drak