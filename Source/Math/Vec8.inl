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
Vec8<T>::Vec8(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, n);
	else {
		xyzw = Vec4<T>(n);
		abcd = Vec4<T>(n);
	}
}

template<typename T>
Vec8<T>::Vec8(T* arr) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		if constexpr (alignof(T*) == SIMDStruct::alignement)
			m_simdVec = SIMDStruct::load(arr);
		else
			m_simdVec = SIMDStruct::loadu(arr);
	}
	else
		memcpy(m_vec, arr, sizeof(m_vec));
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
		m_simdVec = v.m_simdVec;
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec8<T>::Vec8(Vec8<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = v.m_simdVec;
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec8<T>::Vec8(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.m_simdVec, static_cast<T>(0));
	else {
		xyzw = v;
		abcd = Vec4<T>(0);
	}
}

template<typename T>
Vec8<T>::Vec8(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.m_simdVec, static_cast<T>(0));
	else {
		xyzw = std::move(v);
		abcd = Vec4<T>(0);
	}
}

template<typename T>
Vec8<T>::Vec8(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v1.m_simdVec, v2.m_simdVec);
	else {
		xyzw = v1;
		abcd = v2;
	}
}

template<typename T>
Vec8<T>::Vec8(Vec4<T>&& v1, Vec4<T>&& v2) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v2.m_simdVec, v2.m_simdVec);
	else {
		xyzw = std::move(v1);
		abcd = std::move(v2);
	}
}

template<typename T>
Vec8<T>::Vec8(const SIMDType& ss) {
	m_simdVec = ss;
}

template<typename T>
Vec8<T> Vec8<T>::broadcast(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::broadcast(v.m_simdVec);
	else
		return { v, v };
}


template<typename T>
bool Vec8<T>::isNormalized() const {
	return IsEqual_V<F32>(magnitude(), 1.0f);
}

template<typename T>
bool Vec8<T>::isNull() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return SIMDStruct::isAllZeros(m_simdVec);
	else
		return xyzw.isNull() && abcd.isNull();
}

template<typename T>
F32 Vec8<T>::magnitude() const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return std::sqrt(SIMDStruct::horizontalAdd((*this * *this).m_simdVec));
	else
		return std::sqrt<F32>(Dot(xyzw, xyzw) + Dot(abcd, abcd));
}

template<typename T>
Vec8<T>& Vec8<T>::operator=(const Vec8<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = v.m_simdVec;
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator=(Vec8<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = v.m_simdVec;
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator+=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, n);
	else {
		xyzw += n;
		abcd += n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator-=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, n);
	else {
		xyzw -= n;
		abcd -= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator*=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::mul(m_simdVec, n);
	else {
		xyzw *= n;
		abcd *= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator/=(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::div(m_simdVec, n);
	else if (IsNotEqual_V<T>(n, static_cast<T>(0))) {
		x /= n;
		y /= n;
		z /= n;
		w /= n;
		a /= n;
		b /= n;
		c /= n;
		d /= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator>>=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::rShift(m_simdVec, n);
	else {
		xyzw >>= n;
		abcd >>= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::lShift(m_simdVec, n);
	else {
		xyzw <<= n;
		abcd <<= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator&=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::andOp(m_simdVec, n);
	else {
		xyzw &= n;
		abcd &= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator^=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::xorOp(m_simdVec, n);
	else {
		xyzw ^= n;
		abcd ^= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator|=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::orOp(m_simdVec, n);
	else {
		xyzw |= n;
		abcd |= n;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator++() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, 1);
	else {
		++xyzw;
		++abcd;
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::operator--() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, 1);
	else {
		--xyzw;
		--abcd;
	}
	return *this;
}

template<typename T>
Vec8<T> Vec8<T>::operator+(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::add(m_simdVec, n));
	else
		return Vec8<T>(xyzw + n, abcd + n);
}

template<typename T>
Vec8<T> Vec8<T>::operator-(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::sub(m_simdVec, n));
	else
		return Vec8<T>(xyzw - n, abcd - n);
}

template<typename T>
Vec8<T> Vec8<T>::operator*(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::mul(m_simdVec, n));
	else
		return Vec8<T>(xyzw * n, abcd * n);
}

template<typename T>
Vec8<T> Vec8<T>::operator/(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::div(m_simdVec, n));
	else if (IsNotEqual_V<T>(n, static_cast<T>(0)))
		return Vec8<T>(x / n, y / n, z / n, w / n,
			a / n, b / n, c / n, d / n);
}

template<typename T>
Vec8<T> Vec8<T>::operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::rShift(m_simdVec, n));
	else
		return Vec8<T>(xyzw >> n, abcd >> n);
}

template<typename T>
Vec8<T> Vec8<T>::operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::lShift(m_simdVec, n));
	else
		return Vec8<T>(xyzw << n, abcd << n);
}

