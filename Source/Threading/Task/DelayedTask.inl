#include <Threading/Timer/Timer.hpp>
#include <Threading/Task/DelayedTask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
DelayedTask<FunctionType>::DelayedTask(FunctionType&& func, const F32 delay,
	const drak::time::Timer::TimeDuration delayType)
	: m_func(func), m_delay(delay), m_delayType(delayType) {
}

template<class FunctionType>
void DelayedTask<FunctionType>::operator()() {
	drak::time::Timer delay(&m_func, m_delay, m_delayType, false);
	delay.enabled(true);
}

template<class FunctionType>
void DelayedTask<FunctionType>::execute() {
	drak::time::Timer delay(&m_func, m_delay, m_delayType, false);
	delay.enabled(true);
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
void DelayedTask<FunctionType>::delayType(const drak::time::Timer::TimeDuration newDelayType) {
	m_delayType = newDelayType;
}

} // namespace task
} // namespace thread
} // namespace drak
