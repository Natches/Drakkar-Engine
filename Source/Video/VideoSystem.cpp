#include <PrecompiledHeader/pch.hpp>
#ifdef WINDOWING_SDL
#include <Windowing/Window/SDLWindow.hpp>
#endif
//#include <vld.h>

namespace drak {
namespace video {

bool VideoSystem::startup(const VideoSettings& settings) {
	editorMode = true;
	if (settings.renderer == gfx::ERenderer::OPENGL)
		m_pRenderer = new gfx::gl::GLRenderer;
	return m_pRenderer->init();
}

bool VideoSystem::startup(const VideoSettings& settings, AWindow*& pMainWindow) {
	editorMode = false;
	#ifdef WINDOWING_SDL
	if (!SDLWindow::InitSDLVideo())
		return false;
	pMainWindow = new SDLWindow(settings.window);
	#endif

	return pMainWindow ? startup(settings) : false;
}

void VideoSystem::shutdown() {
	if (!editorMode) {
	#ifdef WINDOWING_SDL
		SDLWindow::QuitSDLVideo();
	#endif
	}
}

} // namespace video
} // namespace drak