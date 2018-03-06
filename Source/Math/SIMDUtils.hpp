#pragma once

#include<Core/Core.hpp>
#include<immintrin.h>
#include <limits>

namespace SIMDUtils {

template<typename T, U32 nElement, U32 size = sizeof(T) * 8,
	bool isIntegral = std::is_integral_v<T>, bool isF32 = std::is_same_v<T, F32>>
struct BestSIMDType {
	using SIMDType = NOT_A_TYPE;
};

template<typename T>
struct BestSIMDType<T, 4, 32, false, true> {
	using SIMDType = typename __m128;

	static constexpr I32 alignement = 16;
	static void set(SIMDType& m, T n1, T n2, T n3, T n4) {
		m = _mm_set_ps(n1, n2, n3, n4);
	}
	static void set(SIMDType& m, T f) {
		m = _mm_set_ps1(f);
	}
	static SIMDType load(T const* arr) {
		return _mm_load_ps(arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm_loadu_ps(arr);
	}
	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm_castps_si128(_mm_xor_ps(m1, m2)));
	}

	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_castps_si128(_mm_cmpgt_ps(m1, m2)));
	}

	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_castps_si128(_mm_cmpge_ps(m1, m2)));
	}
	static bool isAllZeros(const SIMDType& m) {
		union alignas(alignement) {
			T mask[4] = { 1, 1, 1, 1 };
			SIMDType m2;
		};
		return _mm_test_all_zeros(_mm_castps_si128(m2), _mm_castps_si128(m));
	}

	static T horizontalAdd(const SIMDType& m) {
		__m64 m2 = _mm_hadd_pi32(m.m128_i64[0], m.m128_i64[1]);
		m2 = _mm_hadd_pi32(m2, m2);
		return m2.m64_f32[0];
	}

	static SIMDType add(const SIMDType& m, const T f) {
		return _mm_add_ps(m, _mm_set_ps1(f));
	}
	static SIMDType sub(const SIMDType& m, const T f) {
		return _mm_sub_ps(m, _mm_set_ps1(f));
	}
	static SIMDType mul(const SIMDType& m, const T f) {
		return _mm_mul_ps(m, _mm_set_ps1(f));
	}
	static SIMDType div(const SIMDType& m, const T f) {
		return _mm_div_ps(m, _mm_set_ps1(f));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_ps(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_ps(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm_mul_ps(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		return _mm_div_ps(m1, m2);
	}

	static SIMDType negate(const SIMDType& m) {
		return _mm_mul_ps(_mm_set_ps1(-1.f), m);
	}

	static SIMDType cross(const SIMDType& m1, const SIMDType& m2) {
		__m256 temp1, temp2;

		temp1 = _mm256_set_ps(m1.m128_f32[1], m1.m128_f32[2], m1.m128_f32[0],
			m1.m128_f32[2], m1.m128_f32[0], m1.m128_f32[1], 0.f, 0.f);
		temp2 = _mm256_set_ps(m2.m128_f32[2], m2.m128_f32[0], m2.m128_f32[1],
			m2.m128_f32[1], m2.m128_f32[2], m2.m128_f32[0], 0.f, 0.f);

		temp1 = _mm256_mul_ps(temp1, temp2);

		return sub(_mm256_extractf128_ps(temp1, 0), _mm256_extractf128_ps(temp1, 1));
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm_max_ps(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm_min_ps(m1, m2);
	}

	static SIMDType ceil(const SIMDType& m) {
		return _mm_ceil_ps(m);
	}
	static SIMDType floor(const SIMDType& m) {
		return _mm_floor_ps(m);
	}
	static SIMDType round(const SIMDType& m) {
		return _mm_round_ps(m, _MM_ROUND_NEAREST);
	}
};

template<typename T>
struct BestSIMDType<T, 4, 32, true, false> {
	using SIMDType = typename __m128i;

	static constexpr I32 alignement = 16;
	static void set(SIMDType& m, T n1, T n2, T n3, T n4) {
		m = _mm_set_epi32(n1, n2, n3, n4);
	}
	static void set(SIMDType& m, T i) {
		m = _mm_set1_epi32(i);
	}
	static SIMDType load(T const* arr) {
		return _mm_load_si128((SIMDType const*)arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm_loadu_si128((SIMDType const*)arr);;
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm_xor_si128(m1, m2));
	}
	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpgt_epi32(m1, m2));
	}
	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpge_epi32_mask(m1, m2));
	}

	static bool isAllZeros(const SIMDType& m) {
		union alignas(alignement) {
			T mask[4] = { 1, 1, 1, 1 };
			SIMDType m2;
		};
		return _mm_test_all_zeros(m2, m);
	}
	static T horizontalAdd(const SIMDType& m) {
		__m64 m2 = _mm_hadd_pi32(m.m128_i64[0], m.m128_i64[1]);
		m2 = _mm_hadd_pi32(m2, m2);
		return m2.m64_i32[0];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm_add_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm_sub_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm_mul_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
#ifndef __INTEL_COMPILER
		__m128 temp1, temp2;
		BestSIMDType<F32, 4>::set(temp1,
			static_cast<F32>(m.m128i_i32[0]), static_cast<F32>(m.m128i_i32[1]),
			static_cast<F32>(m.m128i_i32[2]), static_cast<F32>(m.m128i_i32[3]));
		BestSIMDType<F32, 4>::set(temp2, static_cast<F32>(i));
		temp1 = BestSIMDType<F32, 4>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m128_f32[0]), static_cast<T>(temp1.m128_f32[1]),
			static_cast<T>(temp1.m128_f32[2]), static_cast<T>(temp1.m128_f32[3]));

		return res;
