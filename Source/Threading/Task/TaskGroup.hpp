#pragma once

#include <vector>

namespace drak {
namespace thread {
class ThreadPool;

namespace task {
class ATask;
class TaskSequence;

template<class T>
class TaskGroup {

public:
	TaskGroup() = delete;
	TaskGroup(ThreadPool& pool);
	~TaskGroup() = default;

	void registerTask(T&& task);
	void unRegisterTask(T&& task);
	void waitForTasks();

	template<bool areAllocated>
	void clearGroup();
	void sendGroupToThreadPool();

	void toSequence(TaskSequence& seq);
private:
	std::vector<T> m_taskList;
	ThreadPool& m_pool;
};

} //namespace task
} //namespace thread
} //namespace drak
#include <Threading/Task/TaskGroup.inl>