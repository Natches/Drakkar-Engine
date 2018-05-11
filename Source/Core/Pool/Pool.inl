#include <Core/Pool/Pool.hpp>

namespace drak {
namespace core {

template<typename T>
Pool<T>::~Pool() {
	if constexpr(std::is_pointer_v<T>) {
		for (auto& x : m_pool) {
			delete x;
			x = nullptr;
		}
	}
}

template<typename T>
Pool<T>::Pool(U32 min) {
	m_pool.resize(min);
	m_inUse.reserve(min);
}

template<typename T>
Pool<T>::Pool(Pool<T>&& p) : m_inUse(std::move(p.m_inUse)), m_pool(std::move(p.m_pool)) {
}

template<typename T>
Pool<T>& Pool<T>::operator=(Pool<T>&& p) {
	m_inUse = std::move(p.m_inUse);
	m_pool = std::move(p.m_pool);
	return *this;
}

template<typename T>
T& Pool<T>::borrow() {
	if (m_pool.empty())
		grow();
	m_inUse.emplace_back(m_pool.front());
	m_pool.erase(m_pool.begin());
	return m_inUse[m_inUse.size() - 1];
}

template<typename T>
void Pool<T>::getBack(T&& t) {
	m_inUse.erase(std::remove(m_inUse.begin(), m_inUse.end(), t), m_inUse.end());
	m_pool.emplace_back(std::move(t));
	t = T();
}

template<typename T>
void Pool<T>::grow() {
	m_pool.resize((m_inUse.size() + 1) + (U32)(0.25f * m_inUse.size()));
}

} //namespace core
} //namespace drak