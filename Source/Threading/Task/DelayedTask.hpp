#pragma once

#include <Threading/Task/ITask.hpp>

namespace drak {
namespace thread {
namespace task {

template<class FunctionType>
class DelayedTask : public ITask {

public:
	DelayedTask() = delete;
	DelayedTask(FunctionType&& func, const F32 delay,
		const drak::time::Timer::TimeDuration delayType);
	virtual ~DelayedTask() = default;

	virtual void operator()() override;
	virtual void execute() override;

	F32 delay() const;
	void delay(const F32 newDelay);

	void delayType(const drak::time::Timer::TimeDuration newDelayType);

private:
	FunctionType m_func;
	F32 m_delay;
	drak::time::Timer::TimeDuration m_delayType;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/DelayedTask.inl>
