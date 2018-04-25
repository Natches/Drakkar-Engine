#include <PrecompiledHeader/pch.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>
#include <Core/Utils/MacroUtils.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Scene/LevelSystem.hpp>

#define SIM_RATE 1.f/30.f 

DK_USE_NAMESPACE(drak)

#ifdef USE_PVD
#define PVD_HOST "127.0.0.1"
#endif

using namespace physx;
using namespace drak::components;

void drak::PhysicsSystem::InitRigidBody(components::RigidBody & rb, components::Transform& trans, LevelSystem& level)
{
	if (rb.isStatic) {
		rb.rigidActor = m_pPhysics->createRigidStatic(
			physx::PxTransform(
				trans.position.x,
				trans.position.y,
				trans.position.z,
				PxQuat(
					trans.rotation.x,
					trans.rotation.y,
					trans.rotation.z,
					trans.rotation.w
				)
			)
		);
	}
	else {
		rb.rigidActor = m_pPhysics->createRigidDynamic(
			physx::PxTransform(
				trans.position.x,
				trans.position.y,
				trans.position.z,
				PxQuat(
					trans.rotation.x,
					trans.rotation.y,
					trans.rotation.z,
					trans.rotation.w
				)
			)
		);
		if(rb.isKinematic)
			((physx::PxRigidDynamic*)rb.rigidActor)->setRigidBodyFlag(physx::PxRigidBodyFlag::eKINEMATIC, true);
		((physx::PxRigidDynamic*)rb.rigidActor)->setSleepThreshold(0.001f);
		physx::PxRigidBodyExt::updateMassAndInertia(*(physx::PxRigidDynamic*)rb.rigidActor, rb.mass);
	}

	BoxCollider& boxColldier = level.getGameObjects()[rb.GameObjectID]->getComponent<BoxCollider>();
	physx::PxMaterial* mat = m_pPhysics->createMaterial(
		boxColldier.material.staticFriction,
		boxColldier.material.dynamicFriction,
		boxColldier.material.restitution
	);
	physx::PxShape* box = m_pPhysics->createShape(
		PxBoxGeometry(
			boxColldier.width / 2.f,
			boxColldier.height / 2.f,
			boxColldier.depth / 2.f
		),
		*mat,
		true
	);
	box->setLocalPose(
		PxTransform(
			boxColldier.localPosition.x,
			boxColldier.localPosition.y,
			boxColldier.localPosition.z,
			PxQuat(
				boxColldier.localRotation.x,
				boxColldier.localRotation.y,
				boxColldier.localRotation.z,
				boxColldier.localRotation.w
			)
		)
	);
	rb.rigidActor->attachShape(*box);

	U64* goIDX = new U64;
	*goIDX = rb.GameObjectID;
	rb.rigidActor->userData = goIDX;
	m_pPhysicsScene->addActor(*rb.rigidActor);
	return;
}

void drak::PhysicsSystem::AddCollisionCallback(RigidBody& rb,
	events::EventType type, 
	events::EventListener listener)
{
	m_pPhysicsEvent->AddEventListener(rb, type, listener);
}

PhysicsSystem::PhysicsSystem() {
}


PhysicsSystem::~PhysicsSystem() {
}

