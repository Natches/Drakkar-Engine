#include <PrecompiledHeader/pch.hpp>
#include <iostream>
#include <string>
#include <Converter/ResourceConverter.hpp>

int main(int ac, char**av) {
	drak::converter::ResourceConverter r;
	r.startup();
	char** toConvert = new char*[ac];
	char** alreadyConverted = new char*[ac];
	U32 sizeToConvert = 0, sizeAlreadyConverted = 0;
	std::vector<std::string> files;
	for (int i = 1; i < ac; ++i) {
		if (drak::io::AllExtension(av[i]) == "dkResources.bin") {
			alreadyConverted[sizeAlreadyConverted++] = av[i];
		}
		else {
			toConvert[sizeToConvert++] = av[i];
			if (drak::definition::IsMesh(av[i])) {
				files.emplace_back((std::string("Resources/Models/") + drak::io::FileNameNoExtension(av[i])) + ".dkResources.bin");
				alreadyConverted[sizeAlreadyConverted++] = files[files.size() - 1].data();
			}
			else if (drak::definition::IsTexture(av[i])) {
				files.emplace_back((std::string("Resources/Textures/") + drak::io::FileNameNoExtension(av[i])) + ".dkResources.bin");
				alreadyConverted[sizeAlreadyConverted++] = files[files.size() - 1].data();
			}
		}
	}
	if(sizeToConvert)
		r.convert(sizeToConvert, (const char**)toConvert);
	char choice;
	std::cout << "Do you want to compress files ? (y/n) \n";
	std::cin >> choice;
	if (choice == 'y') {
		std::cout << "Name of package (32char max) :\n";
		char name[32];
		std::cin >> name;
		r.toPackage(sizeAlreadyConverted, (const char**)alreadyConverted, name);
	}
	r.shutdown();
	system("pause");
	delete[] toConvert;
	delete[] alreadyConverted;
	return 0;
}