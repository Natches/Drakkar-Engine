#include <PrecompiledHeader\pch.hpp>
#include <Engine/Engine.hpp>
#include <Engine/InputManager.hpp>
#include "CameraController.hpp"

#include <Engine/Scene/LevelSystem.hpp>

using namespace drak;
using namespace core;
using namespace behavior;
using namespace events;
using namespace function;

CameraController::CameraController() : updateBind(MemberFunction<CameraController, void, const Event*>(this, &CameraController::update, NULL)),
startBind(MemberFunction<CameraController, void, const Event*>(this, &CameraController::start, NULL)) {
}

CameraController::~CameraController() {
}

void CameraController::init() {
	bindUpdateToEngine();
	bindStartToEngine();
}

void CameraController::update(const Event* pEvent) {
	gfx::Camera& camera = Engine::Get().getMainCamera();
	math::Vec3f movement;
	if (InputManager::keyDown(events::Key::KEY_W)) {
		movement += -camera.forward();
	}
	if (InputManager::keyDown(events::Key::KEY_S)) {
		movement += camera.forward();
	}
	if (InputManager::keyDown(events::Key::KEY_A)) {
		movement += -camera.right();
	}
	if (InputManager::keyDown(events::Key::KEY_D)) {
		movement += camera.right();
	}
	if (InputManager::keyDown(events::Key::KEY_Q)) {
		movement += camera.up();
	}
	if (InputManager::keyDown(events::Key::KEY_E)) {
		movement += -camera.up();
	}

	camera.move(movement * movementSpeed * DeltaTime);

	if (InputManager::keyDown(events::Key::KEY_LEFT)) {
		camera.at() = camera.eye() + math::Direction(camera.eye(), camera.at()).rotate<math::Axis::Y>(rotateSpeed * DeltaTime);
	}
	if (InputManager::keyDown(events::Key::KEY_RIGHT)) {
		camera.at() = camera.eye() + math::Direction(camera.eye(), camera.at()).rotate<math::Axis::Y>(-rotateSpeed * DeltaTime);
	}

	camera.buildView();
}

void CameraController::start(const Event* pEvent) {

}

void CameraController::bindUpdateToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_START, new MemberFunction<CameraController, void, const Event*>(this, &CameraController::start));
}
void CameraController::bindStartToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_LOOP_START, new MemberFunction<CameraController, void, const Event*>(this, &CameraController::update));
}