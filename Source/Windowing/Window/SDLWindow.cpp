#include "SDL.h"
#undef main // avoid SDL name conflict

#include <GL/glew.h>

#include <Windowing/Window/SDLWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

using namespace drak::events;

namespace drak {
namespace video {

SDLWindow::SDLWindow(const WindowSettings& settings)
:	AWindow(settings) {

	U32 winFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	m_pWin = SDL_CreateWindow(
		settings.title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		settings.resX,
		settings.resY,
		winFlags
	);

	m_pEvt = new SDL_Event;

	m_glContext = SDL_GL_CreateContext(static_cast<SDL_Window*>(m_pWin));
	m_open = true;
}

SDLWindow::~SDLWindow() {
	if (m_open) close();
}

bool SDLWindow::InitSDLVideo() {
	return SDL_Init(SDL_INIT_VIDEO) == 0;
}

void SDLWindow::QuitSDLVideo() {
	SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void SDLWindow::pollEvents() {
	SDL_PollEvent(m_pEvt);
	switch (m_pEvt->type) {
	case SDL_WINDOWEVENT:
		m_open = m_pEvt->window.event != SDL_WINDOWEVENT_CLOSE;
		break;
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		//KeyEvent e {
		//	Keyboard::Key::W,
		//	SDLK_0
		//	m_pEvt->key.type == SDL_KEYDOWN ? Keyboard::KEY_PRESSED : Keyboard::KEY_RELEASED
		//};

		break;
	}
}

void SDLWindow::clear() {
	F32 color[] = { 0.f, 0.f, 0.f };
	glClearBufferfv(GL_COLOR, 0, color);
	glClear(GL_DEPTH_BUFFER_BIT);
}

void SDLWindow::swapBuffers() {
	SDL_GL_SwapWindow(static_cast<SDL_Window*>(m_pWin));
}

void SDLWindow::close() {
	delete m_pEvt;
	SDL_DestroyWindow(static_cast<SDL_Window*>(m_pWin));
}

} // namespace video
} // namespace drak

