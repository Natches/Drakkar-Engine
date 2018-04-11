#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Math/Matrix4x4.hpp>
#include <Windowing/Input/Keyboard.hpp>
#include <PxPhysicsAPI.h>
#include <string>

using namespace drak;
using namespace core;
using namespace components;
using namespace events;
using namespace function;
using namespace math;

class Floor : public AGameObject {
	// Inherited via AGameObject
	virtual void update() override
	{
	}
	virtual void start() override
	{
		name = "Floor";
	}
};

class Cube : public AGameObject {
public:
	bool hitByPlayer = false;
private:
	virtual void update() override {
	}

	virtual void start() override {
		name = "Cube";
		RigidBody& rb = *getComponent<RigidBody>();
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			rb,
			PhysicsEventDispatcher::COLLISION_IN,
			new MemberFunction<Cube, void, const Event*>
			(this, &Cube::OnCollisionEnter));
	}

	void Cube::OnCollisionEnter(const Event* pEvent) {
		if (!pEvent)
			return;
		const CollisionEvent* e = static_cast<const CollisionEvent*>(pEvent);
		switch (e->type) {
		case PhysicsEventDispatcher::COLLISION_IN:
			if (getLevel()->getGameObjects()[e->otherGameObjectIDX]->getName() == "Player") {
				Model& model = *getComponent<Model>();
				model.albedo.r = 1.0f;
				model.albedo.g = 1.0f;
				model.albedo.b = 0.0f;
			}
			break;
		}
	}

	void Cube::OnCollisionExit(const Event* pEvent) {
	}

	void Cube::OnCollisionStay(const Event* pEvent) {
	}

};

class Player : public AGameObject {
	// Inherited via AGameObject
	float speed = 50.f;
	int score = 0;
	virtual void update() override
	{
	}

	virtual void start() override
	{
		name = "Player";
		Keyboard::Get().addEventListener(KeyEvent::KEY_DOWN, 
			new MemberFunction<Player, void, const Event*>(this, &Player::KeyPress, &Keyboard::Get().event()));

		RigidBody& rb = *getComponent<RigidBody>();
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			rb,
			PhysicsEventDispatcher::COLLISION_IN,
			new MemberFunction<Player, void, const Event*>
				(this, &Player::OnCollisionEnter));
	}

	void Player::OnCollisionEnter(const Event* pEvent) {
		if (!pEvent)
			return;
		const CollisionEvent* e = static_cast<const CollisionEvent*>(pEvent);
		switch (e->type) {
		case PhysicsEventDispatcher::COLLISION_IN:
			AGameObject* obj = getLevel()->getGameObjects()[e->otherGameObjectIDX];
			if (obj->getName() == "Cube") {
				++score;
				Model& m = *getComponent<Model>();
				m.albedo.g -= 0.1f;
				m.albedo.b -= 0.1f;
			}
			break;
		}
	}

	void Player::KeyPress(const Event* pEvent) {
		if(!pEvent)
			return;
		const KeyEvent* ke = static_cast<const KeyEvent*>(pEvent);
		Transform& trans = *getComponent<Transform>();
		switch (ke->key)
		{
		case Key::KEY_UP:
			Engine::Get().getPhysicsSystem().move(
				*getComponent<RigidBody>(),
					trans.position + Vec3f(0, 0, -speed * DeltaTime),
					trans.rotation);
			break;
		case Key::KEY_DOWN:
			Engine::Get().getPhysicsSystem().move(
				*getComponent<RigidBody>(), 
					trans.position + Vec3f(0, 0, speed * DeltaTime),
					trans.rotation);
			break;
		case Key::KEY_LEFT:
			Engine::Get().getPhysicsSystem().move(
				*getComponent<RigidBody>(),
					trans.position + Vec3f(-speed * DeltaTime, 0, 0),
					trans.rotation);
			break;
		case Key::KEY_RIGHT:
			Engine::Get().getPhysicsSystem().move(
				*getComponent<RigidBody>(),
					trans.position + Vec3f(speed * DeltaTime, 0, 0),
					trans.rotation);
			break;
		default:
			break;
		}
	}
};

class MainScene : public IManualSceneBlueprint {
	// Inherited via IManualSceneBlueprint
	virtual void build(LevelSystem& level) override
	{
		int numOfCubes = 20;
		for (int i = 0; i < numOfCubes; ++i) {
			Cube& aCube = level.addGameObject<Cube>();
			Transform& t = *aCube.getComponent<Transform>();
			t.position = math::Vec3f(0, i*15.f, 0);
			t.scale = math::Vec3f(10, 10, 10);

			Model& model = aCube.addComponent<Model>();
			model.albedo.r = 0.f;
			model.albedo.g = 1.f;
			model.albedo.b = 0.f;

			RigidBody& rigid = aCube.addComponent<RigidBody>();
			rigid.mass = 1.f;
			BoxCollider& boxCollider = aCube.addComponent<BoxCollider>();
			boxCollider.width = 10;
			boxCollider.height = 10;
			boxCollider.depth = 10;
			boxCollider.material = PhysicsMaterial{0.5f, 0.5f, 0.5f};
			
			Engine::Get().getPhysicsSystem().InitRigidBody(rigid, level);
		}

		//GROUND
		Floor& ground = level.addGameObject<Floor>();
		Transform& groundT = *ground.getComponent<Transform>();
		groundT.position = math::Vec3f(0, -50, 0);
		groundT.scale = math::Vec3f(3000, 100, 3000);
		RigidBody& rigid = ground.addComponent<RigidBody>();
		rigid.mass = 1.f;
		rigid.isStatic = true;
		BoxCollider& boxCollider = ground.addComponent<BoxCollider>();
		boxCollider.width = 3000;
		boxCollider.height = 100;
		boxCollider.depth = 3000;
		boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.f };
		Engine::Get().getPhysicsSystem().InitRigidBody(rigid, level);

		//PLAYER
		Player& player = level.addGameObject<Player>();
		Transform& playerT = *player.getComponent<Transform>();
		playerT.position = math::Vec3f(30, 10, 0);
		playerT.scale = math::Vec3f(10, 10, 10);
		Model& playerModel = player.addComponent<Model>();
		playerModel.albedo.r = 1.f;
		playerModel.albedo.g = 1.f;
		playerModel.albedo.b = 1.f;

		RigidBody& playerRigid = player.addComponent<RigidBody>();
		playerRigid.mass = 5.f;
		playerRigid.isKinematic = true;
		BoxCollider& playerBoxCollider = player.addComponent<BoxCollider>();
		playerBoxCollider.width = 10;
		playerBoxCollider.height = 10;
		playerBoxCollider.depth = 10;
		playerBoxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
		Engine::Get().getPhysicsSystem().InitRigidBody(playerRigid, level);
	}
};

int main(int argc, char** argv) {
	Engine::Get().startup();
	MainScene scene;
	Engine::Get().loadScene(scene);
	Engine::Get().startLoop();
	Engine::Get().shutdown();
}