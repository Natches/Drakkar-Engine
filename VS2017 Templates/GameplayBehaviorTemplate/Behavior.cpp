#include <PrecompiledHeader\pch.hpp>
#include <Engine/Engine.hpp>
#include "$safeitemname$.hpp"

using namespace drak;
using namespace core;
using namespace behavior;
using namespace events;
using namespace function;

$safeitemname$::$safeitemname$() : updateBind(MemberFunction<$safeitemname$, void, const Event*>(this, &$safeitemname$::update, NULL)),
startBind(MemberFunction<$safeitemname$, void, const Event*>(this, &$safeitemname$::start, NULL)) {
}

$safeitemname$::~$safeitemname$() {
}

void $safeitemname$::init() {
	bindUpdateToEngine();
	bindStartToEngine();
}

void $safeitemname$::update(const Event* pEvent) {

}

void $safeitemname$::start(const Event* pEvent) {

}

void $safeitemname$::bindUpdateToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_START, new MemberFunction<$safeitemname$, void, const Event*>(this, &$safeitemname$::start));
}
void $safeitemname$::bindStartToEngine() {
	Engine::Get().GetEventDispatcher().addEventListener(events::EngineEventDispatcher::UPDATE_LOOP_START, new MemberFunction<$safeitemname$, void, const Event*>(this, &$safeitemname$::update));
}