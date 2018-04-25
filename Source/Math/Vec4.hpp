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
	DK_SERIALIZED_OBJECT(Vec4<T>)
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
	Vec4(T W, const Vec3<T>& v);
	Vec4(T W, Vec3<T>&& v);
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
	Vec4<T> abs()		const;
	Vec4<T> sign()		const;

	/*template<Axis ax>
	Vec4<T> rotate(const F32 angle) const;
	template<Axis ax>
	Vec4<T> rotate(const Vec4<T>& euler) const;*/
	//Todo template<Axis ax>
	//Todo Vec4<T> rotate(const Vec4<T>& euler) const;

	template<typename U>
	Vec4<U> cast() const;

	Vec4<F32> ceil()	const;
	Vec4<F32> floor()	const;
	Vec4<F32> round()	const;
	Vec4<F32> sqrt()	const;

	Vec2<T> yz() const;
	Vec2<T> yx() const;
	Vec2<T> wz() const;
	Vec2<T> zy() const;

	Vec3<T> zyx() const;
	Vec3<T> yzx() const;
	Vec3<T> zxy() const;

	Vec3<T> bgr() const;
	Vec3<T> gbr() const;
	Vec3<T> brg() const;

	Vec3<T> wyz() const;
	Vec3<T> zyw() const;
	Vec3<T> zwy() const;

	Vec4<T> bgra() const;
	Vec4<T> gbra() const;
	Vec4<T> brga() const;

private:
	/*F32 computeAngleX();
	F32 computeAngleY();
	F32 computeAngleZ();*/

public:
	union alignas(SIMDStruct::alignement) {
		T m_vec[4];
		struct { T x, y, z, w; };
		struct { T r, g, b, a; };
		struct { Vec3<T> xyz; };
		struct { Vec3<T> rgb; };
		struct { Vec2<T> xy, zw; };
		struct { Vec2<T> rg, ba; };
		struct { T padding1; Vec3<T> yzw; };
		struct { T padding2; Vec3<T> gba; };
		SIMDType m_simdVec;
	};

public:
	static Vec4<T> Null();
	static Vec4<T> Up();
	static Vec4<T> Right();
	static Vec4<T> Forward();
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

using Vec4c  = typename Vec4<U8>;
using Vec4sc = typename Vec4<I8>;
using Vec4s  = typename Vec4<I16>;
using Vec4us = typename Vec4<U16>;
using Vec4i  = typename Vec4<I32>;
using Vec4u  = typename Vec4<U32>;
using Vec4f  = typename Vec4<F32>;

} //namespace maths
} //namespace drak
#include<Math/Vec4.inl>

DK_METADATA_BEGIN(drak::math::Vec4c)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4sc)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4s)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4us)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4i)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4u)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec4f)
DK_PUBLIC_FIELDS(m_simdVec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END