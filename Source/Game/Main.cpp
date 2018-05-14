#include <PrecompiledHeader/pch.hpp>
#include <Engine/Engine.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Components/ABehavior.hpp>
#include <Game/BehaviorMonolith.h>

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
	virtual void build(LevelSystem & scene) override
	{
		name = "Scene";
		GameObject& cube = scene.addGameObject();
		Transform& cube_TR = cube.getComponent<Transform>();
		RigidBody& cube_RB = cube.addComponent<RigidBody>();
		Model& cube_MDL = cube.addComponent<Model>();
		BoxCollider& cube_BC = cube.addComponent<BoxCollider>();

		cube_TR.setGlobalPosition(Vec3f(0,0,0));
		cube_TR.setGlobalScale(Vec3f(10.f, 10.f, 10.f));
		cube_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 0.f)));

		cube_RB.mass = 1000.f;

		cube_MDL.albedo = gfx::Color3(1,0,0);

		PhysicsMaterial mat;
		mat.dynamicFriction = 0.5f;
		mat.restitution = 0.5f;
		mat.staticFriction = 0.5f;
		cube_BC.width = 10.f;
		cube_BC.height = 10.f;
		cube_BC.depth = 10.f;
		cube_BC.material = mat;
		BHVR.getCubeBehaviorContainer().emplace_back();
		BHVR.getCubeBehaviorContainer()[BHVR.getCubeBehaviorContainer().size() - 1].gameObjectID = cube.getIdx();
		const U32 parentIDX = cube.getIdx();

		GameObject& childCube = scene.addGameObject();
		Transform& childCube_TR = childCube.getComponent<Transform>();
		Model& childCube_MDL = childCube.addComponent<Model>();

		childCube_TR.setGlobalPosition(Vec3f(30, 0, 0));
		childCube_TR.setGlobalScale(Vec3f(10.0f, 10.0f, 10.0f));
		childCube_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 90.f)));

		childCube_MDL.albedo = gfx::Color3(1, 0, 0);
		const U32 parent2IDX = childCube.getIdx();
		childCube.setParent(parentIDX);

		GameObject& childCube2 = scene.addGameObject();
		Transform& childCube2_TR = childCube2.getComponent<Transform>();
		Model& childCube2_MDL = childCube2.addComponent<Model>();

		childCube2_TR.setGlobalPosition(Vec3f(50, 0, 0));
		childCube2_TR.setGlobalScale(Vec3f(10.f, 10.f, 10.f));
		childCube2_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 0.f)));

		childCube2_MDL.albedo = gfx::Color3(1, 0, 0);

		childCube2.setParent(parent2IDX);


		GameObject& floor = scene.addGameObject();
		floor.name = "Floor";
		Transform& floor_TR = floor.getComponent<Transform>();
		RigidBody& floor_RB = floor.addComponent<RigidBody>();
		Model& floor_MDL = floor.addComponent<Model>();
		BoxCollider& floor_BC = floor.addComponent<BoxCollider>();

		floor_TR.setGlobalPosition(Vec3f(0, -50.f, 0));
		floor_TR.setGlobalScale(Vec3f(1000.f, 10.f, 1000.f));
		floor_TR.setGlobalRotation(Quaternion(1.f, Vec3f(0.f, 0.f, 0.f)));

		floor_RB.mass = 1000.f;
		floor_RB.isStatic = true;

		floor_MDL.albedo = gfx::Color3(0, 1, 0);

		floor_BC.width = 1000.f;
		floor_BC.height = 10.f;
		floor_BC.depth = 1000.f;
		floor_BC.material = mat;

		for (int i = 0; i < 2500; ++i) {
			GameObject& instCube = scene.addGameObject();
			Transform& instCube_TR = instCube.getComponent<Transform>();
			RigidBody& instCube_RB = instCube.addComponent<RigidBody>();
			Model& instCube_MDL = instCube.addComponent<Model>();
			BoxCollider& instCube_BC = instCube.addComponent<BoxCollider>();

			instCube_TR.setGlobalPosition(Vec3f(0, i * 5.f, 0));
			instCube_TR.setGlobalScale(Vec3f(10.f, 10.f, 10.f));
			instCube_TR.setGlobalRotation(Quaternion(Vec3f(0.f, 0.f, 0.f)));

			instCube_RB.mass = 1000.f;

			instCube_MDL.albedo = gfx::Color3(1, 0, 0);

			PhysicsMaterial matInst;
			matInst.dynamicFriction = 0.5f;
			matInst.restitution = 0.5f;
			matInst.staticFriction = 0.5f;
			instCube_BC.width = 10.f;
			instCube_BC.height = 10.f;
			instCube_BC.depth = 10.f;
			instCube_BC.material = matInst;
		}


		BHVR.init();
	}
};

void main() {
	BP bp;
	Engine::Get().startup();
	Engine::Get().loadScene(bp);
	//Engine::Get().loadScene("Scene");
	//BHVR.load();
	Engine::Get().startLoop();
	BHVR.save();
	Engine::Get().shutdown();
}


