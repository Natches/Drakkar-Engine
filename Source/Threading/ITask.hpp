#pragma once

namespace drak {
namespace thread {

class ITask {

public:
	virtual void operator()() = 0;
	virtual void invoke() = 0;

};

} //namespace thread
} //namespace drak