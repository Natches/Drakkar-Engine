#include "IniFile.h"
#include <stdexcept>
#include <cassert>
#include <string>
template<>
inline int IniFile::GetValue<int>(const char * parameterName)
{
	try
	{
		parameters.at(parameterName);
	}
	catch (std::out_of_range)
	{
		assert(false);
	}
	return std::stoi( parameters[parameterName]);
}

template<>
inline float IniFile::GetValue<float>(const char * parameterName)
{
	try
	{
		parameters.at(parameterName);
	}
	catch (std::out_of_range)
	{
		assert(false);
	}
	return std::stof(parameters[parameterName]);
}

template<>
inline std::string IniFile::GetValue <std::string> (const char * parameterName)
{
	try
	{
		parameters.at(parameterName);
	}
	catch (std::out_of_range)
	{
		assert(false);
	}
	return std::string(parameters[parameterName]);
}