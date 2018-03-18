#include <Core/Scene/SceneSystem.h>
using namespace drak;
using namespace core;
using namespace components;

Scene* SceneSystem::scene = new Scene();

Scene* drak::core::SceneSystem::GetScene()
{
	return scene;
}

void SceneSystem::loadScene(const char* name) {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Load and build Scene from file\n");
}

void SceneSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*scene);
}

bool SceneSystem::Startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	return true;
}

void SceneSystem::Shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
}

Scene::Scene() {
}

Scene::~Scene() {
}

std::list<AGameObject*>& drak::core::Scene::GetGameObjects()
{
	return m_gameObjects;
}