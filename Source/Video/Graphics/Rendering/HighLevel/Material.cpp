#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {

Material::Material(const std::string& name, std::string&& albedo,
	std::string&& normal, math::Vec3f&& diffuseColor,
	math::Vec3f&& specularColor, math::Vec3f&& ambientColor,
	math::Vec3f&& transparentColor, F32 opacity, F32 shininess,
	F32 shininessStrength, bool wireframe, bool twoSided)
:	m_name(name), albedo(std::move(albedo)), normal(std::move(normal)),
diffuseColor(std::move(diffuseColor)), specularColor(std::move(specularColor)),
ambientColor(std::move(ambientColor)), transparentColor(std::move(transparentColor)),
opacity(opacity), shininess(shininess), shininessStrength(shininessStrength),
wireframe(wireframe), twoSided(twoSided) {

}

} //namespace gfx
} //namespace drak