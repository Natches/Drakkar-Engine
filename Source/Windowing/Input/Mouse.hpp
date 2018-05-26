#pragma once

#include <map>
#include <list>

#include <Core/Engine/Event.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Windowing/Window/AWindow.hpp>

namespace drak {
namespace events {

struct MouseEvent : public Event {
	enum : EventType {
		MOUSE_DOWN,
		MOUSE_UP,
		MOUSE_MOVE
	};

	enum MouseButton : U8 {
		MOUSE_LEFT,
		MOUSE_RIGHT
	};

	MouseEvent() = default;
	MouseEvent(MouseButton b, EventType t);
	MouseEvent(I32 x, I32 y, EventType t);

	MouseButton btn;
	I32			xPos, yPos;
};

class Mouse final : public IEventDispatcher {
	DK_NONMOVABLE_NONCOPYABLE(Mouse)
public:
	DRAK_API static Mouse& Get();

	DRAK_API void addEventListener(EventType type, EventListener listener) override;
	void removeEventListener(EventType type, EventListener listener) override;

	DK_GETTER_REF_V(MouseEvent, event, m_evt)

protected:
	void dispatchEvent(const Event* e) override;

private:
	Mouse()  = default;
	~Mouse() = default;

private:
	std::map<EventType, std::list<EventListener>> m_listeners;
	MouseEvent m_evt;

friend void video::AWindow::handleMouseEvent(const MouseEvent& e);
};

} // namespace events
} // namespace drak