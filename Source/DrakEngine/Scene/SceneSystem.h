#pragma once
#include <Core/Core.hpp>
#include <Core/Engine/ISystem.h>
#include <Core/Components/AGameObject.h>
#include <Core/Components/AComponent.h>
#include <list>
#include <vector>
namespace drak {
namespace core {
#include <DrakEngine/Scene/SceneSystemUtils.hpp>
class Scene {
	std::list<AGameObject*> m_gameObjects;
public:
	template <I32 n>
	inline void* getComponentContainerID();
	COMPONENT_CONTAINER(Transform)

	Scene();
	~Scene();
	template <typename T>
	void addComponentToGameObject(AGameObject* gameObject) {
		if (gameObject->getComponentFlag(AComponent<T>::id))
			return;
		gameObject->setComponentFlag(AComponent<T>::id, true);
		((std::vector<T>*)getComponentContainerID<AComponent<T>::id>())->push_back(T());
		gameObject->setHandleIDPair(AComponent<T>::id, ((std::vector<T>*)getComponentContainerID<AComponent<T>::id>())->size() - 1);
	}
	template <typename T>
	AGameObject* addGameObject() {
		m_gameObjects.push_back(new T());
		std::list<AGameObject*>::iterator it = m_gameObjects.begin();
		std::advance(it, m_gameObjects.size() - 1);
		(*it)->myScene = this;
		return (*it);
	}
	template <typename T>
	T* getComponentFromHandle(int handle) {
		return &(*((std::vector<T>*)getComponentContainerID<AComponent<T>::id>()))[handle];
	}

	DRAK_API std::list<AGameObject*>& GetGameObjects();

};

class DRAK_API IManualSceneBlueprint{
public:
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(Scene& scene) = 0;
};

class SceneSystem{
public:
	DRAK_API static Scene* GetScene();
	DRAK_API static void loadScene(const char* name);
	DRAK_API static void loadScene(IManualSceneBlueprint& sceneBluePrint);

	// Inherited via ISystem
	DRAK_API static bool Startup();
	DRAK_API static void Shutdown();
private:
	DRAK_API static Scene* scene;
};

} //core
} //drak


