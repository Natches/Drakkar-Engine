#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/Base/AResourceManager.hpp>
#include <Video/Graphics/Rendering/HighLevel/Material.hpp>

namespace drak {

namespace definition {
struct Material;
struct ResourceName;
} //namespace converter

namespace gfx {
class Material;
} //namespace gfx

class MaterialManager final : public AResourceManager<gfx::Material, MaterialMap> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(MaterialManager)

	using Base = typename AResourceManager<gfx::Material, MaterialMap>;

public:
	virtual void preload(const std::string& names, const std::string& filename);
	virtual void preload(const definition::ResourceName& names, const std::string& filename) override;
	void load(const std::string& filename, std::vector<definition::Material>& inMaterials);
	void reload(std::vector<definition::Material>& inMaterials);

private:
	MaterialManager() = default;
	virtual ~MaterialManager() = default;
};

} // namespace drak