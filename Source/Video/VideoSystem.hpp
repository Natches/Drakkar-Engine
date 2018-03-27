#pragma once

#include <Windowing/ARenderWindow.hpp>
#include <Video/VideoSettings.hpp>

namespace drak {
namespace video {

/*!
* \class VideoSystem
* \ingroup DrakVideo
* \brief
*
*/
class VideoSystem final {
public:
	VideoSystem()	= delete;
	~VideoSystem()	= delete;

public:
	static bool	Startup(const VideoSettings& settings);
	static void	Shutdown();

	static ARenderWindow* MainWindow() { return s_pMainWin; }

private:
	static ARenderWindow*	s_pMainWin;
	static bool				s_ready;
};

} // namespace video
} // namespace drak