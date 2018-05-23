#include <PrecompiledHeader/pch.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>
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

void drak::PhysicsSystem::InitRigidBody(components::RigidBody& rb, components::Transform& trans, LevelSystem& level)
{
	BoxCollider& boxCollider = level.getGameObjects()[rb.GameObjectID].getComponent<BoxCollider>();
	physx::PxMaterial* mat = m_pPhysics->createMaterial(
		boxCollider.material.staticFriction,
		boxCollider.material.dynamicFriction,
		boxCollider.material.restitution
	);
	if (rb.isStatic) {
		rb.rigidActor = m_pPhysics->createRigidStatic(
			physx::PxTransform(
				trans.getGlobalPosition().x,
				trans.getGlobalPosition().y,
				trans.getGlobalPosition().z,
				PxQuat(
					trans.getGlobalRotation().m_vecPart.x,
					trans.getGlobalRotation().m_vecPart.y,
					trans.getGlobalRotation().m_vecPart.z,
					trans.getGlobalRotation().m_scalar
				)
			)
		);
		PxShape* shape = PxRigidActorExt::createExclusiveShape(*rb.rigidActor, PxBoxGeometry(boxCollider.width * 0.25f, boxCollider.height * 0.25f, boxCollider.depth * 0.25f), *mat);
		shape->setLocalPose(
			PxTransform(
				boxCollider.localPosition.x,
				boxCollider.localPosition.y,
				boxCollider.localPosition.z,
				PxQuat(boxCollider.localRotation.x,
					boxCollider.localRotation.y,
					boxCollider.localRotation.z,
					boxCollider.localRotation.w)));
	}
	else {
		rb.rigidActor = m_pPhysics->createRigidDynamic(
			physx::PxTransform(
				trans.getGlobalPosition().x,
				trans.getGlobalPosition().y,
				trans.getGlobalPosition().z,
				PxQuat(
					trans.getGlobalRotation().m_vecPart.x,
					trans.getGlobalRotation().m_vecPart.y,
					trans.getGlobalRotation().m_vecPart.z,
					trans.getGlobalRotation().m_scalar
				)
			)
		);
		if(rb.isKinematic)
			((physx::PxRigidDynamic*)rb.rigidActor)->setRigidBodyFlag(physx::PxRigidBodyFlag::eKINEMATIC, true);
		PxShape* shape = PxRigidActorExt::createExclusiveShape(*rb.rigidActor, PxBoxGeometry(boxCollider.width * 0.25f, boxCollider.height * 0.25f, boxCollider.depth * 0.25f), *mat);
		shape->setLocalPose(
			PxTransform(
				boxCollider.localPosition.x,
				boxCollider.localPosition.y,
				boxCollider.localPosition.z,
				PxQuat(boxCollider.localRotation.x,
					boxCollider.localRotation.y,
					boxCollider.localRotation.z,
					boxCollider.localRotation.w)));
		physx::PxRigidBodyExt::updateMassAndInertia(*(physx::PxRigidDynamic*)rb.rigidActor, rb.mass);
	}

	U64* goIDX = new U64;
	*goIDX = rb.GameObjectID;
	rb.rigidActor->userData = goIDX;
	m_pPhysicsScene->addActor(*rb.rigidActor);
	rb.rigidActor->setActorFlag(PxActorFlag::eDISABLE_SIMULATION, !rb.active());
	return;
}

