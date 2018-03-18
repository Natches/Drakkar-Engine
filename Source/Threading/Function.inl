#include <Threading/Function.hpp>
#include <Threading/IndicesTrick.hpp>

namespace drak {
namespace function {

#pragma region Global Function
	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(ReturnType(*func)(VArgs...), VArgs ...args)
		: m_pFunc(func), m_args(std::forward<VArgs>(args)...)
	{
	}

	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(const std::tuple<VArgs...>& args)
		: m_args(args)
	{
	}

	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(std::tuple<VArgs...>&& args)
		: m_args(std::move(args))
	{
	}

	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(ReturnType(*func)(VArgs...))
		: m_pFunc(func)
	{
	}

	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(const GlobalFunction& gf)
		: m_pFunc(gf.m_pFunc), m_args(gf.m_args)
	{
	}

	template<class ReturnType, class ...VArgs>
	GlobalFunction<ReturnType, VArgs...>::GlobalFunction(GlobalFunction&& gf)
		: m_pFunc(std::move(gf.m_pFunc)), m_args(std::move(gf.m_args))
	{
	}

	template<class ReturnType, class ...VArgs>
	void GlobalFunction<ReturnType, VArgs...>::operator=(const GlobalFunction& gf)
	{
		m_pFunc = gf.m_pFunc;
		m_args = gf.m_args;
	}

	template<class ReturnType, class ...VArgs>
	void GlobalFunction<ReturnType, VArgs...>::operator=(GlobalFunction&& gf)
	{
		m_pFunc = std::move(gf.m_pFunc);
		m_args = std::move(gf.m_args);
	}

	template<class ReturnType, class ...VArgs>
	bool GlobalFunction<ReturnType, VArgs...>::operator==(const GlobalFunction& gf)
	{
		return m_pFunc == (gf.m_pFunc) && m_args == gf.m_args;
	}

	template<class ReturnType, class ...VArgs>
	bool GlobalFunction<ReturnType, VArgs...>::operator!=(const GlobalFunction& gf)
	{
		return !(*this == gf);
	}

	template<class ReturnType, class ...VArgs>
	void GlobalFunction<ReturnType, VArgs...>::updateArgs(VArgs ...args)
	{
		m_args = std::make_tuple<VArgs...>(std::forward<VArgs>(args)...);
	}

	template<class ReturnType, class ...VArgs>
	ReturnType GlobalFunction<ReturnType, VArgs...>::operator()()
	{
		return operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class ...VArgs>
	ReturnType GlobalFunction<ReturnType, VArgs...>::invoke()
	{
		return operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class ...VArgs>
	void GlobalFunction<ReturnType, VArgs...>::operator()() {
		operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class ...VArgs>
	void GlobalFunction<ReturnType, VArgs...>::invoke() {
		operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class ...VArgs>
	ReturnType GlobalFunction<ReturnType, VArgs...>::operator()(VArgs ...args)
	{
		updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class ...VArgs>
	ReturnType GlobalFunction<ReturnType, VArgs...>::invoke(VArgs ...args)
	{
		updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class ...VArgs>
	template<int ...Indices>
	ReturnType GlobalFunction<ReturnType, VArgs...>::operator()(const index<Indices...>& i)
	{
		return m_pFunc(std::get<Indices>(std::forward<std::tuple<VArgs...>>(m_args))...);
	}
#pragma endregion

#pragma region Member Function
	template<class ReturnType, class CallerType, class ...VArgs>
	MemberFunction<ReturnType, CallerType, VArgs...>::MemberFunction(CallerType* caller, ReturnType(CallerType::* func)(VArgs...), VArgs ...args)
		: GlobalFunction<VArgs...>([](VArgs...) {}, std::forward<VArgs>(args)...), m_pFunc(func), m_pCaller(caller)
	{
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	MemberFunction<ReturnType, CallerType, VArgs...>::MemberFunction(ReturnType(CallerType::* func)(VArgs...))
		: GlobalFunction<VArgs...>([](VArgs...) {}), m_pFunc(func)
	{
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	MemberFunction<ReturnType, CallerType, VArgs...>::MemberFunction(const MemberFunction& mf)
		: GlobalFunction<VArgs...>(mf.m_args), m_pFunc(mf.m_pFunc), m_pCaller(mf.m_pCaller)
	{
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	MemberFunction<ReturnType, CallerType, VArgs...>::MemberFunction(MemberFunction&& mf)
		: GlobalFunction<VArgs...>(std::move(mf.m_args)), m_pFunc(std::move(mf.m_pFunc)), m_pCaller(std::move(mf.m_pCaller))
	{
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	void MemberFunction<ReturnType, CallerType, VArgs...>::operator=(const MemberFunction& mf)
	{
		m_pFunc = mf.m_pFunc;
		m_pCaller = mf.m_pCaller;
		m_args = mf.m_args;
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	void MemberFunction<ReturnType, CallerType, VArgs...>::operator=(MemberFunction&& mf)
	{
		m_pFunc = std::move(mf.m_pFunc);
		m_pCaller = std::move(mf.m_pCaller);
		m_args = std::move(mf.m_args);
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	bool MemberFunction<ReturnType, CallerType, VArgs...>::operator==(const MemberFunction& mf)
	{
		return (m_pCaller == mf.m_pCaller && m_args == mf.m_args && m_pFunc == mf.m_pFunc);
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	bool MemberFunction<ReturnType, CallerType, VArgs...>::operator!=(const MemberFunction& mf)
	{
		return !(*this == mf);
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	bool MemberFunction<ReturnType, CallerType, VArgs...>::operator==(const GlobalFunction<VArgs...>& gf)
	{
		return false;
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	bool MemberFunction<ReturnType, CallerType, VArgs...>::operator!=(const GlobalFunction<VArgs...>& gf)
	{
		return true;
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::operator()()
	{
		return operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::invoke()
	{
		return operator()(BuildIndex<sizeof...(VArgs)>());
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::operator()(CallerType* caller, VArgs ...args)
	{
		m_pCaller = caller;
		this->updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::invoke(CallerType* caller, VArgs ...args)
	{
		m_pCaller = caller;
		this->updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::operator()(VArgs ...args)
	{
		this->updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::invoke(VArgs ...args)
	{
		this->updateArgs(std::forward<VArgs>(args)...);
		return invoke();
	}

	template<class ReturnType, class CallerType, class ...VArgs>
	template<int ...Indices>
	ReturnType MemberFunction<ReturnType, CallerType, VArgs...>::operator()(const index<Indices...>& i)
	{
		if (m_pCaller)
			return (m_pCaller->*m_pFunc)(std::get<Indices>(std::forward<std::tuple<VArgs...>>(this->m_args))...);
	}
#pragma endregion

} // namespace function
} // namespace drak 
