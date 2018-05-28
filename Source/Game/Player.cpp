#include <PrecompiledHeader\pch.hpp>
#include <Engine/Engine.hpp>
#include <Engine/InputManager.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include "Player.hpp"

using namespace drak;
using namespace core;
using namespace behavior;
using namespace events;
using namespace function;

Player::Player() : updateBind(MemberFunction<Player, void, const Event*>(this, &Player::update, NULL)),
startBind(MemberFunction<Player, void, const Event*>(this, &Player::start, NULL)) {
}

Player::~Player() {
}

void Player::init() {
	bindUpdateToEngine();
	bindStartToEngine();
}

void Player::update(const Event* pEvent) {
	gfx::Camera& camera = Engine::Get().getMainCamera();
	components::RigidBody* rigidBody = getComponent<components::RigidBody>();;

	components::Transform* transform = getComponent<components::Transform>();;

	if (transform && rigidBody) {
		if (InputManager::keyDown(events::Key::KEY_W)) {
			transform->setGlobalPosition(transform->getGlobalPosition() + math::Rotate(transform->getGlobalRotation(), math::Vec3f(0,0, -movementSpeed * DeltaTime)));
		}
		if (InputManager::keyDown(events::Key::KEY_S)) {
			transform->setGlobalPosition(transform->getGlobalPosition() + math::Rotate(transform->getGlobalRotation(), math::Vec3f(0, 0, movementSpeed * DeltaTime)));
		}
		if (InputManager::keyDown(events::Key::KEY_A)) {
			transform->setGlobalRotation(transform->getGlobalRotation() * (math::Quaternion(math::Vec3f(0, 1, 0), rotateSpeed * DeltaTime)));
		}
		if (InputManager::keyDown(events::Key::KEY_D)) {
			transform->setGlobalRotation(transform->getGlobalRotation() * (math::Quaternion(math::Vec3f(0, 1, 0), -rotateSpeed * DeltaTime)));
		}

		//if (InputManager::mousePos().x != oldMouseX) {
		//	if (InputManager::mousePos().x < oldMouseX) {
		//		transform->setGlobalRotation(transform->getGlobalRotation() * (math::Quaternion(math::Vec3f(0, 1, 0), rotateSpeed * DeltaTime)));
		//		--oldMouseX;
		//	}
		//	else if (InputManager::mousePos().x > oldMouseX) {
		//		transform->setGlobalRotation(transform->getGlobalRotation() * (math::Quaternion(math::Vec3f(0, 1, 0), -rotateSpeed * DeltaTime)));
		//		++oldMouseX;
		//	}
		//}
		camera.eye() = transform->getGlobalPosition() + math::Rotate(transform->getGlobalRotation(),cameraOffset);
		camera.at() = transform->getGlobalPosition();
	}

	//math::Vec3f movement;
	

	//camera.move(movement * movementSpeed * DeltaTime);

	//if (InputManager::keyDown(events::Key::KEY_LEFT)) {
	//	camera.at() = camera.eye() + math::Direction(camera.eye(), camera.at()).rotate<math::Axis::Y>(rotateSpeed * DeltaTime);
	//}
	//if (InputManager::keyDown(events::Key::KEY_RIGHT)) {
	//	camera.at() = camera.eye() + math::Direction(camera.eye(), camera.at()).rotate<math::Axis::Y>(-rotateSpeed * DeltaTime);
	//}



	camera.buildView();
}

void Player::start(const Event* pEvent) {
	//oldMouseX == InputManager::mousePos().x;
}

void Player::bindUpdateToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_START, new MemberFunction<Player, void, const Event*>(this, &Player::start));
}
void Player::bindStartToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_LOOP_START, new MemberFunction<Player, void, const Event*>(this, &Player::update));
}