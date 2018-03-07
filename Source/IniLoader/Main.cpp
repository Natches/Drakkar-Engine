#include "IniFile.h"
int main()
{
	IniFile file;
	file.LoadFile("Ini/IniTest.txt");
	float porkCost = file.GetValue<float>("PorkCost");
	float sheildCost = file.GetValue<float>("ShieldCost");
 	system("pause");
}