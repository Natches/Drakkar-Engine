#include <Core/Timer/ATimer.hpp>

namespace drak {
namespace time {

	std::chrono::time_point<std::chrono::high_resolution_clock> ATimer::currentTime()
	{
		return std::chrono::high_resolution_clock::now();
	}

} // namespace time
} // namespace drak