#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Skeleton::Skeleton(const Skeleton& skTon) : m_boneList(skTon.m_boneList),
	m_handleList(skTon.m_handleList), m_animList(skTon.m_animList),
	m_invGlobalPos(skTon.m_invGlobalPos) {
}

Skeleton::Skeleton(Skeleton&& skTon) : m_boneList(std::move(skTon.m_boneList)),
	m_handleList(std::move(skTon.m_handleList)), m_animList(std::move(skTon.m_animList)),
	m_invGlobalPos(std::move(skTon.m_invGlobalPos)) {
}

Skeleton& Skeleton::operator=(const Skeleton& skTon) {
	m_handleList = skTon.m_handleList;
	m_boneList = skTon.m_boneList;
	m_animList = skTon.m_animList;
	m_invGlobalPos = skTon.m_invGlobalPos;
	return *this;
}

Skeleton& Skeleton::operator=(Skeleton&& skTon) {
	m_handleList = std::move(skTon.m_handleList);
	m_boneList = std::move(skTon.m_boneList);
	m_animList = std::move(skTon.m_animList);
	m_invGlobalPos = std::move(skTon.m_invGlobalPos);
	return *this;
}

const Animation* Skeleton::animationByName(const std::string& name) const {
	if (m_animList.find(name) != m_animList.end())
		return &m_animList.at(name);
	else
		return nullptr;
}

core::EError Skeleton::jointByName(const std::string& name, Joint& j) const {
	if (m_handleList.find(name) != m_handleList.end()) {
		j = m_boneList[m_handleList.at(name)].joint;
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

core::EError Skeleton::idxByName(const std::string& name, U32& i) const {
	if (m_handleList.find(name) != m_handleList.end()) {
		i = m_handleList.at(name);
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

} // namespace animation
} // namespace drak