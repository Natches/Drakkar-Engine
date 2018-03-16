#pragma once

#include <Core/Utils/MacroUtils.h>

namespace drak {
namespace types {

struct Type {
};

} // namespace types
} // namespace drak

#define DK_TYPELIST(ArgsN, Class, Instance, ...)				\
template<typename T, int i>										\
struct TypeList {												\
};																\
template<>														\
struct TypeList<Class, Instance> : public drak::types::Type {	\
	DK_TYPE(ArgsN, __VA_ARGS__)									\
};																\
using DK_CONCAT(DK_CONCAT(TypeList, Class), Instance) =			\
	typename TypeList<Class, Instance>;

#define DK_TYPE(ArgsN, ...)										\
	DK_EXPAND(DK_CONCAT(DK_TYPE, ArgsN)(__VA_ARGS__))

#define DK_TYPE0()

#define DK_TYPE1(Class)											\
	using DK_CONCAT(m_, 0) = typename Class;					\
	DK_EXPAND(DK_TYPE_END())

#define DK_TYPE2(Class, ...)									\
	using DK_CONCAT(m_, 1) = typename Class;					\
	DK_EXPAND(DK_TYPE1(__VA_ARGS__))

#define DK_TYPE3(Class, ...)									\
	using DK_CONCAT(m_, 2) = typename Class;					\
	DK_EXPAND(DK_TYPE2(__VA_ARGS__))

#define DK_TYPE4(Class, ...)									\
	using DK_CONCAT(m_, 3) = typename Class;					\
	DK_EXPAND(DK_TYPE3(__VA_ARGS__))

#define DK_TYPE5(Class, ...)									\
	using DK_CONCAT(m_, 4) = typename Class;					\
	DK_EXPAND(DK_TYPE4(__VA_ARGS__))

#define DK_TYPE6(Class, ...)									\
	using DK_CONCAT(m_, 5) = typename Class;					\
	DK_EXPAND(DK_TYPE5(__VA_ARGS__))

#define DK_TYPE7(Class, ...)									\
	using DK_CONCAT(m_, 6) = typename Class;					\
	DK_EXPAND(DK_TYPE6(__VA_ARGS__))

#define DK_TYPE8(Class, ...)									\
	using DK_CONCAT(m_, 7) = typename Class;					\
	DK_EXPAND(DK_TYPE7(__VA_ARGS__))

#define DK_TYPE9(Class, ...)									\
	using DK_CONCAT(m_, 8) = typename Class;					\
	DK_EXPAND(DK_TYPE8(__VA_ARGS__))

