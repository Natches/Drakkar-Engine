#pragma once

#include <vector>
#include <Core/Utils/ClassUtils.hpp>
#include <Threading/Thread/ThreadObject.hpp>

namespace drak {
class ResourceConverter;
namespace core {
	class Engine;
} // namespace core
namespace converter {
class ResourceConverter;
} //namespace converter
namespace thread {

class ThreadPool {
	friend ThreadObject;
	friend core::Engine;
	friend drak::converter::ResourceConverter;
	DK_NONMOVABLE_NONCOPYABLE(ThreadPool)

	using Task = task::ATask;
public:
	void waitForAllTasks()const;

	template<class...VArgs>
	void addTask(Task* pTask, VArgs&&...args);

private:
	ThreadPool() = default;
	~ThreadPool() = default;
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
