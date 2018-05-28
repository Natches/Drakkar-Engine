#pragma once
#include <Core/Core.hpp>
#include <vector>
#include <unordered_map>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
//#include <foundation/PxTransform.h>

namespace physx {
	class PxScene;
	class PxFoundation;
	class PxPhysics;
	class PxCooking;
	class PxTolerancesScale;
	class PxPvd;
	class PxShape;
	//class PxCudaContextManager;
}



//class ContactReport : physx::

namespace drak {
	class LevelSystem;
	class GameObject;
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
		DRAK_API physx::PxPhysics* getPhysics() { return m_pPhysics; }
		DRAK_API physx::PxScene& getPhysicsScene() { return *m_pPhysicsScene; }
		DRAK_API void AddCollisionCallback(const components::RigidBody& rb, events::EventType type, events::EventListener listener);
		DRAK_API void applyImpulse(components::RigidBody& target, math::Vec3f& impulse);
		DRAK_API void applyForce(components::RigidBody& target, math::Vec3f& force);
		DRAK_API void changeVelocity(components::RigidBody& target, math::Vec3f& newVelocity);
		DRAK_API void goTo(components::RigidBody& target, math::Vec3f& newPos, math::Quaternion& newRot = math::Quaternion(math::Vec4f(0,0,0,1)));
		DRAK_API bool raycast(math::Vec3f position, math::Vec3f direction, F32 maxLength, U32& gameObjectID);
	private:
		PhysicsSystem();
		~PhysicsSystem();
		void InitRigidBody(components::RigidBody & rb, components::Transform& trans, LevelSystem& level);
		//void attachChildrenToRoot(LevelSystem& level, components::RigidBody& target);
		//void addChildShapes(LevelSystem& level, GameObject& target, std::vector<std::pair<physx::PxShape*, physx::PxTransform>>& shapes);
		void updateComponents(LevelSystem& levelSystem);
		bool advance(F64 deltaTime, LevelSystem& levelSystem);
		bool Startup();
		void Shutdown();
		events::PhysicsEvents*		m_pPhysicsEvent;
		physx::PxFoundation*		m_pFoundation;
		physx::PxPhysics*			m_pPhysics;
		physx::PxCooking*			m_pCooking;
		physx::PxTolerancesScale*	m_cScale;
		physx::PxScene*				m_pPhysicsScene;
#ifdef USE_PVD
		physx::PxPvd*				m_pPvd;
#endif // DEBUG
		F64 AccumulatedTime;
	};
}