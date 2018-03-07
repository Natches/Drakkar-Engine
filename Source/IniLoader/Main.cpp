#include "IniFile.h"
int main()
{
	IniFile file;
	file.LoadFile("Ini/IniTest.txt");
	float porkvalue = file.GetValue<float>("PorkPrice");
}