#pragma warning(disable : 4799)
#include <cassert>
#include <Math/Vec4.hpp>

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
Vec4<T>::Vec4(const T n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, n);
	else {
		xyz = Vec3<T>(n);
		w = n;
	}
}

template<typename T>
Vec4<T>::Vec4(T* arr) {
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
		m_simdVec = v.m_simdVec;
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
}

template<typename T>
Vec4<T>::Vec4(Vec4<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = v.m_simdVec;
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
		xy = v;
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(Vec2<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y,
			static_cast<T>(0), static_cast<T>(0));
	else {
		xy = std::move(v);
		z = static_cast<T>(0);
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec2<T>& v1, const Vec2<T>& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v1.x, v1.y, v2.x, v2.y);
	else {
		xy = v1;
		zw = v2;
	}
}

template<typename T>
Vec4<T>::Vec4(Vec2<T>&& v1, Vec2<T>&& v2) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v1.x, v1.y, v2.x, v2.y);
	else {
		xy = std::move(v1);
		zw = std::move(v2);
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec3<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, static_cast<T>(0));
	else {
		xyz = v;
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(Vec3<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, static_cast<T>(0));
	else {
		xyz = std::move(v);
		w = static_cast<T>(0);
	}
}

template<typename T>
Vec4<T>::Vec4(const Vec3<T>& v, T W) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, W);
	else {
		xyz = v;
		w = W;
	}
}

template<typename T>
Vec4<T>::Vec4(Vec3<T>&& v, T W) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, v.x, v.y, v.z, W);
	else {
		xyz = v;
		w = W;
	}
}

template<typename T>
Vec4<T>::Vec4(T X, const Vec3<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, X, v.x, v.y, v.z);
	else {
		x = X;
		yzw = v;
	}
}

template<typename T>
Vec4<T>::Vec4(T X, Vec3<T>&& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		SIMDStruct::set(m_simdVec, X, v.x, v.y, v.z);
	else {
		x = X;
		yzw = std::move(v);
	}
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
		return std::sqrt(static_cast<F32>(Dot(xyz, xyz) + w * w));
}

template<typename T>
Vec4<T>& Vec4<T>::operator=(const Vec4<T>& v) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = v.m_simdVec;
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
		m_simdVec = v.m_simdVec;
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else
		memcpy(m_vec, v.m_vec, sizeof(m_vec));
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
		xyz += n;
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
		xyz -= n;
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
		xyz *= n;
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
		xyz >>= n;
		w >>= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator<<=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::lShift(m_simdVec, n);
	else {
		xyz <<= n;
		w <<= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator&=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::andOp(m_simdVec, n);
	else {
		xyz &= n;
		w &= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator^=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::xorOp(m_simdVec, n);
	else {
		xyz ^= n;
		w ^= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator|=(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::orOp(m_simdVec, n);
	else {
		xyz |= n;
		w |= n;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator++() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::add(m_simdVec, 1);
	else {
		++xyz;
		++w;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::operator--() {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::sub(m_simdVec, 1);
	else {
		--xyz;
		--w;
	}
	return *this;
}

template<typename T>
Vec4<T> Vec4<T>::operator+(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::add(m_simdVec, n));
	else
		return Vec4<T>(xyz + n, w + n);
}

template<typename T>
Vec4<T> Vec4<T>::operator-(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::sub(m_simdVec, n));
	else
		return Vec4<T>(xyz - n, w - n);
}

template<typename T>
Vec4<T> Vec4<T>::operator*(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::mul(m_simdVec, n));
	else
		return Vec4<T>(xyz * n, w * n);
}

template<typename T>
Vec4<T> Vec4<T>::operator/(const T n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::div(m_simdVec, n));
	else {
		if (IsNotEqual_V<T>(n, static_cast<T>(0)))
			return Vec4<T>(x / n, y / n, z / n, w / n);
	}
}

template<typename T>
Vec4<T> Vec4<T>::operator>>(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::rShift(m_simdVec, n));
	else
		return Vec4<T>(xyz >> n, w >> n);
}

template<typename T>
Vec4<T> Vec4<T>::operator<<(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::lShift(m_simdVec, n));
	else
		return Vec4<T>(xyz << n, w << n);
}

