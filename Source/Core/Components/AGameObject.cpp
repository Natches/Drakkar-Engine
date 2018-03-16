#include <Core/Components/AGameObject.h>
#include <Core/Log/Log.hpp>

DK_LOG_CATEGORY_DEFINE(GameObjectLog)
DK_LOG_CATEGORY_DECLARE(GameObjectLog, LoggerVerbosity::DEBUG)

AGameObject::AGameObject()
{
}


AGameObject::~AGameObject()
{
}

void AGameObject::setComponentFlag(int id, bool value) {
	m_componentFlags = value ? m_componentFlags | (1ll << id) : m_componentFlags ^ (1ll << id);
}

bool AGameObject::getComponentFlag(int id){
	return m_componentFlags&(1ll <<id);
}

void AGameObject::setHandleIDPair(int id, int handle) {
	m_handlesToComponents.insert(std::make_pair(id, handle));
}

int AGameObject::getHandle(int id) {
	return m_handlesToComponents[id];
}
