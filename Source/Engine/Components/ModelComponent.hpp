#pragma once

#include <Core/Utils/AComponentUtils.hpp>
#include <Video/Graphics/Common/Color.hpp>
#include <Serialization\MetaData.hpp>

namespace drak {
namespace gfx {
class IRenderable;
}
}

DRAK_COMPONENT_START(Model)
DK_SERIALIZED_OBJECT(Model)
gfx::IRenderable* pModel;
gfx::Color3 albedo;
DRAK_COMPONENT_END(Model)

DK_METADATA_BEGIN(drak::components::Model)
DK_PUBLIC_FIELDS(albedo, idx, GameObjectID)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END