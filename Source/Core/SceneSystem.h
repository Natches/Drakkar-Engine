#pragma once
#include <Core/Core.hpp>
#include <Core/ISystem.h>
#include <Core/AGameObject.h>
#include <Core/AComponent.h>
#include <list>
#include <vector>
namespace drak {
namespace core {
#include <Core/SceneSystemUtils.h>									
class Scene {
	std::list<AGameObject> m_gameObjects;
public:
	template <I32 n>
	inline void* getComponentContainerID();
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(Mesh)
	DRAK_API Scene();
	DRAK_API ~Scene();
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
		m_gameObjects.push_back(T());
		std::list<AGameObject>::iterator it = m_gameObjects.begin();
		std::advance(it, m_gameObjects.size() - 1);
		(*it).myScene = this;
		return &(*it);
	}
	template <typename T>
	T* getComponentFromHandle(int handle) {
		return &(*((std::vector<T>*)getComponentContainerID<AComponent<T>::id>()))[handle];
	}

	DRAK_API std::list<AGameObject>& GetGameObjects();

};

class DRAK_API IManualSceneBlueprint{
public:
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(Scene& scene) = 0;
};

class SceneSystem : public ISystem {
public:
	DRAK_API SceneSystem();
	DRAK_API ~SceneSystem();

	DRAK_API Scene* GetScene();
	DRAK_API void loadScene(const char* name);
	DRAK_API void loadScene(IManualSceneBlueprint& sceneBluePrint);

	// Inherited via ISystem
	virtual bool Startup() override;
	virtual void Shutdown() override;
private:
	Scene scene;
};

} //core
} //drak


