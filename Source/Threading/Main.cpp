#include <Threading/Function/Function.hpp>
#include <Threading/Task/RecurentTask.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Threading/Thread/ThreadPool.hpp>
#include <Threading/Timer/Timer.hpp>
#include <iostream>
#include <functional>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>
#include <random>

DK_IMPORT(drak::time)
DK_IMPORT(drak::thread)
DK_IMPORT(drak::thread::task)
DK_IMPORT(drak::function)
DK_IMPORT(drak::math)

static std::random_device rd;
//static std::atomic<int> i;

void add() {
	printf("Je suis Majextueux");
}

using namespace std::chrono_literals;

int main() {
	/*auto t1 = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(10000ms);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / (float)1000/ * / (float)10000 * /<< std::endl;*/
	//std::cout << i << std::endl;
	//auto f = [&i]() { return i += 1; };

	//std::function<void()> f = std::bind(add, 1, 2);

	//std::cout << f() << std::endl;

	//GlobalFunction<int, void> g(add);
	system("pause");
	return 0;
}