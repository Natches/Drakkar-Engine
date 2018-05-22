#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/Base/AResourceManager.hpp>
#include <Video/Graphics/Rendering/HighLevel/Model.hpp>

namespace drak {

namespace definition {
struct Model;
struct ResourceName;
} //namespace converter

namespace gfx {
struct Model;
} //namespace gfx


class ModelManager final : public AResourceManager<gfx::Model, ModelMap> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(ModelManager)
public:
	virtual void preload(const definition::ResourceName& names) override;
	void load(const std::string& filename, std::vector<definition::Model>& inModels);
	void reload(std::vector<definition::Model>& ininModelsTex);

private:
	ModelManager() = default;
	virtual ~ModelManager() = default;
};

} // namespace drak