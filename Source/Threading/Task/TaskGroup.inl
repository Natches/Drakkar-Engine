#include <Threading/Task/ATask.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {
namespace task {

template<class T>
TaskGroup<T>::TaskGroup(ThreadPool& pool) : m_pool(pool) {
}

template<class T>
void TaskGroup<T>::registerTask(T&& task) {
	m_taskList.emplace_back(std::forward<T>(task));
}

template<class T>
void TaskGroup<T>::unRegisterTask(T&& task) {
	m_taskList.erase(m_taskList.remove(std::move(task)));
}

template<class T>
void TaskGroup<T>::waitForTasks() {
	for each(const T& task in m_taskList)
		while (!task.executed());
}

template<class Task>
void TaskGroup<Task>::clearGroup() {
	m_taskList.clear();
}

template<class T>
void TaskGroup<T>::sendGroupToThreadPool() {
	T* data = m_taskList.data();
	for(size_t i = 0, size = m_taskList.size(); i < size; ++i)
		m_pool.addTask(data + i);
}

} //namespace task
} //namespace thread
} //namespace drak