#pragma once

#include <Threading/Timer/Timer.hpp>
#include <Threading/Task/Task.hpp>
#include <Threading/Function/Function.hpp>

namespace drak {
namespace thread {

class ThreadPool;

namespace task {

class RecurentTask {

	using MemberFunction = drak::function::MemberFunction<RecurentTask, void, void>;

public:
	RecurentTask() = delete;
	RecurentTask(ATask* pTask, ThreadPool& pool);
	RecurentTask(ATask* pTask, ThreadPool& pool, drak::time::Timer&& timer);

	void timer(drak::time::Timer&& timer);
	void enabled(const bool b);

	void recur();
	void task(ATask* pTask);

private:
	Task<MemberFunction> m_recurTask;
	ATask* m_pTask;
	ThreadPool& m_pool;
	drak::time::Timer m_timer;
};

} // namespace task
} // namespace thread
} // namespace drak