#include "SDL_video.h"

#include <DrakRHI/DrakGLContext.h>
#include <DrakRHI/DrakGLWindow.h>

namespace drak {
namespace gfx {

DrakGLContext::DrakGLContext(DrakGLWindow* const pGLwin) {
	m_pGLctx = SDL_GL_CreateContext(pGLwin->m_pWin);
	// TODO (Simon): major + minor versions, profile mask, vendor + renderer (GPU)...?
}

} // namespace gfx
} // namespace drak