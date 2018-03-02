#pragma once

#include <Core/Core.hpp>

#include <RHI/OpenGL/OpenGLWindow.hpp>
#include <RHI/OpenGL/OpenGLContext.hpp>

namespace drak {
namespace gfx {

/*!
 * \class OpenGLRHI
 * \ingroup DrakVideo
 * \brief OpenGL Render Hardware Interface
 *
 */
class OpenGLRHI final {
public:
	OpenGLRHI() = delete;

	static bool	Startup();
	static void	Shutdown();

	static OpenGLWindow* CreateWindow(I32 resX, I32 resY, const char* title);
	static OpenGLContext* CreateContext(OpenGLWindow* const pGLwin);

private:
	static bool	s_ready;
};

} // namespace gfx
} // namespace drak
