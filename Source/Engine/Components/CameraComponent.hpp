#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Serialization\MetaData.hpp>
#include <Math/Vec3.hpp>
#include <Math/Matrix4x4.hpp>
DRAK_COMPONENT_START(CameraComponent)
DK_SERIALIZED_OBJECT(CameraComponent)
math::Mat4f		m_view;
math::Mat4f 	m_prsp;
math::Mat4f		m_ortho;

math::Vec3f 	m_eye;
math::Vec3f 	m_at;
math::Vec3f 	m_up;
math::Vec3f		m_direction;

F32 			m_fov;
F32				m_tanHalfFov;
F32				m_aspect;
F32 			m_nearZ;
F32 			m_farZ;
F32				m_inv_fsubn;

F32				m_orthoR;
F32				m_orthoH;
DRAK_API static void BuildView(CameraComponent& camera);
DRAK_API static void BuildPerspective(CameraComponent& camera);
DRAK_COMPONENT_END(CameraComponent)

DK_METADATA_BEGIN(drak::components::CameraComponent)
DK_PUBLIC_FIELDS(m_view, m_prsp, m_ortho, m_eye, m_at, m_up, m_direction, m_fov, m_tanHalfFov, m_aspect, m_nearZ, m_farZ, m_inv_fsubn, m_orthoR, m_orthoH)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END