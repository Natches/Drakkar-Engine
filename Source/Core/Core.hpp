#pragma once
#include <Core/Engine/Types.hpp>
#include <Core/Engine/TypeTraits.hpp>
#include <Core/Engine/Engine.hpp>
#include <Core/Utils/ClassUtils.h>
#include <Core/Utils/TemplateUtils.h>
#include <Core/Log/Log.hpp>

#ifdef DRAK_EXPORTS  
#define DRAK_API __declspec(dllexport)   
#else  
#define DRAK_API __declspec(dllimport)   
#endif