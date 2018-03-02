#include <Video/DrakVideo.hpp>

using namespace drak::video;

int main() {
	WindowSettings	ws = {"DrakVideoTest", 1280, 720, 0, 0};
	VideoSettings	settings = {ws};

	if (DrakVideo::Startup(settings)) {
		
		DrakVideo::Shutdown();
		return 0;
	}
	return 1;
}