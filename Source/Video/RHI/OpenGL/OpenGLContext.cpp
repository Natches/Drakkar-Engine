#include "SDL_video.h"

#include <Video/RHI/OpenGL/OpenGLContext.hpp>
#include <Video/RHI/OpenGL/OpenGLWindow.hpp>

namespace drak {
namespace video {

OpenGLContext::OpenGLContext(OpenGLWindow* const pWin) {
	m_pCtx = SDL_GL_CreateContext(pWin->m_pWin);
	// TODO (Simon): major + minor versions, profile mask, vendor + renderer (GPU)...?
}

} // namespace gfx
} // namespace drak