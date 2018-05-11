#include <PrecompiledHeader/pch.hpp>
#include <Converter/ResourceDefinitions.hpp>

namespace drak {

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
{ "irr", EFileType::MESH },
{ "irrmesh", EFileType::MESH },
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
	std::string ext(file);
	ext.erase(ext.begin(), ext.begin() + ext.find_last_of('.'));
	if (ext[0] == '.')
		return fileMap.find(ext.c_str() + 1) != fileMap.end() && fileMap.at(ext.c_str() + 1) == EFileType::TEXTURE;
	else
		return false;
}

bool IsMesh(const char* file) {
	std::string ext(file);
	ext.erase(ext.begin(), ext.begin() + ext.find_last_of('.'));
	if (ext[0] == '.') {
		return fileMap.find(ext.c_str() + 1) != fileMap.end() && fileMap.at(ext.c_str() + 1) == EFileType::MESH;
	}
	else
		return false;
}

} //namespace drak
