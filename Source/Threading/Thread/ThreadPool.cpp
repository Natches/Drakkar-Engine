#include <Threading/Thread/ThreadPool.hpp>

namespace drak {
namespace thread {

ThreadPool::ThreadPool(const U32 threadNumber) {
	m_pool.reserve(threadNumber);
	for (U32 i = 0; i < threadNumber; ++i) {
		m_pool.emplace_back(new ThreadObject(*this, i));
	}
}

ThreadPool::~ThreadPool() {
	for (auto threadObject : m_pool)
		threadObject->join();
}

void ThreadPool::WaitForAllTasks() {
	for (auto threadObject : m_pool)
		while (!threadObject->sleep());
}

} //namespace thread
} //namespace drak