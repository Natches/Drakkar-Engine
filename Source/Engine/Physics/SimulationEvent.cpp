#include "SimulationEvent.hpp"
#include <PxPhysicsAPI.h>
#include <Engine/Components/RigidBodyComponent.hpp>
#include <Core/Components/AGameObject.hpp>

using namespace physx;
using namespace drak;
using namespace events;

PhysicsEvents::PhysicsEvents() {
}


PhysicsEvents::~PhysicsEvents() {
}

void drak::events::PhysicsEvents::AddEventListener(components::RigidBody* rb, EventType type, EventListener listener)
{
	m_collisionEventDispatchers.insert({ ((AGameObject*)rb->rigidActor->userData)->id, PhysicsEventDispatcher() });
	m_collisionEventDispatchers[((AGameObject*)rb->rigidActor->userData)->id].addEventListener(type, listener);
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
		if(m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[0]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[0]->userData)->id].dispatchEvent(&in);
		if (m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[1]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[1]->userData)->id].dispatchEvent(&in);
	}
	else if(pairs->flags.isSet(PxContactPairFlag::eACTOR_PAIR_LOST_TOUCH)) {
		if (m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[0]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[0]->userData)->id].dispatchEvent(&out);
		if (m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[1]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[1]->userData)->id].dispatchEvent(&out);
	}
	else if (pairHeader.pairs->events.isSet(PxPairFlag::eNOTIFY_TOUCH_PERSISTS)) {
		if (m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[0]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[0]->userData)->id].dispatchEvent(&stay);
		if (m_collisionEventDispatchers.find(((AGameObject*)pairHeader.actors[1]->userData)->id) != m_collisionEventDispatchers.end())
			m_collisionEventDispatchers[((AGameObject*)pairHeader.actors[1]->userData)->id].dispatchEvent(&stay);
	}
}

void PhysicsEvents::onTrigger(PxTriggerPair * pairs, PxU32 count) {

}

void PhysicsEvents::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count) {
}