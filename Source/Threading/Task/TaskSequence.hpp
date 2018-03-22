#pragma once

#include <vector>
#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
namespace task {

class TaskSequence : public ATask {

public:
	TaskSequence() = default;
	virtual ~TaskSequence() = default;

	template<class T, class...VArgs>
	void addTasks(T&& first, VArgs&&...args);

	virtual void operator()() override;
	virtual void execute() override;

private:
	std::vector<ATask*> m_taskList;
	void addTasks() {};
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/TaskSequence.inl>