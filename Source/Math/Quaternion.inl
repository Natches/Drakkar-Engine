#include <Math/Quaternion.hpp>
#include "Vec3.hpp"

namespace drak {
namespace math {

Quaternion::Quaternion() : m_scalar(0), m_vecPart(0) {
}

Quaternion::Quaternion(const Vec4f& v) : quat(v) {
}

Quaternion::Quaternion(const F32 scalar, const Vec3f& v) 
	: m_scalar(scalar), m_vecPart(v) {
}

Quaternion::Quaternion(Vec4f&& v) 
	: quat(std::move(v)) {
}

Quaternion::Quaternion(const F32 scalar, Vec3f&& v) 
	: m_scalar(scalar), m_vecPart(std::move(v)) {
}

Quaternion::Quaternion(const Vec3f& euler) {
	fromEuler(euler);
}

Quaternion::Quaternion(Vec3f&& euler) {
	fromEuler(std::move(euler));
}

Quaternion::Quaternion(Axis axis, F32 Angle)
	: m_scalar(0), m_vecPart(0) {
	Angle *= ToRadF * 0.5f;
	m_scalar = cos(Angle);
	DK_SELECT(axis)
		DK_CASE(Axis::X, m_vecPart.x = sin(Angle))
		DK_CASE(Axis::Y, m_vecPart.y = sin(Angle))
		DK_CASE(Axis::Z, m_vecPart.z = sin(Angle))
	DK_END
}

Quaternion::Quaternion(const Vec3f& axis, F32 Angle) {
	fromAxisAndAngle(axis, Angle);
}

Quaternion::Quaternion(Vec3f&& axis, F32 Angle) {
	fromAxisAndAngle(std::move(axis), Angle);
}

Quaternion::Quaternion(const Mat4f& mat) {
	fromMatrix(mat);
}

Quaternion::Quaternion(Mat4f&& mat) {
	fromMatrix(std::move(mat));
}

Quaternion::Quaternion(const Quaternion& q) 
	: quat(q.quat) {
}

Quaternion::Quaternion(Quaternion&& q) 
	: quat(std::move(q.quat)) {
	q.quat = Vec4f::Null();
}

Quaternion& Quaternion::conjugate() {
	m_vecPart.negate();
	return *this;
}

float Quaternion::magnitude() const {
	return quat.magnitude();
}

Quaternion& Quaternion::inverse() {
	float magn = magnitude();
	if (IsEqual_V<float>(magn, 1.f))
		return conjugate();
	else
		return conjugate() /= (magn * magn);
}

Quaternion& Quaternion::normalize() {
	return *this /= magnitude();
}

Quaternion Quaternion::operator+(const F32 f) const {
	return Quaternion(quat + f);
}

Quaternion& Quaternion::operator+=(const F32 f) {
	return *this = *this + f;
}

Quaternion Quaternion::operator-(const F32 f) const {
	return Quaternion(quat - f);
}

Quaternion& Quaternion::operator-=(const F32 f) {
	return *this = *this - f;
}

Quaternion Quaternion::operator*(const F32 f) const {
	return Quaternion(quat * f);
}

Quaternion& Quaternion::operator*=(const F32 f) {
	return *this = *this * f;
}

Quaternion Quaternion::operator/(const F32 f) const {
	return Quaternion(quat / f);
}

Quaternion& Quaternion::operator/=(const F32 f) {
	return *this = *this / f;
}

Mat4f Quaternion::matrix() {
	normalize();
	Vec8f vec = ( Vec8f(Vec4f(m_vecPart, m_vecPart.x),
		Vec4f(m_vecPart, m_vecPart.x)) *
		Vec8f(Vec4f(m_vecPart, m_vecPart.y),
			Vec4f(m_scalar, m_scalar, m_scalar, m_vecPart.z)));
	F32 vYZ = (m_vecPart.y * m_vecPart.z);
	return Mat4f( 0.5f - (vec.y + vec.z), (vec.w - vec.c), (vec.d + vec.b), 0,
						(vec.w + vec.c), 0.5f - (vec.x + vec.z), (vYZ - vec.a), 0,
						(vec.d - vec.b), (vYZ + vec.a), 0.5f - (vec.x + vec.y), 0,
						 0, 0, 0, 1);
}

Vec3f Quaternion::euler() const {
	float s2 = quat.y * quat.y + quat.z * quat.z;
	float c2 = quat.x * quat.x + quat.w * quat.w;
	float s = atanf(quat.w / quat.x);
	float d = atan2f(quat.z, quat.y);

	return  Vec3f(s + d,
		IsNotEqual_V(c2, 0.f) ? 2.f * atanf(sqrt(s2 / c2)) : (0.5f > s2) ? 0.f : M_PI,
		s - d) * ToDegF;
}

inline Vec4f Quaternion::forward() {
	return Rotate(*this, Vec4f::Forward());
}

inline Vec4f Quaternion::right() {
	return Rotate(*this, Vec4f::Right());
}

inline Vec4f Quaternion::up() {
	return Rotate(*this, Vec4f::Up());
}

template<typename U>
void Quaternion::fromEuler(U&& u) {
	Vec3f theta(std::forward<U>(u) * (ToRadF * 0.5f));
	Vec3f cosV{ cos(theta.x - theta.z), cos(theta.y), cos(theta.x + theta.z) };
	Vec3f sinV{ sin(theta.x - theta.z), sin(theta.y), sin(theta.x + theta.z) };

	quat = { cosV.z * cosV.y,
			 cosV.x * sinV.y,
			 sinV.x * sinV.y,
			 sinV.z * cosV.y };
}

template<typename U>
void Quaternion::fromMatrix(U&& u) {
	Vec4f v{ 1 + std::forward<U>(u).a00 + std::forward<U>(u).a11 +
		std::forward<U>(u).a22, 1 + std::forward<U>(u).a00 -
		std::forward<U>(u).a11 - std::forward<U>(u).a22,
		1 - std::forward<U>(u).a00 + std::forward<U>(u).a11 -
		std::forward<U>(u).a22, 1 - std::forward<U>(u).a00 -
		std::forward<U>(u).a11 + std::forward<U>(u).a22 };
	Vec3f signV = Vec3f(std::forward<U>(u).a21 - std::forward<U>(u).a12,
		std::forward<U>(u).a02 - std::forward<U>(u).a20,
		std::forward<U>(u).a10 - std::forward<U>(u).a01).sign();
	v.sqrt();
	v = (v.cast<F32>() * 0.5f).cast<F32>();
	quat = v * Vec4f(1.0f, signV);
}

template<typename U>
void Quaternion::fromAxisAndAngle(U&& u, F32 Angle) {
	Angle *= ToRadF * 0.5f;
	m_scalar = cos(Angle);
	m_vecPart = std::forward<U>(u) * sin(Angle);
}

Quaternion operator+(const Quaternion& qa, const Quaternion& qb) {
	return Quaternion(qa.quat + qb.quat);
}


Quaternion operator-(const Quaternion& qa, const Quaternion& qb) {
	return Quaternion(qa.quat - qb.quat);
}

Quaternion operator*(const Quaternion& qa, const Quaternion& qb) {
	return Quaternion(qa.m_scalar * qb.m_scalar - Dot(qa.m_vecPart, qb.m_vecPart),
		(qa.m_vecPart * qb.m_scalar) + (qb.m_vecPart * qa.m_scalar) +
		Cross(qa.m_vecPart, qb.m_vecPart));
}

Quaternion& operator+=(Quaternion& qa, const Quaternion& qb) {
	return qa = qa + qb;
}

Quaternion& operator-=(Quaternion& qa, const Quaternion& qb) {
	return qa = qa - qb;
}

Quaternion& operator*=(Quaternion& qa, const Quaternion& qb) {
	return qa = qa * qb;
}

Quaternion& Quaternion::operator=(const Quaternion& qb) {
	quat = qb.quat;
	return *this;
}

Quaternion& Quaternion::operator=(Quaternion&& qb) {
	quat = std::move(qb.quat);
	qb.quat = Vec4f::Null();
	return *this;
}

bool operator==(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat == qb.quat;
}

bool operator!=(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat != qb.quat;
}

bool operator<(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat > qb.quat;
}

bool operator<=(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat >= qb.quat;
}

bool operator>(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat < qb.quat;
}

bool operator>=(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat <= qb.quat;
}

Quaternion Conjugate(const Quaternion& q) {
	return Quaternion(q).conjugate();
}

Quaternion Inverse(const Quaternion& q) {
	return Quaternion(q).inverse();
}

Quaternion Normalize(const Quaternion& q) {
	return Quaternion(q).normalize();
}

Mat4f Matrix(const Quaternion & q) {
	return Quaternion(q).matrix();
}

Vec3f Rotate(const Quaternion& q, const Vec3f& v) {
	return (Quaternion(-Dot(q.m_vecPart, v), (v * q.m_scalar) +
		Cross(q.m_vecPart, v)) * Inverse(q)).m_vecPart;
}

Vec4f Rotate(const Quaternion& q, const Vec4f& v) {
	return (Quaternion(-Dot(q.m_vecPart, v.xyz), (v.xyz * q.m_scalar) +
		Cross(q.m_vecPart, v.xyz)) * Inverse(q)).m_vecPart;
}

Quaternion SLerp(const Quaternion & qa, const Quaternion & qb, F32 percent) {
	return Quaternion(SLerp(qa.quat, qb.quat, percent));
}

Vec3f Rotate(const Vec3f& v, const Vec3f& axis, const F32 angle) {
	return Rotate(Quaternion(axis, angle), v);
}

Vec3f Rotate(const Vec3f& v, const Vec3f& euler) {
	return Rotate(Quaternion(euler), v);
}

Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const Vec3f& euler) {
	return point + Rotate(Quaternion(euler), Direction(point, v));
}

Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const Vec3f& euler, const F32 distance) {
	return point + (Rotate(Quaternion(euler), Direction(point, v).normalize()) * distance);
}

