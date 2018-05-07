#pragma once
#include <Core/Core.hpp>
#include <Core/Components/GameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>
#include <Serialization\Serializer.hpp>
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
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(LevelSystem& scene) = 0;
};

struct Scene {
	Scene(std::vector<GameObject>& gameObjects, std::vector<U32> rootIDXs, std::vector<components::Transform>& transforms, std::vector<components::Model>& models, components::CameraComponent& mainCamera) :
		transforms(transforms),
		models(models),
		gameObjects(gameObjects),
		rootIDXs(rootIDXs),
		mainCamera(mainCamera){}
	std::vector<components::Transform>& transforms;
	std::vector<components::Model>& models;
	std::vector<GameObject>& gameObjects;
	std::vector<U32> rootIDXs;
	components::CameraComponent& mainCamera;
};

class LevelSystem {
	DK_SERIALIZED_OBJECT(LevelSystem)
	friend core::Engine;
	friend void drak::GameObject::makeRoot();
	friend void drak::GameObject::setParent(U32 pIdx);
	friend void drak::GameObject::setParent(GameObject& parent);


	template <I32 n>
	inline void* __ccByID() {}
	COMPONENT_CONTAINER(RigidBody)
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(Model)
	COMPONENT_CONTAINER(BoxCollider)
	COMPONENT_CONTAINER(CameraComponent)

	std::vector<GameObject> m_gameObjects;
	std::vector<U32> m_rootIdxs;

	void addGameObjectToRoots(U32 idx) {
		m_rootIdxs.push_back(idx);
	}

	void removeGameObjectFromRoots(U32 idx) {
		for (U32 i = 0; i < m_rootIdxs.size(); ++i) {
			if (m_rootIdxs[i] == idx) {
				m_rootIdxs[i] = *m_rootIdxs.end();
				m_rootIdxs.pop_back();
			}
		}
	}
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

	GameObject& addGameObject() {
		try {
			m_gameObjects.push_back(GameObject());
		}
		catch (std::bad_array_new_length &e) {
			Logbook::Log(Logbook::EOutput::CONSOLE, "Level System", e.what());
		}
		GameObject& gameObject = m_gameObjects[m_gameObjects.size() - 1];
		gameObject.setIdx(m_gameObjects.size() - 1);
		gameObject.setLevel(this);
		m_rootIdxs.push_back(gameObject.getIdx());
		//Add transform to all game objects
		addComponentToGameObject<components::Transform>(gameObject);
		return gameObject;
	}

	Scene getScene() {
		return Scene(m_gameObjects, m_rootIdxs, __getComponentContainer(components::Transform), __getComponentContainer(components::Model), __getComponentContainer(components::CameraComponent)[0]);
	}
};
} //core

DK_METADATA_BEGIN(drak::LevelSystem)
DK_PUBLIC_FIELDS(RigidBodyComponentContainer, TransformComponentContainer, ModelComponentContainer, BoxColliderComponentContainer, m_gameObjects, m_rootIdxs)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END