#pragma once

#include <Core/Engine/Types.hpp>
#include <Core/Utils/ClassUtils.hpp>

namespace drak {
namespace io {

enum E_FileOpeningMethod : U8 {
	READ,
	WRITE,
	READ_WRITE,
	APPEND,
	BINARY
};

DRAK_API bool FileExists(const char* path);

DRAK_API bool DirectoryExists(const char* path);

DRAK_API bool CreateDirectory(const char* path);

DRAK_API bool CreateDirectoryIfDoesntExist(const char* path);

} // namespace io
} // namespace drak