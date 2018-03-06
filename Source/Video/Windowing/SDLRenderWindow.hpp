#pragma once

#include "SDL_video.h"
#include "SDL_events.h"

#include <Video/Windowing/RenderWindow.hpp>

namespace drak {
namespace video {

/*!
* \class SDLRenderWindow
* \ingroup DrakVideo
* \brief Inherits Window; builds on an SDLWindow
*
*/
class SDLRenderWindow : public RenderWindow {
protected:
	SDLRenderWindow(const WindowSettings& settings);
	virtual ~SDLRenderWindow();

protected:
	virtual void PollEvents() override;
	virtual void SwapBuffers() override;
	virtual void Close() override;

protected:
	void*		m_pWin;
	I32			m_resX, m_resY;
	SDL_Event	m_evt;

friend class DrakVideo;
};

} // namespace video
} // namespace drak