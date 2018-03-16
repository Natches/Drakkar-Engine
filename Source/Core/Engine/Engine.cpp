#include <Core/Timer/FrameTimer.hpp>
#include <Core/Engine/Engine.hpp>


namespace drak {

time::FrameTimer& core::Engine::s_frameTime = time::FrameTimer();

namespace core {
void Engine::update() {
	s_frameTime.update();
}
} // namespace core
} // namespace drak