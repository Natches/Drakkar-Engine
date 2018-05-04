#include <PrecompiledHeader/pch.hpp>
#include <Game\BehaviorMonolith.h>
using namespace drak;
using namespace events;
using namespace function;
using namespace serialization;

void BehaviorMonolith::load() {
	//PlayerBehaviorContainer.push_back(behavior::Player());
	//drak::serialization::Serializer::LoadFile<EExtension::JSON, BehaviorMonolith>(*this, "Behaviors");
}

BehaviorMonolith::BehaviorMonolith() {
	Keyboard::Get().addEventListener(KeyEvent::KEY_DOWN,
		new MemberFunction<BehaviorMonolith, void, const Event*>(this, &BehaviorMonolith::serializeEvent, &Keyboard::Get().event()));
}

void BehaviorMonolith::save() {
	std::stringstream out;
	Serialize<EExtension::JSON>(out);
	std::fstream file;
	file.open("Behaviors.json", std::fstream::out);
	if (file.is_open()) {
		file << out.rdbuf();
		file.close();
	}
}

void drak::BehaviorMonolith::init()
{
	for (int i = 0; i < GET_BHVR_CONTAINER(Cube).size(); ++i) {
		GET_BHVR_CONTAINER(Cube)[i].init();
	}
}

void BehaviorMonolith::serializeEvent(const events::Event* pEvent) {
	if (!pEvent)
		return;
	const  events::KeyEvent* ke = static_cast<const  events::KeyEvent*>(pEvent);
	if (ke->key == events::Key::KEY_SPACE)
		save();
}