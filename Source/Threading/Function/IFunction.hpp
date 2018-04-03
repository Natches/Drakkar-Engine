#pragma once

namespace drak {
namespace function {

class IFunction {
public:
	IFunction() = default;
	virtual ~IFunction() = default;

	virtual void operator()() = 0;
	virtual void invoke() = 0;
};

template<class Caller>
class IMemberFunction {
public:
	IMemberFunction() = default;
	virtual ~IMemberFunction() = default;

	virtual void operator()() = 0;
	virtual void invoke() = 0;

	virtual void operator()(Caller* caller) = 0;
	virtual void invoke(Caller* caller) = 0;

private:
	Caller* caller;
};

} // namespace function
} // namespace drak
