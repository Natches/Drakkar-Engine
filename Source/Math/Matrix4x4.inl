#include<Math/Matrix4x4.hpp>

namespace drak {
namespace math {

template<typename T>
Matrix4x4<T>::Matrix4x4() {
}
template<typename T>
Matrix4x4<T>::Matrix4x4(const T f1, const T f2, const T f3, const T f4,
	const T f5, const T f6, const T f7, const T f8,
	const T f9, const T f10, const T f11, const T f12,
	const T f13, const T f14, const T f15, const T f16) 
	: row12(f1, f2, f3, f4, f5, f6, f7, f8), row34(f9, f10, f11, f12, f13, f14, f15, f16){
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Vec8<T>& v1, const Vec8<T>& v2) : row12(v1), row34(v2) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Vec8<T>&& v1, Vec8<T>&& v2) : row12(std::move(v1)), row34(std::move(v2)) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Vec4<T>& v1, const Vec4<T>& v2, const Vec4<T>& v3, const Vec4<T>& v4)
	: row12(v1, v2), row34(v3, v4) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Vec4<T>&& v1, Vec4<T>&& v2, Vec4<T>&& v3, Vec4<T>&& v4)
	: row12(std::move(v1), std::move(v2)), row34(std::move(v3), std::move(v4)) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& m) : row12(m.row12), row34(m.row34) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Matrix4x4<T>&& m) 
	: row12(std::forward<Matrix4x4<T>>(m).row12), row34(std::forward<Matrix4x4<T>>(m).row34) {
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4<T>& m) {
	row12 = m.row12;
	row34 = m.row34;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(Matrix4x4<T>&& m) {
	row12 = std::forward<Matrix4x4<T>>(m).row12;
	row34 = std::forward<Matrix4x4<T>>(m).row34;
	return *this;
}

template<typename T>
bool Matrix4x4<T>::operator==(const Matrix4x4<T>& m) const {
	return row12 == m.row12 && row34 == m.row34;
}

template<typename T>
bool Matrix4x4<T>::operator!=(const Matrix4x4<T>& m) const {
	return row12 != m.row12 && row34 != m.row34;
}

template<typename T>
bool Matrix4x4<T>::operator>(const Matrix4x4<T>& m) const {
	return row12 > m.row12 && row34 > m.row34;
}

template<typename T>
bool Matrix4x4<T>::operator<(const Matrix4x4<T>& m) const {
	return row12 < m.row12 && row34 < m.row34;
}

template<typename T>
bool Matrix4x4<T>::operator>=(const Matrix4x4<T>& m) const {
	return row12 >= m.row12 && row34 >= m.row34;
}

template<typename T>
bool Matrix4x4<T>::operator<=(const Matrix4x4<T>& m) const {
	return row12 <= m.row12 && row34 <= m.row34;
}

template<typename T>
bool Matrix4x4<T>::isIdentity() const {
	return row12 == { static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) } &&
		row34 == { static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) };
}

template<typename T>
bool Matrix4x4<T>::isOrthogonal() const {
	return false;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator+=(const T n) {
	row12 += n;
	row34 += n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator-=(const T n) {
	row12 -= n;
	row34 -= n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator*=(const T n) {
	row12 *= n;
	row34 *= n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator/=(const T n) {
	row12 /= n;
	row34 /= n;
	return *this;
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator+(const T n) const {
	return Matrix4x4<T>(row12 + n, row34 + n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator-(const T n) const {
	return Matrix4x4<T>(row12 - n, row34 - n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator*(const T n) const {
	return Matrix4x4<T>(row12 * n, row34 * n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator/(const T n) const {
	return Matrix4x4<T>(row12 / n, row34 / n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::transpose() const {
	Vec8<T>::SIMDType m1, m2;
	Vec8<T>::SIMDStruct::transpose(row12.m_simdVec, row34.m_simdVec, m1, m2);
	return Matrix4x4<T>(m1, m2);
}

template<typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) 	{
	Matrix4x4<T>& rs = m2.transpose();

	return Matrix4x4<T>({ EightDot({ m1.row1, m1.row1 },{ m1.row2, m1.row2 }, rs.row12, rs.row34) },
		{ EightDot({ m1.row3, m1.row3 },{ m1.row4, m1.row4 }, rs.row12, rs.row34) });
}

template<typename T>
Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	Matrix4x4<T>& rs = m2.transpose();

	m1.row12 = { EightDot({ m1.row1, m1.row1 }, { m1.row2, m1.row2 }, rs.row12, rs.row34) };
	m1.row34 = { EightDot({ m1.row3, m1.row3 }, { m1.row4, m1.row4 }, rs.row12, rs.row34) };

	return m1;
}

} //namespace math
} //namespace drak