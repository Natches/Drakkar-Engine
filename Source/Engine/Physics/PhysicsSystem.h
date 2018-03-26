#pragma once
#include <Core/Core.hpp>
namespace physx {
	class PxScene;
	class PxFoundation;
	class PxPhysics;
	class PxCooking;
	class PxTolerancesScale;
}

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
		bool InitPxScene(physx::PxScene** pxScene);
		bool Update(physx::PxScene* scene, F64 deltaTime, components::RigidBody* rigidBodies, components::Transform* transforms);
		bool Startup();
		void Shutdown();
		physx::PxFoundation*		m_pFoundation;
		physx::PxPhysics*			m_pPhysics;
		physx::PxCooking*			m_pCooking;
		physx::PxTolerancesScale*	m_cScale;
#ifdef USE_PVD
		PxPvd*				m_pPvd;
#endif // DEBUG
		F64 AccumulatedTime;
	};
}


