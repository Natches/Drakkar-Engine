#include <Threading/Task/Task.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
Task<FunctionType>::Task(const FunctionType& f) : m_func(f) {

}

template<class FunctionType>
Task<FunctionType>::Task(FunctionType && f) : m_func(std::forward<FunctionType>(f)) {
}

template<class FunctionType>
void Task<FunctionType>::operator()() {
	m_func();

}

template<class FunctionType>
void Task<FunctionType>::execute() {
	m_func();
}


} // namespace task
} // namespace thread
} // namespace drak
