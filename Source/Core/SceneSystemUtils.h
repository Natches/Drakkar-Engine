#pragma once
#define COMPONENT_CONTAINER(ComponentType)																											\
	std::vector<components::##ComponentType> ComponentType##ComponentContainer;																		\
	template <>																																		\
	inline void* getComponentContainerID<components::AComponent<components::##ComponentType>::id>() { return &ComponentType##ComponentContainer;}