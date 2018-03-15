#pragma once

#define CONCATIMPL(x, y) x##y
#define CONCAT(x, y) CONCATIMPL(x, y)
#define CONCATIMPLVAARGS(x, ...) x##__VA_ARGS__
#define CONCATVAARGS(x, ...) CONCATIMPLVAARGS(x, __VA_ARGS__)
#define EXPAND(...) __VA_ARGS__