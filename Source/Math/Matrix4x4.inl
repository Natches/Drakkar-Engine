#include<Math/Matrix4x4.hpp>

namespace drak {
namespace math {

#pragma region MutualFunction

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4() {
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::isOrthogonal() const {
	return isIdentity(*this * transpose());
}

template<typename T, Ordering order>
Matrix4x4<T, order> Scale(const Vec3<T>& v) {
	return Identity() * v;
}

template<typename T, Ordering order>
Matrix4x4<T, order>& Scale(Matrix4x4<T, order>& m, const Vec3<T>& v) {
	m.a *= v.x;
	m.f *= v.y;
	m.k *= v.z;
	return m;
}

template<typename T, Ordering order>
Matrix4x4<T, order> Identity() {
	Matrix4x4<T, order> temp;
	temp.a = temp.f = temp.k = temp.p = static_cast<T>(1);
	return temp;
}

template<Ordering order, AngleUnit unit>
Matrix4x4<F32, order> Rotation(const Vec3<F32>& euler) {
	if constexpr(unit == AngleUnit::DEGREE) {
		Vec4<F32> t{ euler };
		t *= ToRadF;

		return RotationY<order, AngleUnit::RADIANS>(t.y) *
			RotationX<order, AngleUnit::RADIANS>(t.x) * RotationZ<order, AngleUnit::RADIANS>(t.z);
	}
	else {
		return RotationY<order, unit>(t.y) *
			RotationX<order, unit>(t.x) * RotationZ<order, unit>(t.z);
	}
}

template<Ordering order, AngleUnit unit>
Matrix4x4<F32, order> RotationX(F32 angleX) {
	if constexpr(unit == AngleUnit::DEGREE) 
		angleX *= ToRadF;
	Matrix4x4<F32, order> temp;
	temp.j = sin(angleX);
	temp.g = -(temp.j);
	temp.f =  temp.k = cos(angleX);
	return temp;
}

template<Ordering order, AngleUnit unit>
Matrix4x4<F32, order> RotationY(F32 angleY) {
	if constexpr(unit == AngleUnit::DEGREE)
		angleY *= ToRadF;
	Matrix4x4<F32, order> temp;
	temp.c = sin(angleY);
	temp.i = -(temp.c);
	temp.a = temp.k = cos(angleX);
	return temp;
}

template<Ordering order, AngleUnit unit>
Matrix4x4<F32, order> RotationZ(F32 angleZ) {
	if constexpr(unit == AngleUnit::DEGREE)
		angleZ *= ToRadF;
	Matrix4x4<F32, order> temp;
	temp.e = sin(angleX);
	temp.b = -(temp.e);
	temp.a = temp.f = cos(angleX);
	return temp;
}

#pragma endregion MutualFunction

#pragma region RowOrdered

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(const T f1, const T f2, const T f3, const T f4,
	const T f5, const T f6, const T f7, const T f8,
	const T f9, const T f10, const T f11, const T f12,
	const T f13, const T f14, const T f15, const T f16)
	: m_row12(f1, f2, f3, f4, f5, f6, f7, f8), m_row34(f9, f10, f11, f12, f13, f14, f15, f16) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(const T* arr) : m_row12(arr), m_row34(arr + 8) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(const Vec8<T>& v1, const Vec8<T>& v2) : m_row12(v1), m_row34(v2) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(Vec8<T>&& v1, Vec8<T>&& v2) 
	: m_row12(std::move(v1)), m_row34(std::move(v2)) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(const Vec4<T>& v1, const Vec4<T>& v2,
	const Vec4<T>& v3, const Vec4<T>& v4)
	: m_row12(v1, v2), m_row34(v3, v4) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(Vec4<T>&& v1, Vec4<T>&& v2, Vec4<T>&& v3, Vec4<T>&& v4)
	: m_row12(std::move(v1), std::move(v2)), m_row34(std::move(v3), std::move(v4)) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(const Matrix4x4<T>& m) : m_row12(m.m_row12), m_row34(m.m_row34) {
}

template<typename T, Ordering order>
Matrix4x4<T, order>::Matrix4x4(Matrix4x4<T>&& m)
	: m_row12(std::forward<Matrix4x4<T>>(m).m_row12),
	m_row34(std::forward<Matrix4x4<T>>(m).m_row34) {
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator=(const Matrix4x4<T>& m) {
	m_row12 = m.m_row12;
	m_row34 = m.m_row34;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator=(Matrix4x4<T>&& m) {
	m_row12 = std::forward<Matrix4x4<T>>(m).m_row12;
	m_row34 = std::forward<Matrix4x4<T>>(m).m_row34;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator=(const MATRIX_COLUMN_MAJOR(T)& m) {
	Matrix4x4<T> temp{ m.transpose() };
	m_row12 = m.m_row12;
	m_row34 = m.m_row34;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator=(MATRIX_COLUMN_MAJOR(T)&& m) {
	Matrix4x4<T> temp = std::forward<MATRIX_COLUMN_MAJOR(T)>(m).transpose();
	m_row12 = temp.m_row12;
	m_row34 = temp.m_row34;
	return *this;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator==(const Matrix4x4<T>& m) const {
	return m_row12 == m.m_row12 && m_row34 == m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator!=(const Matrix4x4<T>& m) const {
	return m_row12 != m.m_row12 && m_row34 != m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator>(const Matrix4x4<T>& m) const {
	return m_row12 > m.m_row12 && m_row34 > m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator<(const Matrix4x4<T>& m) const {
	return m_row12 < m.m_row12 && m_row34 < m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator>=(const Matrix4x4<T>& m) const {
	return m_row12 >= m.m_row12 && m_row34 >= m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::operator<=(const Matrix4x4<T>& m) const {
	return m_row12 <= m.m_row12 && m_row34 <= m.m_row34;
}

template<typename T, Ordering order>
bool Matrix4x4<T, order>::isIdentity() const {
	return m_row12 == { static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) } &&
		m_row34 == { static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) };
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator+=(const T n) {
	m_row12 += n;
	m_row34 += n;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator-=(const T n) {
	m_row12 -= n;
	m_row34 -= n;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator*=(const T n) {
	m_row12 *= n;
	m_row34 *= n;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T>& Matrix4x4<T, order>::operator/=(const T n) {
	m_row12 /= n;
	m_row34 /= n;
	return *this;
}

template<typename T, Ordering order>
Matrix4x4<T> Matrix4x4<T, order>::operator+(const T n) const {
	return Matrix4x4<T>(m_row12 + n, m_row34 + n);
}

template<typename T, Ordering order>
Matrix4x4<T> Matrix4x4<T, order>::operator-(const T n) const {
	return Matrix4x4<T>(m_row12 - n, m_row34 - n);
}

template<typename T, Ordering order>
Matrix4x4<T> Matrix4x4<T, order>::operator*(const T n) const {
	return Matrix4x4<T>(m_row12 * n, m_row34 * n);
}

template<typename T, Ordering order>
Matrix4x4<T> Matrix4x4<T, order>::operator/(const T n) const {
	return Matrix4x4<T>(m_row12 / n, m_row34 / n);
}

template<typename T, Ordering order>
MATRIX_COLUMN_MAJOR(T) Matrix4x4<T, order>::transpose() const {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>) {
		Vec8<T>::SIMDType m1, m2;
		Vec8<T>::SIMDStruct::transpose(m_row12.m_simdVec, m_row34.m_simdVec, m1, m2);
		return MATRIX_COLUMN_MAJOR(T)(m1, m2);
	}
	else {
		return { m_mat[0], m_mat[4], m_mat[8], m_mat[12],
				 m_mat[1], m_mat[5], m_mat[9], m_mat[13],
				 m_mat[2], m_mat[6], m_mat[10], m_mat[14],
				 m_mat[3], m_mat[7], m_mat[11], m_mat[15] };
	}
}

template<typename T, Ordering order>
MATRIX_COLUMN_MAJOR(T) Matrix4x4<T, order>::toColumnMajor() const {
	return transpose();
}

template<typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	MATRIX_COLUMN_MAJOR(T)& rs = m2.transpose();

	return { EightDot(Vec8<T>::broadcast(m1.m_row1),
		Vec8<T>::broadcast(m1.m_row2), rs.m_col12, rs.m_col34),
		EightDot(Vec8<T>::broadcast(m1.m_row3),
			Vec8<T>::broadcast(m1.m_row4), rs.m_col12, rs.m_col34) };
}

template<typename T>
Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	MATRIX_COLUMN_MAJOR(T)& rs = m2.transpose();

	m1.m_row12 = { EightDot( Vec8<T>::broadcast(m1.m_row1),
		Vec8<T>::broadcast(m1.m_row2), rs.m_col12, rs.m_col34) };
	m1.m_row34 = { EightDot(Vec8<T>::broadcast(m1.m_row3),
		Vec8<T>::broadcast(m1.m_row4), rs.m_col12, rs.m_col34) };

	return m1;
}

template<typename T>
Matrix4x4<T> Translate(const Vec3<T>& v) {
	Matrix4x4<T> res{ Identity() };
	res.m_row4 = { v, static_cast<T>(1) };
	return Identity();
}

template<typename T>
Matrix4x4<T>& Translate(Matrix4x4<T>& m, const Vec3<T>& v) {
	m.m_row4 += { v };
	return m;
}

#pragma endregion RowOrdered

#pragma region ColumnOrdered

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(const T f1, const T f2, const T f3, const T f4,
	const T f5, const T f6, const T f7, const T f8,
	const T f9, const T f10, const T f11, const T f12,
	const T f13, const T f14, const T f15, const T f16)
	: m_col12(f1, f2, f3, f4, f5, f6, f7, f8), m_col34(f9, f10, f11, f12, f13, f14, f15, f16) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(const T* arr) : m_col12(arr), m_col34(arr + 8) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(const Vec8<T>& v1, const Vec8<T>& v2) 
	: m_col12(v1), m_col34(v2) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(Vec8<T>&& v1, Vec8<T>&& v2) 
	: m_col12(std::move(v1)), m_col34(std::move(v2)) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(const Vec4<T>& v1, const Vec4<T>& v2,
	const Vec4<T>& v3, const Vec4<T>& v4)
	: m_col12(v1, v2), m_col34(v3, v4) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(Vec4<T>&& v1, Vec4<T>&& v2,
	Vec4<T>&& v3, Vec4<T>&& v4)
	: m_col12(std::move(v1), std::move(v2)), m_col34(std::move(v3), std::move(v4)) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(const MATRIX_COLUMN_MAJOR(T)& m) 
	: m_col12(m.m_col12), m_col34(m.m_col34) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)::Matrix4x4(MATRIX_COLUMN_MAJOR(T)&& m)
	: m_col12(std::forward<Matrix4x4<T>>(m).m_col12),
	m_col34(std::forward<Matrix4x4<T>>(m).m_col34) {
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator=(const MATRIX_COLUMN_MAJOR(T)& m) {
	m_col12 = m.m_col12;
	m_col34 = m.m_col34;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator=(MATRIX_COLUMN_MAJOR(T)&& m) {
	m_col12 = std::forward<MATRIX_COLUMN_MAJOR(T)>(m).m_col12;
	m_col34 = std::forward<MATRIX_COLUMN_MAJOR(T)>(m).m_col34;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator=(const Matrix4x4<T>& m) {
	MATRIX_COLUMN_MAJOR(T) temp = m.transpose();
	m_col12 = m.m_col12;
	m_col34 = m.m_col34;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator=(Matrix4x4<T>&& m) {
	MATRIX_COLUMN_MAJOR(T) temp = std::forward<MATRIX_ROW_MAJOR(T)>(m).transpose();
	m_col12 = temp.m_col12;
	m_col34 = temp.m_col34;
	return *this;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator==(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 == m.m_col12 && m_col34 == m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator!=(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 != m.m_col12 && m_col34 != m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator>(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 > m.m_col12 && m_col34 > m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator<(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 < m.m_col12 && m_col34 < m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator>=(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 >= m.m_col12 && m_col34 >= m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::operator<=(const MATRIX_COLUMN_MAJOR(T)& m) const {
	return m_col12 <= m.m_col12 && m_col34 <= m.m_col34;
}

template<typename T>
bool MATRIX_COLUMN_MAJOR(T)::isIdentity() const {
	return m_col12 == { static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0) } &&
		m_col34 == { static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0),
		static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1) };
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator+=(const T n) {
	m_col12 += n;
	m_col34 += n;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator-=(const T n) {
	m_col12 -= n;
	m_col34 -= n;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator*=(const T n) {
	m_col12 *= n;
	m_col34 *= n;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& MATRIX_COLUMN_MAJOR(T)::operator/=(const T n) {
	m_col12 /= n;
	m_col34 /= n;
	return *this;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) MATRIX_COLUMN_MAJOR(T)::operator+(const T n) const {
	return MATRIX_COLUMN_MAJOR(T)(m_col12 + n, m_col34 + n);
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) MATRIX_COLUMN_MAJOR(T)::operator-(const T n) const {
	return MATRIX_COLUMN_MAJOR(T)(m_col12 - n, m_col34 - n);
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) MATRIX_COLUMN_MAJOR(T)::operator*(const T n) const {
	return MATRIX_COLUMN_MAJOR(T)(m_col12 * n, m_col34 * n);
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) MATRIX_COLUMN_MAJOR(T)::operator/(const T n) const {
	return MATRIX_COLUMN_MAJOR(T)(m_col12 / n, m_col34 / n);
}

template<typename T>
Matrix4x4<T> MATRIX_COLUMN_MAJOR(T)::transpose() const {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>) {
		Vec8<T>::SIMDType m1, m2;
		Vec8<T>::SIMDStruct::transpose(m_col12.m_simdVec, m_col34.m_simdVec, m1, m2);
		return Matrix4x4<T>(m1, m2);
	}
	else {
		return { m_mat[0], m_mat[4], m_mat[8], m_mat[12],
			m_mat[1], m_mat[5], m_mat[9], m_mat[13],
			m_mat[2], m_mat[6], m_mat[10], m_mat[14],
			m_mat[3], m_mat[7], m_mat[11], m_mat[15] };
	}
}

template<typename T>
Matrix4x4<T> MATRIX_COLUMN_MAJOR(T)::toRowMajor() const {
	return transpose();
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) operator*(const MATRIX_COLUMN_MAJOR(T)& m1,
	const MATRIX_COLUMN_MAJOR(T)& m2) {
	Matrix4x4<T>& rs = m2.transpose();

	return { EightDot(Vec8<T>::broadcast(m1.m_col1),
		Vec8<T>::broadcast(m1.m_col2), rs.m_row12, rs.m_row34),
		EightDot(Vec8<T>::broadcast(m1.m_col3),
			Vec8<T>::broadcast(m1.m_col4), rs.m_row12, rs.m_row34) };
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& operator*=(MATRIX_COLUMN_MAJOR(T)& m1,
	const MATRIX_COLUMN_MAJOR(T)& m2) {
	Matrix4x4<T> rs(m2.transpose());

	m1.m_col12 = { EightDot(Vec8<T>::broadcast(m1.m_col1),
		Vec8<T>::broadcast(m1.m_col2),
		rs.m_row12, rs.m_row34) };
	m1.m_col34 = { EightDot(Vec8<T>::broadcast(m1.m_col3),
		Vec8<T>::broadcast(m1.m_col4),
		rs.m_row12, rs.m_row34) };

	return m1;
}

template<typename T>
MATRIX_COLUMN_MAJOR(T) Translate(const Vec3<T>& v) {
	MATRIX_COLUMN_MAJOR(T) res{ Identity() };
	res.m_col4 = { v, static_cast<T>(1) };
	return Identity();
}

template<typename T>
MATRIX_COLUMN_MAJOR(T)& Translate(MATRIX_COLUMN_MAJOR(T)& m,
	const Vec3<T>& v) {
	m.m_col4 += { v };
	return m;
}


#pragma endregion ColumnOrdered

} //namespace math
} //namespace drak