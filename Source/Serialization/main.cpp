#include <iostream>
#include <Core/Utils/MacroUtils.hpp>
#include <Core/Core.hpp>
#include <Threading/Function/Function.hpp>
#include <Serialization/Serializer.hpp>
#include <array>
#include <tuple>
#include <map>
#include <variant>
#include <optional>
#include <any>
#include <sstream>
#include <type_traits>
#include <fstream>
#include <Log/Log.hpp>
#include <Math/Matrix4x4.hpp>

DK_IMPORT(drak::function)
DK_IMPORT(drak::serialization)
DK_IMPORT(drak::types)

class Ser {
	DK_SERIALIZED_OBJECT(Ser)
	int i = 0;
	int c = 0;
	int x = 0;
};

class Test {
	DK_SERIALIZED_OBJECT(Test)
public:
	inline int foo(int i) { std::cout << i << std::endl; return i; };
public:
	Ser serial, ser1;
	float xizzy;
public:
	int instance;
	int s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f;
	drak::math::Mat4f mat;
	Ser b[26];
	std::string str;
	Ser* pt;
	std::vector<int> vec;
	std::vector<double*> vec2;
	std::vector<Ser> vec3;
	std::vector<Ser*> vec4;
	std::vector<std::string> vecstr;
	std::vector<std::vector<int>> vecstr2;
};

DK_METADATA_BEGIN(Ser)
DK_PRIVATE_FIELDS(i, c)
DK_SERIALIZE_PRIVATE_FIELDS
DK_METADATA_END
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Ser)

DK_METADATA_BEGIN(Test)
DK_PUBLIC_FIELDS(instance, s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f, b, vec4, vecstr2)
DK_PRIVATE_FIELDS(serial, ser1, pt, vec2, vecstr)
DK_PRIVATE_STATIC_FIELDS(xizzy, str, vec, vec3, mat)
DK_SERIALIZE_PUBLIC_AND_PRIVATE_AND_PRIVATE_STATIC_FIELDS
DK_METADATA_END
DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(Test)

int main() {
	Test t;
	float z = 55;
	t.serial.c = 25;
	t.ser1.c = 25;
	t.ser1.i = 25;
	t.gf = 10;
	for (int i = 0; i < SizeOfArray_V<TYPEOF(Test::b)>; ++i) {
		t.b[i].c = i;
		t.vec.emplace_back(i);
		t.vec2.emplace_back(new double(i));
		t.vec3.emplace_back(t.b[i]);
		t.vec4.emplace_back(new Ser(t.b[i]));
		t.vecstr.emplace_back(std::to_string(i));
		t.vecstr2.emplace_back(t.vec);
	}
	delete t.vec2[5];
	t.vec2[5] = nullptr;
	t.str = "";
	t.pt = new Ser{ 12,536,0 };
	t.mat = drak::math::Mat4f( 1,2,5,2,2,18,5,5,5,5,8,6,3,69,9,1 );
	MetaData<Test>::PrivateStaticFields::set(t, "xizzy", &z);
	//MetaData<Test>::PrivateFields::set(t, "ser1", &z);
	//MetaData<Test>::PrivateFields::set(t, "serial", &z);
	t.s = 1; std::string s;
	std::stringstream str("", std::ios::binary | std::ios::out | std::ios::in);
	t.serialize(str);
	Serializer::SerializeToFile("./", "SerializaedDataOfTest.txt", t, t, t, t, t, t );
	/*std::ofstream of("serializedData2.txt", std::ios::binary | std::ios::out);
	if (of.is_open()) {
		of << str.rdbuf();
		of.close();
	}*/
	return 0;
}