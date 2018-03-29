#pragma once

#include <unordered_map>
#include <vector>

#include <Video/Graphics/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

/*!
* \class GLShader
* \ingroup DrakVideo
* \brief
*
*/
class GLShader
{
	using UniformMap = std::unordered_map<std::string, GLint>;

public:
	GLShader() = default;
	virtual ~GLShader();

	bool loadFromData(const std::string& vertCode, const std::string& fragCode);
	bool loadFromFile(const std::string& vertFilename, const std::string& fragFilename);

	void use();

	void setUniform(const std::string& name, GLfloat value);
	void setUniform(const std::string& name, GLint value);
	void setUniform(const std::string& name, GLuint value);

	//void setUniform(const std::string& name, const glm::vec3& v3);
	//void setUniform(const std::string& name, const glm::vec4& v4);
	//void setUniform(const std::string& name, const glm::mat4& matrix);

private:
	bool readFileText(const std::string& filename, std::vector<char>& text);
	bool compileProgram(const char* vertCode, const char* fragCode);
	bool compileShader(GLuint shaderID, const char* code);

private:
	UniformMap	m_uniMap;
	GLuint		m_glID;
};

} // namespace gl
} // namespace gfx
} // namespace drak
