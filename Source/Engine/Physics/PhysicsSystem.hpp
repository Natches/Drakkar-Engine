#pragma once
#include <Core/Core.hpp>
#include <vector>
#include <unordered_map>
#include <Math/Vec3.hpp>

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
		bool InitPxScene(Scene* scene);
		void updateComponents(std::vector<components::Transform>& transforms);
		bool advance(F64 deltaTime, std::vector<components::Transform>& transforms, std::vector<components::RigidBody>& rigidBodies);
		bool Startup();
		void Shutdown();
		void applyImpulse(components::RigidBody& target, math::Vec3f& impulse);
		void applyForce(components::RigidBody& target, math::Vec3f& force);
		void changeVelocity(components::RigidBody& target, math::Vec3f& newVelocity);
		events::PhysicsEvents*		m_pPhysicsEvent;
		physx::PxFoundation*		m_pFoundation;
		physx::PxPhysics*			m_pPhysics;
		physx::PxCooking*			m_pCooking;
		physx::PxTolerancesScale*	m_cScale;
#ifdef USE_PVD
		physx::PxPvd*				m_pPvd;
		Scene* m_GameScene;
#endif // DEBUG
		F64 AccumulatedTime;
	};
}