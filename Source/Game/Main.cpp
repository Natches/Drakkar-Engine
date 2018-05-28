#include <PrecompiledHeader/pch.hpp>
#include <Engine/Engine.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Components/ABehavior.hpp>
#include <Game/BehaviorMonolith.h>
#include <Engine/Scene/LevelSystem.hpp>


using namespace drak;
using namespace core;
using namespace components;
using namespace events;
using namespace function;
using namespace math;
using namespace serialization;

class BP : public IManualSceneBlueprint {
public:

	// Inherited via IManualSceneBlueprint
	virtual void build(LevelSystem& scene) override
	{
		scene.m_resourceManager->convertOrLoad(std::string("./Resources/Models/SK_Mannequin.dkResources"));
		scene.m_resourceManager->convertOrLoad(std::string("./Resources/Models/cube.dkResources"));
		PhysicsMaterial mat;
		mat.dynamicFriction = 0.5f;
		mat.restitution = 0.5f;
		mat.staticFriction = 0.5f;
		name = "Scene";

		for (I32 i = 0; i < 10; ++i) {
			for (I32 j = 0; j < 10; ++j) {
				GameObject& box = scene.addGameObject();
				box.name = "Box";
				Transform& boxTrans = *box.getComponent<Transform>();
				RigidBody& boxRigid = box.addComponent<RigidBody>();
				drak::components::Model& boxModel = box.addComponent<drak::components::Model>();
				BoxCollider& boxCollider = box.addComponent<BoxCollider>();
				boxTrans.setGlobalPosition(Vec3f(j * 50.f, 0.f, i * 50.f));
				boxTrans.setGlobalScale(Vec3f(100.f, 100.f, 100.f));
				boxTrans.setGlobalRotation(Quaternion(1.f, Vec3f(0.f, 0.f, 0.f)));
				boxRigid.mass = 10.f;
				boxModel.name = "SK_Mannequin1";
				boxCollider.width = 50.f;
				boxCollider.height = 50.f;
				boxCollider.depth = 50.f;
				boxCollider.material = mat;
			}
		}



		GameObject& player = scene.addGameObject();
		player.name = "Player";
		Transform& playerTrans = *player.getComponent<Transform>();
		RigidBody& playerRigid = player.addComponent<RigidBody>();
		BoxCollider& playerCollider = player.addComponent<BoxCollider>();
		drak::components::Model& playerModel = player.addComponent<drak::components::Model>();
		playerTrans.setGlobalPosition(Vec3f(0, -30.f, 50));
		playerTrans.setGlobalScale(Vec3f(100.f, 100.f, 100.f));
		playerTrans.setGlobalRotation(Quaternion(1.f, Vec3f(0.f, 0.f, 0.f)));
		playerRigid.mass = 1000.f;
		playerRigid.isKinematic = true;
		playerModel.name = "cube";
		playerCollider.width = 50.f;
		playerCollider.height = 50.f;
		playerCollider.depth = 50.f;
		playerCollider.material = mat;
		BHVR.getPlayerBehaviorContainer().emplace_back(new behavior::Player ());
		BHVR.getPlayerBehaviorContainer()[BHVR.getPlayerBehaviorContainer().size() - 1]->gameObjectID = player.getIdx();


		GameObject& floor = scene.addGameObject();
		floor.name = "Floor";
		Transform& floor_TR = *floor.getComponent<Transform>();
		RigidBody& floor_RB = floor.addComponent<RigidBody>();
		drak::components::Model& floor_MDL = floor.addComponent<drak::components::Model>();
		BoxCollider& floor_BC = floor.addComponent<BoxCollider>();
		floor_TR.setGlobalPosition(Vec3f(0, -40.f, 0));
		floor_TR.setGlobalScale(Vec3f(10000.f, 2.f, 10000.f));
		floor_TR.setGlobalRotation(Quaternion(1.f, Vec3f(0.f, 0.f, 0.f)));
		floor_RB.mass = 1000.f;
		floor_RB.isStatic = true;
		floor_MDL.name = "cube";
		floor_BC.width = 5000.f;
		floor_BC.height = 25.f;
		floor_BC.depth = 5000.f;
		floor_BC.material = mat;

		BHVR.init();
		BHVR.save();
	}
};

void main() {
	BP bp;
	Engine::Get().startup();
	Engine::Get().loadScene(bp);
	//Engine::Get().loadScene("Scene");
	//BHVR.load();
	Engine::Get().startLoop();
	Engine::Get().shutdown();
}