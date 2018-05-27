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
		GameObject& raycastPointer = scene.addGameObject();
		Transform& raycastPointer_TR = *raycastPointer.getComponent<Transform>();
		drak::components::Model& raycastPointer_MDL = raycastPointer.addComponent<drak::components::Model>();
		raycastPointer_TR.setGlobalPosition(Vec3f(0.f, 0.f, 0.f));
		raycastPointer_TR.setGlobalScale(Vec3f(10.f, 10.f, 10.f));
		raycastPointer_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 0.f)));
		raycastPointer_MDL.model = "cube";

		for (int i = 0; i < 20; ++i) {
			GameObject& cube = scene.addGameObject();
			Transform& cube_TR = *cube.getComponent<Transform>();
			RigidBody& cube_RB = cube.addComponent<RigidBody>();
			drak::components::Model& cube_MDL = cube.addComponent<drak::components::Model>();
			BoxCollider& cube_SC = cube.addComponent<BoxCollider>();

			cube_TR.setGlobalPosition(Vec3f(0.f, 0.f + i * 5.f, 0.f));
			cube_TR.setGlobalScale(Vec3f(1.f, 1.f, 1.f));
			cube_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 45.f)));

			cube_RB.mass = 100.f;

			cube_MDL.model = "SK_Mannequin1";

			cube_SC.width = 4.f;
			cube_SC.height = 2.f;
			cube_SC.depth = 2.f;
			cube_SC.material = mat;

			BHVR.getCubeBehaviorContainer().emplace_back(new behavior::Cube());
			BHVR.getCubeBehaviorContainer()[BHVR.getCubeBehaviorContainer().size() - 1]->gameObjectID = cube.getIdx();
		}

		GameObject& cameraController = scene.addGameObject();
		cameraController.name = "CameraController";
		BHVR.getCameraControllerBehaviorContainer().emplace_back(new behavior::CameraController());
		BHVR.getCameraControllerBehaviorContainer()[BHVR.getCameraControllerBehaviorContainer().size() - 1]->gameObjectID = cameraController.getIdx();

		GameObject& floor = scene.addGameObject();
		floor.name = "Floor";
		Transform& floor_TR = *floor.getComponent<Transform>();
		RigidBody& floor_RB = floor.addComponent<RigidBody>();
		drak::components::Model& floor_MDL = floor.addComponent<drak::components::Model>();
		BoxCollider& floor_BC = floor.addComponent<BoxCollider>();

		floor_TR.setGlobalPosition(Vec3f(0, -50.f, 0));
		floor_TR.setGlobalScale(Vec3f(1000.f, 10.f, 1000.f));
		floor_TR.setGlobalRotation(Quaternion(1.f, Vec3f(0.f, 0.f, 0.f)));

		floor_RB.mass = 1000.f;
		floor_RB.isStatic = true;

		floor_MDL.model = "cube";

		floor_BC.width = 1000.f;
		floor_BC.height = 10.f;
		floor_BC.depth = 1000.f;
		floor_BC.material = mat;

		BHVR.init();
		BHVR.save();
	}
};

void main() {
	BP bp;
	Engine::Get().startup();
	//Engine::Get().loadScene(bp);
	Engine::Get().loadScene("Scene");
	BHVR.load();
	Engine::Get().startLoop();
	Engine::Get().shutdown();
}