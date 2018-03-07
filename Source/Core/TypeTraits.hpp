#pragma once

#include <type_traits>

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
	using type = T & ;
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

} //namespace types
} //namespace drak
#define NOT_A_TYPE drak::types::noTypes::NoType
#define IS_LARGER_THAN_V(T1, T2)  drak::types::IsLargerThan_V<T1, T2>
#define ADD_REF_IF_T(b, T) drak::types::AddRefIf_T<b, T>
#define ENABLE_IF_ELSE_T(b, T1, T2)  drak::types::EnableIfElse_T<b, T1, T2>

