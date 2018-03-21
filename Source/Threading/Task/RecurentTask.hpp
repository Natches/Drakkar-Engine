#pragma once

#include <Threading/Timer/Timer.hpp>
#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {

class ThreadPool;

namespace task {

class RecurentTask {

public:
	RecurentTask() = delete;
	RecurentTask(ATask* pTask, ThreadPool& pool);
	RecurentTask(ATask* pTask, ThreadPool& pool, const drak::time::Timer& timer);

	void timer(const drak::time::Timer& timer);
	void enabled(const bool b);

	void recur();
	void task(ATask* pTask);

private:
	ATask* m_pTask;
	ThreadPool& m_pool;
	drak::time::Timer m_timer;
};

} // namespace task
} // namespace thread
} // namespace drak