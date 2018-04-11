#pragma once

#include <ResourceManager/ResourceManager.hpp>
#include <Video/Graphics/Rendering/Texture.hpp>

namespace drak {

class TextureManager : public ResourceManager<gfx::Texture> {
public:
	ResourcePtr loadImpl(const std::string& filename) override;
};

using TexturePtr = TextureManager::ResourcePtr;

} // namespace drak