void drak::PhysicsSystem::AddCollisionCallback(const RigidBody& rb,
	events::EventType type, 
	events::EventListener listener){
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
	std::vector<GameObject>& gameObjects = levelSystem.getGameObjects();
	for (U32 i = 0; i < nbActiveActors; ++i) {
		Transform& t = transforms[gameObjects[*static_cast<U64*>(activeActors[i]->userData)].getComponentIDX(ComponentType<Transform>::id)];
		PxRigidActor& actor = *(PxRigidActor*)activeActors[i];
		PxTransform actorTransform = actor.getGlobalPose();
		t.setGlobalPosition( math::Vec3f(actorTransform.p.x, actorTransform.p.y, actorTransform.p.z));
		t.setGlobalRotation(math::Quaternion(actorTransform.q.w, math::Vec3f(actorTransform.q.x, actorTransform.q.y, actorTransform.q.z)));
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
	std::vector<GameObject>& gameObjects = levelSystem.getGameObjects();
	for (int i = 0; i < transforms.size(); ++i) {
		if (transforms[i].isDirty()) {
			GameObject& gameObject = gameObjects[transforms[i].GameObjectID];
			if (gameObject.getComponentFlag(ComponentType<RigidBody>::id)) {
				transforms[i].isDirty() = false;
				PxTransform trans(
					transforms[i].getGlobalPosition().x,
					transforms[i].getGlobalPosition().y,
					transforms[i].getGlobalPosition().z,
					PxQuat(transforms[i].getGlobalRotation().m_vecPart.x, transforms[i].getGlobalRotation().m_vecPart.y, transforms[i].getGlobalRotation().m_vecPart.z, transforms[i].getGlobalRotation().m_scalar));
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

/*void drak::PhysicsSystem::addChildShapes(LevelSystem & level, GameObject& target, std::vector<std::pair<physx::PxShape*, physx::PxTransform>>& shapes) {
	for (U32 i = 0; i < target.children().size(); ++i) {
		GameObject& child = level.m_gameObjects[target.children()[i]];
		if (child.getComponentFlag(ComponentType<RigidBody>::id)) {
			RigidBody& childRB = child.getComponent<RigidBody>();
			childRB.rigidActor->setActorFlag(PxActorFlag::eDISABLE_SIMULATION, true);
			U32 shapeCount = childRB.rigidActor->getNbShapes();
			PxShape** childShapes = new PxShape*[shapeCount];
			shapeCount = childRB.rigidActor->getShapes(childShapes, shapeCount);
			for (U32 i = 0; i < shapeCount; ++i) {
				PxVec3 pos = PxShapeExt::getGlobalPose(*childShapes[i], *childRB.rigidActor).p;
				shapes.push_back(std::make_pair(childShapes[i], PxShapeExt::getGlobalPose(*childShapes[i], *childRB.rigidActor)));
			}
		}
		addChildShapes(level, child, shapes);
	}
}*/

/*void drak::PhysicsSystem::attachChildrenToRoot(LevelSystem& level, components::RigidBody& target){
	GameObject& gameObject = level.m_gameObjects[target.GameObjectID];
	std::vector<std::pair<physx::PxShape*, physx::PxTransform>> shapes;
	for (U32 i = 0; i < gameObject.children().size(); ++i) {
		if (level.m_gameObjects[gameObject.children()[i]].getComponentFlag(ComponentType<RigidBody>::id)) {
			RigidBody& childRB = level.m_gameObjects[gameObject.children()[i]].getComponent<RigidBody>();
			childRB.rigidActor->setActorFlag(PxActorFlag::eDISABLE_SIMULATION, true);
			U32 shapeCount = childRB.rigidActor->getNbShapes();
			PxShape** childShapes = new PxShape*[shapeCount];
			shapeCount = childRB.rigidActor->getShapes(childShapes, shapeCount);
			for (U32 i = 0; i < shapeCount; ++i) {
				shapes.push_back(std::make_pair(childShapes[i], PxShapeExt::getGlobalPose(*childShapes[i], *childRB.rigidActor)));
			}
		}
		addChildShapes(level, level.m_gameObjects[gameObject.children()[i]], shapes);
	}

	for (U32 i = 0; i < shapes.size(); ++i) {
		PxShape* shape = PxRigidActorExt::createExclusiveShape(*target.rigidActor, shapes[i].first->getGeometry().any(), *shapes[i].first->getMaterialFromInternalFaceIndex(1));
		shapes[i].second;
		PxVec3 globalPos = shapes[i].second.p;
		shape->setLocalPose(
			PxTransform(
				shapes[i].second.p - target.rigidActor->getGlobalPose().p,
				shapes[i].first->getLocalPose().q));
		//physx::PxRigidBodyExt::updateMassAndInertia(*target.rigidActor, rb.mass);
	}
	//target.rigidActor = m_pPhysics->createRigidDynamic(target.rigidActor->getGlobalPose());
	//physx::PxRigidBodyExt::updateMassAndInertia((*(PxRigidBody*)target.rigidActor), target.mass);
}*/