#pragma once

#include <Core/Core.hpp>

#include <DrakRHI/DrakGLWindow.h>
#include <DrakRHI/DrakGLContext.h>

namespace drak {
namespace gfx {

/*!
 * \class DrakVideo
 * \ingroup DrakRHI
 * \brief 
 *
 */
class DrakVideo final {
public:
	DrakVideo()							= delete;
	DrakVideo(const DrakVideo&)			= delete;
	DrakVideo(DrakVideo&&)				= delete;
	void operator=(const DrakVideo&)	= delete;
	void operator=(DrakVideo&&)			= delete;

public:
	static bool	Startup();
	static void	Shutdown();

	static DrakGLWindow* CreateGLWindow(I32 resX, I32 resY, const char* title);
	static DrakGLContext* CreateGLContext(DrakGLWindow* const pGLwin);

private:
	static bool	s_ready;
};

} // namespace gfx
} // namespace drak
