#pragma once

#include <string>
#include <Core/Engine/Types.hpp>
#include <Math/Vec3.hpp>

namespace drak {
template<typename T>
class Resource;
class MaterialManager;
namespace gfx {

class Material final {
	friend class Resource<Material>;
public:
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
	std::string		albedo;
	std::string		normal;
	math::Vec3f		diffuseColor;
	math::Vec3f		specularColor;
	math::Vec3f		ambientColor;
	math::Vec3f		transparentColor;
	F32				opacity;
	F32				shininess;
	F32				shininessStrength;
	bool			wireframe;
	bool			twoSided;
	bool			instantiated;

private:
	Material() = default;

private:
	std::string m_name;
};

} // namespace gfx
} // namespace drak