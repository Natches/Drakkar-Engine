#pragma once

#define DK_NOMOVE_CTOR(T) T(T&&) = delete;
#define DK_NOCOPY_CTOR(T) T(const T&) = delete;
#define DK_NOMOVE_OP(T) T& operator=(T&&) = delete;
#define DK_NOCOPY_OP(T) T& operator=(const T&) = delete;

#define DK_NOMOVE_NOCOPY_CTOR(T)\
DK_NOMOVE_CTOR(T)				\
DK_NOCOPY_CTOR(T)

#define DK_NOMOVE_NOCOPY_OP(T)  \
DK_NOMOVE_OP(T)					\
DK_NOCOPY_OP(T)

#define DK_NONCOPYABLE(T)		\
DK_NOCOPY_CTOR(T)				\
DK_NOCOPY_OP(T)


#define DK_NONMOVABLE(T)		\
DK_NOMOVE_CTOR(T)				\
DK_NOMOVE_OP(T)

#define DK_NONMOVABLE_NONCOPYABLE(T) \
DK_NOMOVE_NOCOPY_CTOR(T)			 \
DK_NOMOVE_NOCOPY_OP(T)

#define DK_GETTER(T, name, var)	T name() { return var; };
#define DK_GETTER_C(T, name, var) T name() const { return var; };
#define DK_GETTER_REF_C(T, name, var) const T& name() const	{ return var; };
#define DK_GETTER_REF_V(T, name, var) T& name()	{ return var; };

#define DK_SETTER(T, name, var)	void name(T	val) { var = val; };
#define DK_SETTER_REF_C(T, name, var) void name(const T& val) { var = val; };
#define DK_SETTER_MOVE(T, name, var) void name(T&& val) { var = std::move(val); };

#ifdef DRAK_EXPORT
#define DRAK_API __declspec(dllexport)
#else
#define DRAK_API __declspec(dllimport)
#endif