PxFilterFlags DrakFilterShader(
	PxFilterObjectAttributes attributes0,
	PxFilterData filterData0,
	PxFilterObjectAttributes attributes1,
	PxFilterData filterData1,
	PxPairFlags& pairFlags,
	const void* constantBlock,
	PxU32 constantBlockSize){

	/*if (PxFilterObjectIsTrigger(attributes0) && PxFilterObjectIsTrigger(attributes1)) {
		pairFlags = PxPairFlag::eTRIGGER_DEFAULT;
		return PxFilterFlag::eCALLBACK;
	}*/
	pairFlags = PxPairFlag::eCONTACT_DEFAULT;
	pairFlags |= PxPairFlag::eNOTIFY_CONTACT_POINTS;
	pairFlags |= PxPairFlag::eDETECT_DISCRETE_CONTACT;
	pairFlags |= PxPairFlag::eNOTIFY_TOUCH_FOUND;
	pairFlags |= PxPairFlag::eNOTIFY_TOUCH_LOST;
	pairFlags |= PxPairFlag::eNOTIFY_TOUCH_PERSISTS;

	return PxFilterFlag::eDEFAULT;
	/*pairFlags |= PxPairFlag::eNOTIFY_CONTACT_POINTS & PxPairFlag::eNOTIFY_THRESHOLD_FORCE_FOUND &
		PxPairFlag::eNOTIFY_THRESHOLD_FORCE_LOST & PxPairFlag::eNOTIFY_THRESHOLD_FORCE_PERSISTS &
		PxPairFlag::eNOTIFY_TOUCH_FOUND & PxPairFlag::eNOTIFY_TOUCH_LOST & PxPairFlag::eNOTIFY_TOUCH_PERSISTS;*/
}

void drak::PhysicsSystem::updateComponents(LevelSystem& levelSystem) {
	m_pPhysicsScene->fetchResults(true);
	PxU32 nbActiveActors;
	PxActor** activeActors = m_pPhysicsScene->getActiveActors(nbActiveActors);
	std::vector<Transform>& transforms = levelSystem.getComponentContainerByType<Transform>();
	std::vector<AGameObject*>& gameObjects = levelSystem.getGameObjects();
	for (U32 i = 0; i < nbActiveActors; ++i) {
		Transform& t = transforms[gameObjects[*static_cast<U64*>(activeActors[i]->userData)]->getComponentIDX(ComponentType<Transform>::id)];
		PxRigidActor& actor = *(PxRigidActor*)activeActors[i];
		PxTransform actorTransform = actor.getGlobalPose();
		t.position.x = actorTransform.p.x;
		t.position.y = actorTransform.p.y;
		t.position.z = actorTransform.p.z;

		t.rotation.x = actorTransform.q.x;
		t.rotation.y = actorTransform.q.y;
		t.rotation.z = actorTransform.q.z;
		t.rotation.w = actorTransform.q.w;
	}
}

bool drak::PhysicsSystem::advance(F64 deltaTime, LevelSystem& levelSystem) {
	AccumulatedTime += deltaTime;
	if (AccumulatedTime > SIM_RATE * 3)
		AccumulatedTime = SIM_RATE;
	if (AccumulatedTime < SIM_RATE)
		return false;
	AccumulatedTime -= SIM_RATE;
	std::vector<Transform>& transforms = levelSystem.getComponentContainerByType<Transform>();
	std::vector<RigidBody>& rigidBodies = levelSystem.getComponentContainerByType<RigidBody>();
	std::vector<AGameObject*>& gameObjects = levelSystem.getGameObjects();
	for (int i = 0; i < transforms.size(); ++i) {
		if (transforms[i].dirty) {
			AGameObject& gameObject = *gameObjects[transforms[i].GameObjectID];
			if (gameObject.getComponentFlag(ComponentType<RigidBody>::id)) {
				transforms[i].dirty = false;
				PxTransform trans(
					transforms[i].position.x,
					transforms[i].position.y,
					transforms[i].position.z,
					PxQuat(transforms[i].rotation.x, transforms[i].rotation.y, transforms[i].rotation.z, transforms[i].rotation.w));
				rigidBodies[gameObject.getComponentIDX(ComponentType<RigidBody>::id)].rigidActor->setGlobalPose(trans);
			}
		}
	}
	m_pPhysicsScene->simulate(SIM_RATE);
	return true;
}

bool PhysicsSystem::Startup() {
	physx::PxDefaultErrorCallback* gDefaultErrorCallback = new physx::PxDefaultErrorCallback();
	physx::PxDefaultAllocator* gDefaultAllocatorCallback = new physx::PxDefaultAllocator();

	m_pFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, *gDefaultAllocatorCallback, *gDefaultErrorCallback);
	if (!m_pFoundation)
		Logbook::Log(Logbook::EOutput::BOTH, "Physics Log","Failed to create PhysX foundation.\n");

	bool recordMemoryAllocations = false;
	m_cScale = new physx::PxTolerancesScale();

