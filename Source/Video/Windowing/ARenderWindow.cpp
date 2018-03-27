#include <GL/glew.h>

#include <Video/Windowing/ARenderWindow.hpp>

namespace drak {
namespace video {

ARenderWindow::ARenderWindow(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

void ARenderWindow::Clear() const {
	F32 color[] = { 0.f, 0.f, 0.f };
	glClearBufferfv(GL_COLOR, 0, color);
	glClear(GL_DEPTH_BUFFER_BIT);
}

} // namespace video
} // namespace drak