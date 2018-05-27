#pragma once

#include <string>
#include <vector>
#include <Animation/Geometry/SkinnedVertex.hpp>
#include <Animation/Skeleton/Skeleton.hpp>

namespace drak {
template<typename T>
class Resource;
class SkinnedMeshManager;
namespace geom {

class SkinnedMesh {
	friend class Resource<geom::SkinnedMesh>;

public:
	SkinnedMesh(const std::string& name, std::vector<Vertex1P1N1UV1B1W>&& vertices,
		std::vector<U32>&& indices, animation::Skeleton&& skeleton);
	~SkinnedMesh() = default;

	using Manager = SkinnedMeshManager;

	DK_GETTER_REF_C(std::string, name, m_name)
	DK_GETTER_REF_C(std::vector<Vertex1P1N1UV1B1W>, vertices, m_vertices)
	DK_GETTER_REF_C(std::vector<U32>, indices, m_indices)
	DK_GETTER_REF_C(animation::Skeleton, skeleton, m_skeleton)

private:
	SkinnedMesh() = default;

private:
	std::string						m_name;
	std::vector<Vertex1P1N1UV1B1W>	m_vertices;
	std::vector<U32>				m_indices;
	animation::Skeleton				m_skeleton;
};

} // namespace geom
} // namespace drak