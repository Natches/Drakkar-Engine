#include <ResourceManager/MeshManager.hpp>

using namespace drak::geom;

namespace drak {

MeshPtr MeshManager::preloadMesh(const std::string& filename) {
	auto meshLoc = m_meshes.find(filename);
	if (meshLoc == m_meshes.end())
		m_meshes[filename] = std::make_shared<Mesh<Vertex1P1N1UV>>(filename);
	return m_meshes[filename];
}

MeshPtr MeshManager::loadMesh(const std::string& filename) {
	auto meshLoc = preloadMesh(filename);
	// meshLoc->load();
	return meshLoc;
}

} // namespace drak