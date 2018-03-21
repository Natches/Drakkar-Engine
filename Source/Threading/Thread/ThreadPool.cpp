#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

void ThreadPool::waitForAllTasks() const{
	for (auto threadObject : m_pool)
		while (!threadObject->sleep());
}

bool ThreadPool::startup(const U32 threadNumber) {
	if (!m_pool.size()) {
		m_pool.reserve(threadNumber);
		for (U32 i = 0; i < threadNumber; ++i) {
			m_pool.emplace_back(new ThreadObject(*this, i));
		}
	}
	return true;
}

void ThreadPool::shutdown() {
	for (auto threadObject : m_pool) {
		threadObject->join();
		delete threadObject;
	}
}

} //namespace thread
} //namespace drak