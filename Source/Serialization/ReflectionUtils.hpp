#pragma once

#include <Core/Utils/VA_ArgsUtils.hpp>

#define DK_POINT_MEMBER(...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_SIZEOF_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_NAME_ARRAY(...)																\
static constexpr std::array<constexpr const char*, DK_ARGS_N(__VA_ARGS__)> s_varName =	\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };

#define DK_MEMBER_TUPLE(...)																	\
static constexpr auto s_var = std::make_tuple(DK_REVERSE_VA_ARGS(DK_POINT_MEMBER(__VA_ARGS__)));

#define DK_STATIC_SIZE(...)											\
static constexpr size_t s_staticSize = DK_SIZEOF_VA_ARGS(__VA_ARGS__);

#define DK_TOTAL_SIZE(...)																				\
static size_t ComputeTotalSize(const type& t) {															\
	return s_staticSize + DK_EXPAND(DK_CONCAT(DK_DYNAMIC_SIZE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__));	\
};

#define DK_GET_BY_NAME(...)													\
static std::tuple<void*, size_t> get(const type& t, const char* str) {		\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_SET_BY_NAME(...)													\
static bool set(type& t, const char* name, void* data) {					\
	DK_EXPAND(DK_CONCAT(DK_SET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
	return false;															\
}

#define DK_GET_SIZE_BY_NAME(...)												\
static size_t SizeOf(const type* t, const char* str) {							\
	DK_EXPAND(DK_CONCAT(DK_SIZEOF_TYPE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_GET_TYPENAME_BY_NAME(...)										\
static const char* typeNameOf(const char* str){								\
	DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_METADATA_GET_BY_NAME(...)													\
static std::tuple<void*, size_t> get(const type& t, const char* name){					\
	std::tuple<void*, size_t> res;														\
	DK_EXPAND(DK_CONCAT(DK_METADATA_GET_BY_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_METADATA_SET_BY_NAME(...)															\
static bool set(type& t, const char* name, void* data){											\
	return DK_EXPAND(DK_CONCAT(DK_METADATA_SET_BY_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_METADATA_FIELD_ADDITIONAL_INFORMATION(...)	\
DK_METADATA_FIELD_ARRAY(__VA_ARGS__)					\
DK_METADATA_FIELD_NAME_ARRAY(__VA_ARGS__)				\
DK_METADATA_FIELD_STATIC_SIZE(__VA_ARGS__)				\
DK_METADATA_FIELD_TOTAL_SIZE(__VA_ARGS__)

#define DK_METADATA_FIELD_ARRAY(...)															\
static constexpr std::array<IFields<type>*, DK_ARGS_N(__VA_ARGS__)> s_fields =					\
{ DK_EXPAND(DK_CONCAT(DK_METADATA_FIELD_ARRAY, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__)) };	\

#define DK_METADATA_FIELD_NAME_ARRAY(...)							\
static constexpr std::array<constexpr const char*, DK_ARGS_N(__VA_ARGS__)> s_fieldName	\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };

#define DK_METADATA_FIELD_STATIC_SIZE(...)	\
static constexpr size_t s_staticSize =		\
DK_EXPAND(DK_CONCAT(DK_METADATA_FIELD_STATIC_SIZE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE(...)														\
static size_t ComputeTotalSize(const type& t) {													\
return DK_EXPAND(DK_CONCAT(DK_METADATA_FIELD_TOTAL_SIZE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_POINT_MEMBER_IMPL0(...)	__VA_ARGS__
#define DK_POINT_MEMBER_IMPL1(t)\
DK_POINT_MEMBER_IMPL0(&type::t)

#define DK_POINT_MEMBER1(t, ...)\
DK_POINT_MEMBER_IMPL0(__VA_ARGS__, &type::t)

#define DK_POINT_MEMBER_IMPL2(t, ...)\
DK_EXPAND(DK_POINT_MEMBER1(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL3(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL2(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL4(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL3(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL5(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL4(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL6(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL5(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL7(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL6(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL8(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL7(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL9(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL8(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL10(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL9(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL11(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL10(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL12(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL11(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL13(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL12(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL14(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL13(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL15(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL14(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL16(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL15(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL17(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL16(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL18(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL17(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL19(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL18(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL20(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL19(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL21(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL20(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL22(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL21(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL23(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL22(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL24(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL23(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL25(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL24(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL26(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL25(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL27(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL26(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL28(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL27(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL29(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL28(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL30(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL29(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL31(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL30(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_IMPL32(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_IMPL31(__VA_ARGS__, &type::t))

#define DK_SIZEOF_TYPE_IMPL(ty)															\
if(!strcmp(str, #ty)) {																	\
	if constexpr (drak::serialization::SizeOfSerializedType<TYPEOF(type::ty)>())		\
		return drak::serialization::SizeOfSerializedType<TYPEOF(type::ty)>();			\
	else																				\
		return drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t->ty);\
}

#define DK_SIZEOF_TYPE0 return 0;
#define DK_SIZEOF_TYPE1(ty)\
DK_SIZEOF_TYPE_IMPL(ty)

#define DK_SIZEOF_TYPE2(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE1(__VA_ARGS__))

#define DK_SIZEOF_TYPE3(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE2(__VA_ARGS__))

#define DK_SIZEOF_TYPE4(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE3(__VA_ARGS__))

#define DK_SIZEOF_TYPE5(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE4(__VA_ARGS__))

#define DK_SIZEOF_TYPE6(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE5(__VA_ARGS__))

#define DK_SIZEOF_TYPE7(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE6(__VA_ARGS__))

#define DK_SIZEOF_TYPE8(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE7(__VA_ARGS__))

#define DK_SIZEOF_TYPE9(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE8(__VA_ARGS__))

#define DK_SIZEOF_TYPE10(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE9(__VA_ARGS__))

#define DK_SIZEOF_TYPE11(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE10(__VA_ARGS__))

#define DK_SIZEOF_TYPE12(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE11(__VA_ARGS__))

#define DK_SIZEOF_TYPE13(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE12(__VA_ARGS__))

#define DK_SIZEOF_TYPE14(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE13(__VA_ARGS__))

#define DK_SIZEOF_TYPE15(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE14(__VA_ARGS__))

#define DK_SIZEOF_TYPE16(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE15(__VA_ARGS__))

#define DK_SIZEOF_TYPE17(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE16(__VA_ARGS__))

#define DK_SIZEOF_TYPE18(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE17(__VA_ARGS__))

#define DK_SIZEOF_TYPE19(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE18(__VA_ARGS__))

#define DK_SIZEOF_TYPE20(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE19(__VA_ARGS__))

#define DK_SIZEOF_TYPE21(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE20(__VA_ARGS__))

#define DK_SIZEOF_TYPE22(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE21(__VA_ARGS__))

#define DK_SIZEOF_TYPE23(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE22(__VA_ARGS__))

#define DK_SIZEOF_TYPE24(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE23(__VA_ARGS__))

#define DK_SIZEOF_TYPE25(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE24(__VA_ARGS__))

#define DK_SIZEOF_TYPE26(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE25(__VA_ARGS__))

#define DK_SIZEOF_TYPE27(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE26(__VA_ARGS__))

#define DK_SIZEOF_TYPE28(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE27(__VA_ARGS__))

#define DK_SIZEOF_TYPE29(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE28(__VA_ARGS__))

#define DK_SIZEOF_TYPE30(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE29(__VA_ARGS__))

#define DK_SIZEOF_TYPE31(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE30(__VA_ARGS__))

#define DK_SIZEOF_TYPE32(ty, ...)\
DK_SIZEOF_TYPE_IMPL(ty)	\
DK_EXPAND(DK_SIZEOF_TYPE31(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS0
#define DK_SIZEOF_VA_ARGS1(t)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>();\

#define DK_SIZEOF_VA_ARGS2(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS1(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS3(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS2(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS4(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS3(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS5(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS4(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS6(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS5(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS7(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS6(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS8(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS7(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS9(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS8(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS10(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS9(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS11(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS10(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS12(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS11(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS13(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS12(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS14(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS13(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS15(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS14(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS16(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS15(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS17(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS16(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS18(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS17(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS19(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS18(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS20(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS19(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS21(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS20(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS22(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS21(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS23(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS22(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS24(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS23(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS25(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS24(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS26(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS25(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS27(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS26(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS28(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS27(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS29(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS28(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS30(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS29(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS31(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS30(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS32(t, ...)\
drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS31(__VA_ARGS__))

#define DK_DYNAMIC_SIZE0
#define DK_DYNAMIC_SIZE1(ty)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty);\

#define DK_DYNAMIC_SIZE2(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE1(__VA_ARGS__))

#define DK_DYNAMIC_SIZE3(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE2(__VA_ARGS__))

#define DK_DYNAMIC_SIZE4(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE3(__VA_ARGS__))

#define DK_DYNAMIC_SIZE5(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE4(__VA_ARGS__))

#define DK_DYNAMIC_SIZE6(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE5(__VA_ARGS__))

#define DK_DYNAMIC_SIZE7(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE6(__VA_ARGS__))

#define DK_DYNAMIC_SIZE8(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE7(__VA_ARGS__))

#define DK_DYNAMIC_SIZE9(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE8(__VA_ARGS__))

#define DK_DYNAMIC_SIZE10(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE9(__VA_ARGS__))

#define DK_DYNAMIC_SIZE11(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE10(__VA_ARGS__))

#define DK_DYNAMIC_SIZE12(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE11(__VA_ARGS__))

#define DK_DYNAMIC_SIZE13(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE12(__VA_ARGS__))

#define DK_DYNAMIC_SIZE14(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE13(__VA_ARGS__))

#define DK_DYNAMIC_SIZE15(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE14(__VA_ARGS__))

#define DK_DYNAMIC_SIZE16(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE15(__VA_ARGS__))

#define DK_DYNAMIC_SIZE17(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE16(__VA_ARGS__))

#define DK_DYNAMIC_SIZE18(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE17(__VA_ARGS__))

#define DK_DYNAMIC_SIZE19(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE18(__VA_ARGS__))

#define DK_DYNAMIC_SIZE20(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE19(__VA_ARGS__))

#define DK_DYNAMIC_SIZE21(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE20(__VA_ARGS__))

#define DK_DYNAMIC_SIZE22(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE21(__VA_ARGS__))

#define DK_DYNAMIC_SIZE23(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE22(__VA_ARGS__))

#define DK_DYNAMIC_SIZE24(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE23(__VA_ARGS__))

#define DK_DYNAMIC_SIZE25(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE24(__VA_ARGS__))

#define DK_DYNAMIC_SIZE26(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE25(__VA_ARGS__))

#define DK_DYNAMIC_SIZE27(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE26(__VA_ARGS__))

#define DK_DYNAMIC_SIZE28(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE27(__VA_ARGS__))

#define DK_DYNAMIC_SIZE29(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE28(__VA_ARGS__))

#define DK_DYNAMIC_SIZE30(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE29(__VA_ARGS__))

#define DK_DYNAMIC_SIZE31(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE30(__VA_ARGS__))

#define DK_DYNAMIC_SIZE32(ty, ...)\
drak::serialization::SizeOfDynamiclyAllocatedType<TYPEOF(type::ty)>(t.ty)	 +\
DK_EXPAND(DK_DYNAMIC_SIZE31(__VA_ARGS__))

#define DK_TYPE_NAME_IMPL(t)\
if (!strcmp(str, #t))	\
	return typeid(TYPEOF(type::t)).name();

#define DK_TYPE_NAME0 return "";
#define DK_TYPE_NAME1(t)\
DK_TYPE_NAME_IMPL(t)	\
DK_TYPE_NAME0

#define DK_TYPE_NAME2(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME1(__VA_ARGS__))

#define DK_TYPE_NAME3(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME2(__VA_ARGS__))

#define DK_TYPE_NAME4(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME3(__VA_ARGS__))

#define DK_TYPE_NAME5(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME4(__VA_ARGS__))

#define DK_TYPE_NAME6(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME5(__VA_ARGS__))

#define DK_TYPE_NAME7(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME6(__VA_ARGS__))

#define DK_TYPE_NAME8(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME7(__VA_ARGS__))

#define DK_TYPE_NAME9(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME8(__VA_ARGS__))

#define DK_TYPE_NAME10(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME9(__VA_ARGS__))

#define DK_TYPE_NAME11(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME10(__VA_ARGS__))

#define DK_TYPE_NAME12(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME11(__VA_ARGS__))

#define DK_TYPE_NAME13(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME12(__VA_ARGS__))

#define DK_TYPE_NAME14(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME13(__VA_ARGS__))

#define DK_TYPE_NAME15(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME14(__VA_ARGS__))

#define DK_TYPE_NAME16(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME15(__VA_ARGS__))

#define DK_TYPE_NAME17(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME16(__VA_ARGS__))

#define DK_TYPE_NAME18(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME17(__VA_ARGS__))

#define DK_TYPE_NAME19(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME18(__VA_ARGS__))

#define DK_TYPE_NAME20(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME19(__VA_ARGS__))

#define DK_TYPE_NAME21(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME20(__VA_ARGS__))

#define DK_TYPE_NAME22(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME21(__VA_ARGS__))

#define DK_TYPE_NAME23(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME22(__VA_ARGS__))

#define DK_TYPE_NAME24(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME23(__VA_ARGS__))

#define DK_TYPE_NAME25(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME24(__VA_ARGS__))

#define DK_TYPE_NAME26(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME25(__VA_ARGS__))

#define DK_TYPE_NAME27(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME26(__VA_ARGS__))

#define DK_TYPE_NAME28(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME27(__VA_ARGS__))

#define DK_TYPE_NAME29(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME28(__VA_ARGS__))

#define DK_TYPE_NAME30(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME29(__VA_ARGS__))

#define DK_TYPE_NAME31(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME30(__VA_ARGS__))

#define DK_TYPE_NAME32(t, ...)					\
DK_TYPE_NAME_IMPL(t)	\
DK_EXPAND(DK_TYPE_NAME31(__VA_ARGS__))

#define DK_GET_DATA_IMPL(ty)	\
if (!strcmp(str, #ty))			\
return GetData<TYPEOF(t.ty)>(t.ty);

#define DK_GET_DATA0 return std::make_tuple<void*, size_t>(nullptr, 0);
#define DK_GET_DATA1(ty)\
DK_GET_DATA_IMPL(ty)	\
DK_GET_DATA0

#define DK_GET_DATA2(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA1(__VA_ARGS__))

#define DK_GET_DATA3(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA2(__VA_ARGS__))

#define DK_GET_DATA4(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA3(__VA_ARGS__))

#define DK_GET_DATA5(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA4(__VA_ARGS__))

#define DK_GET_DATA6(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA5(__VA_ARGS__))

#define DK_GET_DATA7(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA6(__VA_ARGS__))

#define DK_GET_DATA8(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA7(__VA_ARGS__))

#define DK_GET_DATA9(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA8(__VA_ARGS__))

#define DK_GET_DATA10(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA9(__VA_ARGS__))

#define DK_GET_DATA11(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA10(__VA_ARGS__))

#define DK_GET_DATA12(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA11(__VA_ARGS__))

#define DK_GET_DATA13(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA12(__VA_ARGS__))

#define DK_GET_DATA14(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA13(__VA_ARGS__))

#define DK_GET_DATA15(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA14(__VA_ARGS__))

#define DK_GET_DATA16(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA15(__VA_ARGS__))

#define DK_GET_DATA17(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA16(__VA_ARGS__))

#define DK_GET_DATA18(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA17(__VA_ARGS__))

#define DK_GET_DATA19(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA18(__VA_ARGS__))

#define DK_GET_DATA20(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA19(__VA_ARGS__))

#define DK_GET_DATA21(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA20(__VA_ARGS__))

#define DK_GET_DATA22(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA21(__VA_ARGS__))

#define DK_GET_DATA23(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA22(__VA_ARGS__))

#define DK_GET_DATA24(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA23(__VA_ARGS__))

#define DK_GET_DATA25(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA24(__VA_ARGS__))

#define DK_GET_DATA26(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA25(__VA_ARGS__))

#define DK_GET_DATA27(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA26(__VA_ARGS__))

#define DK_GET_DATA28(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA27(__VA_ARGS__))

#define DK_GET_DATA29(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA28(__VA_ARGS__))

#define DK_GET_DATA30(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA29(__VA_ARGS__))

#define DK_GET_DATA31(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA30(__VA_ARGS__))

#define DK_GET_DATA32(ty, ...)\
DK_GET_DATA_IMPL(ty)	\
DK_EXPAND(DK_GET_DATA31(__VA_ARGS__))

#define DK_SET_DATA_IMPL(ty) \
if (!strcmp(name, #ty)) {	\
SetData<TYPEOF(t.ty)>(t.ty, (const char*)data, 0);	\
return true;								\
}

#define DK_SET_DATA0(...)
#define DK_SET_DATA1(ty)  \
DK_SET_DATA_IMPL(ty)

#define DK_SET_DATA2(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA1(__VA_ARGS__))

#define DK_SET_DATA3(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA2(__VA_ARGS__))

#define DK_SET_DATA4(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA3(__VA_ARGS__))

#define DK_SET_DATA5(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA4(__VA_ARGS__))

#define DK_SET_DATA6(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA5(__VA_ARGS__))

#define DK_SET_DATA7(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA6(__VA_ARGS__))

#define DK_SET_DATA8(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA7(__VA_ARGS__))

#define DK_SET_DATA9(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA8(__VA_ARGS__))

#define DK_SET_DATA10(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA9(__VA_ARGS__))

#define DK_SET_DATA11(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA10(__VA_ARGS__))

#define DK_SET_DATA12(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA11(__VA_ARGS__))

#define DK_SET_DATA13(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA12(__VA_ARGS__))

#define DK_SET_DATA14(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA13(__VA_ARGS__))

#define DK_SET_DATA15(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA14(__VA_ARGS__))

#define DK_SET_DATA16(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA15(__VA_ARGS__))

#define DK_SET_DATA17(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA16(__VA_ARGS__))

#define DK_SET_DATA18(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA17(__VA_ARGS__))

#define DK_SET_DATA19(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA18(__VA_ARGS__))

#define DK_SET_DATA20(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA19(__VA_ARGS__))

#define DK_SET_DATA21(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA20(__VA_ARGS__))

#define DK_SET_DATA22(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA21(__VA_ARGS__))

#define DK_SET_DATA23(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA22(__VA_ARGS__))

#define DK_SET_DATA24(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA23(__VA_ARGS__))

#define DK_SET_DATA25(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA24(__VA_ARGS__))

#define DK_SET_DATA26(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA25(__VA_ARGS__))

#define DK_SET_DATA27(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA26(__VA_ARGS__))

#define DK_SET_DATA28(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA27(__VA_ARGS__))

#define DK_SET_DATA29(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA28(__VA_ARGS__))

#define DK_SET_DATA30(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA29(__VA_ARGS__))

#define DK_SET_DATA31(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA30(__VA_ARGS__))

#define DK_SET_DATA32(ty, ...)  \
DK_SET_DATA_IMPL(ty)	\
DK_EXPAND(DK_SET_DATA31(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME_IMPL(fields)								\
if ((res = fields::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))	\
	return res;

#define DK_METADATA_GET_BY_NAME0 return res;
#define DK_METADATA_GET_BY_NAME1(fields)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_METADATA_GET_BY_NAME0

#define DK_METADATA_GET_BY_NAME2(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME1(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME3(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME2(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME4(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME3(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME5(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME4(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME6(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME5(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME7(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME6(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME8(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME7(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME9(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME8(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME10(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME9(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME11(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME10(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME12(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME11(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME13(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME12(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME14(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME13(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME15(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME14(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME16(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME15(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME17(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME16(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME18(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME17(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME19(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME18(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME20(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME19(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME21(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME20(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME22(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME21(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME23(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME22(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME24(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME23(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME25(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME24(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME26(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME25(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME27(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME26(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME28(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME27(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME29(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME28(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME30(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME29(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME31(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME30(__VA_ARGS__))

#define DK_METADATA_GET_BY_NAME32(fields, ...)\
DK_METADATA_GET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_GET_BY_NAME31(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME_IMPL(fields) \
fields::set(t, name, data) ||

#define DK_METADATA_SET_BY_NAME1(fields)\
fields::set(t, name, data);

#define DK_METADATA_SET_BY_NAME2(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME1(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME3(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME2(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME4(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME3(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME5(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME4(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME6(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME5(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME7(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME6(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME8(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME7(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME9(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME8(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME10(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME9(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME11(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME10(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME12(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME11(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME13(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME12(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME14(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME13(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME15(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME14(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME16(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME15(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME17(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME16(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME18(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME17(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME19(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME18(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME20(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME19(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME21(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME20(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME22(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME21(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME23(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME22(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME24(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME23(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME25(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME24(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME26(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME25(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME27(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME26(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME28(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME27(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME29(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME28(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME30(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME29(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME31(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME30(__VA_ARGS__))

#define DK_METADATA_SET_BY_NAME32(fields, ...)\
DK_METADATA_SET_BY_NAME_IMPL(fields)	\
DK_EXPAND(DK_METADATA_SET_BY_NAME31(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY_IMPL(fields) \
(IFields<type>*)&s_##fields,

#define DK_METADATA_FIELD_ARRAY1(fields)\
(IFields<type>*)&s_##fields

#define DK_METADATA_FIELD_ARRAY2(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY1(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY3(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY2(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY4(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY3(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY5(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY4(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY6(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY5(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY7(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY6(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY8(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY7(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY9(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY8(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY10(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY9(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY11(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY10(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY12(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY11(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY13(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY12(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY14(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY13(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY15(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY14(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY16(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY15(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY17(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY16(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY18(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY17(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY19(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY18(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY20(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY19(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY21(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY20(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY22(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY21(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY23(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY22(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY24(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY23(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY25(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY24(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY26(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY25(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY27(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY26(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY28(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY27(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY29(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY28(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY30(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY29(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY31(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY30(__VA_ARGS__))

#define DK_METADATA_FIELD_ARRAY32(fields, ...)\
DK_METADATA_FIELD_ARRAY_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_ARRAY31(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields) \
fields::s_staticSize +

#define DK_METADATA_FIELD_STATIC_SIZE1(fields)\
fields::s_staticSize;

#define DK_METADATA_FIELD_STATIC_SIZE2(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE1(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE3(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE2(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE4(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE3(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE5(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE4(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE6(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE5(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE7(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE6(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE8(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE7(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE9(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE8(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE10(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE9(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE11(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE10(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE12(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE11(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE13(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE12(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE14(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE13(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE15(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE14(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE16(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE15(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE17(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE16(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE18(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE17(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE19(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE18(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE20(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE19(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE21(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE20(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE22(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE21(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE23(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE22(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE24(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE23(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE25(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE24(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE26(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE25(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE27(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE26(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE28(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE27(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE29(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE28(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE30(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE29(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE31(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE30(__VA_ARGS__))

#define DK_METADATA_FIELD_STATIC_SIZE32(fields, ...)\
DK_METADATA_FIELD_STATIC_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_STATIC_SIZE31(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields) \
fields::ComputeTotalSize(t) +

#define DK_METADATA_FIELD_TOTAL_SIZE1(fields)\
fields::ComputeTotalSize(t);

#define DK_METADATA_FIELD_TOTAL_SIZE2(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE1(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE3(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE2(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE4(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE3(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE5(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE4(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE6(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE5(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE7(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE6(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE8(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE7(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE9(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE8(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE10(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE9(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE11(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE10(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE12(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE11(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE13(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE12(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE14(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE13(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE15(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE14(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE16(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE15(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE17(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE16(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE18(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE17(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE19(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE18(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE20(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE19(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE21(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE20(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE22(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE21(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE23(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE22(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE24(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE23(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE25(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE24(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE26(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE25(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE27(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE26(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE28(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE27(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE29(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE28(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE30(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE29(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE31(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE30(__VA_ARGS__))

#define DK_METADATA_FIELD_TOTAL_SIZE32(fields, ...)\
DK_METADATA_FIELD_TOTAL_SIZE_IMPL(fields)	\
DK_EXPAND(DK_METADATA_FIELD_TOTAL_SIZE31(__VA_ARGS__))