#include <DrakEngine/Scene/SceneSystem.h>
#include <DrakEngine/Physics/PhysicsSystem.h>
#include <PxPhysicsAPI.h>
using namespace drak;
using namespace core;

void SceneSystem::loadScene(const char* name) {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Load and build Scene from file\n");
}

void SceneSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(scene);
}

SceneSystem::SceneSystem() {
}
SceneSystem::~SceneSystem() {
}

bool SceneSystem::Startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	return true;
}

void SceneSystem::Shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
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

std::vector<AGameObject*>& drak::Scene::GetGameObjects()
{
	return m_gameObjects;
}