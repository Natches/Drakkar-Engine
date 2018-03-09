#pragma once

#include <Core/Types.hpp>

namespace drak {
namespace video {
namespace ogl {

extern bool s_Ready;

bool Init();

enum class DepthFunc : U8 {
	LESS, 
	LEQUAL, 
	EQUAL, 
	GEQUAL, 
	GREATER 
};
void DepthMode(bool on, DepthFunc func);

enum class CullFunc : U8 { 
	FRONT,
	BACK, 
	BOTH 
};
void CullMode(bool on, CullFunc func);

} // namespace ogl
} // namespace gfx
} // namespace drak
