#pragma once

#include <atomic>
#include <Threading/Task/ITask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class DeferredTask : public ITask {

public:
	DeferredTask() = delete;
	DeferredTask(FunctionType&& func);
	virtual ~DeferredTask() = default;

	virtual void operator()() override;
	virtual void execute() override;

	typename FunctionType::RetType get();
	bool completed();

private:
	FunctionType m_func;
	FunctionType::RetType m_return;
	std::atomic<bool> m_completed;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/DeferredTask.inl>
