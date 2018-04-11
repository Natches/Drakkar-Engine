#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

void ResourceSystem::startup() {
	
}

void ResourceSystem::shutdown() {

}

MeshPtr ResourceSystem::loadMesh(const std::string& filename) {
	m_pMeshManager->loadResource(filename);
}

TexturePtr ResourceSystem::loadTexture(const std::string& filename) {

}

} // namespace drak 