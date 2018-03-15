#include <Core/Core.hpp>
#include <Core/Engine.hpp>
#include <Log/Log.hpp>
#include <Core/AGameObject.h>
#include <Core/AComponent.h>

using namespace drak;
using namespace core;
using namespace components;
class Player : public AGameObject {
	Transform* transform;
	virtual void Update() override {
	}

	virtual void Start() override {
		transform = CurrentScene()->getComponentFromHandle<Transform>(getHandle(AComponent<Transform>::id));
	}
};

class MainScene : public IManualSceneBlueprint {
	// Inherited via IManualSceneBlueprint
	virtual void build(Scene & scene) override
	{
		Player* p1 = (Player*)scene.addGameObject<Player>();
		scene.addComponentToGameObject<Transform>(p1);
		Transform* playerTransform = scene.getComponentFromHandle<Transform>(p1->getHandle(AComponent<Transform>::id));
	}
};

int main(int argc, char** argv) {
	Engine engine;
	engine.startup();
	MainScene scene;
	engine.GetSceneSystem().loadScene(scene);
	engine.startLoop();
	engine.shutdown();
	system("pause");
}