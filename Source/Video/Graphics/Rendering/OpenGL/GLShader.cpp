#include <PrecompiledHeader/pch.hpp>

using namespace drak::math;

namespace drak {
namespace gfx {
namespace gl {

GLShader::~GLShader() {
	destroyProgram();
}

void GLShader::destroyProgram() {
	if (m_glID != GL_INVALID)
		glDeleteProgram(m_glID);
}

void GLShader::use() const {
	assert(m_glID != GL_INVALID);
	glUseProgram(m_glID);
}

bool GLShader::loadFromData(const std::string& vertCode, const std::string& fragCode) {
	return compileProgram(vertCode.c_str(), fragCode.c_str());
}

bool GLShader::loadFromFile(const std::string& vertPath, const std::string& fragPath) {
	std::vector<GLchar> vertCode;
	if (!readFileText(vertPath, vertCode))
		return false;

	std::vector<GLchar> fragCode;
	if (!readFileText(fragPath, fragCode))
		return false;

	return compileProgram(vertCode.data(), fragCode.data());
}

bool GLShader::compileProgram(const GLchar* vertCode, const GLchar* fragCode) {
	if (vertCode == nullptr || fragCode == nullptr)
		return false;

	// don't overwrite m_glID unless 'new' program links well (see func. end)
	GLuint progID = glCreateProgram();

	GLuint vertID = glCreateShader(GL_VERTEX_SHADER);
	if (!compileShader(vertID, vertCode))
		return false;

	GLuint fragID = glCreateShader(GL_FRAGMENT_SHADER);
	if (!compileShader(fragID, fragCode))
		return false;

	glAttachShader	(progID, vertID);
	glAttachShader	(progID, fragID);
	glLinkProgram	(progID);
	glDeleteShader	(vertID);
	glDeleteShader	(progID);

	if (checkLink(progID)) {
		// successful load/reload -> replace 'old' program
		destroyProgram();
		m_glID = progID;
		return true;
	}

	// failed load/reload -> keep 'old' program
	glDeleteProgram(progID);
	return false;
}

bool GLShader::compileShader(GLuint shaderID, const GLchar* code) {
	glShaderSource(shaderID, 1, &code, nullptr);
	glCompileShader(shaderID);

	if (checkCompile(shaderID))
		return true;

	glDeleteShader(shaderID);
	return true;
}

bool GLShader::checkLink(GLuint progID) {
	GLint linked;
	glGetProgramiv(progID, GL_LINK_STATUS, &linked);

	if (linked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(m_glID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetProgramInfoLog(m_glID, maxLength, nullptr, errorLog.data());
		std::cout << errorLog.data() << '\n';
		return false;
	}
	return true;
}

bool GLShader::checkCompile(GLuint shaderID) {
	GLint compiled = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);

	if (compiled == GL_FALSE) {
		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, nullptr, errorLog.data());
		std::cout << errorLog.data() << '\n';
		return false;
	}
	return true;
}

bool GLShader::readFileText(const std::string& filename, std::vector<GLchar>& outText) {
	std::ifstream file(filename.c_str());
	if (file) {
		file.seekg(0, std::ios_base::end);
		std::streamsize size = file.tellg();
		if (size > 0) {
			file.seekg(0, std::ios_base::beg);
			outText.resize(static_cast<std::size_t>(size));
			file.read(&outText[0], size);
		}
		outText.push_back('\0');
		return true;
	}
	else {
		std::cout << ("ERROR: Couldn't read " + filename).c_str() << '\n';
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