#pragma once

#include <Core/Utils/MacroUtils.hpp>
#include <Core/Engine/Types.hpp>

namespace drak {
namespace core {

DK_ENUM_CLASS(EError, U8, NO_ERROR, FILE_NOT_FOUND, DIRECTORY_ALREADY_EXIST, ACCESS_DENIED,
	DIRECTORY_NOT_CREATED, DIRECTORY_NOT_FOUND, CLASS_NOT_FOUND, FILE_NOT_OPENED)

} //namespace core
} //namespace drak