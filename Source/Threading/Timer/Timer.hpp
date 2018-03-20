#pragma once

#include <mutex>
#include <Core/Timer/ATimer.hpp>
#include <Threading/Function/IFunction.hpp>

namespace drak {
namespace time {

class Timer : public ATimer {
	/*friend TimeThread;*/
public:
	Timer();
	Timer(drak::function::IFunction* func, const F32 interval, const TimeDuration intervalType, const bool loop);
	virtual ~Timer();

	void configure(drak::function::IFunction* func, const F32 interval, const TimeDuration intervalType, const bool loop);

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

	F32 elapsed(const TimeDuration duration_type,
		TimeDuration* duration_type_returned = nullptr);
	F32 elapsed()const;

	bool enabled()const;
	void enabled(const bool b);

	bool loop()const;
	void loop(const bool b);

private:
	F32 m_time;
	F32 m_interval;
	TimeDuration m_intervalType;
	bool m_enabled;
	bool m_loop;
	drak::function::IFunction* m_pFunc;
};

} // namespace time
} // namespace drak

