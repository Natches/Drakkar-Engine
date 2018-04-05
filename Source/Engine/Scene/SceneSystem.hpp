#pragma once
#include <Core/Core.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/SceneSystemUtils.hpp>
#include <list>
#include <vector>
#include <map>
namespace physx{
	class PxScene;
}

namespace drak {
namespace core {
	class Engine;
}

class Scene {
	template <I32 n>
	inline void* getComponentContainerByID();
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(RigidBody)
	COMPONENT_CONTAINER(Model)
	void setComponentFlag(U64* componentFlags, int id, bool value) {
		*componentFlags = value ? *componentFlags | (1LL << id) : *componentFlags ^ (1LL << id);
	}
	bool getComponentFlag(U64* componentFlags, int id) {
		return *componentFlags & (1LL << id);
	}
	void setHandleIDPair(std::map<U64, U64>* componentHandles, int id, int handle) {
		componentHandles->insert(std::make_pair(id, handle));
	}
public:
	std::vector<AGameObject*> m_gameObjects;
	Scene();
	~Scene();

	physx::PxScene* m_pPhysXScene;

	template <typename T>
	void addComponentToGameObject(AGameObject* gameObject) {
		components::Transform* goTransform = getComponentByHandle<components::Transform>(gameObject->transformIDX);
		if (getComponentFlag(&goTransform->m_componentFlags, components::ComponentType<T>::id))
			return;
		setComponentFlag(
			&goTransform->m_componentFlags,
			components::ComponentType<T>::id,
			true);
		std::vector<T>* v = ((std::vector<T>*)getComponentContainerByID<components::ComponentType<T>::id>());
		v->push_back(T());
		static_cast<components::AComponent*>(&(*v)[v->size() - 1])->idx = v->size() - 1;
		static_cast<components::AComponent*>(&(*v)[v->size() - 1])->transformHandle = goTransform->idx;
		setHandleIDPair(&goTransform->m_handlesToComponents, components::ComponentType<T>::id, v->size() - 1);
	}

	template <typename T>
	T* addGameObject() {
		m_gameObjects.push_back(new T());
		m_gameObjects[m_gameObjects.size() - 1]->myScene = this;
		m_gameObjects[m_gameObjects.size() - 1]->id = (U32)m_gameObjects.size() - 1;
		TransformComponentContainer.push_back(components::Transform());
		TransformComponentContainer[TransformComponentContainer.size() - 1].transformHandle = TransformComponentContainer.size() - 1;
		setComponentFlag(&TransformComponentContainer[TransformComponentContainer.size() - 1].m_componentFlags, components::ComponentType<components::Transform>::id, true);
		setHandleIDPair(&TransformComponentContainer[TransformComponentContainer.size() - 1].m_handlesToComponents, components::ComponentType<components::Transform>::id, TransformComponentContainer.size() - 1);
		m_gameObjects[m_gameObjects.size() - 1]->transformIDX = TransformComponentContainer.size() - 1;
		return static_cast<T*>(m_gameObjects[m_gameObjects.size() - 1]);
	}
	template <typename T>
	T* getComponentByHandle(int handle) {
		return &(*((std::vector<T>*)getComponentContainerByID<components::ComponentType<T>::id>()))[handle];
	}

	template <typename T>
	std::vector<T>* getComponentContainerByType() {
		return (std::vector<T>*)getComponentContainerByID<components::ComponentType<T>::id>();
	}

	DRAK_API std::vector<AGameObject*>& getGameObjects();

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
	~SceneSystem();
	SceneSystem(); 
	void loadScene(const char* name);
	void loadScene(IManualSceneBlueprint& sceneBluePrint);
	bool Startup();
	void Shutdown();
	Scene* scene;
};

} //core