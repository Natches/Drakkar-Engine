#pragma once

#include <Video/Windowing/RenderWindow.hpp>
#include <Video/VideoSettings.hpp>

namespace drak {
namespace video {

/*!
* \class DrakVideo
* \ingroup DrakVideo
* \brief
*
*/
class DrakVideo final {
public:
	DrakVideo()	= delete;
	~DrakVideo() = delete;

public:
	static bool	Startup(const VideoSettings& settings);
	static void	Shutdown();

	static RenderWindow*	MainWindow() { return s_pMainWin; }

private:
	static RenderWindow*	s_pMainWin;
	static bool				s_ready;
};

} // namespace video
} // namespace drak