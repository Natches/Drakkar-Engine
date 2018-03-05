#include "SDL.h"
#undef main // undefine SDL main to avoid potential name conflicts

#include <Video/DrakVideo.hpp>

namespace drak {
namespace video {

#pragma region Static Initialization
bool DrakVideo::s_ready = false;
#pragma endregion

#pragma region Startup/Shutdown
bool DrakVideo::Startup(const VideoSettings& settings) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}

	s_ready = true;

	//TODO (Simon): additional video init code

	return true;
}

void DrakVideo::Shutdown() {

}
#pragma endregion

} // namespace video
} // namespace drak