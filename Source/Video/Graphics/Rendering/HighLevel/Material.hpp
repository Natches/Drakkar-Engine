#pragma once

#include <string>
#include <Core/Engine/Types.hpp>
#include <Math/Vec3.hpp>

namespace drak {
class MaterialManager;
namespace gfx {

class Material final {
public:
	Material() = delete;
	Material(const std::string& name, std::string&& albedo = "", std::string&& normal = "",
		math::Vec3f&& diffuseColor = { 1.f, 1.f, 1.f },
		math::Vec3f&& specularColor = { 1.f, 1.f, 1.f },
		math::Vec3f&& ambientColor = { 0.2f, 0.2f, 0.2f },
		math::Vec3f&& transparentColor = { 0.f, 0.f, 0.f },
		F32 opacity = 1.f, F32 shininess = 0.f, F32 shininessStrength = 1.f,
		bool wireframe = false, bool twoSided = false);
	~Material() = default;

	DK_GETTER_REF_C(std::string, name, m_name)

	using Manager = MaterialManager;

public:
	std::string m_albedo;
	std::string m_normal;
	math::Vec3f m_diffuseColor;
	math::Vec3f m_specularColor;
	math::Vec3f m_ambientColor;
	math::Vec3f m_transparentColor;
	F32 m_opacity;
	F32 m_shininess;
	F32 m_shininessStrength;
	bool m_wireframe;
	bool m_twoSided;

private:
	std::string m_name;
};

} // namespace gfx
} // namespace drak