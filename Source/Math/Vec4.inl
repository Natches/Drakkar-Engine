#include "Vec4.hpp"

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
		memcpy_inline(m_vec, arr, sizeof(m_vec));
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
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(const SIMDType& ss) {
	m_simdVec = ss;
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
		return types::IsEqual_V<T>(x, static_cast<T>(0)) &&
		types::IsEqual_V<T>(y, static_cast<T>(0)) &&
		types::IsEqual_V<T>(z, static_cast<T>(0)) &&
		types::IsEqual_V<T>(w, static_cast<T>(0));
}

template<typename T>
F32 Vec4<T>::magnitude() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return std::sqrt(SIMDStruct::horizontalAdd(*this * *this));
	else
		return std::sqrt<F32>(x * x + y * y + z * z + w * w);
}

template<typename T>
Vec4<T>& Vec4<T>::operator=(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator=(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(std::forward<Vec4<T>>(v).m_vec);
	else
		memcpy_inline(m_vec, std::forward<Vec4<T>>(v).m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator+=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, n);
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
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, n);
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
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::mul(m_simdVec, n);
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
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::div(m_simdVec, n);
	else {
		assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
		if (types::IsNotEqual_V<T>(n, static_cast<T>(0))) {
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
		assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
		if (types::IsNotEqual_V<T>(n, static_cast<T>(0)))
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
		assert(types::IsEqual_V(size, static_cast<T>(0)))
			if (types::IsNotEqual_V(size, static_cast<T>(0)))
				return *this / size;
		return *this;
	}
}

template<typename T>
Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)> Vec4<T>::ceil() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(SIMDStruct::ceil(m_simdVec));
	else {
		Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(std::ceil(x), std::ceil(y),
			std::ceil(z), std::ceil(w));
	}
}

template<typename T>
Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)> Vec4<T>::floor() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(SIMDStruct::floor(m_simdVec));
	else {
		Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(std::floor(x), std::floor(y),
			std::floor(z), std::floor(w));
	}
}

template<typename T>
Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)> Vec4<T>::round() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(SIMDStruct::round(m_simdVec));
	else {
		Vec4<ENABLE_IF_ELSE_T(!Vec4<T>::isIntegral, T, NOT_A_TYPE)>(std::round(x), std::round(y),
			std::round(z), std::round(w));
	}
}

template<typename T>
template<typename U>
Vec4<U> Vec4<T>::cast() const {
	return Vec4<U>(static_cast<U>(x), static_cast<U>(y),
		static_cast<U>(z), static_cast<U>(w));
}

template<typename T>
Vec4<T> operator+(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::add(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

template<typename T>
Vec4<T> operator-(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::sub(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

template<typename T>
Vec4<T> operator*(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::mul(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

template<typename T>
Vec4<T> operator/(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::div(v1.m_simdVec, v2.m_simdVec));
	else {
		assert(v2.isNull());
		if (!v2.isNull())
			return Vec4<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
	}
}

template<typename T>
Vec4<T> operator>>(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::rShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z, v1.w >> v2.w);
}
template<typename T>
Vec4<T> operator<<(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::lShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z, v1.w << v2.w);
}
template<typename T>
Vec4<T> operator&(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::andOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z, v1.w & v2.w);
}
template<typename T>
Vec4<T> operator^(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::xorOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z, v1.w ^ v2.w);
}
template<typename T>
Vec4<T> operator|(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::orOp(v1.m_simdVec, v2.m_simdVec));
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
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::horizontalAdd(v1 * v2);
	else
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

template<typename T>
Vec4<T> Cross(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::cross(v1, v2));
	else
		return Vec4<T>(v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x, static_cast<T>(0));
}

template<typename T>
F32 Distance(const Vec4<T>& v1, const Vec4<T>& v2) {
	return magnitude(v1 - v2);
}

template<typename T>
Vec4<T> Direction(const Vec4<T>& origin, const Vec4<T>& destination) {
	return Vec4<T>(destination - origin);
}

template<typename T>
Vec4<T> Min(const Vec4<T>& v1, const Vec4<T>& v2) {
	return SIMDStruct::min(v1, v2);
}

template<typename T>
Vec4<T> Max(const Vec4<T>& v1, const Vec4<T>& v2) {
	return SIMDStruct::max(v1, v2);
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


} //namespace math 
} //namespace drak
