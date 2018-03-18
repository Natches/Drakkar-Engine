#pragma once

#include <tuple>
#include <Threading/IFunction.hpp>

namespace drak {
namespace function {

template<int...idx>
struct index;

#pragma region GlobalFunction

template<class ReturnType, class...VArgs>
class GlobalFunction {
public:
	GlobalFunction() = delete;
	GlobalFunction(ReturnType(*func)(VArgs...), VArgs...args);
	GlobalFunction(ReturnType(*func)(VArgs...));
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void updateArgs(VArgs...args);

	virtual ReturnType operator()();
	virtual ReturnType invoke();

	virtual ReturnType operator()(VArgs...args);
	virtual ReturnType invoke(VArgs...args);

protected:
	GlobalFunction(const std::tuple<VArgs...>& args);
	GlobalFunction(std::tuple<VArgs...>&& args);
	std::tuple<VArgs...> m_args;

private:
	ReturnType(*m_pFunc)(VArgs...args);

private:
	template <int... Indices>
	ReturnType operator()(const index<Indices...>& i);
};

template<>
class GlobalFunction<void, void>
	: public IFunction {
public:
	GlobalFunction() = delete;
	GlobalFunction(void(*func)());
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	virtual void operator()() override;
	virtual void invoke() override;

private:
	void(*m_pFunc)();
};

template<class...VArgs>
class GlobalFunction<void, VArgs...>
	: public IFunction {
public:
	GlobalFunction() = delete;
	GlobalFunction(void(*func)(VArgs...), VArgs...args);
	GlobalFunction(void(*func)(VArgs...));
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void updateArgs(VArgs...args);

	virtual void operator()() override;
	virtual void invoke() override;

	virtual void operator()(VArgs...args);
	virtual void invoke(VArgs...args);

protected:
	GlobalFunction(const std::tuple<VArgs...>& args);
	GlobalFunction(std::tuple<VArgs...>&& args);
	std::tuple<VArgs...> m_args;

private:
	void(*m_pFunc)(VArgs...args);

private:
	template <int... Indices>
	void operator()(const index<Indices...>& i);
};

template<class ReturnType>
class GlobalFunction<ReturnType, void> {

public:
	GlobalFunction() = delete;
	GlobalFunction(ReturnType(*func)());
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	virtual ReturnType operator()();
	virtual ReturnType invoke();
private:
	ReturnType(*m_pFunc)();
};

#pragma endregion GlobalFunction

#pragma region MemberFunction

template<class ReturnType, class CallerType, class...VArgs>
class MemberFunction
	: public GlobalFunction<ReturnType, VArgs...> {
public:
	MemberFunction() = delete;
	MemberFunction(CallerType* caller, ReturnType(CallerType::*func)(VArgs...), VArgs...args);
	MemberFunction(ReturnType(CallerType::*func)(VArgs...));
	virtual ~MemberFunction() = default;

	MemberFunction(const MemberFunction& mf);
	MemberFunction(MemberFunction&& mf);
	void operator=(const MemberFunction& mf);
	void operator=(MemberFunction&& mf);

	bool operator==(const MemberFunction& mf);
	bool operator!=(const MemberFunction& mf);

	bool operator==(const GlobalFunction<VArgs...>& gf);
	bool operator!=(const GlobalFunction<VArgs...>& gf);

	void caller(CallerType* caller) { m_pCaller = caller; };
	CallerType* caller() { return m_pCaller; };

	virtual ReturnType operator()() override;
	virtual ReturnType invoke()override;

	ReturnType operator()(CallerType* caller, VArgs...args);
	ReturnType invoke(CallerType* caller, VArgs...args);

	virtual ReturnType operator()(VArgs...args)override;
	virtual ReturnType invoke(VArgs...args)override;

private:
	ReturnType(CallerType::*m_pFunc)(VArgs...args);

private:
	template <int... Indices>
	ReturnType operator()(const index<Indices...>& i);

protected:
	CallerType* m_pCaller;
};

#pragma endregion MemberFunction

} // namespace function
} // namespace drak

#include <Threading/Function.inl>