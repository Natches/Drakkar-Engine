#pragma once
#include <Core/Core.hpp>
//#include <Math/Vec3.hpp>
#include <vector>
/*!
*	@file
*	Stores the definition of all components.
*/

namespace drak {
namespace components {
#include <Core/Utils/AComponentUtils.hpp>

DRAK_COMPONENT_START(Transform)
std::vector<Transform*> children;
Transform* parent;
//math::Vec3f pos;
DRAK_COMPONENT_END(Transform)

} //components
} //drak
