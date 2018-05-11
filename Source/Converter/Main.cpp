#include <PrecompiledHeader/pch.hpp>
#include <iostream>
#include <Converter/ResourceConvert.hpp>

int main(int ac, char**av) {
	drak::converter::ResourceConverter r;
	r.startup();
	r.convert(ac, av);
	r.shutdown();
	system("pause");
	return 0;
}