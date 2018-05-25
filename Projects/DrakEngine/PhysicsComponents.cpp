#include <PrecompiledHeader\pch.hpp>
#include <Engine/Components/PhysicsComponents.hpp>
#include <PxPhysicsAPI.h>
using namespace drak;
using namespace components;

void drak::components::RigidBody::activate(bool value) {
	m_active = value;
	if (rigidActor == nullptr) {
		return;
	}
	rigidActor->setActorFlag(physx::PxActorFlag::eDISABLE_SIMULATION, !value);
}