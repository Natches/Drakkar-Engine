#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/Base/AResourceManager.hpp>
#include <Video/Graphics/Rendering/HighLevel/Texture.hpp>

namespace drak {

namespace definition {
struct Texture;
struct ResourceName;
} //namespace converter

namespace gfx {
class Texture;
} //namespace gfx

class TextureManager final : public AResourceManager<gfx::Texture, TextureMap> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(TextureManager)

	using Base = typename AResourceManager<gfx::Texture, TextureMap>;
public:
	virtual void preload(const std::string& names);
	virtual void preload(const definition::ResourceName& names) override;
	void load(const std::string& filename, std::vector<definition::Texture>& inTextures);
	void reload(std::vector<definition::Texture>& inTextures);

private:
	TextureManager() = default;
	virtual ~TextureManager() = default;
};

} // namespace drak