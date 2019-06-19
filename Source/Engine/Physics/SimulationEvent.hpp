#pragma once
#include <PXSimulationEventCallback.h>
#include <Core/Engine/Event.hpp>
#include <vector>
#include <unordered_map>
#include <string.h>

namespace drak {

namespace components {
	struct RigidBody;
}

namespace events {
struct CollisionEvent : public Event {
	U64 otherGameObjectIDX;
};

class PhysicsEventDispatcher : public DefaultEventDispatcher {
public:
	enum : EventType {
		COLLISION_IN,
		COLLISION_OUT,
		COLLISION_STAY
	};

protected:
	void dispatchEvent(const Event* e) override;

	friend class PhysicsEvents;
};

class PhysicsEvents : public physx::PxSimulationEventCallback {
	std::unordered_map<U64, PhysicsEventDispatcher> m_collisionEventDispatchers;
public:
	PhysicsEvents();
	~PhysicsEvents();
	void AddEventListener(const components::RigidBody& rb, EventType type,  EventListener listener);
	void onConstraintBreak(physx::PxConstraintInfo * constraints, physx::PxU32 count) override;
	void onWake(physx::PxActor ** actors, physx::PxU32 count) override;
	void onSleep(physx::PxActor ** actors, physx::PxU32 count) override;
	void onContact(const physx::PxContactPairHeader& pairHeader, const physx::PxContactPair * pairs, physx::PxU32 nbPairs) override;
	void onTrigger(physx::PxTriggerPair * pairs, physx::PxU32 count) override;
	void onAdvance(const physx::PxRigidBody * const * bodyBuffer, const physx::PxTransform * poseBuffer, const physx::PxU32 count) override;
};

}
}