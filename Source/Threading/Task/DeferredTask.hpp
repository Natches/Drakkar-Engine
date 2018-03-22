#pragma once

#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class DeferredTask : public ATask {

public:
	DeferredTask() = delete;
	DeferredTask(const FunctionType& func);
	DeferredTask(FunctionType&& func);
	DeferredTask(const DeferredTask& d);
	DeferredTask(DeferredTask&& d);
	virtual ~DeferredTask() = default;

	DeferredTask& operator=(const DeferredTask& d);
	DeferredTask& operator=(DeferredTask&& d);

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
