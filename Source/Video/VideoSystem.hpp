#pragma once

#include <Core/Utils/ClassUtils.hpp>
#include <Video/VideoSettings.hpp>

namespace drak {
namespace video {

// Fwd declaration
class ARenderWindow;

/*!
* \class VideoSystem
* \ingroup DrakVideo
* \brief
*
*/
class VideoSystem final {
	DK_NONMOVABLE_NONCOPYABLE(VideoSystem)
public:
	VideoSystem() = default;

	bool startup(const VideoSettings& settings);
	void shutdown();

	static ARenderWindow* MainWindow() { return s_pMainWin; }

private:
	static ARenderWindow*	s_pMainWin;
	static bool				s_ready;
};

} // namespace video
} // namespace drak