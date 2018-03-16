#pragma once

#include<Math/Vec8.hpp>

namespace drak {
namespace math {

enum class Ordering : U8 {
	ROW_MAJOR,
	COLUMN_MAJOR
};

#pragma region RowOrdered
template<typename T, Ordering order = Ordering::ROW_MAJOR>
struct Matrix4x4 {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");
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
	Matrix4x4<T>& operator=(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m);
	Matrix4x4<T>& operator=(Matrix4x4<T, Ordering::COLUMN_MAJOR>&& m);

public:
	bool operator==(const Matrix4x4<T>& m) const;
	bool operator!=(const Matrix4x4<T>& m) const;
	bool operator>(const Matrix4x4<T>& m) const;
	bool operator<(const Matrix4x4<T>& m) const;
	bool operator>=(const Matrix4x4<T>& m) const;
	bool operator<=(const Matrix4x4<T>& m) const;
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

	Matrix4x4<T, Ordering::COLUMN_MAJOR> transpose() const;
	Matrix4x4<T, Ordering::COLUMN_MAJOR> toColumnMajor() const;

public:
	union {
		T m_mat[16];
		struct { Vec8<T> m_row12, m_row34; };
		struct { Vec4<T> m_row1, m_row2, m_row3, m_row4; };
		struct { T a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; };
	};
};
#pragma endregion RowOrdered

#pragma region ColumnOrdered
template<typename T>
struct Matrix4x4<T, Ordering::COLUMN_MAJOR> {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64),
		"\"T\" must be a scalar Type and not a 64 bits data type");
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
	Matrix4x4(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m);
	Matrix4x4(Matrix4x4<T, Ordering::COLUMN_MAJOR>&& m);

public:
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator=(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator=(Matrix4x4<T, Ordering::COLUMN_MAJOR>&& m);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator=(const Matrix4x4<T>& m);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator=(Matrix4x4<T>&& m);

public:
	bool operator==(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool operator!=(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool operator>(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool operator<(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool operator>=(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool operator<=(const Matrix4x4<T, Ordering::COLUMN_MAJOR>& m) const;
	bool isIdentity() const;
	bool isOrthogonal() const;

public:
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator+=(const T n);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator-=(const T n);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator*=(const T n);
	Matrix4x4<T, Ordering::COLUMN_MAJOR>& operator/=(const T n);

	Matrix4x4<T, Ordering::COLUMN_MAJOR> operator+(const T n) const;
	Matrix4x4<T, Ordering::COLUMN_MAJOR> operator-(const T n) const;
	Matrix4x4<T, Ordering::COLUMN_MAJOR> operator*(const T n) const;
	Matrix4x4<T, Ordering::COLUMN_MAJOR> operator/(const T n) const;

	Matrix4x4<T> transpose() const;
	Matrix4x4<T> toRowMajor() const;

public:
	union {
		T m_mat[16];
		struct { Vec8<T> m_col12, m_col34; };
		struct { Vec4<T> m_col1, m_col2, m_col3, m_col4; };
		struct { T a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; };
	};
};
#pragma endregion ColumnOrdered


#define MATRIX_ROW_MAJOR(T) Matrix4x4<T>
#define MATRIX_COLUMN_MAJOR(T) Matrix4x4<T, Ordering::COLUMN_MAJOR>


template<typename T, Ordering order>
Matrix4x4<T, order> operator*(const Matrix4x4<T, order>& m1, const Matrix4x4<T, order>& m2);

template<typename T, Ordering order>
 Matrix4x4<T, order>& operator*=(Matrix4x4<T, order>& m1, const Matrix4x4<T, order>& m2);

 template<typename T>
 Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const MATRIX_COLUMN_MAJOR(T)& m2);

 template<typename T>
 Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const  MATRIX_COLUMN_MAJOR(T)& m2);

 template<typename T>
 MATRIX_COLUMN_MAJOR(T) operator*(const MATRIX_COLUMN_MAJOR(T)& m1, const Matrix4x4<T>& m2);

 template<typename T>
 MATRIX_COLUMN_MAJOR(T)& operator*=(MATRIX_COLUMN_MAJOR(T)& m1, const  Matrix4x4<T>& m2);

template<typename T, Ordering order>
Vec4<T> operator*(const Matrix4x4<T, order>& m, const Vec4<T>& v);

template<typename T, Ordering order>
Vec4<T>& operator*=(const Matrix4x4<T, order>& m, Vec4<T>& v);

template<typename T, Ordering order>
Vec3<T> operator*(const Matrix4x4<T, order>& m, const Vec3<T>& v);

template<typename T, Ordering order>
Vec3<T>& operator*=(const Matrix4x4<T, order>& m, Vec3<T>& v);

template<typename T, Ordering order = Ordering::ROW_MAJOR>
Matrix4x4<T, order> Scale(const Vec3<T>& v);

template<typename T, Ordering order = Ordering::ROW_MAJOR>
Matrix4x4<T, order> Translate(const Vec3<T>& v);

template<typename T, Ordering order>
Matrix4x4<T, order>& Scale(Matrix4x4<T, order>& m, const Vec3<T>& v);

template<typename T, Ordering order>
Matrix4x4<T, order>& Translate(Matrix4x4<T, order>& m, const Vec3<T>& v);

template<typename T, Ordering order = Ordering::ROW_MAJOR>
Matrix4x4<T, order> Identity();

template<Ordering order = Ordering::ROW_MAJOR, AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32, order> Rotation(const Vec3<F32>& euler);

template<Ordering order = Ordering::ROW_MAJOR, AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32, order> RotationX(F32 angleX);

template<Ordering order = Ordering::ROW_MAJOR, AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32, order> RotationY(F32 angleY);

template<Ordering order = Ordering::ROW_MAJOR, AngleUnit unit = AngleUnit::DEGREE>
Matrix4x4<F32, order> RotationZ(F32 angleZ);

template<typename T, Ordering order>
std::ostream& operator<<(std::ostream& o, const Matrix4x4<T, order>& v);

using Mat4x4c    = typename Matrix4x4<U8>;
using Mat4x4sc   = typename Matrix4x4<I8>;
using Mat4x4s    = typename Matrix4x4<I16>;
using Mat4x4us   = typename Matrix4x4<U16>;
using Mat4x4i    = typename Matrix4x4<I32>;
using Mat4x4ui   = typename Matrix4x4<U32>;
using Mat4x4lli  = typename Matrix4x4<I64>;
using Mat4x4ulli = typename Matrix4x4<U64>;
using Mat4x4f    = typename Matrix4x4<F32>;
using Mat4x4d    = typename Matrix4x4<F64>;
} //namespace math
} //namespace drak
#include<Math/Matrix4x4.inl>