#include <Core/Timer/Timer.hpp>

namespace drak {
namespace time {

Timer::Timer() {
	m_begin = currentTime();
	m_time = 0.0;
	m_interval = 0.0;
	m_intervalType = TimeDuration::MILLISECONDS;
}

Timer::~Timer() {
}

float Timer::duration(const TimeDuration duration_type, TimeDuration* duration_type_returned) {
	constexpr double invNano = 1.0 / (double)TimeDuration::NANOSECONDS;
	unsigned long long elapsed = (unsigned long long)
		std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime() - m_begin).count();
	switch (duration_type) {
	case TimeDuration::HOURS:
		return static_cast<float>((elapsed * invNano) / (double)TimeDuration::HOURS);
	case TimeDuration::MINUTES:
		return static_cast<float>((elapsed * invNano) / (double)TimeDuration::MINUTES);
	case TimeDuration::SECONDS:
		return static_cast<float>((elapsed * invNano));
	case TimeDuration::MILLISECONDS:
		return static_cast<float>((elapsed * invNano) * (double)TimeDuration::MILLISECONDS);
	case TimeDuration::MICROSECONDS:
		return static_cast<float>((elapsed * invNano) * (double)TimeDuration::MICROSECONDS);
	case TimeDuration::NANOSECONDS:
		return static_cast<float>(elapsed);
	case TimeDuration::AUTO:
	{
		if (elapsed < 1000) {
			*duration_type_returned = TimeDuration::NANOSECONDS;
			return static_cast<float>(elapsed);
		}
		else if (elapsed < 1000000) {
			*duration_type_returned = TimeDuration::MICROSECONDS;
			return static_cast<float>((elapsed * invNano) * (double)TimeDuration::MICROSECONDS);
		}
		else if (elapsed < 1000000000) {
			*duration_type_returned = TimeDuration::MILLISECONDS;
			return static_cast<float>((elapsed * invNano) * (double)TimeDuration::MILLISECONDS);
		}
		else if (elapsed < (unsigned long long)1000000000 * 60) {
			*duration_type_returned = TimeDuration::SECONDS;
			return static_cast<float>(((unsigned long long)elapsed * invNano));
		}
		else if (elapsed < (unsigned long long)1000000000 * 3600) {
			*duration_type_returned = TimeDuration::MINUTES;
			return static_cast<float>((elapsed * invNano) / (double)TimeDuration::MINUTES);
		}
		else {
			*duration_type_returned = TimeDuration::HOURS;
			return static_cast<float>((elapsed * invNano) / (double)TimeDuration::HOURS);
		}
	}
	default:
		*duration_type_returned = TimeDuration::MILLISECONDS;
		return static_cast<float>((elapsed * invNano)* (double)TimeDuration::MILLISECONDS);
	}
}

void Timer::start() {
	m_enabled = true;
	m_begin = currentTime();
	m_time = 0.f;
}

void Timer::resume() {
	m_enabled = true;
	m_time -= duration(m_intervalType);
}

void Timer::pause() {
	m_enabled = false;
}

void Timer::stop() {
	m_enabled = false;
}

void Timer::reset(const bool enabled) {
	m_enabled = true;
	m_begin = currentTime();
	m_time = 0.f;
}

void Timer::interval(const float f) {
	m_interval = f;
}

double Timer::interval() const {
	return m_interval;
}

Timer::TimeDuration Timer::intervalType() const {
	return m_intervalType;
}

void Timer::intervalType(const TimeDuration td)
{
	if (td == TimeDuration::AUTO)
		m_intervalType = TimeDuration::MILLISECONDS;
	else
		m_intervalType = td;
	m_time = 0.0;
};

float Timer::elapsed(const TimeDuration duration_type, TimeDuration* duration_type_returned) {
	constexpr double invNano = 1.0 / (double)TimeDuration::NANOSECONDS;
	unsigned long long elapsed = 0ull;

	if (m_intervalType == duration_type)
		return m_time;

	switch (m_intervalType) {
	case TimeDuration::HOURS:
		elapsed = static_cast<unsigned long long>(m_time * (double)TimeDuration::HOURS);
		break;
	case TimeDuration::MINUTES:
		elapsed = static_cast<unsigned long long>(m_time * (double)TimeDuration::MINUTES);
		break;
	case TimeDuration::MILLISECONDS:
		elapsed = static_cast<unsigned long long>(m_time / (double)TimeDuration::MILLISECONDS);
		break;
	case TimeDuration::MICROSECONDS:
		elapsed = static_cast<unsigned long long>(m_time / (double)TimeDuration::MICROSECONDS);
		break;
	case TimeDuration::NANOSECONDS:
		elapsed = static_cast<unsigned long long>(m_time * invNano);
	}

	switch (duration_type) {
	case TimeDuration::HOURS:
		return static_cast<float>(elapsed / (double)TimeDuration::HOURS);
	case TimeDuration::MINUTES:
		return static_cast<float>(elapsed / (double)TimeDuration::MINUTES);
	case TimeDuration::SECONDS:
		return static_cast<float>(elapsed);
	case TimeDuration::MILLISECONDS:
		return static_cast<float>(elapsed * (double)TimeDuration::MILLISECONDS);
	case TimeDuration::MICROSECONDS:
		return static_cast<float>(elapsed * (double)TimeDuration::MICROSECONDS);
	case TimeDuration::NANOSECONDS:
		return static_cast<float>(elapsed / invNano);
	case TimeDuration::AUTO:
	{
		if (elapsed < 1000) {
			*duration_type_returned = TimeDuration::NANOSECONDS;
			return static_cast<float>(elapsed / invNano);
		}
		else if (elapsed < 1000000) {
			*duration_type_returned = TimeDuration::MICROSECONDS;
			return static_cast<float>(elapsed * (double)TimeDuration::MICROSECONDS);
		}
		else if (elapsed < 1000000000) {
			*duration_type_returned = TimeDuration::MILLISECONDS;
			return static_cast<float>(elapsed * (double)TimeDuration::MILLISECONDS);
		}
		else if (elapsed < (unsigned long long)1000000000 * 60) {
			*duration_type_returned = TimeDuration::SECONDS;
			return static_cast<float>(elapsed);
		}
		else if (elapsed < (unsigned long long)1000000000 * 3600) {
			*duration_type_returned = TimeDuration::MINUTES;
			return static_cast<float>(elapsed / (double)TimeDuration::MINUTES);
		}
		else {
			*duration_type_returned = TimeDuration::HOURS;
			return static_cast<float>(elapsed / (double)TimeDuration::HOURS);
		}
	}
	default:
		*duration_type_returned = TimeDuration::MILLISECONDS;
		return static_cast<float>(elapsed * (double)TimeDuration::MILLISECONDS);
	}
}

float Timer::elapsed() const {
	return m_time;
}

bool Timer::enabled() const {
	return m_enabled;
}

void Timer::enabled(const bool b) {
	m_enabled = b;
}

} // namespace time
} // namsepace drak