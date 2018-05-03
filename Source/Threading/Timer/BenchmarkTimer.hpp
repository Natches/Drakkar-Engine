#pragma once

#include <mutex>
#include <Core/Timer/ATimer.hpp>
#include <Threading/Task/TaskGroup.hpp>

namespace drak {
namespace thread {
namespace task {
template<typename func>
class Task;
} // namespace task
class ThreadPool;
} // namespace thread
namespace function {
class IFunction;
template<typename Caller, typename Return, typename...VArgs>
class MemberFunction;
} // namespace thread

namespace time {
class BenchmarkTimer final
	: public ATimer {
	using Member = drak::function::MemberFunction<BenchmarkTimer, void, drak::function::IFunction*, const char*>;
	DK_NONMOVABLE_NONCOPYABLE(BenchmarkTimer)
public:
	BenchmarkTimer() = delete;
	BenchmarkTimer(drak::thread::ThreadPool& pool);
	virtual ~BenchmarkTimer() = default;

	virtual F32 duration(const TimeDuration duration_type, TimeDuration* duration_type_returned = nullptr) override;
	virtual void start() override;
	virtual void stop() override;
	virtual void reset(const bool enabled) override;

	void print(TimeDuration duration_type, const char* message = "");
	void addFunction(drak::function::IFunction* f, const char* msg = "");
	void timeFunctionInParallel();
	void timeFunctions();
	void waitEndOfTasks();

private:
	virtual void pause()override {};
	virtual void resume()override {};
	void time(drak::function::IFunction* f, const char* msg = "");

private:
	static std::mutex m_mutex;
	drak::thread::task::TaskGroup<drak::thread::task::Task<Member>> m_grp;
	drak::thread::ThreadPool& m_pool;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_end;
};

} // namespace time
} // namespace drak