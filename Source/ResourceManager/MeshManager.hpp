#pragma once

#include <ResourceManager/ResourceManager.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

using MeshPtr = std::shared_ptr<geom::Mesh>;

class MeshManager : public ResourceManager {
public:
	MeshPtr createResource(const std::string& filename) override;
	MeshPtr loadResource(const std::string& filename) override;

};

} // namespace drak