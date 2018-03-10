#include<cassert>
#include<Math/Vec3.hpp>

namespace drak {
namespace math {

template<typename T>
constexpr bool Vec3<T>::isIntegral;

template<typename T>
Vec3<T>::Vec3() : m_vec{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) } {
}

template<typename T>
Vec3<T>::Vec3(const T X, const T Y, const T Z) : m_vec{ X, Y, Z } {
}

template<typename T>
Vec3<T>::Vec3(const Vec3<T>& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(Vec3<T>&& v) 
	: m_vec{ std::forward<Vec3<T>>(v).x, std::forward<Vec3<T>>(v).y, std::forward<Vec3<T>>(v).z } {
}

template<typename T>
Vec3<T>::Vec3(const Vec2<T>& v)
	: m_vec{ v.x, v.y, static_cast<T>(0) } {
}

template<typename T>
Vec3<T>::Vec3(Vec2<T>&& v)
	: m_vec{ std::forward<Vec2<T>>(v).x, std::forward<Vec2<T>>(v).y, static_cast<T>(0) } {
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
	return !(x < v.x && y < v.y && z < v.z);
}

template<typename T>
bool Vec3<T>::operator<(const Vec3<T>& v) const {
	return !(x > v.x && y > v.y && z > v.z);
}

template<typename T>
bool Vec3<T>::operator>=(const Vec3<T>& v) const {
	return !(x <= v.x && y <= v.y && z <= v.z);
}

template<typename T>
bool Vec3<T>::operator<=(const Vec3<T>& v) const {
	return !(x >= v.x && y >= v.y && z >= v.z);
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
	return std::sqrt(static_cast<F32>(x * x + y * y + z * z));
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

template<typename T>
template<AngleUnit au>
Vec3<T> Vec3<T>::rotation() const {
	return Vec3<T>(rotation<Axis::X, au>(), rotation<Axis::Y, au>(), rotation<Axis::Z, au>());
}

template<>
Vec3<F32> Vec3<F32>::ceil() {
	return Vec3<F32>(std::ceil(x), std::ceil(y), std::ceil(z));
}

template<>
Vec3<F32> Vec3<F32>::floor() {
	return Vec3<F32>(std::floor(x), std::floor(y), std::floor(z));
}

template<>
Vec3<F32> Vec3<F32>::round() {
	return Vec3<F32>(std::round(x), std::round(y), std::round(z));
}

template<typename T>
Vec2<T> Vec3<T>::xy() {
	return Vec2<T>(x, y);
}

template<typename T>
Vec2<T> Vec3<T>::yz() {
	return Vec2<T>(y, z);
}

template<typename T>
Vec2<T> Vec3<T>::yx() {
	return Vec2<T>(y, x);
}

template<typename T>
Vec2<T> Vec3<T>::zy() {
	return Vec2<T>(z, y);
}

template<typename T>
Vec2<T> Vec3<T>::xz() {
	return Vec2<T>(x, z);
}

template<typename T>
Vec2<T> Vec3<T>::zx() {
	return Vec2<T>(z, x);
}

template<typename T>
Vec3<T> Vec3<T>::zyx() {
	return Vec3<T>(z, y, x);
}

template<typename T>
Vec3<T> Vec3<T>::yzx() {
	return Vec3<T>(y, z, x);
}

template<typename T>
Vec3<T> Vec3<T>::zxy() {
	return Vec3<T>(z, x, y);
}

template<typename T>
Vec3<T> Vec3<T>::bgr() {
	return Vec3<T>(b, g, r);
}

template<typename T>
Vec3<T> Vec3<T>::gbr() {
	return Vec3<T>(g, b, r);
}

template<typename T>
Vec3<T> Vec3<T>::brg() {
	return Vec3<T>(b, r, g);
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
Vec3<T>& Vec3<T>::operator+=(const T n) {
	x += n;
	y += n;
	z += n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(const T n) {
	x -= n;
	y -= n;
	z -= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(const T n) {
	x *= n;
	y *= n;
	z *= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator/=(const T n) {
	assert(IsNotEqual_V<T>(n, static_cast<T>(0)));
	if (IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= n;
		y /= n;
		z /= n;
	}
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator>>=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	x >>= n;
	y >>= n;
	z >>= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator<<=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	x <<= n;
	y <<= n;
	z <<= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator&=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	x &= n;
	y &= n;
	z &= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator^=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	x ^= n;
	y ^= n;
	z ^= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator|=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
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
Vec3<T> Vec3<T>::operator+(const T n) const {
	return Vec3<T>(x + n, y + n, z + n);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const T n) const {
	return Vec3<T>(x - n, y - n, z - n);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T n) const {
	return Vec3<T>(x * n, y * n, z * n);
}

template<typename T>
Vec3<T> Vec3<T>::operator/(const T n) const {
	assert(IsNotEqual_V<T>(n, static_cast<T>(0)));
	if (IsNotEqual_V<T>(n, static_cast<T>(0)))
		return Vec3<T>(x / n, y / n, z / n);
	return Vec3<T>(x, y, z);
}

template<typename T>
Vec3<T> Vec3<T>::operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x >> n, y >> n, z >> n);
}

template<typename T>
Vec3<T> Vec3<T>::operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x << n, y << n, z << n);
}

template<typename T>
Vec3<T> Vec3<T>::operator&(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x & n, y & n, z & n);
}

template<typename T>
Vec3<T> Vec3<T>::operator^(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(x ^ n, y ^ n, z ^ n);
}

template<typename T>
Vec3<T> Vec3<T>::operator|(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
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
	assert(IsNotEqual_V(size, static_cast<T>(0)))
	if (IsNotEqual_V(size, static_cast<T>(0)))
		return *this / size;
	return Vec3<T>(x, y, z);
}

template<typename T>
template<Axis ax>
Vec3<T> Vec3<T>::rotate(const F32 angle) const {
	static_assert(false, "Not implemented !!");
	return Vec3<T>();
	//TODO rotation with quat return Vec3<T>();
}

template<typename T>
template<Axis ax>
Vec3<T> Vec3<T>::rotate(const Vec3<T>& euler) const {
	static_assert(false, "Not implemented !!");
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
	assert(!v2.isNull());
	if (!v2.isNull())
		return Vec3<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
	else
		return Vec3<T>(v1.x, v1.y, v1.z);
}

template<typename T>
Vec3<T> operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z);
}
template<typename T>
Vec3<T> operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z);
}
template<typename T>
Vec3<T> operator&(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z);
}
template<typename T>
Vec3<T> operator^(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z);
}
template<typename T>
Vec3<T> operator|(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z);
}