template<typename T>
Vec8<T> Vec8<T>::operator&(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::andOp(m_simdVec, n));
	else
		return Vec8<T>(xyzw & n, abcd & n);
}

template<typename T>
Vec8<T> Vec8<T>::operator^(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::xorOp(m_simdVec, n));
	else
		return Vec8<T>(xyzw ^ n, abcd ^ n);
}

template<typename T>
Vec8<T> Vec8<T>::operator|(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::orOp(m_simdVec, n));
	else
		return Vec8<T>(xyzw | n, abcd | n);
}

template<typename T>
Vec8<T> Vec8<T>::operator++(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::add(m_simdVec, 1));
	else
		return Vec8<T>(xyzw++, abcd++);
}

template<typename T>
Vec8<T> Vec8<T>::operator--(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::sub(m_simdVec, 1));
	else
		return Vec8<T>(xyzw--, abcd--);
}

template<typename T>
Vec8<T> Vec8<T>::operator-() const {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec8<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec8<T>(-xyzw, -abcd);
}

template<typename T>
Vec8<T>& Vec8<T>::negate() {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::negate(m_simdVec);
	else {
		xyzw.negate();
		abcd.negate();
	}
	return *this;
}

template<typename T>
Vec8<T>& Vec8<T>::abs() {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::abs(m_simdVec);
	else {
		xyzw.abs();
		abcd.abs();
	}
	return *this;
}

template<typename T>
Vec8<F32>& Vec8<T>::ceil() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::ceil(m_simdVec);
	return *this;
}

template<typename T>
Vec8<F32>& Vec8<T>::floor() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::floor(m_simdVec);
	return *this;
}

template<typename T>
Vec8<F32>& Vec8<T>::round() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::round(m_simdVec);
	return *this;
}

template<typename T>
Vec8<F32>& Vec8<T>::sqrt() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::sqrt(m_simdVec);
	return *this;
}

template<typename T>
Vec8<F32>& Vec8<T>::normalize() {
	static_assert(!Vec8<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::div(m_simdVec, magnitude());
	return *this;
}

template<typename T>
Vec8<T> Vec8<T>::sign() const {
	if constexpr(std::is_signed_v<T>) {
		if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE> && !std::is_same_v<T, I8>)
			return SIMDStruct::sign(m_simdVec);
		else {
			return Vec8<T>(x >= 0 ? 1 : -1, y >= 0 ? 1 : -1,
				z >= 0 ? 1 : -1, w >= 0 ? 1 : -1,
				a >= 0 ? 1 : -1, b >= 0 ? 1 : -1,
				c >= 0 ? 1 : -1, d >= 0 ? 1 : -1);
		}
	}
	else
		return Vec8<T>(1, 1, 1, 1, 1, 1, 1, 1);
}

template<typename T>
template<typename U>
Vec8<U> Vec8<T>::cast() const {
	return Vec8<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w),
		static_cast<U>(a), static_cast<U>(b), static_cast<U>(c), static_cast<U>(d));
}

template<typename T>
bool operator==(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::areEqual(v1.m_simdVec, v2.m_simdVec);
	else
		return v1.xyzw == v2.xyzw && v1.abcd == v2.abcd;
}
template<typename T>
bool operator!=(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return !Vec8<T>::SIMDStruct::areEqual(v1.m_simdVec, v2.m_simdVec);
	else
		return v1.xyzw != v2.xyzw && v1.abcd != v2.abcd;
}

template<typename T>
bool operator>(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return !Vec8<T>::SIMDStruct::isGreaterThan(v2.m_simdVec, v1.m_simdVec);
	else
		return v1.xyzw > v2.xyzw && v1.abcd > v2.abcd;
}

template<typename T>
bool operator<(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return !Vec8<T>::SIMDStruct::isGreaterThan(v1.m_simdVec, v2.m_simdVec);
	else
		return v1.xyzw < v2.xyzw && v1.abcd < v2.abcd;
}

template<typename T>
bool operator>=(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return !Vec8<T>::SIMDStruct::isGreaterOrEqThan(v2.m_simdVec, v1.m_simdVec);
	else
		return v1.xyzw >= v2.xyzw && v1.abcd >= v2.abcd;
}

template<typename T>
bool operator<=(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return !Vec8<T>::SIMDStruct::isGreaterOrEqThan(v1.m_simdVec, v2.m_simdVec);
	else
		return v1.xyzw <= v2.xyzw && v1.abcd <= v2.abcd;
}

template<typename T>
Vec8<T> operator+(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::add(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw + v2.xyzw, v1.abcd + v2.abcd);
}

template<typename T>
Vec8<T> operator-(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::sub(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw - v2.xyzw, v1.abcd - v2.abcd);
}

template<typename T>
Vec8<T> operator*(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::mul(v1.m_simdVec, v2.m_simdVec);
	else
		return Vec8<T>(v1.xyzw * v2.xyzw, v1.abcd * v2.abcd);
}

