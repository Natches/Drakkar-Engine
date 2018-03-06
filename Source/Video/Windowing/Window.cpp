#include <Video/Windowing/Window.hpp>

namespace drak {
namespace video {

Window::Window(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY) {
}

} // namespace video
} // namespace drak