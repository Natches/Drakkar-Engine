#pragma once

#include <chrono>

namespace drak {
namespace time {

class ATimer {
public:
	enum class TimeDuration : int {
		HOURS = 3600,
		MINUTES = 60,
		SECONDS = 1,
		MILLISECONDS = 1000,
		MICROSECONDS = 1000000,
		NANOSECONDS = 1000000000,
		AUTO
	};

public:
	virtual float duration(const TimeDuration duration_type,
		TimeDuration* duration_type_returned = nullptr) = 0;
	virtual void start() = 0;
	virtual void resume() = 0;
	virtual void pause() = 0;
	virtual void stop() = 0;
	virtual void reset(const bool enabled) = 0;

protected:
	std::chrono::time_point<std::chrono::high_resolution_clock> currentTime();

protected:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};

} // namespace time
} // namespace drak