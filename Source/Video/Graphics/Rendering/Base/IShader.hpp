#pragma once

namespace drak {
class ShaderManager;
namespace gfx {

/*!
* \class IShader
* \ingroup Graphics
* \brief
*
*/
class IShader {
public:

	IShader() = default;
	virtual ~IShader() = default;

	using Manager = ShaderManager;

	virtual void use() const = 0;

	virtual bool loadFromData(const std::string& vertCode, const std::string& fragCode) = 0;
	virtual bool loadFromFile(const std::string& vertPath, const std::string& fragPath) = 0;

	virtual void uniform(const std::string& name, F32 value) = 0;
	virtual void uniform(const std::string& name, I32 value) = 0;
	virtual void uniform(const std::string& name, U32 value) = 0;

	virtual void uniform(const std::string& name, const math::Vec2f& v2) = 0;
	virtual void uniform(const std::string& name, const math::Vec3f& v3) = 0;
	virtual void uniform(const std::string& name, const math::Vec4f& v4) = 0;
	virtual void uniform(const std::string& name, const math::Mat4f& matrix) = 0;
};

using ShaderMap = std::unordered_map<std::string, IShader*>;

} // namespace gfx
} // namespace drak
