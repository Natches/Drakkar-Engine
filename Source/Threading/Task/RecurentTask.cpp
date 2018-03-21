#include <Threading/Thread/ThreadPool.hpp>
#include <Threading/Task/RecurentTask.hpp>
#include <Threading/Function/Function.hpp>
#include <Threading/Task/Task.hpp>

namespace drak {
namespace thread {
namespace task {

using MemberFunction = drak::function::MemberFunction<RecurentTask, void, void>;
using Timer = drak::time::Timer;

RecurentTask::RecurentTask(ATask* pTask, ThreadPool& pool) : m_pool(pool), m_pTask(pTask) {
}

RecurentTask::RecurentTask(ATask* pTask, ThreadPool& pool, const Timer& timer)
	: m_pool(pool), m_pTask(pTask), m_timer(timer) {
	m_timer.task(m_pTask);
}

void RecurentTask::timer(const Timer& timer) {
	m_timer = timer;
	m_timer.task(m_pTask);
}

void RecurentTask::enabled(const bool b) {
	m_timer.enabled(b);
}

void RecurentTask::recur() {
	m_pool.addTask(m_pTask);
}

void RecurentTask::task(ATask* pTask) {
	m_pTask = pTask;
}

} // namespace task
} // namespace thread
} // namespace drak