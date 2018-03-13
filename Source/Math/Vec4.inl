#pragma warning(disable : 4799)
#include<cassert>
#include<Math/Vec4.hpp>

namespace drak {
namespace math {

template<typename T>
constexpr bool Vec4<T>::isIntegral;

template<typename T>
Vec4<T>::Vec4() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, static_cast<T>(0));
	else
		memset(m_vec, 0, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(T* arr) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		if constexpr (alignof(T*) == SIMDType::alignement)
			m_simdVec = SIMDStruct::load(arr);
		else
			m_simdVec = SIMDStruct::loadu(arr);
	}
	else
		memcpy(m_vec, arr, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(const T X, const T Y, const T Z, const T W) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, X, Y, Z, W);
	else {
		x = X;
		y = Y;
		z = Z;
		w = W;
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(const SIMDType& ss) {
	m_simdVec = ss;
	if constexpr(std::is_same_v<T, I16>)
		_m_empty();
}

template<typename T>
Vec4<T>::Vec4(const Vec2<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, static_cast<T>(0), static_cast<T>(0));
	else {
		x = v.x;
		y = v.y;
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(Vec2<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, std::forward<Vec2<T>>(v).x, std::forward<Vec2<T>>(v).y,
			static_cast<T>(0), static_cast<T>(0));
	else {
		x = std::forward<Vec2<T>>(v).x;
		y = std::forward<Vec2<T>>(v).y;
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec2<T>& v1, const Vec2<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v1.x, v1.y, v2.x, v2.y);
	else {
		x = v1.x;
		y = v1.y;
		z = v2.x;
		w = v2.y;
	}
}

template<typename T>
Vec4<T>::Vec4(Vec2<T>&& v1, Vec2<T>&& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, std::forward<Vec2<T>>(v1).x, std::forward<Vec2<T>>(v1).y,
			std::forward<Vec2<T>>(v2).x, std::forward<Vec2<T>>(v2).y);
	else {
		x = std::forward<Vec2<T>>(v1).x;
		y = std::forward<Vec2<T>>(v1).y;
		z = std::forward<Vec2<T>>(v2).x;
		w = std::forward<Vec2<T>>(v2).y;
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec3<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, static_cast<T>(0));
	else {
		x = v.x;
		y = v.y;
		z = v.z;
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(Vec3<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, std::forward<Vec3<T>>(v).x,
			std::forward<Vec3<T>>(v).y, std::forward<Vec3<T>>(v).z, static_cast<T>(0));
	else {
		x = std::forward<Vec3<T>>(v).x;
		y = std::forward<Vec3<T>>(v).y;
		z = std::forward<Vec3<T>>(v).z;
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec3<T>& v, T W) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, W);
	else {
		x = v.x;
		y = v.y;
		z = v.z;
		w = W;
	}
}

template<typename T>
Vec4<T>::Vec4(Vec3<T>&& v, T W) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, std::forward<Vec3<T>>(v).x,
			std::forward<Vec3<T>>(v).y, std::forward<Vec3<T>>(v).z, W);
	else {
		x = std::forward<Vec3<T>>(v).x;
		y = std::forward<Vec3<T>>(v).y;
		z = std::forward<Vec3<T>>(v).z;
		w = W;
	}
}

template<typename T>
bool Vec4<T>::operator==(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::areEqual(m_simdVec, v.m_simdVec);
	else
		return x == v.x && y == v.y && z == v.z && w == v.w;
}
template<typename T>
bool Vec4<T>::operator!=(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::areEqual(m_simdVec, v.m_simdVec);
	else
		return !(x == v.x && y == v.y && z == v.z && w == v.w);
}

template<typename T>
bool Vec4<T>::operator>(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterThan(v.m_simdVec, m_simdVec);
	else
		return !(x < v.x && y < v.y && z < v.z && w < v.w);
}

template<typename T>
bool Vec4<T>::operator<(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterThan(m_simdVec, v.m_simdVec);
	else
		return !(x > v.x && y > v.y && z > v.z && w > v.w)
}

