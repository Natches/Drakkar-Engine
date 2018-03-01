#pragma once

#include<Core/Core.hpp>
#include<mmintrin.h>  //MMX
#include<xmmintrin.h> //SSE
#include<emmintrin.h> //SSE2
#include<pmmintrin.h> //SSE3
#include<tmmintrin.h> //SSSE3
#include<smmintrin.h> //SSE4.1
#include<nmmintrin.h> //SSE4.2
#include<wmmintrin.h> //AES
#include<immintrin.h> //AVX
#include<zmmintrin.h> //AVX512

namespace SIMDUtils {

template<typename T, U32 nElement, U32 size = sizeof(T) * 8,
	bool isIntegral = std::is_integral_v<T>, bool isFloat = std::is_same_v<T, f32>>
struct BestSIMDType {
	using type = NOT_A_TYPE;
};

template<typename T>
struct BestSIMDType<T, 2, 64, true, false> {
	using type = typename __m128i;
};

template<typename T>
struct BestSIMDType<T, 2, 64, false, false> {
	using type = typename __m128d;
};

template<typename T>
struct BestSIMDType<T, 4, 32, false, true> {
	using type = typename __m128;
};

template<typename T>
struct BestSIMDType<T, 4, 32, true, false> {
	using type = typename __m128i;
};

template<typename T>
struct BestSIMDType<T, 8, 16, true, false> {
	using type = typename __m128i;
};

template<typename T>
struct BestSIMDType<T, 4, 64, false, false> {
	using type = typename __m256d;
};

template<typename T>
struct BestSIMDType<T, 4, 64, true, false> {
	using type = typename __m256i;
};

template<typename T>
struct BestSIMDType<T, 8, 32, true, false> {
	using type = typename __m256i;
};

template<typename T>
struct BestSIMDType<T, 8, 32, false, true> {
	using type = typename __m256;
};

template<typename T>
struct BestSIMDType<T, 8, 64, false, false> {
	using type = typename __m512d;
};

template<typename T>
struct BestSIMDType<T, 8, 64, true, false> {
	using type = typename __m512i;
};

template<typename T>
struct BestSIMDType<T, 16, 32, true, false> {
	using type = typename __m512i;
};

template<typename T>
struct BestSIMDType<T, 16, 32, false, true> {
	using type = typename __m512;
};

template<typename T, U32 nElement>
using BestSIMDType_T = typename BestSIMDType<T, nElement>::type;

} //namespace SIMDUtils