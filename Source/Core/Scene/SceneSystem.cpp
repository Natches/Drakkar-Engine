#include <Core/Scene/SceneSystem.h>
//#include "AComponent.h"
DK_LOG_CATEGORY_DEFINE(SCENE_SYSTEM_LOG)
DK_LOG_CATEGORY_DECLARE(SCENE_SYSTEM_LOG, ELoggerVerbosity::DEBUG)
using namespace drak;
using namespace core;
using namespace components;

Scene* SceneSystem::scene = new Scene();

Scene* drak::core::SceneSystem::GetScene()
{
	return scene;
}

void SceneSystem::loadScene(const char* name) {
	DK_LOG(SCENE_SYSTEM_LOG, ELoggerVerbosity::DEBUG, "Load and build Scene from file\n")
}

void SceneSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*scene);
}

bool SceneSystem::Startup() {
	DK_LOG(SCENE_SYSTEM_LOG, ELoggerVerbosity::DEBUG, "Startup Scene System\n")
	return true;
}

void SceneSystem::Shutdown() {
	DK_LOG(SCENE_SYSTEM_LOG, ELoggerVerbosity::DEBUG, "Shutdown Scene System\n")
}

Scene::Scene() {
}

Scene::~Scene() {
}

std::list<AGameObject*>& drak::core::Scene::GetGameObjects()
{
	return m_gameObjects;
}
