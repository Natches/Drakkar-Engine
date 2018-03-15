#pragma once

#include <Core/TemplateUtils.h>

#define SERVICEVARNAME(T) m_##T

#define SERVICE(T) \
T SERVICEVARNAME(T) = T::Create();

#define REGISTER_SERVICES(Name, N, ...)															\
TYPELIST(N, Name, 1, __VA_ARGS__)																\
SERVICESPECIALIZE(N, __VA_ARGS__)																\
inline void CONCAT(Startup, Name)() {															\
	Name::instance().Startup(new ServiceTemplated<N, __VA_ARGS__>(), new TypeList<Name, 1>());	\
}																								\
using CONCAT(Name, RegisteredServiceType) = TypeList<Name, N>;

#define GETSERVICE(SL, N, T, TypeListStruct)													\
	static_cast<ServiceTemplated<N, GATHERTYPE(TypeListStruct, N)>*>							\
		(SL::instance().m_service)->SERVICEVARNAME(T)

#define SERVICESPECIALIZE(N, ...)														\
template<int i, typename ...U>															\
struct ServiceTemplated {																\
};																						\
template<>																				\
struct ServiceTemplated<N, __VA_ARGS__> : public drak::sys::ServiceLocator::Services {	\
	SERVICESPECIALIZETEMPLATE(N, __VA_ARGS__)											\
};

#define SERVICESPECIALIZETEMPLATE(N, ...)							\
	EXPAND(CONCAT(SERVICESPECIALIZETEMPLATE, N)(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE0()

#define SERVICESPECIALIZETEMPLATE1(T)								\
	SERVICE(T)														\

#define SERVICESPECIALIZETEMPLATE2(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE1(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE3(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE2(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE4(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE3(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE5(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE4(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE6(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE5(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE7(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE6(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE8(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE7(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE9(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE8(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE10(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE9(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE11(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE10(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE12(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE11(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE13(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE12(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE14(T,...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE13(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE15(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE14(__VA_ARGS__))

#define SERVICESPECIALIZETEMPLATE16(T, ...)							\
	SERVICE(T)														\
	EXPAND(SERVICESPECIALIZETEMPLATE15(__VA_ARGS__))