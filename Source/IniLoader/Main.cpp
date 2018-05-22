#include "IniFile.hpp"
int main()
{
	IniFile file;
	file.LoadFromFile("Ini/IniTest.txt");
	float porkCost = file.GetValue<float>("PorkCost");
	float sheildCost = file.GetValue<float>("ShieldCost");
 	system("pause");
}