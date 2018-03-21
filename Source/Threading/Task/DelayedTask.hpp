#pragma once

#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
namespace task {

class DelayedTask : public ATask {

	using DelayType = drak::time::Timer::TimeDuration;

public:
	DelayedTask() = delete;
	DelayedTask(ATask* pTask, const F32 delay,
		const DelayType delayType);
	virtual ~DelayedTask() = default;

	virtual void operator()() override;
	virtual void execute() override;

	F32 delay() const;
	void delay(const F32 newDelay);

	void delayType(const DelayType newDelayType);

private:
	ATask* m_pTask;
	F32 m_delay;
	DelayType m_delayType;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/DelayedTask.inl>
