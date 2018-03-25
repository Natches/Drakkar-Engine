#include <iostream>
#include <Core/Utils/MacroUtils.hpp>
#include <Threading/Function/Function.hpp>
#include <Serialization/SerializationUtils.hpp>
#include <array>
#include <tuple>
#include <map>
#include <variant>
#include <optional>
#include <any>
#include <string>

DK_IMPORT(drak::function)
DK_IMPORT(drak::serialization)

class Ser {
	int i = 0;
};

class Test {
	DK_SERIALIZED_OBJECT(Test)
		inline int foo(int i) { std::cout << i << std::endl; return i; };
	Ser serial, ser1;
public:
	int instance;
	int s, g, k, h, l, n,v, x, z, a, e, r, t, u, j, gf , f;
};
DK_METADATA(Test)
DK_PUBLIC_MEMBERS(Test, instance, s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f)
DK_END;

struct Test2 {
	int instance;
};

auto get(const char* c) {

}

int main() {
	system("pause");
	return 0;
}