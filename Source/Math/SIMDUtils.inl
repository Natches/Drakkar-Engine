#include<Math/SIMDUtils.hpp>

namespace SIMDUtils {

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