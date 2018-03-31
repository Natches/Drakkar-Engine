#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
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
	video::VideoSettings	videoSettings	= { winSettings };

	// TODO (Simon): Check for failed startups
	videoSystem.startup(videoSettings, pMainWindow);
	renderSystem.startup(videoSystem.graphicsDriver());
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
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->Start();
	}
	
	while (pMainWindow->isOpen()) {
		s_frameTime.update();
		pMainWindow->pollEvents();
		pMainWindow->clear();
		renderSystem.startFrame();

		std::vector<AGameObject*>& gameObjects = sceneSystem.scene->getGameObjects();
		for (unsigned int i = 0; i < gameObjects.size(); ++i) {
			gameObjects[i]->Update();
		}
		std::vector<components::Transform> subArray = sceneSystem.scene->getFilteredComponentSubArray<components::Transform>(components::ComponentType<components::RigidBody>::id);
		physicsSystem.Update(sceneSystem.scene->m_pPhysXScene, s_frameTime.deltaTime(),
				sceneSystem.scene->getComponentContainerByType<components::RigidBody>(),
				&subArray);
		sceneSystem.scene->stampSubArrayIntoMainArray<components::Transform>(subArray);

		renderSystem.showFrame();
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