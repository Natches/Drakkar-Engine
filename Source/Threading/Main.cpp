#include <Threading/StealableQueue.hpp>
#include <Threading/Function/Function.hpp>
#include <Threading/Task/Task.hpp>
#include <Threading/Thread/ThreadPool.hpp>
#include <iostream>
#include <functional>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>


DK_IMPORT(drak::thread)
DK_IMPORT(drak::thread::task)
DK_IMPORT(drak::function)
DK_IMPORT(drak::math)

void add() {
	for (int i = 0; i < 100000; ++i);
}

int main() {

	Task<GlobalFunction<void, void>> t({ add });

	ThreadPool pool;

	for (int i = 0; i < 1000000000; ++i) {
		pool.addTask(&t, &t, &t, &t, &t, &t, &t, &t, &t, &t);
	}


	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	//GlobalFunction<int, void> g(add);

	system("pause");

	return 0;
}