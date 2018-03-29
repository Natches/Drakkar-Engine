#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

using namespace drak::events;

namespace drak {
namespace video {

AWindow::AWindow(const WindowSettings& settings) 
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

void AWindow::handleKeyEvent(const Event* pEvt) {
	Keyboard::Get().dispatchEvent(pEvt);
}

} // namespace video
} // namespace drak