#include<cassert>
#include<Math/Vec8.hpp>

namespace drak {
namespace math {

template<typename T>
constexpr bool Vec8<T>::isIntegral;

template<typename T>
Vec8<T>::Vec8() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, static_cast<T>(0));
	else
		memset(m_vec, 0, sizeof(m_vec));
}

template<typename T>
Vec8<T>::Vec8(T* arr) {
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
Vec8<T>::Vec8(const T X, const T Y, const T Z, const T W,
	const T A, const T B, const T C, const T D) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, X, Y, Z, W, A, B, C, D);
	else {
		x = X;
		y = Y;
		z = Z;
		w = W;
		a = A;
		b = B;
		c = C;
		d = D;
	}
}

template<typename T>
Vec8<T>::Vec8(const Vec8<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec8<T>::Vec8(Vec8<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec8<T>::Vec8(const SIMDType& ss) {
	m_simdVec = ss;
}

template<typename T>
bool Vec8<T>::operator==(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::areEqual(m_simdVec, v.m_simdVec);
	else
		return x == v.x && y == v.y && z == v.z && w == v.w &&
		a == v.a && b == v.b && c == v.c && d == v.d;
}
template<typename T>
bool Vec8<T>::operator!=(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::areEqual(m_simdVec, v.m_simdVec);
	else
		return !(x == v.x && y == v.y && z == v.z && w == v.w &&
			a == v.a && b == v.b && c == v.c && d == v.d);
}

template<typename T>
bool Vec8<T>::operator>(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterThan(v.m_simdVec, m_simdVec);
	else
		return !(x < v.x && y < v.y && z < v.z && w < v.w &&
			a < v.a && b < v.b && c < v.c && d < v.d);
}

template<typename T>
bool Vec8<T>::operator<(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterThan(m_simdVec, v.m_simdVec);
	else
		return !(x > v.x && y > v.y && z > v.z && w > v.w &&
			a > v.a && b > v.b && c > v.c && d > v.d)
}

template<typename T>
bool Vec8<T>::operator>=(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterOrEqThan(v.m_simdVec, m_simdVec);
	else
		return !(x <= v.x && y <= v.y && z <= v.z && w <= v.w &&
			a <= v.a && b <= v.b && c <= v.c && d <= v.d);
}

template<typename T>
bool Vec8<T>::operator<=(const Vec8<T>& v) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !SIMDStruct::isGreaterOrEqThan(m_simdVec, v.m_simdVec);
	else
		return !(x >= v.x && y >= v.y && z >= v.z && w >= v.w &&
			a >= v.a && b >= v.b && c >= v.c && d >= v.d);
}

template<typename T>
bool Vec8<T>::isNormalized() const {
	return types::IsEqual_V<F32>(magnitude(), 1.0f);
}

template<typename T>
bool Vec8<T>::isNull() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::isAllZeros(m_simdVec);
	else
		return types::IsEqual_V<T>(x, static_cast<T>(0)) &&
		types::IsEqual_V<T>(y, static_cast<T>(0)) &&
		types::IsEqual_V<T>(z, static_cast<T>(0)) &&
		types::IsEqual_V<T>(w, static_cast<T>(0)) &&
		types::IsEqual_V<T>(a, static_cast<T>(0)) &&
		types::IsEqual_V<T>(b, static_cast<T>(0)) &&
		types::IsEqual_V<T>(c, static_cast<T>(0)) &&
		types::IsEqual_V<T>(d, static_cast<T>(0));
}

template<typename T>
F32 Vec8<T>::magnitude() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return std::sqrt(SIMDStruct::horizontalAdd(*this * *this));
	else
		return std::sqrt<F32>(x * x + y * y + z * z + w * w + a * a + b * b + c * c + d * d);
}

