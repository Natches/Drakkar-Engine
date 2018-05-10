#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Serialization\MetaData.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
#include <Math/Quaternion.hpp>
#include <map>

DRAK_COMPONENT_START(Transform)
DK_SERIALIZED_OBJECT(Transform)
math::Vec3f globalPosition = math::Vec3f(0, 0, 0);
math::Vec3f globalScale = math::Vec3f(1, 1, 1);
math::Quaternion globalRotation = math::Quaternion(1.f, math::Vec3f(0.f));
math::Vec3f localPosition = math::Vec3f(0, 0, 0);
math::Vec3f localScale = math::Vec3f(1, 1, 1);
math::Quaternion localRotation = math::Quaternion(1.f, math::Vec3f(0.f));
bool dirty = false;
bool m_isRoot = true;
DRAK_COMPONENT_END(Transform)


//TODO add incremetor functions
void setTransformPos(drak::components::Transform& t, drak::math::Vec3f newPos);
void setTransformRot(drak::components::Transform& t, drak::math::Quaternion newRot);

DK_METADATA_BEGIN(drak::components::Transform)
DK_PUBLIC_FIELDS(globalPosition, globalScale, globalRotation, localPosition, localScale, localRotation, m_isRoot, idx, GameObjectID)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