template<typename T>
Vec4<T> Vec4<T>::operator&(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::andOp(m_simdVec, n));
	else
		return Vec4<T>(xyz & n, w & n);
}

template<typename T>
Vec4<T> Vec4<T>::operator^(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::xorOp(m_simdVec, n));
	else
		return Vec4<T>(xyz ^ n, w ^ n);
}

template<typename T>
Vec4<T> Vec4<T>::operator|(const ENABLE_IF_ELSE_T(isIntegral, I32, NOT_A_TYPE)n) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::orOp(m_simdVec, n));
	else
		return Vec4<T>(xyz | n, w | n);
}

template<typename T>
Vec4<T> Vec4<T>::operator++(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::add(m_simdVec, 1));
	else
		return Vec4<T>(xyz++, w++);
}

template<typename T>
Vec4<T> Vec4<T>::operator--(const I32) const {
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::sub(m_simdVec, 1));
	else
		return Vec4<T>(xyz--, w--);
}

template<typename T>
Vec4<T> Vec4<T>::operator-() const {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		return Vec4<T>(SIMDStruct::negate(m_simdVec));
	else
		return Vec4<T>(-xyz, -w);
}

template<typename T>
Vec4<T>& Vec4<T>::negate() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>)
		m_simdVec = SIMDStruct::negate(m_simdVec);
	else {
		xyz.negate();
		w = -w;
	}
	return *this;
}

