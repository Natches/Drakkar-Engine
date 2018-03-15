#pragma once

#include <Core/MacroUtils.h>

struct Type {
};

template<typename T, int i>
struct TypeList {
};

#define TYPELIST(x, Name, N, ...)									\
template<>															\
struct TypeList<Name, N> : public Type {							\
	ANONSTRUCTRECURSIVE(x, __VA_ARGS__)								\
};

#define ANONSTRUCTRECURSIVE(T, ...)					\
	EXPAND(CONCAT(ANONSTRUCTRECURSIVE, T)(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE0()

#define ANONSTRUCTRECURSIVE1(T)						\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTEND())

#define ANONSTRUCTRECURSIVE2(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE1(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE3(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE2(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE4(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE3(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE5(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE4(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE6(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE5(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE7(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE6(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE8(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE7(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE9(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE8(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE10(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE9(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE11(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE10(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE12(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE11(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE13(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE12(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE14(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE13(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE15(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE14(__VA_ARGS__))

#define ANONSTRUCTRECURSIVE16(T, ...)				\
	using CONCAT(m_, __COUNTER__) = typename T;		\
	EXPAND(ANONSTRUCTRECURSIVE15(__VA_ARGS__))


#define ANONSTRUCTEND()								\
	const int count = __COUNTER__;

#define GATHERTYPE1(TypeStruct, ...) \
		EXPAND(TypeStruct::m_0, __VA_ARGS__)

#define GATHERTYPE2(TypeStruct, ...) \
		EXPAND(GATHERTYPE1(TypeStruct, TypeStruct::m_1, __VA_ARGS__))

#define GATHERTYPE3(TypeStruct, ...) \
		EXPAND(GATHERTYPE2(TypeStruct, TypeStruct::m_2, __VA_ARGS__))

#define GATHERTYPE4(TypeStruct, ...) \
		EXPAND(GATHERTYPE3(TypeStruct, TypeStruct::m_3, __VA_ARGS__))

#define GATHERTYPE5(TypeStruct, ...) \
		EXPAND(GATHERTYPE4(TypeStruct, TypeStruct::m_4, __VA_ARGS__))

#define GATHERTYPE6(TypeStruct, ...) \
		EXPAND(GATHERTYPE5(TypeStruct, TypeStruct::m_5, __VA_ARGS__))

#define GATHERTYPE7(TypeStruct, ...) \
		EXPAND(GATHERTYPE6(TypeStruct, TypeStruct::m_6, __VA_ARGS__))

#define GATHERTYPE8(TypeStruct, ...) \
		EXPAND(GATHERTYPE7(TypeStruct, TypeStruct::m_7, __VA_ARGS__))

#define GATHERTYPE9(TypeStruct, ...) \
		EXPAND(GATHERTYPE8(TypeStruct, TypeStruct::m_8, __VA_ARGS__))

#define GATHERTYPE10(TypeStruct, ...) \
		EXPAND(GATHERTYPE9(TypeStruct, TypeStruct::m_9, __VA_ARGS__))

#define GATHERTYPE11(TypeStruct, ...) \
		EXPAND(GATHERTYPE10(TypeStruct, TypeStruct::m_10, __VA_ARGS__))

#define GATHERTYPE12(TypeStruct, ...) \
		EXPAND(GATHERTYPE11(TypeStruct, TypeStruct::m_11, __VA_ARGS__))

#define GATHERTYPE13(TypeStruct, ...) \
		EXPAND(GATHERTYPE12(TypeStruct, TypeStruct::m_12, __VA_ARGS__))

#define GATHERTYPE14(TypeStruct, ...) \
		EXPAND(GATHERTYPE13(TypeStruct, TypeStruct::m_13, __VA_ARGS__))

#define GATHERTYPE15(TypeStruct, ...) \
		EXPAND(GATHERTYPE14(TypeStruct, TypeStruct::m_14, __VA_ARGS__))

#define GATHERTYPE16(TypeStruct, ...) \
		EXPAND(GATHERTYPE15(TypeStruct, TypeStruct::m_15, __VA_ARGS__))

#define GATHERTYPEBASE1(TypeStruct) \
		EXPAND(TypeStruct::m_0)

#define GATHERTYPEBASE2(TypeStruct) \
		EXPAND(GATHERTYPE1(TypeStruct, TypeStruct::m_1))

#define GATHERTYPEBASE3(TypeStruct) \
		EXPAND(GATHERTYPE2(TypeStruct, TypeStruct::m_2))

#define GATHERTYPEBASE4(TypeStruct) \
		EXPAND(GATHERTYPE3(TypeStruct, TypeStruct::m_3))

#define GATHERTYPEBASE5(TypeStruct) \
		EXPAND(GATHERTYPE4(TypeStruct, TypeStruct::m_4))

#define GATHERTYPEBASE6(TypeStruct) \
		EXPAND(GATHERTYPE5(TypeStruct, TypeStruct::m_5))

#define GATHERTYPEBASE7(TypeStruct) \
		EXPAND(GATHERTYPE6(TypeStruct, TypeStruct::m_6))

#define GATHERTYPEBASE8(TypeStruct) \
		EXPAND(GATHERTYPE7(TypeStruct, TypeStruct::m_7))

#define GATHERTYPEBASE9(TypeStruct) \
		EXPAND(GATHERTYPE8(TypeStruct, TypeStruct::m_8))

#define GATHERTYPEBASE10(TypeStruct) \
		EXPAND(GATHERTYPE9(TypeStruct, TypeStruct::m_9))

#define GATHERTYPEBASE11(TypeStruct) \
		EXPAND(GATHERTYPE10(TypeStruct, TypeStruct::m_10))

#define GATHERTYPEBASE12(TypeStruct) \
		EXPAND(GATHERTYPE11(TypeStruct, TypeStruct::m_11))

#define GATHERTYPEBASE13(TypeStruct) \
		EXPAND(GATHERTYPE12(TypeStruct, TypeStruct::m_12))

#define GATHERTYPEBASE14(TypeStruct) \
		EXPAND(GATHERTYPE13(TypeStruct, TypeStruct::m_13))

#define GATHERTYPEBASE15(TypeStruct) \
		EXPAND(GATHERTYPE14(TypeStruct, TypeStruct::m_14))

#define GATHERTYPEBASE16(TypeStruct) \
		EXPAND(GATHERTYPE15(TypeStruct, TypeStruct::m_15))

#define GATHERTYPE(TypeStruct, N) \
		EXPAND(CONCAT(GATHERTYPEBASE, N)(TypeStruct))