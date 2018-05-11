#include <PrecompiledHeader/pch.hpp>
#include <Engine/Components/TransformComponent.hpp>
#include <Engine/Components/PhysicsComponents.hpp>
#include <Engine/Engine.hpp>

using namespace drak;
using namespace components;

void setTransformPos(Transform & t, math::Vec3f newPos)
{
	t.position = newPos;
	t.dirty = true;
}

void setTransformRot(Transform & t, math::Quaternion newRot)
{
	t.rotation = newRot;
	t.dirty = true;
}
