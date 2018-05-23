#include <PrecompiledHeader\pch.hpp>
#include <PxPhysicsAPI.h>
#include <Engine\Physics\PhysicsSystem.hpp>
using namespace drak;
using namespace components;

void RigidBody::activate(bool value) {
	m_active = value;
	if (rigidActor == nullptr) {
		return;
	}
	rigidActor->setActorFlag(physx::PxActorFlag::eDISABLE_SIMULATION, !value);
}

RigidBody::RigidBody() {
}

RigidBody::~RigidBody(){
	rigidActor.reset();
	//if (rigidActor) {
	//	drak::core::Engine::Get().getPhysicsSystem().getPhysicsScene()->removeActor(*rigidActor);
	//}
}

//copy constructor
RigidBody::RigidBody(const RigidBody & other):
	AComponent(dynamic_cast<const AComponent&>(other)){
	mass = other.mass;
	isStatic = other.isStatic;
	isKinematic = other.isKinematic;
	m_active = other.m_active;
	rigidActor = other.rigidActor;
}
// move constructor
RigidBody::RigidBody(RigidBody && other):
	AComponent(dynamic_cast<const AComponent&>(other)),
	rigidActor(std::move(other.rigidActor)),
	mass(other.mass),
	isStatic(other.isStatic),
	isKinematic(other.isKinematic),
	m_active(other.m_active){
}
// copy assignment
RigidBody& RigidBody::operator=(const RigidBody & other){
	mass = other.mass;
	isStatic = other.isStatic;
	isKinematic = other.isKinematic;
	m_active = other.m_active;
	rigidActor = other.rigidActor;
	return *this;
}
// move assignment
RigidBody& RigidBody::operator=(RigidBody && other){
	if (this != &other) // prevent self-move
	{
		mass = other.mass;
		isStatic = other.isStatic;
		isKinematic = other.isKinematic;
		m_active = other.m_active;
		rigidActor = std::move(other.rigidActor);
	}
	return *this;
}