template<Axis ax>
Vec3f Rotate(const Vec3f& v, const F32 angle) {
	return Rotate(Quaternion(ax, angle), v);
}

template<Axis ax>
Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const F32 angle) {
	return point + Rotate(Quaternion(ax, angle), Direction(point, v));
}

template<Axis ax>
Vec3f RotateAround(const Vec3f& v, const Vec3f& point, const F32 angle, const F32 distance) {
	return point + (Rotate(Quaternion(ax, angle), Direction(point, v).normalize()) * distance);
}

template<typename T>
template<Axis ax>
Vec3<F32>& Vec3<T>::rotate(const F32 angle) {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(ax, angle), *this);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::rotate(const Vec3<F32>& axis, const F32 angle) {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(v, angle), *this);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::rotate(const Vec3<F32>& euler) {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(euler), *this);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::rotateAround(const Vec3<F32>& point, const F32 angle) {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + Direction(point, *this).rotate(angle)));
}

template<typename T>
Vec3<F32>& Vec3<T>::rotateAround(const Vec3<F32>& point, const F32 angle, const F32 distance) {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + (Direction(point, *this).normalize() * distance).rotate(angle)));
}

template<typename T>
template<Axis ax>
Vec4<F32>& Vec4<T>::rotate(const F32 angle) {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(ax, angle), *this);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::rotate(const Vec3<F32>& axis, const F32 angle) {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(v, angle), *this);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::rotate(const Vec3<F32>& euler) {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	*this = Rotate(Quaternion(euler), *this);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::rotateAround(const Vec4<F32>& point, const F32 angle) {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + Direction(point, *this).rotate(angle)));
}

