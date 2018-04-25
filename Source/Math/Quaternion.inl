#include <Math/Quaternion.hpp>

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
	v = Vec4f::Null();
}

Quaternion::Quaternion(const F32 scalar, Vec3f&& v) 
	: m_scalar(scalar), m_vecPart(std::move(v)) {
}

template<AngleUnit au>
Quaternion::Quaternion(const Vec3f& euler) {
	fromEuler<au>(euler);
}

template<AngleUnit au>
Quaternion::Quaternion(Vec3f&& euler) {
	fromEuler<au>(std::move(euler));
}

template<AngleUnit au>
Quaternion::Quaternion(const Vec3f& axis, F32 Angle) {
	fromAxisAndAngle(axis, Angle);
}

template<AngleUnit au>
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

Quaternion Quaternion::conjugate() const {
	return quat.conjugate();
}

float Quaternion::magnitude() const {
	return quat.magnitude();
}

Quaternion Quaternion::inverse() const {
	float magn = magnitude();
	if (IsEqual_V<float>(magn, 1.f))
		return conjugate();
	else
		return conjugate() / (magn * magn);
}

Quaternion Quaternion::normalize() const {
	return *this / magnitude();
}

Quaternion Quaternion::operator+(const F32 f) const {
	return quat + f;
}

Quaternion& Quaternion::operator+=(const F32 f) {
	*this = *this + f;
}

Quaternion Quaternion::operator-(const F32 f) const {
	return quat - f;
}

Quaternion& Quaternion::operator-=(const F32 f) {
	*this = *this - f;
}

Quaternion Quaternion::operator*(const F32 f) const {
	return quat * f;
}

Quaternion& Quaternion::operator*=(const F32 f) {
	*this = *this * f;
}

Quaternion Quaternion::operator/(const F32 f) const {
	return quat / f;
}

Quaternion& Quaternion::operator/=(const F32 f) {
	*this = *this / f;
}

Mat4f Quaternion::matrix() const {
	Quaternion normalized = normalize();
	Vec8<F32> vec = ( Vec8<F32>(Vec4f(normalized.m_vecPart, normalized.m_vecPart.x),
		Vec4f(normalized.m_vecPart, normalized.m_vecPart.x)) *
		Vec8<F32>(Vec4f(normalized.m_vecPart, normalized.m_vecPart.y),
			Vec4f(normalized.m_scalar, normalized.m_scalar, normalized.m_scalar, normalized.m_vecPart.z)))* 2;
	F32 vYZ = 2 * (normalized.m_vecPart.y * normalized.m_vecPart.z);
	return Mat4f( 1 - (vec.y + vec.z), (vec.w - vec.c), (vec.d + vec.b), 0,
						(vec.w + vec.c), 1 - (vec.x + vec.z), (vYZ - vec.a), 0,
						(vec.d - vec.b), (vYZ + vec.a), 1 - (vec.x + vec.y), 0,
						 0, 0, 0, 1);
}

Vec3f Quaternion::euler() const {
	Vec8<F32> vec = (Vec8<F32>(Vec4f(m_scalar, m_scalar, m_scalar, m_vecPart.y),
		Vec4f(m_vecPart, m_vecPart.x)) * Vec8<F32>(Vec4f(m_vecPart, m_vecPart.z),
			Vec4f(m_vecPart.y, m_vecPart.y, m_vecPart.x, m_vecPart.x)));
	F32 pitch = std::clamp(-2 * (vec.c - vec.y), -1.0f, 1.0f);
	return Vec3f(IsEqual_V(pitch, -1.f) ?
		atan2f(m_vecPart.x, m_scalar) : IsEqual_V(pitch, 1.f) ?
		atan2f(m_vecPart.x, m_scalar) :
		atan2f(vec.x + vec.w, 0.5f - (vec.b + vec.d)),
		asinf(pitch),
		IsEqual_V(fabs(pitch), 1.f) ? 0.f : atan2f((vec.z + vec.a), 0.5f - (vec.b + (m_vecPart.z * m_vecPart.z))));
}

template<AngleUnit au, typename U>
void Quaternion::fromEuler(U&& u) {
	Vec3f theta;
	if constexpr(au == AngleUnit::DEGREE)
		theta = { (std::forward<U>(u) * (ToRadF * 0.5f)) };
	else
		theta = { (std::forward<U>(u) * 0.5f) };
	Vec3f cosV{ cos(theta.x), cos(theta.y), cos(theta.z) };
	Vec3f sinV{ sin(theta.x), sin(theta.y), sin(theta.z) };

	m_scalar = cosV.x * cosV.y * cosV.z + sinV.x * sinV.y * sinV.z;
	m_vecPart = { sinV.x * cosV.y * cosV.z - cosV.x * sinV.y * sinV.z,
		cosV.x * sinV.y * cosV.z + sinV.x * cosV.y * sinV.z,
		cosV.x * cosV.y * sinV.z - sinV.x * sinV.y * cosV.z };
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
	v = v.sqrt();
	v = (v.cast<F32>() * 0.5f).cast<F32>();
	quat = v * Vec4f(1.0f, signV);
}

template<AngleUnit au, typename U>
inline void Quaternion::fromAxisAndAngle(U&& u, F32 Angle) {
	if constexpr (au == AngleUnit::DEGREE)
		Angle *= ToRadF * 0.5f;
	else
		Angle *= 0.5f;
	
	m_scalar = cos(Angle);
	m_vecPart = std::forward<U>(u) * sin(Angle);
}

Quaternion operator+(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat + qb.quat;
}


Quaternion operator-(const Quaternion& qa, const Quaternion& qb) {
	return qa.quat - qb.quat;
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

Vec3f Rotate(const Quaternion& q, const Vec3f& v) {
	return (Quaternion(-Dot(q.m_vecPart, v), (v * q.m_scalar) +
		Cross(q.m_vecPart, v))* q.inverse()).m_vecPart;
}

Vec4f Rotate(const Quaternion& q, const Vec4f& v) {
	Vec3f temp = v.xyz;
	return (Quaternion(-Dot(q.m_vecPart, temp), (temp * q.m_scalar) +
		Cross(q.m_vecPart, temp))* q.inverse()).m_vecPart;
}

std::ostream& operator<<(std::ostream& o, const Quaternion& v) {
	o << "[" << v.m_scalar << ", " << v.m_vecPart << "]\n";
	return o;
}

} // namespace math
} // namespace drak