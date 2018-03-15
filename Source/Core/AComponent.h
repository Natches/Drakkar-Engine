#pragma once
#include <Core/Core.hpp>
#include <Math/Vec3.hpp>
#include <vector>
/*!
*	@file
*	Stores the definition of all components.
*/


namespace drak {
namespace components {
#include "AComponentUtils.h"

DRAK_COMPONENT_START(Transform)
std::vector<Transform*> children;
Transform* parent;
math::Vec3f pos;
DRAK_COMPONENT_END(Transform)

DRAK_COMPONENT_START(Other)
const char* text = "Hello World";
DRAK_COMPONENT_END(Other)

DRAK_COMPONENT_START(H1)
const char* text = "Hello World";
DRAK_COMPONENT_END(H1)

DRAK_COMPONENT_START(H2)
const char* text = "Hello World";
DRAK_COMPONENT_END(H2)

} //components
} //drak
