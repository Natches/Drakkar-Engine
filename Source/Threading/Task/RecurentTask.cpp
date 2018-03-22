#include <Threading/Thread/ThreadPool.hpp>
#include <Threading/Task/RecurentTask.hpp>
#include <Threading/Task/Task.hpp>

namespace drak {
namespace thread {
namespace task {

using Timer = drak::time::Timer;

RecurentTask::RecurentTask(ATask* pTask, ThreadPool& pool) : m_pool(pool), m_pTask(pTask),
	m_recurTask(MemberFunction(this, &RecurentTask::recur)) {
}

RecurentTask::RecurentTask(ATask* pTask, ThreadPool& pool, Timer&& timer)
	: m_pool(pool), m_pTask(pTask), m_timer(std::move(timer)),
	m_recurTask(MemberFunction(this, &RecurentTask::recur)) {
	m_timer.task(m_pTask);
}

void RecurentTask::timer(Timer&& timer) {
	m_timer = std::move(timer);
	m_timer.task(&m_recurTask);
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