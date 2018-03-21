#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Threading/StealableQueue.hpp>

namespace std {
	class thread;
}

namespace drak {
namespace thread {

class ThreadPool;

namespace task {
	class ITask;
}
class ThreadObject {
	DK_NONCOPYABLE(ThreadObject)
	DK_NOMOVE_OP(ThreadObject)
	using Task = task::ITask;
public:
	ThreadObject() = delete;
	ThreadObject(ThreadPool& pool, const U8 instance, const U32 waitingSize = 10u);
	~ThreadObject();

	ThreadObject(ThreadObject&& object);

	void waitingSize(const U32 newWaitingSize);

	bool sleep();
	bool isPlaceInQueue();
	bool hasJoined() const;

	void mainLoop();
	void join();

	template<class...VArgs>
	void addTask(Task* task, VArgs&&...args);

private:
	void stealTask();
	void addTask() {};

private:
	ThreadPool& m_pParent;
	std::thread* m_pThread;
	StealableQueue<Task*> m_taskList;
	StealableQueue<Task*> m_stealedTaskList;
	U32 m_waitingSize;
	U8 m_instance;
	bool m_join;
};

} //namespace thread
} //namespace drak
#include <Threading/Thread/ThreadObject.inl>
