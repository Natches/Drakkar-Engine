#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/ResourceSystem.hpp>

namespace drak {

ResourceSystem::ResourceSystem(ResourceSystemData& data) : m_systemData(data) {

}

void ResourceSystem::convert(const std::string& filename, definition::Pak& pak) {
	std::string ext = io::Extension(filename.c_str());
	if (ext != std::string("dkrsrc") && ext != std::string("pak")) {
		const char* temp = filename.data();
		m_converter.convert(1, &temp);
	}
	else if (ext == std::string("pak"))
		pak = m_converter.fromPackage(filename.data());
}

void ResourceSystem::convertOrLoad(const std::string& filename) {
	convertLoad(filename, nullptr);
}

void ResourceSystem::reload(const std::string filename, void* task) {
	using namespace serialization;

	std::vector<definition::Model> models;
	std::vector<definition::Texture> textures;
	std::vector<definition::Material> materials;
	std::vector<definition::Mesh> meshes;
	std::vector<definition::SkinnedMesh> skMeshes;
	definition::ResourceName rName;

	if (Serializer::LoadFromFile<EExtension::BINARY, false, definition::ResourceName>(filename.c_str(),
		rName, models, meshes, skMeshes, materials, textures) == DK_OK) {

		if (textures.size())
			m_textureManager.reload(textures);
		if (meshes.size())
			m_meshManager.reload(meshes);
		if (skMeshes.size())
			m_skinnedMeshManager.reload(skMeshes);
		if (materials.size())
			m_materialManager.reload(materials);
		if (models.size())
			m_modelManager.reload(models);
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
	if (std::find(m_systemData.fileLoaded.begin(), m_systemData.fileLoaded.end(), filename) ==
		m_systemData.fileLoaded.end()) {
		std::vector<definition::Model> models;
		std::vector<definition::Texture> textures;
		std::vector<definition::Material> materials;
		std::vector<definition::Mesh> meshes;
		std::vector<definition::SkinnedMesh> skMeshes;
		definition::ResourceName rName;

		if (Serializer::LoadFromFile<EExtension::BINARY, false, definition::ResourceName>(filename.c_str(),
			rName, models, meshes, skMeshes, materials, textures) == DK_OK) {

			if (textures.size()) {
				m_textureManager.preload(rName, filename);
				m_textureManager.load(filename, textures);
			}
			if (meshes.size()) {
				m_meshManager.preload(rName, filename);
				m_meshManager.load(filename, meshes);
			}
			if (skMeshes.size()) {
				m_skinnedMeshManager.preload(rName, filename);
				m_skinnedMeshManager.load(filename, skMeshes);
			}
			if (materials.size()) {
				m_materialManager.preload(rName, filename);
				m_materialManager.load(filename, materials);
			}
			if (models.size()) {
				m_modelManager.preload(rName, filename);
				m_modelManager.load(filename, models);
			}

			m_mutex.lock();
			if (std::find(m_systemData.fileLoaded.begin(), m_systemData.fileLoaded.end(), filename) ==
				m_systemData.fileLoaded.end())
				m_systemData.fileLoaded.emplace_back(filename);
			m_mutex.unlock();
		}
		else
			std::cout << "Error while loading from :" << filename << std::endl;
	}
}

void ResourceSystem::convertLoad(const std::string filename, void* task) {
	definition::Pak pak;
	convert(filename, pak);
	if (!pak.filenames.size()) {
		std::string ext = io::AllExtension(filename.c_str());
		if (ext != "dkrsrc" && ext != "pak") {
			load(io::Directories(filename.c_str()) +
				io::FileNameNoExtension(filename.c_str()) + ".dkrsrc");
		}
		else
			load(filename);
	}
	else {
		m_mutex.lock();
		if (std::find(m_systemData.packageLoaded.begin(), m_systemData.packageLoaded.end(), filename) ==
			m_systemData.packageLoaded.end())
			m_systemData.packageLoaded.emplace_back(filename);
		m_mutex.unlock();
		for (auto file : pak.filenames) {
			load(file);
		}
	}
	if (task) {
		m_mutex.lock();
		m_loadingAssets.erase(std::find(m_loadingAssets.begin(), m_loadingAssets.end(),
			(thread::task::Task<func>*)task));
		delete (thread::task::Task<func>*)task;
		m_mutex.unlock();
	}
}

bool ResourceSystem::startup() {
	m_pool.startup();
	m_converter.startup(&m_pool);
	updateFromData();
	return true;
}

void ResourceSystem::updateFromData() {
	if (m_systemData.packageLoaded.size()) {
		std::vector<std::string> temp = m_systemData.packageLoaded;
		for (auto& pakName : temp) {
			/*char* buffer = new char[sizeof(thread::task::Task<func>)];
			new (buffer) thread::task::Task<func>
				(func(this, &ResourceSystem::convertLoad, (const std::string)pakName, (void*)buffer));
			m_mutex.lock();
			m_loadingAssets.emplace_back((thread::task::Task<func>*)buffer);
			m_pool.addTask(m_loadingAssets[m_loadingAssets.size() - 1]);
			m_mutex.unlock();*/
			m_systemData.packageLoaded.erase(std::find(m_systemData.packageLoaded.begin(),
				m_systemData.packageLoaded.end(), pakName));
			convertOrLoad(pakName);
		}
	}
	if (m_systemData.fileLoaded.size()) {
		std::vector<std::string> temp = m_systemData.fileLoaded;
		for (auto& file : temp) {
			/*char* buffer = new char[sizeof(thread::task::Task<func>)];
			new (buffer) thread::task::Task<func>
				(func(this, &ResourceSystem::convertLoad, (const std::string)file, (void*)buffer));
			m_mutex.lock();
			m_loadingAssets.emplace_back((thread::task::Task<func>*)buffer);
			m_pool.addTask(m_loadingAssets[m_loadingAssets.size() - 1]);
			m_mutex.unlock();*/
			m_systemData.fileLoaded.erase(std::find(m_systemData.fileLoaded.begin(),
				m_systemData.fileLoaded.end(), file));
			convertOrLoad(file);
		}
	}
}

bool ResourceSystem::shutdown() {
	m_converter.shutdown();
	m_pool.waitForAllTasks();
	m_pool.shutdown();
	return true;
}

} // namespace drak