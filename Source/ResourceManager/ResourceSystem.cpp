#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

ResourcePtr<gfx::IShader*> ResourceSystem::loadOrGetShader(const std::string& name,
	const std::string& vertFile, const std::string& fragFile) {
	if (m_shaderManager.contain(name))
		return m_shaderManager.m_map[name];
	else {
		m_shaderManager.preload(name);
		m_shaderManager.load(name, vertFile, fragFile);
		return m_shaderManager.m_map[name];
	}
}

void ResourceSystem::convert(const std::string& filename, definition::Pak& pak) {
	std::string ext = io::Extension(filename.c_str());
	if (ext != std::string("dkResource") && ext != std::string("pak")) {
		const char* temp = filename.data();
		m_converter.convert(1, &temp);
	}
	else if (ext == std::string("pak"))
		pak = m_converter.fromPackage(filename.data());
}

void ResourceSystem::reload(const std::string& filename, void* task) {
	using namespace serialization;

	std::vector<definition::Model> models;
	std::vector<definition::Texture> textures;
	std::vector<definition::Material> materials;
	std::vector<definition::Mesh> meshes;
	definition::ResourceName rName;

	if (Serializer::LoadFromFile<EExtension::BINARY, false, definition::ResourceName>(filename.c_str(),
		rName, models, textures, materials, meshes) == DK_OK) {

		if (models.size())
			m_modelManager.reload(models);
		if (textures.size())
			m_textureManager.reload(textures);
		if (materials.size())
			m_materialManager.reload(materials);
		if (meshes.size())
			m_meshManager.reload(meshes);
	}
	else
		std::cout << "Error while reloading from :" << filename << std::endl;
	m_mutex.lock();
	m_loadingAssets.erase(std::find(m_loadingAssets.begin(), m_loadingAssets.end(),
		(thread::task::Task<func>*)task));
	delete (thread::task::Task<func>*)task;
	m_mutex.unlock();
}

void ResourceSystem::load(const std::string& filename) {
	using namespace serialization;

	std::vector<definition::Model> models;
	std::vector<definition::Texture> textures;
	std::vector<definition::Material> materials;
	std::vector<definition::Mesh> meshes;
	definition::ResourceName rName;

	if (Serializer::LoadFromFile<EExtension::BINARY, false, definition::ResourceName>(filename.c_str(),
		rName, models, textures, materials, meshes) == DK_OK) {

		if (models.size()) {
			m_modelManager.preload(rName);
			m_modelManager.load(filename, models);
		}
		if (textures.size()) {
			m_textureManager.preload(rName);
			m_textureManager.load(filename, textures);
		}
		if (materials.size()) {
			m_materialManager.preload(rName);
			m_materialManager.load(filename, materials);
		}
		if (meshes.size()) {
			m_meshManager.preload(rName);
			m_meshManager.load(filename, meshes);
		}
	}
	else
		std::cout << "Error while loading from :" << filename << std::endl;
}

void ResourceSystem::convertLoad(const std::string filename, void* task) {
	definition::Pak pak;
	convert(filename, pak);
	if (!pak.filenames.size())
		load(filename);
	else {
		for (auto file : pak.filenames) {
			load(file);
		}
	}
	m_mutex.lock();
	m_loadingAssets.erase(std::find(m_loadingAssets.begin(), m_loadingAssets.end(),
		(thread::task::Task<func>*)task));
	delete (thread::task::Task<func>*)task;
	m_mutex.unlock();
}

bool ResourceSystem::startup() {
	m_converter.startup();
	return true;
}

bool ResourceSystem::shutdown() {
	m_converter.shutdown();
	return true;
}

} // namespace drak