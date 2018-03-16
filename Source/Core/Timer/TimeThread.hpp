#pragma once

#include <thread>
#include <condition_variable>

class Timer;
namespace drak {
namespace time {

/*
class TimeThread {
public:
	TimeThread() = delete;
	TimeThread(Timer& t);
	~TimeThread();

	void time();
	void notify();

private:
	Timer & _t;
	std::thread _th;
	std::condition_variable cv;
	std::mutex _m;
	bool _join;
};*/

}
}

