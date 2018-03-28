#pragma once

#include <string>

#include <Core/Engine/Types.hpp>
#include <Core/Utils/ClassUtils.hpp>
#include <Threading/Function/Function.hpp>

namespace drak {
namespace events {

using EventType	= U8;
struct Event {
	EventType type;
};

using EventListener = function::GlobalFunction<void, Event*>;
class IEventDispatcher {
public:
	virtual ~IEventDispatcher() {};

	virtual void addEventListener(EventType type, EventListener listener) = 0;
	virtual void removeEventListener(EventType type, EventListener listener) = 0;

protected:
	virtual void dispatchEvent(Event* e) = 0;
};

} // namespace core
} // namespace drak

