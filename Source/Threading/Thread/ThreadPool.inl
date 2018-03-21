#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

template<class ...VArgs>
void ThreadPool::addTask(Task* task, VArgs&&...args) {
	static U16 last = 0;
	last >= static_cast<U16>(m_pool.size()) ? last = 0 : last = last;
	m_pool[last]->addTask(task);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		last = addTask(last + 1, std::forward<VArgs>(args)...);
	else
		last += 1;
}

template<class ...VArgs>
U16 ThreadPool::addTask(U16 threadNumber, Task* task, VArgs&&...args) {
	if (threadNumber == static_cast<U16>(m_pool.size()))
		threadNumber = 0;
	m_pool[threadNumber]->addTask(task);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		return addTask(++threadNumber, std::forward<VArgs>(args)...);
	else
		return threadNumber;
}

} //namespace thread
} //namespace drak
