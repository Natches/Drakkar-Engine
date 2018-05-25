#include <Threading/Task/ATask.hpp>
#include <Threading/Task/TaskSequence.hpp>
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
	if constexpr (std::is_pointer_v<T>) {
		for(const auto& t : m_taskList)
			while (!(*t).executed());
	}
	else {
		for(const auto& t : m_taskList)
			while (!t.executed());
	}
}

template<class Task>
template<bool areAllocated>
void TaskGroup<Task>::clearGroup() {
	if constexpr (areAllocated) {
		for (auto x : m_taskList) {
			delete x;
		}
	}
	m_taskList.clear();
}

template<class T>
void TaskGroup<T>::sendGroupToThreadPool() {
	if constexpr(std::is_pointer_v<T>) {
		for (size_t i = 0, size = m_taskList.size(); i < size; ++i)
			m_pool.addTask(m_taskList[i]);
	}
	else {
		T* data = m_taskList.data();
		for (size_t i = 0, size = m_taskList.size(); i < size; ++i)
			m_pool.addTask(data + i);
	}
}

template<class T>
void TaskGroup<T>::toSequence(TaskSequence& seq) {
	for (auto& task : m_taskList)
		seq.addTasks(&task);
}

} //namespace task
} //namespace thread
} //namespace drak