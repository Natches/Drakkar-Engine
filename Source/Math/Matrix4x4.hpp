#pragma once

#include<Math/Vec8.hpp>

namespace drak {
namespace math {

template<typename T>
struct Matrix4x4 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64), DK_MATH_ERROR0(T));
	DK_SERIALIZED_OBJECT(Matrix4x4<T>)
public:
	Matrix4x4();
	Matrix4x4(const T f1, const T f2, const T f3, const T f4,
		const T f5, const T f6, const T f7, const T f8,
		const T f9, const T f10, const T f11, const T f12,
		const T f13, const T f14, const T f15, const T f16);
	Matrix4x4(const T* arr);
	Matrix4x4(const Vec8<T>& v1, const Vec8<T>& v2);
	Matrix4x4(Vec8<T>&& v1, Vec8<T>&& v2);
	Matrix4x4(const Vec4<T>& v1, const Vec4<T>& v2, const Vec4<T>& v3, const Vec4<T>& v4);
	Matrix4x4(Vec4<T>&& v1, Vec4<T>&& v2, Vec4<T>&& v3, Vec4<T>&& v4);
	Matrix4x4(const Matrix4x4<T>& m);
	Matrix4x4(Matrix4x4<T>&& m);

public:
	Matrix4x4<T>& operator=(const Matrix4x4<T>& m);
	Matrix4x4<T>& operator=(Matrix4x4<T>&& m);

public:
	bool isIdentity() const;
	bool isOrthogonal() const;

public:
	Matrix4x4<T>& operator+=(const T n);
	Matrix4x4<T>& operator-=(const T n);
	Matrix4x4<T>& operator*=(const T n);
	Matrix4x4<T>& operator/=(const T n);

	Matrix4x4<T> operator+(const T n) const;
	Matrix4x4<T> operator-(const T n) const;
	Matrix4x4<T> operator*(const T n) const;
	Matrix4x4<T> operator/(const T n) const;

	Matrix4x4<T>& transpose();
	Matrix4x4<F32>& inverse();
	Matrix4x4<T>& minor();
	Matrix4x4<T>& cofactor();
	Matrix4x4<T>& adjugate();
	F32 determinant() const;

public:
	union {
		T m_mat[16];
		struct { Vec8<T> m_row12, m_row34; };
		struct { Vec4<T> m_row1, m_row2, m_row3, m_row4; };
		struct { T a00, a01, a02, a03, a10, a11, a12, a13, a20, a21, a22,
			a23, a30, a31, a32, a33; };
	};
};

using Mat4c = typename Matrix4x4<U8>;
using Mat4sc = typename Matrix4x4<I8>;
using Mat4s = typename Matrix4x4<I16>;
using Mat4us = typename Matrix4x4<U16>;
using Mat4i = typename Matrix4x4<I32>;
using Mat4u = typename Matrix4x4<U32>;
using Mat4f = typename Matrix4x4<F32>;

template<typename T>
bool operator==(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);
template<typename T>
bool operator!=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);
template<typename T>
bool operator>(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);
template<typename T>
bool operator<(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);
template<typename T>
bool operator>=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);
template<typename T>
bool operator<=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);

template<typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);

template<typename T>
 Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const Matrix4x4<T>& m2);

template<typename T>
Vec4<T> operator*(const Matrix4x4<T>& m, const Vec4<T>& v);

template<typename T>
Vec4<T>& operator*=(const Matrix4x4<T>& m, Vec4<T>& v);

template<typename T>
Vec3<T> operator*(const Matrix4x4<T>& m, const Vec3<T>& v);

template<typename T>
Vec3<T>& operator*=(const Matrix4x4<T>& m, Vec3<T>& v);

template<typename T>
Matrix4x4<T> Transpose(const Matrix4x4<T>& m);

inline Mat4f Inverse(const Mat4f& m);

template<typename T>
Matrix4x4<T> Minor(const Matrix4x4<T>& m);

template<typename T>
Matrix4x4<T> Cofactor(const Matrix4x4<T>& m);

template<typename T>
Matrix4x4<T> Adjugate(const Matrix4x4<T>& m);

template<typename T>
Matrix4x4<T> Scale(const Vec3<T>& v);

template<typename T>
Matrix4x4<T> Translate(const Vec3<T>& v);

template<typename T>
Matrix4x4<T>& Scale(Matrix4x4<T>& m, const Vec3<T>& v);

template<typename T>
Matrix4x4<T>& Translate(Matrix4x4<T>& m, const Vec3<T>& v);

template<typename T>
Matrix4x4<T> Identity();

template<AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32> Rotation(const Vec3<F32>& euler);

template<AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32> RotationX(F32 angleX);

template<AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32> RotationY(F32 angleY);

template<AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32> RotationZ(F32 angleZ);

template<typename T>
std::ostream& operator<<(std::ostream& o, const Matrix4x4<T>& v);

} //namespace math
} //namespace drak
#include<Math/Matrix4x4.inl>


DK_METADATA_BEGIN(drak::math::Mat4c)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4sc)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4s)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4us)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4i)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4u)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(drak::math::Mat4f)
DK_PUBLIC_FIELDS(m_row12, m_row34)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END