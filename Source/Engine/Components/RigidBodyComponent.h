#pragma once
#include <Core/Utils/AComponentUtils.hpp>
namespace physx {
	class PxRigidActor;
}
DRAK_COMPONENT_START(RigidBody)
physx::PxRigidActor* rigidActor;
DRAK_COMPONENT_END(RigidBody)