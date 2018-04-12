#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Math/Matrix4x4.hpp>
#include <Windowing/Input/Keyboard.hpp>
#include <Engine\CreateDerivative.hpp>
#include <string>

using namespace drak;
using namespace core;
using namespace components;
using namespace events;
using namespace function;
using namespace math;

class Floor : public AGameObject {
	// Inherited via AGameObject
public:
	Floor() {
		derivedTypeID = 1;
		name = "Floor";
	}
	virtual void update() override
	{
	}
	virtual void start() override
	{
	}
};

class Cube : public AGameObject {
public:
	Cube() {
		derivedTypeID = 0;
		name = "Cube";
	}

	bool hitByPlayer = false;
	virtual void update() override {
	}

	virtual void start() override {
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
public:
	Player() {
		derivedTypeID = 2;
		name = "Player";
	}

	// Inherited via AGameObject
	float speed = 50.f;
	int score = 0;
	virtual void update() override
	{
	}

	virtual void start() override
	{
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

int main(int argc, char** argv) {
	Engine::Get().startup();
	Engine::Get().createAll<Cube>();
	Engine::Get().createAll<Floor>();
	Engine::Get().createAll<Player>();
	Engine::Get().startLoop();
	Engine::Get().shutdown();
}