template<typename T>
bool Vec4<T>::operator>=(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterOrEqThan(v.m_simdVec, m_simdVec);
	else
		return !(x <= v.x && y <= v.y && z <= v.z && w <= v.w)
}

template<typename T>
bool Vec4<T>::operator<=(const Vec4<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterOrEqThan(m_simdVec, v.m_simdVec);
	else
		return !(x >= v.x && y >= v.y && z >= v.z && w >= v.w)
}

template<typename T>
bool Vec4<T>::isNormalized() const {
	return types::IsEqual_V<F32>(magnitude(), 1.0f);
}

template<typename T>
bool Vec4<T>::isNull() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::isAllZeros(m_simdVec);
	else
		return IsEqual_V<T>(x, static_cast<T>(0)) &&
		IsEqual_V<T>(y, static_cast<T>(0)) &&
		IsEqual_V<T>(z, static_cast<T>(0)) &&
		IsEqual_V<T>(w, static_cast<T>(0));
}

template<typename T>
F32 Vec4<T>::magnitude() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return std::sqrt(static_cast<F32>(SIMDStruct::horizontalAdd((*this * *this).m_simdVec)));
	else
		return std::sqrt(static_cast<F32>(x * x + y * y + z * z + w * w));
}

template<typename T>
Vec4<T>& Vec4<T>::operator=(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::load(v.m_vec);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator=(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::load(std::forward<Vec4<T>>(v).m_vec);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else
		memcpy(m_vec, std::forward<Vec4<T>>(v).m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator+=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::add(m_simdVec, n);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else {
		x += n;
		y += n;
		z += n;
		w += n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator-=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::sub(m_simdVec, n);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else {
		x -= n;
		y -= n;
		z -= n;
		w -= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator*=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::mul(m_simdVec, n);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else {
		x *= n;
		y *= n;
		z *= n;
		w *= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator/=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::div(m_simdVec, n);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else {
		assert(!IsNotEqual_V<T>(n, static_cast<T>(0)));
		if (IsNotEqual_V<T>(n, static_cast<T>(0))) {
			x /= n;
			y /= n;
			z /= n;
			w /= n;
		}
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::rShift(m_simdVec, n);
	else {
		x >>= n;
		y >>= n;
		z >>= n;
		w >>= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::lShift(m_simdVec, n);
	else {
		x <<= n;
		y <<= n;
		z <<= n;
		w <<= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator&=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::andOp(m_simdVec, n);
	else {
		x &= n;
		y &= n;
		z &= n;
		w &= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator^=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::xorOp(m_simdVec, n);
	else {
		x ^= n;
		y ^= n;
		z ^= n;
		w ^= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator|=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::orOp(m_simdVec, n);
	else {
		x |= n;
		y |= n;
		z |= n;
		w |= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator++() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, 1);
	else {
		++x;
		++y;
		++z;
		++w;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator--() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, 1);
	else {
		--x;
		--y;
		--z;
		--w;
	}
	return *this;
}

template<typename T>
Vec4<T> Vec4<T>::operator+(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::add(m_simdVec, n));
	else
		return Vec4<T>(x + n, y + n, z + n, w + n);
}

template<typename T>
Vec4<T> Vec4<T>::operator-(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::sub(m_simdVec, n));
	else
		return Vec4<T>(x - n, y - n, z - n, w - n);
}

template<typename T>
Vec4<T> Vec4<T>::operator*(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::mul(m_simdVec, n));
	else
		return Vec4<T>(x * n, y * n, z * n, w * n);
}

template<typename T>
Vec4<T> Vec4<T>::operator/(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::div(m_simdVec, n));
	else {
		assert(IsNotEqual_V<T>(n, static_cast<T>(0)));
		if (IsNotEqual_V<T>(n, static_cast<T>(0)))
			return Vec4<T>(x / n, y / n, z / n, w / n);
	}
}

template<typename T>
Vec4<T> Vec4<T>::operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::rShift(m_simdVec, n));
	else
		return Vec4<T>(x >> n, y >> n, z >> n, w >> n);
}

template<typename T>
Vec4<T> Vec4<T>::operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::lShift(m_simdVec, n));
	else
		return Vec4<T>(x << n, y << n, z << n, w << n);
}

template<typename T>
Vec4<T> Vec4<T>::operator&(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::andOp(m_simdVec, n));
	else
		return Vec4<T>(x & n, y & n, z & n, w & n);
}

template<typename T>
Vec4<T> Vec4<T>::operator^(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::xorOp(m_simdVec, n));
	else
		return Vec4<T>(x ^ n, y ^ n, z ^ n, w ^ n);
}

