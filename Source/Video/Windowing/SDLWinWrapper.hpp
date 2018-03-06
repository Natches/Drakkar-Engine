#pragma once

#include "SDL_video.h"
#include <Video/Windowing/Window.hpp>

namespace drak {
namespace video {

/*!
* \class SDLWinWrapper
* \ingroup DrakVideo
* \brief Inherits Window; builds on an SDLWindow
*
*/
class SDLWinWrapper : public Window {
protected:
	SDLWinWrapper(const WindowSettings& settings);

protected:
	virtual bool IsOpen() const override;
	virtual void Close()		override;

protected:
	void*	m_pWin;
	I32		m_resX, m_resY;

friend class DrakVideo;
};

} // namespace video
} // namespace drak