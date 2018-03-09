#ifdef WINDOWING_SDL
#include "SDL.h"
// undefine SDL main to avoid potential name conflicts
#undef main

#include <Video/Windowing/SDLRenderWindow.hpp>
#endif

#include <vld.h>

#include <Video/DrakVideo.hpp>
#include <Video/RHI/OpenGL/GLRHI.hpp>

namespace drak {
namespace video {

#pragma region Static Initialization
ARenderWindow* DrakVideo::s_pMainWin = nullptr;
bool DrakVideo::s_ready	= false;
#pragma endregion

#pragma region Startup/Shutdown
bool DrakVideo::Startup(const VideoSettings& settings) {
	#ifdef WINDOWING_SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}
	s_pMainWin = new SDLRenderWindow(settings.window);
	#endif

	if (!ogl::Init(true)) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}

	ogl::DepthFunc	(true, ogl::DepthMode::LESS);
	ogl::CullFunc	(true, ogl::FaceSide::BACK);

	s_ready = true;
	return true;
}

void DrakVideo::Shutdown() {
	delete s_pMainWin;

	#ifdef WINDOWING_SDL
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
	#endif
}
#pragma endregion

} // namespace video
} // namespace drak