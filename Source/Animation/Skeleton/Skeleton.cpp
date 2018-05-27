#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Skeleton::Skeleton(const Skeleton& skTon) : m_base(skTon.m_base),
	m_boneList(skTon.m_boneList), m_animList(skTon.m_animList),
	m_invGlobalPos(skTon.m_invGlobalPos) {
}

Skeleton::Skeleton(Skeleton&& skTon) : m_base(std::move(skTon.m_base)),
	m_boneList(std::move(skTon.m_boneList)), m_animList(std::move(skTon.m_animList)),
	m_invGlobalPos(std::move(skTon.m_invGlobalPos)) {
	skTon.m_base = "";
}

Skeleton& Skeleton::operator=(const Skeleton& skTon) {
	m_base = skTon.m_base;
	m_boneList = skTon.m_boneList;
	m_animList = skTon.m_animList;
	m_invGlobalPos = skTon.m_invGlobalPos;
	return *this;
}

Skeleton& Skeleton::operator=(Skeleton&& skTon) {
	m_base = std::move(skTon.m_base);
	m_boneList = std::move(skTon.m_boneList);
	m_animList = std::move(skTon.m_animList);
	m_invGlobalPos = std::move(skTon.m_invGlobalPos);
	skTon.m_base = "";
	return *this;
}

const Animation* Skeleton::animationByName(const std::string& name) const {
	if (m_animList.find(name) != m_animList.end())
		return &m_animList.at(name);
	else
		return nullptr;
}

core::EError Skeleton::jointByName(const std::string& name, Joint& j) const {
	if (m_boneList.find(name) != m_boneList.end()) {
		j = m_boneList.at(name).joint;
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

} // namespace animation
} // namespace drak