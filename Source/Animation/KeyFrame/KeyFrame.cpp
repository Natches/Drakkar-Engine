#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

KeyFrame::KeyFrame(const KeyFrame& kFrame)
	: m_jointList(kFrame.m_jointList) {
}

KeyFrame::KeyFrame(KeyFrame&& kFrame)
	: m_jointList(std::move(kFrame.m_jointList)) {
}

KeyFrame& KeyFrame::operator=(const KeyFrame& kFrame) {
	m_jointList = kFrame.m_jointList;
	return *this;
}

KeyFrame& KeyFrame::operator=(KeyFrame&& kFrame) {
	m_jointList = std::move(kFrame.m_jointList);
	return *this;
}

core::EError KeyFrame::jointByName(const std::string& name, Joint& j) const {
	if (m_jointList.find(name) != m_jointList.end()) {
		j = m_jointList.at(name);
		return DK_OK;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

} // namespace animation
} // namespace drak