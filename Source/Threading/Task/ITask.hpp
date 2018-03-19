#pragma once

namespace drak {
namespace thread {
namespace task {

class ITask {

public:
	virtual void operator()() = 0;
	virtual void execute() = 0;

};

} // namespace task
} // namespace thread
} // namespace drak