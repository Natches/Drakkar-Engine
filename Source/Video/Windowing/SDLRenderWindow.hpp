#pragma once

#include "SDL_video.h"
#include "SDL_events.h"

#include <Video/Windowing/ARenderWindow.hpp>

namespace drak {
namespace video {

/*!
* \class SDLRenderWindow
* \ingroup DrakVideo
* \brief Inherits ARenderWindow; builds on an SDL_Window
*
*/
class SDLRenderWindow : public ARenderWindow {
protected:
	SDLRenderWindow(const WindowSettings& settings);
	virtual ~SDLRenderWindow();

protected:
	void PollEvents()	override;
	void SwapBuffers()	override;
	void Clear()		override;
	void Close()		override;

protected:
	void*		m_pWin;
	I32			m_resX, m_resY;
	SDL_Event	m_evt;

friend class VideoSystem;
};

} // namespace video
} // namespace drak