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

public:
	virtual void preload(const definition::ResourceName& rName) override;
	void load(const std::string& filename, std::vector<definition::Mesh>& inMeshes);
	void reload(std::vector<definition::Mesh>& inMeshes);

private:
	MeshManager() = default;
	virtual ~MeshManager() = default;
};

} // namespace drak