#include <thread>
#include <Threading/Task/ITask.hpp>
#include <Threading/Thread/ThreadObject.hpp>
#include <Threading/Thread/ThreadPool.hpp>

using namespace std::chrono_literals;

namespace drak {
namespace thread {

ThreadObject::ThreadObject(ThreadPool& pool, const U32 waitingSize)
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
	  m_join(false) {
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
	while (!m_join) {
		if (!m_taskList.size()) {
			stealTask();
			std::this_thread::sleep_for(378ns);
		}
		else {
			if (m_taskList.front()) {
				m_taskList.front()->execute();
				m_taskList.pop<false>();
			}
		}
	}
}

void ThreadObject::join() {
	m_join = true;
}

void ThreadObject::stealTask() {
	for (auto& threadObject : m_pParent.m_pool) {
		if (threadObject != this && (threadObject->m_taskList.size() > threadObject->m_waitingSize)) {
			m_taskList.steal(threadObject->m_waitingSize, threadObject->m_taskList);
			break;
		}
	}
}

} //namespace thread
} //namespace drak