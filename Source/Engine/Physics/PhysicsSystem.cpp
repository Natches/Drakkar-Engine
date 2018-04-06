#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>
#include <Core/Utils/MacroUtils.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Engine/Scene/SceneSystem.hpp>

#define SIM_RATE 1.f/30.f 

DK_IMPORT(drak)

#ifdef USE_PVD
#define PVD_HOST "127.0.0.1"
#endif

using namespace physx;
using namespace drak::components;

void drak::PhysicsSystem::AddCollisionCallback(RigidBody* rb,
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

bool drak::PhysicsSystem::InitPxScene(Scene* scene) {
	physx::PxSceneDesc desc(*m_cScale);
	m_GameScene = scene;
	desc.filterShader = DrakFilterShader;
	desc.cpuDispatcher = physx::PxDefaultCpuDispatcherCreate(4);
	desc.broadPhaseType = physx::PxBroadPhaseType::eSAP;
	desc.flags |= PxSceneFlag::eENABLE_ACTIVE_ACTORS;
	PxScene** pxScene= &m_GameScene->m_pPhysXScene;
	*pxScene = m_pPhysics->createScene(desc);
	(*pxScene)->setSimulationEventCallback(m_pPhysicsEvent);
	(*pxScene)->setGravity(physx::PxVec3(0, -9.8f, 0));
	return false;
}

void drak::PhysicsSystem::updateComponents(std::vector<Transform>& transforms) {
	m_GameScene->m_pPhysXScene->fetchResults(true);
	PxU32 nbActiveActors;
	PxActor** activeActors = m_GameScene->m_pPhysXScene->getActiveActors(nbActiveActors);
	printf("%i\n", nbActiveActors);
	for (I32 i = 0; i < nbActiveActors; ++i) {
		Transform& t = transforms[((AGameObject*)activeActors[i]->userData)->transformIDX];
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

bool drak::PhysicsSystem::advance(F64 deltaTime, std::vector<Transform>& transforms, std::vector<components::RigidBody>& rigidBodies)
{
	AccumulatedTime += deltaTime;
	if (AccumulatedTime > SIM_RATE * 3)
		AccumulatedTime = 0;
	if (AccumulatedTime < SIM_RATE)
		return false;
	AccumulatedTime -= SIM_RATE;
	U64 hasRigidBodyFlag = 1 << ComponentType<RigidBody>::id;
	for (int i = 0; i < transforms.size(); ++i) {
		if (transforms[i].dirty) {
			if ((transforms[i].m_componentFlags & hasRigidBodyFlag) == hasRigidBodyFlag) {
				transforms[i].dirty = false;
				PxTransform trans(
					transforms[i].position.x,
					transforms[i].position.y,
					transforms[i].position.z,
					PxQuat(transforms[i].rotation.x, transforms[i].rotation.y, transforms[i].rotation.z, transforms[i].rotation.w));
				rigidBodies[transforms[i].m_handlesToComponents[ComponentType<RigidBody>::id]].rigidActor->setGlobalPose(trans);
			}
		}
	}
	m_GameScene->m_pPhysXScene->simulate(SIM_RATE);
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
	return true;
}

void PhysicsSystem::Shutdown() {
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