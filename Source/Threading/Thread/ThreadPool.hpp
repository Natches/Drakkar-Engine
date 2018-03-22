#pragma once

#include <vector>
#include <DrakEngine/Engine/Engine.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Threading/Thread/ThreadObject.hpp>

namespace drak {
namespace thread {

class ThreadPool {
	friend ThreadObject;
	friend drak::core::Engine;

	DK_NONMOVABLE_NONCOPYABLE(ThreadPool)

	using Task = task::ATask;
public:
	~ThreadPool() = default;

	void waitForAllTasks()const;

	template<class...VArgs>
	void addTask(Task* pTask, VArgs&&...args);

private:
	ThreadPool() = default;
	bool startup(const U32 threadNumber = std::thread::hardware_concurrency());
	void shutdown();

	template<class...VArgs>
	U16 addTask(U16 threadNumber, Task* pTask, VArgs&&...args);

private:
	std::vector<ThreadObject*> m_pool;
};

} //namespace thread
} //namespace drak
#include <Threading/Thread/ThreadPool.inl>
