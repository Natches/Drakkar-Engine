#include <Video/Graphics/Geometry/Mesh.hpp>
#include <Video/Graphics/Tools/ModelImporter.hpp>

using namespace drak::gfx::tools;

namespace drak {
namespace geom {

Mesh::Mesh(const std::string& filename = "")
:	m_filename(filename) {

}

Mesh::~Mesh() {

}

bool Mesh::load() {
	ModelImporter mdlImp;
	return mdlImp.importFromFile(m_filename);
}

void Mesh::addVertex(const Vertex& v) {
	m_vertices.push_back(v);
}

void Mesh::addIndex(U16 i) {
	m_indices.push_back(i);
}

void Mesh::addTriangle(
	const Vertex& v1, U16 i1,
	const Vertex& v2, U16 i2,
	const Vertex& v3, U16 i3) {
	m_vertices.push_back(v1); m_indices.push_back(i1);
	m_vertices.push_back(v2); m_indices.push_back(i2);
	m_vertices.push_back(v3); m_indices.push_back(i3);
}

} // namespace geom
} // namespace drak