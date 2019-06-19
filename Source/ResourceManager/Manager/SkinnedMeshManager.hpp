#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/Base/AResourceManager.hpp>
#include <Animation/Geometry/SkinnedMesh.hpp>

namespace drak {

namespace definition {
struct SkinnedMesh;
struct ResourceName;
} //namespace definition


class SkinnedMeshManager final : public AResourceManager<geom::SkinnedMesh, SkinnedMeshMap> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(SkinnedMeshManager)

		using Base = typename AResourceManager<geom::SkinnedMesh, SkinnedMeshMap>;
public:
	virtual void preload(const std::string& names, const std::string& filename);
	virtual void preload(const definition::ResourceName& rName, const std::string& filename) override;
	void load(const std::string& filename, std::vector<definition::SkinnedMesh>& inSkinnedMeshes);
	void reload(std::vector<definition::SkinnedMesh>& inSkinnedMeshes);

private:
	SkinnedMeshManager() = default;
	virtual ~SkinnedMeshManager() = default;
};

} // namespace drak