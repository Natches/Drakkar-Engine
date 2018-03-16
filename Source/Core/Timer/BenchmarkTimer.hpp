#pragma once

#include <mutex>
#include "ATimer.h"

namespace ThreadLib
{
	class PoolThread;
}
namespace NLib
{

	class BenchmarkTimer final
		: public ATimer
	{
	public:
		BenchmarkTimer();
		virtual ~BenchmarkTimer();

		virtual inline void start()override { _begin = current_time(); };
		virtual inline void stop() override { _end = current_time(); };
		virtual double duration(E_TIME_DURATION duration_type, E_TIME_DURATION* duration_type_returned = nullptr)override;

		void print(E_TIME_DURATION duration_type, const char* message = "");
		void time_function_parallel(std::function<void()> f, const char* message = "");
		void time_function(std::function<void()> f, const char* message = "");
		void wait_end_of_task();

	private:
		virtual void pause()override {};
		virtual void resume()override {};

	private:
		static std::mutex _mutex;
		ThreadLib::PoolThread* _pool;
		std::chrono::time_point<std::chrono::high_resolution_clock> _end;
	};

}