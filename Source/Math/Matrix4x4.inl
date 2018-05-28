#include<Math/Matrix4x4.hpp>

namespace drak {
namespace math {

template<typename T>
Matrix4x4<T>::Matrix4x4() {
	memset(m_mat, 0, sizeof(m_mat));
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const T f1, const T f2, const T f3, const T f4,
	const T f5, const T f6, const T f7, const T f8,
	const T f9, const T f10, const T f11, const T f12,
	const T f13, const T f14, const T f15, const T f16)
	: m_row12(f1, f2, f3, f4, f5, f6, f7, f8), m_row34(f9, f10, f11, f12, f13, f14, f15, f16) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const T* arr) : m_row12(arr), m_row34(arr + 8) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Vec8<T>& v1, const Vec8<T>& v2) : m_row12(v1), m_row34(v2) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Vec8<T>&& v1, Vec8<T>&& v2) 
	: m_row12(std::move(v1)), m_row34(std::move(v2)) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Vec4<T>& v1, const Vec4<T>& v2,
	const Vec4<T>& v3, const Vec4<T>& v4)
	: m_row12(v1, v2), m_row34(v3, v4) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Vec4<T>&& v1, Vec4<T>&& v2, Vec4<T>&& v3, Vec4<T>&& v4)
	: m_row12(std::move(v1), std::move(v2)), m_row34(std::move(v3), std::move(v4)) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& m) : m_row12(m.m_row12), m_row34(m.m_row34) {
}

