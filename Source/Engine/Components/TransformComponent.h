#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <vector>

DRAK_COMPONENT_START(Transform)
std::vector<Transform*> children;
Transform* parent;
//math::Vec3f pos;
DRAK_COMPONENT_END(Transform)
