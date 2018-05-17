#include <PrecompiledHeader/pch.hpp>
#include <Converter/ResourceConverter.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <zlib.h>

namespace drak {
namespace converter {

void ResourceConverter::startup() {
	m_pool.startup();
	m_modelImporterPool = new core::Pool<tools::importer::ModelImporter>((U32)m_pool.m_pool.size());
}

void ResourceConverter::shutdown() {
	m_pool.waitForAllTasks();
	m_pool.shutdown();
}

void ResourceConverter::convert(int count, char** filename) {
	using namespace drak::thread::task;

	TaskGroup<ATask*> grp(m_pool);
	for (int i = 0; i < count; ++i) {
		if (definition::IsMesh(filename[i])) {
			char choice;
			std::cout << "Do you want to Optimize the Mesh ( " << filename[i] << " ) ? (y/n)\n";
			std::cin >> choice;
			using func = function::MemberFunction<ResourceConverter, void, const char*, bool>;
			func f(this, &ResourceConverter::convertModel, (const char*)filename[i], choice == 'y');
			Task<func>* task = new Task<func>(f);
			grp.registerTask(std::move(task));
		}
		else if (definition::IsTexture(filename[i])) {
			using func = function::MemberFunction<ResourceConverter, void, const char*>;

			func f(this, &ResourceConverter::convertTexture, (const char*)filename[i]);
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

void ResourceConverter::toPackage(int count, char** filename, const char* finalName) {
	using namespace definition;
	using namespace serialization;

	Pak p;
	std::string str;
	for (int i = 0; i < count; ++i) {
		z_stream strm;
		p.filenames.emplace_back(filename[i]);
		strm.zalloc = Z_NULL;
		strm.zfree = Z_NULL;
		strm.opaque = Z_NULL;
		if (deflateInit(&strm, 9) != Z_OK) {
			std::cout << "Resource Converter : Failed to Init Deflate\n";
			continue;
		}
		std::ifstream file(filename[i], std::ios::in | std::ios::binary);
		std::stringstream sstr(std::ios::in | std::ios::out | std::ios::binary);
		sstr << file.rdbuf();
		file.close();
		strm.avail_in = strm.avail_out = (U32)sstr.str().size();
		U8* temp1 = new U8[(U32)sstr.str().size()];
		memcpy(temp1, sstr.str().data(), strm.avail_in);
		strm.next_in = temp1;
		U8* temp2 = new U8[(U32)sstr.str().size()];
		strm.next_out = temp2;
		if (deflate(&strm, Z_FINISH) == Z_STREAM_ERROR) {
			std::cout << "Resource Converter : Failed to Deflate :" << filename[i] << "\n";
			deflateEnd(&strm);
			continue;
		}
		str = std::string((const char*)temp2, sstr.str().size() - strm.avail_out);
		p.files.emplace_back(str);
		deflateEnd(&strm);
	}
	Serializer::SerializeToFile<EExtension::BINARY, Pak, false>(p, "Resources/Packaged/",
		(std::string(finalName) + ".pak").c_str());
}

void ResourceConverter::convertModel(const char* filename, bool optimizeMesh) {
	using namespace definition;
	using namespace serialization;

	m_mutex.lock();
	tools::importer::ModelImporter importer(m_modelImporterPool.load()->borrow());
	m_mutex.unlock();
	if (importer.startImport(filename, optimizeMesh)) {
		std::vector<Texture> textures;
		std::vector<Material> materials;
		std::vector<Model> models;
		std::vector<Mesh> meshes;

		importer.importModel(models, meshes, materials, textures);
		std::string path = drak::io::FileNameNoExtension(importer.filename().c_str());
		path.insert(path.end() - path.begin(), ".dkResources");
		Serializer::SerializeToFile<EExtension::BINARY, Model, false>
			(models, "Resources/Models/", path.c_str());

		path.insert(0, "Resources/Models/");
		Serializer::AddObjectToFile<EExtension::BINARY, Mesh, false>(meshes, path.c_str());
		Serializer::AddObjectToFile<EExtension::BINARY, Material, false>(materials, path.c_str());
		Serializer::AddObjectToFile<EExtension::BINARY, Texture, false>(textures, path.c_str());
	}
	m_mutex.lock();
	m_modelImporterPool.load()->getBack(std::move(importer));
	m_mutex.unlock();
}

void ResourceConverter::convertTexture(const char* filename) {
	using namespace definition;
	using namespace serialization;

	Texture tex;
	tools::importer::loadTextureFromFile(filename, tex);
	std::string path = drak::io::FileNameNoExtension(filename);
	path.insert(path.end() - path.begin(), ".dkResources");
	Serializer::SerializeToFile<EExtension::BINARY, Texture, false>(tex, "Resources/Textures/", path.c_str());
}

} // namespace converter
} // namespace drak