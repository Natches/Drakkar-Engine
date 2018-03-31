#pragma once

#define LOG_FILE "Serialization.log"

#include <Core/Utils/MacroUtils.hpp>
#include <Core/Engine/Types.hpp>
#include <Core/Engine/TypeTraits.hpp>

namespace drak {
namespace serialization {

template<typename T>
struct MetaData {};

template<typename T>
struct IFields {
	virtual const char* varName(int idx) = 0;
	virtual int varN() = 0;
	virtual size_t totalSizeAllVar() = 0;
	virtual bool hasDynamiclyAllocatedMemory() = 0;
	virtual std::tuple<void*, size_t> getVar(T& t, const char* str) = 0;
};

} // namespace serialization
} // namespace drak

#define DK_POINT_MEMBER(...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_CHECK_FOR_PTR(...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_FOR_PTR, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_SIZEOF_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_ALL_FIELDS_BINARY_DATA(fields, N)\
DK_EXPAND(DK_CONCAT(DK_ALL_FIELDS_BINARY_DATA, N)(fields, N - 1))

#define DK_POINT_MEMBER_BASE0(...)	__VA_ARGS__
#define DK_POINT_MEMBER_BASE1(t)\
DK_POINT_MEMBER_BASE0(&type::t)

#define DK_POINT_MEMBER1(t, ...)\
DK_POINT_MEMBER_BASE0(__VA_ARGS__, &type::t)

