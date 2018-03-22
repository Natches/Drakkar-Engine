#pragma once

#include <Core/Utils/AComponentUtils.hpp>
#include <Math/Vec3.hpp>
#include <Math/Matrix4x4.hpp>

namespace drak {
namespace video {

class Camera final {
public:
	Camera();
	~Camera();

	const math::Mat4f& lookAt(const math::Vec3f& eye, const math::Vec3f& at, const math::Vec3f& up);
	const math::Mat4f& perspective(F32 fov, F32 aspect, F32 nearZ, F32 farZ);
	const math::Mat4f& orthographic(F32 width, F32 height, F32 nearZ, F32 farZ);

	DK_GETTER(math::Mat4f, viewPerspective, buildViewPerspective())

private:
	void buildView();
	void buildPerspective();
	void buildOrthographic();

	inline math::Mat4f buildViewPerspective() { return m_prsp * m_view; }

private:
	math::Mat4f		m_view;
	math::Mat4f 	m_prsp;
	math::Mat4f		m_ortho;
	
	math::Vec3f 	m_eye;
	math::Vec3f 	m_at;
	math::Vec3f 	m_up;
	math::Vec3f		m_direction;
	
	F32 			m_fov;
	F32				m_aspect;
	F32 			m_nearZ;
	F32 			m_farZ;
	F32				m_inv_fsubn;
	
	F32				m_orthoR;
	F32				m_orthoH;
};

} // namespace video 
} // namespace drak
