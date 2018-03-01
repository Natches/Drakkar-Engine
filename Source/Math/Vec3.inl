#include "Vec3.hpp"

namespace drak {
namespace math {

template<typename T>
constexpr bool Vec3<T>::isLarger;

template<typename T>
constexpr bool Vec3<T>::isIntegral;

template<typename T>
Vec3<T>::Vec3() : m_vec{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) } {
}

template<typename T>
Vec3<T>::Vec3(const Type X, const Type Y, const Type Z) : m_vec{ X, Y, Z } {
}

template<typename T>
Vec3<T>::Vec3(ENABLE_IF_ELSE_T(isLarger, T &&, NOT_A_TYPE)X,
	ENABLE_IF_ELSE_T(isLarger, T &&, NOT_A_TYPE)Y,
	ENABLE_IF_ELSE_T(isLarger, T &&, NOT_A_TYPE)Z) :
	m_vec{ std::forward<T>(X), std::forward<T>(Y), std::forward<T>(Z) } {
}

template<typename T>
Vec3<T>::Vec3(const Vec3<T>& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(Vec3<T>&& v) 
	: m_vec{ std::move(std::forward<Vec2<T>>(v).x),
	std::move(std::forward<Vec2<T>>(v).y),
	std::move(std::forward<Vec2<T>>(v).z) } {
}

template<typename T>
bool Vec3<T>::operator==(const Vec3<T>& v) const {
	return x == v.x && y == v.y && z == v.z;
}

template<typename T>
bool Vec3<T>::operator!=(const Vec3<T>& v) const {
	return x != v.x && y != v.y && z != v.z;
}

template<typename T>
bool Vec3<T>::operator>(const Vec3<T>& v) const {
	return x > v.x && y > v.y && z > v.z;
}

template<typename T>
bool Vec3<T>::operator<(const Vec3<T>& v) const {
	return x < v.x && y < v.y && z < v.z;
}

template<typename T>
bool Vec3<T>::operator>=(const Vec3<T>& v) const {
	return x >= v.x && y >= v.y && z >= v.z;
}

template<typename T>
bool Vec3<T>::operator<=(const Vec3<T>& v) const {
	return x <= v.x && y <= v.y && z <= v.z;
}

template<typename T>
bool Vec3<T>::isNormalized() const {
	return IsEqual_V<F32>(magnitude(), 1.f)
}

template<typename T>
bool Vec3<T>::isNull() const {
	return IsEqual_V<T>(x, static_cast<T>(0)) &&
		IsEqual_V<T>(y, static_cast<T>(0)) &&
		IsEqual_V<T>(z, static_cast<T>(0));
}

template<typename T>
F32 Vec3<T>::magnitude() const {
	return sqrt<F32>(x * x + y * y + z * z);
}

template<typename T>
template<Axis ax, AngleUnit au>
F32 Vec3<T>::rotation() const {
	if constexpr(ax == Axis::Z) {
		if constexpr (au == AngleUnit::DEGREE) {
			if (F32 angle = computeAngleZ(); 0.f < angle)
				return angle * ToDegF;
			else if (0.f > angle)
				return (angle * ToDegF) + 360.f;
		}
		return angle;		
	}
	else if constexpr(ax == Axis::Y) {
		if constexpr (au == AngleUnit::DEGREE) {
			if (F32 angle = computeAngleY(); 0.f < angle)
				return angle * ToDegF;
			else if (0.f > angle)
				return (angle * ToDegF) + 360.f;
		}
		return angle;
	}
	else {
		if constexpr (au == AngleUnit::DEGREE) {
			if (F32 angle = computeAngleX(); 0.f < angle)
				return angle * ToDegF;
			else if (0.f > angle)
				return (angle * ToDegF) + 360.f;
		}
		return angle;
	}
}

template<AngleUnit au>
Vec3<T> Vec3<T>::rotation() const {
	return Vec3<T>(rotation<Axis::X, au>(), rotation<Axis::Y, au>(), rotation<Axis::Z, au>());
}

template<typename T>
F32 Vec3<T>::computeAngleX() {
	if (z > static_cast<T>(0))
		return std::acos<F32>(y / magnitude());
	else if (z < static_cast<T>(0))
		return -std::acos<F32>(y / magnitude());
	return 0.f;
}

template<typename T>
F32 Vec3<T>::computeAngleY() {
	if (x > static_cast<T>(0))
		return std::acos<F32>(z / magnitude());
	else if (x < static_cast<T>(0))
		return -std::acos<F32>(z / magnitude());
	return 0.f;
}

template<typename T>
F32 Vec3<T>::computeAngleZ() {
	if (y > static_cast<T>(0))
			return std::acos<F32>(x / magnitude());
	else if (y < static_cast<T>(0))
			return -std::acos<F32>(x / magnitude());
	return 0.f;
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(const Vec3<T>& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(Vec3<T>&& v) {
	x = std::move(std::forward<Vec3<T>>(v).x);
	y = std::move(std::forward<Vec3<T>>(v).y);
	z = std::move(std::forward<Vec3<T>>(v).z);
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(const Type n) {
	x += n;
	y += n;
	z += n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(const Type n) {
	x -= n;
	y -= n;
	z -= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(const Type n) {
	x *= n;
	y *= n;
	z *= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator/=(const Type n) {
	assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
	if (types::IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= n;
		y /= n;
		z /= n;
	}
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) {
	x += std::forward<T>(n);
	y += std::forward<T>(n);
	z += std::forward<T>(n);
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) {
	x -= std::forward<T>(n);
	y -= std::forward<T>(n);
	z -= std::forward<T>(n);
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) {
	x *= std::forward<T>(n);
	y *= std::forward<T>(n);
	z *= std::forward<T>(n);
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator/=(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) {
	assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
	if (types::IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= std::forward<T>(n);
		y /= std::forward<T>(n);
		z /= std::forward<T>(n);
	}
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	x >>= n;
	y >>= n;
	z >>= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	x <<= n;
	y <<= n;
	z <<= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator&=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	x &= n;
	y &= n;
	z &= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator^=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	x ^= n;
	y ^= n;
	z ^= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator|=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	x |= n;
	y |= n;
	z |= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator++() {
	++x;
	++y;
	++z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator--() {
	--x;
	--y;
	--z;
	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const Type n) const {
	return Vec3<T>(v.x + n, v.y + n, v.z + n);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const Type n) const {
	return Vec3<T>(v.x - n, v.y - n, v.z - n);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const Type n) const {
	return Vec3<T>(v.x * n, v.y * n, v.z * n);
}

template<typename T>
Vec3<T> Vec3<T>::operator/(const Type n) const {
	assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
	if (types::IsNotEqual_V<T>(n, static_cast<T>(0)))
		return Vec3<T>(x / n, y / n, z / n);
	return Vec3<T>(x, y, z);
}

template<typename T>
Vec3<T> Vec3<T>::operator+(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) const {
	return Vec3<T>(x + std::forward<T>(n), y + std::forward<T>(n), z + std::forward<T>(n));
}

template<typename T>
Vec3<T> Vec3<T>::operator-(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) const {
	return Vec3<T>(x - std::forward<T>(n), y - std::forward<T>(n), z - std::forward<T>(n));
}

template<typename T>
Vec3<T> Vec3<T>::operator*(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) const {
	return Vec3<T>(x * std::forward<T>(n), y * std::forward<T>(n), z * std::forward<T>(n));
}

template<typename T>
Vec3<T> Vec3<T>::operator/(ENABLE_IF_ELSE_T(isLarger, T&&, NOT_A_TYPE)n) const {
	assert(types::IsEqual_V<T>(std::forward<T>(n), static_cast<T>(0)));
	if (types::IsNotEqual_V<T>(std::forward<T>(n), static_cast<T>(0)))
		return Vec3<T>(x / std::forward<T>(n), y / std::forward<T>(n), z / std::forward<T>(n));
	return Vec3<T>(x, y, z);
}

template<typename T>
Vec3<T> Vec3<T>::operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x >> n, y >> n, z >> n);
}

template<typename T>
Vec3<T> Vec3<T>::operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x << n, y << n, z << n);
}

template<typename T>
Vec3<T> Vec3<T>::operator&(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x & n, y & n, z & n);
}

template<typename T>
Vec3<T> Vec3<T>::operator^(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x ^ n, y ^ n, z ^ n);
}

template<typename T>
Vec3<T> Vec3<T>::operator|(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x | n, y | n, z | n);
}

template<typename T>
Vec3<T> Vec3<T>::operator++(const I32) const {
	return Vec3<T>(x++, y++, z++);
}

template<typename T>
Vec3<T> Vec3<T>::operator--(const I32) const {
	return Vec3<T>(x--, y--, z--);
}

template<typename T>
Vec3<T> Vec3<T>::operator-() const {
	return Vec3<T>(-x, -y, -z);
}

template<typename T>
Vec3<T> Vec3<T>::conjugate() const {
	return -*this;
}

template<typename T>
Vec3<T> Vec3<T>::normalize() const {
	F32 size = magnitude();
	assert(types::IsEqual_V(size, static_cast<T>(0)))
	if (types::IsNotEqual_V(size, static_cast<T>(0)))
		return *this / size;
	return *this;
}

template<typename T>
template<Axis ax>
Vec3<T> Vec3<T>::rotate(const F32 angle) const {
	return Vec3<T>();
	//TODO rotation with quat return Vec3<T>();
}

template<typename T>
template<Axis ax>
Vec3<T> Vec3<T>::rotate(const Vec3<T>& euler) const {
	return Vec3<T>();
	//TODO rotation with quat return Vec3<T>();
}

template<typename T>
template<typename U>
Vec3<U> Vec3<T>::cast() const {
	return Vec3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
}

template<typename T>
Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template<typename T>
Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<typename T>
Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template<typename T>
Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>();
}

} //namespace math 
} //namespace drak