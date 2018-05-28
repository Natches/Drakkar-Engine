#include <IniLoader/IniFile.hpp>
#include <fstream>
#include <iostream>
#include <string>

IniFile::IniFile()
{
}


IniFile::~IniFile()
{
}

bool IniFile::LoadFromFile(const char * name)
{
	filename = name;
	std::ifstream fs;
	fs.open(name);
	if (fs.good())
	{
		while (!fs.eof())
		{
			std::string line;
			std::getline(fs, line);
			std::string ParamName = line.substr(0, line.find_first_of(" = "));
			std::string ParamVal = line.substr(line.find_first_of(" = ") + 3);
			parameters.insert(std::pair<std::string, std::string>(ParamName, ParamVal));
		}
	}
	fs.close();
	return false;
}
