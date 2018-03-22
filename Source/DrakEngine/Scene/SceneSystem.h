#pragma once
#include <Core/Core.hpp>
#include <Core/Components/AGameObject.h>
#include <DrakEngine/Components/Components.h>
#include <DrakEngine/Scene/SceneSystemUtils.hpp>
#include <list>
#include <vector>
namespace physx{
	class PxScene;
}

namespace drak {
namespace core {
	class Engine;
}
class Scene {
	std::vector<AGameObject*> m_gameObjects;
	template <I32 n>
	inline void* getComponentContainerFromID();
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(RigidBody)
public:



	Scene();
	~Scene();

	physx::PxScene* m_pPhysXScene;

	template <typename T>
	void addComponentToGameObject(AGameObject* gameObject) {
		if (gameObject->getComponentFlag(components::ComponentType<T>::id))
			return;
		gameObject->setComponentFlag(components::ComponentType<T>::id, true);
		std::vector<T>* v = ((std::vector<T>*)getComponentContainerFromID<components::ComponentType<T>::id>());
		v->push_back(T());
		static_cast<components::AComponent*>(&((*v)[v->size() - 1]))->ownerID = gameObject->id;
		gameObject->setHandleIDPair(components::ComponentType<T>::id, (int)((std::vector<T>*)getComponentContainerFromID<components::ComponentType<T>::id>())->size() - 1);
	}
	template <typename T>
	AGameObject* addGameObject() {
		m_gameObjects.push_back(new T());
		m_gameObjects[m_gameObjects.size() - 1]->myScene = this;
		m_gameObjects[m_gameObjects.size() - 1]->id = (U32)m_gameObjects.size() - 1;
		return m_gameObjects[m_gameObjects.size() - 1];
	}
	template <typename T>
	T* getComponentFromHandle(int handle) {
		return &(*((std::vector<T>*)getComponentContainerFromID<components::ComponentType<T>::id>()))[handle];
	}

	template <typename T>
	std::vector<T>* getComponentContainerFromType() {
		return (std::vector<T>*)getComponentContainerFromID<components::ComponentType<T>::id>();
	}

	template <typename T>
	std::vector<T> getComponentSubArray(U64 flag) {
		std::vector<T> subVector;
		std::vector<T>* vector = getComponentContainerFromType<T>();
		for (unsigned int i = 0; i < vector->size(); ++i) {
			//Only push back if game object has the flag at least
			if ((m_gameObjects[static_cast<components::AComponent*>(&((*vector)[i]))->ownerID]->m_componentFlags & flag) == flag) {
				subVector.push_back((*vector)[i]);
			}
		}
		return subVector;
	}



	DRAK_API std::vector<AGameObject*>& GetGameObjects();

};

class DRAK_API IManualSceneBlueprint{
public:
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(Scene& scene) = 0;
};

class SceneSystem {
	DK_NONMOVABLE_NONCOPYABLE(SceneSystem)
	friend core::Engine;
private:
	// Inherited via ISystem
	~SceneSystem();
	SceneSystem(); 
	void loadScene(const char* name);
	void loadScene(IManualSceneBlueprint& sceneBluePrint);
	bool Startup();
	void Shutdown();
	Scene scene;
};

} //core