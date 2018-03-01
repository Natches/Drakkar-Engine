#pragma once
#pragma once

#include <type_traits>
#include "types.hpp"
#include "Warning.h"

extern "C++" {
	namespace drakMaths {
		template<typename T>
		struct Vec4 {

#define x m_pVec[0]
#define y m_pVec[1]
#define z m_pVec[2]
#define w m_pVec[3]

			static_assert(std::is_scalar_v<T>, "\"T\" must be a scalar Type");

		public:
			enum class Axis {
				X,
				Y,
				Z
			};

		public:
			Vec4();
			explicit Vec4(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) X,
				const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) Y,
				const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) Z,
				const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) W);

			explicit Vec4(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) X,
				ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) Y,
				ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) Z,
				ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) W);

			Vec4(const Vec4<T>& v);
			Vec4(Vec4<T>&& v);
			~Vec4() = default;

		public:
			bool operator==(const Vec4<T>& v) const;
			bool operator!=(const Vec4<T>& v) const;
			bool operator>(const Vec4<T>& v)  const;
			bool operator<(const Vec4<T>& v)  const;
			bool operator>=(const Vec4<T>& v) const;
			bool operator<=(const Vec4<T>& v) const;

			bool isNormalized(const Vec4<T>& v) const;
			bool isNull(const Vec4<T>& v) const;

			float magnitude() const;
			float angle(const Axis& axis) const;

			Vec4<T>& conjugate();
			Vec4<T>& normalize();
			Vec4<T>& rotate(const Axis& axis, f32 angle);

			Vec4<T>& operator=(const Vec4<T>& v);
			Vec4<T>& operator=(Vec4<T>&& v);
			Vec4<T>& operator+=(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n);
			Vec4<T>& operator-=(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n);
			Vec4<T>& operator*=(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n);
			Vec4<T>& operator/=(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n);
			Vec4<T>& operator+=(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n);
			Vec4<T>& operator-=(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n);
			Vec4<T>& operator*=(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n);
			Vec4<T>& operator/=(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n);
			Vec4<T>& operator>>=(const std::enable_if_t<std::is_integral_v<T>, T> n);
			Vec4<T>& operator<<=(const std::enable_if_t<std::is_integral_v<T>, T> n);
			Vec4<T>& operator&=(const std::enable_if_t<std::is_integral_v<T>, T> n);
			Vec4<T>& operator^=(const std::enable_if_t<std::is_integral_v<T>, T> n);
			Vec4<T>& operator|=(const std::enable_if_t<std::is_integral_v<T>, T> n);
			Vec4<T>& operator++();
			Vec4<T>& operator--();

			Vec4<T> operator+(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n) const;
			Vec4<T> operator-(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n) const;
			Vec4<T> operator*(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n) const;
			Vec4<T> operator/(const ADD_REF_IF_T(IS_LARGER_THAN_V(T, T*), T) n) const;
			Vec4<T> operator+(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n) const;
			Vec4<T> operator-(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n) const;
			Vec4<T> operator*(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n) const;
			Vec4<T> operator/(ENABLE_IF_ELSE_T(IS_LARGER_THAN_V(T, T*), T&&, NOT_A_TYPE) n) const;
			Vec4<T> operator>>(const std::enable_if_t<std::is_integral_v<T>, T> n)const;
			Vec4<T> operator<<(const std::enable_if_t<std::is_integral_v<T>, T> n)const;
			Vec4<T> operator&(const std::enable_if_t<std::is_integral_v<T>, T> n) const;
			Vec4<T> operator^(const std::enable_if_t<std::is_integral_v<T>, T> n) const;
			Vec4<T> operator|(const std::enable_if_t<std::is_integral_v<T>, T> n) const;
			Vec4<T> operator++(const int32) const;
			Vec4<T> operator--(const int32) const;
			Vec4<T> operator-()	  const;

			float* vec() const;

			template<typename U>
			Vec4<U> cast() const;

		public:
			T m_pVec[4];
		};

		template<typename T>
		float dot(const Vec4<T>& v1, const Vec4<T>& v2);

		template<typename T>
		Vec4<T> cross(const Vec4<T>& v1, const Vec4<T>& v2);

		template<typename T>
		float distance(const Vec4<T>& v1, const Vec4<T>& v2);

		template<typename T>
		Vec4<T> direction(const Vec4<T>& origin, const Vec4<T>& destination);

		template<typename T>
		void rotateAround(const Vec4<T>& v1, const Vec4<T>& point, const typename Vec4<T>::Axis& axis, const f32 angle);

		template<typename T>
		bool arePerpendicular(const Vec4<T>& v1, const Vec4<T>& v2);

		template<typename T>
		bool areColinear(const Vec4<T>& v1, const Vec4<T>& v2);

		template<typename T>
		bool areOpposed(const Vec4<T>& v1, const Vec4<T>& v2);

		using Vec4c = typename Vec4<uint8>;
		using Vec4sc = typename Vec4<int8>;
		using Vec4si = typename Vec4<int16>;
		using Vec4sui = typename Vec4<uint16>;
		using Vec4i = typename Vec4<int32>;
		using Vec4ui = typename Vec4<uint32>;
		using Vec4lli = typename Vec4<int64>;
		using Vec4ulli = typename Vec4<uint64>;
		using Vec4f = typename Vec4<f32>;
		using Vec4d = typename Vec4<f64>;
		using Vec4ld = typename Vec4<d81>;
	}
#include "Vec4.inl"
}
