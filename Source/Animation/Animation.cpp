#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Animation::Animation(const Animation& anim)
	: m_name(anim.m_name), m_frames(anim.m_frames),
	m_animationDuration(anim.m_animationDuration) {
}

Animation::Animation(Animation&& anim)
	: m_name(std::move(anim.m_name)), m_frames(std::move(anim.m_frames)),
	m_animationDuration(std::move(anim.m_animationDuration)) {
}

void Animation::buildNecessaryBoneList(std::unordered_map<std::string, bool>& neededBones) const {
	for (auto kFrame : m_frames) {
		for (auto& nBone : neededBones) {
			if (kFrame.jointByName(nBone.first, Joint()) == core::EError::NO_ERROR)
				nBone.second = true;
		}
	}
}

} // namespace animation
} // namespace drak