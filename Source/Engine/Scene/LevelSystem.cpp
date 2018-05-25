#include <PrecompiledHeader/pch.hpp>
//#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
//#include <Serialization\Serializer.hpp>
//#include <Engine\Engine.hpp>
//#include <fstream>
//#include <PxPhysicsAPI.h>
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
		if(m_gameObjects[i].getParent() >= 0 )
			m_gameObjects[i].setParent(m_gameObjects[i].getParent());
	}
}
#undef _INIT_COMPONENTS_OF_TYPE(type)

void LevelSystem::loadScene(IManualSceneBlueprint& sceneBluePrint) {
	sceneBluePrint.build(*this);
	filename = sceneBluePrint.name;
	SerializeLevel();
}

bool LevelSystem::startup() {
	Logbook::Log(Logbook::EOutput::BOTH, "SceneSystem.txt", "Startup Scene System\n");
	//events::Keyboard::Get().addEventListener(events::KeyEvent::KEY_DOWN,
	//	new function::MemberFunction<LevelSystem, void, const events::Event*>(this, &LevelSystem::SerializeEvent, &events::Keyboard::Get().event()));

	return true;
}

void LevelSystem::moveChildren(const Transform& parentTransform, const std::vector<U32>& children) {
	for (U32 i = 0; i < children.size(); ++i) {
		m_gameObjects[children[i]].getComponent<Transform>()->setGlobalPosition(parentTransform.getGlobalPosition() + math::Rotate(parentTransform.getGlobalRotation(), m_gameObjects[children[i]].getComponent<Transform>()->getLocalPosition()));
		m_gameObjects[children[i]].getComponent<Transform>()->setGlobalScale(parentTransform.getGlobalScale() * m_gameObjects[children[i]].getComponent<Transform>()->getLocalScale());
		m_gameObjects[children[i]].getComponent<Transform>()->setGlobalRotation(parentTransform.getGlobalRotation() * m_gameObjects[children[i]].getComponent<Transform>()->getLocalRotation());
		m_gameObjects[children[i]].getComponent<Transform>()->isDirty() = true;
		moveChildren(*m_gameObjects[children[i]].getComponent<Transform>(), m_gameObjects[children[i]].children());
	}
}

void drak::LevelSystem::propogateMovementFromRoots() {
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
}