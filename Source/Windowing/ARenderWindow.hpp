#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Video/VideoSystem.hpp>
#include <Windowing/WindowSettings.hpp>

namespace drak {
namespace video {

/*!
* \class ARenderWindow
* \ingroup DrakVideo
* \brief Abstract base window class, forcing implementation of essential functionality.
*
*/
class ARenderWindow { 
	DK_NONMOVABLE_NONCOPYABLE(ARenderWindow)
public:
	ARenderWindow(const WindowSettings& settings);
	virtual ~ARenderWindow() = default;

public:
	virtual void*	WindowPointer() const	{ return m_pWin; }
	virtual I32		Width()			const	{ return m_resX; }
	virtual I32		Height()		const	{ return m_resY; }
	virtual F32		AspectRatio()	const	{ return (F32)m_resX / (F32)m_resY; }
	virtual bool	IsOpen()		const	{ return m_open; }
	
	virtual void	PollEvents()	= 0;
	virtual void	Clear()			= 0;
	virtual void	SwapBuffers()	= 0;
	virtual void	Close()			= 0;

protected:
	void*	m_pWin;
	I32		m_resX, m_resY;
	bool	m_open;

friend bool VideoSystem::startup(const VideoSettings& settings);
};

} // namespace video
} // namespace drak