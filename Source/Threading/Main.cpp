#include <Threading/StealableQueue.hpp>
#include <Threading/Function.hpp>
#include <iostream>
#include <functional>

DK_IMPORT(drak::thread)
DK_IMPORT(drak::function)

int add() {
	return 1 + 1;
}

int main() {

	StealableQueue<int> q;
	q.emplace(1);
	int i = 0;

	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	GlobalFunction<int, void> g(add);

	system("pause");

	return 0;
}