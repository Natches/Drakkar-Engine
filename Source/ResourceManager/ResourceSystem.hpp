#pragma once

#include <vector>
#include <Core/Utils/ClassUtils.hpp>
#include <ResourceManager/Manager/ModelManager.hpp>
#include <ResourceManager/Manager/MeshManager.hpp>
#include <ResourceManager/Manager/MaterialManager.hpp>
#include <ResourceManager/Manager/TextureManager.hpp>
#include <ResourceManager/Manager/ShaderManager.hpp>
#include <ResourceManager/Resource/ResourceDefinitions.hpp>
#include <Converter/ResourceConverter.hpp>
#include <Threading/Thread/ThreadPool.hpp>
#include <Threading/Task/Task.hpp>
#include <Threading/Function/Function.hpp>

namespace drak {
namespace gfx {
class IShader;
} //namespace gfx

struct ResourceSystemData {
	std::vector<std::string> fileLoaded;
	std::vector<std::string> packageLoaded;
};

class ResourceSystem final {
	friend class LevelSystem;

	DK_SERIALIZED_OBJECT(ResourceSystem)
	DK_NONMOVABLE_NONCOPYABLE(ResourceSystem)

	using func = typename function::MemberFunction<ResourceSystem, void, const std::string, void*>;
public:
	template<typename T>
	ResourcePtr<T> loadOrGet(const std::string& name, const std::string& filename = "");

	void convertOrLoad(const std::string& filename);

	template<typename T>
	void unload(const std::string& name);

	template<typename T>
	void reload(const std::string& name);

private:
	template<typename T, typename U>
	ResourcePtr<T> loadOrGet(U& manager, const std::string& name, const std::string& filename);
	template<typename U>
	void reload(U& manager, const std::string& filename);
	void reload(const std::string filename, void* task);
	void load(const std::string& filename);
	void convert(const std::string& filename, definition::Pak& pak);
	void convertLoad(const std::string filename, void* task);

	ResourceSystem(ResourceSystemData& data);

	bool startup();
	void updateFromData();
	bool shutdown();

	ModelManager		m_modelManager;
	TextureManager		m_textureManager;
	MeshManager			m_meshManager;
	MaterialManager		m_materialManager;

	converter::ResourceConverter m_converter;
	std::vector<thread::task::Task<func>*> m_loadingAssets;
	std::mutex m_mutex;

	ResourceSystemData& m_systemData;

	thread::ThreadPool m_pool;
};

} // namespace drak

#include <ResourceManager/ResourceSystem.inl>

DK_METADATA_BEGIN(drak::ResourceSystemData)
DK_PRIVATE_FIELDS(fileLoaded, packageLoaded)
DK_PRIVATE_FIELD_COMPLEMENT
DK_METADATA_END