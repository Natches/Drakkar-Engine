#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/Base/AResourceManager.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

namespace definition {
struct Mesh;
struct ResourceName;
} //namespace converter


class MeshManager final : public AResourceManager<geom::Mesh, MeshMap> {
	friend class ResourceSystem;

	DK_NONMOVABLE_NONCOPYABLE(MeshManager)

	using Base = typename AResourceManager<geom::Mesh, MeshMap>;
public:
	virtual void preload(const std::string& names, const std::string& filename);
	virtual void preload(const definition::ResourceName& rName, const std::string& filename) override;
	void load(const std::string& filename, std::vector<definition::Mesh>& inMeshes);
	void reload(std::vector<definition::Mesh>& inMeshes);

private:
	MeshManager() = default;
	virtual ~MeshManager() = default;
};

} // namespace drak