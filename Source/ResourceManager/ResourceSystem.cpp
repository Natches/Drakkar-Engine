#include <iostream> // TODO (Simon): replace with Log

#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

void ResourceSystem::startup() {
	std::cout << "ResourceSystem startup" << std::endl;
}

void ResourceSystem::shutdown() {
	std::cout << "ResourceSystem shutdown" << std::endl;
}

MeshPtr ResourceSystem::loadMesh(const std::string& filename) {
	m_pMeshManager->loadMesh(filename);
}

} // namespace drak 