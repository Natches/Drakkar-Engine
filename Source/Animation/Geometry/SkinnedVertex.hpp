#pragma once

#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace geom {

const VertexAttribDesc g_SkinnedVertexAttribDesc[5] = {
	{ VERT_ATTR_POS,	FLOAT, 3u, false },
	{ VERT_ATTR_NORMAL, FLOAT, 3u, false },
	{ VERT_ATTR_UV,		FLOAT, 2u, false },
	{ VERT_ATTR_BONE_ID, UNSIGNED_INT, 4u, false },
	{ VERT_ATTR_BONE_WEIGHT, FLOAT, 4u, false }
};

struct Vertex1P1N1UV1B1W : public Vertex1P1N1UV {
	Vertex1P1N1UV1B1W() = default;
	Vertex1P1N1UV1B1W(const math::Vec3f& aPos, const math::Vec3f& aNormal, const math::Vec2f& aUV,
		const math::Vec4u& aBoneIndice, const math::Vec4f& aBoneWeight)
		: Vertex1P1N1UV(aPos, aNormal, aUV), boneIndice(aBoneIndice), boneWeight(aBoneWeight) {
	}
	math::Vec4u boneIndice;
	math::Vec4f boneWeight;
};

} // namespace geom
} // namespace drak