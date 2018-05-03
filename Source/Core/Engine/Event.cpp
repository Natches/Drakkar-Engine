#include <PrecompiledHeader/pch.hpp>
#include <Core/Engine/Event.hpp>

namespace drak {
	namespace events {

		void DefaultEventDispatcher::addEventListener(EventType type, EventListener listener) {
			m_listeners[type].push_front(listener);
		}

		void DefaultEventDispatcher::removeEventListener(EventType type, EventListener listener) {
			//TODO Simon			
		}

		void DefaultEventDispatcher::dispatchEvent(const Event* e) {
			if (m_listeners.find(e->type) != m_listeners.end())
				for (auto& l : m_listeners[e->type]) {
					l->invoke(std::move(e));
				}
		}

	} // namespace events
} // namespace drak