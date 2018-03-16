#pragma once

#include <Core/Utils/TemplateUtils.h>

#define DK_SERVICE_VARNAME(Class) m_##Class

#define DK_SERVICE(Class) \
Class DK_SERVICE_VARNAME(Class) = Class::Create();

#define DK_REGISTER_SERVICES(ServiceLocation, ArgsN, ...)											\
DK_TYPELIST(ArgsN, ServiceLocation, 1, __VA_ARGS__)													\
DK_SERVICE_SPECIALIZE(ArgsN, __VA_ARGS__)															\
inline void DK_CONCAT(Startup, ServiceLocation)() {													\
	ServiceLocation::instance().Startup(new ServiceTemplated<ArgsN, __VA_ARGS__>(),					\
		new TypeList<ServiceLocation, 1>());														\
}																									\
using DK_CONCAT(ServiceLocation, RegisteredServiceTypeList) = TypeList<ServiceLocation, 1>;			\
using DK_CONCAT(ServiceLocation, RegisteredServiceTemplated) =										\
	ServiceTemplated<ArgsN, __VA_ARGS__>;

#define DK_GET_SERVICE(ServiceLoc, T, RegisteredServiceTemplated)									\
static_cast<RegisteredServiceTemplated*>(ServiceLoc::instance().m_service)->DK_SERVICE_VARNAME(T)

#define DK_SERVICE_SPECIALIZE(ArgsN, ...)															\
template<int I, typename ...U>																		\
struct ServiceTemplated {																			\
};																									\
template<>																							\
struct ServiceTemplated<ArgsN, __VA_ARGS__> : public drak::sys::ServiceLocator::Services {			\
	DK_IMPLEMENT_SERVICE(ArgsN, __VA_ARGS__)														\
};

#define DK_IMPLEMENT_SERVICE(ArgsN, ...) \
	DK_EXPAND(DK_CONCAT(DK_IMPLEMENT_SERVICE, ArgsN)(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE0()

#define DK_IMPLEMENT_SERVICE1(Class) \
	DK_SERVICE(Class)

#define DK_IMPLEMENT_SERVICE2(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE1(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE3(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE2(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE4(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE3(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE5(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE4(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE6(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE5(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE7(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE6(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE8(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE7(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE9(Class, ...)						\
	DK_SERVICE(Class)											\
	DK_EXPAND(DK_IMPLEMENT_SERVICE8(__VA_ARGS__))




#define DK_IMPLEMENT_SERVICE10(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE9(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE11(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE10(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE12(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE11(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE13(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE12(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE14(Class,...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE13(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE15(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE14(__VA_ARGS__))

#define DK_IMPLEMENT_SERVICE16(Class, ...)							\
	DK_SERVICE(Class)														\
	DK_EXPAND(DK_IMPLEMENT_SERVICE15(__VA_ARGS__))