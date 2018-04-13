#pragma once

#include <memory>
#include <unordered_map>

#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

using MeshPtr = std::shared_ptr<geom::Mesh>;
using MeshMap = std::unordered_map<const std::string&, MeshPtr>;

class MeshManager {
public:
	MeshPtr preloadMesh(const std::string& filename);
	MeshPtr loadMesh(const std::string& filename);

protected:
	friend class ResourceSystem;
	MeshManager() = default;

protected:
	MeshMap m_meshes;
};

} // namespace drak