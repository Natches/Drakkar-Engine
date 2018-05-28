#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace thread {

using namespace std::chrono_literals;

TimeThread::TimeThread(time::Timer& timer) : m_timer(timer), m_join(false) {
	m_pThread = new std::thread(&TimeThread::mainloop, this);
}

TimeThread::TimeThread(TimeThread&& thread)
	: m_join(false), m_timer(std::forward<time::Timer>(thread.m_timer)), m_pThread(thread.m_pThread) {
	thread.join();
	thread.m_pThread->detach();
	thread.m_pThread = nullptr;
	new (m_pThread) std::thread(&TimeThread::mainloop, this);
}

TimeThread::~TimeThread() {
	if (m_pThread) {
		m_pThread->detach();
		delete m_pThread;
	}
}

void TimeThread::mainloop() {
	while (m_timer.enabled() && !m_join) {
		DK_SELECT(m_timer.intervalType())
			DK_CASE(time::Timer::TimeDuration::HOURS,
				std::this_thread::sleep_for(std::chrono::hours(U64(m_timer.interval()))))
			DK_CASE(time::Timer::TimeDuration::MINUTES,
				std::this_thread::sleep_for(std::chrono::minutes(U64(m_timer.interval()))))
			DK_CASE(time::Timer::TimeDuration::SECONDS,
				std::this_thread::sleep_for(std::chrono::seconds(U64(m_timer.interval()))))
			DK_CASE(time::Timer::TimeDuration::MILLISECONDS,
				std::this_thread::sleep_for(std::chrono::milliseconds(U64(m_timer.interval()))))
			DK_CASE(time::Timer::TimeDuration::MICROSECONDS,
				std::this_thread::sleep_for(std::chrono::microseconds(U64(m_timer.interval()))))
			DK_CASE(time::Timer::TimeDuration::NANOSECONDS,
				std::this_thread::sleep_for(std::chrono::nanoseconds(U64(m_timer.interval()))))
		DK_END
		if (m_timer.enabled()) {
			m_timer.task()->execute();
			if (!((m_timer.loop() >> 31) & 1)) {
				m_timer.loop(m_timer.loop() - 1);
				if (!m_timer.loop())
					m_timer.enabled(false);
			}
		}
	}
}

void TimeThread::join() {
	m_join = true;
}

void TimeThread::resetThread() {
	new (m_pThread) std::thread(&TimeThread::mainloop, this);
}

} // namespace drak
} // namespace thread