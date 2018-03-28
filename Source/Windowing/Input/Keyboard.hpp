#pragma once

#include <map>
#include <forward_list>

#include <Core/Engine/Event.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Windowing/Window/AWindow.hpp>

namespace drak {
namespace events {

class Keyboard final : public IEventDispatcher {
	DK_NONMOVABLE_NONCOPYABLE(Keyboard)
public:
	enum : EventType {
		KEY_PRESSED,
		KEY_RELEASED
	};

	enum class Key : U8 {
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
		KEY_Z
	};

public:
	static Keyboard& Get();

	void addEventListener		(EventType type, EventListener listener) override;
	void removeEventListener	(EventType type, EventListener listener) override;

protected:
	void dispatchEvent(Event* e) override;

private:
	Keyboard();
	~Keyboard();

	std::map<EventType, std::forward_list<EventListener>> m_listeners;

friend void video::AWindow::pollEvents()
};

struct KeyEvent : public Event {
	KeyEvent() = default;
	KeyEvent(Keyboard::Key k, EventType t);

	Keyboard::Key key;
};

} // namespace input
} // namespace drak