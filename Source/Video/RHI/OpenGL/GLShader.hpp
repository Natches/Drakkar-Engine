#pragma once

#include <unordered_map>
#include <vector>

#include <Video/RHI/OpenGL/GLTypes.hpp>

namespace drak {
namespace video {
namespace gl {

class GLShader final
{
	using UniformMap = std::unordered_map<std::string, GLint>;

public:
	//GLShader();
	//~GLShader();

	bool loadFromFile(
		const std::string& vertFilename,
		const std::string& fragFilename);

	//static void Use(GLShader* const pShader);

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