#else
		return _mm_div_epi32(m, i);
#endif // !__INTEL_COMPILER

	}

	static SIMDType rShift(const SIMDType& m, const T i) {
		return _mm_srli_epi32(m, i);
	}
	static SIMDType lShift(const SIMDType& m, const T i) {
		return _mm_slli_epi32(m, i);
	}
	static SIMDType andOp(const SIMDType& m, const T i) {
		return _mm_and_si128(m, _mm_set1_epi32(i));
	}
	static SIMDType orOp(const SIMDType& m, const T i) {
		return _mm_or_si128(m, _mm_set1_epi32(i));
	}
	static SIMDType xorOp(const SIMDType& m, const T i) {
		return _mm_xor_si128(m, _mm_set1_epi32(i));
	}
	static SIMDType negate(const SIMDType& m) {
		return _mm_sign_epi32(m, _mm_set1_epi32(-1));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_epi32(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_epi32(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm_mul_epi32(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
#ifndef __INTEL_COMPILER
		__m128 temp1, temp2;
		BestSIMDType<F32, 4>::set(temp1,
			static_cast<F32>(m1.m128i_i32[0]), static_cast<F32>(m1.m128i_i32[1]),
			static_cast<F32>(m1.m128i_i32[2]), static_cast<F32>(m1.m128i_i32[3]));
		BestSIMDType<F32, 4>::set(temp2,
			static_cast<F32>(m2.m128i_i32[0]), static_cast<F32>(m2.m128i_i32[1]),
			static_cast<F32>(m2.m128i_i32[2]), static_cast<F32>(m2.m128i_i32[3]));
		temp1 = BestSIMDType<F32, 4>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m128_f32[0]), static_cast<T>(temp1.m128_f32[1]),
			static_cast<T>(temp1.m128_f32[2]), static_cast<T>(temp1.m128_f32[3]));
		return res;
#else
		return _mm_div_epi32(m1, m2);
#endif
	}

	static SIMDType rShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_srli_epi32(m, m2);
	}
	static SIMDType lShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_slli_epi32(m, m2);
	}
	static SIMDType andOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_and_si128(m, m2);
	}
	static SIMDType orOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_or_si128(m, m2);
	}
	static SIMDType xorOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_xor_si128(m, m2);
	}

	static SIMDType cross(const SIMDType& m1, const SIMDType& m2) {
		__m256i temp1, temp2;

		temp1 = _mm256_set_epi32(m1.m128_f32[1], m1.m128_f32[2], m1.m128_f32[0],
			m1.m128_f32[2], m1.m128_f32[0], m1.m128_f32[1], 0.f, 0.f);
		temp2 = _mm256_set_epi32(m2.m128_f32[2], m2.m128_f32[0], m2.m128_f32[1],
			m2.m128_f32[1], m2.m128_f32[2], m2.m128_f32[0], 0.f, 0.f);

		temp1 = _mm256_mul_epi32(temp1, temp2);

		return sub(_mm256_extractf128_si256(temp1, 0), _mm256_extractf128_si256(temp1, 1));
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm_max_epi32(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm_min_epi32(m1, m2);
	}
};

