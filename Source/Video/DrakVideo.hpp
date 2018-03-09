#pragma once

#include <Video/Windowing/ARenderWindow.hpp>
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

	static ARenderWindow*	MainWindow() { return s_pMainWin; }

private:
	static ARenderWindow*	s_pMainWin;
	static bool				s_ready;
};

} // namespace video
} // namespace drak