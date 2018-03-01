#pragma once

#include <Core/Core.hpp>

//---------------------------------------------------------------------------------------
//	Forward declarations
//---------------------------------------------------------------------------------------
struct SDL_Window;

namespace drak {
namespace gfx {
	
class DrakGLWindow final {
public:
	DrakGLWindow()							= delete;
	DrakGLWindow(const DrakGLWindow&)		= delete;
	DrakGLWindow(DrakGLWindow&&)			= delete;
	void operator=(const DrakGLWindow&)		= delete;
	void operator=(DrakGLWindow&&)			= delete;

private:
	DrakGLWindow(I32 resX, I32 resY, const char* title);

private:
	SDL_Window*		m_pWin;
	int				m_resX, m_resY;

friend class DrakVideo;
friend class DrakGLContext;
};

} // namespace gfx
} // namespace drak