template<typename T>
Vec4<T>& Vec4<T>::abs() {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE>) {
		m_simdVec = SIMDStruct::abs(m_simdVec);
		if constexpr(std::is_same_v<T, I16>)
			_m_empty();
	}
	else {
		xyz.abs();
		w = std::abs(w);
	}
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::ceil() {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::ceil(m_simdVec);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::floor() {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::floor(m_simdVec);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::round() {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::round(m_simdVec);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::sqrt() {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::sqrt(m_simdVec);
	return *this;
}

template<typename T>
Vec4<F32>& Vec4<T>::normalize() {
	static_assert(!Vec4<T>::isIntegral, DK_MATH_ERROR2(T));
	m_simdVec = SIMDStruct::div(m_simdVec, magnitude());
	return *this;
}

template<typename T>
Vec4<T> Vec4<T>::sign() const {
	if constexpr(std::is_signed_v<T>) {
		if constexpr (!std::is_same_v<SIMDType, NOT_A_TYPE> && !std::is_same_v<T, I16>)
			return SIMDStruct::sign(m_simdVec);
		else {
			F32 wFTemp = static_cast<F32>(w);
			U32 wTemp = (*reinterpret_cast<U32*>(&wFTemp) & (1 << 31)) | (1 << 30);
			return Vec4<T>(xyz.sign(),
				static_cast<T>(*reinterpret_cast<F32*>(&wTemp) * 0.5f));
		}
	}
	else
		return Vec4<T>(1, 1, 1, 1);
}

template<typename T>
Vec2<T> Vec4<T>::yz() const {
	return Vec2<T>(y, z);
}

template<typename T>
Vec2<T> Vec4<T>::yx() const {
	return Vec2<T>(y, x);
}

template<typename T>
Vec2<T> Vec4<T>::wz() const {
	return Vec2<T>(w, z);
}

template<typename T>
Vec2<T> Vec4<T>::zy() const {
	return Vec2<T>(z, y);
}

template<typename T>
Vec3<T> Vec4<T>::zyx() const {
	return Vec3<T>(z, y, x);
}

template<typename T>
Vec3<T> Vec4<T>::yzx() const {
	return Vec3<T>(y, z, x);
}

template<typename T>
Vec3<T> Vec4<T>::zxy() const {
	return Vec3<T>(z, x, y);
}

template<typename T>
Vec3<T> Vec4<T>::bgr() const {
	return Vec3<T>(b, g, r);
}

template<typename T>
Vec3<T> Vec4<T>::gbr() const {
	return Vec3<T>(g, b, r);
}

template<typename T>
Vec3<T> Vec4<T>::brg() const {
	return Vec3<T>(b, r, g);
}

template<typename T>
Vec3<T> Vec4<T>::wyz() const {
	return Vec3<T>(w, y, z);
}

template<typename T>
Vec3<T> Vec4<T>::zyw() const {
	return Vec3<T>(z, y, w);
}

template<typename T>
Vec3<T> Vec4<T>::zwy() const {
	return Vec3<T>(z, w, y);
}

template<typename T>
Vec4<T> Vec4<T>::bgra() const {
	return Vec4<T>(b, r, g, a);
}

template<typename T>
Vec4<T> Vec4<T>::gbra() const {
	return Vec4<T>(g, b, r, a);
}

template<typename T>
Vec4<T> Vec4<T>::brga() const {
	return Vec4<T>(b, r, g, a);
}

template<typename T>
Vec4<T> Vec4<T>::Null() {
	return Vec4<T>();
}

template<typename T>
Vec4<T> Vec4<T>::Up() {
	return Vec4<T>(Vec3<T>::Up(), static_cast<T>(1));
}

template<typename T>
Vec4<T> Vec4<T>::Right() {
	return Vec4<T>(Vec3<T>::Right(), static_cast<T>(1));
}

template<typename T>
Vec4<T> Vec4<T>::Forward() {
	return Vec4<T>(Vec3<T>::Forward(), static_cast<T>(1));
}

template<typename T>
template<typename U>
Vec4<U> Vec4<T>::cast() const {
	return Vec4<U>(static_cast<U>(x), static_cast<U>(y),
		static_cast<U>(z), static_cast<U>(w));
}

template<typename T>
bool operator==(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>::SIMDStruct::areEqual(v1.m_simdVec, v2.m_simdVec);
	else
		return v1.xyz == v2.xyz && v1.w == v2.w;
}
template<typename T>
bool operator!=(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return !Vec4<T>::SIMDStruct::areEqual(v1.m_simdVec, v2.m_simdVec);
	else
		return !(v1.xyz == v2.xyz && v1.w == v2.w);
}

template<typename T>
bool operator>(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return !Vec4<T>::SIMDStruct::isGreaterThan(v2.m_simdVec, v1.m_simdVec);
	else
		return !(v1.xyz < v2.xyz && v1.w < v2.w);
}

template<typename T>
bool operator<(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return !Vec4<T>::SIMDStruct::isGreaterThan(v1.m_simdVec, v2.m_simdVec);
	else
		return !(v1.xyz > v2.xyz && v1.w > v2.w);
}

template<typename T>
bool operator>=(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return !Vec4<T>::SIMDStruct::isGreaterOrEqThan(v2.m_simdVec, v1.m_simdVec);
	else
		return !(v1.xyz <= v2.xyz && v1.w <= v2.w);
}

template<typename T>
bool operator<=(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return !Vec4<T>::SIMDStruct::isGreaterOrEqThan(v1.m_simdVec, v2.m_simdVec);
	else
		return !(v1.xyz >= v2.xyz && v1.w >= v2.w);
}

template<typename T>
Vec4<T> operator+(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::add(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz + v2.xyz, v1.w + v2.w);
}

template<typename T>
Vec4<T> operator-(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::sub(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz - v2.xyz, v1.w - v2.w);
}

template<typename T>
Vec4<T> operator*(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::mul(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz * v2.xyz, v1.w * v2.w);
}

template<typename T>
Vec4<T> operator/(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::div(v1.m_simdVec, v2.m_simdVec));
	else {
		if (!v2.isNull())
			return Vec4<T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
	}
}

template<typename T>
Vec4<T> operator>>(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::rShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz >> v2.xyz, v1.w >> v2.w);
}
template<typename T>
Vec4<T> operator<<(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::lShift(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz << v2.xyz, v1.w << v2.w);
}
template<typename T>
Vec4<T> operator&(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::andOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz & v2.xyz, v1.w & v2.w);
}
template<typename T>
Vec4<T> operator^(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::xorOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz ^ v2.xyz, v1.w ^ v2.w);
}
template<typename T>
Vec4<T> operator|(const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v1,
	const ENABLE_IF_ELSE_T(Vec4<T>::isIntegral, Vec4<T>, NOT_A_TYPE)& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::orOp(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(v1.xyz | v2.xyz, v1.w | v2.w);
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
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>::SIMDStruct::horizontalAdd((v1 * v2).m_simdVec);
	else
		return Dot(v1.xyz, v2.xyz) + v1.w * v2.w;
}

template<typename T>
Vec4<T> Cross(const Vec4<T>& v1, const Vec4<T>& v2) {
	if constexpr (!std::is_same_v<typename Vec4<T>::SIMDType, NOT_A_TYPE>)
		return Vec4<T>(Vec4<T>::SIMDStruct::cross(v1.m_simdVec, v2.m_simdVec));
	else
		return Vec4<T>(Cross(v1.xyz, v2.xyz), static_cast<T>(0));
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
Vec4<T> Negate(const Vec4<T>& v) {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	return -v;
}

template<typename T>
Vec4<T> Abs(const Vec4<T>& v) {
	static_assert(std::is_signed_v<T>, DK_MATH_ERROR3(T));
	if constexpr(!std::is_same_v<Vec4<T>, NOT_A_TYPE>)
		return Vec4<T>::SIMDStruct::abs(v.m_simdVec);
	else
		return Vec4(Abs(v.xyz), std::abs(v.w));
}

Vec4f operator/(F32 f1, const Vec4f& v) {
	__m128 temp;
	Vec4f::SIMDStruct::set(temp, f1);
	return Vec4f::SIMDStruct::div(temp, v.m_simdVec);
}

Vec4f Normalize(const Vec4f& v) {
	return v / v.magnitude();
}

Vec4f Ceil(const Vec4f& v) {
	return Vec4f::SIMDStruct::ceil(v.m_simdVec);
}

Vec4f Floor(const Vec4f& v) {
	return Vec4f::SIMDStruct::floor(v.m_simdVec);
}

Vec4f Round(const Vec4f& v) {
	return Vec4f::SIMDStruct::round(v.m_simdVec);
}

Vec4f Sqrt(const Vec4f& v) {
	return Vec4f::SIMDStruct::sqrt(v.m_simdVec);
}

template<typename T>
Vec4<T> Min(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Vec4<T>::SIMDStruct::min(v1.m_simdVec, v2.m_simdVec);
}

template<typename T>
Vec4<T> Max(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Vec4<T>::SIMDStruct::max(v1.m_simdVec, v2.m_simdVec);
}

template<typename T>
bool ArePerpendicular(const Vec4<T>& v1, const Vec4<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(0));
}

template<typename T>
bool AreColinear(const Vec4<T>& v1, const Vec4<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(1));
}

