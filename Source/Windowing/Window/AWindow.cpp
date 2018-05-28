#include <PrecompiledHeader/pch.hpp>

using namespace drak::events;

namespace drak {
namespace video {

AWindow::AWindow(const WindowSettings& settings)
:	m_resX(settings.resX),
	m_resY(settings.resY),
	m_open(false) {
}

void AWindow::handleKeyEvent(const KeyEvent& e) {
	Keyboard::Get().m_evt = e;
	Keyboard::Get().dispatchEvent(&Keyboard::Get().m_evt);
}

void AWindow::handleMouseEvent(const MouseEvent& e) {
	Mouse::Get().m_evt = e;
	Mouse::Get().dispatchEvent(&Mouse::Get().m_evt);
}

} // namespace video
} // namespace drak