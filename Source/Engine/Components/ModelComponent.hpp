#pragma once

#include <Core/Utils/AComponentUtils.hpp>
#include <Video/Graphics/Common/Color.hpp>
#include <Serialization\MetaData.hpp>

DRAK_COMPONENT_START(Model)
DK_SERIALIZED_OBJECT(Model)
std::string model;
DRAK_API void deleteComponent() { ; }
DRAK_API void initComponent() { ; }
DRAK_COMPONENT_END(Model)

DK_METADATA_BEGIN(drak::components::Model)
DK_PUBLIC_FIELDS(model, idx, GameObjectID)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END