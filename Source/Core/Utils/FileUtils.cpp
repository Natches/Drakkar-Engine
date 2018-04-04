#include <Core/Utils/FileUtils.hpp>
#include <fstream>
#include <io.h>
#include <direct.h>

namespace drak {
namespace io {

bool FileExists(const char* path) {
	return !_access(path, 0);
}

bool DirectoryExists(const char* path) {
	return !_access(path, 0);
}

bool CreateDirectory(const char* path) {
	return !_mkdir(path);
}

bool CreateDirectoryIfDoesntExist(const char* path) {
	if (!DirectoryExists(path))
		return CreateDirectory(path);
	return true;
}

} // namespace io
} // namespace drak