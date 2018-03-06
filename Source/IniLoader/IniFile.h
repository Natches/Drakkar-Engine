#pragma once
#include <map>
class IniFile
{
	const char* filename;
	std::map<const char*, const char*> parameters;
public:
	IniFile();
	~IniFile();
	bool LoadFile(const char* name);
};

