#include <IniLoader/IniFile.hpp>
#include <stdexcept>
#include <cassert>
#include <string>
template<>
inline int IniFile::GetValue<int>(const char * parameterName) {
	if (parameters.find(parameterName) != parameters.end()) {
		return std::stoi(parameters[parameterName]);
	}
	assert(false);
	return 0;
}

template<>
inline float IniFile::GetValue<float>(const char * parameterName) {
	if (parameters.find(parameterName) != parameters.end()) {
		return std::stof(parameters[parameterName]);
	}
	assert(false);
	return 0.f;
}

template<>
inline std::string IniFile::GetValue <std::string>(const char * parameterName) {
	if (parameters.find(parameterName) != parameters.end()) {
		return std::string(parameters[parameterName]);
	}
	assert(false);
	return "";
}

template<>
inline long IniFile::GetValue <long>(const char * parameterName) {
	if (parameters.find(parameterName) != parameters.end()) {
		return std::stol(parameters[parameterName]);
	}
	assert(false);
	return 0l;
}

template<>
inline double IniFile::GetValue <double>(const char * parameterName) {
	if (parameters.find(parameterName) != parameters.end()) {
		return std::stod(parameters[parameterName]);
	}
	assert(false);
	return 0.0;
}