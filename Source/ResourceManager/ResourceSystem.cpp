#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

void ResourceSystem::startup() {
	// m_pModelManager = new ModelManager();
}

void ResourceSystem::shutdown() {
	// delete m_pModelManager;
}

MeshPtr ResourceSystem::loadMesh(const std::string& filename) {
	return m_meshManager.loadMesh(filename);
}

} // namespace drak 