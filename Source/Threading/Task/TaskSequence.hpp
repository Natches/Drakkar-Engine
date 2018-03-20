#pragma once

#include <Threading/Task/ITask.hpp>
#include <vector>

namespace drak {
namespace thread {
namespace task {

class TaskSequence : public ITask {

public:
	TaskSequence() = default;
	virtual ~TaskSequence() = default;

	template<class T, class...VArgs>
	void addTasks(T&& first, VArgs&&...args);

	virtual void operator()() override;
	virtual void execute() override;

private:
	std::vector<ITask*> m_taskList;
	void addTasks() {};
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/TaskSequence.inl>