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
class GLShader : public GLObject, public IShader {
	using UniformMap = std::unordered_map<std::string, GLint>;
public:
	GLShader() = default;
	virtual ~GLShader();

	void use() const override;

	bool loadFromData(const std::string& vertCode, const std::string& fragCode) override;
	bool loadFromFile(const std::string& vertPath, const std::string& fragPath) override;

	void uniform(const std::string& name, F32 value) override;
	void uniform(const std::string& name, I32 value) override;
	void uniform(const std::string& name, U32 value) override;
		 
	void uniform(const std::string& name, const math::Vec2f& v2) override;
	void uniform(const std::string& name, const math::Vec3f& v3) override;
	void uniform(const std::string& name, const math::Vec4f& v4) override;
	void uniform(const std::string& name, const math::Mat4f& matrix) override;

protected:
	bool readFileText(const std::string& path, std::vector<GLchar>& outText);
	bool compileShader(GLuint shaderID, const GLchar* code);
	bool compileProgram(const GLchar* vertCode, const GLchar* fragCode);
	void destroyProgram();

	bool checkLink(GLuint progID);
	bool checkCompile(GLuint shaderID);

protected:
	UniformMap	m_uniMap;
};

} // namespace gl
} // namespace gfx
} // namespace drak
