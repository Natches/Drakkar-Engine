#include <PrecompiledHeader/pch.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {
namespace geom {

Mesh::Mesh(const std::string& name, std::vector<Vertex1P1N1UV>&& vertices,
	std::vector<U32>&& indices)
:	m_name(name), m_vertices(std::move(vertices)), m_indices(std::move(indices)) {

}

} // namespace geom
} // namespace drak