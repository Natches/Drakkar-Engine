#include <iostream>
#include <Core/Utils/MacroUtils.hpp>
#include <Core/Core.hpp>
#include <Threading/Function/Function.hpp>
#include <Serialization/SerializationUtils.hpp>
#include <array>
#include <tuple>
#include <map>
#include <variant>
#include <optional>
#include <any>
#include <sstream>
#include <type_traits>

DK_IMPORT(drak::function)
DK_IMPORT(drak::serialization)
DK_IMPORT(drak::types)

class Ser {
	DK_SERIALIZED_OBJECT(Ser)
	int i;
};

class Test {
	DK_SERIALIZED_OBJECT(Test)
public:
		inline int foo(int i) { std::cout << i << std::endl; return i; };
	Ser serial, ser1;
public:
	int instance;
	int s, g, k, h, l, n,v, x, z, a, e, r, t, u, j, gf , f;
};

DK_METADATA(Ser)
DK_PUBLIC_MEMBERS(Ser, i)
DK_SERIALIZE_PUBLIC_FIELDS(Ser, 1)
DK_END;
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Ser)

DK_METADATA(Test)
DK_PUBLIC_MEMBERS(Test, instance, s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f, serial, ser1)
DK_SERIALIZE_PUBLIC_FIELDS(Test, 20)
DK_END;
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Test)

struct Test2 {
	int instance;
};

auto get(const char* c) {

}

int main() {
	Test t;
	std::stringstream str("", std::ios::binary | std::ios::out);
	t.serialize(str);
	std::cout << str.str().c_str() << std::endl;

	system("pause");
	return 0;
}