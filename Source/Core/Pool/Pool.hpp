#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <vector>

namespace drak {
namespace core {

template<typename T>
class Pool {
	DK_NONCOPYABLE(Pool<T>)
public:
	Pool() = default;
	~Pool();

	Pool(U32 min);
	Pool(Pool&& p);

	Pool& operator=(Pool&& p);

	T& borrow();
	void getBack(T&& t);

private:
	void grow();

private:
	std::vector<T> m_pool;
	std::vector<T> m_inUse;
};

} //namespace core
} //namespace drak

#include <Core/Pool/Pool.inl>