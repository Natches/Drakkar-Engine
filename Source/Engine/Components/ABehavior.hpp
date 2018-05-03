#pragma once
#include <Serialization/MetaData.hpp>
#include <Engine/Engine.hpp>
namespace drak {
namespace behavior {
struct ABehaviorVariables {
	U32 gameObjectID;
	std::string name;
};


template <class c>
struct  BehaviorType {
	static const U32 ID;
};

#define BHVR_TYPE(name)						\
template <>									\
struct  BehaviorType<name>					\
{											\
static const U32 id = (U32)__COUNTER__;		\
};

}
}