template<typename T>
Vec4<F32>& Vec4<T>::rotateAround(const Vec4<F32>& point, const F32 angle, const F32 distance) {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + Direction(point, *this).rotate(angle)));
}

template<Axis ax>
Vec4f Rotate(const Vec4f& v, const F32 angle) {
	return Rotate(Quaternion(ax, angle), v);
}

template<Axis ax>
Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const F32 angle) {
	return point + Rotate(Quaternion(ax, angle), Direction(point, v));
}

template<Axis ax>
Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const F32 angle, const F32 distance) {
	return point + (Rotate(Quaternion(ax, angle), Direction(point, v).normalize()) * distance);
}

Vec4f Rotate(const Vec4f& v, const Vec3f& axis, const F32 angle) {
	return Rotate(Quaternion(axis, angle), v);
}

Vec4f Rotate(const Vec4f& v, const Vec3f& euler) {
	return Rotate(Quaternion(euler), v);
}

Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const Vec3f& euler) {
	return point + Rotate(Quaternion(euler), Direction(point, v));
}

Vec4f RotateAround(const Vec4f& v, const Vec4f& point, const Vec3f& euler, const F32 distance) {
	return point + (Rotate(Quaternion(euler), Direction(point, v).normalize()) * distance);
}


std::ostream& operator<<(std::ostream& o, const Quaternion& v) {
	o << "[" << v.m_scalar << ", " << v.m_vecPart << "]\n";
	return o;
}

} // namespace math
} // namespace drak