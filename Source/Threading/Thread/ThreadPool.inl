#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

template<class ...VArgs>
void ThreadPool::addTask(Task* task, VArgs&&...args) {
	m_pool[0]->addTask(task);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		addTask(1, std::forward<VArgs>(args)...);
}

template<class ...VArgs>
void ThreadPool::addTask(U16 threadNumber, Task* task, VArgs&&...args) {
	if (threadNumber == static_cast<U16>(m_pool.size()))
		threadNumber = 0;
	m_pool[threadNumber]->addTask(task);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		addTask(++threadNumber, std::forward<VArgs>(args)...);
}

} //namespace thread
} //namespace drak
