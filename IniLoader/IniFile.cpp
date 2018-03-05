#include "IniFile.h"
#include <fstream>
#include <string.h>

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
	std::string line;
	fs.getline(line, 100);

	return false;
}
