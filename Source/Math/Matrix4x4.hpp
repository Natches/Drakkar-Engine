#pragma once

#include<Math/Vec8.hpp>

namespace drak {
namespace math {

template<typename T>
struct Matrix4x4 {
public:
	Matrix4x4();
	Matrix4x4(const T f1, const T f2, const T f3, const T f4,
		const T f5, const T f6, const T f7, const T f8,
		const T f9, const T f10, const T f11, const T f12,
		const T f13, const T f14, const T f15, const T f16);
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

	Matrix4x4<T> transpose() const;

public:
	union {
		T m_mat[16];
		struct { Vec8<T> row12, row34; };
		struct { Vec4<T> row1, row2, row3, row4; };
		struct { T a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p; };
	};
};

template<typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2);

template<typename T>
Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const Matrix4x4<T>& m2);

} //namespace math
} //namespace drak
#include<Math/Matrix4x4.inl>