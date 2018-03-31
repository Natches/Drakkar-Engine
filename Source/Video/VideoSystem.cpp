#ifdef WINDOWING_SDL
#include <Windowing/Window/SDLWindow.hpp>
#endif

#include <vld.h>

#include <Core/Core.hpp>
#include <Video/VideoSystem.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLRenderHardware.hpp>

namespace drak {
namespace video {

bool VideoSystem::startup(const VideoSettings& settings, AWindow*& pMainWindow) {
	#ifdef WINDOWING_SDL
	if (!SDLWindow::InitSDLVideo()) {
		return false;
	}
		
	pMainWindow = new SDLWindow(settings.window);
	#endif

	//if (pMainWindow == nullptr || !gl::GLRendering::Init(true)) {
	//	return false;
	//}
	return true;
}

void VideoSystem::shutdown() {
	#ifdef WINDOWING_SDL
	SDLWindow::QuitSDLVideo();
	#endif
}

} // namespace video
} // namespace drak