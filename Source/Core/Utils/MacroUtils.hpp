#pragma once

#define DK_STRINGIZE_IMPL(x) #x
#define DK_STRINGIZE(x) DK_STRINGIZE_IMPL(x)
#define DK_CONCATIMPL(x, y) x##y
#define DK_CONCAT(x, y) DK_CONCATIMPL(x, y)
#define DK_EXPAND(...) __VA_ARGS__
#define DK_PASTE(x) DK_EXPAND(##x)
#define COMA ,

#define DK_SELECT(query)		switch(query) {
#define DK_CASE(cond, line)		case cond: line; break;
#define DK_END					}

#define DK_ENUM(name, type, ...) enum name : type { \
	__VA_ARGS__										\
};

#define DK_ENUM_CLASS(name, type, ...) enum class name : type { \
	__VA_ARGS__										\
};

#define DK_USE_NAMESPACE(name) using namespace name;
#define DK_USE(usingType, type) using usingType = type;
#define TYPEOF(x) std::remove_cv_t<std::remove_reference_t<decltype(x)>>
#define NAKED_TYPE(T) std::remove_cv_t<std::remove_reference_t<std::remove_pointer_t<std::remove_all_extents_t<T>>>>
#define REMOVE_ALL_TYPE_MODIFIER(T) \
std::remove_cv_t<std::remove_reference_t<std::remove_pointer_t<std::remove_all_extents_t<drak::types::VectorType_T<T>>>>>