#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace io {

core::EError FileExists(const char* path) {
	if (!(_access_s(path, 0)))
		return core::EError::NO_ERROR;
	else
		return core::EError::FILE_NOT_FOUND;

}

core::EError DirectoryExists(const char* path) {
	if (!(_access_s(path, 0)))
		return core::EError::NO_ERROR;
	else
		return core::EError::DIRECTORY_NOT_FOUND;
}

core::EError CreateDirectory(const char* path) {
	if (!(_mkdir(path)))
		return core::EError::NO_ERROR;
	else if (errno == EEXIST)
		return core::EError::DIRECTORY_ALREADY_EXIST;
	else
		return core::EError::DIRECTORY_NOT_CREATED;
}

DRAK_API core::EError CreateDirectories(const char* path) {
	core::EError err;
	std::string directory = path;
	size_t pos = 0, oldPos = 0;
	while((pos = directory.find_first_of('/')) != directory.npos ||
		(pos = directory.find_first_of('\\')) != directory.npos) {
		oldPos += pos + 1;
		directory = path;
		directory.erase(directory.begin() + oldPos, directory.end());
		if ((err = DirectoryExists(directory.c_str())) != core::EError::NO_ERROR)
			if ((err = CreateDirectory(directory.c_str())) == core::EError::DIRECTORY_NOT_CREATED)
				return err;
		directory = path + oldPos;
	}
	return core::EError::NO_ERROR;
}

core::EError CreateDirectoryIfDoesntExist(const char* path) {
	core::EError err;
	if ((err = DirectoryExists(path)) != core::EError::NO_ERROR)
		return CreateDirectory(path);
	return core::EError::DIRECTORY_ALREADY_EXIST;
}

DRAK_API std::string Extension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('.')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string AllExtension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_first_of('.')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string FileName(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if ((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	return file;
}

DRAK_API std::string FileNameNoExtension(const char* path) {
	std::string file(path);
	size_t pos = 0;
	if((pos = file.find_last_of('/')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('\\')) != file.npos)
		file.erase(file.begin(), file.begin() + pos + 1);
	if ((pos = file.find_last_of('.')) != file.npos)
		file.erase(file.begin() + pos, file.end());
	return file;
}

} // namespace io
} // namespace drak