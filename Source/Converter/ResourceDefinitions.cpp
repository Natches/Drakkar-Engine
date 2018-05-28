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

core::EError Skeleton::jointByName(const std::string& name, Joint& j) const {
	if (handles.find(name) != handles.end()) {
		j = bones.at(handles.at(name)).joint;
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

void Skeleton::interpolateKeyframe() {
	for (auto& animPair : animations) {
		std::vector<Keyframe> tempFrame;
		Animation& anim = animPair.second;
		tempFrame.reserve(anim.frames.size());
		for (U32 i = 0, size = (U32)anim.frames.size(); i < size; ++i) {
			definition::Keyframe& frame = anim.frames[i], newFrame;
			Joint j, j2;
			for (auto& bone : bones) {
				if (frame.jointByName(bone.name, j) == DK_OK) {
					if (i != size - 1) {
						if (anim.frames[i + 1].jointByName(bone.name, j2) == DK_OK) {
							j.pos = math::Lerp(j.pos, j2.pos, 0.5f);
							//j.rot = math::SLerp(j.rot, j2.rot, 0.5f);
						}
					}
					else if (i == size - 1) {
						if (anim.frames[0].jointByName(bone.name, j2) == DK_OK) {
							j.pos = math::Lerp(j.pos, j2.pos, 0.5f);
							//j.rot = math::SLerp(j.rot, j2.rot, 0.5f);
						}
					}
					if (j == bone.joint)
						frame.joints.erase(bone.name);
					else
						newFrame.joints[bone.name] = j;
				}
			}
			tempFrame.emplace_back(newFrame);
		}
		anim.frames = std::move(tempFrame);
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

bool Joint::operator==(const Joint& j) {
	return pos == j.pos  && rot == j.rot;
}

} // namespace definition
} // namespace drak
