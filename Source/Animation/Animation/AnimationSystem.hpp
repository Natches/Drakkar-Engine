#pragma once

#include <Core/Core.hpp>

class AnimationSystem final {
	DK_NONMOVABLE_NONCOPYABLE(AnimationSystem)
public:
	AnimationSystem() = default;

	bool startup(const int MinTimeBetweenUpdate);
	void shutdown();
};
