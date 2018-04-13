#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Windowing/Window/AWindow.hpp>

using namespace drak::components;
using namespace drak::time;
using namespace drak::thread;
using namespace drak::video;
using namespace drak::gfx;

namespace drak {
namespace core {
ThreadPool Engine::s_pool;
bool Engine::s_running = true;

Engine::Engine() {

}

Engine::~Engine() {

}

PhysicsSystem& Engine::getPhysicsSystem()
{
	return m_physicsSystem;
}

int Engine::startup() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");

	WindowSettings	winSettings		= { "Drakkar Engine", 1600, 900 };
	VideoSettings	videoSettings	= { winSettings, ERenderer::OPENGL };

	m_videoSystem.startup(videoSettings, m_pMainWindow);
	m_renderSystem.startup(m_videoSystem.renderer());
	m_resourceSystem.startup();
	m_sceneSystem.Startup();
	s_pool.startup();
	m_physicsSystem.Startup();
	m_physicsSystem.InitPxScene(&m_sceneSystem.scene->m_pPhysXScene);

	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	m_sceneSystem.Shutdown();
	m_physicsSystem.Shutdown();
	m_renderSystem.shutdown();
	m_videoSystem.shutdown();
	
	Logbook::CloseLogs();
	s_pool.shutdown();

	return 0;
}

void Engine::startLoop() {
	s_frameTime.start();

	std::vector<AGameObject*>& gameObjects = m_sceneSystem.scene->getGameObjects();
	for (auto g : gameObjects)
		g->Start();
	
	while (m_pMainWindow->isOpen()) {
		s_frameTime.update();
		m_pMainWindow->pollEvents();

		gameObjects = m_sceneSystem.scene->getGameObjects();
		for (auto g : gameObjects)
			g->Update();

		m_physicsSystem.Update(*m_sceneSystem.scene, s_frameTime.deltaTime(),
				*m_sceneSystem.scene->getComponentContainerByType<RigidBody>(),
				*m_sceneSystem.scene->getComponentContainerByType<Transform>());

		F32 t0 = s_frameTime.duration();
		m_pMainWindow->clear();
		m_renderSystem.startFrame();
		// render scene
		m_renderSystem.endFrame();
		m_pMainWindow->swapBuffers();
		F32 t1 = s_frameTime.duration() - t0;

		std::cout << "RenderSystem time: " << t1 * (F32)ATimer::TimeDuration::MILLISECONDS << " ms\n";
		//Logbook::Log(Logbook::EOutput::CONSOLE, "Rendering: ", "%.6f ms\n", renderTime);
	}
	s_frameTime.stop();
}

void Engine::stopGame() {
	Engine::s_running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	m_sceneSystem.loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak