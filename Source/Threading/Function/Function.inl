#include <Threading/Function/Function.hpp>
#include <Threading/Function/IndicesTrick.hpp>
#include <Log/Log.hpp>

namespace drak {
namespace function {

#pragma region Global Function
#pragma region No-Specialization
template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(ReturnType(*func)(VArgs...),
	VArgs&&...args) : m_pFunc(func), m_args(std::forward<VArgs>(args)...) {
}

template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(const std::tuple<VArgs...>& args)
	: m_args(args) {
}

template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(std::tuple<VArgs...>&& args)
	: m_args(std::move(args)) {
}

template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(ReturnType(*func)(VArgs...))
	: m_pFunc(func) {
}

template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(const GlobalFunction& gf)
	: m_pFunc(gf.m_pFunc), m_args(gf.m_args) {
}

template<class ReturnType, class ...VArgs>
GlobalFunction<ReturnType, VArgs...>::GlobalFunction(GlobalFunction&& gf)
	: m_pFunc(std::move(gf.m_pFunc)), m_args(std::move(gf.m_args)) {
}

template<class ReturnType, class ...VArgs>
void GlobalFunction<ReturnType, VArgs...>::operator=(const GlobalFunction& gf) {
	m_pFunc = gf.m_pFunc;
	m_args = gf.m_args;
}

template<class ReturnType, class ...VArgs>
void GlobalFunction<ReturnType, VArgs...>::operator=(GlobalFunction&& gf) {
	m_pFunc = std::move(gf.m_pFunc);
	m_args = std::move(gf.m_args);
}

template<class ReturnType, class ...VArgs>
bool GlobalFunction<ReturnType, VArgs...>::operator==(const GlobalFunction& gf) {
	return m_pFunc == (gf.m_pFunc) && m_args == gf.m_args;
}

template<class ReturnType, class ...VArgs>
bool GlobalFunction<ReturnType, VArgs...>::operator!=(const GlobalFunction& gf) {
	return !(*this == gf);
}

template<class ReturnType, class ...VArgs>
void GlobalFunction<ReturnType, VArgs...>::args(VArgs&&...args) {
	m_args = std::make_tuple<VArgs...>(std::forward<VArgs>(args)...);
}

template<class ReturnType, class ...VArgs>
void GlobalFunction<ReturnType, VArgs...>::function(ReturnType(*func)(VArgs...)) {
	m_pFunc = func;
}

template<class ReturnType, class ...VArgs>
ReturnType GlobalFunction<ReturnType, VArgs...>::operator()() {
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ReturnType, class ...VArgs>
ReturnType GlobalFunction<ReturnType, VArgs...>::invoke() {
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ReturnType, class ...VArgs>
ReturnType GlobalFunction<ReturnType, VArgs...>::operator()(VArgs&&...args) {
	args(std::forward<VArgs>(args)...);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ReturnType, class ...VArgs>
ReturnType GlobalFunction<ReturnType, VArgs...>::invoke(VArgs&&...args) {
	args(std::forward<VArgs>(args)...);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ReturnType, class ...VArgs>
template<int ...Indices>
ReturnType GlobalFunction<ReturnType, VArgs...>::operator()(const index<Indices...>& i) {
	return m_pFunc(std::get<Indices>(std::forward<std::tuple<VArgs...>>(m_args))...);
}
#pragma endregion
#pragma region PartialSpecialization void VArgs
template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(void(*func)(VArgs...), VArgs&&...args)
	: m_pFunc(func), m_args(std::forward<VArgs>(args)...) {
}

template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(void(*func)(VArgs...)) : m_pFunc(func) {
}

template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(const std::tuple<VArgs...>& args)
	: m_args(args) {
}

template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(std::tuple<VArgs...>&& args)
	: m_args(std::move(args)) {
}

template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(const GlobalFunction& gf)
	: m_pFunc(gf.m_pFunc), m_args(gf.m_args) {
}

template<class ...VArgs>
GlobalFunction<void, VArgs...>::GlobalFunction(GlobalFunction&& gf)
	: m_pFunc(std::move(gf.m_pFunc)), m_args(std::move(gf.m_args)) {
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::operator=(const GlobalFunction& gf) {
	m_pFunc = gf.m_pFunc;
	m_args = gf.m_args;
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::operator=(GlobalFunction&& gf) {
	m_pFunc = std::move(gf.m_pFunc);
	m_args = std::move(gf.m_args);
}

template<class ...VArgs>
bool GlobalFunction<void, VArgs...>::operator==(const GlobalFunction& gf) {
	return m_pFunc == (gf.m_pFunc) && m_args == gf.m_args;
}

template<class ...VArgs>
bool GlobalFunction<void, VArgs...>::operator!=(const GlobalFunction& gf) {
	return !(*this == gf);
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::args(VArgs&&...args) {
	m_args = std::make_tuple<VArgs...>(std::forward<VArgs>(args)...);
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::function(void(*func)(VArgs...)) {
	m_pFunc = func;
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::operator()() {
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::invoke() {
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::operator()(VArgs&&...args) {
	args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ...VArgs>
void GlobalFunction<void, VArgs...>::invoke(VArgs&&...args) {
	args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class ...VArgs>
template<int ...Indices>
void GlobalFunction<void, VArgs...>::operator()(const index<Indices...>& i) {
	m_pFunc(std::get<Indices>(std::forward<std::tuple<VArgs...>>(m_args))...);
}
#pragma endregion
#pragma region PartialSpecialization ReturnType void
template<class ReturnType>
GlobalFunction<ReturnType, void>::GlobalFunction(ReturnType(*func)()) : m_pFunc(func) {
}

template<class ReturnType>
GlobalFunction<ReturnType, void>::GlobalFunction(const GlobalFunction& gf)
	: m_pFunc(gf.m_pFunc) {
}

template<class ReturnType>
GlobalFunction<ReturnType, void>::GlobalFunction(GlobalFunction&& gf)
	: m_pFunc(std::move(gf.m_pFunc)) {
}

template<class ReturnType>
void GlobalFunction<ReturnType, void>::operator=(const GlobalFunction& gf) {
	m_pFunc = gf.m_pFunc;
}

template<class ReturnType>
void GlobalFunction<ReturnType, void>::operator=(GlobalFunction&& gf) {
	m_pFunc = std::move(gf.m_pFunc);
}

template<class ReturnType>
bool GlobalFunction<ReturnType, void>::operator==(const GlobalFunction& gf) {
	return m_pFunc == (gf.m_pFunc);
}

template<class ReturnType>
bool GlobalFunction<ReturnType, void>::operator!=(const GlobalFunction& gf) {
	return !(*this == gf);
}

template<class ReturnType>
void GlobalFunction<ReturnType, void>::function(ReturnType(*func)()) {
	m_pFunc = func;
}

template<class ReturnType>
ReturnType GlobalFunction<ReturnType, void>::operator()() {
	return m_pFunc();
}

template<class ReturnType>
ReturnType GlobalFunction<ReturnType, void>::invoke() {
	return m_pFunc();
}

#pragma endregion
#pragma region Specialization void void
GlobalFunction<void, void>::GlobalFunction(void(*func)()) : m_pFunc(func) {
}

GlobalFunction<void, void>::GlobalFunction(const GlobalFunction& gf)
	: m_pFunc(gf.m_pFunc) {
}

GlobalFunction<void, void>::GlobalFunction(GlobalFunction&& gf)
	: m_pFunc(std::move(gf.m_pFunc)) {
}

void GlobalFunction<void, void>::operator=(const GlobalFunction& gf) {
	m_pFunc = gf.m_pFunc;
}

void GlobalFunction<void, void>::operator=(GlobalFunction&& gf) {
	m_pFunc = std::move(gf.m_pFunc);
}

bool GlobalFunction<void, void>::operator==(const GlobalFunction& gf) {
	return m_pFunc == (gf.m_pFunc);
}

bool GlobalFunction<void, void>::operator!=(const GlobalFunction& gf) {
	return !(*this == gf);
}

void GlobalFunction<void, void>::function(void(*func)()) {
	m_pFunc = func;
}

void GlobalFunction<void, void>::operator()() {
	m_pFunc();
}

void GlobalFunction<void, void>::invoke() {
	m_pFunc();
}
#pragma endregion
#pragma endregion

#pragma region Member Function
#pragma region No-Specialization

template<class CallerType, class ReturnType, class ...VArgs>
MemberFunction<CallerType, ReturnType, VArgs...>::MemberFunction(CallerType* caller,
	ReturnType(CallerType::*func)(VArgs...)) : m_pFunc(func), m_pCaller(caller) {
}

template<class CallerType, class ReturnType, class...VArgs>
MemberFunction<CallerType, ReturnType, VArgs...>::MemberFunction(CallerType* caller,
	ReturnType(CallerType::* func)(VArgs...), VArgs&&...args)
	: GlobalFunction<ReturnType, VArgs...>(std::make_tuple<VArgs>(std::forward<VArgs>(args)...)...),
	m_pFunc(func), m_pCaller(caller) {
}

template<class CallerType, class ReturnType, class...VArgs>
MemberFunction<CallerType, ReturnType, VArgs...>::MemberFunction
(ReturnType(CallerType::* func)(VArgs...)) : m_pFunc(func) {
}

template<class CallerType, class ReturnType, class...VArgs>
MemberFunction<CallerType, ReturnType, VArgs...>::MemberFunction(const MemberFunction& mf)
	: GlobalFunction<ReturnType, VArgs...>(mf.m_args), m_pFunc(mf.m_pFunc),
	m_pCaller(mf.m_pCaller) {
}

template<class CallerType, class ReturnType, class...VArgs>
MemberFunction<CallerType, ReturnType, VArgs...>::MemberFunction(MemberFunction&& mf)
	: GlobalFunction<ReturnType, VArgs...>(std::move(mf.m_args)), m_pFunc(std::move(mf.m_pFunc)),
	m_pCaller(std::move(mf.m_pCaller)) {
}

template<class CallerType, class ReturnType, class...VArgs>
void MemberFunction<CallerType, ReturnType, VArgs...>::operator=(const MemberFunction& mf) {
	m_pFunc = mf.m_pFunc;
	m_pCaller = mf.m_pCaller;
	m_args = mf.m_args;
}

template<class CallerType, class ReturnType, class...VArgs>
void MemberFunction<CallerType, ReturnType, VArgs...>::operator=(MemberFunction&& mf) {
	m_pFunc = std::move(mf.m_pFunc);
	m_pCaller = std::move(mf.m_pCaller);
	m_args = std::move(mf.m_args);
}

template<class CallerType, class ReturnType, class...VArgs>
bool MemberFunction<CallerType, ReturnType, VArgs...>::operator==(const MemberFunction& mf) {
	return (m_pCaller == mf.m_pCaller && m_args == mf.m_args && m_pFunc == mf.m_pFunc);
}

template<class CallerType, class ReturnType, class...VArgs>
bool MemberFunction<CallerType, ReturnType, VArgs...>::operator!=(const MemberFunction& mf) {
	return !(*this == mf);
}

template<class CallerType, class ReturnType, class...VArgs>
bool MemberFunction<CallerType, ReturnType, VArgs...>::operator==
(const GlobalFunction<VArgs...>& gf) {
	return false;
}

template<class CallerType, class ReturnType, class...VArgs>
bool MemberFunction<CallerType, ReturnType, VArgs...>::operator!=
(const GlobalFunction<VArgs...>& gf) {
	return true;
}

template<class CallerType, class ReturnType, class ...VArgs>
void MemberFunction<CallerType, ReturnType, VArgs...>::function
(ReturnType(CallerType::* func)(VArgs...)) {
	m_pFunc = func;
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::operator()() {
	assert(m_pCaller);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::invoke() {
	assert(m_pCaller);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::operator()(CallerType* caller,
	VArgs&&...args) {
	assert(caller);
	m_pCaller = caller;
	args(std::forward<VArgs>(args)...);
	return invoke();
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::invoke(CallerType* caller,
	VArgs&&...args) {
	assert(caller);
	m_pCaller = caller;
	args(std::forward<VArgs>(args)...);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::operator()(VArgs&&...args) {
	assert(m_pCaller);
	args(std::forward<VArgs>(args)...);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class ReturnType, class...VArgs>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::invoke(VArgs&&...args) {
	assert(m_pCaller);
	args(std::forward<VArgs>(args)...);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class ReturnType, class...VArgs>
template<int ...Indices>
ReturnType MemberFunction<CallerType, ReturnType, VArgs...>::operator()
(const index<Indices...>& i) {
	assert(m_pCaller);
	if (!m_pCaller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	return (m_pCaller->*m_pFunc)
		(std::get<Indices>(std::forward<std::tuple<VArgs...>>(this->m_args))...);
}
#pragma endregion
#pragma region PartialSpecialization CallerType void VArgs
template<class CallerType, class ...VArgs>
MemberFunction<CallerType, void, VArgs...>::MemberFunction(CallerType * caller,
	void(CallerType::* func)(VArgs...)) : m_pFunc(func), m_pCaller(caller) {
}
template<class CallerType, class...VArgs>
MemberFunction<CallerType, void, VArgs...>::MemberFunction(CallerType* caller,
	void(CallerType::* func)(VArgs...), VArgs&&...args)
	: GlobalFunction<void, VArgs...>(std::make_tuple<VArgs>(std::forward<VArgs>(args)...)...),
	m_pFunc(func), m_pCaller(caller) {
}

template<class CallerType, class...VArgs>
MemberFunction<CallerType, void, VArgs...>::MemberFunction(void(CallerType::* func)(VArgs...))
	: m_pFunc(func) {
}

template<class CallerType, class...VArgs>
MemberFunction<CallerType, void, VArgs...>::MemberFunction(const MemberFunction& mf)
	: GlobalFunction<VArgs...>(mf.m_args), m_pFunc(mf.m_pFunc), m_pCaller(mf.m_pCaller) {
}

template<class CallerType, class...VArgs>
MemberFunction<CallerType, void, VArgs...>::MemberFunction(MemberFunction&& mf)
	: GlobalFunction<VArgs...>(std::move(mf.m_args)), m_pFunc(std::move(mf.m_pFunc)),
	m_pCaller(std::move(mf.m_pCaller)) {
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::operator=(const MemberFunction& mf) {
	m_pFunc = mf.m_pFunc;
	m_pCaller = mf.m_pCaller;
	m_args = mf.m_args;
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::operator=(MemberFunction&& mf) {
	m_pFunc = std::move(mf.m_pFunc);
	m_pCaller = std::move(mf.m_pCaller);
	m_args = std::move(mf.m_args);
}

template<class CallerType, class...VArgs>
bool MemberFunction<CallerType, void, VArgs...>::operator==(const MemberFunction& mf) {
	return (m_pCaller == mf.m_pCaller && m_args == mf.m_args && m_pFunc == mf.m_pFunc);
}

template<class CallerType, class...VArgs>
bool MemberFunction<CallerType, void, VArgs...>::operator!=(const MemberFunction& mf) {
	return !(*this == mf);
}

template<class CallerType, class...VArgs>
bool MemberFunction<CallerType, void, VArgs...>::operator==(const GlobalFunction<VArgs...>& gf) {
	return false;
}

template<class CallerType, class...VArgs>
bool MemberFunction<CallerType, void, VArgs...>::operator!=(const GlobalFunction<VArgs...>& gf) {
	return true;
}

template<class CallerType, class ...VArgs>
void MemberFunction<CallerType, void, VArgs...>::function(void(CallerType::* func)(VArgs...)) {
	m_pFunc = func;
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::operator()() {
	assert(m_pCaller);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::invoke() {
	assert(m_pCaller);
	return operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::operator()(CallerType* caller, VArgs&&...args) {
	assert(caller);
	m_pCaller = caller;
	args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::invoke(CallerType* caller, VArgs&&...args) {
	assert(caller);
	m_pCaller = caller;
	this->args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::operator()(VArgs&&...args) {
	assert(m_pCaller);
	args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
void MemberFunction<CallerType, void, VArgs...>::invoke(VArgs&&...args) {
	assert(m_pCaller);
	args(std::forward<VArgs>(args)...);
	operator()(BuildIndex<sizeof...(VArgs)>());
}

template<class CallerType, class...VArgs>
template<int ...Indices>
void MemberFunction<CallerType, void, VArgs...>::operator()(const index<Indices...>& i) {
	if (m_pCaller)
		(m_pCaller->*m_pFunc)
		(std::get<Indices>(std::forward<std::tuple<VArgs...>>(this->m_args))...);
	else {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
}
#pragma endregion
#pragma region PartialSpecialization CallerType ReturnType void
template<class CallerType, class ReturnType>
MemberFunction<CallerType, ReturnType, void>::MemberFunction(CallerType* caller,
	ReturnType(CallerType::* func)()) :  m_pFunc(func), m_pCaller(caller) {
}

template<class CallerType, class ReturnType>
MemberFunction<CallerType, ReturnType, void>::MemberFunction(ReturnType(CallerType::* func)())
	:  m_pFunc(func) {
}

template<class CallerType, class ReturnType>
MemberFunction<CallerType, ReturnType, void>::MemberFunction(const MemberFunction& mf)
	:  m_pCaller(mf.m_pCaller) {
}

template<class CallerType, class ReturnType>
MemberFunction<CallerType, ReturnType, void>::MemberFunction(MemberFunction&& mf)
	:  m_pFunc(std::move(mf.m_pFunc)), m_pCaller(std::move(mf.m_pCaller)) {
}

template<class CallerType, class ReturnType>
void MemberFunction<CallerType, ReturnType, void>::operator=(const MemberFunction& mf) {
	m_pFunc = mf.m_pFunc;
	m_pCaller = mf.m_pCaller;
}

template<class CallerType, class ReturnType>
void MemberFunction<CallerType, ReturnType, void>::operator=(MemberFunction&& mf) {
	m_pFunc = std::move(mf.m_pFunc);
	m_pCaller = std::move(mf.m_pCaller);
}

template<class CallerType, class ReturnType>
bool MemberFunction<CallerType, ReturnType, void>::operator==(const MemberFunction& mf) {
	return (m_pCaller == mf.m_pCaller && m_pFunc == mf.m_pFunc);
}

template<class CallerType, class ReturnType>
bool MemberFunction<CallerType, ReturnType, void>::operator!=(const MemberFunction& mf) {
	return !(*this == mf);
}

template<class CallerType, class ReturnType>
void MemberFunction<CallerType, ReturnType, void>::function(ReturnType(CallerType::* func)()) {
	m_pFunc = func;
}

template<class CallerType, class ReturnType>
ReturnType MemberFunction<CallerType, ReturnType, void>::operator()() {
	assert(m_pCaller);
	if (!m_pCaller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	return (m_pCaller->*m_pFunc)();
}

template<class CallerType, class ReturnType>
ReturnType MemberFunction<CallerType, ReturnType, void>::invoke() {
	assert(m_pCaller);
	if (!m_pCaller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	return (m_pCaller->*m_pFunc)();
}

template<class CallerType, class ReturnType>
ReturnType MemberFunction<CallerType, ReturnType, void>::operator()(CallerType* caller) {
	assert(caller);
	if (!caller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	m_pCaller = caller;
	return (m_pCaller->*m_pFunc)();
}

template<class CallerType, class ReturnType>
ReturnType MemberFunction<CallerType, ReturnType, void>::invoke(CallerType* caller) {
	assert(caller);
	if (!caller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	m_pCaller = caller;
	return (m_pCaller->*m_pFunc)();
}
#pragma endregion
#pragma region PartialSpecialization CallerType void void
template<class CallerType>
MemberFunction<CallerType, void, void>::MemberFunction(CallerType* caller,
	void(CallerType::* func)()) : m_pFunc(func), m_pCaller(caller) {
}

template<class CallerType>
MemberFunction<CallerType, void, void>::MemberFunction(void(CallerType::* func)())
	: m_pFunc(func) {
}

template<class CallerType>
MemberFunction<CallerType, void, void>::MemberFunction(const MemberFunction& mf)
	: m_pCaller(mf.m_pCaller) {
}

template<class CallerType>
MemberFunction<CallerType, void, void>::MemberFunction(MemberFunction&& mf)
	: m_pFunc(std::move(mf.m_pFunc)), m_pCaller(std::move(mf.m_pCaller)) {
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::operator=(const MemberFunction& mf) {
	m_pFunc = mf.m_pFunc;
	m_pCaller = mf.m_pCaller;
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::operator=(MemberFunction&& mf) {
	m_pFunc = std::move(mf.m_pFunc);
	m_pCaller = std::move(mf.m_pCaller);
}

template<class CallerType>
bool MemberFunction<CallerType, void, void>::operator==(const MemberFunction& mf) {
	return (m_pCaller == mf.m_pCaller && m_pFunc == mf.m_pFunc);
}

template<class CallerType>
bool MemberFunction<CallerType, void, void>::operator!=(const MemberFunction& mf) {
	return !(*this == mf);
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::function(void(CallerType::* func)()) {
	m_pFunc = func;
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::operator()() {
	assert(m_pCaller);
	if (!m_pCaller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	(m_pCaller->*m_pFunc)();
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::invoke() {
	assert(m_pCaller);
	if (!m_pCaller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	(m_pCaller->*m_pFunc)();
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::operator()(CallerType* caller) {
	assert(caller);
	if (!caller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	m_pCaller = caller;
	(m_pCaller->*m_pFunc)();
}

template<class CallerType>
void MemberFunction<CallerType, void, void>::invoke(CallerType* caller) {
	assert(caller);
	if (!caller) {
		Logbook::Log(Logbook::EOutput::BOTH, "crash.log",
			"FATAL ERROR\n TERMINATION OF PROGRAM\n Cause : MemberFunction Caller was nullptr.");
		exit(1);
	}
	m_pCaller = caller;
	(m_pCaller->*m_pFunc)();
}
#pragma endregion
#pragma endregion

} // namespace function
} // namespace drak 
