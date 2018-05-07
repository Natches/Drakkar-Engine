#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/ResourceDefinitions.hpp>

namespace drak {

class MeshManager;
class MaterialManager;

class ModelManager final {
	DK_NONMOVABLE_NONCOPYABLE(ModelManager)
public:


private:
	friend class ResourceSystem;
	ModelManager(MeshManager* pMeshManager, MaterialManager* pMaterialManager);

private:
	ModelMap			m_models;
	MeshManager*		m_pMeshManager;
	MaterialManager*	m_pMaterialManager;
};

} // namespace drak