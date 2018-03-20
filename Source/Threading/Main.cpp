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
	for (int i = 0; i < 1000000000; ++i);
}

int main() {
	Task<GlobalFunction<void, void>> t({ add });

	ThreadPool pool;

	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		pool.addTask(&t, &t, &t, &t, &t, &t, &t, &t);
	}
	pool.WaitForAllTasks();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / (float)1000 << std::endl;

	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	//GlobalFunction<int, void> g(add);
	system("pause");

	return 0;
}