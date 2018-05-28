#pragma once

#include <Threading/Task/ATask.hpp>
#include <Threading/Function/IFunction.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class Task : public ATask {

public:
	Task() = delete;
	Task(const Task& t);
	Task(Task&& t);
	Task(const FunctionType& f);
	Task(FunctionType&& f);
	virtual ~Task() = default;

	Task& operator=(const Task& t);
	Task& operator=(Task&& t);

	virtual void operator()() override;
	virtual void execute() override;

private:
	FunctionType m_func;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/Task.inl>