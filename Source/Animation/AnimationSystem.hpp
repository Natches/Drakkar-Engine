#pragma once

#include <Core/Core.hpp>

namespace drak {
namespace core {
class Engine;
} //namespace core
namespace animation {

class AnimationSystem final {
	DK_NONMOVABLE_NONCOPYABLE(AnimationSystem)
	friend class core::Engine;
private:
	AnimationSystem() = default;

	bool startup(const int MinTimeBetweenUpdate);
	void shutdown();
};

} //namespace animation
} //namespace drak