#include <Video/Graphics/Camera.hpp>

using namespace drak::math;

namespace drak {
namespace video {

Camera::Camera()
{
}

Camera::~Camera()
{
}

#pragma region View Matrix
const Mat4f& Camera::lookAt(
	const math::Vec3f& eye, 
	const math::Vec3f& at, 
	const math::Vec3f& up) {

	m_eye	= eye;
	m_at	= at;
	m_up	= up;

	buildView();
	return m_view;
}

void Camera::buildView() {
	Vec3f zc = (m_eye - m_at).normalize();
	Vec3f xc = Cross(m_up, zc).normalize();
	Vec3f yc = Cross(zc, xc);

	m_view = Mat4f(
		xc.x,
		xc.y,
		xc.z,
		Dot(-m_eye, xc),   
		yc.x,			   
		yc.y,			  
		yc.z,		
		Dot(-m_eye, yc),
		zc.x,			   
		zc.y,		
		zc.z,
		Dot(-m_eye, zc),
		0.f,		   
		0.f, 
		0.f,
		1.f
	);
}
#pragma endregion

#pragma region Perspective Projection
const Mat4f& Camera::perspective(F32 fov, F32 aspect, F32 nearZ, F32 farZ) {
	m_fov			= fov;
	m_aspect		= aspect;
	m_nearZ			= nearZ;
	m_farZ			= farZ;
	m_inv_fsubn		= -1.f / (m_farZ - m_nearZ);

	buildPerspective();
	return m_prsp;
}

void Camera::buildPerspective() {
	F32 inv_tan = 1.f / tan(ToRadian(m_fov * 0.5f));

	m_prsp = Mat4f(
		inv_tan / m_aspect,
		0.f,		
		0.f,									
		0.f,
		0.f,					
		inv_tan,
		0.f,									
		0.f,
		0.f,					
		0.f,		
		m_inv_fsubn * (m_farZ + m_nearZ),
		m_inv_fsubn * m_farZ * m_nearZ * 2.f,
		0.f,					
		0.f,		
		-1.f,
		0.f
	);
}
#pragma endregion

#pragma region Orthographic Projection
const Mat4f& Camera::orthographic(F32 width, F32 height, F32 nearZ, F32 farZ) {
	m_orthoR		= width  * 0.5f;
	m_orthoH		= height * 0.5f;
	m_nearZ			= nearZ;
	m_farZ			= farZ;
	m_inv_fsubn		= -1.f / (m_farZ - m_nearZ);

	buildOrthographic();
	return m_ortho;
}

void Camera::buildOrthographic() {
	m_ortho = Mat4f(
		1.f / m_orthoR,	
		0.f,
		0.f,
		0.f,
		0.f,
		1.f / m_orthoH,
		0.f,
		0.f,
		0.f,
		0.f,
		m_inv_fsubn * 2.f, 
		0.f,
		0.f,
		0.f,
		m_inv_fsubn * (m_farZ + m_nearZ),
		1.f
	);
}
#pragma endregion

} // namespace video
} // namespace drak