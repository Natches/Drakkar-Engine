#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {
namespace geom {

Mesh::Mesh(const std::string& filename = "")
:	m_filename(filename) {

}

Mesh::~Mesh() {

}

void Mesh::addVertex(const Vertex1P1N1UV& v) {
	m_vertices.push_back(v);
}

void Mesh::addTriangleVertices(
	const Vertex1P1N1UV& v1,
	const Vertex1P1N1UV& v2,
	const Vertex1P1N1UV& v3) {
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
}

void Mesh::addIndex(U32 i) {
	m_indices.push_back(i);
}

void Mesh::addTriangleIndices(U32 i1, U32 i2, U32 i3) {
	addIndex(i1);
	addIndex(i2);
	addIndex(i3);
}

} // namespace geom
} // namespace drak