#pragma once

#include <memory>
#include <unordered_map>

#include <Video/Graphics/Geometry/Mesh.hpp>
#include <ResourceManager/Resource.hpp>

namespace drak {

using MeshPtr		= std::shared_ptr<geom::Mesh>;
using MeshMap		= std::unordered_map<std::string, MeshPtr>;

class ResourceManager {
public:
	virtual ~ResourceManager();



protected:
	MeshMap	m_meshes;
};

} // namespace drak