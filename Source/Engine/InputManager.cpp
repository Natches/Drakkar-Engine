#include <PrecompiledHeader\pch.hpp>
#include <Engine\InputManager.hpp>

drak::InputManager* drak::InputManager::m_pInstance = nullptr;

drak::InputManager * drak::InputManager::get(){
	if (drak::InputManager::m_pInstance == nullptr)
		drak::InputManager::m_pInstance = new drak::InputManager();
	return drak::InputManager::m_pInstance;
}

bool drak::InputManager::keyDown(events::Key key) {
	return drak::InputManager::get()->m_keyStates[key];
}

bool drak::InputManager::mouseButtonDown(events::MouseEvent::MouseButton button){
	switch (button) {
	case events::MouseEvent::MouseButton::MOUSE_LEFT:
		return drak::InputManager::get()->m_mouseLeftButtonSate;
		break;
	case events::MouseEvent::MouseButton::MOUSE_RIGHT:
		return drak::InputManager::get()->m_mouseRightButtonSate;
		break;
	}
	return false;
}

drak::math::Vec2i drak::InputManager::mousePos(){
	return drak::InputManager::get()->m_mousePos;
}

drak::InputManager::InputManager(){
	m_pressEventBind = function::MemberFunction<drak::InputManager, void, const events::Event*>(this, &drak::InputManager::keyPressEvent, NULL);
	m_releaseEventBind = function::MemberFunction<drak::InputManager, void, const events::Event*>(this, &drak::InputManager::keyReleaseEvent, NULL);
	m_mouseMoveBind = function::MemberFunction<drak::InputManager, void, const events::Event*>(this, &drak::InputManager::mouseMoveEvent, NULL);
	m_mousePressBind = function::MemberFunction<drak::InputManager, void, const events::Event*>(this, &drak::InputManager::mousePressEvent, NULL);
	m_mouseReleaseBind = function::MemberFunction<drak::InputManager, void, const events::Event*>(this, &drak::InputManager::mouseReleaseEvent, NULL);
	for (U8 i = 0; i < 43; ++i) {
		m_keyStates.insert(std::make_pair<events::Key, bool>((events::Key)i, false ));
	}
	events::Mouse::Get().addEventListener(events::MouseEvent::MOUSE_MOVE, &m_mouseMoveBind);
	events::Mouse::Get().addEventListener(events::MouseEvent::MOUSE_DOWN, &m_mousePressBind);
	events::Mouse::Get().addEventListener(events::MouseEvent::MOUSE_UP, &m_mouseReleaseBind);
	events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_DOWN, &m_pressEventBind);
	events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_UP, &m_releaseEventBind);
}

void drak::InputManager::keyPressEvent(const events::Event * pEvent){
	if (!pEvent)
		return;
	const events::KeyEvent* key = static_cast<const events::KeyEvent*>(pEvent);
	m_keyStates[key->key] = true;
}

void drak::InputManager::keyReleaseEvent(const events::Event * pEvent){
	if (!pEvent)
		return;
	const events::KeyEvent* key = static_cast<const events::KeyEvent*>(pEvent);
	m_keyStates[key->key] = false;
}

void drak::InputManager::mouseMoveEvent(const events::Event * pEvent){
	if (!pEvent)
		return;
	const events::MouseEvent* mouse = static_cast<const events::MouseEvent*>(pEvent);
	m_mousePos = math::Vec2i(mouse->xPos, mouse->yPos);
}

void drak::InputManager::mousePressEvent(const events::Event * pEvent){
	if (!pEvent)
		return;
	const events::MouseEvent* mouse = static_cast<const events::MouseEvent*>(pEvent);
	switch (mouse->btn) {
	case events::MouseEvent::MouseButton::MOUSE_LEFT:
		m_mouseLeftButtonSate = true;
		break;
	case events::MouseEvent::MouseButton::MOUSE_RIGHT:
		m_mouseRightButtonSate = true;
		break;
	}
}

void drak::InputManager::mouseReleaseEvent(const events::Event * pEvent) {
	if (!pEvent)
		return;
	const events::MouseEvent* mouse = static_cast<const events::MouseEvent*>(pEvent);
	switch (mouse->btn) {
	case events::MouseEvent::MouseButton::MOUSE_LEFT:
		m_mouseLeftButtonSate = false;
		break;
	case events::MouseEvent::MouseButton::MOUSE_RIGHT:
		m_mouseRightButtonSate = false;
		break;
	}
}
