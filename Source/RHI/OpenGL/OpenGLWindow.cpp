#include "SDL.h"
#undef main // undefine SDL main to avoid potential name conflicts

#include <RHI/OpenGL/OpenGLWindow.h>

namespace drak {
namespace gfx {

OpenGLWindow::OpenGLWindow(I32 resX, I32 resY, const char* title)
:	m_resX(resX), m_resY(resY) {
	m_pWin = SDL_CreateWindow(
		title, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		m_resX, m_resY,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (!m_pWin) {
		// TODO (Simon): log error message
	}
}

} // namespace gfx
} // namespace drak