template<typename T>
Vec4<T> Vec4<T>::operator|(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::orOp(m_simdVec, n));
	else
		return Vec4<T>(x | n, y | n, z | n, w | n);
}

template<typename T>
Vec4<T> Vec4<T>::operator++(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::add(m_simdVec, 1));
	else
		return Vec4<T>(x++, y++, z++, w++);
}

template<typename T>
Vec4<T> Vec4<T>::operator--(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::sub(m_simdVec, 1));
	else
		return Vec4<T>(x--, y--, z--, w--);
}

template<typename T>
Vec4<T> Vec4<T>::operator-() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec4<T>(-x, -y, -z, -w);
}

template<typename T>
Vec4<T> Vec4<T>::conjugate() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec4<T>(-x, -y, -z, -w);
}

template<typename T>
Vec4<T> Vec4<T>::normalize() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::div(m_simdVec, magnitude()));
	else {
		F32 size = magnitude();
		assert(IsNotEqual_V(size, static_cast<T>(0)));
		if (IsNotEqual_V(size, static_cast<T>(0)))
				return *this / size;
		return Vec4<T>(x, y, z, w);
	}
}

template<>
Vec4<F32> Vec4<F32>::ceil() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<F32>(SIMDStruct::ceil(m_simdVec));
	else {
		Vec4<F32>(std::ceil(x), std::ceil(y),
			std::ceil(z), std::ceil(w));
	}
}

template<>
Vec4<F32> Vec4<F32>::floor() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<F32>(SIMDStruct::floor(m_simdVec));
	else {
		Vec4<F32>(std::floor(x), std::floor(y), std::floor(z), std::floor(w));
	}
}

template<>
Vec4<F32> Vec4<F32>::round() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<F32>(SIMDStruct::round(m_simdVec));
	else {
		Vec4<F32>(std::round(x), std::round(y), std::round(z), std::round(w));
	}
}

template<typename T>
Vec3<T> Vec4<T>::xyz() {
	return Vec3<T>(x, y, z);
}

template<typename T>
Vec3<T> Vec4<T>::zyx() {
	return Vec3<T>(z, y, x);
}

template<typename T>
Vec3<T> Vec4<T>::yzx() {
	return Vec3<T>(y, z, x);
}

template<typename T>
Vec3<T> Vec4<T>::zxy() {
	return Vec3<T>(z, x, y);
}

template<typename T>
Vec3<T> Vec4<T>::rgb() {
	return Vec3<T>(r, g, b);
}

template<typename T>
Vec3<T> Vec4<T>::bgr() {
	return Vec3<T>(b, g, r);
}

template<typename T>
Vec3<T> Vec4<T>::gbr() {
	return Vec3<T>(g, b, r);
}

template<typename T>
Vec3<T> Vec4<T>::brg() {
	return Vec3<T>(b, r, g);
}

template<typename T>
Vec3<T> Vec4<T>::wyz() {
	return Vec3<T>(w, y, z);
}

template<typename T>
Vec3<T> Vec4<T>::zyw() {
	return Vec3<T>(z, y, w);
}

template<typename T>
Vec3<T> Vec4<T>::yzw() {
	return Vec3<T>(y, z, w);
}

template<typename T>
Vec3<T> Vec4<T>::zwy() {
	return Vec3<T>(z, w, y);
}

