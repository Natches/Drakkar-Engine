#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace thread {
namespace task {

void TaskSequence::operator()() {
	for each(ATask* pTask in m_taskList) {
		pTask->execute();
	}
	m_executed.store(true, std::memory_order_release);
}

void TaskSequence::execute() {
	for each(ATask* pTask in m_taskList) {
		pTask->execute();
	}
	m_executed.store(true, std::memory_order_release);
}

TaskGroup<ATask*> TaskSequence::toGroup(ThreadPool& pool) {
	TaskGroup<ATask*> grp(pool);
	for (auto& task : m_taskList)
		grp.registerTask(std::move(task));
	return grp;
}

} // namespace task
} // namespace thread
} // namespace drak