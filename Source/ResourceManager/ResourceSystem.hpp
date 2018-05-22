#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/ModelManager.hpp>
#include <ResourceManager/Manager/MeshManager.hpp>
#include <ResourceManager/Manager/MaterialManager.hpp>
#include <ResourceManager/Manager/TextureManager.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>
#include <Converter/ResourceConverter.hpp>

namespace drak {
namespace core {
class Engine;
} //namespace core

class ResourceSystem final {
	friend core::Engine;

	DK_NONMOVABLE_NONCOPYABLE(ResourceSystem)

public:
	template<typename T>
	core::EError loadOrGet(const std::string& filename, ResourcePtr<T>& out);

	template<typename T>
	core::EError unload(const std::string& filename);

	template<typename T>
	core::EError reload(const std::string& filename, ResourcePtr<T>& out);

	core::EError unloadAll(const std::string& filename);

	core::EError reloadAll(const std::string& filename);

private:
	ResourceSystem() = default;

	core::EError startup();
	core::EError shutdown();

	//ShaderManager	m_shaderManager;

	ModelManager		m_modelManager;
	TextureManager		m_textureManager;
	MeshManager			m_meshManager;
	MaterialManager		m_materialManager;

	converter::ResourceConverter m_converter;
};

} // namespace drak

#include <ResourceManager/ResourceSystem.inl>