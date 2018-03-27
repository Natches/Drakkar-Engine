#include <GL/glew.h>

#include <Video/Windowing/ARenderWindow.hpp>

namespace drak {
namespace video {

ARenderWindow::ARenderWindow(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

} // namespace video
} // namespace drak