#pragma once

#include <ResourceManager/ResourceManager.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

class MeshManager : public ResourceManager<geom::Mesh> {
protected:
	ResourcePtr loadImpl(const std::string& filename) override;
};

using MeshPtr = MeshManager::ResourcePtr;

} // namespace drak