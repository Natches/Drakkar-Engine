#pragma once
#define COMPONENT_CONTAINER(c)																											\
std::vector<components::##c> c##ComponentContainer;																						\
template <>																																\
inline void* __ccByID<components::ComponentType<components::##c>::id>() { return &c##ComponentContainer;}

#define __getComponentContainer(c) (*(std::vector<c>*)__ccByID<components::ComponentType<c>::id>())