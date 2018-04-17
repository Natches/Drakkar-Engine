#include <PrecompiledHeader/pch.hpp>
//#include <Math/MathUtils.hpp>

namespace drak {
namespace time {

F32 FrameTimer::frameRate() const {
	if (drak::math::IsNotEqual_V<F32>(0.f, m_deltaTimeNoScale))
		return 1.f / m_deltaTimeNoScale;
	else
		return std::numeric_limits<F32>::infinity();
}

F32 FrameTimer::deltaTimeNoScale() const {
	return m_deltaTimeNoScale;
}

F32 FrameTimer::deltaTime() const {
	return m_deltaTime;
}

F32 FrameTimer::timeScale() const {
	return m_timeScale;
}

void FrameTimer::timeScale(const F32 f) {
	m_timeScale = f;
}

FrameTimer::FrameTimer() {
	m_begin = currentTime();
	m_timeScale = 1.f;
	m_deltaTime = 0.f;
}

F32 FrameTimer::duration(const TimeDuration duration_type,
	TimeDuration* duration_type_returned) {

	constexpr F64 invNano = 1.0 / (F64)TimeDuration::NANOSECONDS;
	U64 elapsed = (U64)
		std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime() - m_begin).count();
	return static_cast<F32>(elapsed * invNano);
}

void FrameTimer::start() {
	m_begin = currentTime();
	m_deltaTime = 0.f;
}

void FrameTimer::resume() {
	m_timeScale = 1.f;
}

void FrameTimer::pause() {
	m_timeScale = 0.f;
}

void FrameTimer::stop() {
	m_timeScale = 0.f;
	m_deltaTime = 0.f;
}

void FrameTimer::reset(const bool enabled) {
	m_begin = currentTime();
	m_deltaTime = 0.f;
}

void FrameTimer::update() {
	m_deltaTimeNoScale = duration();
	m_begin = currentTime();
	m_deltaTime = m_deltaTimeNoScale * m_timeScale;
}

} //namespace time
} //namespace drak