#if defined(_M_IX86) || defined(__INTEL_COMPILER)
template<typename T>
struct BestSIMDType<T, 4, 16, true, false> {
	using SIMDType = typename __m64;
	static constexpr I32 alignement = 8;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4) {
		m = _mm_set_pi16(n1, n2, n3, n4);
		_m_empty();
	}
	static void set(SIMDType& m, T i) {
		m = _mm_set1_pi16(i);
		_m_empty();
	}
	static SIMDType load(T const* arr) {
		return *(SIMDType const*)arr;
	}
	static SIMDType loadu(T const* arr) {
		__m64 res;
		memcpy_inline(res.m64_i16, arr, sizeof(res.m64_i16));
		_m_empty();
		return res;
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_m_pxor(m1, m2));
	}
	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_m_pcmpgtw(m1, m2));
	}
	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return areEqual(m1, m2) || !isGreaterThan(m1, m2);
	}

	static bool isAllZeros(const SIMDType& m) {
		_m_empty();
		return !static_cast<bool>(m.m64_i64);
	}
	static T horizontalAdd(const SIMDType& m) {
		SIMDType m2 = _mm_hadd_pi16(m, m);
		m2 = _mm_hadd_pi16(m2, m2);
		_m_empty();
		return m2.m64_i16[0];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		__m64 res = _mm_add_pi16(m, _mm_set1_pi16(i));
		_m_empty();
		return res;
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		__m64 res = _mm_sub_pi16(m, _mm_set1_pi16(i));
		_m_empty();
		return res;
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		SIMDType hi = _mm_mulhi_pi16(m, _mm_set1_pi16(i));
		SIMDType low = _mm_mullo_pi16(m, _mm_set1_pi16(i));
		SIMDType res;
		res.m64_i16[0] = low.m64_i16[0];
		res.m64_i16[1] = hi.m64_i16[0];
		res.m64_i16[2] = low.m64_i16[2];
		res.m64_i16[3] = hi.m64_i16[2];
		_m_empty();
		return res;
	}
	static SIMDType div(const SIMDType& m, const T i) {
		static_assert("No division allowed on \" I8 \\ I16 \\ __m64\" Data Type!!");
		return mul(m, 1 / i);
	}

	static SIMDType rShift(const SIMDType& m, const T i) {
		return _mm_srli_pi16(m, i);
	}
	static SIMDType lShift(const SIMDType& m, const T i) {
		return _mm_slli_pi16(m, i);
	}
	static SIMDType andOp(const SIMDType& m, const T i) {
		return _m_pand(m, _mm_set1_pi16(i));
	}
	static SIMDType orOp(const SIMDType& m, const T i) {
		return _m_por(m, _mm_set1_pi16(i));
	}
	static SIMDType xorOp(const SIMDType& m, const T i) {
		return _m_pxor(m, _mm_set1_pi16(i));
	}
	static SIMDType negate(const SIMDType& m) {
		return mul(m, _mm_set1_pi16(-1));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_pi16(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_pi16(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		SIMDType hi = _mm_mulhi_pi16(m1, m2);
		SIMDType low = _mm_mullo_pi16(m1, m2);
		SIMDType res;
		res.m64_i16[0] = low.m64_i16[0];
		res.m64_i16[1] = hi.m64_i16[0];
		res.m64_i16[2] = low.m64_i16[2];
		res.m64_i16[3] = hi.m64_i16[2];
		_m_empty();
		return res;
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		static_assert("No division allowed on \" I8 \\ I16 \\ __m64\" Data Type!!");
		return m1;
	}

	static SIMDType rShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_srli_pi16(m, m2);
	}
	static SIMDType lShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_slli_pi16(m, m2);
	}
	static SIMDType andOp(const SIMDType& m1, const SIMDType& m2) {
		return _m_pand(m, m2);
	}
	static SIMDType orOp(const SIMDType& m1, const SIMDType& m2) {
		return _m_por(m, m2);
	}
	static SIMDType xorOp(const SIMDType& m1, const SIMDType& m2) {
		return _m_pxor(m, m2);
	}

	static SIMDType cross(const SIMDType& m1, const SIMDType& m2) {
		__m128i temp1, temp2;

		temp1 = _mm_set_epi16(m1.m64_i16[1], m1.m64_i16[2], m1.m64_i16[0],
			m1.m64_i16[2], m1.m64_i16[0], m1.m64_i16[1], 0.f, 0.f);
		temp2 = _mm_set_epi16(m2.m64_i16[2], m2.m64_i16[0], m2.m64_i16[1],
			m2.m64_i16[1], m2.m64_i16[2], m2.m64_i16[0], 0.f, 0.f);

		temp1 = _mm_mullo_epi16(temp1, temp2);
		_m_empty();
		return sub(temp1.m128i_i64[0], temp1.m128i_i64[1]);
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm_max_pi16(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm_min_pi16(m1, m2);
	}
};
#endif

