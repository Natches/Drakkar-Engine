#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace definition {

DK_ENUM_CLASS(EFileType, U8, MESH, TEXTURE)

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

bool IsTexture(const char* file) {
	return fileMap.find(drak::io::Extension(file)) != fileMap.end() && fileMap.at(drak::io::Extension(file)) == EFileType::TEXTURE;
}

bool IsMesh(const char* file) {
	return fileMap.find(drak::io::Extension(file)) != fileMap.end() && fileMap.at(drak::io::Extension(file)) == EFileType::MESH;
}

} // namespace definition
} // namespace drak
