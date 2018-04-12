#include <Core/Components/AGameObject.h>
void drak::AGameObject::setComponentFlag(int id, bool value) {
	m_componentFlags = value ? m_componentFlags | (1LL << id) : m_componentFlags ^ (1LL << id);
}

bool drak::AGameObject::getComponentFlag(int id){
	return m_componentFlags&(1LL << id);
}

void drak::AGameObject::setHandleIDPair(int id, int handle) {
	m_handlesToComponents.insert(std::make_pair(id, handle));
}