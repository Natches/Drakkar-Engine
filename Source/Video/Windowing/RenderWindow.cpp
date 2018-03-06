#include <GL/glew.h>

#include <Video/Windowing/RenderWindow.hpp>

namespace drak {
namespace video {

RenderWindow::RenderWindow(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

void RenderWindow::Clear() const {
	glClear(GL_COLOR_BUFFER_BIT);
}

} // namespace video
} // namespace drak