#include <Threading/Task/DeferredTask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
DeferredTask<FunctionType>::DeferredTask(FunctionType&& func)
	: m_func(std::forward<FunctionType>(func)) {
	m_executed.store(false, std::memory_order_release);
}

template<class FunctionType>
void DeferredTask<FunctionType>::operator()() {
	m_return = m_func();
	m_executed.store(true, std::memory_order_release);
}

template<class FunctionType>
void DeferredTask<FunctionType>::execute() {
	m_return = m_func();
	m_executed.store(true, std::memory_order_release);
}

template<class FunctionType>
typename FunctionType::RetType DeferredTask<FunctionType>::get() {
	while (!m_executed.load(std::memory_order_acquire));
	return m_return;
}

} // namespace task
} // namespace thread
} // namespace drak