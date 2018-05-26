#include <PrecompiledHeader/pch.hpp>
#include <Engine/Engine.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/Rendering/RenderSystem.hpp>

using namespace drak::components;
using namespace drak::time;
using namespace drak::thread;
using namespace drak::video;
using namespace drak::gfx;

namespace drak {
namespace core {
Engine* Engine::m_pInstance = nullptr;

bool Engine::s_running = true;

Engine::Engine() {
	m_pVideoSystem		= new video::VideoSystem();
	m_pRenderSystem		= new gfx::RenderSystem();
	m_pPhysicsSystem	= new PhysicsSystem;
	m_pLevelSystem		= new LevelSystem;
}

Engine::~Engine() {
	delete m_pVideoSystem;
	delete m_pRenderSystem;
	delete m_pPhysicsSystem;
	delete m_pLevelSystem;
}

DRAK_API drak::PhysicsSystem& Engine::getPhysicsSystem(){
	return *m_pPhysicsSystem;
}

DRAK_API LevelSystem & Engine::currentLevel(){
		return *m_pLevelSystem;
}

int Engine::startup(bool editorMode) {
	m_editorMode = editorMode;

	m_evt.type = events::EngineEventDispatcher::STARTUP_BEGIN;
	m_eventDispatcher.dispatchEvent(&m_evt);

	video::WindowSettings  winSettings		= { "DrakVideoTest", 1600, 900 };
	video::VideoSettings   videoSettings	= { winSettings, gfx::ERenderer::OPENGL };

	bool videoStatus = m_editorMode ?
		m_pVideoSystem->startup(videoSettings) :
		m_pVideoSystem->startup(videoSettings, m_pMainWindow);

	if (videoStatus
		&& m_pRenderSystem->startup(m_pVideoSystem->renderer())
		&& m_pPhysicsSystem->Startup()
		&& m_pLevelSystem->startup()
		&& m_pool.startup()) {

		m_evt.type = events::EngineEventDispatcher::STARTUP_END;
		m_eventDispatcher.dispatchEvent(&m_evt);

		return 0;
	}
	return 1;
}

int Engine::shutdown() {
	m_evt.type = events::EngineEventDispatcher::SHUTDOWN_START;
	m_eventDispatcher.dispatchEvent(&m_evt);

	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	m_pLevelSystem->shutdown();
	m_pPhysicsSystem->Shutdown();
	m_pRenderSystem->shutdown();
	m_pVideoSystem->shutdown();

	Logbook::CloseLogs();
	m_pool.shutdown();
	m_evt.type = events::EngineEventDispatcher::SHUTDOWN_END;
	m_eventDispatcher.dispatchEvent(&m_evt);

	return 0;
}

void Engine::startLoop() {
	if (m_editorMode)
		return;

	s_frameTime.start();

	std::vector<GameObject>& gameObjects = m_pLevelSystem->getGameObjects();
	for (auto& go : gameObjects) {
		if(go.getComponentFlag(ComponentType<RigidBody>::id))
			m_pPhysicsSystem->InitRigidBody(*go.getComponent<RigidBody>(), *go.getComponent<Transform>(), *m_pLevelSystem);
	}

	m_evt.type = events::EngineEventDispatcher::UPDATE_START;
	m_eventDispatcher.dispatchEvent(&m_evt);

	while (s_running) {
		s_frameTime.update();
		m_pMainWindow->pollEvents();

		m_evt.type = events::EngineEventDispatcher::UPDATE_LOOP_START;
		m_eventDispatcher.dispatchEvent(&m_evt);

		m_pLevelSystem->propogateMovementFromRoots();

		if(m_pPhysicsSystem->advance(s_frameTime.deltaTime(), *m_pLevelSystem))
			m_pPhysicsSystem->updateComponents(*m_pLevelSystem);

		m_pMainWindow->clear();
		renderScene();
		m_pMainWindow->swapBuffers();

		m_evt.type = events::EngineEventDispatcher::UPDATE_LOOP_END;
		m_eventDispatcher.dispatchEvent(&m_evt);
	}
	s_frameTime.stop();
	m_evt.type = events::EngineEventDispatcher::UPDATE_END;
	m_eventDispatcher.dispatchEvent(&m_evt);
}

void Engine::renderScene() {
	m_pRenderSystem->startFrame();
	//m_pRenderSystem->renderGrid();
	m_pRenderSystem->forwardRender(m_pLevelSystem->getScene());
	m_pRenderSystem->endFrame();
}

void Engine::StopGame() {
	s_running = false;
}

void Engine::loadScene(IManualSceneBlueprint& sceneBlueprint) {
	m_pLevelSystem->loadScene(sceneBlueprint);
}

void Engine::loadScene(const char* filename) {
	m_pLevelSystem->loadScene(filename);
}

DRAK_API Engine& Engine::Get(){
	if (!m_pInstance)
		m_pInstance = new Engine();
	return *m_pInstance;
}



} // namespace core
} // namespace drak