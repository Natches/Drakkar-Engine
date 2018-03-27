#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>


namespace drak {
namespace core {
thread::ThreadPool core::Engine::s_pool;
bool Engine::running = true;

Engine::Engine() {

}

Engine::~Engine() {

}

int Engine::startup() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	GetInstance().sceneSystem.Startup();
	GetInstance().s_frameTime.start();
	s_pool.startup();
	GetInstance().physicsSystem.Startup();
	GetInstance().physicsSystem.InitPxScene(&GetInstance().sceneSystem.scene->m_pPhysXScene);
	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	sceneSystem.Shutdown();
	physicsSystem.Shutdown();
	Logbook::CloseLogs();
	s_pool.shutdown();
	return 0;
}

void Engine::startLoop() {
	std::vector<AGameObject*>& gameObjects = sceneSystem.scene->GetGameObjects();
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[0]->Start();
	}
	while (running) {
		s_frameTime.update();
		std::vector<AGameObject*>& gameObjects = sceneSystem.scene->GetGameObjects();
		for (unsigned int i = 0; i < gameObjects.size(); ++i) {
			gameObjects[i]->Update();
		}
	physicsSystem.Update(sceneSystem.scene->m_pPhysXScene, s_frameTime.deltaTime(),
			&(*sceneSystem.scene->getComponentContainerFromType<components::RigidBody>())[0],
			&sceneSystem.scene->getComponentSubArray<components::Transform>(components::ComponentType<components::RigidBody>::id)[0]);
	}
}

void Engine::stopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	sceneSystem.loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak