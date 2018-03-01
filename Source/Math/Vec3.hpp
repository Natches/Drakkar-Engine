#pragma once

#include "MathUtils.hpp"

namespace drak {
namespace math {

template<typename T>
struct Vec3 {
#define x m_vec[0]
#define y m_vec[1]
#define z m_vec[2]
	static_assert(std::is_scalar_v<T>, "\"T\" must be a scalar Type");
	static constexpr bool isIntegral = std::is_integral_v<T>;
private:
	static constexpr bool isLarger = IS_LARGER_THAN_V(T, T*);
	using Type = ADD_REF_IF_T(isLarger, T);

public:
	Vec3();

	explicit Vec3(const Type X, const Type Y, const Type Z);
	explicit Vec3(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) X,
		ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) Y,
		ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) Z);

	Vec3(const Vec3<T>& v);
	Vec3(Vec3<T>&& v);
	~Vec3() = default;

public:
	bool operator==(const Vec3<T>& v) const;
	bool operator!=(const Vec3<T>& v) const;
	bool operator>(const Vec3<T>& v)  const;
	bool operator<(const Vec3<T>& v)  const;
	bool operator>=(const Vec3<T>& v) const;
	bool operator<=(const Vec3<T>& v) const;

	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

	template<Axis ax, AngleUnit au = AngleUnit::DEGREE>
	F32 rotation() const;

	template<AngleUnit au = AngleUnit::DEGREE>
	Vec3<T> rotation() const;
	//TODO : Quat<F32> rotation() const;

	Vec3<T>& operator  =(const Vec3<T>& v);
	Vec3<T>& operator  =(Vec3<T>&& v);
	Vec3<T>& operator +=(const Type n);
	Vec3<T>& operator -=(const Type n);
	Vec3<T>& operator *=(const Type n);
	Vec3<T>& operator /=(const Type n);
	Vec3<T>& operator +=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec3<T>& operator -=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec3<T>& operator *=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec3<T>& operator /=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n);
	Vec3<T>& operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator &=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator ^=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator |=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator++();
	Vec3<T>& operator--();

	Vec3<T> operator+(const Type n) const;
	Vec3<T> operator-(const Type n) const;
	Vec3<T> operator*(const Type n) const;
	Vec3<T> operator/(const Type n) const;
	Vec3<T> operator+(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec3<T> operator-(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec3<T> operator*(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec3<T> operator/(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE) n) const;
	Vec3<T> operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator&(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator^(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator|(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator++(const I32) const;
	Vec3<T> operator--(const I32) const;
	Vec3<T> operator-()	  const;

	Vec3<T> conjugate() const;
	Vec3<T> normalize() const;
	template<Axis ax>
	Vec3<T> rotate(const F32 angle) const;
	template<Axis ax>
	Vec3<T> rotate(const Vec3<T>& euler) const;
	//Todo template<Axis ax>
	//Todo Vec3<T> rotate(const Vec3<T>& euler) const;

	template<typename U>
	Vec3<U> cast() const;

private:
	F32 computeAngleX();
	F32 computeAngleY();
	F32 computeAngleZ();

public:
	T m_vec[3];
};

template<typename T>
Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T> operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T> operator&(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T> operator^(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T> operator|(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);

template<typename T>
Vec3<T>& operator+=(Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T>& operator-=(Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T>& operator*=(Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
Vec3<T>& operator/=(Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T>& operator>>=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T>& operator<<=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T>& operator&=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T>& operator^=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec3<T>& operator|=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2);

template<typename T>
F32 Dot(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
F32 Distance(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> Direction(const Vec3<T>& origin, const Vec3<T>& destination);

template<typename T>
template<Axis ax>
void RotateAround(Vec3<T>& v1, const Vec3<T>& point, const F32 angle);

template<typename T>
bool ArePerpendicular(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
bool AreColinear(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
bool AreOpposed(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
bool AreSameDirection(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
bool AreOpposedDirection(const Vec3<T>& v1, const Vec3<T>& v2);

using Vec3c = typename Vec3<U8>;
using Vec3sc = typename Vec3<I8>;
using Vec3si = typename Vec3<I16>;
using Vec3sui = typename Vec3<U16>;
using Vec3i = typename Vec3<I32>;
using Vec3ui = typename Vec3<U32>;
using Vec3lli = typename Vec3<I64>;
using Vec3ulli = typename Vec3<U64>;
using Vec3f = typename Vec3<F32>;
using Vec3d = typename Vec3<F64>;

} //namespace maths
} //namespace drak
#include "Vec3.inl"