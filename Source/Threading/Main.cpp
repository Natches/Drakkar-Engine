#include <Threading/StealableQueue.hpp>
#include <Threading/Function/Function.hpp>
#include <Threading/Task/Task.hpp>
#include <iostream>
#include <functional>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>


DK_IMPORT(drak::thread)
DK_IMPORT(drak::thread::task)
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

	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	//GlobalFunction<int, void> g(add);

	system("pause");

	return 0;
}