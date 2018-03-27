#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Engine/Components/Components.h>
#include <Engine/Scene/SceneSystem.h>
#include <Math/Matrix4x4.hpp>

using namespace drak;
using namespace core;
using namespace components;
DK_IMPORT(drak::math)

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
	Engine::GetInstance().startup();
	MainScene scene;
	Engine::GetInstance().loadScene(scene);
	Engine::GetInstance().startLoop();
	Engine::GetInstance().shutdown();
	system("pause");
}