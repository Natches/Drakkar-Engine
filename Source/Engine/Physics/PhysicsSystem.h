#pragma once
#include <Core/Core.hpp>
#include <vector>

namespace physx {
	class PxScene;
	class PxFoundation;
	class PxPhysics;
	class PxCooking;
	class PxTolerancesScale;
	class PxPvd;
	//class PxCudaContextManager;
}

class SimulationEvent;
//class ContactReport : physx::



namespace drak {
	namespace components {
		struct RigidBody;
		struct Transform;
	}
	namespace core {
		class Engine;
	}


	class PhysicsSystem
	{
		DK_NONMOVABLE_NONCOPYABLE(PhysicsSystem)
		friend core::Engine;
	public:
		physx::PxPhysics* getPhysics() {return m_pPhysics; }
	private:
		PhysicsSystem();
		~PhysicsSystem();
		bool InitPxScene(physx::PxScene** pxScene);
		bool Update(physx::PxScene* scene, F64 deltaTime, std::vector<components::RigidBody>* rigidBodies, std::vector<components::Transform>* transforms);
		bool Startup();
		void Shutdown();
		SimulationEvent*			m_pSimulationEvent;
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