#pragma once

#include <vector>
#include <Converter/ModelImporter.hpp>
#include <Threading/Thread/Threadpool.hpp>
#include <Core/Pool/Pool.hpp>

namespace drak {

namespace tools {
class ModelImporter;
} //namespace tools

namespace converter {

class ResourceConverter {

public:
	void startup();
	void shutdown();

	void convert(int count, char**filename);
	void toPackage(int count, char**filename, const char* finalName);

	void convertModel(const char* filename, bool optimizeMesh);

private:
	void convertModel(const char* filename, bool optimizeMesh);
	void convertTexture(const char* filename);

private:
	std::atomic<core::Pool<tools::importer::ModelImporter>*> m_modelImporterPool;
	thread::ThreadPool m_pool;
	std::mutex m_mutex;
};

} // namespace converter
} // namespace drak