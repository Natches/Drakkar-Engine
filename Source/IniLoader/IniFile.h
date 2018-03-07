#pragma once
#include <map>
#include <string>
class IniFile
{
	const char* filename;
	std::map<std::string, std::string> parameters;
public:
	IniFile();
	~IniFile();
	bool LoadFile(const char* name);
	template <typename T>
	T GetValue(const char* parameterName);
};

#include "IniFile.inl"