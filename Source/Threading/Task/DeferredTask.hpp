#pragma once

#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class DeferredTask : public ATask {

public:
	DeferredTask() = delete;
	DeferredTask(FunctionType&& func);
	virtual ~DeferredTask() = default;

	virtual void operator()() override;
	virtual void execute() override;

	typename FunctionType::RetType get();

private:
	FunctionType m_func;
	FunctionType::RetType m_return;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/DeferredTask.inl>
