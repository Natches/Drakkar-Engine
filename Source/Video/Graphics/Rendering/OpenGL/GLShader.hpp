#pragma once

#include <unordered_map>
#include <vector>

#include <Video/Graphics/Rendering/Base/IShader.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>

namespace drak {
namespace gfx {
namespace gl {

/*!
* \class GLShader
* \ingroup Graphics
* \brief
*
*/
class GLShader final : public GLObject, public IShader {
	using UniformMap = std::unordered_map<std::string, GLint>;
public:
	GLShader();
	~GLShader();

	void use() const override;

	bool loadFromData(
		const std::string& vertCode, 
		const std::string& fragCode) override;
	bool loadFromFile(
		const std::string& vertFilename, 
		const std::string& fragFilename) override;

	void setUniform(const std::string& name, F32 value) override;
	void setUniform(const std::string& name, I32 value) override;
	void setUniform(const std::string& name, U32 value) override;

	void setUniform(const std::string& name, const math::Vec2f& v2) override;
	void setUniform(const std::string& name, const math::Vec3f& v3) override;
	void setUniform(const std::string& name, const math::Vec4f& v4) override;
	void setUniform(const std::string& name, const math::Mat4f& matrix) override;

private:
	bool readFileText(const std::string& filename, std::vector<char>& text);
	bool compileProgram(const char* vertCode, const char* fragCode);
	bool compileShader(GLuint shaderID, const char* code);

private:
	UniformMap	m_uniMap;
};

} // namespace gl
} // namespace gfx
} // namespace drak
