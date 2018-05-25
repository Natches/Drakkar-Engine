#include <PrecompiledHeader/pch.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Components/GameObject.hpp>
#include <Engine/Engine.hpp>
#include <PxPhysicsAPI.h>
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
	if (getComponent<components::Transform>()->isRoot()) {
		return;
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
		getComponent<components::Transform>()->isRoot() = true;
		level->addGameObjectToRoots(idx);
	}
	getComponent<RigidBody>()->activate(true);
}
void GameObject::setParent(const I32 pIDX) {
	if (getComponent<components::Transform>()->isRoot()) {
		getComponent<components::Transform>()->isRoot() = false;
		level->removeGameObjectFromRoots(idx);
	}
	else {
		level->getGameObjects()[parentIDX].removeChild(idx);
	}
	parentIDX = pIDX;
	level->getGameObjects()[pIDX].attachChild(idx);
	getComponent<RigidBody>()->activate(false);
	Transform& parentTransform = *level->getGameObjects()[parentIDX].getComponent<Transform>();
	getComponent<components::Transform>()->setLocalPosition(getComponent<components::Transform>()->getGlobalPosition() - parentTransform.getGlobalPosition());
	getComponent<components::Transform>()->setLocalScale(getComponent<components::Transform>()->getGlobalScale() / parentTransform.getGlobalScale());
}