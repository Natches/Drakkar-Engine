#pragma once

#include <map>
#include <vector>
#include <Serialization/MetaData.hpp>
#include <Math/Vec4.hpp>

namespace drak {
namespace definition {

DK_ENUM(EFileType, U8, MESH = 1 << 0, TEXTURE = 1 << 1, MATERIAL = 1 << 2, MODEL = 1 << 3,
	SKINNEDMESH = 1 << 4)

struct Vertex {
	math::Vec3f pos, normal;
	math::Vec2f uv;
};

struct SkeletalVertex {
	math::Vec3f pos, normal;
	math::Vec2f uv;
	math::Vec4u boneId;
	math::Vec4f weight;
};

struct Mesh {
	std::string name;
	std::vector<U32> indices;
	std::vector<Vertex> vertices;
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
	bool skinned;
};

struct Joint {
	bool operator==(const Joint& j);
	math::Vec3f pos;
	math::Vec3f scale;
	math::Quat rot;
};

struct Bone {
	bool operator==(const Bone& b);
	std::string name;
	std::vector<std::string> children;
	Joint joint;
	std::string parent;
};

struct Keyframe {
	core::EError jointByName(const std::string& name, Joint& j) const;
	std::map<std::string, Joint> joints;
};

struct Animation {
	void buildNecessaryBoneList(std::unordered_map<std::string, bool>& neededBones) const;
	std::string name;
	std::vector<Keyframe> frames;
	F32 animationDuration;
	F32 tickPerSecond;
};

struct Skeleton {
	core::EError jointByName(const std::string& name, Joint& j) const;
	void interpolateKeyframe();
	void optimizeBoneList();
	void eraseFromHierarchy(Bone& b, Bone* parent);
	std::string base;
	std::map<std::string, Bone> bones;
	std::map<std::string, Animation> animations;
	math::Mat4f invGlobalPos;
};

struct SkinnedMesh {
	std::string name;
	std::vector<U32> indices;
	std::vector<SkeletalVertex> vertices;
	Skeleton skeleton;
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
DK_PUBLIC_FIELDS(mesh, material, skinned)
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

DK_METADATA_BEGIN(drak::definition::Joint)
DK_PUBLIC_FIELDS(pos, scale, rot)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Bone)
DK_PUBLIC_FIELDS(name, children, joint)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Keyframe)
DK_PUBLIC_FIELDS(joints)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Animation)
DK_PUBLIC_FIELDS(name, frames, animationDuration, tickPerSecond)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::Skeleton)
DK_PUBLIC_FIELDS(base, bones, animations,invGlobalPos)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::definition::SkinnedMesh)
DK_PUBLIC_FIELDS(name, indices, vertices, skeleton)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END