template<typename T>
Vec8<T>& Vec8<T>::operator=(const Vec8<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(v.m_vec);
	else
		memcpy_inline(m_vec, v.m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator=(Vec8<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::load(std::forward<Vec8<T>>(v).m_vec);
	else
		memcpy_inline(m_vec, std::forward<Vec8<T>>(v).m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator+=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, n);
	else {
		x += n;
		y += n;
		z += n;
		w += n;
		a += n;
		b += n;
		c += n;
		d += n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator-=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, n);
	else {
		x -= n;
		y -= n;
		z -= n;
		w -= n;
		a -= n;
		b -= n;
		c -= n;
		d -= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator*=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::mul(m_simdVec, n);
	else {
		x *= n;
		y *= n;
		z *= n;
		w *= n;
		a *= n;
		b *= n;
		c *= n;
		d *= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator/=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::div(m_simdVec, n);
	else {
		assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
		if (types::IsNotEqual_V<T>(n, static_cast<T>(0))) {
			x /= n;
			y /= n;
			z /= n;
			w /= n;
			a /= n;
			b /= n;
			c /= n;
			d /= n;
		}
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::rShift(m_simdVec, n);
	else {
		x >>= n;
		y >>= n;
		z >>= n;
		w >>= n;
		a >>= n;
		b >>= n;
		c >>= n;
		d >>= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::lShift(m_simdVec, n);
	else {
		x <<= n;
		y <<= n;
		z <<= n;
		w <<= n;
		a <<= n;
		b <<= n;
		c <<= n;
		d <<= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator&=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::andOp(m_simdVec, n);
	else {
		x &= n;
		y &= n;
		z &= n;
		w &= n;
		a &= n;
		b &= n;
		c &= n;
		d &= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator^=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::xorOp(m_simdVec, n);
	else {
		x ^= n;
		y ^= n;
		z ^= n;
		w ^= n;
		a ^= n;
		b ^= n;
		c ^= n;
		d ^= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator|=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::orOp(m_simdVec, n);
	else {
		x |= n;
		y |= n;
		z |= n;
		w |= n;
		a |= n;
		b |= n;
		c |= n;
		d |= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator++() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, 1);
	else {
		++x;
		++y;
		++z;
		++w;
		++a;
		++b;
		++c;
		++d;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator--() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, 1);
	else {
		--x;
		--y;
		--z;
		--w;
		--a;
		--b;
		--c;
		--d;
	}
	return *this;
}

template<typename T>
Vec8<T> Vec8<T>::operator+(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::add(m_simdVec, n));
	else
		return Vec8<T>(x + n, y + n, z + n, w + n,
			a + n, b + n, c + n, d + n);
}

template<typename T>
Vec8<T> Vec8<T>::operator-(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::sub(m_simdVec, n));
	else
		return Vec8<T>(x - n, y - n, z - n, w - n,
			a - n, b - n, c - n, d - n);
}

template<typename T>
Vec8<T> Vec8<T>::operator*(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::mul(m_simdVec, n));
	else
		return Vec8<T>(x * n, y * n, z * n, w * n,
			a * n, b * n, c * n, d * n);
}

template<typename T>
Vec8<T> Vec8<T>::operator/(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::div(m_simdVec, n));
	else {
		assert(types::IsEqual_V<T>(n, static_cast<T>(0)));
		if (types::IsNotEqual_V<T>(n, static_cast<T>(0)))
			return Vec8<T>(x / n, y / n, z / n, w / n,
				a / n, b / n, c / n, d / n);
	}
}

template<typename T>
Vec8<T> Vec8<T>::operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::rShift(m_simdVec, n));
	else
		return Vec8<T>(x >> n, y >> n, z >> n, w >> n,
			a >> n, b >> n, c >> n, d >> n);
}

template<typename T>
Vec8<T> Vec8<T>::operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::lShift(m_simdVec, n));
	else
		return Vec8<T>(x << n, y << n, z << n, w << n,
			a << n, b << n, c << n, d << n);
}

template<typename T>
Vec8<T> Vec8<T>::operator&(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::andOp(m_simdVec, n));
	else
		return Vec8<T>(x & n, y & n, z & n, w & n,
			a & n, b & n, c & n, d & n);
}

template<typename T>
Vec8<T> Vec8<T>::operator^(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::xorOp(m_simdVec, n));
	else
		return Vec8<T>(x ^ n, y ^ n, z ^ n, w ^ n,
			a ^ n, b ^ n, c ^ n, d ^ n);
}

template<typename T>
Vec8<T> Vec8<T>::operator|(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::orOp(m_simdVec, n));
	else
		return Vec8<T>(x | n, y | n, z | n, w | n,
			a | n, b | n, c | n, d | n);
}

template<typename T>
Vec8<T> Vec8<T>::operator++(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::add(m_simdVec, 1));
	else
		return Vec8<T>(x++, y++, z++, w++,
			a++, b++, c++, d++);
}

template<typename T>
Vec8<T> Vec8<T>::operator--(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::sub(m_simdVec, 1));
	else
		return Vec8<T>(x--, y--, z--, w--,
			a--, b--, c--, d--);
}

template<typename T>
Vec8<T> Vec8<T>::operator-() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec8<T>(-x, -y, -z, -w,
			-a, -b, -c, -d);
}

template<typename T>
Vec8<T> Vec8<T>::conjugate() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec8<T>(-x, -y, -z, -w,
			-a, -b, -c, -d);
}

template<typename T>
Vec8<T> Vec8<T>::normalize() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::div(m_simdVec, magnitude()));
	else {
		F32 size = magnitude();
		assert(types::IsEqual_V(size, static_cast<T>(0)));
		if (types::IsNotEqual_V(size, static_cast<T>(0)))
			return *this / size;
		return Vec8<T>(*this);
	}
}

template<>
Vec8<F32> Vec8<F32>::ceil() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<F32>(SIMDStruct::ceil(m_simdVec));
	else {
		Vec8<F32>(std::ceil(x), std::ceil(y),
			std::ceil(z), std::ceil(w), std::ceil(a), std::ceil(b), std::ceil(c), std::ceil(d));
	}
}

