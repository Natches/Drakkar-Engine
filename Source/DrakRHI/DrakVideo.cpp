#include "SDL.h"
#undef main // undefine SDL main to avoid potential name conflicts

#include <DrakRHI/DrakVideo.h>
#include <DrakRHI/DrakGLWindow.h>

namespace drak {
namespace gfx {
	
//---------------------------------------------------------------------------------------
//	Static variable initialization
//---------------------------------------------------------------------------------------
bool DrakVideo::s_ready	= false;

bool DrakVideo::Startup() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}

	s_ready = true;

	//TODO (Simon): additional video init code

	return true;
}

void DrakVideo::Shutdown() {
	// TODO (Simon): DrakVideo::Shutdown()
}

DrakGLWindow* DrakVideo::CreateGLWindow(I32 resX, I32 resY, const char* title) {
	DrakGLWindow* pGLwin = nullptr;
	if (s_ready) {
		pGLwin = new DrakGLWindow(resX, resY, title);
	}
	else {
		// TODO (Simon): log DrakVideo::Init() uncalled error message
	}
	return pGLwin;
}

DrakGLContext* DrakVideo::CreateGLContext(DrakGLWindow* const pGLwin) {
	DrakGLContext* pGLctx = nullptr;
	if (s_ready && pGLwin != nullptr) {
		pGLctx = new DrakGLContext(pGLwin);
	}
	else {
		// TODO (Simon): log DrakVideo error message
	}
	return pGLctx;
}

} // namespace gfx
} // namespace drak