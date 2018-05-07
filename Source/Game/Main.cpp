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
		GameObject& player = scene.addGameObject();
		Transform& player_TR = player.getComponent<Transform>();
		RigidBody& player_RB = player.addComponent<RigidBody>();
		CameraComponent& player_CAM = player.addComponent<CameraComponent>();
		Model& player_MDL = player.addComponent<Model>();
		BoxCollider& player_BC = player.addComponent<BoxCollider>();

		player_TR.position = Vec3f(0,0,0);
		player_TR.scale = Vec3f(10.f, 10.f, 10.f);
		player_TR.rotation = Quaternion(Vec3f(0.f, 0.f, 45.f));

		player_CAM.m_fov = 60.f;
		player_CAM.m_aspect = 16.f / 9.f;
		player_CAM.m_nearZ = 1.f;
		player_CAM.m_farZ = 2048.f;
		player_CAM.m_up = Vec3f(0, 1, 0);
		player_CAM.m_at = Vec3f(0, 0, 0);

		player_RB.mass = 1000.f;

		player_MDL.albedo = gfx::Color3(1,0,0);

		PhysicsMaterial mat;
		mat.dynamicFriction = 0.5f;
		mat.restitution = 0.5f;
		mat.staticFriction = 0.5f;
		player_BC.width = 10.f;
		player_BC.height = 10.f;
		player_BC.depth = 10.f;
		player_BC.material = mat;
		BHVR.getCubeBehaviorContainer().emplace_back();
		BHVR.getCubeBehaviorContainer()[BHVR.getCubeBehaviorContainer().size() - 1].gameObjectID = player.getIdx();

		GameObject& cube = scene.addGameObject();
		Transform& cube_TR = cube.getComponent<Transform>();
		RigidBody& cube_RB = cube.addComponent<RigidBody>();
		Model& cube_MDL = cube.addComponent<Model>();
		BoxCollider& cube_BC = cube.addComponent<BoxCollider>();

		cube_TR.position = Vec3f(0, 0, 0);
		cube_TR.scale = Vec3f(10.f, 10.f, 10.f);
		cube_TR.rotation = Quaternion(Vec3f(0.f, 0.f, 45.f));

		cube_RB.mass = 1000.f;

		cube_MDL.albedo = gfx::Color3(1, 0, 0);

		cube_BC.width = 10.f;
		cube_BC.height = 10.f;
		cube_BC.depth = 10.f;
		cube_BC.material = mat;

		GameObject& floor = scene.addGameObject();
		floor.name = "Floor";
		Transform& floor_TR = floor.getComponent<Transform>();
		RigidBody& floor_RB = floor.addComponent<RigidBody>();
		Model& floor_MDL = floor.addComponent<Model>();
		BoxCollider& floor_BC = floor.addComponent<BoxCollider>();

		floor_TR.position = Vec3f(0, -50.f, 0);
		floor_TR.scale = Vec3f(100.f, 10.f, 100.f);

		floor_RB.mass = 1000.f;
		floor_RB.isStatic = true;

		floor_MDL.albedo = gfx::Color3(0, 1, 0);

		floor_BC.width = 100.f;
		floor_BC.height = 10.f;
		floor_BC.depth = 100.f;
		floor_BC.material = mat;

		BHVR.init();
	}
};

void main() {
	BP bp;
	Engine::Get().startup();
	Engine::Get().loadScene(bp);
	//BHVR.load();

	Engine::Get().startLoop();
	BHVR.save();
	Engine::Get().shutdown();
}