template<typename T>
struct BestSIMDType<T, 8, 16, true, false> {
	using SIMDType = typename __m128i;
	static constexpr I32 alignement = 16;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4, T n5, T n6, T n7, T n8) {
		m = _mm_set_epi16(n1, n2, n3, n4, n5, n6, n7, n8);
		return m;
	}
	static void set(SIMDType& m, T i) {
		m = _mm_set1_epi16(i);
	}
	static SIMDType load(T const* arr) {
		return _mm_load_si128((SIMDType const*)arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm_loadu_si128((SIMDType const*)arr);;
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm_xor_si128(m1, m2));
	}
	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpgt_epi16(m1, m2));
	}
	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpge_epi16_mask(m1, m2));
	}

	static bool isAllZeros(const SIMDType& m) {
		union alignas(alignement) {
			T mask[8] = { 1, 1, 1, 1, 1, 1, 1, 1};
			SIMDType m2;
		};
		return _mm_test_all_zeros(m2, m);
	}
	static T horizontalAdd(const SIMDType& m) {
		__m64 m2 = _mm_hadd_pi16(m.m128_i64[0], m.m128_i64[1]);
		m2 = _mm_hadd_pi16(m2, m2);
		return m2.m64_i32[0];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm_add_epi16(m, _mm_set1_epi16(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm_sub_epi16(m, _mm_set1_epi16(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm_mullo_epi16(m, _mm_set1_epi16(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
		static_assert("No division allowed on \" I8 \\ I16 \\ __m64\" Data Type!!");
		return 0;
	}

	static SIMDType rShift(const SIMDType& m, const T i) {
		return _mm_srli_epi16(m, i);
	}
	static SIMDType lShift(const SIMDType& m, const T i) {
		return _mm_slli_epi16(m, i);
	}
	static SIMDType andOp(const SIMDType& m, const T i) {
		return _mm_and_si128(m, _mm_set1_epi16(i));
	}
	static SIMDType orOp(const SIMDType& m, const T i) {
		return _mm_or_si128(m, _mm_set1_epi16(i));
	}
	static SIMDType xorOp(const SIMDType& m, const T i) {
		return _mm_xor_si128(m, _mm_set1_epi16(i));
	}
	static SIMDType negate(const SIMDType& m) {
		return _mm_sign_epi16(m, _mm_set1_epi16(-1));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_epi16(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_epi16(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm_mullo_epi16(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		static_assert("No division allowed on \" I8 \\ I16 \\ __m64\" Data Type!!");
		return 0;
	}

	static SIMDType rShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_srli_epi16(m, m2);
	}
	static SIMDType lShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm_slli_epi16(m, m2);
	}
	static SIMDType andOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_and_si128(m, m2);
	}
	static SIMDType orOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_or_si128(m, m2);
	}
	static SIMDType xorOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm_xor_si128(m, m2);
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm_max_epi16(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm_min_epi16(m1, m2);
	}
};

template<typename T>
struct BestSIMDType<T, 8, 32, true, false> {
	using SIMDType = typename __m256i;
	static constexpr I32 alignement = 32;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4, T n5, T n6, T n7, T n8) {
		m = _mm256_set_epi32(n1, n2, n3, n4, n5, n6, n7, n8);
	}
	static void set(SIMDType& m, T i) {
		m = _mm256_set1_epi32(i);
	}
	static SIMDType load(T const* arr) {
		return _mm256_load_si256((SIMDType const*)arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm256_loadu_si256((SIMDType const*)arr);;
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm256_xor_si256(m1, m2));
	}
	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_cmpgt_epi32(m1, m2));
	}
	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_cmpge_epi32_mask(m1, m2));
	}

	static bool isAllZeros(const SIMDType& m) {
		union alignas(alignement) {
			T mask[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
			SIMDType m2;
		};
		return _mm256_test_all_zeros(m2, m);
	}
	static T horizontalAdd(const SIMDType& m) {
		__m128 m2 = _mm_hadd_epi32(m.m128_i64[0], m.m128_i64[1]);
		m2 = _mm_hadd_epi32(m2, m2);
		return m2.m128_i32[0];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm256_add_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm256_sub_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm256_mul_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
		__m256 temp1, temp2;
		BestSIMDType<F32, 8>::set(temp1,
			static_cast<F32>(m.m256i_i32[0]), static_cast<F32>(m.m256i_i32[1]),
			static_cast<F32>(m.m256i_i32[2]), static_cast<F32>(m.m256i_i32[3]),
			static_cast<F32>(m.m256i_i32[4]), static_cast<F32>(m.m256i_i32[5]),
			static_cast<F32>(m.m256i_i32[6]), static_cast<F32>(m.m256i_i32[7]));
		BestSIMDType<F32, 8>::set(temp2, static_cast<F32>(i));
		temp1 = BestSIMDType<F32, 8>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m256_f32[0]), static_cast<T>(temp1.m256_f32[1]),
			static_cast<T>(temp1.m256_f32[2]), static_cast<T>(temp1.m256_f32[3]),
			static_cast<T>(temp1.m256_f32[4]), static_cast<T>(temp1.m256_f32[5]),
			static_cast<T>(temp1.m256_f32[6]), static_cast<T>(temp1.m256_f32[7]));

		return res;
	}

	static SIMDType rShift(const SIMDType& m, const T i) {
		return _mm256_srli_epi32(m, i);
	}
	static SIMDType lShift(const SIMDType& m, const T i) {
		return _mm256_slli_epi32(m, i);
	}
	static SIMDType andOp(const SIMDType& m, const T i) {
		return _mm256_and_si256(m, _mm256_set1_epi32(i));
	}
	static SIMDType orOp(const SIMDType& m, const T i) {
		return _mm256_or_si256(m, _mm256_set1_epi32(i));
	}
	static SIMDType xorOp(const SIMDType& m, const T i) {
		return _mm256_xor_si256(m, _mm256_set1_epi32(i));
	}
	static SIMDType negate(const SIMDType& m) {
		return _mm256_sign_epi32(m, _mm256_set1_epi32(-1));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_add_epi32(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_sub_epi32(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_mul_epi32(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		__m256 temp1, temp2;
		BestSIMDType<F32, 8>::set(temp1,
			static_cast<F32>(m1.m256i_i32[0]), static_cast<F32>(m1.m256i_i32[1]),
			static_cast<F32>(m1.m256i_i32[2]), static_cast<F32>(m1.m256i_i32[3]),
			static_cast<F32>(m1.m256i_i32[4]), static_cast<F32>(m1.m256i_i32[5]),
			static_cast<F32>(m1.m256i_i32[6]), static_cast<F32>(m1.m256i_i32[7]));

		BestSIMDType<F32, 8>::set(temp2,
			static_cast<F32>(m2.m256i_i32[0]), static_cast<F32>(m2.m256i_i32[1]),
			static_cast<F32>(m2.m256i_i32[2]), static_cast<F32>(m2.m256i_i32[3]),
			static_cast<F32>(m2.m256i_i32[4]), static_cast<F32>(m2.m256i_i32[5]),
			static_cast<F32>(m2.m256i_i32[6]), static_cast<F32>(m2.m256i_i32[7]));

		temp1 = BestSIMDType<F32, 8>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m256_f32[0]), static_cast<T>(temp1.m256_f32[1]),
			static_cast<T>(temp1.m256_f32[2]), static_cast<T>(temp1.m256_f32[3]),
			static_cast<T>(temp1.m256_f32[4]), static_cast<T>(temp1.m256_f32[5]),
			static_cast<T>(temp1.m256_f32[6]), static_cast<T>(temp1.m256_f32[7]));
		return res;
	}

	static SIMDType rShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_srli_epi32(m, m2);
	}
	static SIMDType lShift(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_slli_epi32(m, m2);
	}
	static SIMDType andOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_and_si256(m, m2);
	}
	static SIMDType orOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_or_si256(m, m2);
	}
	static SIMDType xorOp(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_xor_si256(m, m2);
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_max_epi32(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_min_epi32(m1, m2);
	}
};

