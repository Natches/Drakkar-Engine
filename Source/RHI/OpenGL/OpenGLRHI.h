#pragma once

#include <Core/Core.hpp>

#include <RHI/OpenGL/OpenGLWindow.h>
#include <RHI/OpenGL/OpenGLContext.h>

namespace drak {
namespace gfx {

/*!
 * \class DrakVideo
 * \ingroup DrakRHI
 * \brief 
 *
 */
class OpenGLRHI final {
public:
	OpenGLRHI()	= delete;

	static bool	Startup();
	static void	Shutdown();

	static OpenGLWindow* CreateGLWindow(I32 resX, I32 resY, const char* title);
	static OpenGLContext* CreateGLContext(OpenGLWindow* const pGLwin);

private:
	static bool	s_ready;
};

} // namespace gfx
} // namespace drak
