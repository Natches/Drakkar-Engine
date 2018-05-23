#include <ResourceManager/ResourceSystem.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <Serialization/MetaData.hpp>
#include <Converter/ResourceDefinitions.hpp>

namespace drak {

template<typename T>
ResourcePtr<T> ResourceSystem::loadOrGet(const std::string& name, const std::string& filename) {
	static_assert(std::is_same_v<T, gfx::Mesh> || std::is_same_v<T, gfx::Material> ||
		std::is_same_v<T, gfx::Model> || std::is_same_v<T, gfx::Texture>);
	if constexpr (std::is_same_v<T, gfx::Mesh>)
		loadOrGet<T, T::Manager>(m_meshManager, name, filename);
	else if constexpr (std::is_same_v<T, gfx::Material>)
		loadOrGet<T, T::Manager>(m_materialManager, name, filename);
	else if constexpr (std::is_same_v<T, gfx::Model>)
		loadOrGet<T, T::Manager>(m_modelManager, name, filename);
	else if constexpr (std::is_same_v<T, gfx::Texture>)
		loadOrGet<T, T::Manager>(m_textureManager, name, filename);
}

template<typename T>
void ResourceSystem::unload(const std::string& name) {
	static_assert(std::is_same_v<T, gfx::Mesh> || std::is_same_v<T, gfx::Material> ||
		std::is_same_v<T, gfx::Model> || std::is_same_v<T, gfx::Texture>);
	if constexpr (std::is_same_v<T, gfx::Mesh>)
		m_meshManager.unload(name);
	else if constexpr (std::is_same_v<T, gfx::Material>) 
		m_materialManager.unload(name);
	else if constexpr (std::is_same_v<T, gfx::Model>) 
		m_modelManager.unload(name);
	else if constexpr (std::is_same_v<T, gfx::Texture>) 
		m_textureManager.unload(name);
}

template<typename T>
void ResourceSystem::reload(const std::string& name) {
	static_assert(std::is_same_v<T, gfx::Mesh> || std::is_same_v<T, gfx::Material> ||
		std::is_same_v<T, gfx::Model> || std::is_same_v<T, gfx::Texture>);
	if constexpr (std::is_same_v<T, gfx::Mesh>)
		reload<T::Manager>(m_meshManager, m_meshManager[name].filename());
	else if constexpr (std::is_same_v<T, gfx::Material>) 
		reload<T::Manager>(m_materialManager, m_materialManager[name].filename());
	else if constexpr (std::is_same_v<T, gfx::Model>) 
		reload<T::Manager>(m_modelManager, m_modelManager[name].filename());
	else if constexpr (std::is_same_v<T, gfx::Texture>) 
		reload<T::Manager>(m_textureManager, m_textureManager[name].filename());
}

template<typename T, typename U>
ResourcePtr<T> ResourceSystem::loadOrGet(U& manager, const std::string& name, const std::string& filename) {
	if (manager.contain(name))
		return manager[name];
	else {
		manager.preload(name);
		char* buffer = new char[sizeof(thread::task::Task<func>)];
		new (buffer) thread::task::Task<func>
			(func(this, &ResourceSystem::convertLoad, filename, buffer));
		m_mutex.lock();
		m_loadingAssets.emplace_back((thread::task::Task<func>*)buffer);
		m_mutex.unlock();
		Engine::Get().m_pool.addTask(m_loadingAssets[m_loadingAssets.size() - 1]);
		return manager[name];
	}
}

template<typename U>
void ResourceSystem::reload(U& manager, const std::string& filename) {
	char* buffer = new char[sizeof(thread::task::Task<func>)];
	new (buffer) thread::task::Task<func>
		(func(this, &ResourceSystem::convertLoad, filename, buffer));
	m_mutex.lock();
	m_loadingAssets.emplace_back((thread::task::Task<func>*)buffer);
	m_mutex.unlock();
	Engine::Get().m_pool.addTask(m_loadingAssets[m_loadingAssets.size() - 1]);
}

} // namespace drak