#pragma once

namespace drak {
namespace gfx {

class DrakGLWindow;

class DrakGLContext final {
public:
	DrakGLContext(const DrakGLContext&)		= delete;
	DrakGLContext(DrakGLContext&&)			= delete;
	void operator=(const DrakGLContext&)	= delete;
	void operator=(DrakGLContext&&)			= delete;

private:
	DrakGLContext(DrakGLWindow* const pGLwin);

private:
	void* m_pGLctx;

friend class DrakVideo;
};

} // namespace gfx
} // namespace drak