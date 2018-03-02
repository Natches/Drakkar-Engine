#pragma once

namespace drak {
namespace gfx {

class OpenGLWindow;

class OpenGLContext final {
public:
	OpenGLContext(const OpenGLContext&)		= delete;
	OpenGLContext(OpenGLContext&&)			= delete;
	void operator=(const OpenGLContext&)	= delete;
	void operator=(OpenGLContext&&)			= delete;

private:
	OpenGLContext(OpenGLWindow* const pGLwin);

private:
	void* m_pCtx;

friend class OpenGLRHI;
};

} // namespace gfx
} // namespace drak