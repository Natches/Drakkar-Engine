#include <PrecompiledHeader/pch.hpp>
#include <Core/Utils/FileUtils.hpp>

namespace drak {
namespace definition {

static const std::map<std::string, EFileType> fileMap{ { "fbx", EFileType::MESH },
{ "3d", EFileType::MESH },
{ "3ds", EFileType::MESH },
{ "3mf", EFileType::MESH },
{ "ac3d", EFileType::MESH },
{ "amj", EFileType::MESH },
{ "b3d", EFileType::MESH },
{ "blend", EFileType::MESH },
{ "bvh", EFileType::MESH },
{ "cms", EFileType::MESH },
{ "cob", EFileType::MESH },
{ "dae", EFileType::MESH },
{ "md2", EFileType::MESH },
{ "md3", EFileType::MESH },
{ "md5", EFileType::MESH },
{ "mdc", EFileType::MESH },
{ "mdl", EFileType::MESH },
{ "obj", EFileType::MESH },
{ "ply", EFileType::MESH },
{ "stl", EFileType::MESH },
{ "png", EFileType::TEXTURE },
{ "jpeg", EFileType::TEXTURE },
{ "jpg", EFileType::TEXTURE },
{ "tiff", EFileType::TEXTURE },
{ "dds", EFileType::TEXTURE },
{ "tga", EFileType::TEXTURE },
{ "bmp", EFileType::TEXTURE }
};

core::EError Keyframe::jointByName(const std::string& name, Joint& j) const {
	if (joints.find(name) != joints.end()) {
		j = joints.at(name);
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

void Animation::buildNecessaryBoneList(std::unordered_map<std::string, bool>& neededBones) const {
	for (auto kFrame : frames) {
		for (auto& nBone : neededBones) {
			if (kFrame.jointByName(nBone.first, Joint()) == DK_OK)
				nBone.second = true;
		}
	}
}

core::EError Skeleton::jointByName(const std::string& name, Joint& j) const {
	if (bones.find(name) != bones.end()) {
		j = bones.at(name).joint;
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

void Skeleton::eraseFromHierarchy(Bone& b, Bone* parent) {
	for (auto& child : b.children) {
		eraseFromHierarchy(bones[child], &b);
	}
	if(parent)
		parent->children.erase(std::find(parent->children.begin(), parent->children.end(), b.name));
	bones.erase(b.name);
}

void Skeleton::optimizeBoneList() {
	std::unordered_map<std::string, bool> neededBones;
	for (auto& bone : bones)
		neededBones[bone.first] = false;
	for (auto& anim : animations) {
		anim.buildNecessaryBoneList(neededBones);
	}
	for (auto& nBone : neededBones) {
		if (!nBone.second)
			eraseFromHierarchy(bones[nBone.first], &bones[bones[nBone.first].parent]);
	}
}

bool IsTexture(const char* file) {
	return fileMap.find(drak::io::Extension(file)) != fileMap.end() && fileMap.at(drak::io::Extension(file)) == EFileType::TEXTURE;
}

bool IsMesh(const char* file) {
	return fileMap.find(drak::io::Extension(file)) != fileMap.end() && fileMap.at(drak::io::Extension(file)) == EFileType::MESH;
}

bool Bone::operator==(const Bone& b) {
	return b.name == name;
}

} // namespace definition
} // namespace drak
