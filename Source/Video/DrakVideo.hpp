#pragma once

#include <Video/Windowing/Window.hpp>
#include <Video/VideoSettings.hpp>

namespace drak {
namespace video {

/*!
* \class DrakVideo
* \ingroup DrakRHI
* \brief
*
*/
class DrakVideo final {
public:
	DrakVideo() = delete;

	static bool	Startup(const VideoSettings& settings);
	static void	Shutdown();

private:
	static Window*	s_pMainWin;
	static bool		s_ready;
};

} // namespace video
} // namespace drak