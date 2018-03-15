#include <cassert>
#include <ResourceManager/MeshManager.hpp>

namespace drak {
namespace io {
void* MeshManager::getMesh(const std::string& str) {
	assert(false);
	return nullptr;
}
void MeshManager::loadMesh(const std::string& str) {
	assert(false);
}

MeshManager MeshManager::Create() {
	return MeshManager();
}

} // namespace io
} // namespace drak