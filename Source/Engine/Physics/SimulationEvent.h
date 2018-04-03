#pragma once
#include <PxSimulationEventCallback.h>
#include <Core/Engine/Event.hpp>
#include <vector>
#include <unordered_map>

namespace drak {
	namespace events {

		class CollisionEventDispatcher: public IEventDispatcher {
		public:


			// Inherited via IEventDispatcher
			virtual void addEventListener(EventType type, EventListener listener) override;

			virtual void removeEventListener(EventType type, EventListener listener) override;

			virtual void dispatchEvent(const Event * e) override;

		};

		class SimulationEvent : public physx::PxSimulationEventCallback
		{
			std::unordered_map<const char *, CollisionEventDispatcher> m_collisionEventDispatchers;
		public:
			SimulationEvent();
			~SimulationEvent();
			void AddCollisionEvent(const char* name);
			void AddEventListener(const char* name, EventListener listener);
			void RemoveEventListener(const char* name, EventListener listener);
			// Inherited via PxSimulationEventCallback
			virtual void onConstraintBreak(physx::PxConstraintInfo * constraints, physx::PxU32 count) override;
			virtual void onWake(physx::PxActor ** actors, physx::PxU32 count) override;
			virtual void onSleep(physx::PxActor ** actors, physx::PxU32 count) override;
			virtual void onContact(const physx::PxContactPairHeader & pairHeader, const physx::PxContactPair * pairs, physx::PxU32 nbPairs) override;
			virtual void onTrigger(physx::PxTriggerPair * pairs, physx::PxU32 count) override;
			virtual void onAdvance(const physx::PxRigidBody * const * bodyBuffer, const physx::PxTransform * poseBuffer, const physx::PxU32 count) override;
		};
	}
}
