#pragma once
#include <Core/Core.hpp>
/*!
*	@file
*	Macros and templated structures used in the component system
*/

template <class c>
struct  AComponent
{
	static const int ID;
};

#define DRAK_COMPONENT_START(name) 	\
struct name							\
{											 								

#define DRAK_COMPONENT_END(name)				\
};												\
												\
template <>										\
struct  AComponent<name>				\
{												\
	static const U32 id = (U32)__COUNTER__;		\
};												

/*!
*	\def  DRAK_COMPONENT_START(name)
*	\brief Defines the beginning of a component
*	The Component ID Generator uses this as a tag to find which IDs it must generate.
*/

/*!
*	\def  DRAK_COMPONENT_END(name)
*	\brief Defines the end of a component 
*	Creates a template specialization of AComponent templated with the defined component. This allows templated functions to use the component ID as template parameters
*/