template<typename T>
Vec4<T> Vec4<T>::bgra() {
	return Vec4<T>(b, r, g, a);
}

template<typename T>
Vec4<T> Vec4<T>::gbra() {
	return Vec4<T>(g, b, r, a);
}

template<typename T>
Vec4<T> Vec4<T>::brga() {
	return Vec4<T>(b, r, g, a);
}

template<typename T>
template<typename U>
Vec4<U> Vec4<T>::cast() const {
	return Vec4<U>(static_cast<U>(x), static_cast<U>(y),
		static_cast<U>(z), static_cast<U>(w));
}

template<typename T>
Vec4<T> operator+(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::add(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

template<typename T>
Vec4<T> operator-(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::sub(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

template<typename T>
Vec4<T> operator*(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::mul(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

template<typename T>
Vec4<T> operator/(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::div(v1.m_simdVec, v2.m_simdVec));
	else {
		assert(!v2.isNull());
		if (!v2.isNull())
			return Vec4<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
	}
}

template<typename T>
Vec4<T> operator>>(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::rShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z, v1.w >> v2.w);
}
template<typename T>
Vec4<T> operator<<(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::lShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z, v1.w << v2.w);
}
template<typename T>
Vec4<T> operator&(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::andOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z, v1.w & v2.w);
}
template<typename T>
Vec4<T> operator^(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::xorOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z, v1.w ^ v2.w);
}
template<typename T>
Vec4<T> operator|(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::orOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z, v1.w | v2.w);
}

template<typename T>
Vec4<T>& operator+=(Vec4<T>& v1, const Vec4<T>& v2) {
	return v1 = v1 + v2;
}

template<typename T>
Vec4<T>& operator-=(Vec4<T>& v1, const Vec4<T>& v2) {
	return v1 = v1 - v2;
}

template<typename T>
Vec4<T>& operator*=(Vec4<T>& v1, const Vec4<T>& v2) {
	return v1 = v1 * v2;
}

template<typename T>
Vec4<T>& operator/=(Vec4<T>& v1, const Vec4<T>& v2) {
	return v1 = v1 / v2;
}

template<typename T>
Vec4<T>& operator>>=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 >> v2;
}
template<typename T>
Vec4<T>& operator<<=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 << v2;
}
template<typename T>
Vec4<T>& operator&=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 & v2;
}
template<typename T>
Vec4<T>& operator^=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 ^ v2;
}
template<typename T>
Vec4<T>& operator|=(ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 | v2;
}

template<typename T>
T Dot(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>::SIMDStruct::horizontalAdd((v1 * v2).m_simdVec);
	else
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

template<typename T>
Vec4<T> Cross(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::cross(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x, static_cast<T>(0));
}

template<typename T>
F32 Distance(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Direction(v1, v2).magnitude();
}

template<typename T>
Vec4<T> Direction(const Vec4<T>& origin, const Vec4<T>& destination) {
	return Vec4<T>(destination - origin);
}

template<typename T>
Vec4<T> Min(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Vec4<T>::SIMDStruct::min(v1, v2);
}

template<typename T>
Vec4<T> Max(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Vec4<T>::SIMDStruct::max(v1, v2);
}

template<typename T>
bool ArePerpendicular(const Vec4<T>& v1, const Vec4<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(0));
}

template<typename T>
bool AreColinear(const Vec4<T>& v1, const Vec4<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(1));
}

template<typename T>
bool AreOpposed(const Vec4<T>& v1, const Vec4<T>& v2) {
	return types::IsEqual_V<T>(Dot(v1, v2), static_cast<T>(-1));
}

template<typename T>
bool AreSameDirection(const Vec4<T>& v1, const Vec4<T>& v2) {
	return  Dot(v1, v2) > static_cast<T>(0);
}

template<typename T>
bool AreOpposedDirection(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Dot(v1, v2) < static_cast<T>(0);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec4<T>& v) {
	return o << "{ x : " << v.x << ", y :" << v.y << ", z :" << v.z << ", w :" << v.w << " }";
}

} //namespace math 
} //namespace drak