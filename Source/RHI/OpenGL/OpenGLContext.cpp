#include "SDL_video.h"

#include <RHI/OpenGL/OpenGLContext.h>
#include <RHI/OpenGL/OpenGLWindow.h>

namespace drak {
namespace gfx {

OpenGLContext::OpenGLContext(OpenGLWindow* const pWin) {
	m_pCtx = SDL_GL_CreateContext(pWin->m_pWin);
	// TODO (Simon): major + minor versions, profile mask, vendor + renderer (GPU)...?
}

} // namespace gfx
} // namespace drak