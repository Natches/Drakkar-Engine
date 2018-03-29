#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>

DRAK_COMPONENT_START(Transform)
math::Vec3f position;
math::Vec3f scale;
math::Vec4f rotation;
DRAK_COMPONENT_END(Transform)
