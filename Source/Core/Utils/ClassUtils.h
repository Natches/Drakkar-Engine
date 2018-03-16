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