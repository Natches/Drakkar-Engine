#include<cassert>
#include<string>
#include<Math/Vec2.hpp>

namespace drak {
namespace math {

template<typename T>
constexpr bool Vec2<T>::isIntegral;

template<typename T>
Vec2<T>::Vec2() : m_vec{ static_cast<T>(0), static_cast<T>(0) } {
}

template<typename T>
Vec2<T>::Vec2(const T n) : m_vec{ n, n } {
}

template<typename T>
Vec2<T>::Vec2(const T* arr) : memcpy(m_vec, arr, sizeof(m_vec)) {
}

template<typename T>
Vec2<T>::Vec2(const T X, const T Y) : m_vec{ X, Y } {

}

template<typename T>
Vec2<T>::Vec2(const Vec2<T>& v) : m_vec{ v.x, v.y } {
}

template<typename T> 
Vec2<T>::Vec2(Vec2<T>&& v) 
	: m_vec{ v.x, v.y } {
}

template<typename T>
bool Vec2<T>::isNormalized() const {
	return IsEqual_V<F32>(magnitude(), 1.0f);
}

template<typename T>
bool Vec2<T>::isNull() const {
	return IsEqual_V<T>(x, static_cast<T>(0)) && IsEqual_V<T>(y, static_cast<T>(0));
}

template<typename T>
F32 Vec2<T>::magnitude() const {
	return std::sqrt(static_cast<F32>(x * x + y * y));
}

template<typename T>
template<AngleUnit au>
F32 Vec2<T>::rotation() const {
	if (y) {
		if (y > static_cast<T>(0))
			if constexpr (au == AngleUnit::DEGREE)
				return std::acos(x / magnitude()) * ToDegF;
			else
				return std::acos(x / magnitude());
		else if (y < static_cast<T>(0))
			if constexpr (au == AngleUnit::DEGREE)
				return -(std::acos(x / magnitude()) * ToDegF);
			else
				return -std::acos(x / magnitude());
	}
	else
		return 0.f;
	return 0.f;
}

template<typename T>
Vec2<T>& Vec2<T>::operator=(const Vec2<T>& v) {
	x = v.x;
	y = v.y;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator=(Vec2<T>&& v) {
	x = v.x;
	y = v.y;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator+=(const T n) {
	x += n;
	y += n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator-=(const T n) {
	x -= n;
	y -= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator*=(const T n) {
	x *= n;
	y *= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator/=(const T n) {
	if (IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= n;
		y /= n;
	}
	return *this;
}

template<typename T>
Vec2<T>& Vec2<T>::operator>>=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) {
	x >>= n;
	y >>= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator<<=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) {
	x <<= n;
	y <<= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator&=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) {
	x &= n;
	y &= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator^=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) {
	x ^= n;
	y ^= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator|=(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) {
	x |= n;
	y |= n;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator++() {
	++x;
	++y;
	return *this;
}
template<typename T>
Vec2<T>& Vec2<T>::operator--() {
	--x;
	--y;
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::operator+(const T n) const {
	return Vec2<T>(x + n, y + n);
}
template<typename T>
Vec2<T> Vec2<T>::operator-(const T n) const {
	return Vec2<T>(x - n, y - n);
}
template<typename T>
Vec2<T> Vec2<T>::operator*(const T n) const {
	return Vec2<T>(x * n, y * n);
}
template<typename T>
Vec2<T> Vec2<T>::operator/(const T n) const {
	if(IsNotEqual_V<T>(n, static_cast<T>(0)))
		return Vec2<T>(x / n, y / n);
	return Vec2<T>(x, y);
}

template<typename T>
Vec2<T> Vec2<T>::operator>>(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const {
	return Vec2<T>(x >> n, y >> n);
}
template<typename T>
Vec2<T> Vec2<T>::operator<<(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const {
	return Vec2<T>(x << n, y << n);
}
template<typename T>
Vec2<T> Vec2<T>::operator&(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const {
	return Vec2<T>(x & n, y & n);
}
template<typename T>
Vec2<T> Vec2<T>::operator^(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const {
	return Vec2<T>(x ^ n, y ^ n);
}
template<typename T>
Vec2<T> Vec2<T>::operator|(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, I32, NOT_A_TYPE) n) const {
	return Vec2<T>(x | n, y | n);
}

template<typename T>
Vec2<T> Vec2<T>::operator++(const I32) const {
	return Vec2<T>(x++, y++);
}
template<typename T>
Vec2<T> Vec2<T>::operator--(const I32) const {
	return Vec2<T>(x++, y++);
}
template<typename T>
Vec2<T> Vec2<T>::operator-() const {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec2<T>(-x, -y);
}

template<typename T>
Vec2<T>& Vec2<T>::negate() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	x = -x;
	y = -y;
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::normalize() {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	F32 size = magnitude();
	if(IsNotEqual_V(size, 0.f))
		return *this /= size;
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::rotate(F32 angle) {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	angle *= ToRadF;
	T angleCos = std::cos(angle);
	T angleSin = std::sin(angle);
	x = x * angleCos - y * angleSin;
	y = x * angleSin + y * angleCos;
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::rotateAround(const Vec2<F32>& point, const F32 angle) {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + Direction(point, *this).rotate(angle)));
}

template<typename T>
Vec2<F32>& Vec2<T>::rotateAround(const Vec2<F32>& point, const F32 angle, const F32 distance) {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	return (*this = (point + (Direction(point, *this).normalize() * distance).rotate(angle)));
}

template<typename T>
Vec2<T> Vec2<T>::perpendicularVector() const {
	return Vec2<T>(x, -y);
}

template<typename T>
Vec2<T>& Vec2<T>::abs() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	x = std::abs(x);
	y = std::abs(y);
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::sign() const {
	if constexpr(std::is_signed_v<T>) {
		U32 xTemp = (*reinterpret_cast<U32*>(&static_cast<F32>(x)) & (1 << 31)) | (1 << 30);
		U32 yTemp = (*reinterpret_cast<U32*>(&static_cast<F32>(y)) & (1 << 31)) | (1 << 30);
		return Vec2<T>(static_cast<T>(*reinterpret_cast<F32*>(&xTemp) * 0.5f),
			static_cast<T>(*reinterpret_cast<F32*>(&yTemp) * 0.5f));
	}
	else
		return static_cast<T>(1);
}

template<typename T>
Vec2<F32>& Vec2<T>::ceil() {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	x = std::ceil(x);
	y = std::ceil(y);
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::floor() {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	x = std::floor(x);
	y = std::floor(y);
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::round() {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	x = std::round(x);
	y = std::round(y);
	return *this;
}

template<typename T>
Vec2<F32>& Vec2<T>::sqrt() {
	static_assert(!Vec2<T>::isIntegral, DK_MATH_ERROR2(T));
	x = std::sqrt(x);
	y = std::sqrt(y);
	return *this;
}

template<typename T>
Vec2<T> Vec2<T>::yx() const {
	return Vec2<T>(y, x);
}

template<typename T>
Vec2<T> Vec2<T>::Null() {
	return Vec2<T>();
}

template<typename T>
Vec2<T> Vec2<T>::Up() {
	return Vec2<T>(static_cast<T>(0), static_cast<T>(1));
}

template<typename T>
Vec2<T> Vec2<T>::Right() {
	return Vec2<T>(static_cast<T>(1), static_cast<T>(0));
}

template<typename T>
template<typename U>
Vec2<U> Vec2<T>::cast() const {
	static_assert(std::is_scalar_v<U>, DK_MATH_ERROR0(U));
	return Vec2<U>(static_cast<U>(x), static_cast<U>(y));
}

template<typename T>
bool operator==(const Vec2<T>& v1, const Vec2<T>& v2) {
	return IsEqual_V<T>(v1.x, v2.x) && IsEqual_V<T>(v1.y, v2.y);
}

template<typename T>
bool operator!=(const Vec2<T>& v1, const Vec2<T>& v2) {
	return IsNotEqual_V<T>(v1.x, v2.x) && IsNotEqual_V<T>(v1.y, v2.y);
}

template<typename T>
bool operator>(const Vec2<T>& v1, const Vec2<T>& v2) {
	return !(v1.x < v2.x && v1.y < v2.y);
}

template<typename T>
bool operator<(const Vec2<T>& v1, const Vec2<T>& v2) {
	return !(v1.x > v2.x && v1.y > v2.y);
}

template<typename T>
bool operator>=(const Vec2<T>& v1, const Vec2<T>& v2) {
	return !(v1.x <= v2.x && v1.y <= v2.y);
}

template<typename T>
bool operator<=(const Vec2<T>& v1, const Vec2<T>& v2) {
	return !(v1.x >= v2.x && v1.y >= v2.y);
}

template<typename T>
Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Vec2<T>(v1.x + v2.x, v1.y + v2.y);
}

template<typename T>
Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Vec2<T>(v1.x - v2.x, v1.y - v2.y);
}

template<typename T>
Vec2<T> operator*(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Vec2<T>(v1.x * v2.x, v1.y * v2.y);
}

template<typename T>
Vec2<T> operator/(const Vec2<T>& v1, const Vec2<T>& v2) {
	if (!v2.isNull())
		return Vec2<T>(v1.x / v2.x, v1.y / v2.y);
	else
		return Vec2<T>(v1.x, v1.y);
}

template<typename T>
Vec2<T> operator>>(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2) {
	return Vec2<T>(v1.x >> v2.x, v1.y >> v2.y);
}

template<typename T>
Vec2<T> operator<<(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2) {
	return Vec2<T>(v1.x << v2.x, v1.y << v2.y);
}

template<typename T>
Vec2<T> operator&(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2) {
	return Vec2<T>(v1.x & v2.x, v1.y & v2.y);
}

template<typename T>
Vec2<T> operator^(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2) {
	return Vec2<T>(v1.x ^ v2.x, v1.y ^ v2.y);
}

template<typename T>
Vec2<T> operator|(const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)& v2) {
	return Vec2<T>(v1.x | v2.x, v1.y | v2.y);
}

template<typename T>
Vec2<T>& operator+=(Vec2<T>& v1, const Vec2<T>& v2) {
	v1.x += v2.x;
	v1.y += v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator-=(Vec2<T>& v1, const Vec2<T>& v2) {
	v1.x -= v2.x;
	v1.y -= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator*=(Vec2<T>& v1, const Vec2<T>& v2) {
	v1.x *= v2.x;
	v1.y *= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator/=(Vec2<T>& v1, const Vec2<T>& v2) {
	if (!v2.isNull()) {
		v1.x /= v2.x;
		v1.y /= v2.y;
	}
	return v1;
}

template<typename T>
Vec2<T>& operator>>=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v1, const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v2) {
	v1.x >>= v2.x;
	v1.y >>= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator<<=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v1, const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v2) {
	v1.x <<= v2.x;
	v1.y <<= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator&=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v1, const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v2) {
	v1.x &= v2.x;
	v1.y &= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator^=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v1, const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v2) {
	v1.x ^= v2.x;
	v1.y ^= v2.y;
	return v1;
}

template<typename T>
Vec2<T>& operator|=(ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v1, const ENABLE_IF_ELSE_T(Vec2<T>::isIntegral, Vec2<T>, NOT_A_TYPE)&v2) {
	v1.x |= v2.x;
	v1.y |= v2.y;
	return v1;
}

template<typename T>
T Dot(const Vec2<T>& v1, const Vec2<T>& v2) {
	return (v1.x * v2.x + v1.y * v2.y);
}

template<typename T>
T Cross(const Vec2<T>& v1, const Vec2<T>& v2) {
	return (v1.x * v2.y) - (v1.y * v2.x);
}

template<typename T>
Vec2<T> Normalize(const Vec2<T>& v) {
	F32 size = v.magnitude();
	if (IsNotEqual_V(size, static_cast<T>(0)))
		return v / size;
	return v;
}

template<typename T>
Vec2<T> Negate(const Vec2<T>& v) {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec2<T>(-v.x, -v.y);
}

template<typename T>
Vec2<T> Abs(const Vec2<T>& v) {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec2<T>(std::abs(v.x), std::abs(v.y));
}

Vec2f Rotate(const Vec2f& v, F32 angle) {
	angle *= ToRadF;
	F32 angleCos = std::cos(angle);
	F32 angleSin = std::sin(angle);
	return Vec2f(v.x * angleCos - v.y * angleSin, v.x * angleSin + v.y * angleCos);
}

Vec2f Ceil(const Vec2f& v) {
	return Vec2f(std::ceil(v.x), std::ceil(v.y));
}

Vec2f Floor(const Vec2f& v) {
	return Vec2f(std::floor(v.x), std::floor(v.y));
}

Vec2f Round(const Vec2f& v) {
	return Vec2f(std::round(v.x), std::round(v.y));
}

Vec2f Sqrt(const Vec2f& v) {
	return Vec2f(std::sqrt(v.x), std::sqrt(v.y));
}

template<typename T>
F32 Distance(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Direction(v1, v2).magnitude();
}

template<typename T>
Vec2<T> Direction(const Vec2<T>& origin, const Vec2<T>& destination) {
	return destination - origin;
}

template<typename T>
Vec2<T> Min(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Vec2<T>(v1.x < v2.x ? v1.x : v2.x, v1.y < v2.y ? v1.y : v2.y);
}

template<typename T>
Vec2<T> Max(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Vec2<T>(v1.x > v2.x ? v1.x : v2.x, v1.y > v2.y ? v1.y : v2.y);
}

Vec2f RotateAround(const Vec2f& v, const Vec2f& point, const F32 angle) {
	return (point + Direction(point, v).rotate(angle));
}

Vec2f RotateAround(const Vec2f & v, const Vec2f & point, const F32 angle, const F32 distance) {
	return (point + (Direction(point, v).normalize() * distance).rotate(angle));
}

Vec2f Lerp(const Vec2f& start, const Vec2f& end, F32 percent) {
	return Vec2f(start + Direction(start, end) * percent);
}

Vec2f SLerp(const Vec2f& start, const Vec2f& end, F32 percent) {
	F32 dot = Dot(Normalize(start), Normalize(end));
	F32 theta = acos(dot) * percent;
	return Vec2f(start * cos(theta) + (Direction(start, end) * dot).normalize() * sin(theta));
}

Vec2f NLerp(const Vec2f& start, const Vec2f& end, F32 percent) {
	return Lerp(start, end, percent).normalize();
}

template<typename T>
bool ArePerpendicular(const Vec2<T>& v1, const Vec2<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(0));
}

template<typename T>
bool AreColinear(const Vec2<T>& v1, const Vec2<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(1));
}

template<typename T>
bool AreOpposed(const Vec2<T>& v1, const Vec2<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(-1));
}

template<typename T>
bool AreSameDirection(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Dot(v1, v2) > static_cast<T>(0);
}

template<typename T>
bool AreOpposedDirection(const Vec2<T>& v1, const Vec2<T>& v2) {
	return Dot(v1, v2) < static_cast<T>(0);
}

template<typename T, AngleUnit unit>
F32 Angle(const Vec2<T>& va, const Vec2<T>& vb) {
	if constexpr (unit == AngleUnit::RADIANS)
		return acos(Dot(Normalize(va), Normalize(vb)));
	else
		return acos(Dot(Normalize(va), Normalize(vb))) * ToDegF;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec2<T>& v) {
	o << "{ x : " << std::to_string(v.x) << ", y : " << std::to_string(v.y) << " }";
	return o;
}

} //namespace math
} //namespace drak