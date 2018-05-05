#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/ModelManager.hpp>
#include <ResourceManager/MeshManager.hpp>
#include <ResourceManager/TextureManager.hpp>

namespace drak {

class ResourceSystem final {
	DK_NONMOVABLE_NONCOPYABLE(ResourceSystem)
public:
	void startup();
	void shutdown();

	MeshPtr	loadMesh(const std::string& filename);
	
private:
	MeshManager			m_meshManager;
	//TextureManager		m_textureManager;
	//ShaderManager		m_shaderManager;

	//ModelManager*		m_pModelManager;
	//MaterialManager*	m_pMaterialManager;
};

} // namespace drak