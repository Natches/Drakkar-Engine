#pragma once
#include "Core.hpp"
#include <vector>
/*!
*	@file
*	Stores the definition of all components.
*/


namespace drak {
namespace components {
#include "AComponentUtils.h"

DK_COMPONENT_START(Transform)
std::vector<Transform*> children;
Transform* parent;
DK_COMPONENT_END(Transform)

DK_COMPONENT_START(Mesh)
U32 meshID;
DK_COMPONENT_END(Mesh)

DK_COMPONENT_START(Simon)
int age;
DK_COMPONENT_END(Simon)

} //components
} //drak
