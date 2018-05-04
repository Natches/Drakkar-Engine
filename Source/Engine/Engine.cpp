#include <PrecompiledHeader/pch.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/GameObject.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/Rendering/RenderSystem.hpp>



using namespace drak::components;
using namespace drak::time;

namespace drak {
namespace core {
bool Engine::running = true;

Engine::Engine() {
	m_pVideoSystem = new video::VideoSystem();
	m_pRenderSystem = new gfx::RenderSystem();
	m_pPhysicsSystem = new PhysicsSystem;
	m_pLevelSystem = new LevelSystem;
}

Engine::~Engine() {
	delete m_pVideoSystem;
	delete m_pRenderSystem;
	delete m_pPhysicsSystem;
	delete m_pLevelSystem;
}

PhysicsSystem& Engine::getPhysicsSystem()
{
	return *m_pPhysicsSystem;
}

DRAK_API time::FrameTimer& Engine::GetFrameTimer() {
	return s_frameTime;
}

DRAK_API LevelSystem & Engine::currentLevel()
{
		return *m_pLevelSystem;
}

int Engine::startup() {
	events::EngineEvent eEvent;
	eEvent.type = events::EngineEventDispatcher::STARTUP_BEGIN;
	m_eventDispatcher.dispatchEvent(&eEvent);

	//Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	video::WindowSettings	winSettings		= { "DrakVideoTest", 1600, 900 };
	video::VideoSettings	videoSettings	= { winSettings, gfx::ERenderer::OPENGL };

	// TODO (Simon): Check for failed startups
	m_pVideoSystem->startup(videoSettings, m_pMainWindow);
	
	m_pRenderSystem->startup(m_pVideoSystem->renderer());
	
	m_pPhysicsSystem->Startup();
	
	m_pLevelSystem->startup();
	
	m_pool.startup();

	eEvent.type = events::EngineEventDispatcher::STARTUP_END;
	m_eventDispatcher.dispatchEvent(&eEvent);
	return 0;
}

int Engine::shutdown() {
	events::EngineEvent eEvent;
	eEvent.type = events::EngineEventDispatcher::SHUTDOWN_START;
	m_eventDispatcher.dispatchEvent(&eEvent);
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	m_pLevelSystem->shutdown();
	m_pPhysicsSystem->Shutdown();
	m_pRenderSystem->shutdown();
	m_pVideoSystem->shutdown();
	
	Logbook::CloseLogs();
	m_pool.shutdown();
	eEvent.type = events::EngineEventDispatcher::SHUTDOWN_END;
	m_eventDispatcher.dispatchEvent(&eEvent);
	return 0;
}

void Engine::startLoop() {
	s_frameTime.start();

	std::vector<GameObject>& gameObjects = m_pLevelSystem->getGameObjects();
	for (U32 i = 0; i < gameObjects.size(); ++i ) {
		m_pPhysicsSystem->InitRigidBody(gameObjects[i].getComponent<RigidBody>(), gameObjects[i].getComponent<Transform>(), *m_pLevelSystem);
	}

	events::EngineEvent eEvent;
	eEvent.type = events::EngineEventDispatcher::UPDATE_START;
	m_eventDispatcher.dispatchEvent(&eEvent);

	while (m_pMainWindow->isOpen()) {
		s_frameTime.update();
		m_pMainWindow->pollEvents();

		eEvent.type = events::EngineEventDispatcher::UPDATE_LOOP_START;
		m_eventDispatcher.dispatchEvent(&eEvent);

		//gameObjects = m_pLevelSystem->getGameObjects();
		//for (U64 i = 0, size = gameObjects.size(); i < size; ++i)
		//	gameObjects[i]->update();

		if(m_pPhysicsSystem->advance(s_frameTime.deltaTime(), *m_pLevelSystem))
			m_pPhysicsSystem->updateComponents(*m_pLevelSystem);

		m_pMainWindow->clear();
		m_pRenderSystem->startFrame();
		m_pRenderSystem->forwardRender(m_pLevelSystem->getScene());
		
		m_pRenderSystem->endFrame();
		m_pMainWindow->swapBuffers();
		eEvent.type = events::EngineEventDispatcher::UPDATE_LOOP_END;
		m_eventDispatcher.dispatchEvent(&eEvent);
	}
	s_frameTime.stop();
	eEvent.type = events::EngineEventDispatcher::UPDATE_END;
	m_eventDispatcher.dispatchEvent(&eEvent);
}

void Engine::StopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	m_pLevelSystem->loadScene(sceneBlueprint);
}

void Engine::loadScene(const char* filename) {
	m_pLevelSystem->loadScene(filename);
}



} // namespace core
} // namespace drak