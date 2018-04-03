#include "SimulationEvent.h"
#include <PxPhysicsAPI.h>
#include <Engine/Components/RigidBodyComponent.h>

using namespace physx;
using namespace drak;
using namespace events;

PhysicsEvents::PhysicsEvents() {
}


PhysicsEvents::~PhysicsEvents() {
}

void drak::events::PhysicsEvents::AddEventListener(components::RigidBody& rb, EventType type, EventListener listener)
{
	m_collisionEventDispatchers.insert({rb.rigidActor->getName(), PhysicsEventDispatcher()});
	m_collisionEventDispatchers[rb.rigidActor->getName()].addEventListener(type, listener);
}

void drak::events::PhysicsEventDispatcher::dispatchEvent(const Event * e) {
	DefaultEventDispatcher::dispatchEvent(e);
}

void PhysicsEvents::onConstraintBreak(PxConstraintInfo * constraints, PxU32 count) {
}

void PhysicsEvents::onWake(PxActor ** actors, PxU32 count) {
}

void PhysicsEvents::onSleep(PxActor ** actors, PxU32 count) {
}

void PhysicsEvents::onContact(const PxContactPairHeader & pairHeader, const PxContactPair * pairs, PxU32 nbPairs) {
	if (!pairHeader.flags.isSet(physx::PxContactPairHeaderFlag::eREMOVED_ACTOR_0) &&
		!pairHeader.flags.isSet(physx::PxContactPairHeaderFlag::eREMOVED_ACTOR_1)) {
		CollisionEvent e;
		e.type = PhysicsEventDispatcher::COLLISION_IN;
		m_collisionEventDispatchers[pairHeader.actors[0]->getName()].dispatchEvent(&e);
		m_collisionEventDispatchers[pairHeader.actors[1]->getName()].dispatchEvent(&e);
	}
}

void PhysicsEvents::onTrigger(PxTriggerPair * pairs, PxU32 count) {

}

void PhysicsEvents::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count) {
}