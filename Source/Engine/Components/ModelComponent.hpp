#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Video/Graphics/Common/Color.hpp>

namespace drak {
	namespace gfx {
		class IRenderable;
	}
}

DRAK_COMPONENT_START(Model)
gfx::IRenderable* pModel;
gfx::Color3 albedo;
DRAK_COMPONENT_END(Model)