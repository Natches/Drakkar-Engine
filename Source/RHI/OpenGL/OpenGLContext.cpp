#include "SDL_video.h"

#include <RHI/OpenGL/OpenGLContext.hpp>
#include <RHI/OpenGL/OpenGLWindow.hpp>

namespace drak {
namespace gfx {

OpenGLContext::OpenGLContext(OpenGLWindow* const pWin) {
	m_pCtx = SDL_GL_CreateContext(pWin->m_pWin);
	// TODO (Simon): major + minor versions, profile mask, vendor + renderer (GPU)...?
}

} // namespace gfx
} // namespace drak