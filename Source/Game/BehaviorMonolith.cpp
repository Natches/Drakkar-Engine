#include <PrecompiledHeader/pch.hpp>
#include <Game\BehaviorMonolith.h>
using namespace drak;
using namespace events;
using namespace function;
using namespace serialization;

void BehaviorMonolith::load() {
	//PlayerBehaviorContainer.push_back(behavior::Player());
	Serializer::LoadFromFile<EExtension::JSON, BehaviorMonolith>(*this, "./Behaviors");
	init();
}

BehaviorMonolith::BehaviorMonolith() {
	Keyboard::Get().addEventListener(KeyEvent::KEY_DOWN,
		new MemberFunction<BehaviorMonolith, void, const Event*>(this, &BehaviorMonolith::serializeEvent, &Keyboard::Get().event()));
}

void BehaviorMonolith::save() {
	Serializer::SerializeToFile<EExtension::JSON, BehaviorMonolith>(*this, "./", "Behaviors");
}

void drak::BehaviorMonolith::init()
{
	for (int i = 0; i < GET_BHVR_CONTAINER(Cube).size(); ++i) {
		GET_BHVR_CONTAINER(Cube)[i]->init();
	}
	for (int i = 0; i < GET_BHVR_CONTAINER(CameraController).size(); ++i) {
		GET_BHVR_CONTAINER(CameraController)[i]->init();
	}
}

void BehaviorMonolith::serializeEvent(const events::Event* pEvent) {
	if (!pEvent)
		return;
	const  events::KeyEvent* ke = static_cast<const  events::KeyEvent*>(pEvent);
	if (ke->key == events::Key::KEY_SPACE)
		save();
}