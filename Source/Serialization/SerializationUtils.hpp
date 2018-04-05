#pragma once

#define LOG_FILE "Serialization.log"

#include <Core/Utils/MacroUtils.hpp>
#include <Core/Utils/VA_ArgsUtils.hpp>
#include <Core/Engine/Types.hpp>
#include <Core/Engine/TypeTraits.hpp>
#include <array>
#include <tuple>
#include <string>
#include <sstream>
#include <vector>

namespace drak {
namespace serialization {

DK_ENUM_CLASS(E_OutputFileType, U8, BINARY, JSON, INI)

template<typename T>
struct MetaData {};

template<typename T>
struct IFields {
	virtual const char* varName(int idx) = 0;
	virtual int varN() = 0;
	virtual size_t totalSizeAllVar() = 0;
	virtual std::tuple<void*, size_t> getVar(T& t, const char* name) = 0;
	virtual bool setVar(T& t, const char* name, void* data) = 0;
};

template<typename T>
static constexpr size_t SizeOfSerializedType() {
	if constexpr(drak::types::IsBaseType_V<std::remove_all_extents_t<T>> ||
		drak::types::IsBaseType_V<T> )
		return sizeof(T);
	else if constexpr (drak::types::IsBaseType_V<std::remove_pointer_t<T>>)
		return sizeof(std::remove_pointer_t<T>) + 1;
	else if constexpr(std::is_array_v<T>)
		return MetaData<std::remove_all_extents_t<T>>::s_totalSize * drak::types::SizeOfArray_V<T>;
	else if constexpr (std::is_pointer_v<T>)
		return MetaData<std::remove_pointer_t<T>>::s_totalSize + 1;
	else if constexpr (std::is_same_v<T, std::string> || !std::is_same_v<T, drak::types::VectorType_T<T>>)
		return 0;
	else
		return MetaData<T>::s_totalSize;
}

template<typename T>
static size_t SizeOfDynamiclyAllocatedType(const T& t) {
	if constexpr (std::is_same_v<T, std::string>)
		return t.size() + sizeof(size_t);
	else if constexpr (!std::is_same_v<T, drak::types::VectorType_T<T>>) {
		size_t size = sizeof(size_t);
		for (auto& x : t) {
			size += SizeOfSerializedType<drak::types::VectorType_T<T>>() +
				SizeOfDynamiclyAllocatedType<drak::types::VectorType_T<T>>(x);
		}
		return size;
	}
	else
		return 0;
}

} // namespace serialization
} // namespace drak

#define DK_POINT_MEMBER(...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_CHECK_FOR_PTR(...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_FOR_PTR, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_SIZEOF_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

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

