#include <PrecompiledHeader/pch.hpp>
#include "SDL.h"
#undef main // avoid SDL name conflict

#include <Windowing/Window/SDLWindow.hpp>

#include <GL/glew.h>

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
		if (!m_open) close();
		break;
	case SDL_KEYDOWN:
	case SDL_KEYUP:
		KeyEvent e {
			keyConvert(m_pEvt->key.keysym.sym),
			m_pEvt->key.type == SDL_KEYDOWN ? Keyboard::KEY_DOWN : Keyboard::KEY_UP
		};
		handleKeyEvent(e);
		break;
	}
}

Key SDLWindow::keyConvert(int sdlKey) const {
	Key k = Key::KEY_NONE;
	DK_SELECT(sdlKey)
		DK_CASE(SDLK_0,		k = Key::KEY_0)
		DK_CASE(SDLK_1,		k = Key::KEY_1)
		DK_CASE(SDLK_2,		k = Key::KEY_2)
		DK_CASE(SDLK_3,		k = Key::KEY_3)
		DK_CASE(SDLK_4,		k = Key::KEY_4)
		DK_CASE(SDLK_5,		k = Key::KEY_5)
		DK_CASE(SDLK_6,		k = Key::KEY_6)
		DK_CASE(SDLK_7,		k = Key::KEY_7)
		DK_CASE(SDLK_8,		k = Key::KEY_8)
		DK_CASE(SDLK_9,		k = Key::KEY_9)

		DK_CASE(SDLK_a,		k = Key::KEY_A)
		DK_CASE(SDLK_b,		k = Key::KEY_B)
		DK_CASE(SDLK_c,		k = Key::KEY_C)
		DK_CASE(SDLK_d,		k = Key::KEY_D)
		DK_CASE(SDLK_e,		k = Key::KEY_E)
		DK_CASE(SDLK_f,		k = Key::KEY_F)
		DK_CASE(SDLK_g,		k = Key::KEY_G)
		DK_CASE(SDLK_h,		k = Key::KEY_H)
		DK_CASE(SDLK_i,		k = Key::KEY_I)
		DK_CASE(SDLK_j,		k = Key::KEY_J)
		DK_CASE(SDLK_k,		k = Key::KEY_K)
		DK_CASE(SDLK_l,		k = Key::KEY_L)
		DK_CASE(SDLK_m,		k = Key::KEY_M)
		DK_CASE(SDLK_n,		k = Key::KEY_N)
		DK_CASE(SDLK_o,		k = Key::KEY_O)
		DK_CASE(SDLK_p,		k = Key::KEY_P)
		DK_CASE(SDLK_q,		k = Key::KEY_Q)
		DK_CASE(SDLK_r,		k = Key::KEY_R)
		DK_CASE(SDLK_s,		k = Key::KEY_S)
		DK_CASE(SDLK_t,		k = Key::KEY_T)
		DK_CASE(SDLK_u,		k = Key::KEY_U)
		DK_CASE(SDLK_v,		k = Key::KEY_V)
		DK_CASE(SDLK_w,		k = Key::KEY_W)
		DK_CASE(SDLK_x,		k = Key::KEY_X)
		DK_CASE(SDLK_y,		k = Key::KEY_Y)
		DK_CASE(SDLK_z,		k = Key::KEY_Z)

		DK_CASE(SDLK_UP,	k = Key::KEY_UP)
		DK_CASE(SDLK_DOWN,	k = Key::KEY_DOWN)
		DK_CASE(SDLK_LEFT,	k = Key::KEY_LEFT)
		DK_CASE(SDLK_RIGHT, k = Key::KEY_RIGHT)

		DK_CASE(SDLK_SPACE,	k = Key::KEY_SPACE)
	DK_END
	return k;
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

