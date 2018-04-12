#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Core/Engine/Event.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
namespace physx {
	class PxRigidActor;
}

struct PhysicsMaterial {
	F32 staticFriction;
	F32 dynamicFriction;
	F32 restitution;
};

DRAK_COMPONENT_START(BoxCollider, IPlural)
math::Vec3f localPosition = math::Vec3f(0,0,0);
math::Vec4f localRotation = math::Vec4f(0,0,0,1);
PhysicsMaterial material;
I32 width;
I32 height;
I32 depth;
DRAK_COMPONENT_END(BoxCollider)

DRAK_COMPONENT_START(RigidBody)
physx::PxRigidActor* rigidActor;
//std::vector<U32> boxColliderIDXs;
F32 mass;
bool isStatic;
bool isKinematic;
DRAK_COMPONENT_END(RigidBody)

