#include <PrecompiledHeader/pch.hpp>
#include "GameObject.hpp"
#include <Engine/Scene/LevelSystem.hpp>
using namespace drak;

void GameObject::removeChild(U32 childIDX) {
	for (U32 i = 0; i < childrenIDXs.size(); ++i) {
		if (childrenIDXs[i] == childIDX) {
			childrenIDXs[i] = *childrenIDXs.end();
			childrenIDXs.pop_back();
		}
	}
}

void GameObject::makeRoot() {
	if (m_isRoot) {
		return;
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
		m_isRoot = true;
		level->addGameObjectToRoots(idx);
	}
}

void GameObject::setParent(U32 pIDX) {
	if (m_isRoot) {
		m_isRoot = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
	}
	parentIDX = pIDX;
	level->getGameObjects()[pIDX].attachChild(idx);
}

void GameObject::setParent(GameObject& parent) {
	if (m_isRoot) {
		m_isRoot = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parent.getIdx()].removeChild(idx);
	}
	parentIDX = parent.getIdx();
	parent.attachChild(idx);
}

void GameObject::attachChild(U32 childIDX) {
	childrenIDXs.push_back(childIDX);
}

void GameObject::attachChild(GameObject& child) {
	childrenIDXs.push_back(child.getIdx());
}


void GameObject::removeChild(GameObject& child) {
	for (U32 i = 0; i < childrenIDXs.size(); ++i) {
		if (childrenIDXs[i] == child.getIdx()) {
			childrenIDXs[i] = *childrenIDXs.end();
			childrenIDXs.pop_back();
		}
	}
}