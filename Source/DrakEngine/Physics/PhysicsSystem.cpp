#include <DrakEngine/Physics/PhysicsSystem.h>
#include <Core/Utils/MacroUtils.hpp>
#include <DrakEngine/Components/Components.h>


#define SIM_RATE 1.f/60.f

DK_IMPORT(drak)

#ifdef USE_PVD
#define PVD_HOST "127.0.0.1"
#endif


PhysicsSystem::PhysicsSystem() {
}


PhysicsSystem::~PhysicsSystem() {
}

bool drak::PhysicsSystem::InitPxScene(PxScene * pxScene) {
	PxSceneDesc desc(*m_cScale);
	desc.filterShader = PxDefaultSimulationFilterShader;
	desc.cpuDispatcher = PxDefaultCpuDispatcherCreate(4);

	pxScene = m_pPhysics->createScene(desc);
	pxScene->setGravity(PxVec3(0, -9.8f, 0));
	return false;
}

bool drak::PhysicsSystem::Update(physx::PxScene* scene, F64 deltaTime, components::RigidBody* rigidBodies, components::Transform* transforms) {
	AccumulatedTime += deltaTime;
	while (AccumulatedTime >= SIM_RATE)
	{
		scene->simulate(SIM_RATE);
		scene->fetchResults(true);
		AccumulatedTime -= SIM_RATE;
	}
	return true;
}

bool PhysicsSystem::Startup() {
	PxDefaultErrorCallback* gDefaultErrorCallback = new PxDefaultErrorCallback();
	PxDefaultAllocator* gDefaultAllocatorCallback = new PxDefaultAllocator();
	m_cScale = new PxTolerancesScale();
	m_cScale->length = 1;
	m_cScale->speed = 10;
	m_cScale->mass = 1000;

	m_pFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, *gDefaultAllocatorCallback, *gDefaultErrorCallback);
	if (!m_pFoundation)
		Logbook::Log(Logbook::EOutput::BOTH, "Physics Log","Failed to create PhysX foundation.\n");

	bool recordMemoryAllocations = false;
#ifdef USE_PVD
	m_pPvd = PxCreatePvd(*m_pFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	m_pPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);
	m_pPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_pFoundation, PxTolerancesScale(m_cScale), recordMemoryAllocations, m_pPvd);
#else
	m_pPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *m_pFoundation, *m_cScale, recordMemoryAllocations);
#endif
	if (!m_pPhysics)
		Logbook::Log(Logbook::EOutput::BOTH, "Physics Log", "Failed to create PhysX physics.\n");


	return false;
}

void PhysicsSystem::Shutdown() {
	m_pPhysics->release();
#ifdef USE_PVD
	m_pPvd->release();
#endif
	m_pFoundation->release();
}