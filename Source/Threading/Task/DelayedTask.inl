#include <Threading/Timer/Timer.hpp>
#include <Threading/Task/DelayedTask.hpp>

namespace drak {
namespace thread {
namespace task {

DelayedTask::DelayedTask(ATask* pTask, const F32 delay,
	const DelayType delayType) 
	: m_pTask(pTask), m_delay(delay), m_delayType(delayType) {
	m_executed.store(false, std::memory_order_release);
}

DelayedTask::DelayedTask(DelayedTask&& d) : m_delay(std::move(d.m_delay)),
	m_delayType(std::move(d.m_delayType)), m_pTask(std::move(d.m_pTask)),
	m_timer(std::move(d.m_timer)) {
	d.m_pTask = nullptr;
	m_executed.store(false, std::memory_order_release);
}

void DelayedTask::operator=(DelayedTask&& d) {
	m_delay = std::move(d.m_delay);
	m_delayType = std::move(d.m_delayType);  
	m_pTask = std::move(d.m_pTask);
	m_timer = std::move(d.m_timer);
	d.m_pTask = nullptr;
	m_executed.store(false, std::memory_order_release);
}

void DelayedTask::operator()() {
	m_timer.configure(m_pTask, m_delay, m_delayType, false, true);
	m_executed.store(true, std::memory_order_release);
}

void DelayedTask::execute() {
	m_timer.configure(m_pTask, m_delay, m_delayType, false, true);
	m_executed.store(true, std::memory_order_release);
}

F32 DelayedTask::delay() const {
	return m_delay;
}

void DelayedTask::delay(const F32 newDelay) {
	m_delay = newDelay;
}

void DelayedTask::delayType(const DelayType newDelayType) {
	m_delayType = newDelayType;
}

} // namespace task
} // namespace thread
} // namespace drak
