#include <PrecompiledHeader/pch.hpp>
#include "AGameObject.hpp"
#include <Engine/Scene/LevelSystem.hpp>
using namespace drak;

void AGameObject::makeRoot() {
	if (m_isRoot) {
		return;
	}
	else {
		level->getGameObjects()[parentIDX]->removeChild(idx);
		m_isRoot = true;
		level->addGameObjectToRoots(idx);
	}
}

void AGameObject::setParent(U32 pIDX) {
	if (m_isRoot) {
		m_isRoot = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parentIDX]->removeChild(idx);
	}
	parentIDX = pIDX;
	level->getGameObjects()[pIDX]->attachChild(idx);
}

void AGameObject::setParent(AGameObject& parent) {
	if (m_isRoot) {
		m_isRoot = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parent.getIdx()]->removeChild(idx);
	}
	parentIDX = parent.getIdx();
	parent.attachChild(idx);
}

void AGameObject::attachChild(U32 childIDX) {
	childrenIDXs.push_back(childIDX);
}

void AGameObject::attachChild(AGameObject& child) {
	childrenIDXs.push_back(child.getIdx());
}

void AGameObject::removeChild(U32 childIDX) {
	for (U32 i = 0; i < childrenIDXs.size(); ++i) {
		if (childrenIDXs[i] == childIDX) {
			childrenIDXs[i] = *childrenIDXs.end();
			childrenIDXs.pop_back();
		}
	}
}
void AGameObject::removeChild(AGameObject& child) {
	for (U32 i = 0; i < childrenIDXs.size(); ++i) {
		if (childrenIDXs[i] == child.getIdx()) {
			childrenIDXs[i] = *childrenIDXs.end();
			childrenIDXs.pop_back();
		}
	}
}