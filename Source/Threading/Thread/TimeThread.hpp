#pragma once

#include <thread>
#include <Core/Utils/ClassUtils.hpp>

namespace drak {
namespace time {
class Timer;
} //namespace time
namespace thread {

class ThreadPool;

class TimeThread {
	DK_NONCOPYABLE(TimeThread)
	DK_NOMOVE_OP(TimeThread)
public:
	TimeThread(time::Timer& m_timer);
	TimeThread(TimeThread&& thread);
	~TimeThread();

	void mainloop();
	void join();

	void resetThread();

private:
	time::Timer& m_timer;
	std::thread* m_pThread;
	bool m_join;
};

} // namespace thread
} // namespace drak

