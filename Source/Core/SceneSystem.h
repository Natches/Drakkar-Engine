#pragma once
#include "Core/ISystem.h"
#include "AGameObject.h"
#include "AComponent.h"
#include <list>
#include <vector>
namespace drak {
namespace core {
#include "SceneSystemUtils.h"									
class Scene {
	std::list<AGameObject> m_gameObjects;
public:
	template <int T>
	inline void* getComponentContainerID();
	COMPONENT_CONTAINER(Transform)
	COMPONENT_CONTAINER(Mesh)
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


