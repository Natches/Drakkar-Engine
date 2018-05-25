#pragma once

#include <type_traits>
#include <immintrin.h>
#include <vector>
#include <map>
#include <unordered_map>

namespace drak {
namespace types {

template<bool b, typename T1, typename T2>
struct EnableIfElse {
	using type = T2;
};

template<typename T1, typename T2>
struct EnableIfElse<true, T1, T2> {
	using type = T1;
};

template<bool b, typename T1, typename T2>
using EnableIfElse_T = typename EnableIfElse<b, T1, T2>::type;

template<bool b, typename T>
struct AddRefIf {
	using type = T;
};

template<typename T>
struct AddRefIf<true, T> {
	using type = T& ;
};

template<bool b, typename T>
using AddRefIf_T = typename AddRefIf<b, T>::type;

template<typename T1, typename T2>
struct IsLargerThan {
	enum : bool {
		value = (sizeof(T1) > sizeof(T2))
	};
};

template<typename T1, typename T2>
constexpr bool IsLargerThan_V = IsLargerThan<T1, T2>::value;

namespace noTypes {
class NoType {};
}

template<typename T>
struct IsBaseType {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
struct IsBaseType<T*> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
struct IsBaseType<T[]> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T, size_t N>
struct IsBaseType<T[N]> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
struct IsBaseType<const T> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
struct IsBaseType<const T*> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
struct IsBaseType<const T[]> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T, size_t N>
struct IsBaseType<const T[N]> {
	enum : bool {
		value = std::is_same_v<T, bool> || std::is_same_v<T, U8> || std::is_same_v<T, I8> ||
		std::is_same_v<T, U16> || std::is_same_v<T, I16> || std::is_same_v<T, U32> ||
		std::is_same_v<T, I32> || std::is_same_v<T, U64> || std::is_same_v<T, I64> ||
		std::is_same_v<T, F32> || std::is_same_v<T, F64> || std::is_same_v<T, __m64> ||
		std::is_same_v<T, __m128> || std::is_same_v<T, __m256> || std::is_same_v<T, __m128i> ||
		std::is_same_v<T, __m256i> || std::is_enum_v<T>
	};
};

template<typename T>
constexpr bool IsBaseType_V = IsBaseType<T>::value;

template<typename T>
struct IsIntrinType {
	enum : bool {
		value =  std::is_same_v<T, __m128> || std::is_same_v<T, __m256> ||
		std::is_same_v<T, __m128i> || std::is_same_v<T, __m256i>
	};
};

template<typename T>
constexpr bool IsIntrinType_V = IsIntrinType<T>::value;

template<typename T>
struct VectorType {
	using type = typename T;
};

template<typename T>
struct VectorType<std::vector<T, std::allocator<T>>> {
	using type = typename T;
};

template<typename T>
using VectorType_T = typename VectorType<T>::type;

template<typename T>
struct IsVector : VectorType<T> {
	enum : bool {
		value = std::is_same_v<T, std::vector<type>>
	};
};

template<typename T>
constexpr bool IsVector_V = IsVector<T>::value;

template<typename T>
struct PairType {
	using type1 = T;
	using type2 = void;
};

template<typename T, typename U>
struct PairType<std::pair<T, U>> {
	using type1 = T;
	using type2 = U;
};

template<typename T>
using PairType_T1 = typename PairType<T>::type1;

template<typename T>
using PairType_T2 = typename PairType<T>::type2;

template<typename T>
struct IsPair : PairType<T> {
	enum : bool {
		value = std::is_same_v<T, std::pair<type1, type2>>
	};
};

template<typename T>
constexpr bool IsPair_V = IsPair<T>::value;

template<typename T>
struct MapType {
	using type1 = T;
	using type2 = void;
};

template<typename T, typename U>
struct MapType<std::map<T, U>> {
	using type1 = T;
	using type2 = U;
};

template<typename T, typename U>
struct MapType<std::unordered_map<T, U>> {
	using type1 = T;
	using type2 = U;
};

template<typename T>
using MapType_T1 = typename MapType<T>::type1;

template<typename T>
using MapType_T2 = typename MapType<T>::type2;

template<typename T>
struct IsMap : MapType<T> {
	enum : bool {
		value = std::is_same_v<T, std::map<type1, type2>>
	};
};

template<typename T>
constexpr bool IsMap_V = IsMap<T>::value;

template<typename T>
struct IsUnorderedMap : MapType<T> {
	enum : bool {
		value = std::is_same_v<T, std::unordered_map<type1, type2>>
	};
};

template<typename T>
constexpr bool IsUnorderedMap_V = IsUnorderedMap<T>::value;

template<typename T>
struct SizeOfArray {
	enum : int {
		value = 1
	};
};

template<typename T, size_t X>
struct SizeOfArray<T[X]> {
	enum : int {
		value = X
	};
};

template<typename T>
constexpr int SizeOfArray_V = SizeOfArray<T>::value;

} //namespace types
} //namespace drak
#define NOT_A_TYPE drak::types::noTypes::NoType
#define IS_LARGER_THAN_V(T1, T2)  drak::types::IsLargerThan_V<T1, T2>
#define ADD_REF_IF_T(b, T) drak::types::AddRefIf_T<b, T>
#define ENABLE_IF_ELSE_T(b, T1, T2)  drak::types::EnableIfElse_T<b, T1, T2>

