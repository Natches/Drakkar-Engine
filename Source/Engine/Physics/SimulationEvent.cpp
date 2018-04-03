#include "SimulationEvent.h"
#include <PxPhysicsAPI.h>

using namespace physx;
using namespace drak;
using namespace events;

SimulationEvent::SimulationEvent()
{
}


SimulationEvent::~SimulationEvent()
{
}

void drak::events::SimulationEvent::AddCollisionEvent(const char* name)
{
	m_collisionEventDispatchers.insert({ name, CollisionEventDispatcher() });
}

void drak::events::SimulationEvent::AddEventListener(const char* name, EventListener listener)
{
	//m_collisionEventDispatchers[name].addEventListener(listener);
}

void drak::events::SimulationEvent::RemoveEventListener(const char* name, EventListener listener)
{
}

void SimulationEvent::onConstraintBreak(PxConstraintInfo * constraints, PxU32 count)
{
}

void SimulationEvent::onWake(PxActor ** actors, PxU32 count)
{
}

void SimulationEvent::onSleep(PxActor ** actors, PxU32 count)
{
}

void SimulationEvent::onContact(const PxContactPairHeader & pairHeader, const PxContactPair * pairs, PxU32 nbPairs)
{
	if (!pairHeader.flags.isSet(physx::PxContactPairHeaderFlag::eREMOVED_ACTOR_0) && !pairHeader.flags.isSet(physx::PxContactPairHeaderFlag::eREMOVED_ACTOR_1)) {
		//m_collisionEventDispatchers[pairHeader.actors[0]->getName()];
	}
}

void SimulationEvent::onTrigger(PxTriggerPair * pairs, PxU32 count)
{

}

void SimulationEvent::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count)
{
}

void drak::events::CollisionEventDispatcher::addEventListener(EventType type, EventListener listener)
{
}

void drak::events::CollisionEventDispatcher::removeEventListener(EventType type, EventListener listener)
{
}

void drak::events::CollisionEventDispatcher::dispatchEvent(const Event * e)
{
}
