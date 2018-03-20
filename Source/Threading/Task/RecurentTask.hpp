#pragma once

#include <Threading/Task/ITask.hpp>

namespace drak {
namespace thread {
namespace task {

class RecurentTask : public ITask {

public:
	RecurentTask() = delete;
	RecurentTask(ITask* task);

private:
	ITask* m_pTask;

};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/RecurentTask.inl>