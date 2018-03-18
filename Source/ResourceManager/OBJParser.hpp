#pragma once

#include <map>
#include <vector>

#include <Math/Vec3.hpp>
#include <Math/Vec2.hpp>

namespace drak {
namespace io {

struct IndexedVertex {
	U16 pos;
	U16 normal;
	U16 uv;
};

struct IndexComparison {
	bool operator()(const IndexedVertex& left, const IndexedVertex& right) const {
		return memcmp(&left, &right, sizeof(math::Vec3ui)) < 0;
	}
};

using VertexLookupTable = std::map<IndexedVertex, U16, IndexComparison>;

struct MeshData {
	std::vector<math::Vec3f>	positions;
	std::vector<math::Vec3f>	normals;
	std::vector<math::Vec2f>	uvs;
	std::vector<U16>			indices;

	inline void AddPosition(const math::Vec3f& pos) { positions.push_back(pos); }
	inline void AddNormal(const math::Vec3f& normal) { normals.push_back(normal); }
	inline void AddUV(const math::Vec2f& uv) { uvs.push_back(uv); }

	void Clean() {
		positions.clear();
		uvs.clear();
		normals.clear();
		indices.clear();
	}
};

extern const char*	OBJ_PARSE_VEC2F;
extern const char*	OBJ_PARSE_VEC3F;
extern const char*	OBJ_PARSE_TRI;

bool ParseOBJ(
	const std::string& objFilePath, 
	MeshData& meshData, 
	std::string& texturePath);

extern const char*	ERROR_OPEN;
extern const char*	ERROR_PARSE;

} // namespace io
} // namespace drak