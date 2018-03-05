#pragma once

#include <Video/Windowing/WindowSettings.hpp>

namespace drak {
namespace video {

class Window {
public:
	Window()						= delete;
	Window(const Window&)			= delete;
	Window(Window&&)				= delete;
	void operator=(const Window&)	= delete;
	void operator=(Window&&)		= delete;

private:
	Window(const WindowSettings& settings);

private:
	void* m_pWin;
};

} // namespace video
} // namespace drak