#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/MeshManager.hpp>
#include <Converter/ResourceDefinitions.hpp>

using namespace drak::core;
using namespace drak::definition;

namespace drak {

void MeshManager::preload(const std::string& names, const std::string& filename) {
	Base::preload(names, filename);
}

void MeshManager::preload(const ResourceName& rName, const std::string& filename) {
	for (auto name : rName.names) {
		if ((name.second & EFileType::MESH) == EFileType::MESH)
			m_map[name.first] = MeshPtr(new Resource<geom::Mesh>(filename));
	}
}

void MeshManager::load(const std::string& filename, std::vector<definition::Mesh>& inMeshes) {
	for (auto& mesh : inMeshes) {
		if (!m_map[mesh.name].get())
			m_map[mesh.name].reset(new Resource<geom::Mesh>(filename));
		new (m_map[mesh.name].get())
			Resource<geom::Mesh>(filename, geom::Mesh(mesh.name,
			std::move(*reinterpret_cast<std::vector<geom::Vertex1P1N1UV>*>(&mesh.vertices)),
			std::move(mesh.indices)));

		m_map[mesh.name]->loadState(Resource<geom::Mesh>::ELoadState::READY);
	}
}

void MeshManager::reload(std::vector<definition::Mesh>& inMeshes) {
	for (auto& mesh : inMeshes) {
		m_map[mesh.name]->loadState(Resource<geom::Mesh>::ELoadState::LOADING);
		new (&m_map[mesh.name]->m_resource)
			geom::Mesh(mesh.name,
				std::move(*reinterpret_cast<std::vector<geom::Vertex1P1N1UV>*>(&mesh.vertices)),
				std::move(mesh.indices));
		m_map[mesh.name]->loadState(Resource<geom::Mesh>::ELoadState::READY);
	}
}

} // namespace drak