#define DK_SIZEOF_TYPE_IMPL(t) \
if(!strcmp(str, #t))	\
return drak::serialization::SizeOfSerializedType<TYPEOF(type::t)>();

#define DK_SIZEOF_TYPE0 return 0;
#define DK_SIZEOF_TYPE1(t)\
DK_SIZEOF_TYPE_IMPL(t)

#define DK_SIZEOF_TYPE2(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE1(__VA_ARGS__))

#define DK_SIZEOF_TYPE3(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE2(__VA_ARGS__))

#define DK_SIZEOF_TYPE4(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE3(__VA_ARGS__))

#define DK_SIZEOF_TYPE5(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE4(__VA_ARGS__))

#define DK_SIZEOF_TYPE6(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE5(__VA_ARGS__))

#define DK_SIZEOF_TYPE7(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE6(__VA_ARGS__))

#define DK_SIZEOF_TYPE8(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE7(__VA_ARGS__))

#define DK_SIZEOF_TYPE9(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE8(__VA_ARGS__))

#define DK_SIZEOF_TYPE10(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE9(__VA_ARGS__))

#define DK_SIZEOF_TYPE11(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE10(__VA_ARGS__))

#define DK_SIZEOF_TYPE12(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE11(__VA_ARGS__))

#define DK_SIZEOF_TYPE13(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE12(__VA_ARGS__))

#define DK_SIZEOF_TYPE14(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE13(__VA_ARGS__))

#define DK_SIZEOF_TYPE15(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE14(__VA_ARGS__))

#define DK_SIZEOF_TYPE16(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE15(__VA_ARGS__))

#define DK_SIZEOF_TYPE17(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE16(__VA_ARGS__))

#define DK_SIZEOF_TYPE18(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE17(__VA_ARGS__))

#define DK_SIZEOF_TYPE19(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE18(__VA_ARGS__))

#define DK_SIZEOF_TYPE20(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE19(__VA_ARGS__))

#define DK_SIZEOF_TYPE21(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE20(__VA_ARGS__))

#define DK_SIZEOF_TYPE22(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE21(__VA_ARGS__))

#define DK_SIZEOF_TYPE23(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE22(__VA_ARGS__))

#define DK_SIZEOF_TYPE24(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE23(__VA_ARGS__))

#define DK_SIZEOF_TYPE25(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE24(__VA_ARGS__))

#define DK_SIZEOF_TYPE26(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE25(__VA_ARGS__))

#define DK_SIZEOF_TYPE27(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE26(__VA_ARGS__))

#define DK_SIZEOF_TYPE28(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE27(__VA_ARGS__))

#define DK_SIZEOF_TYPE29(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE28(__VA_ARGS__))

#define DK_SIZEOF_TYPE30(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE29(__VA_ARGS__))

#define DK_SIZEOF_TYPE31(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
DK_EXPAND(DK_SIZEOF_TYPE30(__VA_ARGS__))

#define DK_SIZEOF_TYPE32(t, ...)\
DK_SIZEOF_TYPE_IMPL(t)	\
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

#define DK_ADD_TAB(x)			\
for (int i = 0; i < x; ++i)		\
	ss << "\t";

#define DK_SERIALIZE_FUNC_BEGIN																	\
template<bool completeDisplay = false>															\
static std::stringstream& serialize(std::stringstream& ss, const type& t, int recursionLevel = 0) {	\
DK_ADD_TAB(recursionLevel)																		\
ss << "Class " << typeName() << "\n";

#define DK_SERIALIZE_FUNC_END				\
DK_ADD_TAB(recursionLevel)					\
ss << "EndClass" << typeName() << "\n";	\
return ss;									\
}

#define DK_SERIALIZE_1_FIELDS(fields1)												\
static constexpr std::array<IFields<type>*, 1> s_fields								\
{ (IFields<type>*)&s_##fields1 };														\
static constexpr std::array<constexpr const char*, 1> s_fieldName									\
{ DK_STRINGIZE(s_##fields1) };												\
static constexpr size_t s_totalSize =													\
fields1::s_totalSize;																	\
static size_t ComputeTotalSize(const type& t) {\
return fields1::ComputeTotalSize(t);	\
}\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
}																						\
static std::tuple<char*, size_t> GetAllBinaryData(const type& t){										\
size_t size1 = ComputeTotalSize(t);														\
char* data = new char[size1];										\
memcpy(data, fields1::BinaryData(t), fields1::ComputeTotalSize(t));																\
return std::make_tuple(data, size1);																\
}																									\
static std::tuple<void*, size_t> get(const type& t, const char* name){									\
std::tuple<void*, size_t> res;																	\
if ((res = fields1::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))				\
return res;																						\
return res;																						\
}																								\
static bool set(type& t, const char* name, void* data){											\
return fields1::set(t, name, data);										\
}																									\
static type Create(const char* c_str) {														\
	type t;																					\
	SetAllBinaryData(t, c_str);																\
	return t;																				\
}																						\
static type* CreateNew(const char* c_str) {														\
	type* t = new type;																					\
	SetAllBinaryData(*t, c_str);																\
	return t;																				\
}																						\
DK_SERIALIZE_FUNC_BEGIN																\
fields1::serialize<completeDisplay>(t, ss, recursionLevel);		\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN1					\
fields1::deserialize(ss, t);			\
DK_DESERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN2					\
fields1::deserialize(ss, t);			\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_2_FIELDS(fields1, fields2)										\
static constexpr std::array<IFields<type>*, 2> s_fields								\
{ (IFields<type>*)&s_##fields1, (IFields<type>*)&s_##fields2 };				\
static constexpr std::array<constexpr const char*, 2> s_fieldName									\
{ DK_STRINGIZE(s_##fields1), DK_STRINGIZE(s_##fields2) };												\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize;														\
static size_t ComputeTotalSize(const type& t) {\
return fields1::ComputeTotalSize(t) + \
fields2::ComputeTotalSize(t);	\
}\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
fields2::SetEveryData(t, data + fields1::ComputeTotalSize(t));									\
}																						\
static std::tuple<char*, size_t> GetAllBinaryData(const type& t){										\
size_t size1 = ComputeTotalSize(t), size2 = fields1::ComputeTotalSize(t);														\
char* data = new char[size1];										\
memcpy(data, fields1::BinaryData(t), size2);																\
memcpy(data + size2, fields2::BinaryData(t), fields2::ComputeTotalSize(t)) ;									\
return std::make_tuple(data, size1);																\
}																									\
static std::tuple<void*, size_t> get(const type& t, const char* name){									\
std::tuple<void*, size_t> res;																	\
if ((res = fields1::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))				\
return res;																						\
else if ((res = fields2::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))			\
return res;																						\
return res;																						\
}																								\
static bool set(type& t, const char* name, void* data){											\
return fields1::set(t, name, data) || fields2::set(t, name, data);										\
}																									\
static type Create(const char* c_str) {														\
	type t;																					\
	SetAllBinaryData(t, c_str);																\
	return t;																				\
}																						\
static type* CreateNew(const char* c_str) {														\
	type* t = new type;																					\
	SetAllBinaryData(*t, c_str);																\
	return t;																				\
}																						\
DK_SERIALIZE_FUNC_BEGIN																\
fields1::serialize<completeDisplay>(t, ss, recursionLevel);		\
fields2::serialize<completeDisplay>(t, ss, recursionLevel);	\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN1					\
fields1::deserialize(ss, t);			\
fields2::deserialize(ss, t);			\
DK_DESERIALIZE_FUNC_END					\
DK_DESERIALIZE_FUNC_BEGIN2					\
fields1::deserialize(ss, t);			\
fields2::deserialize(ss, t);			\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_3_FIELDS(fields1, fields2, fields3)								\
static constexpr std::array<IFields<type>*, 3> s_fields									\
{ (IFields<type>*)&s_##fields1, (IFields<type>*)&s_##fields2, \
(IFields<type>*)&s_##fields3 };												\
static constexpr std::array<constexpr const char*, 3> s_fieldName									\
{ DK_STRINGIZE(s_##fields1), DK_STRINGIZE(s_##fields2), \
DK_STRINGIZE(s_##fields3) };												\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize + \
fields3::s_totalSize;														\
static size_t ComputeTotalSize(const type& t) {\
return fields1::ComputeTotalSize(t) + \
fields2::ComputeTotalSize(t) + \
fields3::ComputeTotalSize(t);	\
}\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
fields2::SetEveryData(t, data + fields1::ComputeTotalSize(t));									\
fields3::SetEveryData(t, data + fields1::ComputeTotalSize(t) + fields2::ComputeTotalSize(t));	\
}																									\
static std::tuple<char*, size_t> GetAllBinaryData(const type& t){										\
size_t size1 = ComputeTotalSize(t), size2 = fields1::ComputeTotalSize(t),				\
size3 = fields2::ComputeTotalSize(t);														\
char* data = new char[size1];										\
memcpy(data, fields1::BinaryData(t), size2);																\
memcpy(data + size2, fields2::BinaryData(t), size3) ;									\
memcpy(data + size2 + size3,																\
fields3::BinaryData(t), fields3::ComputeTotalSize(t));	\
return std::make_tuple(data, size1);																\
}																									\
static std::tuple<void*, size_t> get(const type& t, const char* name){									\
std::tuple<void*, size_t> res;																	\
if ((res = fields1::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))				\
return res;																						\
else if ((res = fields2::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))			\
return res;																						\
else if ((res = fields3::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))		\
return res;																						\
return res;																						\
}																								\
static bool set(type& t, const char* name, void* data){											\
return fields1::set(t, name, data) || fields2::set(t, name, data) ||fields3::set(t, name, data);				\
}																									\
static type Create(const char* c_str) {														\
	type t;																					\
	SetAllBinaryData(t, c_str);																\
	return t;																				\
}																						\
static type* CreateNew(const char* c_str) {														\
	type* t = new type;																					\
	SetAllBinaryData(*t, c_str);																\
	return t;																				\
}																						\
DK_SERIALIZE_FUNC_BEGIN																	\
fields1::serialize<completeDisplay>(t, ss, recursionLevel);		\
fields2::serialize<completeDisplay>(t, ss, recursionLevel);	\
fields3::serialize<completeDisplay>(t, ss, recursionLevel);	\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN1					\
fields1::deserialize(ss, t);			\
fields2::deserialize(ss, t);			\
fields3::deserialize(ss, t);		\
DK_DESERIALIZE_FUNC_END				\
DK_DESERIALIZE_FUNC_BEGIN2					\
fields1::deserialize(ss, t);			\
fields2::deserialize(ss, t);			\
fields3::deserialize(ss, t);		\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_ALL																\
static constexpr std::array<IFields<type>*, 4> s_fields									\
{ (IFields<type>*)&s_PublicFields, (IFields<type>*)&s_PrivateFields,					\
(IFields<type>*)&s_PublicStaticFields, (IFields<type>*)&s_PrivateStaticFields };		\
static constexpr std::array<constexpr const char*, 4> s_fieldName									\
{ #s_PublicFields, #s_PrivateFields,					\
#s_PublicStaticFields, #s_PrivateStaticFields };		\
static constexpr size_t s_totalSize =													\
PublicFields::s_totalSize +																\
PrivateFields::s_totalSize +															 \
PublicStaticFields::s_totalSize +														\
PrivateStaticFields::s_totalSize;														\
static size_t ComputeTotalSize(const type& t) {\
return PublicFields::ComputeTotalSize(t) + \
PrivateFields::ComputeTotalSize(t) + \
PublicStaticFields::ComputeTotalSize(t) + \
PrivateStaticFields::ComputeTotalSize(t);	\
}\
static void SetAllBinaryData(type& t, const char* data){															\
PublicFields::SetEveryData(t, data);																\
PrivateFields::SetEveryData(t, data + PublicFields::ComputeTotalSize(t));									\
PublicStaticFields::SetEveryData(t, data + PublicFields::ComputeTotalSize(t) +  PrivateFields::ComputeTotalSize(t));	\
PrivateStaticFields::SetEveryData(t, data + PublicFields::ComputeTotalSize(t) +								\
PrivateFields::ComputeTotalSize(t) + PublicStaticFields::ComputeTotalSize(t));									\
}																									\
static std::tuple<char*, size_t> GetAllBinaryData(const type& t){										\
size_t size1 = ComputeTotalSize(t), size2 = PublicFields::ComputeTotalSize(t),				\
size3 = PrivateFields::ComputeTotalSize(t), size4 = PublicStaticFields::ComputeTotalSize(t);														\
char* data = new char[ComputeTotalSize(t)];										\
memcpy(data, PublicFields::BinaryData(t), size2);																\
memcpy(data + size2, PrivateFields::BinaryData(t), size3) ;									\
memcpy(data + size2 + size3, PublicStaticFields::BinaryData(t), size4);	\
memcpy(data + size2 + size3 + size4, PrivateStaticFields::BinaryData(t),  PrivateStaticFields::ComputeTotalSize(t));	\
return std::make_tuple(data, size1);																\
}																									\
static std::tuple<void*, size_t> get(const type& t, const char* name){									\
std::tuple<void*, size_t> res;																	\
if ((res = PublicFields::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))				\
return res;																						\
else if ((res = PrivateFields::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))			\
return res;																						\
else if ((res = PublicStaticFields::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))		\
return res;																						\
else if ((res = PrivateStaticFields::get(t, name)) != std::tuple<void*, size_t>(nullptr, 0))	\
return res;																						\
return res;																						\
}																								\
static bool set(type& t, const char* name, void* data){											\
return PublicFields::set(t, name, data) || PrivateFields::set(t, name, data) ||					\
PublicStaticFields::set(t, name, data) || PrivateStaticFields::set(t, name, data);				\
}																								\
static type Create(const char* c_str) {														\
	type t;																					\
	SetAllBinaryData(t, c_str);																\
	return t;																				\
}																						\
static type* CreateNew(const char* c_str) {														\
	type* t = new type;																					\
	SetAllBinaryData(*t, c_str);																\
	return t;																				\
}																						\
DK_SERIALIZE_FUNC_BEGIN																	\
PublicFields::serialize<completeDisplay>(t, ss, recursionLevel);					\
PrivateFields::serialize<completeDisplay>(t, ss, recursionLevel);						\
PublicStaticFields::serialize<completeDisplay>(t, ss, recursionLevel);						\
PrivateStaticFields::serialize<completeDisplay>(t, ss, recursionLevel);	\
DK_SERIALIZE_FUNC_END																								\
DK_DESERIALIZE_FUNC_BEGIN1					\
PublicFields::deserialize(ss, t);			\
PrivateFields::deserialize(ss, t);			\
PublicStaticFields::deserialize(ss, t);		\
PrivateStaticFields::deserialize(ss, t);	\
DK_DESERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN2					\
PublicFields::deserialize(ss, t);			\
PrivateFields::deserialize(ss, t);			\
PublicStaticFields::deserialize(ss, t);		\
PrivateStaticFields::deserialize(ss, t);	\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_PUBLIC_FIELDS													\
DK_SERIALIZE_1_FIELDS(PublicFields)

#define DK_SERIALIZE_PRIVATE_FIELDS													\
DK_SERIALIZE_1_FIELDS(PrivateFields)

#define DK_SERIALIZE_PUBLIC_STATIC_FIELDS												\
DK_SERIALIZE_1_FIELDS(PublicStaticFields)

#define DK_SERIALIZE_PRIVATE_STATIC_FIELDS												\
DK_SERIALIZE_1_FIELDS(PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PRIVATE_FIELDS											\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateFields)

#define DK_SERIALIZE_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELDS										\
DK_SERIALIZE_2_FIELDS(PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PUBLIC_STATIC_FIELDS								\
DK_SERIALIZE_2_FIELDS(PublicFields, PublicStaticFields)

#define DK_SERIALIZE_PRIVATE_AND_PRIVATE_STATIC_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PRIVATE_AND_PUBLIC_STATIC_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PublicStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PRIVATE_STATIC_FIELDS							\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PRIVATE_AND_PRIVATE_STATIC_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_AND_PUBLIC_STATIC_AND_PRIVATE_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateFields)

#define DK_SERIALIZE_PRIVATE_AND_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PrivateFields, PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_IMPL(ty)										\
DK_ADD_TAB(recursionLevel)											\
ss << "\t\t" << typeid(t.ty).name() << " "#ty;						\
serialize<TYPEOF(t.ty), completeDisplay>(ty, ss, recursionLevel);

#define DK_SERIALIZE_IMPL0

#define DK_SERIALIZE_IMPL1(ty)\
DK_SERIALIZE_IMPL(ty)

#define DK_SERIALIZE_IMPL2(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL1(__VA_ARGS__))

#define DK_SERIALIZE_IMPL3(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL2(__VA_ARGS__))

#define DK_SERIALIZE_IMPL4(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL3(__VA_ARGS__))

#define DK_SERIALIZE_IMPL5(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL4(__VA_ARGS__))

#define DK_SERIALIZE_IMPL6(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL5(__VA_ARGS__))

#define DK_SERIALIZE_IMPL7(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL6(__VA_ARGS__))

#define DK_SERIALIZE_IMPL8(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL7(__VA_ARGS__))

#define DK_SERIALIZE_IMPL9(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL8(__VA_ARGS__))

#define DK_SERIALIZE_IMPL10(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL9(__VA_ARGS__))

#define DK_SERIALIZE_IMPL11(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL10(__VA_ARGS__))

#define DK_SERIALIZE_IMPL12(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL11(__VA_ARGS__))

#define DK_SERIALIZE_IMPL13(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL12(__VA_ARGS__))

#define DK_SERIALIZE_IMPL14(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL13(__VA_ARGS__))

#define DK_SERIALIZE_IMPL15(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL14(__VA_ARGS__))

#define DK_SERIALIZE_IMPL16(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL15(__VA_ARGS__))

#define DK_SERIALIZE_IMPL17(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL16(__VA_ARGS__))

#define DK_SERIALIZE_IMPL18(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL17(__VA_ARGS__))

#define DK_SERIALIZE_IMPL19(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL18(__VA_ARGS__))

#define DK_SERIALIZE_IMPL20(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL19(__VA_ARGS__))

#define DK_SERIALIZE_IMPL21(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL20(__VA_ARGS__))

#define DK_SERIALIZE_IMPL22(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL21(__VA_ARGS__))

#define DK_SERIALIZE_IMPL23(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL22(__VA_ARGS__))

#define DK_SERIALIZE_IMPL24(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL23(__VA_ARGS__))

#define DK_SERIALIZE_IMPL25(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL24(__VA_ARGS__))

#define DK_SERIALIZE_IMPL26(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL25(__VA_ARGS__))

#define DK_SERIALIZE_IMPL27(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL26(__VA_ARGS__))

#define DK_SERIALIZE_IMPL28(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL27(__VA_ARGS__))

#define DK_SERIALIZE_IMPL29(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL28(__VA_ARGS__))

#define DK_SERIALIZE_IMPL30(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL29(__VA_ARGS__))

#define DK_SERIALIZE_IMPL31(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL30(__VA_ARGS__))

#define DK_SERIALIZE_IMPL32(ty, ...)\
DK_SERIALIZE_IMPL(ty)\
DK_EXPAND(DK_SERIALIZE_IMPL31(__VA_ARGS__))

#define DK_NON_SERIALIZED_OBJECT \
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(type)						\
friend drak::serialization::MetaData<type>;				\
static constexpr bool s_serialized = true;				\
public:													\
using MetaData = drak::serialization::MetaData<type>;	\
template<bool completeDisplay = false>															\
std::stringstream& serialize(std::stringstream& ss) {								\
return MetaData::serialize<completeDisplay>(ss, *this, 0);	\
}																							\
template<bool completeDisplay = false>															\
std::stringstream serialize() {																			\
return MetaData::serialize<completeDisplay>(std::stringstream(), *this, 0);	\
}																										\
template<typename T = void>																					\
std::tuple<const char*, size_t> serialize() {														\
return MetaData::GetAllBinaryData(*this);	\
}

#define DK_METADATA_BEGIN(ty)								\
template<>													\
struct drak::serialization::MetaData<ty> {					\
using type = ty;											\
static constexpr const char* typeName() { return #ty; };	\
static ty create() { return ty(); };						\
static ty* createNew() { return new ty; };					\

#define DK_METADATA_FIELDS(fieldName, ...)												\
struct fieldName : public drak::serialization::IFields<type> {							\
private:																						\
template<typename T>																				\
static size_t SetData(T& t, const char* c_str, size_t offset) 	{										\
	if constexpr (drak::types::IsBaseType_V<T>){														\
		memcpy(&(t), c_str + offset, drak::serialization::SizeOfSerializedType<T>());				\
		return drak::serialization::SizeOfSerializedType<T>();									\
	}			\
	else if constexpr (drak::types::IsBaseType_V<std::remove_all_extents_t<T>> && std::is_array_v<T>)	{				\
		memcpy((t), c_str + offset, drak::serialization::SizeOfSerializedType<T>());				\
		return drak::serialization::SizeOfSerializedType<T>();			\
	}							\
	else if constexpr(drak::types::IsBaseType_V<std::remove_pointer_t<T>> && std::is_pointer_v<T>){						\
		char isAllocated = *(c_str + offset); \
		if(isAllocated){				\
			t = new std::remove_pointer_t<T>();																									\
			memcpy(t, c_str + offset + 1, sizeof(std::remove_pointer_t<T>));										\
			return drak::serialization::SizeOfSerializedType<T>();												\
		}																					\
		else{																							\
			t = nullptr;																		\
			return 1;																\
		}																									\
	}																								\
	else if constexpr (!std::is_same_v<T, drak::types::VectorType_T<T>>) {				\
		size_t size = *(size_t*)(c_str + offset);														\
		const char* temp = c_str + offset + sizeof(size_t);													\
		t.reserve(size);																				\
		for(int i = 0; i < size; ++i) {																	\
			drak::types::VectorType_T<T> data;															\
			temp += SetData<drak::types::VectorType_T<T>>(data, temp, 0);								\
			t.emplace_back(data);																		\
		}																								\
		return temp - (c_str + offset);																	\
	}																									\
	else if constexpr (std::is_same_v<T, std::string>) {															\
		size_t size = *(size_t*)(c_str + offset);						\
		t.insert(0, c_str + offset + sizeof(size_t), size );			\
		return size + sizeof(size_t);									\
	}																														\
	else if constexpr(!std::is_array_v<T> && !std::is_pointer_v<T> && !drak::types::IsBaseType_V<T>)	{\
		MetaData<T>::SetAllBinaryData(t, c_str + offset);		\
		return MetaData<T>::ComputeTotalSize(t);		\
	}			\
	else if constexpr(std::is_array_v<T> && !drak::types::IsBaseType_V<T>) {		\
		size_t currentSize = 0; \
		for(int i = 0, size = drak::types::SizeOfArray_V<T>; i < size;currentSize += MetaData<std::remove_all_extents_t<T>>::ComputeTotalSize(t[i]), ++i)	\
			MetaData<std::remove_all_extents_t<T>>::SetAllBinaryData(t[i],\
		c_str + (offset + currentSize));		\
		return currentSize;		\
	}			\
	else if constexpr(std::is_pointer_v<T> && !drak::types::IsBaseType_V<T>) {		\
		char isAllocated = *(char*)(c_str + offset); \
		if (isAllocated) {	\
			t = new std::remove_pointer_t<T>();			\
			MetaData<std::remove_pointer_t<T>>::SetAllBinaryData(*t, c_str + offset + 1);							\
			return MetaData<std::remove_pointer_t<T>>::ComputeTotalSize(*t) + 1;		\
		}			\
		else {				\
			t = nullptr;				\
			return 1;		\
		}				\
	}																										\
}																								\
template<typename T>																	\
static std::tuple<void*, size_t> GetData(const T& t) {										\
if constexpr (drak::types::IsBaseType_V<T>){											\
	return std::make_tuple<void*, size_t>((void*)&(t), sizeof(T));								\
}																						\
else if constexpr(drak::types::IsBaseType_V<std::remove_all_extents_t<T>>) {\
return std::make_tuple<void*, size_t>((void*)(t), sizeof(std::remove_pointer_t<T>));												\
}																									\
else if constexpr (drak::types::IsBaseType_V<std::remove_pointer_t<T>>){\
char* data = new char[sizeof(T) + 1], size;								\
if (size = (bool)t) {															\
	memcpy(data, &size, 1);												\
	memcpy(data + 1, t, sizeof(t));										\
	return std::make_tuple(data, sizeof(T) + 1);						\
}																		\
else{																	\
	memset(data, 0, 1);													\
	return std::make_tuple(data, 1);									\
}																			\
}																		\
else if constexpr(std::is_same_v<T, std::string>){							\
	size_t size = t.size();													\
	std::string temp = t;													\
	temp.insert(0, (const char*)&size, sizeof(size_t));						\
	char* c_ptr = new char[temp.size()];									\
	memcpy(c_ptr, temp.c_str(), temp.size());							\
	return std::make_tuple<void*, size_t>((void*)c_ptr, temp.size());	\
}																		\
else if constexpr (!std::is_same_v<T, drak::types::VectorType_T<T>>) {												\
	size_t size = t.size(), size2 = 0;																										\
	std::vector<std::tuple<void*, size_t>> data;																				\
	data.reserve(t.size());																										\
	for(auto& x : t) {																											\
		data.emplace_back(GetData<TYPEOF(x)>(x));																				\
		size2 += std::get<1>(data.back());																						\
	}																															\
	char* binarydata = new char[size2 + sizeof(size_t)];																				\
	memcpy(binarydata, &size, sizeof(size_t));																						\
	char* temp = binarydata + sizeof(size_t);																						\
	for(auto& x : data) {																										\
		memcpy(temp, std::get<0>(x), std::get<1>(x));																			\
		temp += std::get<1>(x);																									\
		if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<drak::types::VectorType_T<T>>>)\
		delete[] std::get<0>(x);																					\
	}																													\
	return std::make_tuple(binarydata, temp - binarydata);										\
}																											\
else if constexpr(!std::is_array_v<T> && !std::is_pointer_v<T> && !drak::types::IsBaseType_V<T> &&	\
std::is_same_v<T, drak::types::VectorType_T<T>>) {							\
	return std::make_tuple<void*, size_t>((void*)std::get<0>(MetaData<T>::GetAllBinaryData(t)),	\
	MetaData<T>::ComputeTotalSize(t));		\
}																						\
else if constexpr(std::is_array_v<T> && !drak::types::IsBaseType_V<T>){																					\
	size_t totalArraySize = 0;					\
	for (auto& x : t)							\
		totalArraySize += MetaData<std::remove_all_extents_t<T>>::ComputeTotalSize(x);\
	char* c_str = new char[totalArraySize], *temp;	\
	for(int i = 0, size = SizeOfArray_V<T>, currentSize = 0; i < size; currentSize += (int)MetaData<std::remove_all_extents_t<T>>::ComputeTotalSize(t[i]), ++i)	{							\
		temp = std::get<0>(MetaData<std::remove_all_extents_t<T>>::GetAllBinaryData(t[i]));\
		memcpy(c_str + (currentSize),	\
			temp, MetaData<std::remove_all_extents_t<T>>::ComputeTotalSize(t[i]));\
		delete[] temp;																	\
}																						\
return std::make_tuple(c_str, totalArraySize);		\
}																						\
else if constexpr(std::is_pointer_v<T> && !drak::types::IsBaseType_V<T> &&			\
std::is_same_v<T, drak::types::VectorType_T<T>>){													\
if((bool)t) {			\
char* data = new char[MetaData<std::remove_pointer_t<T>>::ComputeTotalSize(*t) + 1], size = 1;	\
memcpy(data, &size, 1);		\
memcpy(data + 1, std::get<0>(MetaData<std::remove_pointer_t<T>>::GetAllBinaryData(*t)), \
MetaData<std::remove_pointer_t<T>>::ComputeTotalSize(*t)); \
return std::make_tuple(data, MetaData<std::remove_pointer_t<T>>::ComputeTotalSize(*t) + 1);			\
}					\
else {				\
	char* data = new char[1]; \
	memset(data, 0, 1);		\
	return std::make_tuple(data, 1);		\
}											\
}																						\
}																						\
public:																					\
static constexpr std::array<constexpr const char*, DK_ARGS_N(__VA_ARGS__)> s_varName =	\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };								\
static constexpr auto s_var =															\
std::make_tuple(DK_REVERSE_VA_ARGS(DK_POINT_MEMBER(__VA_ARGS__)));						\
static constexpr int s_varN = DK_ARGS_N(__VA_ARGS__);									\
static constexpr size_t s_totalSize = DK_SIZEOF_VA_ARGS(__VA_ARGS__);						\
static size_t ComputeTotalSize(const type& t) {												\
	return s_totalSize + DK_EXPAND(DK_CONCAT(DK_DYNAMIC_SIZE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__));\
};																						\
virtual const char* varName(int idx)override{											\
	return s_varName[idx];																\
};																						\
virtual int varN() override {															\
	return s_varN;																		\
};																						\
virtual size_t totalSizeAllVar() override {												\
	return s_totalSize;																	\
};																						\
virtual std::tuple<void*, size_t> getVar(type& t, const char* str)override {			\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
virtual bool setVar(type& t, const char* name, void* data) override {					\
	DK_EXPAND(DK_CONCAT(DK_SET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
	return false;																		\
}																						\
static std::tuple<void*, size_t> get(const type& t, const char* str) {						\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
static size_t SizeOf(const char* str) {													\
	DK_EXPAND(DK_CONCAT(DK_SIZEOF_TYPE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))			\
}																						\
static bool set(type& t, const char* name, void* data) {								\
	DK_EXPAND(DK_CONCAT(DK_SET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
	return false;																		\
}																						\
static const char* typeNameOf(const char* str){											\
	DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
DK_SET_EVERY_DATA_FUNC(__VA_ARGS__)														\
static type& deserialize(std::stringstream& ss, type& t) {								\
DK_DESERIALIZE_LOOP_IMPL(fieldName)														\
return t;																				\
}																						\
template<typename T, bool completeDisplay>															\
static void serialize(const T& t, std::stringstream& ss, int recursionLevel) {							\
if constexpr (drak::types::IsBaseType_V<T> ||														\
		(std::is_array_v<T> &&																		\
		drak::types::IsBaseType_V<T>)) {															\
	DK_ADD_TAB(recursionLevel)																		\
	ss << " Size " << sizeof(t) <<" Binary ";														\
	const char* data;																				\
	if constexpr (std::is_array_v<T>)																\
		data = (const char*)t;																		\
	else																							\
		data = (const char*)&t																		\
	for (size_t i = 0; i < sizeof(t); ++i) {														\
			ss << (data)[i];																		\
	}																								\
	ss << "\n";																						\
}																									\
else if constexpr (!drak::types::IsBaseType_V<T> &&	std::is_array_v<T>){							\
	DK_ADD_TAB(recursionLevel)																		\
	ss <<" :\n";																					\
for(size_t i = 0, size = drak::types::SizeOfArray_V<T> ; i < size; ++i ) {							\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << "[" << i << "] : \n";															\
	MetaData<std::remove_all_extents_t<T>>::serialize<completeDisplay>								\
		(ss, ty[i], recursionLevel + 2);															\
}																									\
}																									\
else {																								\
	DK_ADD_TAB(recursionLevel)																		\
	ss << ":\n";																					\
	MetaData<T>::serialize<completeDisplay>(ss, t, recursionLevel + 2);								\
}																									\
}																									\
template<bool completeDisplay>															\
static std::stringstream& serialize(const type& t, std::stringstream& ss, int recursionLevel){\
DK_ADD_TAB(recursionLevel)																\
ss << "\t"#fieldName << "\n";															\
if constexpr (completeDisplay) {														\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_IMPL,  DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))			\
DK_ADD_TAB(recursionLevel)																\
ss << "\tEnd"#fieldName << "\n";														\
}																						\
else {																					\
DK_ADD_TAB(recursionLevel)																\
ss << "\t\t"#fieldName << " Size " << ComputeTotalSize(t) <<									\
" Binary ";																				\
char* data = BinaryData(t);																\
for(int i = 0, size = (int)ComputeTotalSize(t); i < size; ++i)										\
	ss << data[i];																			\
delete[] data;																			\
ss << "\n";																				\
DK_ADD_TAB(recursionLevel)																\
ss << "\tEnd"#fieldName << "\n";														\
}																						\
return ss;																				\
}																						\
DK_FIELD_BINARY_FUNC(__VA_ARGS__)														\
};																						\
public :																				\
static constexpr fieldName s_##fieldName = fieldName();

#define DK_PUBLIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicFields, __VA_ARGS__)

#define DK_PRIVATE_FIELDS(...)\
DK_METADATA_FIELDS(PrivateFields, __VA_ARGS__)

#define DK_PUBLIC_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicStaticFields, __VA_ARGS__)

#define DK_PRIVATE_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PrivateStaticFields, __VA_ARGS__)

#define DK_METADATA_END																			\
static bool AreEqual(const type& t1, const type& t2) {														\
std::tuple<char*, size_t> binary1 = GetAllBinaryData(t1), binary2 = GetAllBinaryData(t2);		\
bool res = std::get<1>(GetAllBinaryData(t1)) == std::get<1>(GetAllBinaryData(t2)) &&			\
!strcmp(std::get<0>(GetAllBinaryData(t1)), std::get<0>(GetAllBinaryData(t2)));					\
delete[] std::get<0>(GetAllBinaryData(t1));														\
delete[] std::get<0>(GetAllBinaryData(t2));														\
return res;																						\
}																								\
};

#define DK_DESERIALIZE_FUNC_BEGIN1				\
static type& deserialize(type& t, std::stringstream& ss) {\
DK_CHECK_CLASS

#define DK_DESERIALIZE_FUNC_BEGIN2				\
static type deserialize(std::stringstream& ss) {\
type t = create();								\
DK_CHECK_CLASS




#define DK_CHECK_CLASS															\
std::string str;																\
while (ss >> str) {																\
if (str == "Class") {															\
ss >> str;																		\
if (str == typeName())															\
break;																			\
else {																			\
Logbook::Log(Logbook::EOutput::BOTH,											\
LOG_FILE, "MetaData : %s passed but %s should be passed instead !!",			\
str, typeName());																\
exit(1);																		\
}																				\
}																				\
}

#define DK_DESERIALIZE_FUNC_END	\
return t;						\
}

#define DK_DESERIALIZE_LOOP_IMPL(fields)						\
std::string str;												\
while (ss >> str) {												\
	if (str == #fields) {										\
		(ss >> str);											\
		bool completeData = (str != #fields);					\
		size_t binarySize = 0;									\
		int i = 0;												\
		while (str != "End"#fields) {							\
			ss >> str;											\
			if (str == "Size") {								\
				ss >> binarySize;								\
				char* c_str = new char[binarySize];				\
				ss.seekg(8, std::ios::cur);						\
				ss.read(c_str, binarySize);						\
				if(!completeData)								\
					SetEveryData(t, c_str);						\
				else 											\
					set(t, s_varName[i], (void*)c_str);			\
				delete[] c_str;									\
				++i;											\
			}													\
		}														\
		break;													\
	}															\
}

#define DK_SET_EVERY_DATA_FUNC(...)	\
DK_SET_EVERY_DATA_IMPL_FUNC				\
static void SetEveryData(type& t, const char* c_str) {	\
	size_t offset = 0;										\
DK_EXPAND(DK_CONCAT(DK_SET_EVERY_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_SET_EVERY_DATA_IMPL_FUNC \
template<typename T>\
static void SetEveryDataImpl(T& t, const char* c_str, size_t& offset) {\
	offset += SetData<T>(t, c_str, offset); \
}
#define DK_SET_EVERY_DATA0
#define DK_SET_EVERY_DATA1(ty)			\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);

#define DK_SET_EVERY_DATA2(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA1(__VA_ARGS__))

#define DK_SET_EVERY_DATA3(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA2(__VA_ARGS__))

#define DK_SET_EVERY_DATA4(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA3(__VA_ARGS__))

#define DK_SET_EVERY_DATA5(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA4(__VA_ARGS__))

#define DK_SET_EVERY_DATA6(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA5(__VA_ARGS__))

#define DK_SET_EVERY_DATA7(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA6(__VA_ARGS__))

#define DK_SET_EVERY_DATA8(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA7(__VA_ARGS__))

#define DK_SET_EVERY_DATA9(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA8(__VA_ARGS__))

#define DK_SET_EVERY_DATA10(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA9(__VA_ARGS__))

#define DK_SET_EVERY_DATA11(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA10(__VA_ARGS__))

#define DK_SET_EVERY_DATA12(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA11(__VA_ARGS__))

#define DK_SET_EVERY_DATA13(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA12(__VA_ARGS__))

#define DK_SET_EVERY_DATA14(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA13(__VA_ARGS__))

#define DK_SET_EVERY_DATA15(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA14(__VA_ARGS__))

#define DK_SET_EVERY_DATA16(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA15(__VA_ARGS__))

#define DK_SET_EVERY_DATA17(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA16(__VA_ARGS__))

#define DK_SET_EVERY_DATA18(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA17(__VA_ARGS__))

#define DK_SET_EVERY_DATA19(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA18(__VA_ARGS__))

#define DK_SET_EVERY_DATA20(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA19(__VA_ARGS__))

#define DK_SET_EVERY_DATA21(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA20(__VA_ARGS__))

#define DK_SET_EVERY_DATA22(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA21(__VA_ARGS__))

#define DK_SET_EVERY_DATA23(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA22(__VA_ARGS__))

#define DK_SET_EVERY_DATA24(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA23(__VA_ARGS__))

#define DK_SET_EVERY_DATA25(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA24(__VA_ARGS__))

#define DK_SET_EVERY_DATA26(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA25(__VA_ARGS__))

#define DK_SET_EVERY_DATA27(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA26(__VA_ARGS__))

#define DK_SET_EVERY_DATA28(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA27(__VA_ARGS__))

#define DK_SET_EVERY_DATA29(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA28(__VA_ARGS__))

#define DK_SET_EVERY_DATA30(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA29(__VA_ARGS__))

#define DK_SET_EVERY_DATA31(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA30(__VA_ARGS__))

#define DK_SET_EVERY_DATA32(ty, ...)	\
SetEveryDataImpl<TYPEOF(t.ty)>(t.ty, c_str, offset);	\
DK_EXPAND(DK_SET_EVERY_DATA31(__VA_ARGS__))

#define DK_FIELD_BINARY_FUNC(...)													\
static char* BinaryData(const type& t) {											\
	char* data = new char[ComputeTotalSize(t)], *data2;							\
	int offset = 0;																	\
	std::tuple<void*, size_t> binary;											\
DK_EXPAND(DK_CONCAT(DK_FIELD_BINARY_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
return data;																	\
}

#define DK_FIELD_BINARY_IMPL(ty)								\
binary = GetData<TYPEOF(t.ty)>((t.ty));				\
data2 = (char*)std::get<0>(binary);				\
memcpy((data + offset), data2, std::get<1>(binary)); \
if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<TYPEOF(t.ty)>>)\
	delete[] data2;												\
offset += (int)std::get<1>(binary);

#define DK_FIELD_BINARY_IMPL0

#define DK_FIELD_BINARY_IMPL1(t)\
DK_FIELD_BINARY_IMPL(t)

#define DK_FIELD_BINARY_IMPL2(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL1(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL3(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL2(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL4(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL3(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL5(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL4(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL6(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL5(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL7(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL6(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL8(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL7(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL9(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL8(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL10(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL9(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL11(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL10(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL12(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL11(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL13(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL12(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL14(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL13(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL15(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL14(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL16(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL15(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL17(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL16(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL18(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL17(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL19(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL18(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL20(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL19(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL21(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL20(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL22(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL21(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL23(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL22(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL24(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL23(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL25(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL24(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL26(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL25(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL27(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL26(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL28(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL27(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL29(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL28(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL30(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL29(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL31(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL30(__VA_ARGS__))

#define DK_FIELD_BINARY_IMPL32(t, ...)\
DK_FIELD_BINARY_IMPL(t)	\
DK_EXPAND(DK_FIELD_BINARY_IMPL31(__VA_ARGS__))

/*
#define DK_PUBLIC_METHODE(type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_publicMethodeName =		\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };
#define DK_PRIVATE_METHODE(type, ...)															\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_privateMethodeName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };
#define DK_PUBLIC_STATIC_METHODE(type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPublicMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };
#define DK_PRIVATE_STATIC_METHODE(type, ...)													\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPrivateMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };*/