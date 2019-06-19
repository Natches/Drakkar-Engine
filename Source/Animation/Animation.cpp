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

} // namespace animation
} // namespace drak