template<typename T>
bool AreOpposed(const Vec4<T>& v1, const Vec4<T>& v2) {
	return IsEqual_V<T>(Dot(v1, v2), static_cast<T>(-1));
}

template<typename T>
bool AreSameDirection(const Vec4<T>& v1, const Vec4<T>& v2) {
	return  Dot(v1, v2) > static_cast<T>(0);
}

template<typename T>
bool AreOpposedDirection(const Vec4<T>& v1, const Vec4<T>& v2) {
	return Dot(v1, v2) < static_cast<T>(0);
}

template<typename T, AngleUnit unit>
F32 Angle(const Vec4<T>& va, const Vec4<T>& vb) {
	if constexpr (unit == AngleUnit::RADIANS)
		return acos(Dot(Normalize(va), Normalize(vb)));
	else
		return acos(Dot(Normalize(va), Normalize(vb))) * ToDegF;
}

Vec4f Lerp(const Vec4f& start, const Vec4f& end, F32 percent) {
	return Vec4f(start + Direction(start, end) * percent);
}

Vec4f SLerp(const Vec4f& start, const Vec4f& end, F32 percent) {
	F32 dot = Dot(Normalize(start), Normalize(end));
	F32 theta = acos(dot) * percent;
	return Vec4f(start * cos(theta) + (Direction(start, end) * dot).normalize() * sin(theta));
}

Vec4f NLerp(const Vec4f& start, const Vec4f& end, F32 percent) {
	return Lerp(start, end, percent).normalize();
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Vec4<T>& v) {
	return o << "{ x : " << v.x << ", y : " << v.y << ", z : " << v.z << ", w : " << v.w << " }";
}

} //namespace math 
} //namespace drak