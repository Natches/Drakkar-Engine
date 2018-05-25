#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {

Material::Material(const std::string& name, std::string&& albedo,
	std::string&& normal, math::Vec3f&& diffuseColor,
	math::Vec3f&& specularColor, math::Vec3f&& ambientColor,
	math::Vec3f&& transparentColor, F32 opacity, F32 shininess,
	F32 shininessStrength, bool wireframe, bool twoSided)
:	m_name(name), m_albedo(std::move(albedo)), m_normal(std::move(m_normal)),
m_diffuseColor(std::move(diffuseColor)), m_specularColor(std::move(specularColor)),
m_ambientColor(std::move(ambientColor)), m_transparentColor(std::move(transparentColor)),
m_opacity(opacity), m_shininess(shininess), m_shininessStrength(shininessStrength),
m_wireframe(wireframe), m_twoSided(twoSided) {

}

} //namespace gfx
} //namespace drak