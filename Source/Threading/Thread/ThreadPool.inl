#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

template<class ...VArgs>
void ThreadPool::addTask(Task* task, VArgs&&...args) {
	m_pool[0].addTask(task);
	addTask(1, std::forward<VArgs>(args)...);
}

template<class ...VArgs>
void ThreadPool::addTask(U8 threadNumber, Task* task, VArgs&&...args) {
	if (threadNumber == m_pool.size())
		threadNumber = 0;
	m_pool[threadNumber].addTask(task);
	if constexpr (sizeof...(VArgs))
		addTask(threadNumber + 1, std::forward<VArgs>(args)...);
}

} //namespace thread
} //namespace drak
