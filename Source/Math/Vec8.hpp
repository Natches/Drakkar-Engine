#pragma once

#include<Math/MathUtils.hpp>
#include<Math/SIMDUtils.hpp>
#include<ostream>

namespace drak {
namespace math {

template<typename T>
struct Vec8 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");
	static constexpr bool isIntegral = std::is_integral_v<T>;
	using SIMDStruct = typename SIMDUtils::BestSIMDType<T, 8>;
	using SIMDType = typename SIMDStruct::SIMDType;

public:
	Vec8();
	Vec8(T* arr);
	Vec8(const T X, const T Y, const T Z, const T W,
		const T A, const T B, const T C, const T D);

	Vec8(const Vec8<T>& v);
	Vec8(Vec8<T>&& v);
	Vec8(const Vec4<T>& v);
	Vec8(Vec4<T>&& v);
	Vec8(const Vec4<T>& v1, const Vec4<T>& v2);
	Vec8(Vec4<T>&& v1, Vec4<T>&& v2);
	~Vec8() = default;
	Vec8(const SIMDType& ss);

public:
	bool operator==(const Vec8<T>& v) const;
	bool operator!=(const Vec8<T>& v) const;
	bool operator>(const Vec8<T>& v)  const;
	bool operator<(const Vec8<T>& v)  const;
	bool operator>=(const Vec8<T>& v) const;
	bool operator<=(const Vec8<T>& v) const;

	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

	Vec8<T>& operator  =(const Vec8<T>& v);
	Vec8<T>& operator  =(Vec8<T>&& v);
	Vec8<T>& operator +=(const T n);
	Vec8<T>& operator -=(const T n);
	Vec8<T>& operator *=(const T n);
	Vec8<T>& operator /=(const T n);
	Vec8<T>& operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec8<T>& operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec8<T>& operator &=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec8<T>& operator ^=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec8<T>& operator |=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec8<T>& operator++();
	Vec8<T>& operator--();

	Vec8<T> operator+(const T n) const;
	Vec8<T> operator-(const T n) const;
	Vec8<T> operator*(const T n) const;
	Vec8<T> operator/(const T n) const;
	Vec8<T> operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec8<T> operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec8<T> operator&(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec8<T> operator^(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec8<T> operator|(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec8<T> operator++(const I32) const;
	Vec8<T> operator--(const I32) const;
	Vec8<T> operator-()	  const;

	Vec8<T> conjugate() const;
	Vec8<T> normalize() const;

	template<typename U>
	Vec8<U> cast() const;

	Vec8<F32> ceil();
	Vec8<F32> floor();
	Vec8<F32> round();

public:
	union {
		T m_vec[8];
		struct { T x, y, z, w, a, b, c, d; };
		SIMDType m_simdVec;
	}alignas(SIMDStruct::alignement);
};

template<typename T>
Vec8<T> operator+(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T> operator-(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T> operator*(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T> operator/(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
Vec8<T> operator>>(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T> operator<<(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T> operator&(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T> operator^(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T> operator|(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);

template<typename T>
Vec8<T>& operator+=(Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T>& operator-=(Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T>& operator*=(Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
Vec8<T>& operator/=(Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
Vec8<T>& operator>>=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T>& operator<<=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T>& operator&=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T>& operator^=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec8<T>& operator|=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2);

template<typename T>
Vec8<T> Min(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
Vec8<T> Max(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec8<T>& v);

using Vec8c = typename Vec8<U8>;
using Vec8sc = typename Vec8<I8>;
using Vec8si = typename Vec8<I16>;
using Vec8sui = typename Vec8<U16>;
using Vec8i = typename Vec8<I32>;
using Vec8ui = typename Vec8<U32>;
using Vec8lli = typename Vec8<I64>;
using Vec8ulli = typename Vec8<U64>;
using Vec8f = typename Vec8<F32>;
using Vec8d = typename Vec8<F64>;

} //namespace maths
} //namespace drak
#include<Math/Vec8.inl>

