#pragma once
#include <Core/Utils/AComponentUtils.hpp>
namespace physx {
	class PxRigidActor;
	class PxMaterial;
}
DRAK_COMPONENT_START(RigidBody)
physx::PxRigidActor* rigidActor;
physx::PxMaterial* material;
DRAK_COMPONENT_END(RigidBody)

