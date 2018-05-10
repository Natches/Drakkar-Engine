#pragma once

#include <vector>
#include <Serialization/MetaData.hpp>
#include <Math/Vec4.hpp>

namespace drak {

struct Vertex {
	math::Vec3f pos, normal;
	math::Vec2f uv;
};

struct SkeletalVertex {
	math::Vec4f weight;
	math::Vec4u boneId;
	math::Vec3f pos, normal;
	math::Vec2f uv;
};

struct Mesh {
	std::vector<int> indices;
	std::vector<Vertex> vertices;
};

struct SkeletalMesh {
	std::vector<int> indices;
	std::vector<SkeletalVertex> vertices;
};

struct Texture {
	U8 channel;
	U32 width, height;
	std::vector<U8> pixels;
};

struct Material {
	Texture albedo;
	Texture normal;
};

template<typename T>
struct Model {
	static_assert(std::is_same_v<T, Mesh> || std::is_same_v<T, SkeletalMesh>,
		"Must Be a Mesh Definition !!");
	T mesh;
	Material material;
};

bool IsTexture(const char* file);
bool IsMesh(const char* file);

} //namespace drak

DK_METADATA_BEGIN(drak::Vertex)
DK_PUBLIC_FIELDS(pos, normal, uv)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::SkeletalVertex)
DK_PUBLIC_FIELDS(weight, boneId, pos, normal, uv)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::Mesh)
DK_PUBLIC_FIELDS(indices, vertices)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::SkeletalMesh)
DK_PUBLIC_FIELDS(indices, vertices)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::Texture)
DK_PUBLIC_FIELDS(channel, width, height, pixels)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::Material)
DK_PUBLIC_FIELDS(albedo, normal)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::Model<Mesh>)
DK_PUBLIC_FIELDS(mesh, material)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::Model<SkeletalMesh>)
DK_PUBLIC_FIELDS(mesh, material)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END