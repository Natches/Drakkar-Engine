#include <Core/Core.hpp>
#include <DrakEngine/Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <DrakEngine/Components/Components.h>
#include <DrakEngine/Scene/SceneSystem.h>

using namespace drak;
using namespace core;
using namespace components;


class Player : public AGameObject {
	Transform* transform;
	int counter = 0;
	virtual void Update() override {
		if (counter <= 100) {
			Logbook::Log(Logbook::EOutput::CONSOLE, "GameLog.txt", "Player update\n");
		}
		else {
			Engine::stopGame();
		}
		counter++;
	}

	virtual void Start() override {
		transform = myScene->getComponentFromHandle<Transform>(getHandle(ComponentType<Transform>::id));
	}
};

class Cube : public AGameObject {
	virtual void Update() override {
	}

	virtual void Start() override {
	}
};

class MainScene : public IManualSceneBlueprint {
	// Inherited via IManualSceneBlueprint
	virtual void build(Scene & scene) override
	{
		Player* p1 = (Player*)scene.addGameObject<Player>();
		scene.addComponentToGameObject<Transform>(p1);
		scene.addComponentToGameObject<RigidBody>(p1);
	}
};

int main(int argc, char** argv) {
	Engine engine;
	engine.startup();
	MainScene scene;
	engine.loadScene(scene);
	engine.startLoop();
	engine.shutdown();
	system("pause");
}