#pragma once

#include <atomic>

namespace drak {
namespace thread {
namespace task {

class ATask {

public:
	virtual void operator()() = 0;
	virtual void execute() = 0;

	bool executed();
	void reset();

protected:
	std::atomic<bool> m_executed;
};

} // namespace task
} // namespace thread
} // namespace drak