#define DK_TYPE10(Class, ...)									\
	using DK_CONCAT(m_, 9) = typename Class;					\
	DK_EXPAND(DK_TYPE9(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE11(Class, ...)						\
	using DK_CONCAT(m_, 10) = typename Class;					\
	DK_EXPAND(DK_TYPE10(__VA_ARGS__))

#define DK_TYPE12(Class, ...)									\
	using DK_CONCAT(m_, 11) = typename Class;					\
	DK_EXPAND(ANONSTRUCTRECURSIVE11(__VA_ARGS__))

#define DK_TYPE13(Class, ...)									\
	using DK_CONCAT(m_, 12) = typename Class;					\
	DK_EXPAND(DK_TYPE12(__VA_ARGS__))

#define DK_TYPE14(Class, ...)									\
	using DK_CONCAT(m_, 13) = typename Class;					\
	DK_EXPAND(DK_TYPE13(__VA_ARGS__))

#define DK_TYPE15(Class, ...)									\
	using DK_CONCAT(m_, 14) = typename Class;					\
	DK_EXPAND(DK_TYPE14(__VA_ARGS__))

#define DK_TYPE16(Class, ...)									\
	using DK_CONCAT(m_, 15) = typename Class;					\
	DK_EXPAND(DK_TYPE15(__VA_ARGS__))


#define DK_TYPE_END()											\
	const int count = __COUNTER__;

#define DK_GATHER_TYPE1(TypeListStruct, ...) \
		DK_EXPAND(TypeListStruct::m_0, __VA_ARGS__)

#define DK_GATHER_TYPE2(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE1(TypeListStruct, TypeListStruct::m_1, __VA_ARGS__))

#define DK_GATHER_TYPE3(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE2(TypeListStruct, TypeListStruct::m_2, __VA_ARGS__))

#define DK_GATHER_TYPE4(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE3(TypeListStruct, TypeListStruct::m_3, __VA_ARGS__))

#define DK_GATHER_TYPE5(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE4(TypeListStruct, TypeListStruct::m_4, __VA_ARGS__))

#define DK_GATHER_TYPE6(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE5(TypeListStruct, TypeListStruct::m_5, __VA_ARGS__))

#define DK_GATHER_TYPE7(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE6(TypeListStruct, TypeListStruct::m_6, __VA_ARGS__))

#define DK_GATHER_TYPE8(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE7(TypeListStruct, TypeListStruct::m_7, __VA_ARGS__))

#define DK_GATHER_TYPE9(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE8(TypeListStruct, TypeListStruct::m_8, __VA_ARGS__))

#define DK_GATHER_TYPE10(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE9(TypeListStruct, TypeListStruct::m_9, __VA_ARGS__))

#define DK_GATHER_TYPE11(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE10(TypeListStruct, TypeListStruct::m_10, __VA_ARGS__))

#define DK_GATHER_TYPE12(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE11(TypeListStruct, TypeListStruct::m_11, __VA_ARGS__))

#define DK_GATHER_TYPE13(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE12(TypeListStruct, TypeListStruct::m_12, __VA_ARGS__))

#define DK_GATHER_TYPE14(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE13(TypeListStruct, TypeListStruct::m_13, __VA_ARGS__))

#define DK_GATHER_TYPE15(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE14(TypeListStruct, TypeListStruct::m_14, __VA_ARGS__))

#define DK_GATHER_TYPE16(TypeListStruct, ...) \
		DK_EXPAND(DK_GATHER_TYPE15(TypeListStruct, TypeListStruct::m_15, __VA_ARGS__))

#define DK_GATHER_TYPEBASE1(TypeListStruct) \
		DK_EXPAND(TypeListStruct::m_0)

#define DK_GATHER_TYPEBASE2(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE1(TypeListStruct, TypeListStruct::m_1))

#define DK_GATHER_TYPEBASE3(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE2(TypeListStruct, TypeListStruct::m_2))

#define DK_GATHER_TYPEBASE4(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE3(TypeListStruct, TypeListStruct::m_3))

#define DK_GATHER_TYPEBASE5(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE4(TypeListStruct, TypeListStruct::m_4))

#define DK_GATHER_TYPEBASE6(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE5(TypeListStruct, TypeListStruct::m_5))

#define DK_GATHER_TYPEBASE7(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE6(TypeListStruct, TypeListStruct::m_6))

#define DK_GATHER_TYPEBASE8(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE7(TypeListStruct, TypeListStruct::m_7))

#define DK_GATHER_TYPEBASE9(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE8(TypeListStruct, TypeListStruct::m_8))

#define DK_GATHER_TYPEBASE10(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE9(TypeListStruct, TypeListStruct::m_9))

#define DK_GATHER_TYPEBASE11(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE10(TypeListStruct, TypeListStruct::m_10))

#define DK_GATHER_TYPEBASE12(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE11(TypeListStruct, TypeListStruct::m_11))

#define DK_GATHER_TYPEBASE13(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE12(TypeListStruct, TypeListStruct::m_12))

#define DK_GATHER_TYPEBASE14(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE13(TypeListStruct, TypeListStruct::m_13))

#define DK_GATHER_TYPEBASE15(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE14(TypeListStruct, TypeListStruct::m_14))

#define DK_GATHER_TYPEBASE16(TypeListStruct) \
		DK_EXPAND(DK_GATHER_TYPE15(TypeListStruct, TypeListStruct::m_15))

#define DK_GATHER_TYPE(TypeListStruct, N) \
		DK_EXPAND(DK_CONCAT(DK_GATHER_TYPEBASE, N)(TypeListStruct))