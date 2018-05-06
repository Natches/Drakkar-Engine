#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Animation::Animation(const Animation& anim) : m_name(anim.m_name), m_frames(anim.m_frames),
	m_time(anim.m_time) {
}

Animation::Animation(Animation&& anim) : m_name(std::move(anim.m_name)), m_frames(std::move(anim.m_frames)),
	m_time(std::move(anim.m_time)) {
}

} // namespace animation
} // namespace drak