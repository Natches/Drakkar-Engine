#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {
namespace geom {

Mesh::Mesh(const std::string& filename = "")
:	m_filename(filename) {

}

Mesh::~Mesh() {

}

void Mesh::addVertex(const Vertex& v) {
	m_vertices.push_back(v);
}

void Mesh::addIndex(U16 i) {
	m_indices.push_back(i);
}

void Mesh::addTriangleVertices(const Vertex& v1, const Vertex& v2, const Vertex& v3) {
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
}

void Mesh::addTriangleIndices(U16 i1, U16 i2, U16 i3) {
	addIndex(i1);
	addIndex(i2);
	addIndex(i3);
}

} // namespace geom
} // namespace drak