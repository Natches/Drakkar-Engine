#pragma once

#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
namespace task {

class DelayedTask : public ATask {

	using DelayType = drak::time::Timer::TimeDuration;
	DK_NONCOPYABLE(DelayedTask)
public:
	DelayedTask() = delete;
	DelayedTask(ATask* pTask, const F32 delay,
		const DelayType delayType);
	DelayedTask(DelayedTask&& d);
	virtual ~DelayedTask() = default;

	void operator=(DelayedTask&& d);

	virtual void operator()() override;
	virtual void execute() override;

	F32 delay() const;
	void delay(const F32 newDelay);

	void delayType(const DelayType newDelayType);

private:
	ATask* m_pTask;
	F32 m_delay;
	DelayType m_delayType;
	time::Timer m_timer;
};

} // namespace task
} // namespace thread
} // namespace drak
#include <Threading/Task/DelayedTask.inl>
