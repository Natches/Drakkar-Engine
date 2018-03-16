#include <Core/Core.hpp>
#include <Core/Timer/FrameTimer.hpp>
#include <iostream>
#include <vector>

DK_IMPORT(drak::core)

int main() {
	while (true) {
		Engine::update();
		printf("FPS : %f \n", Engine::s_frameTime.frameRate());
	}
}