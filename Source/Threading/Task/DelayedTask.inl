#include <Threading/Timer/Timer.hpp>
#include <Threading/Task/DelayedTask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
DelayedTask<FunctionType>::DelayedTask(ATask* pTask, const F32 delay,
	const DelayType delayType) : m_pTask(pTask), m_delay(delay), m_delayType(delayType) {
	m_executed.store(false, std::memory_order_release);
}

template<class FunctionType>
void DelayedTask<FunctionType>::operator()() {
	drak::time::Timer delay(m_pTask, m_delay, m_delayType, false);
	delay.enabled(true);
	m_executed.store(true, std::memory_order_release)
}

template<class FunctionType>
void DelayedTask<FunctionType>::execute() {
	drak::time::Timer delay(m_pTask, m_delay, m_delayType, false);
	delay.enabled(true);
	m_executed.store(true, std::memory_order_release)
}

template<class FunctionType>
F32 DelayedTask<FunctionType>::delay() const {
	return delay;
}

template<class FunctionType>
void DelayedTask<FunctionType>::delay(const F32 newDelay) {
	m_delay = newDelay;
}

template<class FunctionType>
void DelayedTask<FunctionType>::delayType(const DelayType newDelayType) {
	m_delayType = newDelayType;
}

} // namespace task
} // namespace thread
} // namespace drak
