#pragma once

#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>

namespace drak {
namespace geom {

enum EVertexAttrib : U32 {
	VERT_ATTR_POS,
	VERT_ATTR_NORMAL,
	VERT_ATTR_UV,
	VERT_ATTR_COUNT
};

enum EVertexAttribType : U32 {
	BYTE,
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	INT,
	UNSIGNED_INT,
	FLOAT
};

inline U32 VertexAttribSize(EVertexAttribType type, U32 count) {
	switch (type) {
		case BYTE:
		case UNSIGNED_BYTE:  return 1u * count;
		case SHORT:
		case UNSIGNED_SHORT: return 2u * count;
		default:			 return 4u * count;
	}
};

struct VertexAttribDesc {
	VertexAttribDesc() = default;
	VertexAttribDesc(
		EVertexAttrib		aAttrib,
		EVertexAttribType	aType,
		U32					aCount,
		bool				aNormalized)
	:	attrib(aAttrib),
		type(aType),
		count(aCount),
		normalized(aNormalized) {}

	EVertexAttrib		attrib;
	EVertexAttribType	type;
	U32					count;
	bool				normalized;
};

const VertexAttribDesc g_VertexAttribDesc[3] = {
	{ VERT_ATTR_POS,	FLOAT, 3u, false },
	{ VERT_ATTR_NORMAL, FLOAT, 3u, false },
	{ VERT_ATTR_UV,		FLOAT, 2u, false }
};

struct Vertex1P {
	Vertex1P() = default;
	Vertex1P(const math::Vec3f& aPos)
		: pos(aPos) {}

	math::Vec3f pos;
};

struct Vertex1P1N : public Vertex1P {
	Vertex1P1N() = default;
	Vertex1P1N(const math::Vec3f& aPos, const math::Vec3f& aNormal)
		: Vertex1P(aPos), normal(aNormal) {}

	math::Vec3f normal;
};

struct Vertex1P1N1UV  : public Vertex1P1N {
	Vertex1P1N1UV() = default;
	Vertex1P1N1UV(const math::Vec3f& aPos, const math::Vec3f& aNormal, const math::Vec2f& aUV)
		: Vertex1P1N(aPos, aNormal), uv(aUV) {}

	math::Vec2f uv;
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
