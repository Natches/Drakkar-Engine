#pragma once
class IniFile
{
	const char* filename;
public:
	IniFile();
	~IniFile();
	bool LoadFile(const char* name);
};

