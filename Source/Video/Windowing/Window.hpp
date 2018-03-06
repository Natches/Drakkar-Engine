#pragma once

#include <Video/Windowing/WindowSettings.hpp>

namespace drak {
namespace video {

/*!
* \class Window
* \ingroup DrakVideo
* \brief Abstract base window class, forcing implementation of essential functionality.
*
*/
class Window {
public:
	Window() = delete;
	Window(const Window&) = delete;
	Window(Window&&) = delete;
	virtual ~Window() = default;
	void operator=(const Window&) = delete;
	void operator=(Window&&) = delete;

public:
	virtual void*	WindowPointer()	const { return m_pWin; }
	virtual I32		Width()			const { return m_resX; }
	virtual I32		Height()		const { return m_resY; }
	virtual F32		AspectRatio()	const { return (F32)m_resX / (F32)m_resY; }

	virtual bool	IsOpen()		const = 0;
	virtual void	Close() = 0;

protected:
	Window(const WindowSettings& settings);

protected:
	void*	m_pWin;
	I32		m_resX, m_resY;

	friend class DrakVideo;
};

} // namespace video
} // namespace drak