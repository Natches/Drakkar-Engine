#ifdef WINDOWING_SDL
#include "SDL.h"
// undefine SDL main to avoid potential name conflicts
#undef main

#include <Video/Windowing/SDLWinWrapper.hpp>
#endif // WINDOWING_SDL

#include <vld.h>

#include <Video/DrakVideo.hpp>

namespace drak {
namespace video {

#pragma region Static Initialization

Window* DrakVideo::s_pMainWin	= nullptr;
bool	DrakVideo::s_ready		= false;

#pragma endregion

#pragma region Startup/Shutdown

bool DrakVideo::Startup(const VideoSettings& settings) {
#ifdef WINDOWING_SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}
	s_pMainWin = new SDLWinWrapper(settings.window); 
#endif // WINDOWING_SDL
	s_ready	= true;

	//...
	
	return true;
}


void DrakVideo::Shutdown() {
#ifdef WINDOWING_SDL
	SDL_DestroyWindow((SDL_Window*)s_pMainWin->m_pWin);
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	//SDL_Quit();
#endif
}

#pragma endregion

} // namespace video
} // namespace drak