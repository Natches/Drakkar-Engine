#include <PrecompiledHeader/pch.hpp>

DK_USE_NAMESPACE(drak::thread::task)
DK_USE_NAMESPACE(drak::function)

namespace drak {
namespace time {
std::mutex BenchmarkTimer::m_mutex;

BenchmarkTimer::BenchmarkTimer(drak::thread::ThreadPool& pool) : m_pool(pool), m_grp(pool) {
}

F32 BenchmarkTimer::duration(const TimeDuration duration_type, TimeDuration* duration_type_returned) {
	constexpr double invNano = 1.0 / (double)TimeDuration::NANOSECONDS;
	unsigned long long elapsed = (unsigned long long)std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_begin).count();
	switch (duration_type) {
	case ATimer::TimeDuration::HOURS:
		return F32((elapsed * invNano) / (double)TimeDuration::HOURS);
	case ATimer::TimeDuration::MINUTES:
		return F32((elapsed * invNano) / (double)TimeDuration::MINUTES);
	case ATimer::TimeDuration::SECONDS:
		return F32((elapsed * invNano));
	case ATimer::TimeDuration::MILLISECONDS:
		return F32((elapsed * invNano) * (double)TimeDuration::MILLISECONDS);
	case ATimer::TimeDuration::MICROSECONDS:
		return F32((elapsed * invNano) * (double)TimeDuration::MICROSECONDS);
	case ATimer::TimeDuration::NANOSECONDS:
		return (F32)elapsed;
	case ATimer::TimeDuration::AUTO:
	{
		if (elapsed < 1000) {
			*duration_type_returned = TimeDuration::NANOSECONDS;
			return (F32)elapsed;
		}
		else if (elapsed < 1000000) {
			*duration_type_returned = TimeDuration::MICROSECONDS;
			return F32((elapsed * invNano) * (double)TimeDuration::MICROSECONDS);
		}
		else if (elapsed < 1000000000) {
			*duration_type_returned = TimeDuration::MILLISECONDS;
			return F32((elapsed * invNano) * (double)TimeDuration::MILLISECONDS);
		}
		else if (elapsed < (unsigned long long)1000000000 * 60) {
			*duration_type_returned = TimeDuration::SECONDS;
			return F32(((unsigned long long)elapsed * invNano));
		}
		else if (elapsed < (unsigned long long)1000000000 * 3600) {
			*duration_type_returned = TimeDuration::MINUTES;
			return F32((elapsed * invNano) / (double)TimeDuration::MINUTES);
		}
		else {
			*duration_type_returned = TimeDuration::HOURS;
			return F32((elapsed * invNano) / (double)TimeDuration::HOURS);
		}
	}
	default:
		*duration_type_returned = TimeDuration::MILLISECONDS;
		return F32((elapsed * invNano) * (double)TimeDuration::MILLISECONDS);
	}
}

void BenchmarkTimer::start() {
	m_begin = currentTime();
}

void BenchmarkTimer::stop() {
	m_end = currentTime();
}

void BenchmarkTimer::reset(const bool enabled) {
	m_begin = currentTime();
}

void BenchmarkTimer::print(TimeDuration duration_type, const char* message) {
	std::cout << message << " ";
	TimeDuration duration_type_returned;
	F32 elapsed = duration(duration_type, &duration_type_returned);
	switch (duration_type) {
	case ATimer::TimeDuration::HOURS:
		std::cout << "Time taken : " << elapsed << "h \n";
		break;
	case ATimer::TimeDuration::MINUTES:
		std::cout << "Time taken : " << elapsed << "m \n";
		break;
	case ATimer::TimeDuration::SECONDS:
		std::cout << "Time taken : " << elapsed << "s \n";
		break;
	case ATimer::TimeDuration::MILLISECONDS:
		std::cout << "Time taken : " << elapsed << "ms \n";
		break;
	case ATimer::TimeDuration::MICROSECONDS:
		std::cout << "Time taken : " << elapsed << "mcs \n";
		break;
	case ATimer::TimeDuration::NANOSECONDS:
		std::cout << "Time taken : " << elapsed << "ns \n";
		break;
	case ATimer::TimeDuration::AUTO:
	{
		switch (duration_type_returned) {
		case ATimer::TimeDuration::HOURS:
			std::cout << "Time taken : " << elapsed << "h \n";
			break;
		case ATimer::TimeDuration::MINUTES:
			std::cout << "Time taken : " << elapsed << "m \n";
			break;
		case ATimer::TimeDuration::SECONDS:
			std::cout << "Time taken : " << elapsed << "s \n";
			break;
		case ATimer::TimeDuration::MILLISECONDS:
			std::cout << "Time taken : " << elapsed << "ms \n";
			break;
		case ATimer::TimeDuration::MICROSECONDS:
			std::cout << "Time taken : " << elapsed << "mcs \n";
			break;
		case ATimer::TimeDuration::NANOSECONDS:
			std::cout << "Time taken : " << elapsed << "ns \n";
			break;
		}
	}
	break;
	default:
		std::cout << "Time taken : " << elapsed << "ms \n";
	}
}

void BenchmarkTimer::addFunction(IFunction* f, const char* msg) {
	m_grp.registerTask(Task<Member>(Member(this, &BenchmarkTimer::time, std::move(f), std::move(msg))));
}

void BenchmarkTimer::timeFunctionInParallel() {
	m_grp.sendGroupToThreadPool();
}

void BenchmarkTimer::timeFunctions() {
	TaskSequence seq;
	m_grp.toSequence(seq);
	seq.execute();
}

void BenchmarkTimer::waitEndOfTasks() {
	m_grp.waitForTasks();
}

void BenchmarkTimer::time(IFunction* f, const char* msg) {
	BenchmarkTimer temp(m_pool);
	temp.start();
	f->invoke();
	temp.stop();
	m_mutex.lock();
	temp.print(ATimer::TimeDuration::AUTO, msg);
	m_mutex.unlock();
}

} // namespace time
} // namespace drak
