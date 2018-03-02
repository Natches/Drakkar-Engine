#include "SDL.h"
#undef main // avoid name conflict with SDL main

#include <RHI/OpenGL/OpenGLRHI.hpp>
#include <RHI/OpenGL/OpenGLWindow.hpp>

namespace drak {
namespace gfx {
	
#pragma region Static Variable Initialization
bool OpenGLRHI::s_ready = false;
#pragma endregion

#pragma region Startup/Shutdown
bool OpenGLRHI::Startup() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO (Simon): log DrakVideo::Init() failed error message
		return false;
	}

	s_ready = true;
	return true;
}

void OpenGLRHI::Shutdown() {
	
}
#pragma endregion

OpenGLWindow* OpenGLRHI::CreateWindow(I32 resX, I32 resY, const char* title) {
	OpenGLWindow* pWin = nullptr;
	if (s_ready) {
		pWin = new OpenGLWindow(resX, resY, title);
	}
	else {
		// TODO (Simon): log DrakVideo::Init() uncalled error message
	}
	return pWin;
}

OpenGLContext* OpenGLRHI::CreateContext(OpenGLWindow* const pWin) {
	OpenGLContext* pCtx = nullptr;
	if (s_ready && pWin != nullptr) {
		pCtx = new OpenGLContext(pWin);
	}
	else {
		// TODO (Simon): log DrakVideo error message
	}
	return pCtx;
}

} // namespace gfx
} // namespace drak