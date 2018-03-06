#pragma once

#include <Core/Core.hpp>

#include <Video/RHI/OpenGL/OpenGLWindow.hpp>
#include <Video/RHI/OpenGL/OpenGLContext.hpp>

namespace drak {
namespace video {


class OpenGLRHI final {
public:
	OpenGLRHI()	= delete;

	static bool	Startup();
	static void	Shutdown();

	static OpenGLWindow* CreateGLWindow(I32 resX, I32 resY, const char* title);
	static OpenGLContext* CreateGLContext(OpenGLWindow* const pWin);

private:
	static bool	s_ready;
};

} // namespace gfx
} // namespace drak
