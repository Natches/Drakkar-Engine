#pragma once
#include <Core/Core.hpp>
#include <vector>
#include <unordered_map>

namespace physx {
	class PxScene;
	class PxFoundation;
	class PxPhysics;
	class PxCooking;
	class PxTolerancesScale;
	class PxPvd;
	//class PxCudaContextManager;
}



//class ContactReport : physx::

namespace drak {
	class Scene;
	namespace components {
		struct RigidBody;
		struct Transform;
	}
	namespace core {
		class Engine;
	}
	namespace events {
		class PhysicsEvents;
	}

	class PhysicsSystem
	{
		DK_NONMOVABLE_NONCOPYABLE(PhysicsSystem)
		friend core::Engine;
	public:
		physx::PxPhysics* getPhysics() {return m_pPhysics; }
		DRAK_API void AddCollisionCallback(components::RigidBody* rb, events::EventType type, events::EventListener listener);
	private:
		PhysicsSystem();
		~PhysicsSystem();
		bool InitPxScene(physx::PxScene** pxScene);
		void updateComponents(Scene& scene, std::vector<components::RigidBody>& rigidBodies, std::vector<components::Transform>& transforms);
		bool advance(Scene& scene, F64 deltaTime);
		bool Startup();
		void Shutdown();
		events::PhysicsEvents*		m_pPhysicsEvent;
		physx::PxFoundation*		m_pFoundation;
		physx::PxPhysics*			m_pPhysics;
		physx::PxCooking*			m_pCooking;
		//physx::PxCudaContextManager* m_pCUDAContextManager;
		physx::PxTolerancesScale*	m_cScale;
#ifdef USE_PVD
		physx::PxPvd*				m_pPvd;
#endif // DEBUG
		F64 AccumulatedTime;
	};
}