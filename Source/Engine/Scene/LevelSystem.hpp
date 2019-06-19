#pragma once

#include <Core/Core.hpp>
#include <Engine/GameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>
#include <Serialization/Serializer.hpp>
#include <ResourceManager/ResourceSystem.hpp>
#include <Animation/AnimationScene.hpp>

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
	Scene(
		std::vector<GameObject>& gameObjects,
		std::vector<U32>& rootIDXs,
		std::vector<components::Transform>& transforms,
		std::vector<components::Model>& models,
		std::vector<components::BoxCollider>& hitBoxes,
		ResourceSystem& resourceManager,
		animation::AnimationScene& animScene) :
		gameObjects(gameObjects),
		rootIDXs(rootIDXs),
		transforms(transforms),
		models(models),
		hitBoxes(hitBoxes),
		resourceManager(resourceManager),
		animationScene(animScene)
	{}

	ResourceSystem&							resourceManager;
	animation::AnimationScene&				animationScene;
	std::vector<U32>&						rootIDXs;
	std::vector<GameObject>&				gameObjects;
	std::vector<components::Transform>&		transforms;
	std::vector<components::Model>&			models;
	std::vector<components::BoxCollider>&	hitBoxes;


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
	COMPONENT_CONTAINER(SphereCollider)
	COMPONENT_CONTAINER(Animator)

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

	DRAK_API void propagateMovementFromRoots();

	std::string filename;
	ResourceSystemData m_data;

	void DestroyChild(U32 idx);

	void setComponentGameObjectIDX(U32 originalIDX, U32 newIDX);

	ResourceSystem* m_resourceManager;
	animation::AnimationScene* m_pAnimationScene = nullptr;
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
	T& getComponentByHandle(U32 handle) {
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
		static_cast<components::AComponent*>(&component)->idx = static_cast<U32>(__getComponentContainer(T).size()) - 1;
		static_cast<components::AComponent*>(&component)->GameObjectID = gameObject.getIdx();
		gameObject.setHandleIDPair(components::ComponentType<T>::id, static_cast<U32>(__getComponentContainer(T).size() - 1));
		return component;
	}

	template <typename T>
	void destroyComponent(U32 idx) {
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



	void destroyGameObject(U32 idx);

	DRAK_API GameObject& addGameObject();

	Scene getScene() {
		return Scene(
			m_gameObjects,
			m_rootIdxs,
			__getComponentContainer(components::Transform),
			__getComponentContainer(components::Model),
			__getComponentContainer(components::BoxCollider),
			*m_resourceManager,
			*m_pAnimationScene);
	}
};
} // core

DK_METADATA_BEGIN(drak::LevelSystem)
DK_PUBLIC_FIELDS(
	RigidBodyComponentContainer,
	TransformComponentContainer,
	ModelComponentContainer,
	BoxColliderComponentContainer,
	AnimatorComponentContainer,
	m_pAnimationScene,
	m_gameObjects,
	m_rootIdxs,
	m_data)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END