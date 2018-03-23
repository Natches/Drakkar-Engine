#pragma once

namespace drak {
namespace function {

class IFunction {
public:
	IFunction() = default;
	~IFunction() = default;

	virtual void operator()() = 0;
	virtual void invoke() = 0;
};

} // namespace function
} // namespace drak
