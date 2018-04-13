#include <Math/Quaternion.hpp>

namespace drak {
namespace math {

template<typename T>
Quaternion<T>::Quaternion() : m_scalar(0), m_vecPart(0) {
}
template<typename T>
Quaternion<T>::Quaternion(const Vec4<T>& v) : m_scalar(v.w), m_vecPart(v.xyz()) {
}

template<typename T>
Quaternion<T>::Quaternion(const T scalar, const Vec3<T>& v) 
	: m_scalar(scalar), m_vecPart(v) {
}

template<typename T>
Quaternion<T>::Quaternion(Vec4<T>&& v) 
	: m_scalar(std::move(v.w)), m_vecPart(std::move(v.xyz())) {
}

template<typename T>
Quaternion<T>::Quaternion(const T scalar, Vec3<T>&& v) 
	: m_scalar(scalar), m_vecPart(std::move(v)) {
}

template<typename T>
Quaternion<T>::Quaternion(const Vec3<T>& euler) {
	Vec3<T> theta{ (euler * (ToRadF * 0.5f)) };
	Vec3<T> cos{ cos(theta.x), cos(theta.y), cos(theta.z) };
	Vec3<T> sin{ sin(theta.x), sin(theta.y), sin(theta.z) };

	w = cos.x * cos.y * cos.z + sin.x * sin.y * sin.z;
	m_vecPart = {	sin.x * cos.y * cos.z - cos.x * sin.y * sin.z,
					cos.x * sin.y * cos.z + sin.x * cos.y * sin.z,
					cos.x * cos.y * sin.z - sin.x * sin.y * cos.z  };
}

template<typename T>
Quaternion<T>::Quaternion(const Quaternion& q) 
	: m_scalar(q.m_scalar), m_vecPart(q.m_vecPart) {
}

template<typename T>
Quaternion<T>::Quaternion(Quaternion&& q) 
	: m_scalar(std::move(q.m_scalar)), m_vecPart(std::move(q.m_vecPart)) {
}

template<typename T>
T Quaternion<T>::scalar() const {
	return m_scalar;
}

template<typename T>
Vec3<T> Quaternion<T>::vector() const {
	return m_vecPart;
}

template<typename T>
Quaternion Quaternion<T>::conjugate() const {
	return {-m_vecPart, scalar};
}

template<typename T>
float Quaternion<T>::magnitude() const {
	return Vec4<T>(m_vecPart, m_scalar).magnitude();
}

template<typename T>
Quaternion Quaternion<T>::inverse() const {
	float magn = magnitude();
	if (IsEqual_V<float>(magn, 1.f))
		return conjugate();
	else
		return conjugate() / (magn * magn);
}

template<typename T>
Quaternion Quaternion<T>::normalize() const {
	return *this / magnitude();
}

template<typename T>
Quaternion Quaternion<T>::operator+(const T f) const {
	return {m_vecPart, m_scalar} + f;
}

template<typename T>
Quaternion& Quaternion<T>::operator+=(const T f) {
	*this = *this + f;
}

template<typename T>
Quaternion Quaternion<T>::operator-(const T f) const {
	return { m_vecPart, m_scalar } - f;
}

template<typename T>
Quaternion& Quaternion<T>::operator-=(const T f) {
	*this = *this - f;
}

template<typename T>
Quaternion Quaternion<T>::operator*(const T f) const {
	return { m_vecPart, m_scalar } * f;
}

template<typename T>
Quaternion& Quaternion<T>::operator*=(const T f) {
	*this = *this * f;
}

template<typename T>
Quaternion Quaternion<T>::operator/(const T f) const {
	return { m_vecPart, m_scalar } / f;
}

template<typename T>
Quaternion& Quaternion<T>::operator/=(const T f) {
	*this = *this / f;
}

template<typename T>
Matrix4x4<T> Quaternion<T>::matrix() const {
	Quaternion<T> normalized = normalize();
	Vec8<T> vec = ( { { m_vecPart, m_vecPart.x }, { m_vecPart, m_vecPart.x } } *
	{ { m_vecPart, m_vecPart.y }, { w, w, w, m_vecPart.z } } ) * 2;
	T vYZ = 2 * (m_vecPart.y * m_vecPart.z);
	return Matrix4x4<T>( 1 - (vec.y + vec.z), (vec.w + vec.c), (vec.d - vec.b), 0, 
						 (vec.w - vec.c), 1 - (vec.x + vec.z), (vYZ + vec.a), 0,
						 (vec.d + vec.b), (vYZ - vec.a), 1 - (vec.x + vec.y), 0,
						 0, 0, 0, 1);
}

template<typename T>
Vec3<T> Quaternion<T>::euler() const {
	return Vec3<T>();
}


template<typename T>
template<typename U>
Quaternion<U> Quaternion<T>::cast() {
	return Quaternion<U>(static_cast<U>(m_scalar), m_vecPart.cast<U>());
}

template<typename T>
Quaternion<T> operator+(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } + { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
Quaternion<T> operator-(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } - { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
Quaternion<T> operator*(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return Quaternion<T>(qa.m_scalar * qb.m_scalar - Dot(qa.m_vecPart, qb.m_vecPart),
		(qb.m_scalar * qa.m_vecPart) + (qa.m_scalar * qb.m_vecPart) +
		Cross(qa.m_vecPart, qb.m_vecPart));
}

template<typename T>
Quaternion<T>& operator+=(Quaternion<T>& qa, const Quaternion<T>& qb) {
	return qa = qa + qb;
}

template<typename T>
Quaternion<T>& operator-=(Quaternion<T>& qa, const Quaternion<T>& qb) {
	return qa = qa - qb;
}

template<typename T>
Quaternion<T>& operator*=(Quaternion<T>& qa, const Quaternion<T>& qb) {
	return qa = qa * qb;
}

template<typename T>
Quaternion<T>& operator=(Quaternion<T>& qa, const Quaternion<T>& qb) {
	new (&qa) Quaternion<T>(qb);
}

template<typename T>
Quaternion<T>& operator=(Quaternion<T>& qa, Quaternion<T>&& qb) {
	new (&qa) Quaternion<T>(std::move(qb));
}

template<typename T>
bool operator==(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } == { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
bool operator!=(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } != { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
bool operator<(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } > { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
bool operator<=(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } >= { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
bool operator>(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } < { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
bool operator>=(const Quaternion<T>& qa, const Quaternion<T>& qb) {
	return { qa.m_vecPart, qa.m_scalar } <= { qb.m_vecPart, qb.m_scalar };
}

template<typename T>
Vec3<T> Rotate(const Quaternion<T>& q, const Vec3& v) {
	return (Quaternion<T>(-Dot(q.m_vecPart, v), (q.m_scalar * v) +
		Cross(qa.m_vecPart, v))* q.inverse()).m_vecPart;
}

template<typename T>
Vec4<T> Rotate(const Quaternion<T>& q, const Vec4& v) {
	Vec3<T> temp = v.xyz();
	return (Quaternion<T>(-Dot(q.m_vecPart, temp), (q.m_scalar * temp) +
		Cross(qa.m_vecPart, temp))* q.inverse()).m_vecPart;
}

} // namespace math
} // namespace drak