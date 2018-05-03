#pragma once

#include<Core/Core.hpp>
#include <limits>

namespace SIMDUtils {

template<typename T, U32 nElement, U32 size = sizeof(T) * 8,
	bool isIntegral = std::is_integral_v<T>, bool isF32 = std::is_same_v<T, F32>,
	bool isSigned = std::is_signed_v<T>>
struct BestSIMDType {
	using SIMDType = NOT_A_TYPE;
	static constexpr I32 alignement = 0;
};

template<typename T>
struct BestSIMDType<T, 4, 32, false, true, true> {
	using SIMDType = typename __m128;

	static constexpr I32 alignement = 16;
	static void set(SIMDType& m, T f1, T f2, T f3, T f4) {
		m = _mm_set_ps(f4, f3, f2, f1);
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
		return isAllZeros(_mm_xor_ps(m1, m2));
	}

	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpgt_ps(m1, m2));
	}

	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm_cmpge_ps(m1, m2));
	}
	static bool isAllZeros(const SIMDType& m) {
		return _mm_test_all_zeros(_mm_set1_epi32(0xFFFFFFFF), _mm_castps_si128(m));
	}

	static T horizontalAdd(const SIMDType& m) {
		__m128 m2 = _mm_hadd_ps(m, m);
		m2 = _mm_hadd_ps(m2, m2);
		return m2.m128_f32[0];
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

		temp1 = _mm256_set_ps(0.f, m1.m128_f32[1], m1.m128_f32[0], m1.m128_f32[2], 0.f,
			m1.m128_f32[0], m1.m128_f32[2], m1.m128_f32[1]);
		temp2 = _mm256_set_ps(0.f, m2.m128_f32[0], m2.m128_f32[2], m2.m128_f32[1], 0.f,
			m2.m128_f32[1], m2.m128_f32[0], m2.m128_f32[2]);

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

	static SIMDType sqrt(const SIMDType& m) {
		return _mm_sqrt_ps(m);
	}

	static SIMDType abs(const SIMDType& m) {
		return _mm_andnot_ps(_mm_set1_ps(-0.f), m);
	}

	static SIMDType sign(const SIMDType& m) {
		return _mm_or_ps(_mm_and_ps(_mm_set1_ps(-0.f), m), _mm_set1_ps(1.f));
	}
};

template<typename T, bool isSigned>
struct BestSIMDType<T, 4, 32, true, false, isSigned> {
	using SIMDType = typename __m128i;

