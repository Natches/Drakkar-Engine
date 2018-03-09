#include <Video/Windowing/SDLRenderWindow.hpp>

namespace drak {
namespace video {

SDLRenderWindow::SDLRenderWindow(const WindowSettings& settings)
:	ARenderWindow(settings) {
	m_pWin = SDL_CreateWindow(
		settings.title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		settings.resX,
		settings.resY,
		SDL_WINDOW_OPENGL
	);
	SDL_GL_CreateContext((SDL_Window*)m_pWin);

	m_open = true;
}

SDLRenderWindow::~SDLRenderWindow() {
	
}

void SDLRenderWindow::PollEvents() {
	SDL_PollEvent(&m_evt);
	switch (m_evt.type) {
	case SDL_WINDOWEVENT:
		m_open = m_evt.window.event != SDL_WINDOWEVENT_CLOSE;
		break;
	}
}

void SDLRenderWindow::SwapBuffers() {
	SDL_GL_SwapWindow((SDL_Window*)m_pWin);
}

void SDLRenderWindow::Close() {
	SDL_DestroyWindow((SDL_Window*)m_pWin);
}

} // namespace video
} // namespace drak

