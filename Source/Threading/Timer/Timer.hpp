#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Core/Timer/ATimer.hpp>
#include <Threading/Task/ATask.hpp>

namespace drak {
namespace thread {
	class TimeThread;
} //namespace thread

namespace time {

class Timer : public ATimer {
	friend thread::TimeThread;
	using Task = drak::thread::task::ATask;
	DK_NONCOPYABLE(Timer);
public:
	Timer();
	Timer(Task* pTask, const F32 interval, const TimeDuration intervalType,
		const bool loop, const bool autoStart = false);
	Timer(Timer&& timer);
	virtual ~Timer();

	void operator=(Timer&& timer);

	void configure(Task* pTask, const F32 interval, const TimeDuration intervalType,
		const bool loop, const bool autoStart = false);

	virtual F32 duration(const TimeDuration duration_type,
		TimeDuration* duration_type_returned = nullptr) override;

	virtual void start()override;
	virtual void resume()override;
	virtual void pause()override;
	virtual void stop()override;
	virtual void reset(const bool enabled)override;

	void interval(const F32 f);
	F64 interval()const;
	void intervalType(const TimeDuration td);
	TimeDuration intervalType()const;

	bool enabled()const;
	void enabled(const bool b);

	bool loop()const;
	void loop(const bool b);

	void task(Task* pTask);

	Task* task();

private:
	F32 m_interval;
	TimeDuration m_intervalType;
	bool m_enabled;
	bool m_loop;
	Task* m_pTask;
	thread::TimeThread* m_pThread;
};

} // namespace time
} // namespace drak