template<typename T>
Vec3<T>& operator+=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator-=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator*=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator/=(Vec3<T>& v1, const Vec3<T>& v2) {
	assert(!v2.isNull());
	if (!v2.isNull()) {

		v1.x /= v2.x;
		v1.y /= v2.y;
		v1.z /= v2.z;
	}
	return v1;
}

template<typename T>
Vec3<T>& operator>>=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.x >>= v2.x;
	v1.y >>= v2.y;
	v1.z >>= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator<<=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.x <<= v2.x;
	v1.y <<= v2.y;
	v1.z <<= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator&=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.x &= v2.x;
	v1.y &= v2.y;
	v1.z &= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator^=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.x ^= v2.x;
	v1.y ^= v2.y;
	v1.z ^= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator|=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.x |= v2.x;
	v1.y |= v2.y;
	v1.z |= v2.z;
	return v1;
}

template<typename T>
T Dot(const Vec3<T>& v1, const Vec3<T>& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<typename T>
Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
}

template<typename T>
F32 Distance(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Direction(v1, v2).magnitude();
}

template<typename T>
Vec3<T> Direction(const Vec3<T>& origin, const Vec3<T>& destination) {
	return destination - origin;
}

template<typename T>
bool ArePerpendicular(const Vec3<T>& v1, const Vec3<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(0));
}
template<typename T>
bool AreColinear(const Vec3<T>& v1, const Vec3<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(1));
}
template<typename T>
bool AreOpposed(const Vec3<T>& v1, const Vec3<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(-1));
}
template<typename T>
bool AreSameDirection(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Dot(v1, v2) > static_cast<T>(0);
}
template<typename T>
bool AreOpposedDirection(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Dot(v1, v2) < static_cast<T>(0);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec3<T>& v) {
	return o << "{ x : " << v.x << ", y :" << v.y << ", z : " << v.z << " }";
}

} //namespace math 
} //namespace drak