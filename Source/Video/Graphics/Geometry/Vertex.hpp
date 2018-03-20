#pragma once

#include <Math/Vec3.hpp>
#include <Math/Vec2.hpp>

namespace drak {
namespace video {
namespace geom {

enum VertexAttrib : U32 {
	VERT_ATTR_POS,
	VERT_ATTR_NORMAL,
	VERT_ATTR_UV,
	VERT_ATTR_COUNT
};

struct Vertex {
	Vertex() = default;
	Vertex(
		const math::Vec3f& aPos,
		const math::Vec3f& aNormal,
		const math::Vec2f& aUV);

	math::Vec3f pos;
	math::Vec3f normal;
	math::Vec2f uv;
};

struct IndexedVertex {
	U16 pos;
	U16 normal;
	U16 uv;
};

struct IndexComparison {
	bool operator()(const IndexedVertex& left, const IndexedVertex& right) const {
		return memcmp(&left, &right, sizeof(math::Vec3us)) < 0;
	}
};

} // namespace geom
} // namespace video
} // namespace drak
