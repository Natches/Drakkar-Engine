#include <PrecompiledHeader/pch.hpp>
#include <Converter/ResourceConverter.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <zlib.h>

namespace drak {
namespace converter {

void ResourceConverter::startup(thread::ThreadPool* pool) {
	if (pool) {
		m_pool = pool;
		m_allocated = false;
	}
	else {
		m_pool = new thread::ThreadPool();
		m_pool->startup();
		m_allocated = true;
	}
	m_modelImporterPool = new core::Pool<tools::importer::ModelImporter>((U32)m_pool->m_pool.size());
}

void ResourceConverter::shutdown() {
	if (m_allocated) {
		m_pool->waitForAllTasks();
		m_pool->shutdown();
		delete m_pool;
		m_pool = nullptr;
	}
}

void ResourceConverter::convert(int count, const char** filename) {
	using namespace drak::thread::task;

	TaskGroup<ATask*> grp(*m_pool);
	for (int i = 0; i < count; ++i) {
		if (definition::IsMesh(filename[i])) {
			using func = function::MemberFunction<ResourceConverter, void, const char*, bool>;
			func f(this, &ResourceConverter::convertModel, std::move(filename[i]), true);
			Task<func>* task = new Task<func>(f);
			grp.registerTask(std::move(task));
		}
		else if (definition::IsTexture(filename[i])) {
			using func = function::MemberFunction<ResourceConverter, void, const char*>;

			func f(this, &ResourceConverter::convertTexture, std::move(filename[i]));
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

void ResourceConverter::toPackage(int count, const char** filename, const char* finalName) {
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
		delete[] temp1;
		delete[] temp2;
	}
	Serializer::SerializeToFile<EExtension::BINARY, Pak, false>(p, "Resources/Packaged/",
		(std::string(finalName) + ".pak").c_str());
}

definition::Pak ResourceConverter::fromPackage(const char* filename) {
	using namespace definition;
	using namespace serialization;

	Pak pak;
	Serializer::LoadFromFile<EExtension::BINARY, Pak, false>(pak, filename);
	for (I32 i = 0, size = (I32)pak.filenames.size(); i < size; ++i) {
		std::ofstream file(pak.filenames[i]);
		z_stream strm;
		strm.zalloc = Z_NULL;
		strm.zfree = Z_NULL;
		strm.opaque = Z_NULL;
		strm.avail_in = 0;
		strm.next_in = Z_NULL;
		if (inflateInit(&strm) != Z_OK) {
			std::cout << "Resource Converter : Failed to Init Deflate\n";
			continue;
		}
		strm.avail_in = (U32)pak.files[i].size();
		strm.next_in = (U8*)pak.files[i].c_str();
		U8* out = new U8[strm.avail_in];
		do {
			strm.avail_out = strm.avail_in;
			strm.next_out = out;
			inflate(&strm, Z_NO_FLUSH);
			file.write((const char*)out, strm.total_out);
		} while (strm.avail_out == 0);
		file.close();
		delete[] out;
	}
	pak.files.clear();
	pak.files.shrink_to_fit();
	return pak;
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
		std::vector<SkeletalMesh> skelMeshes;
		ResourceName rName;

		importer.importModel(models, meshes, skelMeshes, materials, textures, rName);

		std::string path = drak::io::FileNameNoExtension(importer.filename().c_str());
		path.insert(path.end() - path.begin(), ".dkResources");

		Serializer::SerializeToFile<EExtension::BINARY, false, ResourceName>
			("Resources/Models/", path.c_str(), rName, models, meshes, skelMeshes, materials, textures);
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
	ResourceName rName;
	rName.names[path] = EFileType::TEXTURE;
	path.insert(path.end() - path.begin(), ".dkResources");
	Serializer::SerializeToFile<EExtension::BINARY, false, Texture>("Resources/Textures/", path.c_str(), tex, rName);
}

} // namespace converter
} // namespace drak