#include "PrecompiledHeader/pch.hpp"
#include "CameraComponent.hpp"
using namespace drak;
using namespace core;
using namespace math;
using namespace components;

void CameraComponent::BuildView(CameraComponent& camera) {
	Vec3f zc = (CurrentLevel.m_gameObjects[camera.GameObjectID].getComponent<Transform>().position - camera.m_at).normalize();
	Vec3f xc = Cross(camera.m_up, zc).normalize();
	Vec3f yc = Cross(zc, xc);

	camera.m_view = Mat4f(
		xc.x,
		xc.y,
		xc.z,
		Dot(-camera.m_eye, xc),
		yc.x,
		yc.y,
		yc.z,
		Dot(-camera.m_eye, yc),
		zc.x,
		zc.y,
		zc.z,
		Dot(-camera.m_eye, zc),
		0.f,
		0.f,
		0.f,
		1.f
	);
}

void CameraComponent::BuildPerspective(CameraComponent & camera) {
	camera.m_inv_fsubn = -1.f / (camera.m_farZ - camera.m_nearZ);
	camera.m_tanHalfFov = tan(ToRadian(camera.m_fov * 0.5f));
	F32 inv_tan = 1.f / camera.m_tanHalfFov;

	camera.m_prsp = Mat4f(
		inv_tan / camera.m_aspect,
		0.f,
		0.f,
		0.f,
		0.f,
		inv_tan,
		0.f,
		0.f,
		0.f,
		0.f,
		camera.m_inv_fsubn * (camera.m_farZ + camera.m_nearZ),
		camera.m_inv_fsubn * (camera.m_farZ * camera.m_nearZ) * 2.f,
		0.f,
		0.f,
		-1.f,
		0.f
	);
}
