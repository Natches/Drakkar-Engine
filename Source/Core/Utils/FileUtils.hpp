#pragma once

#include <Core/Engine/Types.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Core/Engine/Error.hpp>

namespace drak {
namespace io {

enum E_FileOpeningMethod : U8 {
	READ,
	WRITE,
	READ_WRITE,
	APPEND,
	BINARY
};

DRAK_API core::EError FileExists(const char* path);

DRAK_API core::EError DirectoryExists(const char* path);

DRAK_API core::EError CreateDirectory(const char* path);

DRAK_API core::EError CreateDirectories(const char* path);

DRAK_API core::EError CreateDirectoryIfDoesntExist(const char* path);

DRAK_API std::string Extension(const char* path);

DRAK_API std::string AllExtension(const char* path);

DRAK_API std::string FileName(const char* path);

DRAK_API std::string FileNameNoExtension(const char* path);

} // namespace io
} // namespace drak