#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/ModelManager.hpp>
#include <ResourceManager/MeshManager.hpp>
#include <ResourceManager/TextureManager.hpp>
#include <ResourceManager/ResourceDefinitions.hpp>
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

	//TextureManager	m_textureManager;
	//ShaderManager		m_shaderManager;

	ModelManager		m_pModelManager;

	converter::ResourceConverter m_converter;
};

} // namespace drak

#include <ResourceManager/ResourceSystem.inl>