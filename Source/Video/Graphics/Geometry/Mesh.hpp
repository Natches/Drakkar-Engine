#pragma once

#include <vector>

#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace geom {

class Mesh {
public:
	Mesh(const std::string& filename = "");
	virtual ~Mesh();

	void addVertex(const Vertex1P& v);
	void addTriangle(
		const Vertex1P& v1,
		const Vertex1P& v2,
		const Vertex1P& v3);

	void addVertex(const Vertex1P1N& v);
	void addTriangle(
		const Vertex1P1N& v1,
		const Vertex1P1N& v2,
		const Vertex1P1N& v3);

	void addVertex(const Vertex1P1N1UV& v);
	void addTriangle(
		const Vertex1P1N1UV& v1,
		const Vertex1P1N1UV& v2,
		const Vertex1P1N1UV& v3);

	void addTriangleIndices(U32 i1, U32 i2, U32 i3);

	//DK_GETTER_REF_C(std::vector<Vertex>, vertices, m_vertices)
	DK_GETTER_REF_C(std::vector<U32>, indices, m_indices)

protected:
	// std::vector<Vertex>		m_vertices;
	std::vector<math::Vec3f>	m_positions;
	std::vector<math::Vec3f>	m_normals;
	std::vector<math::Vec2f>	m_texCoords;
	std::vector<U32>			m_indices;

	std::string					m_filename;
};

} // namespace geom
} // namespace drak