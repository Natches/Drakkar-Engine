#pragma once

#include <vector>
#include <Video/Graphics/Geometry/Base/AMesh.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace geom {

template<typename vertexType>
class Mesh : public AMesh {
	static_assert(std::is_same_v<Vertex1P, vertexType> || std::is_same_v<Vertex1P1N, vertexType>,
		std::is_same_v<Vertex1P1N1UV, vertexType>, "Must be a vertexType");
public:
	Mesh(const std::string& filename = "");
	virtual ~Mesh();

	void addVertex(const vertexType& v);
	void addTriangle(
		const vertexType& v1,
		const vertexType& v2,
		const vertexType& v3);

	void addIndex(U32 i);
	void addTriangleIndices(U32 i1, U32 i2, U32 i3);

	DK_GETTER_REF_C(std::vector<vertexType>, vertices, m_vertices)
	DK_GETTER_REF_C(std::vector<U32>, indices, m_indices)

protected:
	std::vector<vertexType>		m_vertices;
	std::vector<U32>			m_indices;

	std::string					m_filename;
	U8							m_numAttribs;
};

} // namespace geom
} // namespace drak