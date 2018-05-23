#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/ModelManager.hpp>
#include <ResourceManager/Manager/MeshManager.hpp>
#include <ResourceManager/Manager/MaterialManager.hpp>
#include <ResourceManager/Manager/TextureManager.hpp>
#include <ResourceManager/Manager/ShaderManager.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>
#include <Converter/ResourceConverter.hpp>
#include <Threading/Task/Task.hpp>

namespace drak {
namespace core {
class Engine;
} //namespace core

namespace gfx {
class IShader;
} //namespace gfx

class ResourceSystem final {
	friend core::Engine;

	DK_NONMOVABLE_NONCOPYABLE(ResourceSystem)

public:
	template<typename T>
	ResourcePtr<T> loadOrGet(const std::string& name, const std::string& filename);

	ResourcePtr<gfx::IShader*> loadOrGetShader(const std::string& name, const std::string& vertShader,
		const std::string& fragShader);

	template<typename T>
	void unload(const std::string& name);

	template<typename T>
	void reload(const std::string& name);

private:
	using func = function::MemberFunction<ResourceSystem, void, const std::string,void*>;
	template<typename T, typename U>
	ResourcePtr<T> loadOrGet(U& manager, const std::string& name, const std::string& filename);
	template<typename U>
	void reload(U& manager, const std::string& filename);
	void reload(const std::string& filename, void* task);
	void load(const std::string& filename);
	void convert(const std::string& filename, definition::Pak& pak);
	void convertLoad(const std::string filename, void* task);

	ResourceSystem() = default;

	bool startup();
	bool shutdown();

	ModelManager		m_modelManager;
	TextureManager		m_textureManager;
	MeshManager			m_meshManager;
	MaterialManager		m_materialManager;
	ShaderManager		m_shaderManager;

	converter::ResourceConverter m_converter;
	std::vector<thread::task::Task<func>*> m_loadingAssets;
	std::mutex m_mutex;
};

} // namespace drak

#include <ResourceManager/ResourceSystem.inl>