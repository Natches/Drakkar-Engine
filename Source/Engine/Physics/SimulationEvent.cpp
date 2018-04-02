#include "SimulationEvent.h"

using namespace physx;

SimulationEvent::SimulationEvent()
{
}


SimulationEvent::~SimulationEvent()
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
		//collisionPairs.push_back({ pairHeader.actors[0], pairHeader.actors[1] });
	}
}

void SimulationEvent::onTrigger(PxTriggerPair * pairs, PxU32 count)
{

}

void SimulationEvent::onAdvance(const PxRigidBody * const * bodyBuffer, const PxTransform * poseBuffer, const PxU32 count)
{
}
