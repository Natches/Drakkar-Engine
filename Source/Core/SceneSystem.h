#pragma once
#include "Core/ISystem.h"
namespace drak {
namespace core {

class Scene {
public:
	Scene();
	~Scene();
};

class IManualSceneBlueprint : public Scene {
public:
	IManualSceneBlueprint() = default;
	virtual ~IManualSceneBlueprint() = default;
	virtual void Build(Scene& scene) = 0;
};

class MyTestSceneBlueprint : public IManualSceneBlueprint
{
public:
	// Inherited via IManualBuildScene
	virtual void Build(Scene& scene) override;

};

class SceneSystem : public ISystem {
public:
	SceneSystem();
	~SceneSystem();

	void LoadScene(const char* name);
	void LoadScene(IManualSceneBlueprint& sceneBluePrint);

	// Inherited via ISystem
	virtual bool Startup() override;
	virtual void Shutdown() override;
};

} //core
} //drak