	static constexpr I32 alignement = 16;
	static void set(SIMDType& m, T n1, T n2, T n3, T n4) {
		m = _mm_set_epi32(n4, n3, n2, n1);
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
		return _mm_test_all_zeros(_mm_set1_epi32(0xFFFFFFFF), m);
	}
	static T horizontalAdd(const SIMDType& m) {
#if defined(_M_IX86) || defined(__INTEL_COMPILER)
		__m64 m2 = _mm_hadd_pi32(*(__m64 const*)m.m128i_i64, *(__m64 const*)&m.m128i_i64[1]);
		m2 = _mm_hadd_pi32(m2, m2);
		_m_empty();
		return m2.m64_i32[0];
#else
		SIMDType m2 = _mm_hadd_epi32(m, m);
		m2 = _mm_hadd_epi32(m2, m2);
		return m2.m128i_i32[0];
#endif
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm_add_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm_sub_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm_mullo_epi32(m, _mm_set1_epi32(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
		__m128 temp1, temp2;
		if constexpr (isSigned)
			BestSIMDType<F32, 4>::set(temp1,
				static_cast<F32>(m.m128i_i32[0]), static_cast<F32>(m.m128i_i32[1]),
				static_cast<F32>(m.m128i_i32[2]), static_cast<F32>(m.m128i_i32[3]));
		else
			BestSIMDType<F32, 4>::set(temp1,
				static_cast<F32>(m.m128i_u32[0]), static_cast<F32>(m.m128i_u32[1]),
				static_cast<F32>(m.m128i_u32[2]), static_cast<F32>(m.m128i_u32[3]));
		BestSIMDType<F32, 4>::set(temp2, static_cast<F32>(i));
		temp1 = BestSIMDType<F32, 4>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m128_f32[0]), static_cast<T>(temp1.m128_f32[1]),
			static_cast<T>(temp1.m128_f32[2]), static_cast<T>(temp1.m128_f32[3]));

		return res;
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
		if constexpr (isSigned)
			return _mm_sign_epi32(m, _mm_set1_epi32(-1));
		else
			return m;
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_epi32(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_epi32(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm_mullo_epi32(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		__m128 temp1, temp2;
		if constexpr (isSigned) {
			BestSIMDType<F32, 4>::set(temp1,
				static_cast<F32>(m.m128i_i32[0]), static_cast<F32>(m.m128i_i32[1]),
				static_cast<F32>(m.m128i_i32[2]), static_cast<F32>(m.m128i_i32[3]));
			BestSIMDType<F32, 4>::set(temp2,
				static_cast<F32>(m2.m128i_i32[0]), static_cast<F32>(m2.m128i_i32[1]),
				static_cast<F32>(m2.m128i_i32[2]), static_cast<F32>(m2.m128i_i32[3]));
		}
		else {
			BestSIMDType<F32, 4>::set(temp1,
				static_cast<F32>(m.m128i_u32[0]), static_cast<F32>(m.m128i_u32[1]),
				static_cast<F32>(m.m128i_u32[2]), static_cast<F32>(m.m128i_u32[3]));
			BestSIMDType<F32, 4>::set(temp2,
				static_cast<F32>(m2.m128i_u32[0]), static_cast<F32>(m2.m128i_u32[1]),
				static_cast<F32>(m2.m128i_u32[2]), static_cast<F32>(m2.m128i_u32[3]));
		}
		temp1 = BestSIMDType<F32, 4>::div(temp1, temp2);
		SIMDType res;
		set(res, static_cast<T>(temp1.m128_f32[0]), static_cast<T>(temp1.m128_f32[1]),
			static_cast<T>(temp1.m128_f32[2]), static_cast<T>(temp1.m128_f32[3]));
		return res;
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

		if constexpr (isSigned) {
			temp1 = _mm256_set_epi32(0, m1.m128i_i32[1], m1.m128i_i32[0], m1.m128i_i32[2], 0,
				m1.m128i_i32[0], m1.m128i_i32[2], m1.m128i_i32[1]);
			temp2 = _mm256_set_epi32(0, m2.m128i_i32[0], m2.m128i_i32[2], m2.m128i_i32[1], 0,
				m2.m128i_i32[1], m2.m128i_i32[0], m2.m128i_i32[2]);
		}
		else {
			temp1 = _mm256_set_epi32(0, m1.m128i_u32[1], m1.m128i_u32[0], m1.m128i_u32[2], 0,
				m1.m128i_u32[0], m1.m128i_u32[2], m1.m128i_u32[1]);
			temp2 = _mm256_set_epi32(0, m2.m128i_u32[0], m2.m128i_u32[2], m2.m128i_u32[1], 0,
				m2.m128i_u32[1], m2.m128i_u32[0], m2.m128i_u32[2]);
		}
		temp1 = _mm256_mullo_epi32(temp1, temp2);

		return sub(_mm256_extractf128_si256(temp1, 0), _mm256_extractf128_si256(temp1, 1));
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		if constexpr (isSigned)
			return _mm_max_epi32(m1, m2);
		else
			return _mm_max_epu32(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		if constexpr (isSigned)
			return _mm_min_epi32(m1, m2);
		else
			return _mm_min_epu32(m1, m2);
	}

	static SIMDType abs(const SIMDType& m) {
		if constexpr (isSigned)
			return _mm_abs_epi32(m);
		else
			return m;
	}

	static SIMDType sign(const SIMDType& m) {
		if constexpr (isSigned) {
			__m128 temp = _mm_setr_ps(static_cast<F32>(m.m128i_i32[0]), static_cast<F32>(m.m128i_i32[1]),
				static_cast<F32>(m.m128i_i32[2]), static_cast<F32>(m.m128i_i32[3]));
			temp = _mm_or_ps(_mm_and_ps(_mm_set1_ps(-0.f), temp), _mm_set1_ps(1.f));
			return _mm_setr_epi32(static_cast<I32>(temp.m128_f32[0]), static_cast<I32>(temp.m128_f32[1]),
				static_cast<I32>(temp.m128_f32[2]), static_cast<I32>(temp.m128_f32[3]));
		}
		else
			return _mm_set1_epi32(1);
	}
};

#if defined(_M_IX86) || defined(__INTEL_COMPILER)
template<typename T, bool isSigned>
struct BestSIMDType<T, 4, 16, true, false, isSigned> {
	using SIMDType = typename __m64;
	static constexpr I32 alignement = 8;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4) {
		m = _mm_set_pi16(n4, n3, n2, n1);
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
		memcpy(res.m64_i16, arr, sizeof(res.m64_i16));
		return res;
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		__m64 temp = _m_pxor(m1, m2);
		_m_empty();
		return isAllZeros(temp);
	}
	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_m_pcmpgtw(m1, m2));
	}
	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return areEqual(m1, m2) || !isGreaterThan(m1, m2);
	}

