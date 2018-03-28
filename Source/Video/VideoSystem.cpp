#ifdef WINDOWING_SDL
#include <Windowing/Window/SDLWindow.hpp>
#endif

#include <vld.h>

#include <Core/Core.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>

namespace drak {
namespace video {

AWindow*	VideoSystem::s_pMainWin	= nullptr;
bool			VideoSystem::s_ready	= false;


bool VideoSystem::startup(const VideoSettings& settings) {
	#ifdef WINDOWING_SDL
	if (!SDLWindow::InitSDLVideo()) {
		return false;
	}
		
	s_pMainWin = new SDLWindow(settings.window);
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
	SDLWindow::QuitSDLVideo();
	#endif
}

} // namespace video
} // namespace drak