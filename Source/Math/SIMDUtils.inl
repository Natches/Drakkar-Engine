#include<Math/SIMDUtils.hpp>

namespace SIMDUtils {

template<typename T, U32 nElement, U32 size = sizeof(T) * 8,
	bool isIntegral = std::is_integral_v<T>, bool isF32 = std::is_same_v<T, F32>>
constexpr I32 BestSIMDType<T, nElement, size, isIntegral, isF32>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 4, 32, false, true>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 4, 32, true, false>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 4, 16, true, false>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 8, 16, true, false>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 8, 32, true, false>::alignement;

template<typename T>
constexpr I32 BestSIMDType<T, 8, 32, false, true>::alignement;

}