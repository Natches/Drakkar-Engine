#include "IniFile.h"
#include <fstream>


IniFile::IniFile()
{
}


IniFile::~IniFile()
{
}

bool IniFile::LoadFile(const char * name)
{
	filename = name;
	std::fstream fs;
	fs.open(name, std::fstream::in);
	char* line = new char[100];
	return false;
}
