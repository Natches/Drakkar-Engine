#include <PrecompiledHeader/pch.hpp>
#include <Animation/Geometry/SkinnedMesh.hpp>

namespace drak {
namespace geom {

SkinnedMesh::SkinnedMesh(const std::string& name, std::vector<Vertex1P1N1UV1B1W>&& vertices,
	std::vector<U32>&& indices, animation::Skeleton&& skeleton) : m_name(name),
	m_vertices(std::move(vertices)), m_indices(std::move(indices)), m_skeleton(std::move(skeleton))
{
}

} // namespace geom
} // namespace drak