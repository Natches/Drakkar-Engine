#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

namespace drak {
namespace video {

AWindow::AWindow(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

void AWindow::keyEvents() {

}

} // namespace video
} // namespace drak