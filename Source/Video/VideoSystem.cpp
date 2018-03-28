#ifdef WINDOWING_SDL
#include <Windowing/SDLRenderWindow.hpp>
#endif

#include <vld.h>

#include <Core/Core.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>

#include <cstdio>

namespace drak {
namespace video {

ARenderWindow*	VideoSystem::s_pMainWin	= nullptr;
bool			VideoSystem::s_ready	= false;


bool VideoSystem::startup(const VideoSettings& settings) {
	#ifdef WINDOWING_SDL
	if (!SDLRenderWindow::InitSDLVideo()) {
		return false;
	}
		
	s_pMainWin = new SDLRenderWindow(settings.window);
	#endif

	if (!gl::GLRHI::Init(true)) {
		return false;
	}

	s_ready = true;
	return s_ready;
}

void VideoSystem::shutdown() {
	delete s_pMainWin;

	#ifdef WINDOWING_SDL
	SDLRenderWindow::QuitSDLVideo();
	#endif
}

} // namespace video
} // namespace drak