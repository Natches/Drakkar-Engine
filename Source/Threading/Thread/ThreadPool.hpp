#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Threading/Thread/ThreadObject.hpp>

namespace drak {
namespace thread {

class ThreadPool {
	friend ThreadObject;
	DK_NONMOVABLE_NONCOPYABLE(ThreadPool)
	using Task = task::ITask;
public:
	ThreadPool(const U32 threadNumber = std::thread::hardware_concurrency());
	~ThreadPool();

	template<class...VArgs>
	void addTask(Task* task, VArgs&&...args);

private:
	template<class...VArgs>
	void addTask(U8 threadNumber, Task* task, VArgs&&...args);

private:
	std::vector<ThreadObject> m_pool;
};

} //namespace thread
} //namespace drak