template<>
Vec8<F32> Vec8<F32>::floor() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<F32>(SIMDStruct::floor(m_simdVec));
	else {
		Vec8<F32>(std::floor(x), std::floor(y),
			std::floor(z), std::floor(w), std::floor(a), std::floor(b), std::floor(c), std::floor(d));
	}
}

template<>
Vec8<F32> Vec8<F32>::round() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<F32>(SIMDStruct::round(m_simdVec));
	else {
		Vec8<F32>(std::round(x), std::round(y),
			std::round(z), std::round(w), std::round(a), std::round(b), std::round(c), std::round(d));
	}
}

template<typename T>
template<typename U>
Vec8<U> Vec8<T>::cast() const {
	return Vec8<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w),
		static_cast<U>(a), static_cast<U>(b), static_cast<U>(c), static_cast<U>(d));
}

template<typename T>
Vec8<T> operator+(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::add(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w,
			v1.a + v2.a, v1.b + v2.b, v1.c + v2.c, v1.d + v2.d);
}

template<typename T>
Vec8<T> operator-(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::sub(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w,
			v1.a - v2.a, v1.b - v2.b, v1.c - v2.c, v1.d - v2.d);
}

template<typename T>
Vec8<T> operator*(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::mul(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w,
			v1.a * v2.a, v1.b * v2.b, v1.c * v2.c, v1.d * v2.d);
}

template<typename T>
Vec8<T> operator/(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::div(v1.m_simdVec, v2.m_simdVec));
	else {
		assert(v2.isNull());
		if (!v2.isNull())
			return Vec8<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w,
				v1.a / v2.a, v1.b / v2.b, v1.c / v2.c, v1.d / v2.d);
	}
}

template<typename T>
Vec8<T> operator>>(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::rShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x >> v2.x, v1.y >> v2.y, v1.z >> v2.z, v1.w >> v2.w,
			v1.a >> v2.a, v1.b >> v2.b, v1.c >> v2.c, v1.d >> v2.d);
}
template<typename T>
Vec8<T> operator<<(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::lShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x << v2.x, v1.y << v2.y, v1.z << v2.z, v1.w << v2.w,
			v1.a << v2.a, v1.b << v2.b, v1.c << v2.c, v1.d << v2.d);
}
template<typename T>
Vec8<T> operator&(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::andOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x & v2.x, v1.y & v2.y, v1.z & v2.z, v1.w & v2.w,
			v1.a & v2.a, v1.b & v2.b, v1.c & v2.c, v1.d & v2.d);
}
template<typename T>
Vec8<T> operator^(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::xorOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x ^ v2.x, v1.y ^ v2.y, v1.z ^ v2.z, v1.w ^ v2.w,
			v1.a ^ v2.a, v1.b ^ v2.b, v1.c ^ v2.c, v1.d ^ v2.d);
}
template<typename T>
Vec8<T> operator|(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::orOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.x | v2.x, v1.y | v2.y, v1.z | v2.z, v1.w | v2.w,
			v1.a | v2.a, v1.b | v2.b, v1.c | v2.c, v1.d | v2.d);
}

template<typename T>
Vec8<T>& operator+=(Vec8<T>& v1, const Vec8<T>& v2) {
	return v1 = v1 + v2;
}

template<typename T>
Vec8<T>& operator-=(Vec8<T>& v1, const Vec8<T>& v2) {
	return v1 = v1 - v2;
}

template<typename T>
Vec8<T>& operator*=(Vec8<T>& v1, const Vec8<T>& v2) {
	return v1 = v1 * v2;
}

template<typename T>
Vec8<T>& operator/=(Vec8<T>& v1, const Vec8<T>& v2) {
	return v1 = v1 / v2;
}

template<typename T>
Vec8<T>& operator>>=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 >> v2;
}
template<typename T>
Vec8<T>& operator<<=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 << v2;
}
template<typename T>
Vec8<T>& operator&=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 & v2;
}
template<typename T>
Vec8<T>& operator^=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 ^ v2;
}
template<typename T>
Vec8<T>& operator|=(ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	return v1 = v1 | v2;
}

template<typename T>
Vec8<T> Min(const Vec8<T>& v1, const Vec8<T>& v2) {
	return Vec8<T>::SIMDStruct::min(v1, v2);
}

template<typename T>
Vec8<T> Max(const Vec8<T>& v1, const Vec8<T>& v2) {
	return Vec8<T>::SIMDStruct::max(v1, v2);
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec8<T>& v) {
	return o << " x : " << v.x << ", y :" << v.y << ", z :" << v.z << ", w :" << v.w <<
		" a : " << v.a << ", b :" << v.b << ", c :" << v.c << ", d :" << v.d;
}

} //namespace math 
} //namespace drak

