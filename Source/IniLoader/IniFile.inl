#include "IniFile.h"
#include <stdexcept>
template<>
inline int IniFile::GetValue<int>(const char * parameterName)
{
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
		system("pause");
	}
	return std::stof(parameters[parameterName]);
}