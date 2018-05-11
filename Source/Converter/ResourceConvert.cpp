#include <PrecompiledHeader/pch.hpp>
#include <Converter/ResourceConvert.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <zlib.h>

namespace drak {
namespace converter {

void ResourceConverter::startup() {
	m_pool.startup();
	m_modelImporterPool = core::Pool<tools::ModelImporter>((U32)m_pool.m_pool.size());
}

void ResourceConverter::shutdown() {
	m_pool.waitForAllTasks();
	m_pool.shutdown();
}

void ResourceConverter::convert(int count, char** filename) {
	using namespace drak::thread::task;
	TaskGroup<ATask*> grp(m_pool);
	for (int i = 1; i < count; ++i) {
		if (IsMesh(filename[i])) {
			using func = function::MemberFunction<ResourceConverter, void, tools::ModelImporter&>;

			tools::ModelImporter& imp = m_modelImporterPool.borrow();
			if (imp.startImport(filename[i])) {
				func f(this, &ResourceConverter::convertModel, imp);
				Task<func>* task = new Task<func>(f);
				grp.registerTask(std::move(task));
			}
		}
		else if (IsTexture(filename[i])) {
			using func = function::MemberFunction<ResourceConverter, void, const std::string&>;

			func f(this, &ResourceConverter::convertTexture, filename[i]);
			Task<func>* task = new Task<func>(f);
			grp.registerTask(std::move(task));
		}
		else
			std::cout << "Extension not recognized from Filename : " << filename[i] << "\n";
	}
	grp.sendGroupToThreadPool();
	grp.waitForTasks();
	grp.clearGroup<true>();
}

void ResourceConverter::toPackage(int count, char** filename) {
}

void ResourceConverter::convertModel(tools::ModelImporter& importer) {
	std::vector<Texture> textures;
	std::vector<Material> materials;
	std::vector<Model<Mesh>> models;

	importer.importModel(models, materials, textures);

	std::string path = importer.filename();
	path.erase(path.begin() + path.find_last_of('.'), path.end());
	size_t pos = 0;
	if( pos = path.find_last_of('/') != path.npos)
		path.erase(path.begin(), path.begin() + pos);
	path.insert(path.end() - path.begin(), ".dkResources");

	serialization::Serializer::SerializeToFile<serialization::EExtension::BINARY, Model<Mesh>>(models, "Resources/Models/", path.c_str());
	path.insert(0, "Resources/Models/");
	serialization::Serializer::AddObjectToFile<serialization::EExtension::BINARY, Material>(materials, path.c_str());
	serialization::Serializer::AddObjectToFile<serialization::EExtension::BINARY, Texture>(textures, path.c_str());
}

void ResourceConverter::convertTexture(const std::string& filename) {
	Texture tex;
	tools::loadTextureFromFile(filename, tex);
	std::string path = filename;
	path.erase(path.begin() + path.find_last_of('.'), path.end());
	size_t pos = 0;
	if (pos = path.find_last_of('/') != path.npos)
		path.erase(path.begin(), path.begin() + pos);
	path.insert(path.end() - path.begin(), ".dkResources");
	serialization::Serializer::SerializeToFile<serialization::EExtension::BINARY, Texture>(tex, "Resources/Textures/", path.c_str());
}

} // namespace converter
} // namespace drak