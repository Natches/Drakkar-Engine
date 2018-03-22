#include <Threading/Task/ATask.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {
namespace task {

template<class Task>
TaskGroup::TaskGroup(ThreadPool& pool) : m_pool(pool) {
}

template<class Task>
void TaskGroup::registerTask(Task&& task) {
	m_taskList.push_back(std::move(task));
}

template<class Task>
void TaskGroup::unRegisterTask(Task&& task) {
	m_taskList.erase(m_taskList.remove(std::move(task)));
}

template<class Task>
void TaskGroup::waitForTasks() {
	for each(Task& task in m_taskList)
		while (!task->executed());
}

template<class Task>
void TaskGroup::clearGroup() {
	m_taskList.clear();
}

template<class Task>
void TaskGroup::sendGroupToThreadPool() {
	for each(Task& task in m_taskList)
		m_pool.addTask(&task);
}

} //namespace task
} //namespace thread
} //namespace drak