#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/MeshManager.hpp>

using namespace drak::geom;
using namespace drak::gfx;

namespace drak {
MeshManager::MeshManager() {
}

ResourcePtr<geom::AMesh> MeshManager::get(const std::string& name) const {
	if (m_meshes.find(name) != m_meshes.end())
		return m_meshes.at(name);
	else
		return nullptr;
}

AResource::ELoadState MeshManager::state(const std::string& name) const {
	return AResource::ELoadState();
}

void MeshManager::registerResource(ResourcePtr<geom::AMesh>&& res) {
}

void MeshManager::unRegister(const std::string& name) {
	m_meshes[name].reset();
	m_meshes.erase(name);
}

} // namespace drak