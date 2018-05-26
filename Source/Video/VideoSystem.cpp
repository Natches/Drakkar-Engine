#include <PrecompiledHeader/pch.hpp>
#ifdef WINDOWING_SDL
#include <Windowing/Window/SDLWindow.hpp>
#endif
//#include <vld.h>

namespace drak {
namespace video {

bool VideoSystem::startup(const VideoSettings& settings, AWindow*& pMainWindow) {
	#ifdef WINDOWING_SDL
	if (!SDLWindow::InitSDLVideo())
		return false;
	pMainWindow = new SDLWindow(settings.window);
	#endif

	if (pMainWindow) {
		if (settings.renderer == gfx::ERenderer::OPENGL)
			m_pRenderer = new gfx::gl::GLRenderer;
		return m_pRenderer->init();
	}
	return true;
}

void VideoSystem::shutdown() {
	#ifdef WINDOWING_SDL
	SDLWindow::QuitSDLVideo();
	#endif
}

} // namespace video
} // namespace drak