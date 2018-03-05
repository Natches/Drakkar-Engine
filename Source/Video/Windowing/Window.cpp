#include "SDL_video.h"

#include <Video/Windowing/Window.hpp>

namespace drak {
namespace video {

Window::Window(const WindowSettings& settings) {
	m_pWin = SDL_CreateWindow(
		settings.title,
		settings.posX,
		settings.posY,
		settings.resX,
		settings.resY,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);
}

} // namespace video
} // namespace drak