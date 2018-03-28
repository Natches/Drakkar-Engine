#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Video/VideoSystem.hpp>
#include <Windowing/Window/WindowSettings.hpp>

namespace drak {
namespace video {

/*!
* \class AWindow
* \ingroup DrakVideo
* \brief Abstract base window class, forcing implementation of essential functionality.
*
*/
class AWindow { 
	DK_NONMOVABLE_NONCOPYABLE(AWindow)
public:
	AWindow(const WindowSettings& settings);
	virtual ~AWindow() = default;

public:
	virtual void*	WindowPointer() const	{ return m_pWin; }

	DK_GETTER(I32,	width,			m_resX)
	DK_GETTER(I32,	height,			m_resY)
	DK_GETTER(F32,	aspectRatio,	(F32)m_resX / (F32)m_resY)
	DK_GETTER(bool, isOpen,			m_open)

	virtual void	pollEvents()	= 0;
	virtual void	clear()			= 0;
	virtual void	swapBuffers()	= 0;
	virtual void	close()			= 0;

protected:
	virtual void	keyEvents();

protected:
	void*	m_pWin;
	I32		m_resX, m_resY;
	bool	m_open;

friend bool VideoSystem::startup(const VideoSettings& settings);
};

} // namespace video
} // namespace drak