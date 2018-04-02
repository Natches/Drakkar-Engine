#pragma once

#include <map>
#include <list>

#include <Core/Engine/Event.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Windowing/Window/AWindow.hpp>

namespace drak {
namespace events {

enum class Key : U8 {
	KEY_NONE,

	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,

	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,

	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,

	KEY_SPACE
};

struct KeyEvent : public Event {
	KeyEvent() = default;
	KeyEvent(Key k, EventType t);

	Key key;
};

class Keyboard final : public IEventDispatcher {
	DK_NONMOVABLE_NONCOPYABLE(Keyboard)
public:
	enum : EventType {
		KEY_DOWN,
		KEY_UP
	};

public:
	static Keyboard& Get();

	void addEventListener(EventType type, EventListener listener) override;
	void removeEventListener(EventType type, EventListener listener) override;

	DK_GETTER_REF_V(KeyEvent, event, m_evt)

protected:
	void dispatchEvent(const Event* e) override;

private:
	Keyboard();
	~Keyboard();

private:
	std::map<EventType, std::list<EventListener>> m_listeners;
	KeyEvent m_evt;

friend void video::AWindow::handleKeyEvent(const KeyEvent& e);
};

} // namespace input
} // namespace drak