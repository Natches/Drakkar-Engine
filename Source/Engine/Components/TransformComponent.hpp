#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Serialization\MetaData.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
#include <map>

DRAK_COMPONENT_START(Transform)
DK_SERIALIZED_OBJECT(Transform)
math::Vec3f position = math::Vec3f(0, 0, 0);
math::Vec3f scale = math::Vec3f(1, 1, 1);
math::Vec4f rotation = math::Vec4f(0, 0, 0, 1);
bool dirty = false;
DRAK_COMPONENT_END(Transform)


//TODO add incremetor functions
void setTransformPos(drak::components::Transform& t, drak::math::Vec3f newPos);
void setTransformRot(drak::components::Transform& t, drak::math::Vec4f newRot);

DK_METADATA_BEGIN(drak::components::Transform)
DK_PUBLIC_FIELDS(position, scale, rotation)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
