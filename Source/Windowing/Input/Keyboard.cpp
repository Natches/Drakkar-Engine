#include <Windowing/Input/Keyboard.hpp>

namespace drak {
namespace events {

Keyboard::Keyboard() {

}

Keyboard::~Keyboard() {

}

Keyboard& Keyboard::Get() {
	static Keyboard s_keyboard;
	return s_keyboard;
}

void Keyboard::addEventListener(EventType type, EventListener listener) {
	m_listeners[type].push_front(listener);
}

void Keyboard::removeEventListener(EventType type, EventListener listener) {
	//if (m_listeners.find(type) != m_listeners.end()) {
	//	for (auto it = m_listeners.begin(); it != m_listeners.end(); ++it) {
	//		if (it->second == listener)
	//	}
	//}
}

void Keyboard::dispatchEvent(const Event* e) {
	if (m_listeners.find(e->type) != m_listeners.end())
		for (auto& l : m_listeners[e->type])
			l.invoke(std::move(e));
}

KeyEvent::KeyEvent(Key k, EventType t) 
:	key(k) {
	type = t;
}

} // namespace events
} // namespace drak