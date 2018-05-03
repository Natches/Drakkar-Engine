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

core::EError CreateDirectoryIfDoesntExist(const char* path) {
	core::EError err;
	if ((err = DirectoryExists(path)) == core::EError::NO_ERROR)
		return CreateDirectory(path);
	return err;
}

} // namespace io
} // namespace drak