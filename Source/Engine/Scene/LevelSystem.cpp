#include <PrecompiledHeader/pch.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <PxPhysicsAPI.h>

using namespace drak;
using namespace core;
using namespace serialization;
using namespace components;

LevelSystem::LevelSystem() {

}

LevelSystem::~LevelSystem() {
}

void drak::LevelSystem::SerializeLevel() {
	if(!filename.empty())
		Serializer::SerializeToFile<EExtension::JSON, LevelSystem>(*this, "./", filename.c_str());
	else
		Serializer::SerializeToFile<EExtension::JSON, LevelSystem>(*this, "./", "Scene");
}

class DefaultSceneBP : public IManualSceneBlueprint {
public:

	// Inherited via IManualSceneBlueprint
	virtual void build(LevelSystem & scene) override
	{
	}
};

#define _INIT_COMPONENTS_OF_TYPE(type)							\
for (U32 i = 0; i < __getComponentContainer(type).size(); ++i) {\
	__getComponentContainer(type)[i].initComponent();			\
}

void LevelSystem::loadScene(const char* name) {
	if (name == nullptr)
		filename = "Untitled";
	else
		filename += name;
	if (io::FileExists((filename + ".json").c_str()) != EError::NO_ERR) {
		DefaultSceneBP def;
		loadScene(def);
		return;
	}
	Serializer::LoadFromFile<EExtension::JSON, LevelSystem>(*this, name);
	_INIT_COMPONENTS_OF_TYPE(Transform)
	_INIT_COMPONENTS_OF_TYPE(RigidBody)
	_INIT_COMPONENTS_OF_TYPE(Model)
	_INIT_COMPONENTS_OF_TYPE(BoxCollider)
	for (U32 i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i].setLevel(this);
	}
	m_resourceManager->startup();
}
#undef _INIT_COMPONENTS_OF_TYPE

void LevelSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*this);
	filename = sceneBluePrint.name;
	SerializeLevel();
	m_resourceManager->updateFromData();
}

bool LevelSystem::startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	//events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_DOWN,
	//	new function::MemberFunction<LevelSystem, void, const events::Event*>(this, &LevelSystem::SerializeEvent, &events::Keyboard::Get().event()));
	m_resourceManager = new ResourceSystem(m_data);
	m_resourceManager->startup();
	if(!m_pAnimationScene)
		m_pAnimationScene = new animation::AnimationScene();
	return true;
}

void LevelSystem::moveChildren(const Transform& parentTransform, const std::vector<U32>& children) {
	for (U32 i = 0; i < children.size(); ++i) {
		if (m_gameObjects[children[i]].getComponentFlag(ComponentType<RigidBody>::id) && m_gameObjects[children[i]].getComponent<RigidBody>()->active()) {
			Engine::Get().getPhysicsSystem().goTo(*m_gameObjects[children[i]].getComponent<RigidBody>(), parentTransform.getGlobalPosition() + math::Rotate(parentTransform.getGlobalRotation(), m_gameObjects[children[i]].getComponent<Transform>()->getLocalPosition()), parentTransform.getGlobalRotation() * m_gameObjects[children[i]].getComponent<Transform>()->getLocalRotation());
		}
		else {
			m_gameObjects[children[i]].getComponent<Transform>()->setGlobalPosition(parentTransform.getGlobalPosition() + math::Rotate(parentTransform.getGlobalRotation(), m_gameObjects[children[i]].getComponent<Transform>()->getLocalPosition()));
			m_gameObjects[children[i]].getComponent<Transform>()->setGlobalRotation(parentTransform.getGlobalRotation() * m_gameObjects[children[i]].getComponent<Transform>()->getLocalRotation());
			m_gameObjects[children[i]].getComponent<Transform>()->isDirty() = true;
		}
		m_gameObjects[children[i]].getComponent<Transform>()->setGlobalScale(parentTransform.getGlobalScale() * m_gameObjects[children[i]].getComponent<Transform>()->getLocalScale());
		moveChildren(*m_gameObjects[children[i]].getComponent<Transform>(), m_gameObjects[children[i]].children());
	}
}

void drak::LevelSystem::propagateMovementFromRoots() {
	for (I32 i = 0; i < m_rootIdxs.size(); ++i) {
		moveChildren(*m_gameObjects[m_rootIdxs[i]].getComponent<Transform>(), m_gameObjects[m_rootIdxs[i]].children());
	}
}