#define DK_POINT_MEMBER_BASE2(t, ...)\
DK_EXPAND(DK_POINT_MEMBER1(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE3(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE2(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE4(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE3(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE5(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE4(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE6(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE5(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE7(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE6(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE8(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE7(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE9(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE8(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE10(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE9(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE11(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE10(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE12(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE11(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE13(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE12(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE14(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE13(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE15(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE14(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE16(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE15(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE17(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE16(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE18(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE17(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE19(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE18(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE20(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE19(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE21(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE20(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE22(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE21(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE23(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE22(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE24(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE23(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE25(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE24(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE26(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE25(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE27(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE26(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE28(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE27(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE29(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE28(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE30(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE29(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE31(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE30(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE32(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE31(__VA_ARGS__, &type::t))

#define DK_GET_DATA_IMPL(ty)	\
if (!strcmp(str, #ty))			\
return getData<TYPEOF(t.ty)>(t.ty);

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
if (!strcmp(name, #ty))	\
SetData<TYPEOF(t.ty)>(t.ty, (const char*)data, 0);

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

#define DK_CHECK_FOR_PTR0
#define DK_CHECK_FOR_PTR1(t)\
CheckForPTR<TYPEOF(type::t)>()	\

#define DK_CHECK_FOR_PTR2(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR1(__VA_ARGS__))

#define DK_CHECK_FOR_PTR3(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR2(__VA_ARGS__))

#define DK_CHECK_FOR_PTR4(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR3(__VA_ARGS__))

#define DK_CHECK_FOR_PTR5(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR4(__VA_ARGS__))

#define DK_CHECK_FOR_PTR6(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR5(__VA_ARGS__))

#define DK_CHECK_FOR_PTR7(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR6(__VA_ARGS__))

#define DK_CHECK_FOR_PTR8(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR7(__VA_ARGS__))

#define DK_CHECK_FOR_PTR9(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR8(__VA_ARGS__))

#define DK_CHECK_FOR_PTR10(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR9(__VA_ARGS__))

#define DK_CHECK_FOR_PTR11(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR10(__VA_ARGS__))

#define DK_CHECK_FOR_PTR12(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR11(__VA_ARGS__))

#define DK_CHECK_FOR_PTR13(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR12(__VA_ARGS__))

#define DK_CHECK_FOR_PTR14(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR13(__VA_ARGS__))

#define DK_CHECK_FOR_PTR15(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR14(__VA_ARGS__))

#define DK_CHECK_FOR_PTR16(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR15(__VA_ARGS__))

#define DK_CHECK_FOR_PTR17(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR16(__VA_ARGS__))

#define DK_CHECK_FOR_PTR18(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR17(__VA_ARGS__))

#define DK_CHECK_FOR_PTR19(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR18(__VA_ARGS__))

#define DK_CHECK_FOR_PTR20(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR19(__VA_ARGS__))

#define DK_CHECK_FOR_PTR21(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR20(__VA_ARGS__))

#define DK_CHECK_FOR_PTR22(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR21(__VA_ARGS__))

#define DK_CHECK_FOR_PTR23(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR22(__VA_ARGS__))

#define DK_CHECK_FOR_PTR24(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR23(__VA_ARGS__))

#define DK_CHECK_FOR_PTR25(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR24(__VA_ARGS__))

#define DK_CHECK_FOR_PTR26(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR25(__VA_ARGS__))

#define DK_CHECK_FOR_PTR27(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR26(__VA_ARGS__))

#define DK_CHECK_FOR_PTR28(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR27(__VA_ARGS__))

#define DK_CHECK_FOR_PTR29(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR28(__VA_ARGS__))

#define DK_CHECK_FOR_PTR30(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR29(__VA_ARGS__))

#define DK_CHECK_FOR_PTR31(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR30(__VA_ARGS__))

#define DK_CHECK_FOR_PTR32(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR31(__VA_ARGS__))

#define DK_SIZEOF_TYPE_IMPL(t) \
if(!strcmp(str, #t))	\
return SizeOfSerializedType<TYPEOF(type::t)>();

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
SizeOfSerializedType<TYPEOF(type::t)>();\

#define DK_SIZEOF_VA_ARGS2(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS1(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS3(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS2(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS4(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS3(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS5(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS4(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS6(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS5(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS7(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS6(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS8(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS7(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS9(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS8(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS10(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS9(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS11(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS10(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS12(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS11(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS13(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS12(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS14(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS13(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS15(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS14(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS16(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS15(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS17(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS16(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS18(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS17(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS19(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS18(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS20(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS19(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS21(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS20(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS22(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS21(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS23(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS22(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS24(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS23(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS25(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS24(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS26(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS25(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS27(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS26(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS28(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS27(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS29(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS28(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS30(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS29(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS31(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS30(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS32(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS31(__VA_ARGS__))


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

#define DK_ALL_FIELDS_BINARY_DATA_FUNC(fields)							\
template<typename T, int N>\
static void AllFieldBinaryData##fields(std::stringstream& ss, type& t) {\
if constexpr (drak::types::IsBaseType_V<std::remove_all_extents_t<T>>) {\
std::tuple<void*, size_t> binary = fields::get(t, fields::s_varName[N]);								\
for (size_t i = 0; i < std::get<1>(binary); ++i) {							\
		ss << ((const char*)std::get<0>(binary))[i];						\
}																			\
}																			\
else if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<T>> && !std::is_array_v<T>){						\
std::tuple<void*, size_t> binary;\
T obj = t.*(std::get<N>(fields::s_var));						\
for(auto f : MetaData<T>::s_fields) {							\
		for(int idxVar = f->varN() - 1, varN = -1; idxVar > varN; --idxVar)	{							\
			binary = f->getVar(obj, f->varName(idxVar));											\
			for (size_t i = 0, size = std::get<1>(binary); i < size; ++i)							\
				ss << ((const char*)std::get<0>(binary))[i];										\
		}																							\
	}																								\
}																									\
else {\
std::tuple<void*, size_t> binary;\
for(size_t idx = 0, arraySize = drak::types::SizeOfArray_V<T>; idx < arraySize; ++idx) {	\
	std::remove_all_extents_t<T>& obj = (t.*(std::get<N>(fields::s_var)))[idx];\
	for(auto f : MetaData<std::remove_all_extents_t<T>>::s_fields) {				\
		for(int idxVar = 0, varN = f->varN(); idxVar < varN; ++idxVar)	{							\
			binary = f->getVar(obj, f->varName(idxVar));			\
			for (size_t i = 0, size = std::get<1>(binary); i < size; ++i)							\
				ss << ((const char*)std::get<0>(binary))[i];										\
		}																							\
	}																								\
}																									\
}																									\
}

#define DK_ALL_FIELDS_BINARY_DATA0(fields)\
ss << "\n";					\
DK_ADD_TAB(recursionLevel)	\
ss << "\tEnd" << #fields << "\n";

#define DK_ALL_FIELDS_BINARY_DATA1(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA0(fields)

#define DK_ALL_FIELDS_BINARY_DATA2(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA1(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA3(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA2(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA4(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA3(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA5(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA4(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA6(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA5(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA7(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA6(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA8(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA7(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA9(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA8(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA10(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA9(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA11(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA10(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA12(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA11(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA13(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA12(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA14(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA13(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA15(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA14(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA16(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA15(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA17(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA16(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA18(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA17(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA19(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA18(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA20(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA19(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA21(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA20(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA22(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA21(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA23(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
 DK_ALL_FIELDS_BINARY_DATA22(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA24(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA23(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA25(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA24(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA26(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA25(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA27(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA26(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA28(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA27(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA29(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA28(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA30(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA29(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA31(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA30(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA32(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA31(fields, N - 1)

#define DK_SERIALIZE_FUNC_BEGIN																	\
template<bool completeDisplay = false>															\
static std::stringstream& serialize(std::stringstream& ss, type& t, int recursionLevel = 0) {	\
DK_ADD_TAB(recursionLevel)																		\
ss << "Class " << typeName() << "\n";

#define DK_SERIALIZE_FUNC_END				\
DK_ADD_TAB(recursionLevel)					\
ss << "EndClass" << typeName() << "\n";	\
return ss;									\
}

#define DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(type)									\
template<bool completeDisplay>															\
std::stringstream& type::serialize(std::stringstream& ss) {								\
return drak::serialization::MetaData<type>::serialize<completeDisplay>(ss, *this, 0);	\
}

#define DK_EMPTY_SERIALIZE_FUNCTION_IN_SERIALIZED_OBJECT(type) \
std::stringstream& type::serialize(std::stringstream& ss) {};

#define DK_SERIALIZE_1_FIELDS(fields1)												\
static constexpr std::array<IFields<type>*, 1> s_fields								\
{ (IFields<type>*)&s_##fields1 };														\
static constexpr std::array<constexpr const char*, 1> s_fieldName									\
{ DK_STRINGIZE(s_##fields1) };												\
static constexpr bool s_hasDynamiclyAllocatedMemory =								\
fields1::s_hasDynamiclyAllocatedMemory;												\
static constexpr size_t s_totalSize =													\
fields1::s_totalSize;																	\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
}																						\
DK_SERIALIZE_FUNC_BEGIN																\
serializeLoop##fields1<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);		\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN					\
fields1::deserialize(ss, t);			\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_2_FIELDS(fields1, fields2)										\
static constexpr std::array<IFields<type>*, 2> s_fields								\
{ (IFields<type>*)&s_##fields1, (IFields<type>*)&s_##fields2 };				\
static constexpr std::array<constexpr const char*, 2> s_fieldName									\
{ DK_STRINGIZE(s_##fields1), DK_STRINGIZE(s_##fields2) };												\
static constexpr bool s_hasDynamiclyAllocatedMemory = \
fields1::s_hasDynamiclyAllocatedMemory || \
fields2::s_hasDynamiclyAllocatedMemory; 										\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize;														\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
fields2::SetEveryData(t, data + fields1::s_totalSize);									\
}																						\
DK_SERIALIZE_FUNC_BEGIN																\
serializeLoop##fields1<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);	\
serializeLoop##fields2<type, fields2::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN					\
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
static constexpr bool s_hasDynamiclyAllocatedMemory = \
fields1::s_hasDynamiclyAllocatedMemory || \
fields2::s_hasDynamiclyAllocatedMemory || \
fields3::s_hasDynamiclyAllocatedMemory;										\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize + \
fields3::s_totalSize;														\
static void SetAllBinaryData(type& t, const char* data){															\
fields1::SetEveryData(t, data);																\
fields2::SetEveryData(t, data + fields1::s_totalSize);									\
fields3::SetEveryData(t, data + fields1::s_totalSize + fields2::s_totalSize);	\
}																									\
DK_SERIALIZE_FUNC_BEGIN																	\
serializeLoop##fields1<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);		\
serializeLoop##fields2<type, fields2::s_varN, completeDisplay>(ss, t, recursionLevel);	\
serializeLoop##fields3<type, fields3::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END						\
DK_DESERIALIZE_FUNC_BEGIN					\
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
static constexpr bool s_hasDynamiclyAllocatedMemory =									\
PublicFields::s_hasDynamiclyAllocatedMemory ||											\
PrivateFields::s_hasDynamiclyAllocatedMemory ||											\
PublicStaticFields::s_hasDynamiclyAllocatedMemory ||									\
PrivateStaticFields::s_hasDynamiclyAllocatedMemory;										\
static constexpr size_t s_totalSize =													\
PublicFields::s_totalSize +																\
PrivateFields::s_totalSize +															 \
PublicStaticFields::s_totalSize +														\
PrivateStaticFields::s_totalSize;														\
static void SetAllBinaryData(type& t, const char* data){															\
PublicFields::SetEveryData(t, data);																\
PrivateFields::SetEveryData(t, data + PublicFields::s_totalSize);									\
PublicStaticFields::SetEveryData(t, data + PublicFields::s_totalSize + PrivateFields::s_totalSize);	\
PrivateStaticFields::SetEveryData(t, data + PublicFields::s_totalSize +								\
	PrivateFields::s_totalSize + PublicStaticFields::s_totalSize);									\
}																									\
DK_SERIALIZE_FUNC_BEGIN																	\
	serializeLoopPublicFields<type, PublicFields::s_varN, completeDisplay>(ss, t, recursionLevel);		\
	serializeLoopPrivateFields<type, PrivateFields::s_varN, completeDisplay>(ss, t, recursionLevel);		\
	serializeLoopPublicStaticFields<type, PublicStaticFields::s_varN, completeDisplay>(ss, t, recursionLevel);	\
	serializeLoopPrivateStaticFields<type, PrivateStaticFields::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END																								\
DK_DESERIALIZE_FUNC_BEGIN					\
PublicFields::deserialize(ss, t);			\
PrivateFields::deserialize(ss, t);			\
PublicStaticFields::deserialize(ss, t);		\
PrivateStaticFields::deserialize(ss, t);	\
DK_DESERIALIZE_FUNC_END

#define DK_SERIALIZE_PUBLIC_FIELDS													\
DK_SERIALIZE_1_FIELDS(PublicFields)

#define DK_SERIALIZE_PRIVATE_FIELDS													\
DK_SERIALIZE_1_FIELDS(PrivateFields)

#define DK_SERIALIZE_STATIC_PUBLIC_FIELDS												\
DK_SERIALIZE_1_FIELDS(PublicStaticFields)

#define DK_SERIALIZE_STATIC_PRIVATE_FIELDS												\
DK_SERIALIZE_1_FIELDS(PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_PRIVATE_FIELDS											\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateFields)

#define DK_SERIALIZE_STATIC_PUBLIC_PRIVATE_FIELDS										\
DK_SERIALIZE_2_FIELDS(PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS								\
DK_SERIALIZE_2_FIELDS(PublicFields, PublicStaticFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PublicStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS							\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_PRIVATE_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS_AND_PRIVATE_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PrivateFields, PrivateStaticFields, PublicStaticFields)

#define DK_SERIALIZE_LOOP_FUNC(fields, argN)											\
template<typename T, int N, bool completeDisplay = false>								\
static void serializeLoop##fields(std::stringstream& ss, type& t, int recursionLevel) {	\
DK_ADD_TAB(recursionLevel)																\
ss << "\t" << #fields << "\n";															\
if constexpr (!drak::types::IsBaseType_V<T>){											\
if constexpr (MetaData<T>::fields::s_hasDynamiclyAllocatedMemory || completeDisplay) {	\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_LOOP_IMPL, argN)(fields, N - 1))						\
}																						\
else {																					\
DK_ADD_TAB(recursionLevel)																\
ss << "\t\t" << #fields << " Size " << fields::s_totalSize <<							\
" Binary ";																		\
DK_ALL_FIELDS_BINARY_DATA(fields, argN)													\
}																						\
}																						\
}

#define DK_SERIALIZE_LOOP_IMPL0(fields)\
DK_ADD_TAB(recursionLevel)	\
ss << "\tEnd" << #fields << "\n";

#define DK_SERIALIZE_LOOP_IMPL1(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL0(fields)

#define DK_SERIALIZE_LOOP_IMPL2(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL1(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL3(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL2(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL4(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL3(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL5(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL4(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL6(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL5(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL7(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL6(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL8(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL7(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL9(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL8(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL10(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL9(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL11(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL10(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL12(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL11(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL13(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL12(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL14(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL13(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL15(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL14(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL16(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL15(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL17(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL16(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL18(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL17(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL19(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL18(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL20(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL19(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL21(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL20(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL22(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL21(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL23(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL22(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL24(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL23(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL25(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL24(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL26(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL25(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL27(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL26(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL28(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL27(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL29(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL28(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL30(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL29(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL31(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL30(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL32(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL31(fields, N - 1)


#define DK_SERIALIZE_LOOP_IMPL_FUNC(fields)															\
template<typename T, int N, bool completeDisplay>													\
static void serializeLoopImpl##fields(std::stringstream& ss, type& t, int recursionLevel) {			\
if constexpr (drak::types::IsBaseType_V<T> ||														\
		(std::is_array_v<T> &&																		\
		drak::types::IsBaseType_V<T>)) {															\
	 std::tuple<void*, size_t> binary{ fields::get(t, fields::s_varName[N]) };						\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " << fields::s_varName[N]			\
	<< " Size " << std::get<1>(binary) <<" Binary ";											\
	for (size_t i = 0; i < std::get<1>(binary); ++i) {												\
			ss << ((const char*)std::get<0>(binary))[i];											\
	}																								\
	ss << "\n";																						\
}																									\
else if constexpr (!drak::types::IsBaseType_V<T> &&	std::is_array_v<T>){							\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<								\
	fields::s_varName[N] << " :\n";																	\
for(size_t i = 0, size = drak::types::SizeOfArray_V<T> ; i < size; ++i ) {							\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << "[" << i << "] : \n";															\
	MetaData<std::remove_all_extents_t<T>>::serialize<completeDisplay>								\
		(ss, (t.*(std::get<N>(fields::s_var)))[i], recursionLevel + 2);								\
}																									\
}																									\
else {																								\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<								\
	fields::s_varName[N] << ":\n";																	\
	T  obj{ t.*(std::get<N>(fields::s_var)) };														\
	MetaData<T>::serialize<completeDisplay>															\
		(ss, *(T*)std::get<0>(fields::get(t, fields::s_varName[N])), recursionLevel + 2);			\
}																									\
}

#define DK_NON_SERIALIZED_OBJECT \
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(type)						\
friend drak::serialization::MetaData<type>;				\
static constexpr bool s_serialized = true;				\
public:													\
using MetaData = MetaData<type>;						\
template<bool completeDisplay = false>					\
inline std::stringstream& serialize(std::stringstream& ss);

#define DK_METADATA_BEGIN(ty)								\
template<>													\
struct drak::serialization::MetaData<ty> {					\
using type = ty;											\
static constexpr const char* typeName() { return #ty; };	\
static ty create() { return ty(); };						\
static ty* createNew() { return new ty; };					\
template<typename T>																				\
static constexpr size_t SizeOfSerializedType(){														\
if constexpr(drak::types::IsBaseType_V<std::remove_all_extents_t<T>>)								\
return sizeof(T);																					\
else if constexpr(std::is_array_v<T>)																\
return MetaData<std::remove_all_extents_t<T>>::s_totalSize * drak::types::SizeOfArray_V<T>;			\
else if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<T>> && T::s_serialized)		\
return MetaData<T>::s_totalSize;																	\
else{																								\
Logbook::Log(Logbook::EOutput::BOTH, LOG_FILE,														\
"Cannot get the size of a non serialized object, your object is of type : %s", typeid(T).name());	\
exit(1);																							\
return 0;																							\
}																									\
}

#define DK_METADATA_FIELDS(fieldName, ...)												\
struct fieldName : public drak::serialization::IFields<type> {							\
template<typename T>																				\
static void SetData(T& t, const char* c_str, size_t offset) 	{										\
	if constexpr (drak::types::IsBaseType_V<std::remove_all_extents_t<T>>)														\
		memcpy(&(t), c_str + offset, SizeOfSerializedType<T>());									\
	else if constexpr(!std::is_array_v<T>)															\
		MetaData<T>::SetAllBinaryData(t, c_str + offset);											\
	else																							\
		for(int i = 0, size = drak::types::SizeOfArray_V<T>; i < size; ++i, offset += SizeOfSerializedType<T>())	\
			MetaData<std::remove_all_extents_t<T>>::SetAllBinaryData(t[i], c_str + offset);		\
}																								\
template<typename T>																	\
static std::tuple<void*, size_t> getData(T& t) {										\
if constexpr (drak::types::IsBaseType_V<std::remove_all_extents_t<T>>){					\
	return std::make_tuple<void*, size_t>												\
	(&(t), sizeof(T));																	\
}																						\
else if constexpr(!std::is_array_v<T>) {												\
	return std::make_tuple<void*, size_t>												\
	((void*)&(t), SizeOfSerializedType<T>());											\
}																						\
}																						\
template<typename T>																			\
static constexpr bool CheckForPTR() {															\
 if constexpr (drak::types::IsBaseType_V<std::remove_pointer_t<std::remove_all_extents_t<T>>>)	\
	return std::is_pointer_v<T>;																\
 else																							\
	return drak::serialization::MetaData<std::remove_pointer_t<std::remove_all_extents_t<T>>>::	\
	s_hasDynamiclyAllocatedMemory;																\
}																								\
static constexpr std::array<constexpr const char*, DK_ARGS_N(__VA_ARGS__)> s_varName =	\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };								\
static constexpr auto s_var =															\
std::make_tuple(DK_REVERSE_VA_ARGS(DK_POINT_MEMBER(__VA_ARGS__)));						\
static constexpr int s_varN = DK_ARGS_N(__VA_ARGS__);									\
static constexpr size_t s_totalSize = DK_SIZEOF_VA_ARGS(__VA_ARGS__);					\
static constexpr bool s_hasDynamiclyAllocatedMemory =									\
DK_CHECK_FOR_PTR(__VA_ARGS__);															\
virtual const char* varName(int idx)override{											\
	return s_varName[idx];																\
};																						\
virtual int varN() override {															\
	return s_varN;																		\
};																						\
virtual size_t totalSizeAllVar() override {												\
	return s_totalSize;																	\
};																						\
virtual bool hasDynamiclyAllocatedMemory() override {									\
	return s_hasDynamiclyAllocatedMemory;												\
};																						\
virtual std::tuple<void*, size_t> getVar(type& t, const char* str)override {			\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
static std::tuple<void*, size_t> get(type& t, const char* str) {						\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
static size_t SizeOf(const char* str) {													\
	DK_EXPAND(DK_CONCAT(DK_SIZEOF_TYPE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))			\
}																						\
static void set(type& t, const char* name, void* data) {								\
	DK_EXPAND(DK_CONCAT(DK_SET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
static const char* typeNameOf(const char* str){											\
	DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
DK_SET_EVERY_DATA_FUNC(__VA_ARGS__)														\
static type& deserialize(std::stringstream& ss, type& t) {				\
DK_DESERIALIZE_LOOP_IMPL(fieldName)										\
return t;																\
}																		\
};																						\
private :																				\
DK_ALL_FIELDS_BINARY_DATA_FUNC(fieldName)												\
DK_SERIALIZE_LOOP_IMPL_FUNC(fieldName)													\
DK_SERIALIZE_LOOP_FUNC(fieldName,  DK_ARGS_N(__VA_ARGS__))								\
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
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };

#define DK_METADATA_END };

#define DK_DESERIALIZE_FUNC_BEGIN				\
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
static void SetEveryData(type& t, const char* c_str) {	\
	DK_EXPAND(DK_CONCAT(DK_SET_EVERY_DATA, DK_ARGS_N(__VA_ARGS__))(0, __VA_ARGS__))	\
}

#define DK_SET_EVERY_DATA0
#define DK_SET_EVERY_DATA1(offset, ty)			\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);

#define DK_SET_EVERY_DATA2(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA1(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA3(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA2(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA4(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA3(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA5(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA4(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA6(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA5(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA7(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA6(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA8(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA7(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA9(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA8(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA10(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA9(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA11(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA10(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA12(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA11(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA13(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA12(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA14(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA13(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA15(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA14(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA16(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA15(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA17(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA16(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA18(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA17(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA19(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA18(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA20(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA19(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA21(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA20(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA22(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA21(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA23(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA22(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA24(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA23(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA25(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA24(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA26(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA25(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA27(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA26(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA28(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA27(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA29(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA28(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA30(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA29(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA31(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA30(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))

#define DK_SET_EVERY_DATA32(offset, ty, ...)	\
SetData<TYPEOF(t.ty)>(t.ty, c_str, offset);		\
DK_EXPAND(DK_SET_EVERY_DATA31(offset +  SizeOfSerializedType<TYPEOF(t.ty)>(), __VA_ARGS__))
