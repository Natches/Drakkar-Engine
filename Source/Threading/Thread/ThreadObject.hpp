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
	ThreadObject(ThreadPool& pool, const U32 waitingSize = 5u);
	~ThreadObject();

	ThreadObject(ThreadObject&& object);

	void waitingSize(const U32 newWaitingSize);

	bool isPlaceInQueue();
	bool hasJoined() const;

	void mainLoop();
	void join();

	template<class...VArgs>
	void addTask(Task* task, VArgs&&...args);

private:
	void stealTask();

private:
	ThreadPool& m_pParent;
	std::thread* m_pThread;
	StealableQueue<Task*> m_taskList;
	U32 m_waitingSize;
	bool m_join;
};

} //namespace thread
} //namespace drak
#include <Threading/Thread/ThreadObject.inl>
