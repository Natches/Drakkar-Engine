#pragma once

#include <Core/Core.hpp>

struct SDL_Window;

namespace drak {
namespace video {
	
class OpenGLWindow final {
public:
	OpenGLWindow()							= delete;
	OpenGLWindow(const OpenGLWindow&)		= delete;
	OpenGLWindow(OpenGLWindow&&)			= delete;
	void operator=(const OpenGLWindow&)		= delete;
	void operator=(OpenGLWindow&&)			= delete;

private:
	OpenGLWindow(I32 resX, I32 resY, const char* title);

private:
	SDL_Window*		m_pWin;
	I32				m_resX, m_resY;

friend class OpenGLRHI;
friend class OpenGLContext;
};

} // namespace gfx
} // namespace drak