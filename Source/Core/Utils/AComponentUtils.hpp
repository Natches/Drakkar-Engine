#pragma once
#include <PrecompiledHeader/pch.hpp>

/*!
*	@file
*	Macros and templated structures used in the component system
*/

namespace drak {
namespace components {

template <class c>
struct  ComponentType
{
	static const U32 ID;
};


struct AComponent
{
	U64 idx;
	U64 GameObjectID;
};
}

}
//DK_METADATA_BEGIN(drak::behavior::ABehavior*)
//DK_PUBLIC_FIELDS()
//DK_PUBLIC_FIELD_COMPLEMENT
//DK_METADATA_END
//DK_METADATA_BEGIN(drak::behavior::ABehavior)
//DK_PUBLIC_FIELDS(gameObjectID, name)
//DK_PUBLIC_FIELD_COMPLEMENT
//DK_METADATA_END


#define DRAK_COMPONENT_START(name, ...) 		\
namespace drak {								\
namespace components {							\
struct name : public AComponent, __VA_ARGS__	\
{												\
	//void operator=(const name& other){std::memcpy(this, &other, sizeof(name));}


#define DRAK_COMPONENT_END(name)				\
};												\
												\
}												\
}												\
template <>										\
struct  drak::components::ComponentType<drak::components::name>\
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