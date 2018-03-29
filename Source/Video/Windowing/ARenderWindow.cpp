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
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

} // namespace video
} // namespace drak