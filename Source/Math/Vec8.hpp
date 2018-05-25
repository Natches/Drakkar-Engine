#pragma once

#include <Math/Vec8.fwd>
#include <Math/MathUtils.hpp>
#include <Math/SIMDUtils.hpp>
#include <Math/Vec4.hpp>

namespace drak {
namespace math {

template<typename T>
struct Vec8 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64), DK_MATH_ERROR0(T));
	static constexpr bool isIntegral = std::is_integral_v<T>;
	using SIMDStruct = typename SIMDUtils::BestSIMDType<T, 8>;
	using SIMDType = typename SIMDStruct::SIMDType;
	DK_SERIALIZED_OBJECT(Vec8<T>)
public:
	Vec8();
	explicit Vec8(const T n);
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
	static Vec8<T> broadcast(const Vec4<T>& v);

public:
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

	Vec8<T>& negate();
	Vec8<T>& abs();

	Vec8<F32>& ceil();
	Vec8<F32>& floor();
	Vec8<F32>& round();
	Vec8<F32>& sqrt();
	Vec8<F32>& normalize();

	Vec8<T> sign() const;

	template<typename U>
	Vec8<U> cast() const;

public:
	union alignas(SIMDStruct::alignement) {
		T m_vec[8];
		struct { Vec4<T> xyzw, abcd; };
		struct { Vec2<T> xy, zw, ab, cd; };
		struct { T x, y, z, w, a, b, c, d; };
		SIMDType m_simdVec;
	};
};

template<typename T>
bool operator==(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
bool operator!=(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
bool operator>(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
bool operator<(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
bool operator>=(const Vec8<T>& v1, const Vec8<T>& v2);
template<typename T>
bool operator<=(const Vec8<T>& v1, const Vec8<T>& v2);

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
T Dot(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
Vec4<T> FourDot(const Vec8<T>& row1, const Vec8<T>& row2,
	const Vec8<T>& col1);

template<typename T>
Vec8<T> EightDot(const Vec8<T>& row1, const Vec8<T>& row2,
	const Vec8<T>& col1, const Vec8<T>& col2);

inline Vec8f Normalize(const Vec8f& v);

template<typename T>
Vec8<T> Negate(const Vec8<T>& v);

template<typename T>
Vec8<T> Abs(const Vec8<T>& v);

inline Vec8f Ceil(const Vec8f& v);
inline Vec8f Floor(const Vec8f& v);
inline Vec8f Round(const Vec8f& v);
inline Vec8f Sqrt(const Vec8f& v);

template<typename T>
Vec8<T> Min(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
Vec8<T> Max(const Vec8<T>& v1, const Vec8<T>& v2);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec8<T>& v);

} //namespace maths
} //namespace drak
#include<Math/Vec8.inl>

DK_METADATA_BEGIN(drak::math::Vec8c)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8sc)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8s)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8us)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8i)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8u)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec8f)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END