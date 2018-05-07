#include <PrecompiledHeader/pch.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Engine.hpp>
#include <Game/BehaviorMonolith.h>
#include <Game/Cube.hpp>

using namespace drak;
using namespace behavior;
using namespace math;
using namespace events;
using namespace function;
using namespace components;

Cube::Cube() : updateBind(MemberFunction<Cube, void, const Event*>(this, &Cube::update, NULL)),
	startBind(MemberFunction<Cube, void, const Event*>(this, &Cube::start, NULL)),
	keyboardEventFunc(MemberFunction<Cube, void, const Event*>(this, &Cube::keyboardEvent, NULL)){
	name = "Cube";
}

Cube::~Cube(){
}

void Cube::init() {
	bindUpdateToEngine();
	bindStartToEngine();
}

void Cube::update(const Event* pEvent) {

}

void Cube::start(const Event* pEvent) {
	BehaviorMonolith& mono = BehaviorMonolith::Get();
	RigidBody& rb = getComponent<RigidBody>();
	core::Engine::Get().getPhysicsSystem().AddCollisionCallback(
		rb,
		PhysicsEventDispatcher::COLLISION_IN,
		new MemberFunction<Cube, void, const Event*>
		(this, &Cube::OnCollisionEnter));
	myTransform = &getComponent<Transform>();
	Keyboard::Get().addEventListener(KeyEvent::KEY_DOWN, &keyboardEventFunc);
	CameraComponent::BuildPerspective(getComponent<CameraComponent>());
	CameraComponent::BuildView(getComponent<CameraComponent>());
}

void Cube::keyboardEvent(const events::Event* pEvent) {
	if (!pEvent)
		return;
	const Key key = static_cast<const KeyEvent*>(pEvent)->key;
	DK_SELECT(key)
		DK_CASE(Key::KEY_UP, myTransform->position += Vec3f(0, 1, 0); CameraComponent::BuildView(getComponent<CameraComponent>()))
		DK_CASE(Key::KEY_DOWN, myTransform->position += Vec3f(0, -1, 0); CameraComponent::BuildView(getComponent<CameraComponent>()))
		DK_CASE(Key::KEY_LEFT, myTransform->position += Vec3f(-1, 0, 0); CameraComponent::BuildView(getComponent<CameraComponent>()))
		DK_CASE(Key::KEY_RIGHT, myTransform->position += Vec3f(1, 0, 0); CameraComponent::BuildView(getComponent<CameraComponent>()))
	DK_END

}

void Cube::OnCollisionEnter(const Event* pEvent) {
	if (!pEvent)
		return;
	const CollisionEvent* e = static_cast<const CollisionEvent*>(pEvent);
	switch (e->type) {
	case PhysicsEventDispatcher::COLLISION_IN:
		if (CurrentLevel.getGameObjects()[e->otherGameObjectIDX].name == "Floor") {
			Model& model = getComponent<Model>();
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

void Cube::bindUpdateToEngine() {
	core::Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_LOOP_START, &updateBind);
}
void Cube::bindStartToEngine() {
	core::Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::STARTUP_END, &startBind);
}