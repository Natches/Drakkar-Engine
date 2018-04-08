#pragma once

#include <string>
#include <list>
#include <map>

#include <Core/Engine/Types.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Threading/Function/Function.hpp>

namespace drak {
namespace events {

using EventType	= U8;
struct Event {
	EventType type;
};

using EventListener = function::GlobalFunction<void, const Event*>*;
class IEventDispatcher {
public:
	virtual ~IEventDispatcher() {};

	virtual void addEventListener(EventType type, EventListener listener) = 0;
	virtual void removeEventListener(EventType type, EventListener listener) = 0;

protected:
	virtual void dispatchEvent(const Event* e) = 0;
};

class DefaultEventDispatcher: public IEventDispatcher {
public:
	void addEventListener(EventType type, EventListener listener) override;
	void removeEventListener(EventType type, EventListener listener) override;

protected:
	void dispatchEvent(const Event* e) override;
	std::map<EventType, std::list<EventListener>> m_listeners;
};


} // namespace core
} // namespace drak

