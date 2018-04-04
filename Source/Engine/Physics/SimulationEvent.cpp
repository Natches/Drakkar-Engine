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

void drak::events::PhysicsEvents::AddEventListener(components::RigidBody* rb, EventType type, EventListener listener)
{
	m_collisionEventDispatchers.insert({ *(std::string*)rb->rigidActor->userData, PhysicsEventDispatcher() });
	m_collisionEventDispatchers[*(std::string*)rb->rigidActor->userData].addEventListener(type, listener);
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
	CollisionEvent in;
	in.type = PhysicsEventDispatcher::COLLISION_IN;
	CollisionEvent out;
	out.type = PhysicsEventDispatcher::COLLISION_OUT;
	CollisionEvent stay;
	stay.type = PhysicsEventDispatcher::COLLISION_STAY;

	if (pairs->flags.isSet(PxContactPairFlag::eACTOR_PAIR_HAS_FIRST_TOUCH)) {
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[0]->userData)].dispatchEvent(&in);
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[1]->userData)].dispatchEvent(&in);
	}
	else if(pairs->flags.isSet(PxContactPairFlag::eACTOR_PAIR_LOST_TOUCH)) {
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[0]->userData)].dispatchEvent(&out);
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[1]->userData)].dispatchEvent(&out);
	}
	else if (pairHeader.pairs->events.isSet(PxPairFlag::eNOTIFY_TOUCH_PERSISTS)) {
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[0]->userData)].dispatchEvent(&stay);
		m_collisionEventDispatchers[*((std::string*)pairHeader.actors[1]->userData)].dispatchEvent(&stay);
	}
}

void PhysicsEvents::onTrigger(PxTriggerPair * pairs, PxU32 count) {

}

void PhysicsEvents::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count) {
}