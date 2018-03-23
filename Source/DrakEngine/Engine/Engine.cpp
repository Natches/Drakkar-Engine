#include <DrakEngine/Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Core/Timer/FrameTimer.hpp>
#include <DrakEngine/Physics/PhysicsSystem.h>
#include <DrakEngine/Scene/SceneSystem.h>

namespace drak {
	time::FrameTimer core::Engine::s_frameTime;
	thread::ThreadPool core::Engine::s_pool;
namespace core {
	bool Engine::running = true;

	Engine::Engine() {

	}

	int Engine::startup() {
		Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "Init systems\n");
		//Init systems
		sceneSystem.Startup();
		s_frameTime.start();
		s_pool.startup();
		physicsSystem.Startup();
		physicsSystem.InitPxScene(sceneSystem.scene.m_pPhysXScene);
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
		std::vector<AGameObject*>& gameObjects = sceneSystem.scene.GetGameObjects();
		for (unsigned int i = 0; i < gameObjects.size(); ++i) {
			gameObjects[0]->Start();
		}
		while (running) {
			s_frameTime.update();
			Logbook::Log(Logbook::EOutput::CONSOLE, "EngineLog.txt", "DeltaTime: %f\n",s_frameTime.deltaTime());
			std::vector<AGameObject*>& gameObjects = sceneSystem.scene.GetGameObjects();
			for (unsigned int i = 0; i < gameObjects.size(); ++i) {
				gameObjects[i]->Update();
			}
			physicsSystem.Update(sceneSystem.scene.m_pPhysXScene, s_frameTime.deltaTime(),
				&(*sceneSystem.scene.getComponentContainerFromType<components::RigidBody>())[0],
				&sceneSystem.scene.getComponentSubArray<components::Transform>(components::ComponentType<components::RigidBody>::id)[0]);
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