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
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	FLOAT,
	INT,
	UNSIGNED_INT
};

struct VertexAttribDesc {
	VertexAttribDesc() = default;
	VertexAttribDesc(
		EVertexAttrib		aAttrib,
		EVertexAttribType	aType,
		U32					aSize,
		bool				aNormalized)
	:	attrib(aAttrib),
		type(aType),
		size(aSize),
		normalized(aNormalized) {}

	EVertexAttrib		attrib;
	EVertexAttribType	type;
	U32					size;
	bool				normalized;
};

extern const VertexAttribDesc g_VertexAttribDesc[];

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


} // namespace geom
} // namespace drak
