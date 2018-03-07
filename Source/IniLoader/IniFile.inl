#include "IniFile.h"
#include <stdexcept>
#include <cassert>
#include <string>
template<>
inline int IniFile::GetValue<int>(const char * parameterName)
{
	if (parameters.find(parameterName) != parameters.end())
	{
		return std::stoi(parameters[parameterName]);
	}
	assert(false);
}

template<>
inline float IniFile::GetValue<float>(const char * parameterName)
{
	if (parameters.find(parameterName) != parameters.end())
	{
		return std::stof(parameters[parameterName]);
	}
	assert(false);
}

template<>
inline std::string IniFile::GetValue <std::string> (const char * parameterName)
{
	if (parameters.find(parameterName) != parameters.end())
	{
		return std::string(parameters[parameterName]);
	}
	assert(false);
}

template<>
inline long IniFile::GetValue <long>(const char * parameterName)
{
	if (parameters.find(parameterName) != parameters.end())
	{
		return std::stol(parameters[parameterName]);
	}
	assert(false);
}

template<>
inline double IniFile::GetValue <double>(const char * parameterName)
{
	if (parameters.find(parameterName) != parameters.end())
	{
		return std::stod(parameters[parameterName]);
	}
	assert(false);
}