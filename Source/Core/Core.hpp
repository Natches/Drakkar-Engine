#pragma once
#include <Core/Engine/Types.hpp>
#include <Core/Engine/TypeTraits.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Core/Utils/TemplateUtils.hpp>
#include <Core/Log/Log.hpp>

#ifdef DRAK_EXPORTS
#define DRAK_API __declspec(dllexport)
#else
#define DRAK_API __declspec(dllimport)
#endif