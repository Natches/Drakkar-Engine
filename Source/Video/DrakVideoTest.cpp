#include <Video/DrakVideo.hpp>
#include <Video/RHI/OpenGL/GLRHI.hpp>

using namespace drak::video;

int main() {
	WindowSettings	ws = {"DrakVideoTest", 1280, 720};
	VideoSettings	settings = {ws};
	ARenderWindow*	pWin;

	if (DrakVideo::Startup(settings)) {
		pWin = DrakVideo::MainWindow();
		while (pWin->IsOpen()) {
			pWin->PollEvents();
			pWin->Clear();
			pWin->SwapBuffers();
		}
		pWin->Close();

		system("pause");
		DrakVideo::Shutdown();
		return 0;
	}

	return 1;
}