void LevelSystem::SerializeEvent(const events::Event* pEvent) {
	if (!pEvent)
		return;
	const  events::KeyEvent* ke = static_cast<const  events::KeyEvent*>(pEvent);
	if (ke->key == events::Key::KEY_SPACE)
		SerializeLevel();
}

void LevelSystem::shutdown() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Shutdown Scene System\n");
	//SerializeLevel();
	m_resourceManager->shutdown();
	delete m_resourceManager;
}


void LevelSystem::DestroyChild(U32 idx) {
	if (m_gameObjects.size() < idx)
		return;
	GameObject& target = m_gameObjects[idx];
	target.markForDestruction();
	for (U32 i = 0; i < m_gameObjects[idx].children().size(); ++i) {
		DestroyChild(m_gameObjects[idx].children()[i]);
	}
	m_gameObjects[idx].makeRoot();
	m_rootIdxs.pop_back();

	if (target.getComponentFlag(components::ComponentType<components::RigidBody>::id)) {
		destroyComponent<components::RigidBody>(target.getComponentHandles()[components::ComponentType<components::RigidBody>::id]);
	}
	if (target.getComponentFlag(components::ComponentType<components::Model>::id)) {
		destroyComponent<components::Model>(target.getComponentHandles()[components::ComponentType<components::Model>::id]);
	}
	if (target.getComponentFlag(components::ComponentType<components::BoxCollider>::id)) {
		destroyComponent<components::BoxCollider>(target.getComponentHandles()[components::ComponentType<components::BoxCollider>::id]);
	}
	if (target.getComponentFlag(components::ComponentType<components::SphereCollider>::id)) {
		destroyComponent<components::SphereCollider>(target.getComponentHandles()[components::ComponentType<components::SphereCollider>::id]);
	}
	if (target.getComponentFlag(components::ComponentType<components::Transform>::id)) {
		destroyComponent<components::Transform>(target.getComponentHandles()[components::ComponentType<components::Transform>::id]);
	}
}

void LevelSystem::setComponentGameObjectIDX(U32 originalIDX, U32 newIDX) {
	GameObject& target = m_gameObjects[originalIDX];
	if (target.getComponentFlag(components::ComponentType<components::RigidBody>::id)) {
		target.getComponent<components::RigidBody>()->GameObjectID = newIDX;
		target.getComponent<components::RigidBody>()->rigidActor->userData = *reinterpret_cast<void**>(&newIDX);
	}
	if (target.getComponentFlag(components::ComponentType<components::Model>::id)) {
		target.getComponent<components::Model>()->GameObjectID = newIDX;
	}
	if (target.getComponentFlag(components::ComponentType<components::BoxCollider>::id)) {
		target.getComponent<components::BoxCollider>()->GameObjectID = newIDX;
	}
	if (target.getComponentFlag(components::ComponentType<components::SphereCollider>::id)) {
		target.getComponent<components::SphereCollider>()->GameObjectID = newIDX;
	}
	if (target.getComponentFlag(components::ComponentType<components::Transform>::id)) {
		target.getComponent<components::Transform>()->GameObjectID = newIDX;
	}
}

void LevelSystem::destroyGameObject(U32 idx) {
	DestroyChild(idx);
	for (U32 i = 0; i < m_gameObjects.size(); ++i) {
		if (m_gameObjects[i].isMarkedForDestruction()) {
			U32 tmpIDX = m_gameObjects[i].getIdx();
			setComponentGameObjectIDX(m_gameObjects[m_gameObjects.size() - 1].getIdx(), tmpIDX);
			std::swap(m_gameObjects[i], m_gameObjects[m_gameObjects.size() - 1]);
			m_gameObjects[i].setIdx(tmpIDX);
			m_gameObjects.pop_back();
		}
	}
}

GameObject& LevelSystem::addGameObject() {
	try {
		m_gameObjects.push_back(GameObject());
	}
	catch (std::bad_array_new_length &e) {
		Logbook::Log(Logbook::EOutput::CONSOLE, "Level System", e.what());
	}
	GameObject& gameObject = m_gameObjects[m_gameObjects.size() - 1];
	gameObject.setIdx((U32)m_gameObjects.size() - 1);
	gameObject.setLevel(this);
	m_rootIdxs.push_back(gameObject.getIdx());
	//Add transform to all game objects
	addComponentToGameObject<components::Transform>(gameObject);
	return gameObject;
}