#pragma once

#ifndef QUAT
#define QUAT
#endif // !QUAT

#include <Math/Quaternion.fwd>
#include <Math/Matrix4x4.hpp>

namespace drak {
namespace math {

struct Quaternion {
public:
	inline Quaternion();
	inline Quaternion(const Vec4f& v);
	inline Quaternion(Vec4f&& v);
	inline Quaternion(const F32 scalar, const Vec3f& v);
	inline Quaternion(const F32 scalar, Vec3f&& v);
	inline Quaternion(const Vec3f& euler);
	inline Quaternion(Vec3f&& euler);
	inline Quaternion(const Mat4f& mat);
	inline Quaternion(Mat4f&& mat);
	inline Quaternion(Axis axis, F32 Angle);
	inline Quaternion(const Vec3f& axis, F32 Angle);
	inline Quaternion(Vec3f&& axis, F32 Angle);
	inline Quaternion(const Quaternion& q);
	inline Quaternion(Quaternion&& q);
	inline ~Quaternion() = default;

	inline Quaternion& conjugate();
	inline Quaternion& inverse();
	inline Quaternion& normalize();

	inline float magnitude() const;

	inline Quaternion	operator+	(const F32 f)	const;
	inline Quaternion&	operator+=	(const F32 f);
	inline Quaternion	operator-	(const F32 f)	const;
	inline Quaternion&	operator-=	(const F32 f);
	inline Quaternion	operator*	(const F32 f)	const;
	inline Quaternion&	operator*=	(const F32 f);
	inline Quaternion	operator/	(const F32 f)	const;
	inline Quaternion&	operator/=	(const F32 f);

	inline Quaternion& operator=(const Quaternion& qb);
	inline Quaternion& operator=(Quaternion&& qb);

	inline Mat4f matrix();
	inline Vec3f euler() const;

	inline Vec4f forward();
	inline Vec4f right();
	inline Vec4f up();

public:
	union {
		struct {
			F32 m_scalar;
			Vec3f m_vecPart;
		};
		Vec4f quat;
	};

private:
	template<typename U>
	void fromEuler(U&& u);
	template<typename U>
	void fromMatrix(U&& u);
	template<typename U>
	void fromAxisAndAngle(U&& u, F32 Angle);
};

inline Quaternion operator+(const Quaternion& qa, const Quaternion& qb);

inline Quaternion operator-(const Quaternion& qa, const Quaternion& qb);

inline Quaternion operator*(const Quaternion& qa, const Quaternion& qb);

inline Quaternion& operator+=(Quaternion& qa, const Quaternion& qb);

inline Quaternion& operator-=(Quaternion& qa, const Quaternion& qb);

inline Quaternion& operator*=(Quaternion& qa, const Quaternion& qb);

inline bool operator==(const Quaternion& qa, const Quaternion& qb);

inline bool operator!=(const Quaternion& qa, const Quaternion& qb);

inline bool operator<(const Quaternion& qa, const Quaternion& qb);

inline bool operator<=(const Quaternion& qa, const Quaternion& qb);

inline bool operator>(const Quaternion& qa, const Quaternion& qb);

inline bool operator>=(const Quaternion& qa, const Quaternion& qb);

inline Quaternion Conjugate(const Quaternion& q);

inline Quaternion Inverse(const Quaternion& q);

inline Quaternion Normalize(const Quaternion& q);

inline Mat4f Matrix(const Quaternion& q);

inline Vec3f Rotate(const Quaternion& q, const Vec3f& v);

inline Vec4f Rotate(const Quaternion& q, const Vec4f& v);

inline std::ostream& operator<<(std::ostream& o, const Quaternion& v);

using Quat = Quaternion;

} // namespace math
} // namespace drak
#include <Math/Quaternion.inl>

DK_METADATA_BEGIN(drak::math::Quaternion)
DK_PUBLIC_FIELDS(quat)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END