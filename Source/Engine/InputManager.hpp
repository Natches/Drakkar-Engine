#pragma once
#include <Core/Engine/Event.hpp>
#include <map>
namespace drak {
class InputManager {
public:
	DRAK_API static bool keyDown(events::Key key);
	DRAK_API static bool mouseButtonDown(events::MouseEvent::MouseButton button);
	DRAK_API static math::Vec2i mousePos();
private:
	static InputManager* get();
	static InputManager* m_pInstance;
	InputManager();
	void keyPressEvent(const events::Event* pEvent);
	void keyReleaseEvent(const events::Event* pEvent);
	void mouseMoveEvent(const events::Event* pEvent);
	void mousePressEvent(const events::Event* pEvent);
	void mouseReleaseEvent(const events::Event* pEvent);
	std::map<events::Key, bool> m_keyStates;
	bool m_mouseLeftButtonSate;
	bool m_mouseRightButtonSate;
	math::Vec2i m_mousePos;
	function::MemberFunction<InputManager, void, const events::Event*> m_pressEventBind;
	function::MemberFunction<InputManager, void, const events::Event*> m_releaseEventBind;
	function::MemberFunction<InputManager, void, const events::Event*> m_mouseMoveBind;
	function::MemberFunction<InputManager, void, const events::Event*> m_mousePressBind;
	function::MemberFunction<InputManager, void, const events::Event*> m_mouseReleaseBind;
};
}