	static bool isAllZeros(const SIMDType& m) {
		return !static_cast<bool>(m.m64_i64);
	}
	static T horizontalAdd(const SIMDType& m) {
		SIMDType m2 = _mm_hadd_pi16(m, m);
		m2 = _mm_hadd_pi16(m2, m2);
		_m_empty();
		return m2.m64_i16[0];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm_add_pi16(m, _mm_set1_pi16(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm_sub_pi16(m, _mm_set1_pi16(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm_mullo_pi16(m, _mm_set1_pi16(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
		static_assert(false, "No division allowed on \"I8\\I16\\__m64\" Data Type!!");
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
		if constexpr (isSigned)
			return mul(m, _mm_set1_pi16(-1));
		else
			return m;
	}

	static SIMDType add(const SIMDType& m1, const SIMDType& m2) {
		return _mm_add_pi16(m1, m2);
	}
	static SIMDType sub(const SIMDType& m1, const SIMDType& m2) {
		return _mm_sub_pi16(m1, m2);
	}
	static SIMDType mul(const SIMDType& m1, const SIMDType& m2) {
		return _mm_mullo_pi16(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		static_assert(false, "No division allowed on \"I8\\I16\\__m64\" Data Type!!");
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
		if constexpr (isSigned) {
			temp1 = _mm_set_epi16(0, m1.m64_i16[1], m1.m64_i16[0], m1.m64_i16[2], 0,
				m1.m64_i16[0], m1.m64_i16[2], m1.m64_i16[1]);
			temp2 = _mm_set_epi16(0, m2.m64_i16[0], m2.m64_i16[2], m2.m64_i16[1], 0,
				m2.m64_i16[1], m2.m64_i16[0], m2.m64_i16[2]);
		}
		else {
			temp1 = _mm_set_epi16(0, m1.m64_u16[1], m1.m64_u16[0], m1.m64_u16[2], 0,
				m1.m64_u16[0], m1.m64_u16[2], m1.m64_u16[1]);
			temp2 = _mm_set_epi16(0, m2.m64_u16[0], m2.m64_u16[2], m2.m64_u16[1], 0,
				m2.m64_u16[1], m2.m64_u16[0], m2.m64_u16[2]);
		}
		temp1 = _mm_mullo_epi16(temp1, temp2);
		return sub(*(__m64 const*)temp1.m128i_u64, *(__m64 const*)&temp1.m128i_u64[1]);
	}

	static SIMDType max(const SIMDType& m1, const SIMDType& m2) {
		return _mm_max_pi16(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		return _mm_min_pi16(m1, m2);
	}

	static SIMDType abs(const SIMDType& m) {
		if constexpr (isSigned)
			return _mm_abs_pi16(m);
		else
			return m;
	}
};
#endif

template<typename T, bool isSigned>
struct BestSIMDType<T, 8, 16, true, false, isSigned> {
	using SIMDType = typename __m128i;
	static constexpr I32 alignement = 16;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4, T n5, T n6, T n7, T n8) {
		m = _mm_set_epi16(n8, n7, n6, n5, n4, n3, n2, n1);
	}

	static void set(SIMDType& m, T i) {
		m = _mm_set1_epi16(i);
	}

#if defined(_M_IX86) || defined(__INTEL_COMPILER)
	static void set(SIMDType& m, const __m64& m1, const __m64& m2) {
		m = _mm_set_epi64(m1, m2);
	}
#endif

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
		return _mm_test_all_zeros(_mm_set1_epi16(0xFFFF), m);
	}

	static T horizontalAdd(const SIMDType& m) {
#if defined(_M_IX86) || defined(__INTEL_COMPILER)
		if constexpr (isSigned) {
			__m64 m2 = _mm_hadd_pi16(*(__m64*)(m.m128i_i64), *(__m64*)(m.m128i_i64 + 1));
			m2 = _mm_hadd_pi16(m2, m2);
			_m_empty();
			return m2.m64_i16[0] + m2.m64_i16[1];
		}
		else {
			__m64 m2 = _mm_hadd_pi16(*(__m64*)(m.m128i_u64), *(__m64*)(m.m128i_u64 + 1));
			m2 = _mm_hadd_pi16(m2, m2);
			_m_empty();
			return m2.m64_u16[0] + m2.m64_u16[1];
		}
#else
			__m128i m2 = _mm_hadd_epi16(m, m);
			m2 = _mm_hadd_epi16(m2, m2);
		if constexpr (isSigned)
			return _mm_hadd_epi16(m2, m2).m128i_i16[0];
		else
			return _mm_hadd_epi16(m2, m2).m128i_u16[0];
#endif
	}

#if defined(_M_IX86) || defined(__INTEL_COMPILER)
	static SIMDType broadcast(const __m64& m) {
		SIMDType res = _mm_set1_epi64(m);
		_m_empty();
		return res;
	}
#endif

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
		static_assert(false, "No division allowed on \"I8\\I16\\__m64\" Data Type!!");
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
		if constexpr (isSigned)
			return _mm_sign_epi16(m, _mm_set1_epi16(-1));
		else
			return m;
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
		static_assert(false, "No division allowed on \"I8\\I16\\__m64\" Data Type!!");
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
		if constexpr (isSigned)
			return _mm_max_epi16(m1, m2);
		else
			return _mm_max_epu16(m1, m2);
	}

	static SIMDType min(const SIMDType& m1, const SIMDType& m2) {
		if constexpr (isSigned)
			return _mm_min_epi16(m1, m2);
		else
			return _mm_min_epu16(m1, m2);
	}

	static SIMDType eightHorizontalAdd(const SIMDType& m1, const SIMDType& m2,
		const SIMDType& m3, const SIMDType& m4) {
		return  _mm_hadd_epi16(_mm_hadd_epi16(m1, m2), _mm_hadd_epi16(m3, m4));
	}

	static void transpose(const SIMDType& m1, const SIMDType& m2, SIMDType& m3, SIMDType& m4) {
		if constexpr (isSigned) {
			m3 = _mm_set_epi16(m2.m128i_i16[5], m2.m128i_i16[1], m1.m128i_i16[5], m1.m128i_i16[1],
				m2.m128i_i16[4], m2.m128i_i16[0], m1.m128i_i16[4], m1.m128i_i16[0]);
			m4 = _mm_set_epi16(m2.m128i_i16[7], m2.m128i_i16[3], m1.m128i_i16[7], m1.m128i_i16[3],
				m2.m128i_i16[6], m2.m128i_i16[2], m1.m128i_i16[6], m1.m128i_i16[2]);
		}
		else {
			m3 = _mm_set_epi16(m2.m128i_u16[5], m2.m128i_u16[1], m1.m128i_u16[5], m1.m128i_u16[1],
				m2.m128i_u16[4], m2.m128i_u16[0], m1.m128i_u16[4], m1.m128i_u16[0]);
			m4 = _mm_set_epi16(m2.m128i_u16[7], m2.m128i_u16[3], m1.m128i_u16[7], m1.m128i_u16[3],
				m2.m128i_u16[6], m2.m128i_u16[2], m1.m128i_u16[6], m1.m128i_u16[2]);
		}
	}

	static SIMDType abs(const SIMDType& m) {
		if constexpr (isSigned)
			return _mm_abs_epi16(m);
		else
			return m;
	}

	static SIMDType sign(const SIMDType& m) {
		if constexpr (isSigned) {
			__m256 temp = _mm256_setr_ps(static_cast<F32>(m.m128i_i16[0]), static_cast<F32>(m.m128i_i16[1]),
				static_cast<F32>(m.m128i_i16[2]), static_cast<F32>(m.m128i_i16[3]),
				static_cast<F32>(m.m128i_i16[4]), static_cast<F32>(m.m128i_i16[5]),
				static_cast<F32>(m.m128i_i16[6]), static_cast<F32>(m.m128i_i16[7]));
			temp = _mm256_or_ps(_mm256_and_ps(_mm256_set1_ps(-0.f), temp), _mm256_set1_ps(1.f));
			return _mm_setr_epi16(static_cast<I16>(temp.m256_f32[0]), static_cast<I16>(temp.m256_f32[1]),
				static_cast<I16>(temp.m256_f32[2]), static_cast<I16>(temp.m256_f32[3]),
				static_cast<I16>(temp.m256_f32[4]), static_cast<I16>(temp.m256_f32[5]),
				static_cast<I16>(temp.m256_f32[6]), static_cast<I16>(temp.m256_f32[7]));
		}
		else
			return _mm_set1_epi16(1);
	}
};

template<typename T, bool isSigned>
struct BestSIMDType<T, 8, 32, true, false, isSigned> {
	using SIMDType = typename __m256i;
	static constexpr I32 alignement = 32;

	static void set(SIMDType& m, T n1, T n2, T n3, T n4, T n5, T n6, T n7, T n8) {
		m = _mm256_set_epi32(n8, n7, n6, n5, n4, n3, n2, n1);
	}
	static void set(SIMDType& m, T i) {
		m = _mm256_set1_epi32(i);
	}
	static void set(SIMDType& m, const __m128i& m1, const __m128i& m2) {
		m = _mm256_setr_m128i(m1, m2);
	}

	static SIMDType load(T const* arr) {
		return _mm256_load_si256((SIMDType const*)arr);
	}
	static SIMDType loadu(T const* arr) {
		return _mm256_loadu_si256((SIMDType const*)arr);;
	}

	static SIMDType broadcast(const __m128i& m) {
		return _mm256_broadcastsi128_si256(m);
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
		return _mm256_testz_si256(_mm256_set1_epi32(0xFFFFFFFF), m);
	}
	static T horizontalAdd(const SIMDType& m) {
		__m128i m2 = _mm_hadd_epi32(_mm256_castsi256_si128(m), _mm256_extractf128_si256(m, 1));
		m2 = _mm_hadd_epi32(m2, m2);
		if constexpr(isSigned)
			return m2.m128i_i32[0] + m2.m128i_i32[1];
		else
			return m2.m128i_u32[0] + m2.m128i_u32[1];
	}

	static SIMDType add(const SIMDType& m, const T i) {
		return _mm256_add_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType sub(const SIMDType& m, const T i) {
		return _mm256_sub_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType mul(const SIMDType& m, const T i) {
		return _mm256_mullo_epi32(m, _mm256_set1_epi32(i));
	}
	static SIMDType div(const SIMDType& m, const T i) {
		__m256 temp1, temp2;
		if constexpr (isSigned)
			BestSIMDType<F32, 8>::set(temp1,
				static_cast<F32>(m.m256i_i32[0]), static_cast<F32>(m.m256i_i32[1]),
				static_cast<F32>(m.m256i_i32[2]), static_cast<F32>(m.m256i_i32[3]),
				static_cast<F32>(m.m256i_i32[4]), static_cast<F32>(m.m256i_i32[5]),
				static_cast<F32>(m.m256i_i32[6]), static_cast<F32>(m.m256i_i32[7]));
		else
			BestSIMDType<F32, 8>::set(temp1,
				static_cast<F32>(m.m256i_u32[0]), static_cast<F32>(m.m256i_u32[1]),
				static_cast<F32>(m.m256i_u32[2]), static_cast<F32>(m.m256i_u32[3]),
				static_cast<F32>(m.m256i_u32[4]), static_cast<F32>(m.m256i_u32[5]),
				static_cast<F32>(m.m256i_u32[6]), static_cast<F32>(m.m256i_u32[7]));
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
		return _mm256_mullo_epi32(m1, m2);
	}
	static SIMDType div(const SIMDType& m1, const SIMDType& m2) {
		__m256 temp1, temp2;
		if constexpr (isSigned) {
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
		}
		else {
			BestSIMDType<F32, 8>::set(temp1,
				static_cast<F32>(m1.m256i_u32[0]), static_cast<F32>(m1.m256i_u32[1]),
				static_cast<F32>(m1.m256i_u32[2]), static_cast<F32>(m1.m256i_u32[3]),
				static_cast<F32>(m1.m256i_u32[4]), static_cast<F32>(m1.m256i_u32[5]),
				static_cast<F32>(m1.m256i_u32[6]), static_cast<F32>(m1.m256i_u32[7]));

			BestSIMDType<F32, 8>::set(temp2,
				static_cast<F32>(m2.m256i_u32[0]), static_cast<F32>(m2.m256i_u32[1]),
				static_cast<F32>(m2.m256i_u32[2]), static_cast<F32>(m2.m256i_u32[3]),
				static_cast<F32>(m2.m256i_u32[4]), static_cast<F32>(m2.m256i_u32[5]),
				static_cast<F32>(m2.m256i_u32[6]), static_cast<F32>(m2.m256i_u32[7]));
		}
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

	static __m128i fourHorizontalAdd(const SIMDType& m1, const SIMDType& m2) {
		return  _mm256_permutevar8x32_epi32(_mm256_hadd_epi32(_mm256_hadd_epi32(m1, m2),
			_mm256_hadd_epi32(m3, m4)), _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0));
	}

	static SIMDType eightHorizontalAdd(const SIMDType& m1, const SIMDType& m2,
		const SIMDType& m3, const SIMDType& m4) {
		return  _mm256_permutevar8x32_epi32(_mm256_hadd_epi32(_mm256_hadd_epi32(m1, m2),
			_mm256_hadd_epi32(m3, m4)), _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0));
	}

	static void transpose(SIMDType& m1, SIMDType& m2) {
		m1 = _mm256_permutevar8x32_epi32(m1, _mm256_set_epi32(6, 2, 7, 3, 5, 1, 4, 0));
		m2 = _mm256_permutevar8x32_epi32(m2, _mm256_set_epi32(5, 1, 4, 0, 7, 3, 6, 2));
		SIMDType temp = _mm256_blend_epi32(m1, m2, (0 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7));
		m2 = _mm256_blend_epi32(m2, m1, (0 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7));
		m1 = _mm256_permutevar8x32_epi32(temp, _mm256_set_epi32(7, 6, 3, 2, 5, 4, 1, 0));
		m2 = _mm256_permutevar8x32_epi32(m2, _mm256_set_epi32(3, 2, 5, 4, 1, 0, 7, 6));
	}

	static SIMDType abs(const SIMDType& m) {
		if constexpr (isSigned)
			return _mm256_abs_epi32(m);
		else
			return m;
	}

	static SIMDType sign(const SIMDType& m) {
		if constexpr (isSigned) {
			__m256 temp = _mm256_setr_ps(static_cast<F32>(m.m128i_i32[0]), static_cast<F32>(m.m128i_i32[1]),
				static_cast<F32>(m.m128i_i32[2]), static_cast<F32>(m.m128i_i32[3]),
				static_cast<F32>(m.m128i_i32[4]), static_cast<F32>(m.m128i_i32[5]),
				static_cast<F32>(m.m128i_i32[6]), static_cast<F32>(m.m128i_i32[7]));
			temp = _mm256_or_ps(_mm256_and_ps(_mm256_set1_ps(-0.f), temp), _mm256_set1_ps(1.f));
			return _mm_setr_epi32(static_cast<I32>(temp.m256_f32[0]), static_cast<I32>(temp.m256_f32[1]),
				static_cast<I32>(temp.m256_f32[2]), static_cast<I32>(temp.m256_f32[3]),
				static_cast<I32>(temp.m256_f32[4]), static_cast<I32>(temp.m256_f32[5]),
				static_cast<I32>(temp.m256_f32[6]), static_cast<I32>(temp.m256_f32[7]));
		}
		else
			return _mm_set1_epi32(1);
	}
};

template<typename T>
struct BestSIMDType<T, 8, 32, false, true, true> {
	using SIMDType = typename __m256;
	static constexpr I32 alignement = 32;

	static void set(SIMDType& m, T f1, T f2, T f3, T f4, T f5, T f6, T f7, T f8) {
		m = _mm256_set_ps(f8, f7, f6, f5, f4, f3, f2, f1);
	}

	static void set(SIMDType& m, T f) {
		m = _mm256_set1_ps(f);
	}

	static void set(SIMDType& m, const __m128& m1, T f) {
		m = _mm256_setr_m128(m1, _mm256_set1_ps(f));
	}

	static void set(SIMDType& m, const __m128& m1, const __m128& m2) {
		m = _mm256_setr_m128(m1, m2);
	}

	static SIMDType load(T const* arr) {
		return _mm256_load_ps(arr);
	}

	static SIMDType loadu(T const* arr) {
		return _mm256_loadu_ps(arr);
	}

	static SIMDType broadcast(const __m128& m) {
		return _mm256_broadcast_ps(&m);
	}

	static bool areEqual(const SIMDType& m1, const SIMDType& m2) {
		return isAllZeros(_mm256_xor_ps(m1, m2));
	}

	static bool isGreaterThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_castps_si256(_mm256_cmp_ps(m1, m2, _CMP_GT_OS)));
	}

	static bool isGreaterOrEqThan(const SIMDType& m1, const SIMDType& m2) {
		return !isAllZeros(_mm256_castps_si256(_mm256_cmp_ps(m1, m2, _CMP_GE_OS)));
	}
	static bool isAllZeros(const SIMDType& m) {
		return _mm256_testz_si256(_mm256_set1_epi32(0xFFFFFFFF),
			_mm256_castps_si256(m));
	}

	static T horizontalAdd(const SIMDType& m) {
		__m128 m2 = _mm_hadd_ps(_mm256_castps256_ps128(m), _mm256_extractf128_ps(m, 1));
		m2 = _mm_hadd_ps(m2, m2);
		return m2.m128_f32[0] + m2.m128_f32[1];
	}

	static __m128 fourHorizontalAdd(const SIMDType& m1, const SIMDType& m2) {
		__m256 add1 = _mm256_hadd_ps(m1, m2);
		return  _mm_permutevar_ps(_mm_hadd_ps(_mm256_castps256_ps128(add1),
			_mm256_extractf128_ps(add1, 1)), _mm_set_epi32(3,1,2,0));
	}

	static SIMDType eightHorizontalAdd(const SIMDType& m1, const SIMDType& m2,
		const SIMDType& m3, const SIMDType& m4) {
		return  _mm256_permutevar8x32_ps(_mm256_hadd_ps(_mm256_hadd_ps(m1, m2),
			_mm256_hadd_ps(m3, m4)), _mm256_set_epi32(7, 3, 6, 2, 5, 1, 4, 0));
	}

	static void transpose(SIMDType& m1, SIMDType& m2) {
		m1 = _mm256_permutevar8x32_ps(m1, _mm256_set_epi32(6, 2, 7, 3, 5, 1, 4, 0));
		m2 = _mm256_permutevar8x32_ps(m2, _mm256_set_epi32(5, 1, 4, 0, 7, 3, 6, 2));
		__m256 m3 = _mm256_permutevar8x32_ps(_mm256_blend_ps(m1, m2,
			(0 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7)),
			_mm256_set_epi32(7, 6, 3, 2, 5, 4, 1, 0));
		m2 = _mm256_permutevar8x32_ps(_mm256_blend_ps(m2, m1,
			(0 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7)),
			_mm256_set_epi32(3, 2, 5, 4, 1, 0, 7, 6));

		m1 = m3;
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

	static SIMDType sqrt(const SIMDType& m) {
		return _mm256_sqrt_ps(m);
	}

	static SIMDType abs(const SIMDType& m) {
		return _mm256_andnot_ps(_mm256_set1_ps(-0.f, m));
	}

	static SIMDType sign(const SIMDType& m) {
		return _mm256_or_ps(_mm256_and_ps(_mm256_set1_ps(-0.f), m), _mm256_set1_ps(1.f));
	}
};

template<typename T, U32 nElement>
using BestSIMDType_T = typename BestSIMDType<T, nElement>::type;

} //namespace SIMDUtils