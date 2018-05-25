#include <PrecompiledHeader\pch.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Engine.hpp>
#include <Game/BehaviorMonolith.h>
#include <Game/Cube.hpp>
#include <Engine/Scene/LevelSystem.hpp>

using namespace drak;
using namespace behavior;
using namespace events;
using namespace function;
using namespace components;

Cube::Cube() {
	updateBind = MemberFunction<Cube, void, const Event*>(this, &Cube::update, NULL);
	startBind = MemberFunction<Cube, void, const Event*>(this, &Cube::start, NULL);
	keyBind = MemberFunction<Cube, void, const Event*>(this, &Cube::OnKeyPress, NULL);
	collisionEnterBind = MemberFunction<Cube, void, const Event*>(this, &Cube::OnCollisionEnter, NULL);
	name = "Cube";
}

Cube::~Cube(){
}

void Cube::init() {
	bindUpdateToEngine();
	bindStartToEngine();
	bindKeyPressToEngine();
}

void Cube::update(const Event* pEvent) {

}

void Cube::start(const Event* pEvent) {
	BehaviorMonolith& mono = BehaviorMonolith::Get();
	RigidBody& rb = *getComponent<RigidBody>();
	core::Engine::Get().getPhysicsSystem().AddCollisionCallback(
		rb,
		PhysicsEventDispatcher::COLLISION_IN,
		&collisionEnterBind);
}

void Cube::OnKeyPress(const events::Event * pEvent) {
	if (!pEvent)
		return;
	const KeyEvent* key = static_cast<const KeyEvent*>(pEvent);
	RigidBody& rb = *getComponent<RigidBody>();
	Transform& trans = *getComponent<Transform>();
	switch (key->key)
	{
	case(Key::KEY_SPACE):
		if(getComponent<BoxCollider>())
			EngineCurrentLevel.DestroyComponent<BoxCollider>(getComponent<BoxCollider>()->idx);
		break;
	default:
		break;
	}
}

void Cube::OnCollisionEnter(const Event* pEvent) {
	if (!pEvent)
		return;
	const CollisionEvent* e = static_cast<const CollisionEvent*>(pEvent);
	switch (e->type) {
	case PhysicsEventDispatcher::COLLISION_IN:
		if (EngineCurrentLevel.getGameObjects()[e->otherGameObjectIDX].name == "Floor") {
			if (getComponent<Model>()) {
				Model& model = *getComponent<Model>();
				model.albedo.r = 1.0f;
				model.albedo.g = 1.0f;
				model.albedo.b = 0.0f;
			}
		}
		break;
	}
}

void Cube::OnCollisionExit(const Event* pEvent) {
}

void Cube::OnCollisionStay(const Event* pEvent) {
}

void Cube::bindUpdateToEngine() {
	core::Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_LOOP_START, &updateBind);
}
void Cube::bindStartToEngine() {
	core::Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_START, &startBind);
}

void Cube::bindKeyPressToEngine() {
	Keyboard::Get().addEventListener(KeyEvent::KEY_DOWN, &keyBind);
}
