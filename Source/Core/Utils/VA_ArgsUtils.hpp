#pragma once

#define DK_ARGS_N(...) \
DK_ARGS_N_(__VA_ARGS__, DK_ARGS_INV_N_IMPL)

#define DK_ARGS_N_(...) \
DK_EXPAND(DK_ARGS_N_IMPL(__VA_ARGS__))

#define DK_ARGS_N_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16,	\
_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, N, ...) N
#define DK_ARGS_INV_N_IMPL																		\
32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,									\
16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define DK_STRINGIZE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_STRINGIZE_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_PASTE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_PASTE_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_REVERSE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_REVERSE_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))



#define DK_REVERSE_VA_ARGS0
#define DK_REVERSE_VA_ARGS1(t1)	DK_EXPAND(t1)
#define DK_REVERSE_VA_ARGS2(t1, t2) DK_EXPAND(t2, t1)
#define DK_REVERSE_VA_ARGS3(t1, t2, t3) DK_EXPAND(t3, t2, t1)
#define DK_REVERSE_VA_ARGS4(t1, t2, t3, t4) DK_EXPAND(t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS5(t1, t2, t3, t4, t5) DK_EXPAND(t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS6(t1, t2, t3, t4, t5, t6) DK_EXPAND(t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS7(t1, t2, t3, t4, t5, t6, t7) DK_EXPAND(t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS8(t1, t2, t3, t4, t5, t6, t7, t8) DK_EXPAND(t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS9(t1, t2, t3, t4, t5, t6, t7, t8, t9) DK_EXPAND(t9, t8, t7, t6, t5, t4, t3, t2,t1)
#define DK_REVERSE_VA_ARGS10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) DK_EXPAND(t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) DK_EXPAND(t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) DK_EXPAND(t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS13(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13) DK_EXPAND(t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS14(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14) DK_EXPAND(t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS15(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15) DK_EXPAND(t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS16(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16) DK_EXPAND(t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS17(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17) DK_EXPAND(t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS18(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18) DK_EXPAND(t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS19(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19) DK_EXPAND(t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS20(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20) DK_EXPAND(t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS21(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21) DK_EXPAND(t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS22(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22) DK_EXPAND(t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS23(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23) DK_EXPAND(t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS24(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24) DK_EXPAND(t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS25(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25) DK_EXPAND(t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS26(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26) DK_EXPAND(t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS27(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27) DK_EXPAND(t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS28(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28) DK_EXPAND(t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS29(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29) DK_EXPAND(t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS30(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30) DK_EXPAND(t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS31(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31) DK_EXPAND(t31, t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)
#define DK_REVERSE_VA_ARGS32(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32) DK_EXPAND(t32, t31, t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1)


#define DK_STRINGIZE_IMPL0(...)		__VA_ARGS__
#define DK_STRINGIZE_IMPL1(t)		DK_STRINGIZE_IMPL0(#t)
#define DK_STRINGIZE1(t, ...)		DK_STRINGIZE_IMPL0(__VA_ARGS__, #t)
#define DK_STRINGIZE_IMPL2(t, ...)  DK_EXPAND(DK_STRINGIZE1(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL3(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL2(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL4(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL3(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL5(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL4(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL6(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL5(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL7(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL6(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL8(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL7(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL9(t, ...)  DK_EXPAND(DK_STRINGIZE_IMPL8(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL10(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL9(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL11(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL10(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL12(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL11(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL13(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL12(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL14(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL13(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL15(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL14(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL16(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL15(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL17(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL16(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL18(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL17(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL19(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL18(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL20(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL19(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL21(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL20(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL22(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL21(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL23(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL22(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL24(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL23(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL25(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL24(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL26(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL25(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL27(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL26(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL28(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL27(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL29(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL28(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL30(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL29(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL31(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL30(__VA_ARGS__, #t))
#define DK_STRINGIZE_IMPL32(t, ...) DK_EXPAND(DK_STRINGIZE_IMPL31(__VA_ARGS__, #t))

#define DK_PASTE_IMPL0(...)		__VA_ARGS__
#define DK_PASTE_IMPL1(t)		DK_PASTE_IMPL0(##t)
#define DK_PASTE1(t, ...)		DK_PASTE_IMPL0(__VA_ARGS__, ##t)
#define DK_PASTE_IMPL2(t, ...)  DK_EXPAND(DK_PASTE1(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL3(t, ...)  DK_EXPAND(DK_PASTE_IMPL2(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL4(t, ...)  DK_EXPAND(DK_PASTE_IMPL3(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL5(t, ...)  DK_EXPAND(DK_PASTE_IMPL4(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL6(t, ...)  DK_EXPAND(DK_PASTE_IMPL5(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL7(t, ...)  DK_EXPAND(DK_PASTE_IMPL6(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL8(t, ...)  DK_EXPAND(DK_PASTE_IMPL7(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL9(t, ...)  DK_EXPAND(DK_PASTE_IMPL8(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL10(t, ...) DK_EXPAND(DK_PASTE_IMPL9(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL11(t, ...) DK_EXPAND(DK_PASTE_IMPL10(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL12(t, ...) DK_EXPAND(DK_PASTE_IMPL11(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL13(t, ...) DK_EXPAND(DK_PASTE_IMPL12(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL14(t, ...) DK_EXPAND(DK_PASTE_IMPL13(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL15(t, ...) DK_EXPAND(DK_PASTE_IMPL14(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL16(t, ...) DK_EXPAND(DK_PASTE_IMPL15(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL17(t, ...) DK_EXPAND(DK_PASTE_IMPL16(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL18(t, ...) DK_EXPAND(DK_PASTE_IMPL17(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL19(t, ...) DK_EXPAND(DK_PASTE_IMPL18(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL20(t, ...) DK_EXPAND(DK_PASTE_IMPL19(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL21(t, ...) DK_EXPAND(DK_PASTE_IMPL20(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL22(t, ...) DK_EXPAND(DK_PASTE_IMPL21(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL23(t, ...) DK_EXPAND(DK_PASTE_IMPL22(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL24(t, ...) DK_EXPAND(DK_PASTE_IMPL23(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL25(t, ...) DK_EXPAND(DK_PASTE_IMPL24(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL26(t, ...) DK_EXPAND(DK_PASTE_IMPL25(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL27(t, ...) DK_EXPAND(DK_PASTE_IMPL26(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL28(t, ...) DK_EXPAND(DK_PASTE_IMPL27(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL29(t, ...) DK_EXPAND(DK_PASTE_IMPL28(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL30(t, ...) DK_EXPAND(DK_PASTE_IMPL29(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL31(t, ...) DK_EXPAND(DK_PASTE_IMPL30(__VA_ARGS__, ##t))
#define DK_PASTE_IMPL32(t, ...) DK_EXPAND(DK_PASTE_IMPL31(__VA_ARGS__, ##t))
