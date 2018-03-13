#include "SceneSystem.h"
#include "Log.hpp"
//#include "AComponent.h"
DK_LOG_CATEGORY_DEFINE(SCENE_SYSTEM_LOG)
DK_LOG_CATEGORY_DECLARE(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG)
using namespace drak;
using namespace core;
using namespace components;

SceneSystem::SceneSystem() {
}


SceneSystem::~SceneSystem() {
}

template <typename T>
void drak::core::Scene::addComponentToGameObject(AGameObject* gameObject) {
	static_assert(std::is_base_of<AComponent, T>::value, "derivation failure");
	gameObject->setComponentFlag(ComponentID<T>(), true);
	GetComponentContainerID<ComponentID<T>()>()->push_back(T());
	gameObject->setHandleIDPair(ComponentID<T>(), GetComponentContainerID<ComponentID<T>()>()->size() - 1);
}

template <typename T>
AGameObject* Scene::addGameObject() {
	static_assert(std::is_base_of<AGameObject, T>::value, "derivation failure");
	m_gameObjects.push_back(T());
	std::list<AGameObject>::iterator it = m_gameObjects.begin();
	std::advance(it, m_gameObjects.size() - 1);
	return &(*it);
}

void SceneSystem::loadScene(const char* name) {
	DK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Load and build Scene from file/n")
}

void SceneSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	Scene scene;
	sceneBluePrint.build(scene);
}

bool SceneSystem::Startup() {
	DK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Startup Scene System\n")
		return true;
}

void SceneSystem::Shutdown() {
	DK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Shutdown Scene System\n")
}

Scene::Scene() {
}

Scene::~Scene() {
}

template <typename T>
T* drak::core::Scene::getComponentFromHandle(int handle)
{
	return &(*GetComponentContainerID<ComponentID<T>()>())[handle];
}

void MyTestSceneBlueprint::build(Scene& scene) {
	DebugCube* pDebugCube1 = (DebugCube*)scene.addGameObject<DebugCube>();
	DebugCube* pDebugCube2 = (DebugCube*)scene.addGameObject<DebugCube>();
	scene.addComponentToGameObject<Transform>(pDebugCube1);
	scene.addComponentToGameObject<Transform>(pDebugCube2);
	Transform* t1 = scene.getComponentFromHandle<Transform>(pDebugCube1->getHandle(ComponentID<Transform>()));
	t1->pos = vec3TEMP{0,0,0};
	Transform* t2 = scene.getComponentFromHandle<Transform>(pDebugCube2->getHandle(ComponentID<Transform>()));
	t2->pos = vec3TEMP{ 10,0,0 };
	t1->children.push_back(t2);
	t2->parent = t1;
	DK_LOG(SCENE_SYSTEM_LOG, LoggerVerbosity::DEBUG, "Build manual scene for MyTestScene\n")
}
