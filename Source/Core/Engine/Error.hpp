#pragma once

#include <Core/Utils/MacroUtils.hpp>
#include <Core/Engine/Types.hpp>

namespace drak {
namespace core {

DK_ENUM_CLASS(EError, U8, NO_ERROR, FILE_NOT_FOUND, DIRECTORY_ALREADY_EXIST, ACCESS_DENIED,
	DIRECTORY_NOT_CREATED, DIRECTORY_NOT_FOUND, CLASS_NOT_FOUND, FILE_NOT_OPENED, JOINT_NOT_FOUND)

#define DK_OK core::EError::NO_ERROR
#define DK_DIR_OK(x) x == DK_OK || x == core::EError::DIRECTORY_ALREADY_EXIST

#define DK_MATH_ERROR0(x) "Template type '"DK_STRINGIZE(x)"', must be a Scalar Type( eg : I/U 8-16-32, F32 )	\
and not a 64 bit Scalar Type( eg : I/U 64, F64 ) !!"
#define DK_MATH_ERROR1(x) "Template type '"DK_STRINGIZE(x)"', must be a Floating Point Type ( eg : F32 ) !!"
#define DK_MATH_ERROR2(x) "Template type '"DK_STRINGIZE(x)"', must be a Floating Point Type ( eg : F32 ) to use this func : " __FUNCTION__ "!!"
#define DK_MATH_ERROR3(x) "Template type '"DK_STRINGIZE(x)"', must be a Signed Type ( eg : I/F 8-16-32 ) to use this func : " __FUNCTION__ "!!"

} //namespace core
} //namespace drak