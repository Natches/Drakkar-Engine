#pragma once

#include <vector>
#include <Threading/Thread/Threadpool.hpp>

namespace drak {

class ModelImporter;

namespace converter {

class ResourceConverter {

public:
	void Convert(int count, char**filename);

private:


private:
	std::vector<ModelImporter> m_MeshImporterPool;
	thread::ThreadPool m_pool;
};

} // namespace converter
} // namespace drak