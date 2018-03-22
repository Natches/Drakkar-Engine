#pragma once

#include <vector>

namespace drak {
namespace thread {
class ThreadPool;

namespace task {
class ATask;

template<class Task>
class TaskGroup {

public:
	TaskGroup() = delete;
	TaskGroup(ThreadPool& pool);
	~TaskGroup() = default;

	void registerTask(Task&& task);
	void unRegisterTask(Task&& task);
	void waitForTasks();

	void clearGroup();
	void sendGroupToThreadPool();
private:
	std::vector<Task> m_taskList;
	ThreadPool& m_pool;
};

} //namespace task
} //namespace thread
} //namespace drak
#include <Threading/Task/TaskGroup.inl>