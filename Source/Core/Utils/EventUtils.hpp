#pragma once

#include <Core/Utils/MacroUtils.hpp>

struct Event { 
};



struct MouseEvent : public Event {

enum Type : U8 {
	DOWN,
	UP,
	SCROLL
}	type;


};

