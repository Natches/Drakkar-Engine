#pragma once

#include <ResourceManager/MeshManager.hpp>
#include <ResourceManager/TextureManager.hpp>

namespace drak {

class ResourceSystem final {
public:
	void startup();
	void shutdown();

	MeshPtr		loadMesh(const std::string& filename);
	TexturePtr	loadTexture(const std::string& filename);
	
private:
	MeshManager*	m_pMeshManager;
	TextureManager*	m_pTextureManager;
};

} // namespace drak