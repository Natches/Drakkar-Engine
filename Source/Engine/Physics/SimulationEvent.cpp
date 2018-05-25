#include <PrecompiledHeader/pch.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Components/PhysicsComponents.hpp>
#include <Engine/Components/GameObject.hpp>
#include <PxPhysicsAPI.h>

using namespace physx;
using namespace drak;
using namespace events;

PhysicsEvents::PhysicsEvents() {
}


PhysicsEvents::~PhysicsEvents() {
}

void drak::events::PhysicsEvents::AddEventListener(const components::RigidBody& rb, EventType type, EventListener listener) {
	m_collisionEventDispatchers.insert({ rb.GameObjectID, PhysicsEventDispatcher() });
	m_collisionEventDispatchers[rb.GameObjectID].addEventListener(type, listener);
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
	if (pairs->flags.isSet(PxContactPairFlag::eACTOR_PAIR_HAS_FIRST_TOUCH)) {
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[0]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent in;
			in.type = PhysicsEventDispatcher::COLLISION_IN;
			in.otherGameObjectIDX = (*(U64*)pairHeader.actors[1]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[0]->userData)].dispatchEvent(&in);
		}
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[1]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent in;
			in.type = PhysicsEventDispatcher::COLLISION_IN;
			in.otherGameObjectIDX = (*(U64*)pairHeader.actors[0]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[1]->userData)].dispatchEvent(&in);
		}
	}
	else if(pairs->flags.isSet(PxContactPairFlag::eACTOR_PAIR_LOST_TOUCH)) {
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[0]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent out;
			out.type = PhysicsEventDispatcher::COLLISION_OUT;
			out.otherGameObjectIDX = (*(U64*)pairHeader.actors[1]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[0]->userData)].dispatchEvent(&out);
		}
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[1]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent out;
			out.type = PhysicsEventDispatcher::COLLISION_OUT;
			out.otherGameObjectIDX = (*(U64*)pairHeader.actors[0]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[1]->userData)].dispatchEvent(&out);
		}
	}
	else if (pairHeader.pairs->events.isSet(PxPairFlag::eNOTIFY_TOUCH_PERSISTS)) {
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[0]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent stay;
			stay.type = PhysicsEventDispatcher::COLLISION_STAY;
			stay.otherGameObjectIDX = (*(U64*)pairHeader.actors[1]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[0]->userData)].dispatchEvent(&stay);
		}
		if (m_collisionEventDispatchers.find((*(U64*)pairHeader.actors[1]->userData)) != m_collisionEventDispatchers.end()) {
			CollisionEvent stay;
			stay.type = PhysicsEventDispatcher::COLLISION_STAY;
			stay.otherGameObjectIDX = (*(U64*)pairHeader.actors[0]->userData);
			m_collisionEventDispatchers[(*(U64*)pairHeader.actors[1]->userData)].dispatchEvent(&stay);
		}
	}
}

void PhysicsEvents::onTrigger(PxTriggerPair * pairs, PxU32 count) {

}

void PhysicsEvents::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count) {
}
