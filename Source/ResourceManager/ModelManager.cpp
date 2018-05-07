#include <ResourceManager/ModelManager.hpp>

namespace drak {

ModelManager::ModelManager(
	MeshManager* pMeshManager,
	MaterialManager* pMaterialManager) 
:	m_pMeshManager(pMeshManager), 
	m_pMaterialManager(pMaterialManager) {

}

} // namespace drak