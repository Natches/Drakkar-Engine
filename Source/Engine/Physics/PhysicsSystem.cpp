#include <Engine/Physics/PhysicsSystem.h>
#include <PxPhysicsAPI.h>
#include <Core/Utils/MacroUtils.hpp>
#include <Engine/Components/Components.h>
#include <Engine/Physics/SimulationEvent.h>

#define SIM_RATE 1.f/120.f

DK_USE_NAMESPACE(drak)

#ifdef USE_PVD
#define PVD_HOST "127.0.0.1"
#endif

using namespace physx;

PhysicsSystem::PhysicsSystem() {
}


PhysicsSystem::~PhysicsSystem() {
}



bool drak::PhysicsSystem::InitPxScene(physx::PxScene ** pxScene) {
	physx::PxSceneDesc desc(*m_cScale);
	desc.filterShader = physx::PxDefaultSimulationFilterShader;
	desc.cpuDispatcher = physx::PxDefaultCpuDispatcherCreate(4);
	desc.broadPhaseType = physx::PxBroadPhaseType::eSAP;
	desc.simulationEventCallback = m_pSimulationEvent;
	/*if (m_pCUDAContextManager) {
		desc.gpuDispatcher = m_pCUDAContextManager->getGpuDispatcher();
		desc.flags |= physx::PxSceneFlag::eENABLE_GPU_DYNAMICS;
		desc.broadPhaseType = physx::PxBroadPhaseType::eGPU;
	}*/

	*pxScene = m_pPhysics->createScene(desc);
	(*pxScene)->setGravity(physx::PxVec3(0, -9.8f, 0));
	return false;
}

bool drak::PhysicsSystem::Update(physx::PxScene* scene, F64 deltaTime, std::vector<components::RigidBody>* rigidBodies, std::vector<components::Transform>* transforms) {
	AccumulatedTime += deltaTime;
	bool simulated = false;
	while (AccumulatedTime >= SIM_RATE)
	{
		scene->simulate(SIM_RATE);
		scene->fetchResults(true);
		simulated = true;
		AccumulatedTime -= SIM_RATE;
	}
	if (simulated)
	{
		for (I32 i = 0, size = (*rigidBodies).size(); i < size; ++i)
		{
			(*transforms)[i].position.x = (*rigidBodies)[i].rigidActor->getGlobalPose().p.x;
			(*transforms)[i].position.y = (*rigidBodies)[i].rigidActor->getGlobalPose().p.y;
			(*transforms)[i].position.z = (*rigidBodies)[i].rigidActor->getGlobalPose().p.z;

			(*transforms)[i].rotation.x = (*rigidBodies)[i].rigidActor->getGlobalPose().q.x;
			(*transforms)[i].rotation.y = (*rigidBodies)[i].rigidActor->getGlobalPose().q.y;
			(*transforms)[i].rotation.z = (*rigidBodies)[i].rigidActor->getGlobalPose().q.z;
			(*transforms)[i].rotation.w = (*rigidBodies)[i].rigidActor->getGlobalPose().q.w;
		}
	}
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

	/*physx::PxCudaContextManagerDesc cudaContextManagerDesc;

	m_pCUDAContextManager = PxCreateCudaContextManager(*m_pFoundation, cudaContextManagerDesc);
	if (m_pCUDAContextManager)
	{
		if (!m_pCUDAContextManager->contextIsValid())
		{
			m_pCUDAContextManager->release();
			m_pCUDAContextManager = NULL;
		}
	}*/
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

}