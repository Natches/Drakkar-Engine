#pragma once

#include<Math/MathUtils.hpp>
#include<ostream>

namespace drak {
namespace math {
template<typename T>
struct Vec2 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");

	static constexpr bool isIntegral = std::is_integral_v<T>;
public:
	Vec2();

	Vec2(const T X, const T Y);
	Vec2(const Vec2<T>& v);
	Vec2(Vec2<T>&& v);
	~Vec2() = default;

public:
	bool operator==(const Vec2<T>& v) const;
	bool operator!=(const Vec2<T>& v) const;
	bool operator>(const Vec2<T>& v)  const;
	bool operator<(const Vec2<T>& v)  const;
	bool operator>=(const Vec2<T>& v) const;
	bool operator<=(const Vec2<T>& v) const;

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

	Vec2<T> conjugate() const;
	Vec2<T> normalize() const;
	Vec2<T> rotate(const F32 angle) const;
	Vec2<T> perpendicularVector() const;

	template<typename U>
	Vec2<U> cast() const;

	Vec2<F32> ceil();
	Vec2<F32> floor();
	Vec2<F32> round();

	Vec2<T> yx();

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
F32 Distance(const Vec2<T>& v1, const Vec2<T>& v2);

template<typename T>
Vec2<T> Direction(const Vec2<T>& origin, const Vec2<T>& destination);

template<typename T>
void RotateAround(Vec2<T>& v1, const Vec2<T>& point, const F32 angle);

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

using Vec2c    = typename Vec2<U8>;
using Vec2sc   = typename Vec2<I8>;
using Vec2s    = typename Vec2<I16>;
using Vec2us   = typename Vec2<U16>;
using Vec2i    = typename Vec2<I32>;
using Vec2u    = typename Vec2<U32>;
using Vec2f    = typename Vec2<F32>;

} //namespace maths
} //namespace drak
#include<Math/Vec2.inl>