template<typename T>
Vec8<T> operator/(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::div(v1.m_simdVec, v2.m_simdVec));
	else if (!v2.isNull())
		return Vec8<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w,
			v1.a / v2.a, v1.b / v2.b, v1.c / v2.c, v1.d / v2.d);
}

template<typename T>
Vec8<T> operator>>(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::rShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw >> v2.xyzw, v1.abcd >> v2.abcd);
}
template<typename T>
Vec8<T> operator<<(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::lShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw << v2.xyzw, v1.abcd << v2.abcd);
}
template<typename T>
Vec8<T> operator&(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::andOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw & v2.xyzw, v1.abcd & v2.abcd);
}
template<typename T>
Vec8<T> operator^(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::xorOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw ^ v2.xyzw, v1.abcd ^ v2.abcd);
}
template<typename T>
Vec8<T> operator|(const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec8<T>::isIntegral, Vec8<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>(Vec8<T>::SIMDStruct::orOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec8<T>(v1.xyzw | v2.xyzw, v1.abcd | v2.abcd);
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
T Dot(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::horizontalAdd((v1 * v2).m_simdVec);
	else {
		Vec8<T> temp{ v1 * v2 };
		Vec4<T> temp2{ temp.abcd + temp.xyzw };
		Vec2<T> temp3{ temp2.xy + temp2.zw };
		return temp3.x + temp3.y;
	}
}

template<typename T>
Vec4<T> FourDot(const Vec8<T>& row1, const Vec8<T>& row2, const Vec8<T>& col1) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>) {
		return Vec8<T>::SIMDStruct::fourHorizontalAdd((row1 * col1).m_simdVec,
			(row2 * col1).m_simdVec);
	}
}

template<typename T>
Vec8<T> EightDot(const Vec8<T>& row1, const Vec8<T>& row2,
	const Vec8<T>& col1, const Vec8<T>& col2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>) {	
		return Vec8<T>::SIMDStruct::eightHorizontalAdd((row1 * col1).m_simdVec,
			(row1 * col2).m_simdVec, (row2 * col1).m_simdVec, (row2 * col2).m_simdVec);
	}
	else {
		Vec8<T> Mult1{ (row1 * col1) };
		Vec8<T> Mult2{ (row1 * col2) };
		Vec8<T> Dot1{ { Mult1.xy + Mult1.zw,
			Mult1.ab + Mult1.cd },{ Mult2.xy + Mult2.zw,
			Mult2.ab + Mult2.cd } };

		Mult1 = { (row2 * col1) };
		Mult2 = { (row2 * col2) };
		Vec8<T> Dot2{ { Mult1.xy + Mult1.zw,
			Mult1.xy + Mult1.zw },{ Mult2.xy + Mult2.zw,
			Mult2.xy + Mult2.zw } };

		return { Vec4<T>(Dot1.x + Dot1.y, Dot1.z + Dot1.w, Dot1.a + Dot1.b, Dot1.c + Dot1.d),
			Vec4<T>( Dot2.x + Dot2.y, Dot2.z + Dot2.w, Dot2.a + Dot2.b, Dot2.c + Dot2.d ) };
	}
}

template<typename T>
Vec8<T> Negate(const Vec8<T>& v) {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return Vec8<T>(-v);
}

template<typename T>
Vec8<T> Abs(const Vec8<T>& v) {
	static_assert(!std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr(!std::is_same_v<Vec4<T>, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::abs(v.m_simdVec);
	else
		return Vec8(Abs(v.xyzw), Abs(v.abcd));
}

Vec8f Normalize(const Vec8f& v) {
	return Vec8f::SIMDStruct::div(v.m_simdVec, v.magnitude());
}

Vec8f Ceil(const Vec8f& v) {
	return Vec8f::SIMDStruct::ceil(v.m_simdVec);
}

Vec8f Floor(const Vec8f& v) {
	return Vec8f::SIMDStruct::floor(v.m_simdVec);
}

Vec8f Round(const Vec8f& v) {
	return Vec8f::SIMDStruct::round(v.m_simdVec);
}

Vec8f Sqrt(const Vec8f& v) {
	return Vec8f::SIMDStruct::sqrt(v.m_simdVec);
}

template<typename T>
Vec8<T> Min(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::min(v1, v2);
	else
		return { Min(v.xyzw), Min(v.abcd) };
}

template<typename T>
Vec8<T> Max(const Vec8<T>& v1, const Vec8<T>& v2) {
	if constexpr (!std::is_same_v<Vec8<T>::SIMDType, NOT_A_TYPE>)
		return Vec8<T>::SIMDStruct::max(v1, v2);
	else
		return { Max(v.xyzw), Max(v.abcd) };
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec8<T>& v) {
	return o << "{ x : " << v.x << ", y : " << v.y << ", z : " << v.z << ", w : " << v.w <<
		" a : " << v.a << ", b : " << v.b << ", c : " << v.c << ", d : " << v.d << " }";
}

} //namespace math 
} //namespace drak

