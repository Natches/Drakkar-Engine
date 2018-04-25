#include <PrecompiledHeader/pch.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/Rendering/RenderSystem.hpp>



using namespace drak::components;

namespace drak {
namespace core {
thread::ThreadPool Engine::s_pool;
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


	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	video::WindowSettings	winSettings		= { "DrakVideoTest", 1600, 900 };
	video::VideoSettings	videoSettings	= { winSettings, gfx::ERenderer::OPENGL };
	video::WindowSettings	winSettings		= { "Drakkar Engine", 1600, 900 };
	video::VideoSettings	videoSettings	= { winSettings, gfx::ERenderer::OPENGL };

	// TODO (Simon): Check for failed startups
	m_pVideoSystem->startup(videoSettings, m_pMainWindow);
	
	m_pRenderSystem->startup(m_pVideoSystem->renderer());
	
	m_pPhysicsSystem->Startup();
	
	m_pLevelSystem->startup();
	
	s_pool.startup();
	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	m_pLevelSystem->shutdown();
	m_pPhysicsSystem->Shutdown();
	m_pRenderSystem->shutdown();
	m_pVideoSystem->shutdown();
	
	Logbook::CloseLogs();
	s_pool.shutdown();

	return 0;
}

void Engine::startLoop() {
	s_frameTime.start();

	std::vector<AGameObject*>& gameObjects = m_pLevelSystem->getGameObjects();
	for (U32 i = 0; i < gameObjects.size(); ++i ) {
		m_pPhysicsSystem->InitRigidBody(gameObjects[i]->getComponent<RigidBody>(), gameObjects[i]->getComponent<Transform>(), *m_pLevelSystem);
		gameObjects[i]->start();
	}

	
	while (m_pMainWindow->isOpen()) {
		s_frameTime.update();
		m_pMainWindow->pollEvents();

		gameObjects = m_pLevelSystem->getGameObjects();
		for (U64 i = 0, size = gameObjects.size(); i < size; ++i)
			gameObjects[i]->update();

		if(m_pPhysicsSystem->advance(s_frameTime.deltaTime(), *m_pLevelSystem))
			m_pPhysicsSystem->updateComponents(*m_pLevelSystem);

		m_pMainWindow->clear();
		m_pRenderSystem->startFrame();
		m_pRenderSystem->forwardRender(m_pLevelSystem->getScene());
		
		m_pRenderSystem->endFrame();
		m_pMainWindow->swapBuffers();
	}
	s_frameTime.stop();
}

void Engine::StopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	m_pLevelSystem->loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak