#pragma once

#define DK_STRINGIZE_IMPL(x) #x
#define DK_STRINGIZE(x) DK_STRINGIZE_IMPL(x)
#define DK_CONCATIMPL(x, y) x##y
#define DK_CONCAT(x, y) DK_CONCATIMPL(x, y)
#define DK_EXPAND(...) __VA_ARGS__

#define DK_SELECT(query)		switch(query) {
#define DK_CASE(cond, line)		case cond: line; break;
#define DK_END					}

#define DK_IMPORT(Namespace) using namespace Namespace;