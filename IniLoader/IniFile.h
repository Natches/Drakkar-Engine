#pragma once
#include <map>
class IniFile
{
	const char* filename;
	std::map<char*, char*> values;
public:
	IniFile();
	~IniFile();
	bool LoadFile(const char* name);
};

