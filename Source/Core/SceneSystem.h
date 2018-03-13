#pragma once
#include "Core/ISystem.h"
#include "AGameObject.h"
#include "AComponent.h"
#include <list>
#include <vector>
#include <unordered_map>
namespace drak {
namespace core {
#define COMPONENT_CONTAINER_NAME(ComponentType) ComponentType##ComponentContainer
#define COMPONENT_CONTAINER(ComponentType)																																						\
	std::vector<components::##ComponentType> COMPONENT_CONTAINER_NAME(ComponentType);																											\
	template <int T>																																											\
	inline std::vector<components::##ComponentType>* GetComponentContainerID();																													\
	template <>																																													\
	inline std::vector<components::##ComponentType>* GetComponentContainerID<components::ComponentID<components::##ComponentType>()>() { return &ComponentType##ComponentContainer;}
												

class Scene {
	std::list<AGameObject> m_gameObjects;
public:
	/*std::vector<components::Transform> TransformComponentContainer;
	template <int T>																																							
	inline std::vector<components::Transform>* GetComponentContainerID();
	template <>																																										
	inline std::vector<components::Transform>* GetComponentContainerID<components::ComponentID<components::Transform>()>() { return &TransformComponentContainer;}
	/*
	std::vector<components::Transform> TransformComponentContainer;
	template <int T>																																						
	inline std::vector<components::Transform>* GetComponentContainerID();
	template <>																																									
	inline std::vector<components::Transform>* GetComponentContainerID<components::ComponentID<components::Transform>()>() { return &TransformComponentContainer;}
	*/
	COMPONENT_CONTAINER(Transform)
	//std::unordered_map<int, std::vector<components::AComponent>*> componentMap;
	Scene();
	~Scene();
	template <typename T>
	void addComponentToGameObject(AGameObject* gameObject);
	template <typename T>
	AGameObject* addGameObject();
	template <typename T>
	T* getComponentFromHandle(int handle);
};

class IManualSceneBlueprint{
public:
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void build(Scene& scene) = 0;
};

class MyTestSceneBlueprint : public IManualSceneBlueprint
{
public:
	// Inherited via IManualBuildScene
	virtual void build(Scene& scene) override;

};

class SceneSystem : public ISystem {
public:
	SceneSystem();
	~SceneSystem();

	void loadScene(const char* name);
	void loadScene(IManualSceneBlueprint& sceneBluePrint);

	// Inherited via ISystem
	virtual bool Startup() override;
	virtual void Shutdown() override;
};

} //core
} //drak


