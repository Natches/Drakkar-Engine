#include <Threading/StealableQueue.hpp>
#include <Threading/Function.hpp>
#include <iostream>
#include <functional>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>


DK_IMPORT(drak::thread)
DK_IMPORT(drak::function)
DK_IMPORT(drak::math)

void add() {
}

int add2() {
	return 1;
}

int add2(int i) {
	return i;
}

void add(int i) {

}

struct A {
	void add() {
	}

	int add2() {
		return 1;
	}

	int add2(int i) {
		return i;
	}

	void add(int i) {

	}
};


int main() {

	StealableQueue<int> q;
	q.emplace(1);
	int i = 0;

	A a;

	GlobalFunction<void, void> g1(add);
	g1();

	GlobalFunction<int, void> g2(add2);
	g2();

	GlobalFunction<int, int> g3(add2);
	g3();

	GlobalFunction<void, int> g4(add);
	g4();

	MemberFunction<A, void, void> m1(&a, &A::add);
	m1();

	MemberFunction<A, int, void> m2(&a, &A::add2);
	m2();

	MemberFunction<A, int, int> m3(&a, &A::add2);
	m3();

	MemberFunction<A, void, int> m4(&a, &A::add);
	m4();

	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	//GlobalFunction<int, void> g(add);

	system("pause");

	return 0;
}