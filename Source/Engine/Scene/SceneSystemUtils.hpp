#pragma once
#define COMPONENT_CONTAINER(c)																										\
	std::vector<components::##c> c##ComponentContainer;																				\
	template <>																														\
	inline void* getComponentContainerByID<components::ComponentType<components::##c>::id>() { return &c##ComponentContainer;}