#ifdef USE_PVD
	m_pPvd = PxCreatePvd(*m_pFoundation);
	physx::PxPvdTransport* transport = physx::PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	m_pPvd->connect(*transport, physx::PxPvdInstrumentationFlag::eALL);
	m_pPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_pFoundation, physx::PxTolerancesScale(*m_cScale), recordMemoryAllocations, m_pPvd);
#else
	m_pPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_pFoundation, physx::PxTolerancesScale(*m_cScale));
#endif
	if (!m_pPhysics)
		Logbook::Log(Logbook::EOutput::BOTH, "Physics Log", "Failed to create PhysX physics.\n");
	m_pPhysicsEvent = new events::PhysicsEvents;

	physx::PxSceneDesc desc(*m_cScale);
	desc.filterShader = DrakFilterShader;
	desc.cpuDispatcher = physx::PxDefaultCpuDispatcherCreate(4);
	desc.broadPhaseType = physx::PxBroadPhaseType::eSAP;
	desc.flags |= PxSceneFlag::eENABLE_ACTIVE_ACTORS;
	m_pPhysicsScene = m_pPhysics->createScene(desc);
	m_pPhysicsScene->setSimulationEventCallback(m_pPhysicsEvent);
	m_pPhysicsScene->setGravity(physx::PxVec3(0, -9.8f, 0));

	return true;
}

void PhysicsSystem::Shutdown() {
	if (m_pPhysicsScene) {
		m_pPhysicsScene->release();
		m_pPhysicsScene = NULL;
	}
	if (m_pPhysics) {
		m_pPhysics->release();
		m_pPhysics = NULL;
	}
#ifdef USE_PVD
	if (m_pPvd) {
		m_pPvd->release();
		m_pPvd = NULL;
	}
#endif
	/*if (m_pCUDAContextManager) {
		m_pCUDAContextManager->release();
		m_pCUDAContextManager = NULL;
	}*/
	if (m_pFoundation) {
		m_pFoundation->release();
		m_pFoundation = NULL;
	}
	delete m_pPhysicsEvent;

}

void drak::PhysicsSystem::applyImpulse(components::RigidBody & target, math::Vec3f & impulse) {
	((PxRigidDynamic*)target.rigidActor)->addForce(PxVec3(impulse.x, impulse.y, impulse.z), PxForceMode::eIMPULSE);
}

void drak::PhysicsSystem::applyForce(components::RigidBody & target, math::Vec3f & force) {
	((PxRigidDynamic*)target.rigidActor)->addForce(PxVec3(force.x, force.y, force.z), PxForceMode::eFORCE);
}

void drak::PhysicsSystem::changeVelocity(components::RigidBody & target, math::Vec3f & newVelocity) {
	((PxRigidDynamic*)target.rigidActor)->addForce(PxVec3(newVelocity.x, newVelocity.y, newVelocity.z), PxForceMode::eVELOCITY_CHANGE);
}

void drak::PhysicsSystem::goTo(components::RigidBody & target, math::Vec3f& newPos, math::Vec4f& newRot) {
	if (target.rigidActor->getConcreteType() == PxConcreteType::eRIGID_DYNAMIC) {
		if (((PxRigidDynamic*)target.rigidActor)->getRigidBodyFlags() == PxRigidBodyFlag::eKINEMATIC) {
			((PxRigidDynamic*)target.rigidActor)->setKinematicTarget(PxTransform(newPos.x, newPos.y, newPos.z, PxQuat(newRot.x, newRot.y, newRot.z, newRot.w)));
		}
		else {
			target.rigidActor->setGlobalPose(PxTransform(newPos.x, newPos.y, newPos.z, PxQuat(newRot.x, newRot.y, newRot.z, newRot.w)));
		}
	}
	
}
