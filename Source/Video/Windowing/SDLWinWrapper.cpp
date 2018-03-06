#include <Video/Windowing/SDLWinWrapper.hpp>

namespace drak {
namespace video {

SDLWinWrapper::SDLWinWrapper(const WindowSettings& settings) 
:	Window(settings) {
	m_pWin = SDL_CreateWindow(
		settings.title,
		settings.posX, 
		settings.posY,
		m_resX, 
		m_resY,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);
}

bool SDLWinWrapper::IsOpen() const {
	return true;
}

void SDLWinWrapper::Close() {

}

} // namespace video
} // namespace drak