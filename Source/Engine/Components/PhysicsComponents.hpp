#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Core/Engine/Event.hpp>
#include <Serialization\MetaData.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
namespace physx {
	class PxRigidActor;
}

struct PhysicsMaterial {
	DK_SERIALIZED_OBJECT(PhysicsMaterial)
	F32 staticFriction;
	F32 dynamicFriction;
	F32 restitution;
};
DK_METADATA_BEGIN(PhysicsMaterial)
DK_PUBLIC_FIELDS(staticFriction, dynamicFriction, restitution)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DRAK_COMPONENT_START(BoxCollider)
math::Vec3f localPosition = math::Vec3f(0, 0, 0);
math::Vec4f localRotation = math::Vec4f(0, 0, 0, 1);
PhysicsMaterial material;
I32 width;
I32 height;
I32 depth;
DRAK_COMPONENT_END(BoxCollider)
DK_METADATA_BEGIN(drak::components::BoxCollider)
DK_PUBLIC_FIELDS(localPosition, localRotation, material, width, height, depth)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DRAK_COMPONENT_START(RigidBody)
DK_SERIALIZED_OBJECT(RigidBody)
	physx::PxRigidActor* rigidActor;
	//std::vector<U32> boxColliderIDXs;
	F32 mass;
	bool isStatic;
	bool isKinematic;
DRAK_COMPONENT_END(RigidBody)

DK_METADATA_BEGIN(drak::components::RigidBody)
DK_PUBLIC_FIELDS(mass, isStatic, isKinematic)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END


