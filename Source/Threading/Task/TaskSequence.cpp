#include <Threading/Task/RecurentTask.hpp>
#include "TaskSequence.hpp"

namespace drak {
namespace thread {
namespace task {

void TaskSequence::operator()() {
	for each(ITask* task in m_taskList) {
		task->execute();
	}
}

void TaskSequence::execute() {
	for each(ITask* task in m_taskList) {
		task->execute();
	}
}

} // namespace task
} // namespace thread
} // namespace drak