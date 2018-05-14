#include <PrecompiledHeader/pch.hpp>
#include "TransformComponent.hpp"
#include "PhysicsComponents.hpp"
#include <Engine/Engine.hpp>

using namespace drak;
using namespace components;

void setTransformPos(Transform & t, math::Vec3f newPos)
{
	if (t.m_isRoot)
		t.globalPosition = newPos;
	else
		t.localPosition = newPos;
	t.dirty = true;
}

void setTransformRot(Transform & t, math::Quaternion newRot)
{
	if (t.m_isRoot)
		t.globalRotation = newRot;
	else
		t.localRotation = newRot;
	t.dirty = true;
}
