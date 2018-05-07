#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace geom {

template<typename vertexType>
Mesh<vertexType>::Mesh(const std::string& filename = "")
	: AMesh(static_cast<int>((static_cast<float>(sizeof(vertexType)) / sizeof(Vec3f)) + 0.5f)),
	m_filename(filename) {

}

template<typename vertexType>
Mesh<vertexType>::~Mesh() {

}

template<typename vertexType>
void Mesh<vertexType>::addVertex(const vertexType& v) {
	m_vertices.emplace_back(v);
}

template<typename vertexType>
void Mesh<vertexType>::addTriangle(const vertexType& v1, const vertexType& v2, const vertexType& v3) {
	addVertex(v1);
	addVertex(v2);
	addVertex(v3);
}

template<typename vertexType>
void Mesh<vertexType>::addIndex(U32 i) {
	m_indices.push_back(i);
}

template<typename vertexType>
void Mesh<vertexType>::addTriangleIndices(U32 i1, U32 i2, U32 i3) {
	addIndex(i1);
	addIndex(i2);
	addIndex(i3);
}

} // namespace geom
} // namespace drak