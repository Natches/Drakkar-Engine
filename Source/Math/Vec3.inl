#include <cassert>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>


namespace drak {
namespace math {

template<typename T>
constexpr bool Vec3<T>::isIntegral;

template<typename T>
Vec3<T>::Vec3() : m_vec{ static_cast<T>(0), static_cast<T>(0), static_cast<T>(0) } {
}

template<typename T>
Vec3<T>::Vec3(const T n) : xy(n), z(n) {
}

template<typename T>
Vec3<T>::Vec3(const T X, const T Y, const T Z) : m_vec{ X, Y, Z } {
}

template<typename T>
Vec3<T>::Vec3(const Vec4<T>& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(Vec4<T>&& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(const Vec3<T>& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(Vec3<T>&& v) : m_vec{ v.x, v.y, v.z } {
}

template<typename T>
Vec3<T>::Vec3(const Vec2<T>& v, const T Z) : xy(v), z(Z) {
}

template<typename T>
Vec3<T>::Vec3(Vec2<T>&& v, const T Z) : xy(std::move(v)), z(Z) {
}

template<typename T>
Vec3<T>::Vec3(const T X, const Vec2<T>& v) : x(X), yz(v) {
}

template<typename T>
Vec3<T>::Vec3(const T X, Vec2<T>&& v) : x(X), yz(std::move(v)) {
}

template<typename T>
Vec3<T>::Vec3(const Vec2<T>& v)
	: xy(v), z(static_cast<T>(0)) {
}

template<typename T>
Vec3<T>::Vec3(Vec2<T>&& v)
	: xy(std::move(v)), z(static_cast<T>(0)) {
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
	return std::sqrt(static_cast<F32>(Dot(xy, xy) + z * z));
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(const Vec3<T>& v) {
	xy = v.xy;
	z = v.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator=(Vec3<T>&& v) {
	xy = v.xy;
	z = v.z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator+=(const T n) {
	xy += n;
	z  += n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator-=(const T n) {
	xy -= n;
	z  -= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator*=(const T n) {
	xy *= n;
	z  *= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator/=(const T n) {
	if (IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= n;
		y /= n;
		z /= n;
	}
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator>>=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	xy >>= n;
	z >>= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator<<=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	xy <<= n;
	z <<= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator&=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	xy &= n;
	z &= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator^=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	xy ^= n;
	z ^= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator|=(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) {
	xy |= n;
	z |= n;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator++() {
	++xy;
	++z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::operator--() {
	--xy;
	--z;
	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::operator+(const T n) const {
	return Vec3<T>(xy + n, z + n);
}

template<typename T>
Vec3<T> Vec3<T>::operator-(const T n) const {
	return Vec3<T>(xy - n, z - n);
}

template<typename T>
Vec3<T> Vec3<T>::operator*(const T n) const {
	return Vec3<T>(xy * n, z * n);
}

template<typename T>
Vec3<T> Vec3<T>::operator/(const T n) const {
	if (IsNotEqual_V<T>(n, static_cast<T>(0)))
		return Vec3<T>(x / n, y / n, z / n);
	return Vec3<T>(x, y, z);
}

template<typename T>
Vec3<T> Vec3<T>::operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(xy >> n, z >> n);
}

template<typename T>
Vec3<T> Vec3<T>::operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(xy << n, z << n);
}

template<typename T>
Vec3<T> Vec3<T>::operator&(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(xy & n, z & n);
}

template<typename T>
Vec3<T> Vec3<T>::operator^(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(xy ^ n, z ^ n);
}

template<typename T>
Vec3<T> Vec3<T>::operator|(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, I32, NOT_A_TYPE)n) const {
	return Vec3<T>(xy | n, z | n);
}

template<typename T>
Vec3<T> Vec3<T>::operator++(const I32) const {
	return Vec3<T>(xy++, z++);
}

template<typename T>
Vec3<T> Vec3<T>::operator--(const I32) const {
	return Vec3<T>(xy--, z--);
}

template<typename T>
Vec3<T> Vec3<T>::operator-() const {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec3<T>(-xy, -z);
}

template<typename T>
Vec3<T>& Vec3<T>::negate() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	xy.negate();
	z = -z;
	return *this;
}

template<typename T>
Vec3<T>& Vec3<T>::abs() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	xy.abs();
	z = std::abs(z);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::ceil() {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	xy.ceil();
	z = std::ceil(z);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::floor() {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	xy.floor();
	z = std::floor(z);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::round() {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	xy.round();
	z = std::round(z);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::sqrt() {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	xy.sqrt();
	z = std::sqrt(z);
	return *this;
}

template<typename T>
Vec3<F32>& Vec3<T>::normalize() {
	static_assert(!Vec3<T>::isIntegral, DK_MATH_ERROR2(T));
	F32 size = magnitude();
	if (IsNotEqual_V(size, 0.f))
		return *this /= size;
	return *this;
}

template<typename T>
Vec3<T> Vec3<T>::sign() const {
	return Vec4<T>(*this).sign();
}

template<typename T>
template<typename U>
Vec3<U> Vec3<T>::cast() const {
	static_assert(std::is_scalar_v<U>, DK_MATH_ERROR0(U));
	return Vec3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
}

template<typename T>
Vec2<T> Vec3<T>::yx() const {
	return Vec2<T>(y, x);
}

template<typename T>
Vec2<T> Vec3<T>::zy() const {
	return Vec2<T>(z, y);
}

template<typename T>
Vec2<T> Vec3<T>::xz() const {
	return Vec2<T>(x, z);
}

template<typename T>
Vec2<T> Vec3<T>::zx() const {
	return Vec2<T>(z, x);
}

template<typename T>
Vec3<T> Vec3<T>::zyx() const {
	return Vec3<T>(z, y, x);
}

template<typename T>
Vec3<T> Vec3<T>::yzx() const {
	return Vec3<T>(y, z, x);
}

template<typename T>
Vec3<T> Vec3<T>::zxy() const {
	return Vec3<T>(z, x, y);
}

template<typename T>
Vec2<T> Vec3<T>::gr() const {
	return Vec2<T>(g, r);
}

template<typename T>
Vec2<T> Vec3<T>::bg() const {
	return Vec2<T>(b, g);
}

template<typename T>
Vec2<T> Vec3<T>::rb() const {
	return Vec2<T>(r, b);
}

template<typename T>
Vec2<T> Vec3<T>::br() const {
	return Vec2<T>(b, r);
}

template<typename T>
Vec3<T> Vec3<T>::bgr() const {
	return Vec3<T>(b, g, r);
}

template<typename T>
Vec3<T> Vec3<T>::gbr() const {
	return Vec3<T>(g, b, r);
}

template<typename T>
Vec3<T> Vec3<T>::brg() const {
	return Vec3<T>(b, r, g);
}

template<typename T>
Vec3<T> Vec3<T>::Null() {
	return Vec3<T>();
}

template<typename T>
Vec3<T> Vec3<T>::Up() {
	return Vec3<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
}

template<typename T>
Vec3<T> Vec3<T>::Right() {
	return Vec3<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
}

template<typename T>
Vec3<T> Vec3<T>::Forward() {
	return Vec3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
}

template<typename T>
bool operator==(const Vec3<T>& v1, const Vec3<T>& v2) {
	return v1.xy == v2.xy && v1.z == v2.z;
}

template<typename T>
bool operator!=(const Vec3<T>& v1, const Vec3<T>& v2) {
	return v1.xy != v2.xy && v1.z != v2.z;
}

template<typename T>
bool operator>(const Vec3<T>& v1, const Vec3<T>& v2) {
	return !(v1.xy < v2.xy && v1.z < v2.z);
}

template<typename T>
bool operator<(const Vec3<T>& v1, const Vec3<T>& v2) {
	return !(v1.xy > v2.xy && v1.z > v2.z);
}

template<typename T>
bool operator>=(const Vec3<T>& v1, const Vec3<T>& v2) {
	return !(v1.xy <= v2.xy && v1.z <= v2.z);
}

template<typename T>
bool operator<=(const Vec3<T>& v1, const Vec3<T>& v2) {
	return !(v1.xy >= v2.xy && v1.z >= v2.z);
}

template<typename T>
Vec3<T> operator+(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.xy + v2.xy, v1.z + v2.z);
}

template<typename T>
Vec3<T> operator-(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.xy - v2.xy, v1.z - v2.z);
}

template<typename T>
Vec3<T> operator*(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(v1.xy * v2.xy, v1.z * v2.z);
}

template<typename T>
Vec3<T> operator/(const Vec3<T>& v1, const Vec3<T>& v2) {
	if (!v2.isNull())
		return Vec3<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
	else
		return Vec3<T>(v1.x, v1.y, v1.z);
}

template<typename T>
Vec3<T> operator>>(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.xy >> v2.xy, v1.z >> v2.z);
}
template<typename T>
Vec3<T> operator<<(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.xy << v2.xy, v1.z << v2.z);
}
template<typename T>
Vec3<T> operator&(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.xy & v2.xy, v1.z & v2.z);
}
template<typename T>
Vec3<T> operator^(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.xy ^ v2.xy, v1.z ^ v2.z);
}
template<typename T>
Vec3<T> operator|(const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	return Vec3<T>(v1.xy | v2.xy, v1.z | v2.z);
}

template<typename T>
Vec3<T>& operator+=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.xy += v2.xy;
	v1.z += v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator-=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.xy -= v2.xy;
	v1.z -= v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator*=(Vec3<T>& v1, const Vec3<T>& v2) {
	v1.xy *= v2.xy;
	v1.z *= v2.z;
	return v1;
}

template<typename T>
Vec3<T>& operator/=(Vec3<T>& v1, const Vec3<T>& v2) {
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
	v1.xy >>= v2.xy;
	v1.z >>= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator<<=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.xy <<= v2.xy;
	v1.z <<= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator&=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.xy &= v2.xy;
	v1.z &= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator^=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.xy ^= v2.xy;
	v1.z ^= v2.z;
	return v1;
}
template<typename T>
Vec3<T>& operator|=(ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec3<T>::isIntegral, Vec3<T>, NOT_A_TYPE)& v2) {
	v1.xy |= v2.xy;
	v1.z |= v2.z;
	return v1;
}

template<typename T>
T Dot(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Dot(v1.xy, v2.xy) + v1.z * v2.z;
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

Vec3f Normalize(const Vec3f& v) {
	F32 size = v.magnitude();
	if (IsNotEqual_V(size, 0.f))
		return v / size;
	return v;
}

template<typename T>
Vec3<T> Negate(const Vec3<T>& v) {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec3<T>(Negate(v.xy), -v.z);
}

template<typename T>
Vec3<T> Abs(const Vec3<T>& v) {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec3<T>(Abs(v.xy), std::abs(v.z));
}

template<typename T>
Vec3<T> Min(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(Min(v1.xy, v2.xy), v1.z < v2.z ? v1.z : v2.z);
}

template<typename T>
Vec3<T> Max(const Vec3<T>& v1, const Vec3<T>& v2) {
	return Vec3<T>(Max(v1.xy, v2.xy), v1.z > v2.z ? v1.z : v2.z);
}

Vec3f Ceil(const Vec3f& v) {
	return Vec3f(Ceil(v.xy), std::ceil(v.z));
}

Vec3f Floor(const Vec3f& v) {
	return Vec3f(Floor(v.xy), std::floor(v.z));
}

Vec3f Round(const Vec3f& v) {
	return Vec3f(Round(v.xy), std::round(v.z));
}

Vec3f Sqrt(const Vec3f& v) {
	return Vec3f(Sqrt(v.xy), std::sqrt(v.z));
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
	return o << "{ x : " << v.x << ", y : " << v.y << ", z : " << v.z << " }";
}

} //namespace math 
} //namespace drak