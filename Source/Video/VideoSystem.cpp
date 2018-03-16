#ifdef WINDOWING_SDL
#include "SDL.h" 
#undef main // avoid SDL name conflict

#include <Video/Windowing/SDLRenderWindow.hpp>
#endif

#include <vld.h>

#include <Video/VideoSystem.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>

namespace drak {
namespace video {

#pragma region Static Initialization
ARenderWindow*	VideoSystem::s_pMainWin	= nullptr;
bool			VideoSystem::s_ready	= false;
#pragma endregion

#pragma region Startup/Shutdown
bool VideoSystem::Startup(const VideoSettings& settings) {
	#ifdef WINDOWING_SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}
	s_pMainWin = new SDLRenderWindow(settings.window);
	#endif

	if (!gl::GLRHI::Init(true)) { // TODO (Simon): refactor to call abstract RHI Init()
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}

	s_ready = true;
	return true;
}

void VideoSystem::Shutdown() {
	delete s_pMainWin;

	#ifdef WINDOWING_SDL
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	#endif
}
#pragma endregion

} // namespace video
} // namespace drak