template<typename T>
struct BestSIMDType<T, 8, 32, false, true> {
	using SIMDType = typename __m256;
	static constexpr I32 alignement = 32;

	static void set(SIMDType& m, T f1, T f2, T f3, T f4, T f5, T f6, T f7, T f8) {
		m = _mm256_set_ps(f1, f2, f3, f4, f5, f6, f7, f8);
	}
	static void set(SIMDType& m, T f) {
		m = _mm256_set1_ps(f);
	}
	static SIMDType load(T const* arr) {
		return _mm256_load_ps(arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm256_loadu_ps(arr);
	}
	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm256_castps_si256(_mm256_xor_ps(m1, m2)));
	}

	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_castps_si256(_mm256_cmp_ps(m1, m2, _CMP_GT_OS)));
	}

	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_castps_si256(_mm256_cmp_ps(m1, m2, _CMP_GE_OS)));
	}
	static bool isAllZeros(const SIMDType& m) {
		union alignas(alignement) {
			T mask[8] = { 1, 1, 1, 1, 1, 1, 1, 1 };
			SIMDType m2;
		};
		return _mm256_test_all_zeros(_mm256_castps_si256(m2), _mm256_castps_si256(m));
	}

	static T horizontalAdd(const SIMDType& m) {
		__m128 m2 = _mm_hadd_ps(_mm256_extractf128_ps(m, 0), _mm256_extractf128_ps(m, 1));
		m2 = _mm_hadd_ps(m2, m2);
		return m2.m128_f32[0];
	}

	static SIMDType add(const SIMDType& m, const T f) {
		return _mm256_add_ps(m, _mm256_set1_ps(f));
	}
	static SIMDType sub(const SIMDType& m, const T f) {
		return _mm256_sub_ps(m, _mm256_set1_ps(f));
	}
	static SIMDType mul(const SIMDType& m, const T f) {
		return _mm256_mul_ps(m, _mm256_set1_ps(f));
	}
	static SIMDType div(const SIMDType& m, const T f) {
		return _mm256_div_ps(m, _mm256_set1_ps(f));
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_add_ps(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_sub_ps(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_mul_ps(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_div_ps(m1, m2);
	}

	static SIMDType negate(const SIMDType& m) {
		return _mm256_mul_ps(_mm256_set1_ps(-1.f), m);
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_max_ps(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm256_min_ps(m1, m2);
	}

	static SIMDType ceil(const SIMDType& m) {
		return _mm256_ceil_ps(m);
	}
	static SIMDType floor(const SIMDType& m) {
		return _mm256_floor_ps(m);
	}
	static SIMDType round(const SIMDType& m) {
		return _mm256_round_ps(m, _MM_ROUND_NEAREST);
	}
};

template<typename T, U32 nElement>
using BestSIMDType_T = typename BestSIMDType<T, nElement>::type;

} //namespace SIMDUtils