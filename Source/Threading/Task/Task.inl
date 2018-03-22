#include <Threading/Task/Task.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
Task<FunctionType>::Task(const Task& t) : m_func(t.m_func) {
}

template<class FunctionType>
Task<FunctionType>::Task(Task&& t) : m_func(std::forward<FunctionType>(t.m_func)) {
}

template<class FunctionType>
Task<FunctionType>::Task(const FunctionType& f) 
	: m_func(f) {
	m_executed.store(false, std::memory_order_release);
}

template<class FunctionType>
Task<FunctionType>::Task(FunctionType&& f) 
	: m_func(std::forward<FunctionType>(f)) {
	m_executed.store(false, std::memory_order_release);
}

template<class FunctionType>
Task<FunctionType>& Task<FunctionType>::operator=(const Task& t) {
	m_func = t.m_func;
	return *this;
}

template<class FunctionType>
Task<FunctionType>& Task<FunctionType>::operator=(Task&& t) {
	m_func = std::forward<FunctionType>(t.m_func);
	return *this;
}

template<class FunctionType>
void Task<FunctionType>::operator()() {
	m_func();
	m_executed.store(true, std::memory_order_release);

}

template<class FunctionType>
void Task<FunctionType>::execute() {
	m_func();
	m_executed.store(true, std::memory_order_release);
}


} // namespace task
} // namespace thread
} // namespace drak
