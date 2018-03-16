#include "BenchmarkTimer.h"
#include "PoolThread.h"

namespace NLib
{
	std::mutex BenchmarkTimer::_mutex;

	BenchmarkTimer::BenchmarkTimer()
	{
		_begin = current_time();
		_end = current_time();
		_pool = nullptr;
	}

	BenchmarkTimer::~BenchmarkTimer()
	{
		delete _pool;
		_pool = nullptr;
	}

	void BenchmarkTimer::print(E_TIME_DURATION duration_type, const char* message)
	{
		std::cout << message << " ";
		E_TIME_DURATION duration_type_returned;
		double elapsed = duration(duration_type, &duration_type_returned);
		switch (duration_type)
		{
		case ATimer::HOURS:
			std::cout << "Time taken : " << elapsed << "h \n";
			break;
		case ATimer::MINUTES:
			std::cout << "Time taken : " << elapsed << "m \n";
			break;
		case ATimer::SECONDS:
			std::cout << "Time taken : " << elapsed << "s \n";
			break;
		case ATimer::MILLISECONDS:
			std::cout << "Time taken : " << elapsed << "ms \n";
			break;
		case ATimer::MICROSECONDS:
			std::cout << "Time taken : " << elapsed << "mcs \n";
			break;
		case ATimer::NANOSECONDS:
			std::cout << "Time taken : " << elapsed << "ns \n";
			break;
		case ATimer::AUTO:
		{
			switch (duration_type_returned)
			{
			case ATimer::HOURS:
				std::cout << "Time taken : " << elapsed << "h \n";
				break;
			case ATimer::MINUTES:
				std::cout << "Time taken : " << elapsed << "m \n";
				break;
			case ATimer::SECONDS:
				std::cout << "Time taken : " << elapsed << "s \n";
				break;
			case ATimer::MILLISECONDS:
				std::cout << "Time taken : " << elapsed << "ms \n";
				break;
			case ATimer::MICROSECONDS:
				std::cout << "Time taken : " << elapsed << "mcs \n";
				break;
			case ATimer::NANOSECONDS:
				std::cout << "Time taken : " << elapsed << "ns \n";
				break;
			}
		}
		break;
		default:
			std::cout << "Time taken : " << elapsed << "ms \n";
		}
	}

	double BenchmarkTimer::duration(E_TIME_DURATION duration_type, E_TIME_DURATION * duration_type_returned)
	{
		constexpr double invNano = 1.0 / (double)NANOSECONDS;
		unsigned long long elapsed = (unsigned long long)std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _begin).count();
		switch (duration_type)
		{
		case ATimer::HOURS:
			return ((elapsed * invNano) / (double)HOURS);
		case ATimer::MINUTES:
			return ((elapsed * invNano) / (double)MINUTES);
		case ATimer::SECONDS:
			return ((elapsed * invNano));
		case ATimer::MILLISECONDS:
			return ((elapsed * invNano) * (double)MILLISECONDS);
		case ATimer::MICROSECONDS:
			return ((elapsed * invNano) * (double)MICROSECONDS);
		case ATimer::NANOSECONDS:
			return (double)elapsed;
		case ATimer::AUTO:
		{
			if (elapsed < 1000)
			{
				*duration_type_returned = NANOSECONDS;
				return (double)elapsed;
			}
			else if (elapsed < 1000000)
			{
				*duration_type_returned = MICROSECONDS;
				return ((elapsed * invNano) * (double)MICROSECONDS);
			}
			else if (elapsed < 1000000000)
			{
				*duration_type_returned = MILLISECONDS;
				return ((elapsed * invNano) * (double)MILLISECONDS);
			}
			else if (elapsed < (unsigned long long)1000000000 * 60)
			{
				*duration_type_returned = SECONDS;
				return (((unsigned long long)elapsed * invNano));
			}
			else if (elapsed < (unsigned long long)1000000000 * 3600)
			{
				*duration_type_returned = MINUTES;
				return ((elapsed * invNano) / (double)MINUTES);
			}
			else
			{
				*duration_type_returned = HOURS;
				return ((elapsed * invNano) / (double)HOURS);
			}
		}
		default:
			*duration_type_returned = MILLISECONDS;
			return ((elapsed * invNano) * (double)MILLISECONDS);
		}
	}

	void BenchmarkTimer::time_function_parallel(std::function<void()> f, const char* message)
	{
		if (!_pool)
		{
			_pool = new ThreadLib::PoolThread(2);
			_pool->ChangeMaxWaitingQueueThread(1);
		}
		auto l = [f, message] { BenchmarkTimer().time_function(f, message); };
		_pool->AddTask(new TaskThreadLib::TaskTemplated::TaskTemplate<>(l));
	}

	void BenchmarkTimer::time_function(std::function<void()> f, const char* message)
	{
		start();
		f();
		stop();
		_mutex.lock();
		print(AUTO, message);
		_mutex.unlock();
	}

	void BenchmarkTimer::wait_end_of_task()
	{
		_pool->FinishAllTaskThenContinue();
	}
}