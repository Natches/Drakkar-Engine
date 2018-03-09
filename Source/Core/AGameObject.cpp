#include "AGameObject.h"
#include "Log.hpp"

DK_LOG_CATEGORY_DEFINE(GameObjectLog)
DK_LOG_CATEGORY_DECLARE(GameObjectLog, LoggerVerbosity::DEBUG)

AGameObject::AGameObject()
{
}


AGameObject::~AGameObject()
{
}

void AGameObject::setComponentFlag(int id, bool value) {
	m_componentFlags = value ? m_componentFlags | (1 << id) : m_componentFlags ^ (1 << id);
}

void AGameObject::setHandleIDPair(int id, int handle) {
	//if (m_componentFlags&(1 << id)) {
	//	DK_LOG(GameObjectLog, LoggerVerbosity::DEBUG, "componentAlreadyUsed")
	//	return;
	//}
	m_handlesToComponents.insert(std::make_pair(id, handle));
}

int AGameObject::getHandle(int id) {
	return m_handlesToComponents[id];
}
