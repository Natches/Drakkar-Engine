#pragma once

#include <Core/Core.hpp>
#include <Engine/Components/GameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>
#include <Serialization/Serializer.hpp>
//#include <Math/Vec3.hpp>
//#include <Math/Vec4.hpp>
//#include <list>
//#include <vector>
//#include <map>
//#include <type_traits>

namespace physx{
	class PxScene;
}

namespace drak {
namespace events {
	struct Event;
}
namespace core {
	class Engine;
}

class DRAK_API IManualSceneBlueprint {
public:
	const char* name;
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(LevelSystem& scene) = 0;
};

struct Scene {
	Scene(std::vector<GameObject>& gameObjects, std::vector<U32>& rootIDXs, std::vector<components::Transform>& transforms, std::vector<components::Model>& models) :
		transforms(transforms),
		models(models),
		gameObjects(gameObjects),
		rootIDXs(rootIDXs){}
	std::vector<components::Transform>& transforms;
	std::vector<components::Model>& models;
	std::vector<GameObject>& gameObjects;
	std::vector<U32>& rootIDXs;
};

class LevelSystem {
	DK_SERIALIZED_OBJECT(LevelSystem)
	friend core::Engine;
	friend void drak::GameObject::makeRoot();
	friend void drak::GameObject::setParent(const I32 pIdx);


	template <I32 n>
	inline void* __ccByID() {}
	COMPONENT_CONTAINER(RigidBody)
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(Model)
	COMPONENT_CONTAINER(BoxCollider)

	std::vector<GameObject> m_gameObjects;
	std::vector<U32> m_rootIdxs;
	void moveChildren(const components::Transform& parentTransform, const std::vector<U32>& children);

	void addGameObjectToRoots(U32 idx) {
		m_rootIdxs.push_back(idx);
	}

	void removeGameObjectFromRoots(U32 idx) {
		for (U32 i = 0; i < m_rootIdxs.size(); ++i) {
			if (m_rootIdxs[i] == idx) {
				m_rootIdxs[i] = m_rootIdxs[m_rootIdxs.size() - 1];
				m_rootIdxs.pop_back();
			}
		}
	}

	void propogateMovementFromRoots();

	std::string filename;
public:

	void loadScene(const char* name);
	void loadScene(IManualSceneBlueprint& sceneBluePrint);
	bool startup();
	void shutdown();
	LevelSystem();
	~LevelSystem();

	void SerializeLevel();

	void SerializeEvent(const events::Event* pEvent);

	std::vector<GameObject>& getGameObjects() {
		return m_gameObjects;
	}

	template <typename T>
	T& getComponentByHandle(U64 handle) {
		return __getComponentContainer(T)[handle];
	}

	template <typename T>
	std::vector<T>& getComponentContainerByType() {
		return __getComponentContainer(T);
	}

	template <typename T>
	T& addComponentToGameObject(GameObject& gameObject) {
		gameObject.setComponentFlag(components::ComponentType<T>::id, true);
		__getComponentContainer(T).push_back(T());
		T& component = __getComponentContainer(T)[__getComponentContainer(T).size() - 1];
		static_cast<components::AComponent*>(&component)->idx = __getComponentContainer(T).size() - 1;
		static_cast<components::AComponent*>(&component)->GameObjectID = gameObject.getIdx();
		gameObject.setHandleIDPair(components::ComponentType<T>::id, __getComponentContainer(T).size() - 1);
		return component;
	}

	template <typename T>
	void DestroyComponent(U32 idx) {
		if (components::ComponentType<T>::id == components::ComponentType<Transform>::id)
			return;
		T& target = __getComponentContainer(T)[idx];
		T& last = __getComponentContainer(T)[__getComponentContainer(T).size() - 1];
		U32 newIDX = static_cast<components::AComponent*>(&target)->idx;
		GameObject& gameObjectThatHasTargetComponent = m_gameObjects[static_cast<components::AComponent*>(&target)->GameObjectID];
		GameObject& gameObjectThatHasLastComponent = m_gameObjects[static_cast<components::AComponent*>(&last)->GameObjectID];
		//set flag to 0
		gameObjectThatHasTargetComponent.setComponentFlag(components::ComponentType<T>::id, false);
		//remove handle
		gameObjectThatHasTargetComponent.getComponentHandles().erase(components::ComponentType<T>::id);

		std::swap(target, last);
		static_cast<components::AComponent*>(&target)->idx = idx;
		gameObjectThatHasLastComponent.getComponentHandles()[components::ComponentType<T>::id] = newIDX;
		static_cast<components::AComponent*>(&last)->deleteComponent();
		__getComponentContainer(T).pop_back();
	}

	GameObject& addGameObject() {
		try {
			m_gameObjects.push_back(GameObject());
		}
		catch (std::bad_array_new_length &e) {
			Logbook::Log(Logbook::EOutput::CONSOLE, "Level System", e.what());
		}
		GameObject& gameObject = m_gameObjects[m_gameObjects.size() - 1];
		gameObject.setIdx((U32)m_gameObjects.size() - 1);
		gameObject.setLevel(this);
		m_rootIdxs.push_back(gameObject.getIdx());
		//Add transform to all game objects
		addComponentToGameObject<components::Transform>(gameObject);
		return gameObject;
	}

	Scene getScene() {
		return Scene(m_gameObjects, m_rootIdxs, __getComponentContainer(components::Transform), __getComponentContainer(components::Model));
	}
};
} //core

DK_METADATA_BEGIN(drak::LevelSystem)
DK_PUBLIC_FIELDS(RigidBodyComponentContainer, TransformComponentContainer, ModelComponentContainer, BoxColliderComponentContainer, m_gameObjects, m_rootIdxs)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END