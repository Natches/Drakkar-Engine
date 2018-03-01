#pragma once

#include "MathUtils.hpp"

namespace drak {
namespace math {

template<typename T>
struct Vec2 {
#define x m_vec[0]
#define y m_vec[1]
	static_assert(std::is_scalar_v<T>, "\"T\" must be a scalar Type");
	static constexpr bool isIntegral = std::is_integral_v<T>;
private:
	static constexpr bool isLarger = IS_LARGER_THAN_V(T, T*);
	using Type = ADD_REF_IF_T(isLarger, T);

public:
	Vec2();

	explicit Vec2(const Type X, const Type Y);
	explicit Vec2(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) X,
		ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) Y);

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
	Vec2<T>& operator+=(const Type n);
	Vec2<T>& operator-=(const Type n);
	Vec2<T>& operator*=(const Type n);
	Vec2<T>& operator/=(const Type n);
	Vec2<T>& operator+=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec2<T>& operator-=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec2<T>& operator*=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec2<T>& operator/=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec2<T>& operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator&=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator^=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator|=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec2<T>& operator++();
	Vec2<T>& operator--();

	Vec2<T> operator+(const Type n) const;
	Vec2<T> operator-(const Type n) const;
	Vec2<T> operator*(const Type n) const;
	Vec2<T> operator/(const Type n) const;
	Vec2<T> operator+(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec2<T> operator-(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec2<T> operator*(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec2<T> operator/(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec2<T> operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator&(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator^(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator|(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec2<T> operator++(const I32) const;
	Vec2<T> operator--(const I32) const;
	Vec2<T> operator-()	  const;

	Vec2<T> conjugate() const;
	Vec2<T> normalize() const;
	Vec2<T> rotate(const F32 angle) const;
	Vec2<T> perpendicularVector() const;

	template<typename U>
	Vec2<U> cast() const;

public:
	T m_vec[2];
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
Vec2<T> Cross(const Vec2<T>& v1, const Vec2<T>& v2);

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

using Vec2c    = typename Vec2<U8>;
using Vec2sc   = typename Vec2<I8>;
using Vec2si   = typename Vec2<I16>;
using Vec2sui  = typename Vec2<U16>;
using Vec2i    = typename Vec2<I32>;
using Vec2ui   = typename Vec2<U32>;
using Vec2lli  = typename Vec2<I64>;
using Vec2ulli = typename Vec2<U64>;
using Vec2f    = typename Vec2<F32>;
using Vec2d    = typename Vec2<F64>;

} //namespace maths
} //namespace drak
#include "Vec2.inl"