#include <thread>
#include <Threading/Task/ITask.hpp>
#include <Threading/Thread/ThreadObject.hpp>
#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

ThreadObject::ThreadObject(ThreadPool& pool, const U32 waitingSize)
	: m_pParent(pool), m_join(false), m_waitingSize(waitingSize) {
	m_taskList.reserve(waitingSize);
	m_pThread = new std::thread(&ThreadObject::mainLoop, this);
}


ThreadObject::~ThreadObject() {
	m_pThread->join();
	delete m_pThread;
}

ThreadObject::ThreadObject(ThreadObject&& object)
	: m_pParent(std::move(object.m_pParent)), m_pThread(std::move(object.m_pThread)),
	  m_taskList(std::move(object.m_taskList)), m_waitingSize(std::move(object.m_waitingSize)),
	  m_join(false) {

}

void ThreadObject::waitingSize(const U32 newWaitingSize) {
	m_waitingSize = newWaitingSize;
}

bool ThreadObject::isPlaceInQueue() {
	return m_taskList.safeSize() < m_waitingSize;
}

bool ThreadObject::hasJoined() const {
	return m_join;
}

void ThreadObject::mainLoop() {
	while (!m_join) {
		std::this_thread::yield();
		while (m_taskList.size()) {
			m_taskList.front()->execute();
			m_taskList.pop<false>();
			stealTask();
		}
	}
}

void ThreadObject::join() {
	m_join = true;
}

void ThreadObject::stealTask() {
	for (auto& threadObject : m_pParent.m_pool) {
		if (threadObject.m_taskList.safeSize() > U32(threadObject.m_waitingSize * 0.75f)) {
			m_taskList.steal(U32(threadObject.m_waitingSize * 0.25f), threadObject.m_taskList);
		}
	}
}

} //namespace thread
} //namespace drak