#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Windowing/Window/AWindow.hpp>

using namespace drak::components;
using namespace drak::time;

namespace drak {
namespace core {
thread::ThreadPool core::Engine::s_pool;
bool Engine::running = true;

Engine::Engine() {

}

Engine::~Engine() {

}

PhysicsSystem& Engine::getPhysicsSystem()
{
	return physicsSystem;
}

int Engine::startup() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	video::WindowSettings	winSettings		= { "Drakkar Engine", 1600, 900 };
	video::VideoSettings	videoSettings	= { winSettings, gfx::ERenderer::OPENGL };

	// TODO (Simon): Check for failed startups
	videoSystem.startup(videoSettings, pMainWindow);
	renderSystem.startup(videoSystem.renderer());
	sceneSystem.Startup();
	s_pool.startup();
	physicsSystem.Startup();
	physicsSystem.InitPxScene(&sceneSystem.scene->m_pPhysXScene);

	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	sceneSystem.Shutdown();
	physicsSystem.Shutdown();
	renderSystem.shutdown();
	videoSystem.shutdown();
	
	Logbook::CloseLogs();
	s_pool.shutdown();

	return 0;
}

void Engine::startLoop() {
	s_frameTime.start();

	std::vector<AGameObject*>& gameObjects = sceneSystem.scene->getGameObjects();
	for (auto g : gameObjects)
		g->Start();
	
	while (pMainWindow->isOpen()) {
		s_frameTime.update();
		pMainWindow->pollEvents();

		gameObjects = sceneSystem.scene->getGameObjects();
		for (auto g : gameObjects)
			g->Update();

		physicsSystem.Update(*sceneSystem.scene, s_frameTime.deltaTime(),
				*sceneSystem.scene->getComponentContainerByType<RigidBody>(),
				*sceneSystem.scene->getComponentContainerByType<Transform>());

		F32 t0 = s_frameTime.duration();
		pMainWindow->clear();
		renderSystem.startFrame();
		// render scene
		renderSystem.endFrame();
		pMainWindow->swapBuffers();
		F32 t1 = s_frameTime.duration() - t0;

		std::cout << "RenderSystem time: " << t1 * (F32)ATimer::TimeDuration::MILLISECONDS << " ms\n";
		//Logbook::Log(Logbook::EOutput::CONSOLE, "Rendering: ", "%.6f ms\n", renderTime);
	}
	s_frameTime.stop();
}

void Engine::stopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	sceneSystem.loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak