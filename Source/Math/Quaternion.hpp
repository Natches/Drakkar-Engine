#pragma once

#include <Math/Matrix4x4.hpp>

namespace drak {
namespace math {

template<typename T>
class Quaternion<T> {
	static_assert(std::is_scalar_v<T> && (sizeof(T) * 8 < 64),
		"\"T\" must be a scalar signed Type and not a 64 bits Data Type");
public:
	Quaternion();
	explicit Quaternion(const Vec4<T>& v);
	explicit Quaternion(const T scalar, const Vec3<T>& v);
	explicit Quaternion(Vec4<T>&& v);
	explicit Quaternion(const T scalar, Vec3<T>&& v);
	explicit Quaternion(const Vec3<T>& euler);
	Quaternion(const Quaternion& q);
	Quaternion(Quaternion&& q);
	~Quaternion() = default;

	T scalar() const;
	Vec3<T> vector() const;

	Quaternion conjugate()  const;
	float      magnitude()  const;
	Quaternion inverse()    const;
	Quaternion normalize()	const;

	Quaternion		operator+	(const T f)	const;
	Quaternion&		operator+=	(const T f);
	Quaternion		operator-	(const T f)	const;
	Quaternion&		operator-=	(const T f);
	Quaternion		operator*	(const T f)	const;
	Quaternion&		operator*=	(const T f);
	Quaternion		operator/	(const T f)	const;
	Quaternion&		operator/=	(const T f);

	Matrix4x4<T> matrix() const;
	Vec3<T> euler() const;

	template<typename U>
	Quaternion<U> cast();

private:
	Vec3<T> m_vecPart;
	T m_scalar;
};

template<typename T>
Quaternion<T> operator+(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T> operator-(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T> operator*(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T> operator/(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator+=(Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator-=(Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator*=(Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator/=(Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator=(Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Quaternion<T>& operator=(Quaternion<T>& qa, Quaternion<T>&& qb);

template<typename T>
bool operator==(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
bool operator!=(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
bool operator<(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
bool operator<=(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
bool operator>(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
bool operator>=(const Quaternion<T>& qa, const Quaternion<T>& qb);

template<typename T>
Vec3<T> Rotate(const Quaternion<T>& q, const Vec3& v);

template<typename T>
Vec4<T> Rotate(const Quaternion<T>& q, const Vec4& v);

} // namespace math
} // namespace drak