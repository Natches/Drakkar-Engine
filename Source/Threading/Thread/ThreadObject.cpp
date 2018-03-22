#include <thread>
#include <Threading/Task/ATask.hpp>
#include <Threading/Thread/ThreadObject.hpp>
#include <Threading/Thread/ThreadPool.hpp>

using namespace std::chrono_literals;

namespace drak {
namespace thread {

ThreadObject::ThreadObject(ThreadPool& pool, const U8 instance, const U32 waitingSize)
	: m_pParent(pool), m_join(false), m_waitingSize(waitingSize) {
	m_taskList.reserve(waitingSize);
	m_pThread = new std::thread(&ThreadObject::mainLoop, this);
}


ThreadObject::~ThreadObject() {
	if (m_pThread) {
		m_pThread->join();
		delete m_pThread;
	}
}

ThreadObject::ThreadObject(ThreadObject&& object)
	: m_pParent(std::move(object.m_pParent)), m_pThread(std::move(object.m_pThread)),
	  m_taskList(std::move(object.m_taskList)), m_waitingSize(std::move(object.m_waitingSize)),
	  m_join(false), m_instance(std::move(object.m_instance)) {
}

void ThreadObject::waitingSize(const U32 newWaitingSize) {
	m_waitingSize = newWaitingSize;
}

bool ThreadObject::sleep() {
	return m_taskList.empty();
}

bool ThreadObject::isPlaceInQueue() {
	return m_taskList.safeSize() < m_waitingSize;
}

bool ThreadObject::hasJoined() const {
	return m_join;
}

void ThreadObject::mainLoop() {
	std::this_thread::sleep_for(10us);
	while (!m_join) {
		if (m_taskList.empty())
			std::this_thread::sleep_for(378ns);
		else {
			if (Task* pTask = m_taskList.front()) {
				pTask->execute();
				m_taskList.pop<false>();
			}
			if (m_taskList.safeEmpty())
				stealTask();
		}
	}
}

void ThreadObject::join() {
	m_join = true;
}

void ThreadObject::stealTask() {
	ThreadObject* pNeighbor = m_pParent.m_pool[m_instance + (m_instance & 1) ? (-1) : 1];
	if (pNeighbor->m_taskList.size() > (m_waitingSize))
		m_taskList.steal(U32(m_waitingSize * 0.5f), pNeighbor->m_taskList);
}

} //namespace thread
} //namespace drak