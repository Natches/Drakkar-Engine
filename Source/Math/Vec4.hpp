#pragma once

#include <Math/MathUtils.hpp>
#include <Math/SIMDUtils.hpp>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>
#include<ostream>

namespace drak {
namespace math {

template<typename T>
struct Vec4 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");
	static constexpr bool isIntegral = std::is_integral_v<T>;
	using SIMDStruct = typename SIMDUtils::BestSIMDType<T, 4>;
	using SIMDType = typename SIMDStruct::SIMDType;

public:
	Vec4();
	Vec4(T* arr);
	Vec4(const T X, const T Y, const T Z, const T W);

	Vec4(const Vec4<T>& v);
	Vec4(Vec4<T>&& v);
	Vec4(const SIMDType& ss);
	Vec4(const Vec2<T>& v);
	Vec4(Vec2<T>&& v);
	Vec4(const Vec2<T>& v1, const Vec2<T>& v2);
	Vec4(Vec2<T>&& v1, Vec2<T>&& v2);
	Vec4(const Vec3<T>& v);
	Vec4(Vec3<T>&& v);
	Vec4(const Vec3<T>& v, T W);
	Vec4(Vec3<T>&& v, T W);
	~Vec4() = default;

public:
	bool operator==(const Vec4<T>& v) const;
	bool operator!=(const Vec4<T>& v) const;
	bool operator>(const Vec4<T>& v)  const;
	bool operator<(const Vec4<T>& v)  const;
	bool operator>=(const Vec4<T>& v) const;
	bool operator<=(const Vec4<T>& v) const;

	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

/*
	template<Axis ax, AngleUnit au = AngleUnit::DEGREE>
	F32 rotation() const;

	template<AngleUnit au = AngleUnit::DEGREE>
	Vec4<T> rotation() const;
	//TODO : Quat<F32> rotation() const;*/

	Vec4<T>& operator  =(const Vec4<T>& v);
	Vec4<T>& operator  =(Vec4<T>&& v);
	Vec4<T>& operator +=(const T n);
	Vec4<T>& operator -=(const T n);
	Vec4<T>& operator *=(const T n);
	Vec4<T>& operator /=(const T n);
	Vec4<T>& operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec4<T>& operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec4<T>& operator &=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec4<T>& operator ^=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec4<T>& operator |=(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n);
	Vec4<T>& operator++();
	Vec4<T>& operator--();

	Vec4<T> operator+(const T n) const;
	Vec4<T> operator-(const T n) const;
	Vec4<T> operator*(const T n) const;
	Vec4<T> operator/(const T n) const;
	Vec4<T> operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec4<T> operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec4<T> operator&(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec4<T> operator^(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec4<T> operator|(const  ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE) n) const;
	Vec4<T> operator++(const I32) const;
	Vec4<T> operator--(const I32) const;
	Vec4<T> operator-()	  const;

	Vec4<T> conjugate() const;
	Vec4<T> normalize() const;

	/*template<Axis ax>
	Vec4<T> rotate(const F32 angle) const;
	template<Axis ax>
	Vec4<T> rotate(const Vec4<T>& euler) const;*/
	//Todo template<Axis ax>
	//Todo Vec4<T> rotate(const Vec4<T>& euler) const;

	template<typename U>
	Vec4<U> cast() const;

	Vec4<F32> ceil();
	Vec4<F32> floor();
	Vec4<F32> round();

	Vec2<T> xy();
	Vec2<T> zw();
	Vec2<T> yz();
	Vec2<T> yx();
	Vec2<T> wz();
	Vec2<T> zy();

	Vec3<T> xyz();
	Vec3<T> zyx();
	Vec3<T> yzx();
	Vec3<T> zxy();

	Vec3<T> rgb();
	Vec3<T> bgr();
	Vec3<T> gbr();
	Vec3<T> brg();

	Vec3<T> wyz();
	Vec3<T> zyw();
	Vec3<T> yzw();
	Vec3<T> zwy();

	Vec4<T> bgra();
	Vec4<T> gbra();
	Vec4<T> brga();

private:
	/*F32 computeAngleX();
	F32 computeAngleY();
	F32 computeAngleZ();*/

public:
	union alignas(SIMDStruct::alignement) {
		T m_vec[4];
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		SIMDType m_simdVec;
	};
};

template<typename T>
Vec4<T> operator+(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T> operator-(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T> operator*(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T> operator/(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> operator>>(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T> operator<<(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T> operator&(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T> operator^(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T> operator|(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);

template<typename T>
Vec4<T>& operator+=(Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T>& operator-=(Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T>& operator*=(Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
Vec4<T>& operator/=(Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T>& operator>>=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T>& operator<<=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T>& operator&=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T>& operator^=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);
template<typename T>
Vec4<T>& operator|=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2);

template<typename T>
T Dot(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Cross(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
F32 Distance(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Direction(const Vec4<T>& origin, const Vec4<T>& destination);

template<typename T>
Vec4<T> Min(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Max(const Vec4<T>& v1, const Vec4<T>& v2);

/*
template<Axis ax, typename T>
void RotateAround(Vec4<T>& v1, const Vec4<T>& point, const F32 angle);*/

/*
template<typename T>
template<Axis ax>
void RotateAround(Vec4<T>& v1, const Vec4<T>& point, const Vec4<T>& euler);*/

//TODO template<typename T>
//TODO template<Axis ax>
//TODO void RotateAround(Vec4<T>& v1, const Vec4<T>& point, const Quat<T>& q);

template<typename T>
bool ArePerpendicular(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
bool AreColinear(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
bool AreOpposed(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
bool AreSameDirection(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
bool AreOpposedDirection(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec4<T>& v);

using Vec4c = typename Vec4<U8>;
using Vec4sc = typename Vec4<I8>;
using Vec4s = typename Vec4<I16>;
using Vec4us = typename Vec4<U16>;
using Vec4i = typename Vec4<I32>;
using Vec4ui = typename Vec4<U32>;
using Vec4lli = typename Vec4<I64>;
using Vec4ulli = typename Vec4<U64>;
using Vec4f = typename Vec4<F32>;
using Vec4d = typename Vec4<F64>;

} //namespace maths
} //namespace drak
#include<Math/Vec4.inl>
