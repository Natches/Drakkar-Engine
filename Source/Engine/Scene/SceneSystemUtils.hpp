#pragma once
#define COMPONENT_CONTAINER(c)																											\
std::vector<components::##c> c##ComponentContainer;																						\
template <>																																\
inline void* getComponentContainerByID<components::ComponentType<components::##c>::id>() { return &c##ComponentContainer;}				\
bool c##ContainerDirty;																													\
public:																																	\
template <>																																\
inline void setComponentContainerDirtyByID<components::ComponentType<components::##c>::id>(bool value) { c##ContainerDirty = value; }	\
private:																																\
template <>																																\
inline bool getComponentContainerDirtyByID<components::ComponentType<components::##c>::id>() { return c##ContainerDirty; }				\
std::map<U64, std::vector<components::##c>> knownSubArraysOf##c;																		\
template <>																																\
inline void* getknownSubArraysByID<components::ComponentType<components::##c>::id>() { return &knownSubArraysOf##c; }