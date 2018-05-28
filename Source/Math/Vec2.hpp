#pragma once

#include <Math/Vec2.fwd>
#include <Math/MathUtils.hpp>
#include <Serialization/MetaData.hpp>
#include <ostream>

namespace drak {
namespace math {
template<typename T>
struct Vec2 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) < 64), DK_MATH_ERROR0(T));

	static constexpr bool isIntegral = std::is_integral_v<T>;
	DK_SERIALIZED_OBJECT(Vec2<T>)
public:
	Vec2();
	explicit Vec2(const T n);
	Vec2(const T X, const T Y);
	Vec2(const Vec2<T>& v);
	Vec2(Vec2<T>&& v);
	~Vec2() = default;

public:
	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

	template<AngleUnit au = AngleUnit::DEGREE>
	F32 rotation() const;

	Vec2<T>& operator=(const Vec2<T>& v);
	Vec2<T>& operator=(Vec2<T>&& v);
	Vec2<T>& operator+=(const T n);
	Vec2<T>& operator-=(const T n);
	Vec2<T>& operator*=(const T n);
	Vec2<T>& operator/=(const T n);
	Vec2<T>& operator>>=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator<<=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator&=(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator^=(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator|=(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator++();
	Vec2<T>& operator--();

	Vec2<T> operator+(const T n) const;
	Vec2<T> operator-(const T n) const;
	Vec2<T> operator*(const T n) const;
	Vec2<T> operator/(const T n) const;
	Vec2<T> operator>>(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator<<(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator&(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator^(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator|(const  ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator++(const I32) const;
	Vec2<T> operator--(const I32) const;
	Vec2<T> operator-()	  const;

	Vec2<T>& negate();
	Vec2<T>& abs();

	Vec2<F32>& rotate(F32 angle);
	Vec2<F32>& rotateAround(const Vec2<F32>& point, const F32 angle);
	Vec2<F32>& rotateAround(const Vec2<F32>& point, const F32 angle, const F32 distance);
	Vec2<F32>& ceil();
	Vec2<F32>& floor();
	Vec2<F32>& round();
	Vec2<F32>& sqrt();
	Vec2<F32>& normalize();

	Vec2<T> sign() const;
	Vec2<T> perpendicularVector() const;

	template<typename U>
	Vec2<U> cast() const;

	Vec2<T> yx() const;

public:
	union {
		T m_vec[2];
		struct { T x, y; };
	};

public:
	static Vec2<T> Null();
	static Vec2<T> Up();
	static Vec2<T> Right();
};

template<typename T>
bool operator==(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
bool operator!=(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
bool operator>(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
bool operator<(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
bool operator>=(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
bool operator<=(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T> operator*(const Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T> operator/(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> operator>>(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T> operator<<(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T> operator&(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T> operator^(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T> operator|(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);

template<typename T>
Vec2<T>& operator+=(Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T>& operator-=(Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T>& operator*=(Vec2<T>& v1, const Vec2<T>& v2);
template<typename T>
Vec2<T>& operator/=(Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T>& operator>>=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T>& operator<<=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T>& operator&=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T>& operator^=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec2<T>& operator|=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2);

template<typename T>
T Dot(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
T Cross(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> Normalize(const Vec2<T>& v);

template<typename T>
Vec2<T> Negate(const Vec2<T>& v);

template<typename T>
Vec2<T> Abs(const Vec2<T>& v);

inline Vec2f Rotate(const Vec2f& v, F32 Angle);
inline Vec2f Ceil(const Vec2f& v);
inline Vec2f Floor(const Vec2f& v);
inline Vec2f Round(const Vec2f& v);
inline Vec2f Sqrt(const Vec2f& v);

template<typename T>
F32 Distance(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> Direction(const Vec2<T>& origin, const Vec2<T>& destination);

inline Vec2f RotateAround(const Vec2f& v, const Vec2f& point, const F32 angle);
inline Vec2f RotateAround(const Vec2f& v, const Vec2f& point, const F32 angle, const F32 distance);

template<typename T>
Vec2<T> Min(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> Max(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
bool ArePerpendicular(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
bool AreColinear(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
bool AreOpposed(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
bool AreSameDirection(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
bool AreOpposedDirection(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec2<T>& v);

} //namespace maths
} //namespace drak
#include<Math/Vec2.inl>

DK_METADATA_BEGIN(drak::math::Vec2c)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2sc)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2s)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2us)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2i)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2u)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec2f)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END