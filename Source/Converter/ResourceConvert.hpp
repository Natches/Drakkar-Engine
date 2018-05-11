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
	void toPackage(int count, char**filename);

private:
	void compress();
	void convertModel(tools::ModelImporter& importer);
	void convertTexture(const std::string& filename);

private:
	core::Pool<tools::ModelImporter> m_modelImporterPool;
	thread::ThreadPool m_pool;
};

} // namespace converter
} // namespace drak