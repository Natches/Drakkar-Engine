#include "pch.hpp"
#include <iostream>
#include <Core/Utils/MacroUtils.hpp>
#include <Core/Core.hpp>
#include <Threading/Function/Function.hpp>
#include <Log/Log.hpp>
#include <Math/Matrix4x4.hpp>

DK_USE_NAMESPACE(drak::function)
DK_USE_NAMESPACE(drak::serialization)
DK_USE_NAMESPACE(drak::types)

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
	int b[26];
	std::string str;
	Ser* pt;
	std::vector<int> vec;
	std::vector<double*> vec2;
	std::vector<Ser> vec3;
	std::vector<Ser*> vec4;
	std::vector<std::string> vecstr;
	std::vector<std::vector<int>> vecstr2;
	std::map<int, std::string> maped;
	std::unordered_map<int, std::string> unmaped;
};

DK_METADATA_BEGIN(Ser)
DK_PRIVATE_FIELDS(i, c)
DK_PRIVATE_FIELD_COMPLEMENT
DK_METADATA_END

DK_METADATA_BEGIN(Test)
DK_PUBLIC_FIELDS(instance, unmaped, str, s, g, k, h, l, n, v, x, z, a, e, r, t, u, j, gf, f, b, vec4, vecstr2)
DK_PRIVATE_FIELDS(serial, ser1, pt, mat, vec2, vecstr)
DK_PRIVATE_STATIC_FIELDS(xizzy, maped, vec)
DK_PUBLIC_AND_PRIVATE_AND_PRIVATE_STATIC_FIELD_COMPLEMENT
DK_METADATA_END

int main() {
	Test t;
	float z = 55;
	t.instance = 25;
	t.serial.c = 25;
	t.ser1.c = 25;
	t.ser1.i = 25;
	t.gf = 10;
	for (int i = 0; i < SizeOfArray_V<TYPEOF(Test::b)>; ++i) {
		t.b[i] = i;
		t.vec.emplace_back(i);
		t.vec2.emplace_back(new double(i));
		t.vecstr.emplace_back(std::to_string(i));
		t.vecstr2.emplace_back(t.vec);
		t.maped[i] = std::to_string(i);
		t.unmaped.insert({i, std::to_string(i)});
		t.unmaped.insert({ i, std::to_string(i + 26) });
	}
	delete t.vec2[5];
	t.vec2[5] = nullptr;
	t.pt = nullptr;
	/*t.mat = drak::math::Mat4f( 1,2,5,2,2,18,5,5,5,5,8,6,3,69,9,1 );*/
	MetaData<Test>::set(t, "xizzy", std::string((char*)&z, sizeof(float)));
	t.s = 1;
	std::vector<Test> vd;
	for (int i = 0; i < 30; ++i) {
		vd.emplace_back(t);
	}
	std::stringstream sstr;
/*	drak::math::Mat4i m(1,2,5,3,6,8,9,5,2,3,6,4,9,3,6,7);*/
	Serializer::SerializeToFile<EExtension::BINARY, Test>(t, "./", "Test");

	/*std::ofstream of("testJSON.json");
	of << sstr.rdbuf();
	of.close();*/
	/*std::cout << MetaData<Ser>::s_staticSize * drak::types::SizeOfArray_V<TYPEOF(t.b)> << std::endl;
	t2 = MetaData<Test>::Create(std::get<0>(MetaData<Test>::SerializeToBinary(t)));
	Serializer::SerializeToFile<Test>(t, "./", "SerializedDataOfTest.txt");
	Serializer::AddObjectToFile<Ser>(t.ser1, "./SerializedDataOfTest.txt");
	Serializer::AddObjectToFile<Test>(t2, "./SerializedDataOfTest.txt");
	auto[a,b] = Serializer::LoadEveryFile<Test>("./SerializedDataOfTest.txt");*/
  	return 0;
}