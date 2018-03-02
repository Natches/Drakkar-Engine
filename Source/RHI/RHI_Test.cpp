#include <RHI/OpenGL/OpenGLRHI.h>

using namespace drak::gfx;

int main() {
	OpenGLWindow*	win;
	OpenGLContext*	ctx;

	if (OpenGLRHI::Startup()) {
		win = OpenGLRHI::CreateGLWindow(640, 640, "TestWindow");
		ctx = OpenGLRHI::CreateGLContext(win);

		return 0;
	}
    return 1;
}