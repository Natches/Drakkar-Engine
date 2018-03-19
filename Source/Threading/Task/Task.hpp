#pragma once

#include <Threading/Task/ITask.hpp>
#include <Threading/Function/IFunction.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class Task : public ITask {

public:
	Task() = delete;
	Task(const FunctionType& f);
	Task(FunctionType&& f);
	virtual ~Task() = default;

	virtual void operator()() override;
	virtual void execute() override;

private:
	FunctionType m_func;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/Task.inl>