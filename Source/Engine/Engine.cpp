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

PhysicsSystem& Engine::getPhysicsSystem()
{
	return physicsSystem;
}

int Engine::startup() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
	//Init systems
	Get().sceneSystem.Startup();
	Get().s_frameTime.start();
	s_pool.startup();
	Get().physicsSystem.Startup();
	Get().physicsSystem.InitPxScene(&Get().sceneSystem.scene->m_pPhysXScene);
	return 0;
}

int Engine::shutdown() {
	Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Shutdown systems\n");
	Get().sceneSystem.Shutdown();
	Get().physicsSystem.Shutdown();
	Get().s_frameTime.stop();
	Logbook::CloseLogs();
	s_pool.shutdown();
	return 0;
}

void Engine::startLoop() {
	std::vector<AGameObject*>& gameObjects = sceneSystem.scene->getGameObjects();
	for (unsigned int i = 0; i < gameObjects.size(); ++i) {
		gameObjects[0]->Start();
	}
	unsigned long long frames = 0;
	float runtime = 0;
	while (running) {
		frames++;
		s_frameTime.update();
		std::vector<AGameObject*>& gameObjects = sceneSystem.scene->getGameObjects();
		for (unsigned int i = 0; i < gameObjects.size(); ++i) {
			gameObjects[i]->Update();
		}
		std::vector<components::Transform> subArray = sceneSystem.scene->getFilteredComponentSubArray<components::Transform>(components::ComponentType<components::RigidBody>::id);
		physicsSystem.Update(sceneSystem.scene->m_pPhysXScene, 1.f/60.f,
				sceneSystem.scene->getComponentContainerByType<components::RigidBody>(),
				&subArray);
		sceneSystem.scene->stampSubArrayIntoMainArray<components::Transform>(subArray);
		if(frames>0)
			runtime += s_frameTime.deltaTime();
	}
	printf("Average FPS %f\n", 1.f / (runtime / (frames-0)));
}

void Engine::stopGame() {
	Engine::running = false;
}

void Engine::loadScene(IManualSceneBlueprint & sceneBlueprint) {
	sceneSystem.loadScene(sceneBlueprint);
}



} // namespace core
} // namespace drak