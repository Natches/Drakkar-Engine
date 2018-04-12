#include <Threading/Function/Function.hpp>

namespace drak {
namespace function {

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

} // namespace function
} // namespace drak
