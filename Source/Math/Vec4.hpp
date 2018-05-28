#pragma once

#include <Math/Vec4.fwd>
#include <Math/MathUtils.hpp>
#include <Math/SIMDUtils.hpp>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>

namespace drak {
namespace math {

template<typename T>
struct Vec4 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64), DK_MATH_ERROR0(T));
	static constexpr bool isIntegral = std::is_integral_v<T>;

	using SIMDStruct = typename SIMDUtils::BestSIMDType<T, 4>;
	using SIMDType = typename SIMDStruct::SIMDType;

	DK_SERIALIZED_OBJECT(Vec4<T>)
public:
	Vec4();
	explicit Vec4(const T n);
	explicit Vec4(T* arr);
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
	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

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

	Vec4<T>& negate();
	Vec4<T>& abs();

//#if defined(QUAT)
	template<Axis ax>
	Vec4<F32>& rotate(const F32 angle);
	inline Vec4<F32>& rotate(const Vec3<F32>& axis, const F32 angle);
	inline Vec4<F32>& rotate(const Vec3<F32>& euler);
	inline Vec4<F32>& rotateAround(const Vec4<F32>& point, const F32 angle);
	inline Vec4<F32>& rotateAround(const Vec4<F32>& point, const F32 angle, const F32 distance);
//#endif
	Vec4<F32>& ceil();
	Vec4<F32>& floor();
	Vec4<F32>& round();
	Vec4<F32>& sqrt();
	Vec4<F32>& normalize();

	Vec4<T> sign() const;

	template<typename U>
	Vec4<U> cast() const;

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
bool operator==(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
bool operator!=(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
bool operator>(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
bool operator<(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
bool operator>=(const Vec4<T>& v1, const Vec4<T>& v2);
template<typename T>
bool operator<=(const Vec4<T>& v1, const Vec4<T>& v2);

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

inline Vec4f operator/(F32 f1, const Vec4f& v);

template<typename T>
T Dot(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Cross(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
F32 Distance(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Direction(const Vec4<T>& origin, const Vec4<T>& destination);

inline Vec4f Normalize(const Vec4f& v);

template<typename T>
Vec4<T> Negate(const Vec4<T>& v);

template<typename T>
Vec4<T> Abs(const Vec4<T>& v);

inline Vec4f Ceil(const Vec4f& v);
inline Vec4f Floor(const Vec4f& v);
inline Vec4f Round(const Vec4f& v);
inline Vec4f Sqrt(const Vec4f& v);

//#if defined(QUAT)
template<Axis ax>
inline Vec4f Rotate(const Vec4f& v, const F32 angle);

inline Vec4f Rotate(const Vec4f& v, const Vec3f& axis, const F32 angle);

inline Vec4f Rotate(const Vec4f& v, const Vec3f& euler);

template<Axis ax>
inline Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const F32 angle);

inline Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const Vec3f& euler);

template<Axis ax>
inline Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const F32 angle, const F32 distance);

inline Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const Vec3f& euler, const F32 distance);
//#endif

template<typename T>
Vec4<T> Min(const Vec4<T>& v1, const Vec4<T>& v2);

template<typename T>
Vec4<T> Max(const Vec4<T>& v1, const Vec4<T>& v2);

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

template<typename T, AngleUnit unit = AngleUnit::DEGREE>
F32 Angle(const Vec4<T>& va, const Vec4<T>& vb);

inline Vec4f Lerp(const Vec4f& start, const Vec4f& end, F32 percent);
inline Vec4f SLerp(const Vec4f& start, const Vec4f& end, F32 percent);
inline Vec4f NLerp(const Vec4f& start, const Vec4f& end, F32 percent);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec4<T>& v);

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
