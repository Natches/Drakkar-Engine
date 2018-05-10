#include <PrecompiledHeader/pch.hpp>
#include "GameObject.hpp"
#include <Engine/Scene/LevelSystem.hpp>
using namespace drak;
using namespace components;

void GameObject::attachChild(U32 childIDX) {
	childrenIDXs.push_back(childIDX);

}
void GameObject::removeChild(U32 childIDX) {
	for (U32 i = 0; i < childrenIDXs.size(); ++i) {
		if (childrenIDXs[i] == childIDX) {
			childrenIDXs[i] = childrenIDXs[childrenIDXs.size() - 1];
			childrenIDXs.pop_back();
		}
	}
}
void GameObject::makeRoot() {
	if (getComponent<components::Transform>().m_isRoot) {
		return;
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
		getComponent<components::Transform>().m_isRoot = true;
		level->addGameObjectToRoots(idx);
	}
}
void GameObject::setParent(const U32 pIDX) {
	if (getComponent<components::Transform>().m_isRoot) {
		getComponent<components::Transform>().m_isRoot = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
	}
	parentIDX = pIDX;
	level->getGameObjects()[pIDX].attachChild(idx);
	Transform& parentTransform = level->getGameObjects()[parentIDX].getComponent<Transform>();
	getComponent<components::Transform>().localPosition = parentTransform.globalPosition - getComponent<components::Transform>().globalPosition;
	getComponent<components::Transform>().localRotation = getComponent<components::Transform>().globalRotation;
	getComponent<components::Transform>().localScale = getComponent<components::Transform>().globalScale;
}