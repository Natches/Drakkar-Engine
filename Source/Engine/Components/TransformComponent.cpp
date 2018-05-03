#include <PrecompiledHeader/pch.hpp>
#include "TransformComponent.hpp"
#include "PhysicsComponents.hpp"
#include <Engine/Engine.hpp>

using namespace drak;
using namespace components;

void setTransformPos(Transform & t, math::Vec3f newPos)
{
	t.position = newPos;
	t.dirty = true;
}

void setTransformRot(Transform & t, math::Vec4f newRot)
{
	t.rotation = newRot;
	t.dirty = true;
}
