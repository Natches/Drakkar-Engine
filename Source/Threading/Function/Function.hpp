#pragma once

#include <tuple>
#include <Threading/Function/IFunction.hpp>

namespace drak {
namespace function {

template<int...idx>
struct index;

#pragma region GlobalFunction

template<class ReturnType, class...VArgs>
class GlobalFunction {
public:
	GlobalFunction() = default;
	GlobalFunction(ReturnType(*func)(VArgs...), VArgs&&...args);
	GlobalFunction(ReturnType(*func)(VArgs...));
	~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void args(VArgs&&...args);
	void function(ReturnType(*func)(VArgs...));

	virtual ReturnType operator()();
	virtual ReturnType invoke();

	virtual ReturnType operator()(VArgs&&...args);
	virtual ReturnType invoke(VArgs&&...args);

	using RetType = typename ReturnType;

protected:
	GlobalFunction(const std::tuple<VArgs...>& args);
	GlobalFunction(std::tuple<VArgs...>&& args);
	std::tuple<VArgs...> m_args;

private:
	ReturnType(*m_pFunc)(VArgs...);

private:
	template <int... Indices>
	ReturnType operator()(const index<Indices...>& i);
};

template<class...VArgs>
class GlobalFunction<void, VArgs...>
	: public IFunction {
public:
	GlobalFunction() = default;
	GlobalFunction(void(*func)(VArgs...), VArgs&&...args);
	GlobalFunction(void(*func)(VArgs...));
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void args(VArgs&&...args);
	void function(void(*func)(VArgs...));

	virtual void operator()() override;
	virtual void invoke() override;

	virtual void operator()(VArgs&&...args);
	virtual void invoke(VArgs&&...args);

protected:
	GlobalFunction(const std::tuple<VArgs...>& args);
	GlobalFunction(std::tuple<VArgs...>&& args);
	std::tuple<VArgs...> m_args;

private:
	void(*m_pFunc)(VArgs...);

private:
	template <int... Indices>
	void operator()(const index<Indices...>& i);
};

template<class ReturnType>
class GlobalFunction<ReturnType, void> {

public:
	GlobalFunction() = default;
	GlobalFunction(ReturnType(*func)());
	~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void function(ReturnType(*func)());

	virtual ReturnType operator()();
	virtual ReturnType invoke();

	using RetType = typename ReturnType;
private:
	ReturnType(*m_pFunc)();
};

template<>
class GlobalFunction<void, void>
	: public IFunction {
public:
	GlobalFunction() = default;
	GlobalFunction(void(*func)());
	virtual ~GlobalFunction() = default;

	GlobalFunction(const GlobalFunction& gf);
	GlobalFunction(GlobalFunction&& gf);
	void operator=(const GlobalFunction& gf);
	void operator=(GlobalFunction&& gf);

	bool operator==(const GlobalFunction& gf);
	bool operator!=(const GlobalFunction& gf);

	void function(void(*func)());

	virtual void operator()() override;
	virtual void invoke() override;

private:
	void(*m_pFunc)();
};

#pragma endregion GlobalFunction

#pragma region MemberFunction

template<class CallerType, class ReturnType, class...VArgs>
class MemberFunction
	: public GlobalFunction<ReturnType, VArgs...> {
public:
	MemberFunction() = default;
	MemberFunction(CallerType* caller, ReturnType(CallerType::*func)(VArgs...));
	MemberFunction(CallerType* caller, ReturnType(CallerType::*func)(VArgs...), VArgs&&...args);
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

	void function(ReturnType(CallerType::*func)(VArgs...));

	virtual ReturnType operator()() override;
	virtual ReturnType invoke()override;

	ReturnType operator()(CallerType* caller, VArgs&&...args);
	ReturnType invoke(CallerType* caller, VArgs&&...args);

	virtual ReturnType operator()(VArgs&&...args)override;
	virtual ReturnType invoke(VArgs&&...args)override;

	using RetType = typename ReturnType;

private:
	ReturnType(CallerType::*m_pFunc)(VArgs...);

private:
	template <int... Indices>
	ReturnType operator()(const index<Indices...>& i);

protected:
	CallerType* m_pCaller;
};

template<class CallerType, class...VArgs>
class MemberFunction<CallerType, void, VArgs...>
	: public GlobalFunction<void, VArgs...> {
public:
	MemberFunction() = default;
	MemberFunction(CallerType* caller, void(CallerType::*func)(VArgs...));
	MemberFunction(CallerType* caller, void(CallerType::*func)(VArgs...), VArgs&&...args);
	MemberFunction(void(CallerType::*func)(VArgs...));
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

	void function(void(CallerType::*func)(VArgs...));

	virtual void operator()() override;
	virtual void invoke()override;

	void operator()(CallerType* caller, VArgs&&...args);
	void invoke(CallerType* caller, VArgs&&...args);

	virtual void operator()(VArgs&&...args)override;
	virtual void invoke(VArgs&&...args)override;

private:
	void(CallerType::*m_pFunc)(VArgs...);

private:
	template <int... Indices>
	void operator()(const index<Indices...>& i);

protected:
	CallerType* m_pCaller;
};

template<class CallerType, class ReturnType>
class MemberFunction<CallerType, ReturnType, void> {
public:
	MemberFunction() = default;
	MemberFunction(CallerType* caller, ReturnType(CallerType::*func)());
	MemberFunction(ReturnType(CallerType::*func)());
	virtual ~MemberFunction() = default;

	MemberFunction(const MemberFunction& mf);
	MemberFunction(MemberFunction&& mf);
	void operator=(const MemberFunction& mf);
	void operator=(MemberFunction&& mf);

	bool operator==(const MemberFunction& mf);
	bool operator!=(const MemberFunction& mf);

	void caller(CallerType* caller) { m_pCaller = caller; };
	CallerType* caller() { return m_pCaller; };

	void function(ReturnType(CallerType::*func)());

	ReturnType operator()();
	ReturnType invoke();

	ReturnType operator()(CallerType* caller);
	ReturnType invoke(CallerType* caller);
	using RetType = typename ReturnType;

private:
	ReturnType(CallerType::*m_pFunc)();

protected:
	CallerType* m_pCaller;
};

template<class CallerType>
class MemberFunction<CallerType, void, void>
	: public IFunction {
public:
	MemberFunction() = default;
	MemberFunction(CallerType* caller, void(CallerType::*func)());
	MemberFunction(void(CallerType::*func)());
	virtual ~MemberFunction() = default;

	MemberFunction(const MemberFunction& mf);
	MemberFunction(MemberFunction&& mf);
	void operator=(const MemberFunction& mf);
	void operator=(MemberFunction&& mf);

	bool operator==(const MemberFunction& mf);
	bool operator!=(const MemberFunction& mf);

	void caller(CallerType* caller) { m_pCaller = caller; };
	CallerType* caller() { return m_pCaller; };

	void function(void(CallerType::*func)());

	virtual void operator()() override;
	virtual void invoke() override;

	void operator()(CallerType* caller);
	void invoke(CallerType* caller);

private:
	void(CallerType::*m_pFunc)();

protected:
	CallerType* m_pCaller;
};

#pragma endregion MemberFunction

#pragma region Lambda
#include <functional>
template<class T, class Y>
std::function<T> makeLambda(Y&& t) 	{
	return std::function<T>(t);
}
#pragma endregion Lambda

} // namespace function
} // namespace drak

#include <Threading/Function/Function.inl>