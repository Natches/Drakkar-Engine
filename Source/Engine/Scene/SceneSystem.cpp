#include <Engine/Scene/SceneSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>
using namespace drak;
using namespace core;

SceneSystem::SceneSystem() {

}

SceneSystem::~SceneSystem() {

}

void SceneSystem::loadScene(const char* name) {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Load and build Scene from file\n");
}

void SceneSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*scene);
}

bool SceneSystem::Startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	scene = new Scene;
	return true;
}

void SceneSystem::Shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
	delete scene;
}

drak::Scene::Scene() {
}

drak::Scene::~Scene() {
	m_pPhysXScene->release();
	for (unsigned int i = 0; i < m_gameObjects.size(); ++i)
	{
		delete m_gameObjects[i];
	}
}

std::vector<AGameObject*>& drak::Scene::getGameObjects()
{
	return m_gameObjects;
}