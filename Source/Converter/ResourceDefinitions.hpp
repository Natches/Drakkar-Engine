#pragma once

#include <vector>
#include <Serialization/MetaData.hpp>
#include <Math/Vec4.hpp>

namespace drak {
namespace definition {

DK_ENUM(EFileType, U8, MESH = 1 << 0, TEXTURE = 1 << 1, MATERIAL = 1 << 2, MODEL = 1 << 3)

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
	std::string name;
	std::vector<U32> indices;
	std::vector<Vertex> vertices;
};

struct SkeletalMesh {
	std::string name;
	std::vector<U32> indices;
	std::vector<SkeletalVertex> vertices;
};

struct Texture {
	std::string name;
	std::vector<U8> pixels;
	U32 width, height;
	U16 format;
	U8 channels;
};

struct Material {
	std::string name;
	std::string albedo;
	std::string normal;
	math::Vec3f diffuseColor;
	math::Vec3f specularColor;
	math::Vec3f ambientColor;
	math::Vec3f transparentColor;
	F32 opacity;
	F32 shininess;
	F32 shininessStrength;
	bool wireframe, twoSided;
};

struct Model {
	std::string mesh;
	std::string material;
};

struct ResourceName {
	std::map<std::string, EFileType> names;
};

struct Pak {
	std::vector<std::string> filenames;
	std::vector<std::string> files;
};

bool IsTexture(const char* file);
bool IsMesh(const char* file);

} // namespace definition
} // namespace drak

DK_METADATA_BEGIN(drak::definition::Vertex)
DK_PUBLIC_FIELDS(pos, normal, uv)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::SkeletalVertex)
DK_PUBLIC_FIELDS(weight, boneId, pos, normal, uv)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Mesh)
DK_PUBLIC_FIELDS(name, indices, vertices)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::SkeletalMesh)
DK_PUBLIC_FIELDS(name, indices, vertices)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Texture)
DK_PUBLIC_FIELDS(name, channels, width, height, pixels, format)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Material)
DK_PUBLIC_FIELDS(name, albedo, normal, diffuseColor, specularColor, ambientColor, transparentColor,
opacity, shininess, shininessStrength, twoSided, wireframe)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Model)
DK_PUBLIC_FIELDS(mesh, material)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Pak)
DK_PUBLIC_FIELDS(filenames, files)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::ResourceName)
DK_PUBLIC_FIELDS(names)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END