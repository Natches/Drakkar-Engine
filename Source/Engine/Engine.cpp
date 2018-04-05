#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Windowing/Window/AWindow.hpp>

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
	video::WindowSettings	winSettings		= { "DrakVideoTest", 1600, 900 };
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
				*sceneSystem.scene->getComponentContainerByType<components::RigidBody>(),
				*sceneSystem.scene->getComponentContainerByType<components::Transform>());

		pMainWindow->clear();
		renderSystem.startFrame();
		renderSystem.forwardRender(*sceneSystem.scene->getComponentContainerByType<components::Model>(),
			*sceneSystem.scene->getComponentContainerByType<components::Transform>());
		
		renderSystem.endFrame();
		pMainWindow->swapBuffers();
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