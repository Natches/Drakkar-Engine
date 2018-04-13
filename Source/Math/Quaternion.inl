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
	Vec8<T> vec = { { m_vecPart, m_vecPart.x }, { m_vecPart, m_vecPart.x } } *
	{ { m_vecPart, m_vecPart.y }, { w, w, w, m_vecPart.z } };
	T vYZ = m_vecPart.y * m_vecPart.z;
	return Matrix4x4<T>( 1 - 2 * (vec.y + vec.z), 2 * (vec.w + vec.c), 2 * (vec.d - vec.b), 0, 
						 2 * (vec.w - vec.c), 1 - 2 * (vec.x + vec.z), 2 * (vYZ + vec.a), 0,
						 2 * (vec.d + vec.b), 2 * (vYZ - vec.a), 1 - 2 * (vec.x + vec.y), 0,
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

} // namespace math
} // namespace drak