#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Keyframe::Keyframe(const Keyframe& kFrame)
	: m_jointList(kFrame.m_jointList) {
}

Keyframe::Keyframe(Keyframe&& kFrame)
	: m_jointList(std::move(kFrame.m_jointList)) {
}

Keyframe& Keyframe::operator=(const Keyframe& kFrame) {
	m_jointList = kFrame.m_jointList;
	return *this;
}

Keyframe& Keyframe::operator=(Keyframe&& kFrame) {
	m_jointList = std::move(kFrame.m_jointList);
	return *this;
}

core::EError Keyframe::jointByName(const std::string& name, Joint& j) const {
	if (m_jointList.find(name) != m_jointList.end()) {
		j = m_jointList.at(name);
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

} // namespace animation
} // namespace drak