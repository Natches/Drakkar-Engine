#include <Threading/Thread/ThreadObject.hpp>
#include <thread>

namespace drak {
namespace thread {

template<class ...VArgs>
void ThreadObject::addTask(Task* task, VArgs&&...args) {
	m_taskList.push(task);
	if constexpr (sizeof...(VArgs))
		addTask(std::forward<VArgs>(args)...);
}

} //namespace thread
} //namespace drak
