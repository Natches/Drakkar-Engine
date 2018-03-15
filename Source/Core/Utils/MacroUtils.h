#pragma once

#define DK_CONCATIMPL(x, y) x##y
#define DK_CONCAT(x, y) DK_CONCATIMPL(x, y)
#define DK_EXPAND(...) __VA_ARGS__

#define DK_IMPORT(Namespace) using namespace Namespace;