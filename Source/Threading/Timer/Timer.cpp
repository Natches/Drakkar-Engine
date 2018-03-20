#include <Threading/Timer/Timer.hpp>

namespace drak {
namespace time {

Timer::Timer() {
	m_begin = currentTime();
	m_time = 0.f;
	m_interval = 0.f;
	m_intervalType = TimeDuration::MILLISECONDS;
}

Timer::Timer(drak::function::IFunction* func, const F32 interval, const TimeDuration intervalType, const bool loop)
	: m_pFunc(func), m_interval(interval), m_intervalType(intervalType), m_loop(loop) {
}

Timer::~Timer() {
}

void Timer::configure(drak::function::IFunction* func, const F32 interval, const TimeDuration intervalType, const bool loop) {
	m_interval = interval;
	m_intervalType = intervalType;
	m_loop = loop;
	m_pFunc = func;
}

F32 Timer::duration(const TimeDuration duration_type, TimeDuration* duration_type_returned) {
	constexpr F64 invNano = 1.0 / (F64)TimeDuration::NANOSECONDS;
	U64 elapsed = (U64)
		std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime() - m_begin).count();
	switch (duration_type) {
	case TimeDuration::HOURS:
		return static_cast<F32>((elapsed * invNano) / (F64)TimeDuration::HOURS);
	case TimeDuration::MINUTES:
		return static_cast<F32>((elapsed * invNano) / (F64)TimeDuration::MINUTES);
	case TimeDuration::SECONDS:
		return static_cast<F32>((elapsed * invNano));
	case TimeDuration::MILLISECONDS:
		return static_cast<F32>((elapsed * invNano) * (F64)TimeDuration::MILLISECONDS);
	case TimeDuration::MICROSECONDS:
		return static_cast<F32>((elapsed * invNano) * (F64)TimeDuration::MICROSECONDS);
	case TimeDuration::NANOSECONDS:
		return static_cast<F32>(elapsed);
	case TimeDuration::AUTO:
	{
		if (elapsed < 1000) {
			*duration_type_returned = TimeDuration::NANOSECONDS;
			return static_cast<F32>(elapsed);
		}
		else if (elapsed < 1000000) {
			*duration_type_returned = TimeDuration::MICROSECONDS;
			return static_cast<F32>((elapsed * invNano) * (F64)TimeDuration::MICROSECONDS);
		}
		else if (elapsed < 1000000000) {
			*duration_type_returned = TimeDuration::MILLISECONDS;
			return static_cast<F32>((elapsed * invNano) * (F64)TimeDuration::MILLISECONDS);
		}
		else if (elapsed < (U64)1000000000 * 60) {
			*duration_type_returned = TimeDuration::SECONDS;
			return static_cast<F32>(((U64)elapsed * invNano));
		}
		else if (elapsed < (U64)1000000000 * 3600) {
			*duration_type_returned = TimeDuration::MINUTES;
			return static_cast<F32>((elapsed * invNano) / (F64)TimeDuration::MINUTES);
		}
		else {
			*duration_type_returned = TimeDuration::HOURS;
			return static_cast<F32>((elapsed * invNano) / (F64)TimeDuration::HOURS);
		}
	}
	default:
		*duration_type_returned = TimeDuration::MILLISECONDS;
		return static_cast<F32>((elapsed * invNano)* (F64)TimeDuration::MILLISECONDS);
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

void Timer::interval(const F32 f) {
	m_interval = f;
}

F64 Timer::interval() const {
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

F32 Timer::elapsed(const TimeDuration duration_type, TimeDuration* duration_type_returned) {
	constexpr F64 invNano = 1.0 / (F64)TimeDuration::NANOSECONDS;
	U64 elapsed = 0ull;

	if (m_intervalType == duration_type)
		return m_time;

	switch (m_intervalType) {
	case TimeDuration::HOURS:
		elapsed = static_cast<U64>(m_time * (F64)TimeDuration::HOURS);
		break;
	case TimeDuration::MINUTES:
		elapsed = static_cast<U64>(m_time * (F64)TimeDuration::MINUTES);
		break;
	case TimeDuration::MILLISECONDS:
		elapsed = static_cast<U64>(m_time / (F64)TimeDuration::MILLISECONDS);
		break;
	case TimeDuration::MICROSECONDS:
		elapsed = static_cast<U64>(m_time / (F64)TimeDuration::MICROSECONDS);
		break;
	case TimeDuration::NANOSECONDS:
		elapsed = static_cast<U64>(m_time * invNano);
	}

	switch (duration_type) {
	case TimeDuration::HOURS:
		return static_cast<F32>(elapsed / (F64)TimeDuration::HOURS);
	case TimeDuration::MINUTES:
		return static_cast<F32>(elapsed / (F64)TimeDuration::MINUTES);
	case TimeDuration::SECONDS:
		return static_cast<F32>(elapsed);
	case TimeDuration::MILLISECONDS:
		return static_cast<F32>(elapsed * (F64)TimeDuration::MILLISECONDS);
	case TimeDuration::MICROSECONDS:
		return static_cast<F32>(elapsed * (F64)TimeDuration::MICROSECONDS);
	case TimeDuration::NANOSECONDS:
		return static_cast<F32>(elapsed / invNano);
	case TimeDuration::AUTO:
	{
		if (elapsed < 1000) {
			*duration_type_returned = TimeDuration::NANOSECONDS;
			return static_cast<F32>(elapsed / invNano);
		}
		else if (elapsed < 1000000) {
			*duration_type_returned = TimeDuration::MICROSECONDS;
			return static_cast<F32>(elapsed * (F64)TimeDuration::MICROSECONDS);
		}
		else if (elapsed < 1000000000) {
			*duration_type_returned = TimeDuration::MILLISECONDS;
			return static_cast<F32>(elapsed * (F64)TimeDuration::MILLISECONDS);
		}
		else if (elapsed < (U64)1000000000 * 60) {
			*duration_type_returned = TimeDuration::SECONDS;
			return static_cast<F32>(elapsed);
		}
		else if (elapsed < (U64)1000000000 * 3600) {
			*duration_type_returned = TimeDuration::MINUTES;
			return static_cast<F32>(elapsed / (F64)TimeDuration::MINUTES);
		}
		else {
			*duration_type_returned = TimeDuration::HOURS;
			return static_cast<F32>(elapsed / (F64)TimeDuration::HOURS);
		}
	}
	default:
		*duration_type_returned = TimeDuration::MILLISECONDS;
		return static_cast<F32>(elapsed * (F64)TimeDuration::MILLISECONDS);
	}
}

F32 Timer::elapsed() const {
	return m_time;
}

bool Timer::enabled() const {
	return m_enabled;
}

void Timer::enabled(const bool b) {
	m_enabled = b;
}

bool Timer::loop() const {
	return m_loop;
}

void Timer::loop(const bool b) {
	m_loop = b;
}

} // namespace time
} // namsepace drak