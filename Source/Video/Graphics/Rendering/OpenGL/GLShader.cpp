#include <PrecompiledHeader/pch.hpp>

#define INVALID_SHADER (GLuint)-1

using namespace drak::math;

namespace drak {
namespace gfx {
namespace gl {

GLShader::GLShader() {
	m_glID = INVALID_SHADER;
}

GLShader::~GLShader() {
	if (m_glID)
		glDeleteProgram(m_glID);
}

void GLShader::use() const {
	assert(m_glID != INVALID_SHADER);
	glUseProgram(m_glID);
}

bool GLShader::loadFromData(const std::string& vertCode, const std::string& fragCode) {
	return compileProgram(vertCode.c_str(), fragCode.c_str());
}

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

	I32 linked;
	glGetProgramiv(m_glID, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		I32 maxLength = 0;
		glGetProgramiv(m_glID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(m_glID, maxLength, nullptr, errorLog.data());
		glDeleteProgram(m_glID);

		std::cout << errorLog.data() << std::endl;
		system("pause");
		return false;
	}
	return true;
}

bool GLShader::compileShader(GLuint shaderID, const char* GLShaderCode) {
	I32 compiled = 0;

	glShaderSource(shaderID, 1, &GLShaderCode, nullptr);
	glCompileShader(shaderID);
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

	if (compiled == GL_FALSE) {
		I32 maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<char> errorLog(maxLength);
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

void GLShader::uniform(const std::string& name, F32 value) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1f(m_glID, m_uniMap[name], value);
}

void GLShader::uniform(const std::string& name, I32 value) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1i(m_glID, m_uniMap[name], value);
}

void GLShader::uniform(const std::string& name, U32 value) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform1ui(m_glID, m_uniMap[name], value);
}

void GLShader::uniform(const std::string& name, const math::Vec2f& v2) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform2fv(m_glID, m_uniMap[name], 1, &v2.x);
}

void GLShader::uniform(const std::string& name, const math::Vec3f& v3) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform3fv(m_glID, m_uniMap[name], 1, &v3.x);
}

void GLShader::uniform(const std::string& name, const math::Vec4f& v4) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniform4fv(m_glID, m_uniMap[name], 1, &v4.x);
}

void GLShader::uniform(const std::string& name, const math::Mat4f& matrix) {
	if (m_uniMap.find(name) == m_uniMap.end())
		m_uniMap[name] = glGetUniformLocation(m_glID, name.c_str());
	glProgramUniformMatrix4fv(m_glID, m_uniMap[name], 1, GL_TRUE, matrix.m_mat);
}

} // namespace gl
} // namespace gfx
} // namespace drak