template<typename T>
Matrix4x4<T>::Matrix4x4(Matrix4x4<T>&& m)
	: m_row12(std::move(m.m_row12)), m_row34(std::move(m.m_row34)) {
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(const Matrix4x4<T>& m) {
	m_row12 = m.m_row12;
	m_row34 = m.m_row34;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator=(Matrix4x4<T>&& m) {
	m_row12 = std::move(m.m_row12);
	m_row34 = std::move(m.m_row34);
	return *this;
}

template<typename T>
bool Matrix4x4<T>::isIdentity() const {
	return (*this == Identity<T>());
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator+=(const T n) {
	m_row12 += n;
	m_row34 += n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator-=(const T n) {
	m_row12 -= n;
	m_row34 -= n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator*=(const T n) {
	m_row12 *= n;
	m_row34 *= n;
	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::operator/=(const T n) {
	m_row12 /= n;
	m_row34 /= n;
	return *this;
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator+(const T n) const {
	return Matrix4x4<T>(m_row12 + n, m_row34 + n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator-(const T n) const {
	return Matrix4x4<T>(m_row12 - n, m_row34 - n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator*(const T n) const {
	return Matrix4x4<T>(m_row12 * n, m_row34 * n);
}

template<typename T>
Matrix4x4<T> Matrix4x4<T>::operator/(const T n) const {
	return Matrix4x4<T>(m_row12 / n, m_row34 / n);
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::transpose() {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>) {
		Vec8<T>::SIMDStruct::transpose(m_row12.m_simdVec, m_row34.m_simdVec);
		return *this;
	}
	else {
		return *this = { m_mat[0], m_mat[4], m_mat[8], m_mat[12],
				 m_mat[1], m_mat[5], m_mat[9], m_mat[13],
				 m_mat[2], m_mat[6], m_mat[10], m_mat[14],
				 m_mat[3], m_mat[7], m_mat[11], m_mat[15] };
	}
}

template<typename T>
Matrix4x4<F32>& Matrix4x4<T>::inverse() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	F32 det = determinant();
	if (det != 1.f) {
		if (det == 0.f) {
			return *this = Matrix4x4<F32>(Vec8f(std::numeric_limits<F32>::quiet_NaN()),
				Vec8f(std::numeric_limits<F32>::quiet_NaN()));
		}
		else {
			return adjugate() *= (1.f / det);
		}
	}
	return this->transpose();
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::minor() {
	transpose();

	T Coef00 = a22 * a33 - a32 * a23;
	T Coef02 = a12 * a33 - a32 * a13;
	T Coef03 = a12 * a23 - a22 * a13;
	T Coef04 = a21 * a33 - a31 * a23;
	T Coef06 = a11 * a33 - a31 * a13;
	T Coef07 = a11 * a23 - a21 * a13;
	T Coef08 = a21 * a32 - a31 * a22;
	T Coef10 = a11 * a32 - a31 * a12;
	T Coef11 = a11 * a22 - a21 * a12;
	T Coef12 = a20 * a33 - a30 * a23;
	T Coef14 = a10 * a33 - a30 * a13;
	T Coef15 = a10 * a23 - a20 * a13;
	T Coef16 = a20 * a32 - a30 * a22;
	T Coef18 = a10 * a32 - a30 * a12;
	T Coef19 = a10 * a22 - a20 * a12;
	T Coef20 = a20 * a31 - a30 * a21;
	T Coef22 = a10 * a31 - a30 * a11;
	T Coef23 = a10 * a21 - a20 * a11;

	Vec4<T> Fac0(Coef00, Coef00, Coef02, Coef03);
	Vec4<T> Fac1(Coef04, Coef04, Coef06, Coef07);
	Vec4<T> Fac2(Coef08, Coef08, Coef10, Coef11);
	Vec4<T> Fac3(Coef12, Coef12, Coef14, Coef15);
	Vec4<T> Fac4(Coef16, Coef16, Coef18, Coef19);
	Vec4<T> Fac5(Coef20, Coef20, Coef22, Coef23);

	Vec4<T> Vec0(a10, a00, a00, a00);
	Vec4<T> Vec1(a11, a01, a01, a01);
	Vec4<T> Vec2(a12, a02, a02, a02);
	Vec4<T> Vec3(a13, a03, a03, a03);

	m_row1 = (Vec1 * Fac0 - Vec2 * Fac1 + Vec3 * Fac2);
	m_row2 = (Vec0 * Fac0 - Vec2 * Fac3 + Vec3 * Fac4);
	m_row3 = (Vec0 * Fac1 - Vec1 * Fac3 + Vec3 * Fac5);
	m_row4 = (Vec0 * Fac2 - Vec1 * Fac4 + Vec2 * Fac5);

	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::cofactor() {
	minor();

	Vec4<T> signA(+1, -1, +1, -1);
	Vec4<T> signB(-1, +1, -1, +1);

	m_row1 *= signA;
	m_row2 *= signB;
	m_row3 *= signA;
	m_row4 *= signB;

	return *this;
}

template<typename T>
Matrix4x4<T>& Matrix4x4<T>::adjugate() {
	return cofactor().transpose();
}

template<typename T>
F32 Matrix4x4<T>::determinant() const {
	//Compute Zero in first Column
	F32 invRow1X = 1.f / m_row1.x;
	Vec4<F32> rowTemp1(m_row2 - m_row1 * (m_row2.x * invRow1X));
	Vec4<F32> rowTemp2(m_row3 - m_row1 * (m_row3.x * invRow1X));
	Vec4<F32> rowTemp3(m_row4 - m_row1 * (m_row4.x * invRow1X));
	//Determinant of 3x3 matrix
	return rowTemp1.y * (rowTemp2.z * rowTemp3.w - rowTemp2.w * rowTemp3.z) -
		rowTemp1.z * (rowTemp2.y * rowTemp3.w - rowTemp2.w * rowTemp3.y) +
		rowTemp1.w * (rowTemp2.y * rowTemp3.z - rowTemp2.z * rowTemp3.y);
}

template<typename T>
bool operator==(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 == m2.m_row12 && m1.m_row34 == m2.m_row34;
}

template<typename T>
bool operator!=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 != m2.m_row12 && m1.m_row34 != m2.m_row34;
}

template<typename T>
bool operator>(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 > m2.m_row12 && m1.m_row34 > m2.m_row34;
}

template<typename T>
bool operator<(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 < m2.m_row12 && m1.m_row34 < m2.m_row34;
}

template<typename T>
bool operator>=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 >= m2.m_row12 && m1.m_row34 >= m2.m_row34;
}

template<typename T>
bool operator<=(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	return m1.m_row12 <= m2.m_row12 && m1.m_row34 <= m2.m_row34;
}

template<typename T>
Matrix4x4<T> operator*(const Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	Matrix4x4<T> rs = Transpose(m2);

	return { EightDot(Vec8<T>::broadcast(m1.m_row1),
		Vec8<T>::broadcast(m1.m_row2), rs.m_row12, rs.m_row34),
		EightDot(Vec8<T>::broadcast(m1.m_row3),
			Vec8<T>::broadcast(m1.m_row4), rs.m_row12, rs.m_row34) };
}

template<typename T>
Matrix4x4<T>& operator*=(Matrix4x4<T>& m1, const Matrix4x4<T>& m2) {
	Matrix4x4<T> rs = Transpose(m2);

	m1.m_row12 = EightDot( Vec8<T>::broadcast(m1.m_row1),
		Vec8<T>::broadcast(m1.m_row2), rs.m_row12, rs.m_row34);
	m1.m_row34 = EightDot(Vec8<T>::broadcast(m1.m_row3),
		Vec8<T>::broadcast(m1.m_row4), rs.m_row12, rs.m_row34);

	return m1;
}

template<typename T>
Vec4<T> operator*(const Matrix4x4<T>& m, const Vec4<T>& v) {
	return FourDot(m.m_row12, m.m_row34, Vec8<T>::broadcast(v));
}

template<typename T>
Vec4<T>& operator*=(const Matrix4x4<T>& m, Vec4<T>& v) {
	return (v = FourDot(m.m_row12, m.m_row34, Vec8<T>::broadcast(v)));
}

template<typename T>
Vec3<T> operator*(const Matrix4x4<T>& m, const Vec3<T>& v) {
	return FourDot(m.m_row12, m.m_row34, Vec8<T>::broadcast({ v, 1.f }));
}

template<typename T>
Vec3<T>& operator*=(const Matrix4x4<T>& m, Vec3<T>& v) {
	return (v = FourDot(m.m_row12, m.m_row34, Vec8<T>::broadcast({ v, 1.f })));
}

template<typename T>
Matrix4x4<T> Transpose(const Matrix4x4<T>& m) {
	return Matrix4x4<T>(m).transpose();
}

template<typename T>
Matrix4x4<T> Minor(const Matrix4x4<T>& m) {
	return Matrix4x4<T>(m).minor();
}

template<typename T>
Matrix4x4<T> Cofactor(const Matrix4x4<T>& m) {
	return Matrix4x4<T>(m).cofactor();
}

template<typename T>
Matrix4x4<T> Adjugate(const Matrix4x4<T>& m) {
	return Matrix4x4<T>(m).adjugate();
}

Mat4f Inverse(const Mat4f& m) {
	F32 det = m.determinant();
	if (det != 1.f) {
		if (det == 0.f) {
			return Matrix4x4<F32>(Vec8f(std::numeric_limits<F32>::quiet_NaN()),
				Vec8f(std::numeric_limits<F32>::quiet_NaN()));
		}
		else {
			//Compute Adjugate
			Matrix4x4<F32> temp(m);
			temp.cofactor().transpose(); // adjugate
			return temp * (1 / det);
		}
	}
	return Transpose(m);
}

template<typename T>
bool Matrix4x4<T>::isOrthogonal() const {
	return IsEqual_V<F32>(1.0f, determinant());
}

template<typename T>
Matrix4x4<T> Scale(const Vec3<T>& v) {
	return Matrix4x4<T>(v.x, 0.f, 0.f, 0.f, 0.f, v.y, 0.f, 0.f,
		0.f, 0.f, v.z, 0.f, 0.f, 0.f, 0.f, 1.f);
}

template<typename T>
Matrix4x4<T>& Scale(Matrix4x4<T>& m, const Vec3<T>& v) {
	return m *= Scale<T>(v);
}

template<typename T>
Matrix4x4<T> Translate(const Vec3<T>& v) {
	Matrix4x4<T> res{ Identity<T>() };
	res.a03 = v.x;
	res.a13 = v.y;
	res.a23 = v.z;
	return res;
}

template<typename T>
Matrix4x4<T>& Translate(Matrix4x4<T>& m,
	const Vec3<T>& v) {
	return m *= Translate<T>(v);
}

template<typename T>
Matrix4x4<T> Identity() {
	Matrix4x4<T> temp;
	temp.a00 = temp.a11 = temp.a22 = temp.a33 = static_cast<T>(1);
	return temp;
}

template<AngleUnit unit>
Matrix4x4<F32> Rotation(const Vec3<F32>& euler) {
	if constexpr(unit == AngleUnit::DEGREE) {
		Vec4<F32> t{ euler };
		t *= ToRadF;

		return RotationY<AngleUnit::RADIANS>(t.y) *
			RotationX<AngleUnit::RADIANS>(t.x) * RotationZ<AngleUnit::RADIANS>(t.z);
	}
	else {
		return RotationY<unit>(t.y) *
			RotationX<unit>(t.x) * RotationZ<unit>(t.z);
	}
}

template<AngleUnit unit>
Matrix4x4<F32> RotationX(F32 angleX) {
	if constexpr(unit == AngleUnit::DEGREE)
		angleX *= ToRadF;
	Matrix4x4<F32> temp{ Identity<F32>() };
	temp.a21 = sin(angleX);
	temp.a12 = -(temp.a21);
	temp.a11 = temp.a22 = cos(angleX);
	return temp;
}

template<AngleUnit unit>
Matrix4x4<F32> RotationY(F32 angleY) {
	if constexpr(unit == AngleUnit::DEGREE)
		angleY *= ToRadF;
	Matrix4x4<F32> temp{ Identity<F32>() };
	temp.a02 = sin(angleY);
	temp.a20 = -(temp.a02);
	temp.a00 = temp.a22 = cos(angleY);
	return temp;
}

template<AngleUnit unit>
Matrix4x4<F32> RotationZ(F32 angleZ) {
	if constexpr(unit == AngleUnit::DEGREE)
		angleZ *= ToRadF;
	Matrix4x4<F32> temp{ Identity<F32>() };
	temp.a10 = sin(angleZ);
	temp.a01 = -(temp.a10);
	temp.a00 = temp.a11 = cos(angleZ);
	return temp;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Matrix4x4<T>& v) {
	return o << " | " << v.a00 << " | " << v.a01 << " | " << v.a02 << " | " << v.a03 << "\n"
		" | " << v.a10 << " | " << v.a11 << " | " << v.a12 << " | " << v.a13 << "\n"
		" | " << v.a20 << " | " << v.a21 << " | " << v.a22 << " | " << v.a23 << "\n"
		" | " << v.a30 << " | " << v.a31 << " | " << v.a32 << " | " << v.a33 << " | ";
}


} //namespace math
} //namespace drak