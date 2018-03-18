#include <Core/Core.hpp>
#include <Core/Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Core/Components/AComponent.h>
#include <Core/Scene/SceneSystem.h>

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
		transform = CurrentScene()->getComponentFromHandle<Transform>(getHandle(AComponent<Transform>::id));
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

		Cube* c1 = (Cube*)scene.addGameObject<Cube>();
		scene.addComponentToGameObject<Transform>(c1);
		Cube* c2 = (Cube*)scene.addGameObject<Cube>();
		scene.addComponentToGameObject<Transform>(c2);
		Transform* c1Trans = scene.getComponentFromHandle<Transform>(c1->getHandle(AComponent<Transform>::id));
		Transform* c2Trans = scene.getComponentFromHandle<Transform>(c2->getHandle(AComponent<Transform>::id));
		c1Trans->children.push_back(c2Trans);
		c2Trans->parent = c1Trans;
	}
};

int main(int argc, char** argv) {
	Engine::startup();
	MainScene scene;
	SceneSystem::loadScene(scene);
	Engine::startLoop();
	Engine::shutdown();
	system("pause");
}