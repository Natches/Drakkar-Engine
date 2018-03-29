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
#include <fstream>

DK_IMPORT(drak::function)
DK_IMPORT(drak::serialization)
DK_IMPORT(drak::types)

class Ser {
	DK_SERIALIZED_OBJECT(Ser)
	int i;
	int c;
	int x = 0;
};

class Test {
	DK_SERIALIZED_OBJECT(Test)
public:
		inline int foo(int i) { std::cout << i << std::endl; return i; };
private:
	Ser serial, ser1;
	float xizzy;
public:
	int instance;
	int s, g, k, h, l, n,v, x, z, a, e, r, t, u, j, gf , f;
	Ser b[26];
};

DK_METADATA_BEGIN(Ser)
DK_PRIVATE_FIELDS(i, c)
DK_SERIALIZE_PRIVATE_FIELDS
DK_METADATA_END
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Ser)

DK_METADATA_BEGIN(Test)
DK_PUBLIC_FIELDS(instance, s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f, b)
DK_PRIVATE_FIELDS(serial, ser1)
DK_PRIVATE_STATIC_FIELDS(xizzy)
DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_PRIVATE_FIELDS
DK_METADATA_END
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Test)

int main() {
	Test t;
	t.s = 1;
	std::stringstream str("", std::ios::binary | std::ios::out | std::ios::in);
	t.serialize(str);
	std::tuple<int, int, int> tu{ 1,2,3 };
	std::ofstream of("serializedData.txt", std::ios::binary | std::ios::out);
	if (of.is_open()) {
		of << str.rdbuf();
		of.close();
	}

	system("pause");
	return 0;
}