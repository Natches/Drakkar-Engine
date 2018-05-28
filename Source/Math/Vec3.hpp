#pragma once

#include <Math/Vec4.fwd>
#include <Math/Vec3.fwd>
#include <Math/Vec2.hpp>

namespace drak {
namespace math {

template<typename T>
struct Vec3 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) < 64), DK_MATH_ERROR0(T));
	static constexpr bool isIntegral = std::is_integral_v<T>;
	DK_SERIALIZED_OBJECT(Vec3<T>)
public:
	Vec3();
	explicit Vec3(const T n);
	explicit Vec3(T* arr);
	Vec3(const T X, const T Y, const T Z);
	Vec3(const Vec4<T>& v);
	Vec3(Vec4<T>&& v);
	Vec3(const Vec3<T>& v);
	Vec3(Vec3<T>&& v);
	Vec3(const Vec2<T>& v);
	Vec3(Vec2<T>&& v);
	Vec3(const Vec2<T>& v, const T Z);
	Vec3(Vec2<T>&& v, const T Z);
	Vec3(const T X, const Vec2<T>& v);
	Vec3(const T X, Vec2<T>&& v);
	~Vec3() = default;

public:
	bool isNormalized() const;
	bool isNull() const;

	F32 magnitude() const;

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

	Vec3<T>& negate();
	Vec3<T>& abs();

//#if defined(QUAT)
	template<Axis ax>
	Vec3<F32>& rotate(const F32 angle);
	inline Vec3<F32>& rotate(const Vec3<F32>& axis, const F32 angle);
	inline Vec3<F32>& rotate(const Vec3<F32>& euler);
	inline Vec3<F32>& rotateAround(const Vec3<F32>& point, const F32 angle);
	inline Vec3<F32>& rotateAround(const Vec3<F32>& point, const F32 angle, const F32 distance);
//#endif
	Vec3<F32>& ceil();
	Vec3<F32>& floor();
	Vec3<F32>& round();
	Vec3<F32>& sqrt();
	Vec3<F32>& normalize();

	Vec3<T> sign() const;

	template<typename U>
	Vec3<U> cast() const;

	Vec2<T> yx() const;
	Vec2<T> zy() const;
	Vec2<T> xz() const;
	Vec2<T> zx() const;

	Vec3<T> zyx() const;
	Vec3<T> yzx() const;
	Vec3<T> zxy() const;

	Vec2<T> gr() const;
	Vec2<T> bg() const;
	Vec2<T> rb() const;
	Vec2<T> br() const;

	Vec3<T> bgr() const;
	Vec3<T> gbr() const;
	Vec3<T> brg() const;

public:
	union {
		T m_vec[3];
		struct { T x, y, z; };
		struct { T r, g, b; };
		struct { Vec2<T> xy; };
		struct { Vec2<T> rg; };
		struct { T padding1;  Vec2<T> yz; };
		struct { T padding2;  Vec2<T> gb; };
	};

public:
	static Vec3<T> Null();
	static Vec3<T> Up();
	static Vec3<T> Right();
	static Vec3<T> Forward();
};

template<typename T>
bool operator==(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
bool operator!=(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
bool operator>(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
bool operator<(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
bool operator>=(const Vec3<T>& v1, const Vec3<T>& v2);
template<typename T>
bool operator<=(const Vec3<T>& v1, const Vec3<T>& v2);

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

inline Vec3f Normalize(const Vec3f& v);

template<typename T>
Vec3<T> Negate(const Vec3<T>& v);

template<typename T>
Vec3<T> Abs(const Vec3<T>& v);

inline Vec3f Ceil(const Vec3f& v);
inline Vec3f Floor(const Vec3f& v);
inline Vec3f Round(const Vec3f& v);
inline Vec3f Sqrt(const Vec3f& v);
//#if defined(QUAT)
template<Axis ax>
inline Vec3f Rotate(const Vec3f& v, const F32 angle);

inline Vec3f Rotate(const Vec3f& v, const Vec3f& axis, const F32 angle);

inline Vec3f Rotate(const Vec3f& v, const Vec3f& euler);

template<Axis ax>
inline Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const F32 angle);

inline Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const Vec3f& euler);

template<Axis ax>
inline Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const F32 angle, const F32 distance);

inline Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const Vec3f& euler, const F32 distance);
//#endif
template<typename T>
Vec3<T> Min(const Vec3<T>& v1, const Vec3<T>& v2);

template<typename T>
Vec3<T> Max(const Vec3<T>& v1, const Vec3<T>& v2);

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

template<typename T, AngleUnit unit = AngleUnit::DEGREE>
F32 Angle(const Vec3<T>& va, const Vec3<T>& vb);

inline Vec3f Lerp(const Vec3f& start, const Vec3f& end, F32 percent);
inline Vec3f SLerp(const Vec3f& start, const Vec3f& end, F32 percent);
inline Vec3f NLerp(const Vec3f& start, const Vec3f& end, F32 percent);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec3<T>& v);

} //namespace maths
} //namespace drak
#include<Math/Vec3.inl>

DK_METADATA_BEGIN(drak::math::Vec3c)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3sc)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3s)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3us)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3i)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3u)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Vec3f)
DK_PUBLIC_FIELDS(m_vec)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
