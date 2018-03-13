#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <Video/RHI/OpenGL/GLShader.hpp>

#define INVALID_SHADER (U32)-1

namespace drak {
namespace video {
namespace gl {
/*
void GLShader::Use(GLShader* const pShader) {
	if (pShader && pShader->m_glID != INVALID_SHADER)
	{
		glUseProgram(pShader->m_glID);
	}
	else
	{
		//assert(g_DefaultProgram);
		glUseProgram(g_DefaultProgram->m_glID);
	}
}
*/

bool GLShader::loadFromFile(const std::string& vertFilename, const std::string& fragFilename) {
	std::vector<char> vertCode;
	if (!readFileText(vertFilename, vertCode))
		return false;

	std::vector<char> fragCode;
	if (!readFileText(fragFilename, fragCode))
		return false;

	return compileProgram(vertCode.data(), fragCode.data());
}

bool GLShader::compileProgram(const char* vertCode, const char* fragCode)
{
	if (vertCode == nullptr || fragCode == nullptr)
		return false;

	m_glID = glCreateProgram();

	GLuint vsID = glCreateShader(GL_VERTEX_SHADER);
	if (!compileShader(vsID, vertCode))
		return false;

	GLuint fsID = glCreateShader(GL_FRAGMENT_SHADER);
	if (!compileShader(fsID, fragCode))
		return false;

	glAttachShader(m_glID, vsID);
	glAttachShader(m_glID, fsID);
	glLinkProgram(m_glID);
	glDeleteShader(vsID);
	glDeleteShader(fsID);

	int linked;
	glGetProgramiv(m_glID, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(m_glID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetProgramInfoLog(m_glID, maxLength, nullptr, errorLog.data());
		glDeleteProgram(m_glID);

		std::cout << errorLog.data() << std::endl;
		system("pause");
		return false;
	}
	return true;
}

bool GLShader::compileShader(GLuint shaderID, const char* GLShaderCode) {
	GLint compiled = 0;

	glShaderSource(shaderID, 1, &GLShaderCode, nullptr);
	glCompileShader(shaderID);
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

	if (compiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, nullptr, errorLog.data());
		glDeleteShader(shaderID);

		std::cout << errorLog.data() << std::endl;
		system("pause");
		return false;
	}
	return true;
}

bool GLShader::readFileText(const std::string& filename, std::vector<char>& text) {
	std::ifstream file(filename.c_str());
	if (file) {
		file.seekg(0, std::ios_base::end);
		std::streamsize size = file.tellg();
		if (size > 0) {
			file.seekg(0, std::ios_base::beg);
			text.resize(static_cast<std::size_t>(size));
			file.read(&text[0], size);
		}
		text.push_back('\0');
		return true;
	}
	else {
		std::cout << ("ERROR: Couldn't read " + filename).c_str() << std::endl;
		return false;
	}
}

void GLShader::setUniform(const std::string& name, GLfloat value)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1f(m_glID, m_uniMap[name], value);
}

void GLShader::setUniform(const std::string& name, GLint value)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1i(m_glID, m_uniMap[name], value);
}

void GLShader::setUniform(const std::string& name, GLuint value)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1ui(m_glID, m_uniMap[name], value);
}

/*
void GLShader::setUniform(const std::string& name, const glm::vec3& v3)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform3fv(m_glID, m_uniMap[name], 1u, &v3.x);
}

void GLShader::setUniform(const std::string& name, const glm::vec4& v4)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform3fv(m_glID, m_uniMap[name], 1u, &v4.x);
}

void GLShader::setUniform(const std::string& name, const glm::mat4& matrix)
{
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniformMatrix4fv(m_glID, m_uniMap[name], 1u, GL_FALSE, &matrix[0][0]);
}
*/

} // namespace gl
} // namespace gfx
} // namespace drak