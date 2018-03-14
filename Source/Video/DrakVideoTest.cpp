#include <Video/DrakVideo.hpp>
#include <Video/RHI/OpenGL/GLRHI.hpp>

using namespace drak::video;

void testRun(ARenderWindow* pWin) {
	while (pWin->IsOpen()) {
		pWin->PollEvents();
		pWin->Clear();
		pWin->SwapBuffers();
	}
	pWin->Close();
}

int main() {
	WindowSettings	ws = {"DrakVideoTest", 1280, 720};
	VideoSettings	settings = {ws};

	bool okVideo = DrakVideo::Startup(settings);
	if (okVideo)
		testRun(DrakVideo::MainWindow());

	DrakVideo::Shutdown();
	system("pause");

	return okVideo;
}