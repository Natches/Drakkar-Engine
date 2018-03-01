#pragma once

#include <Core/Core.hpp>
#include <limits>
#include <algorithm>

#define M_PI 3.14159265358979323
#define M_PIF 3.14159265f

namespace drak {
namespace math {

constexpr F32 ToRadF = M_PIF / 180.f;
constexpr F64 ToRad = M_PI / 180.0;

constexpr F32 ToDegF = 180.f / M_PIF;
constexpr F64 ToDeg = 180.0 / M_PI;

template<typename T>
constexpr T ToRadian(T n) {
	static_assert(std::is_floating_point_v<T>, "\"T\" must be a floating point");
	return (n * static_cast<T>(ToRad));
}

template<typename T>
constexpr T ToDegree(T n) {
	static_assert(std::is_floating_point_v<T>, "\"T\" must be a floating point");
	return (n * static_cast<T>(ToDeg));
}

enum class AngleUnit : byte {
	DEGREE,
	RADIANS
};

#define COMPARE_FLOATING_POINT_EQUAL(type, f1, f2) std::fabs(f1 - f2) <= \
		(std::numeric_limits<type>::epsilon() * std::max(fabs(f1), fabs(f2)))
#define COMPARE_FLOATING_POINT_NOT_EQUAL(type, f1, f2) !COMPARE_FLOATING_POINT_EQUAL(type, f1, f2)

template<typename T, bool b = std::is_floating_point_v<T>>
struct IsEqual {
	static inline constexpr bool value(T n1, T n2) {
		return n1 == n2;
	}
};

template<typename T>
struct IsEqual<T, true> {
	static inline constexpr bool value(T n1, T n2) {
		return COMPARE_FLOATING_POINT_EQUAL(T, n1, n2);
	}
};

template<typename T>
inline constexpr bool IsEqual_V(T n1, T n2) {
	return IsEqual<T>::value(n1, n2);
}

template<typename T, bool b = std::is_floating_point_v<T>>
struct IsNotEqual {
	static inline constexpr bool value(T n1, T n2) {
		return n1 == n2;
	}
};

template<typename T>
struct IsNotEqual<T, true> {
	static inline constexpr bool value(T n1, T n2) {
		return COMPARE_FLOATING_POINT_NOT_EQUAL(T, n1, n2);
	}
};

template<typename T>
inline constexpr bool IsNotEqual_V(T n1, T n2) {
	return IsNotEqual<T>::value(n1, n2);
}

} //namespace math
} //namespace drak