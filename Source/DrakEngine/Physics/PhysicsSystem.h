#pragma once
#include <Core/Core.hpp>
#include <PxPhysicsAPI.h>
using namespace physx;

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
	private:
		PhysicsSystem();
		~PhysicsSystem();
		bool InitPxScene(PxScene* pxScene);
		bool Update(physx::PxScene* scene, F64 deltaTime, components::RigidBody* rigidBodies, components::Transform* transforms);
		bool Startup();
		void Shutdown();
		PxFoundation*		m_pFoundation;
		PxPhysics*			m_pPhysics;
		PxCooking*			m_pCooking;
		PxTolerancesScale*	m_cScale;
#ifdef USE_PVD
		PxPvd*				m_pPvd;
#endif // DEBUG
		F64 AccumulatedTime;
	};
}


