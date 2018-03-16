#pragma once
#include <Core/Core.hpp>
#include <vector>
/*!
*	@file
*	Stores the definition of all components.
*/


namespace drak {
namespace components {
#include <Core/Utils/AComponentUtils.h>

DRAK_COMPONENT_START(Transform)
std::vector<Transform*> children;
Transform* parent;
DRAK_COMPONENT_END(Transform)

DRAK_COMPONENT_START(Mesh)
U32 meshID;
DRAK_COMPONENT_END(Mesh)

DRAK_COMPONENT_START(Ben)
int howPD;
DRAK_COMPONENT_END(Ben)

} //components
} //drak
