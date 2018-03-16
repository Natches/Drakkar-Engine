#include <Math/MathUtils.hpp>
#include <Core/Timer/FrameTimer.hpp>

namespace drak {
namespace time {

float FrameTimer::frameRate() const {
	if (drak::math::IsNotEqual_V<float>(0.f, m_deltaTimeNoScale))
		return static_cast<float>(1 / m_deltaTimeNoScale);
	else
		return std::numeric_limits<float>::infinity();
}

float FrameTimer::deltaTimeNoScale() const {
	return m_deltaTimeNoScale;
}

float FrameTimer::deltaTime() const {
	return m_deltaTime;
}

float FrameTimer::timeScale() const {
	return m_timeScale;
}

void FrameTimer::timeScale(const float f) {
	m_timeScale = f;
}

FrameTimer::FrameTimer() {
	m_begin = currentTime();
	m_timeScale = 1.f;
	m_deltaTime = 0.f;
}

float FrameTimer::duration(const TimeDuration duration_type,
	TimeDuration* duration_type_returned) {

	constexpr double invNano = 1.0 / (double)TimeDuration::NANOSECONDS;
	unsigned long long elapsed = (unsigned long long)
		std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime() - m_begin).count();
	return static_cast<float>(elapsed * invNano);
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