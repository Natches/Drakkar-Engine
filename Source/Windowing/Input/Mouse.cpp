#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace events {

Mouse& Mouse::Get() {
	static Mouse s_mouse;
	return s_mouse;
}

void Mouse::addEventListener(EventType type, EventListener listener) {
	m_listeners[type].push_front(listener);
}

void Mouse::removeEventListener(EventType type, EventListener listener) {
	//if (m_listeners.find(type) != m_listeners.end()) {
	//	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it) {
	//		if (it->second == listener)
	//	}
	//}
}

void Mouse::dispatchEvent(const Event* e) {
	if (m_listeners.find(e->type) != m_listeners.end())
		for (auto& l : m_listeners[e->type])
			l->invoke(std::move(e));
}

MouseEvent::MouseEvent(MouseButton b, EventType t)
:	btn(b) {
	type = t;
}

MouseEvent::MouseEvent(I32 x, I32 y, EventType t)
:	xPos(x),
	yPos(y) {
	type = t;
}

} // namespace events
} // namespace drak