#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Skeleton::Skeleton(Bone&& b) : m_base(std::move(b)) {
	b = Bone();
}

Skeleton::Skeleton(Skeleton&& skTon) : m_base(std::move(skTon.m_base)),
	m_boneList(std::move(skTon.m_boneList)) {
	skTon.m_base = Bone();
}

Skeleton& Skeleton::operator=(Skeleton&& skTon) {
	m_base = std::move(skTon.m_base);
	m_boneList = std::move(skTon.m_boneList);
	skTon.m_base = Bone();
	return *this;
}

} // namespace animation
} // namespace drak