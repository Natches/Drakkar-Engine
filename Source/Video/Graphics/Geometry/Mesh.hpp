#pragma once

#include <vector>

#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace video {
namespace geom {

class Mesh {
public:
	Mesh();
	virtual ~Mesh();

	void addVertex(const Vertex& v);
	void addIndex(U16 i);
	void addTriangle(
		const Vertex& v1, U16 i1,
		const Vertex& v2, U16 i2,
		const Vertex& v3, U16 i3);

	DK_GETTER_REF_C(std::vector<Vertex>, vertices, m_vertices)
	DK_GETTER_REF_C(std::vector<U16>, indices, m_indices)

protected:
	std::vector<Vertex> m_vertices;
	std::vector<U16>	m_indices;
};

} // namespace gl
} // namespace video
} // namespace drak