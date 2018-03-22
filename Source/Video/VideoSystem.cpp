#ifdef WINDOWING_SDL
#include "SDL.h"
#undef main // avoid SDL name conflict

#include <Video/Windowing/SDLRenderWindow.hpp>
#endif

#include <vld.h>

#include <Core/Core.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>

//DK_LOG_CATEGORY_DEFINE(VideoSystemLog)
//DK_LOG_CATEGORY_DECLARE(VideoSystemLog, ELoggerVerbosity::DEBUG)

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
		//DK_LOG(VideoSystemLog, ELoggerVerbosity::DEBUG, "SDL error: %s\n", SDL_GetError())
		return false;
	}
	s_pMainWin = new SDLRenderWindow(settings.window);
	#endif

	if (!gl::GLRHI::Init(true)) { // TODO (Simon): refactor to call abstract RHI Init()
		//DK_LOG(VideoSystemLog, ELoggerVerbosity::DEBUG, "Failed to init GLRHI\n")
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