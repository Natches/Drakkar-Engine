#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/ResourceDefinitions.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {

class MeshManager final {
	DK_NONMOVABLE_NONCOPYABLE(MeshManager)

private:
	friend class ResourceSystem;
	MeshManager();

private:
	MeshMap m_meshes;
};

} // namespace drak