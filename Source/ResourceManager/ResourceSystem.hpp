#pragma once

#include <ResourceManager/ModelManager.hpp>
#include <ResourceManager/MeshManager.hpp>
#include <ResourceManager/TextureManager.hpp>

namespace drak {

class ResourceSystem final {
public:
	void startup();
	void shutdown();

	MeshPtr	loadMesh(const std::string& filename);
	
private:
	ModelManager*	m_pModelManager;
	MeshManager*	m_pMeshManager;
	TextureManager*	m_pTextureManager;
};

} // namespace drak