#pragma once

#include<Math/MathUtils.hpp>
#include<Math/Vec2.hpp>
#include<ostream>

namespace drak {
namespace math {

template<typename T>
struct Vec4;

template<typename T>
struct Vec3 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");
	static constexpr bool isIntegral = std::is_integral_v<T>;
public:
	Vec3();
	Vec3(const T X, const T Y, const T Z);
	Vec3(const Vec4<T>& v);
	Vec3(Vec4<T>&& v);
	Vec3(const Vec3<T>& v);
	Vec3(Vec3<T>&& v);
	Vec3(const Vec2<T>& v);
	Vec3(Vec2<T>&& v);
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
	Vec3<T>& operator +=(const T n);
	Vec3<T>& operator -=(const T n);
	Vec3<T>& operator *=(const T n);
	Vec3<T>& operator /=(const T n);
	Vec3<T>& operator>>=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator<<=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator &=(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator ^=(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator |=(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n);
	Vec3<T>& operator++();
	Vec3<T>& operator--();

	Vec3<T> operator+(const T n) const;
	Vec3<T> operator-(const T n) const;
	Vec3<T> operator*(const T n) const;
	Vec3<T> operator/(const T n) const;
	Vec3<T> operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator&(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator^(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator|(const  ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE) n) const;
	Vec3<T> operator++(const I32) const;
	Vec3<T> operator--(const I32) const;
	Vec3<T> operator-()	  const;

	Vec3<T> conjugate() const;
	Vec3<T> normalize() const;
	/*template<Axis ax>
	Vec3<T> rotate(const F32 angle) const;
	template<Axis ax>
	Vec3<T> rotate(const Vec3<T>& euler) const;*/
	//Todo template<Axis ax>
	//Todo Vec3<T> rotate(const Vec3<T>& euler) const;

	template<typename U>
	Vec3<U> cast() const;

	Vec3<F32> ceil();
	Vec3<F32> floor();
	Vec3<F32> round();

	Vec2<T> xy();
	Vec2<T> yz();
	Vec2<T> yx();
	Vec2<T> zy();
	Vec2<T> xz();
	Vec2<T> zx();

	Vec3<T> zyx();
	Vec3<T> yzx();
	Vec3<T> zxy();

	Vec3<T> bgr();
	Vec3<T> gbr();
	Vec3<T> brg();

private:
	F32 computeAngleX();
	F32 computeAngleY();
	F32 computeAngleZ();

public:
	union {
		T m_vec[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
	};

public:
	static Vec3<T> Null();
	static Vec3<T> Up();
	static Vec3<T> Right();
	static Vec3<T> Forward();
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
T Dot(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
F32 Distance(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> Direction(const Vec3<T>& origin, const Vec3<T>& destination);

/*
template<Axis ax, typename T>
void RotateAround(Vec3<T>& v1, const Vec3<T>& point, const F32 angle);

template<Axis ax, typename T>
void RotateAround(Vec3<T>& v1, const Vec3<T>& point, const Vec3<T>& euler);*/

//TODO template<typename T>
//TODO template<Axis ax>
//TODO void RotateAround(Vec3<T>& v1, const Vec3<T>& point, const Quat<T>& q);

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

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec3<T>& v);

using Vec3c  = typename Vec3<U8>;
using Vec3sc = typename Vec3<I8>;
using Vec3s  = typename Vec3<I16>;
using Vec3us = typename Vec3<U16>;
using Vec3i  = typename Vec3<I32>;
using Vec3u  = typename Vec3<U32>;
using Vec3f  = typename Vec3<F32>;

} //namespace maths
} //namespace drak
#include<Math/Vec3.inl>