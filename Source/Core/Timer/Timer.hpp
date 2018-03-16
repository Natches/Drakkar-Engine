#pragma once

#include <mutex>
#include <Core/Timer/ATimer.hpp>

namespace drak {
namespace time {

class Timer : public ATimer {
	/*friend TimeThread;*/
public:
	Timer();
	virtual ~Timer();

	virtual float duration(const TimeDuration duration_type,
		TimeDuration* duration_type_returned = nullptr) override;

	virtual void start()override;
	virtual void resume()override;
	virtual void pause()override;
	virtual void stop()override;
	virtual void reset(const bool enabled)override;

	void interval(const float f);
	double interval()const;
	void intervalType(const TimeDuration td);
	TimeDuration intervalType()const;

	float elapsed( const TimeDuration duration_type,
		TimeDuration* duration_type_returned = nullptr);
	float elapsed()const;

	bool enabled()const;
	void enabled(const bool b);

private:
	float m_time;
	float m_interval;
	TimeDuration m_intervalType;
	bool m_enabled;
};

}
}

