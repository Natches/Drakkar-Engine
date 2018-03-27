#pragma once

namespace drak {
namespace serialization {

template<typename T>
struct MetaData {};

/*
template<typename T, size_t X>
struct MetaData {};*/

} // namespace serialization
} // namespace drak

#define TYPEOF(x) std::remove_reference_t<decltype(x)>

#define DK_STRINGIZE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_STRINGIZE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_PASTE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_PASTE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_POINT_MEMBER(type, ...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_BASE, DK_ARGS_N(__VA_ARGS__))(type, __VA_ARGS__))

#define DK_CHECK_BASE_TYPE(type, ...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_BASE_TYPE_BASE, DK_ARGS_N(__VA_ARGS__))(type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR(fields, type, ...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_FOR_PTR, DK_ARGS_N(__VA_ARGS__))(fields, type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS(type, ...)	\
DK_EXPAND(DK_CONCAT(DK_SIZEOF_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(type, __VA_ARGS__))

#define DK_ALL_FIELDS_BINARY_DATA(fields, N)\
DK_EXPAND(DK_CONCAT(DK_ALL_FIELDS_BINARY_DATA, N)(fields, N - 1))

#define DK_GETTER_METADATA(varArray, N)	\
DK_EXPAND(DK_CONCAT(DK_GETTER_METADATA, N)(varArray))

#define DK_SETTER_METADATA(varArray, N)	\
DK_EXPAND(DK_CONCAT(DK_SETTER_METADATA, N)(varArray))

#define DK_TYPE_NAME(varArray, type, ...)	\
DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(varArray, type, __VA_ARGS__))

#define DK_REVERSE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_REVERSE_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_REVERSE_VA_ARGS0
#define DK_REVERSE_VA_ARGS1(t1)	t1
#define DK_REVERSE_VA_ARGS2(t1, t2) t2, t1
#define DK_REVERSE_VA_ARGS3(t1, t2, t3) t3, t2, t1
#define DK_REVERSE_VA_ARGS4(t1, t2, t3, t4) t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS5(t1, t2, t3, t4, t5) t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS6(t1, t2, t3, t4, t5, t6) t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS7(t1, t2, t3, t4, t5, t6, t7) t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS8(t1, t2, t3, t4, t5, t6, t7, t8) t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS9(t1, t2, t3, t4, t5, t6, t7, t8, t9) t9, t8, t7, t6, t5, t4, t3, t2,t1
#define DK_REVERSE_VA_ARGS10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12) t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS13(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13) t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS14(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14) t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS15(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15) t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS16(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16) t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS17(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17) t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS18(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18) t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS19(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19) t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS20(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20) t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS21(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21) t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS22(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22) t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS23(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23) t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS24(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24) t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS25(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25) t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS26(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26) t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS27(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27) t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS28(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28) t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS29(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29) t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS30(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30) t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS31(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31) t31, t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1
#define DK_REVERSE_VA_ARGS32(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32) t32, t31, t30, t29, t28, t27, t26, t25, t24, t23, t22, t21, t20, t19, t18, t17, t16, t15, t14, t13, t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1


#define DK_STRINGIZE_BASE0(...)		__VA_ARGS__
#define DK_STRINGIZE_BASE1(t)		DK_STRINGIZE_BASE0(#t)
#define DK_STRINGIZE1(t, ...)		DK_STRINGIZE_BASE0(__VA_ARGS__, #t)
#define DK_STRINGIZE_BASE2(t, ...)  DK_EXPAND(DK_STRINGIZE1(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE3(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE2(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE4(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE3(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE5(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE4(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE6(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE5(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE7(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE6(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE8(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE7(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE9(t, ...)  DK_EXPAND(DK_STRINGIZE_BASE8(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE10(t, ...) DK_EXPAND(DK_STRINGIZE_BASE9(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE11(t, ...) DK_EXPAND(DK_STRINGIZE_BASE10(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE12(t, ...) DK_EXPAND(DK_STRINGIZE_BASE11(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE13(t, ...) DK_EXPAND(DK_STRINGIZE_BASE12(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE14(t, ...) DK_EXPAND(DK_STRINGIZE_BASE13(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE15(t, ...) DK_EXPAND(DK_STRINGIZE_BASE14(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE16(t, ...) DK_EXPAND(DK_STRINGIZE_BASE15(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE17(t, ...) DK_EXPAND(DK_STRINGIZE_BASE16(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE18(t, ...) DK_EXPAND(DK_STRINGIZE_BASE17(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE19(t, ...) DK_EXPAND(DK_STRINGIZE_BASE18(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE20(t, ...) DK_EXPAND(DK_STRINGIZE_BASE19(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE21(t, ...) DK_EXPAND(DK_STRINGIZE_BASE20(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE22(t, ...) DK_EXPAND(DK_STRINGIZE_BASE21(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE23(t, ...) DK_EXPAND(DK_STRINGIZE_BASE22(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE24(t, ...) DK_EXPAND(DK_STRINGIZE_BASE23(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE25(t, ...) DK_EXPAND(DK_STRINGIZE_BASE24(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE26(t, ...) DK_EXPAND(DK_STRINGIZE_BASE25(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE27(t, ...) DK_EXPAND(DK_STRINGIZE_BASE26(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE28(t, ...) DK_EXPAND(DK_STRINGIZE_BASE27(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE29(t, ...) DK_EXPAND(DK_STRINGIZE_BASE28(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE30(t, ...) DK_EXPAND(DK_STRINGIZE_BASE29(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE31(t, ...) DK_EXPAND(DK_STRINGIZE_BASE30(__VA_ARGS__, #t))
#define DK_STRINGIZE_BASE32(t, ...) DK_EXPAND(DK_STRINGIZE_BASE31(__VA_ARGS__, #t))

#define DK_PASTE_BASE0(...)		__VA_ARGS__
#define DK_PASTE_BASE1(t)		DK_PASTE_BASE0(##t)
#define DK_PASTE1(t, ...)		DK_PASTE_BASE0(__VA_ARGS__, ##t)
#define DK_PASTE_BASE2(t, ...)  DK_EXPAND(DK_PASTE_BASE1(__VA_ARGS__, ##t))
#define DK_PASTE_BASE3(t, ...)  DK_EXPAND(DK_PASTE_BASE2(__VA_ARGS__, ##t))
#define DK_PASTE_BASE4(t, ...)  DK_EXPAND(DK_PASTE_BASE3(__VA_ARGS__, ##t))
#define DK_PASTE_BASE5(t, ...)  DK_EXPAND(DK_PASTE_BASE4(__VA_ARGS__, ##t))
#define DK_PASTE_BASE6(t, ...)  DK_EXPAND(DK_PASTE_BASE5(__VA_ARGS__, ##t))
#define DK_PASTE_BASE7(t, ...)  DK_EXPAND(DK_PASTE_BASE6(__VA_ARGS__, ##t))
#define DK_PASTE_BASE8(t, ...)  DK_EXPAND(DK_PASTE_BASE7(__VA_ARGS__, ##t))
#define DK_PASTE_BASE9(t, ...)  DK_EXPAND(DK_PASTE_BASE8(__VA_ARGS__, ##t))
#define DK_PASTE_BASE10(t, ...) DK_EXPAND(DK_PASTE_BASE9(__VA_ARGS__, ##t))
#define DK_PASTE_BASE11(t, ...) DK_EXPAND(DK_PASTE_BASE10(__VA_ARGS__, ##t))
#define DK_PASTE_BASE12(t, ...) DK_EXPAND(DK_PASTE_BASE11(__VA_ARGS__, ##t))
#define DK_PASTE_BASE13(t, ...) DK_EXPAND(DK_PASTE_BASE12(__VA_ARGS__, ##t))
#define DK_PASTE_BASE14(t, ...) DK_EXPAND(DK_PASTE_BASE13(__VA_ARGS__, ##t))
#define DK_PASTE_BASE15(t, ...) DK_EXPAND(DK_PASTE_BASE14(__VA_ARGS__, ##t))
#define DK_PASTE_BASE16(t, ...) DK_EXPAND(DK_PASTE_BASE15(__VA_ARGS__, ##t))
#define DK_PASTE_BASE17(t, ...) DK_EXPAND(DK_PASTE_BASE16(__VA_ARGS__, ##t))
#define DK_PASTE_BASE18(t, ...) DK_EXPAND(DK_PASTE_BASE17(__VA_ARGS__, ##t))
#define DK_PASTE_BASE19(t, ...) DK_EXPAND(DK_PASTE_BASE18(__VA_ARGS__, ##t))
#define DK_PASTE_BASE20(t, ...) DK_EXPAND(DK_PASTE_BASE19(__VA_ARGS__, ##t))
#define DK_PASTE_BASE21(t, ...) DK_EXPAND(DK_PASTE_BASE20(__VA_ARGS__, ##t))
#define DK_PASTE_BASE22(t, ...) DK_EXPAND(DK_PASTE_BASE21(__VA_ARGS__, ##t))
#define DK_PASTE_BASE23(t, ...) DK_EXPAND(DK_PASTE_BASE22(__VA_ARGS__, ##t))
#define DK_PASTE_BASE24(t, ...) DK_EXPAND(DK_PASTE_BASE23(__VA_ARGS__, ##t))
#define DK_PASTE_BASE25(t, ...) DK_EXPAND(DK_PASTE_BASE24(__VA_ARGS__, ##t))
#define DK_PASTE_BASE26(t, ...) DK_EXPAND(DK_PASTE_BASE25(__VA_ARGS__, ##t))
#define DK_PASTE_BASE27(t, ...) DK_EXPAND(DK_PASTE_BASE26(__VA_ARGS__, ##t))
#define DK_PASTE_BASE28(t, ...) DK_EXPAND(DK_PASTE_BASE27(__VA_ARGS__, ##t))
#define DK_PASTE_BASE29(t, ...) DK_EXPAND(DK_PASTE_BASE28(__VA_ARGS__, ##t))
#define DK_PASTE_BASE30(t, ...) DK_EXPAND(DK_PASTE_BASE29(__VA_ARGS__, ##t))
#define DK_PASTE_BASE31(t, ...) DK_EXPAND(DK_PASTE_BASE30(__VA_ARGS__, ##t))
#define DK_PASTE_BASE32(t, ...) DK_EXPAND(DK_PASTE_BASE31(__VA_ARGS__, ##t))

#define DK_POINT_MEMBER_BASE0(...)	__VA_ARGS__
#define DK_POINT_MEMBER_BASE1(type, t)\
DK_POINT_MEMBER_BASE0(&type::t)

#define DK_POINT_MEMBER1(type, t, ...)\
DK_POINT_MEMBER_BASE0(__VA_ARGS__, &type::t)

#define DK_POINT_MEMBER_BASE2(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER1(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE3(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE2(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE4(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE3(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE5(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE4(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE6(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE5(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE7(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE6(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE8(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE7(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE9(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE8(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE10(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE9(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE11(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE10(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE12(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE11(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE13(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE12(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE14(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE13(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE15(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE14(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE16(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE15(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE17(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE16(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE18(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE17(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE19(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE18(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE20(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE19(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE21(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE20(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE22(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE21(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE23(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE22(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE24(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE23(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE25(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE24(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE26(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE25(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE27(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE26(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE28(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE27(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE29(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE28(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE30(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE29(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE31(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE30(type, __VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE32(type, t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE31(type, __VA_ARGS__, &type::t))


#define DK_CHECK_BASE_TYPE_BASE0(...)	__VA_ARGS__
#define DK_CHECK_BASE_TYPE_BASE1(type, t)\
DK_POINT_MEMBER_BASE0(drak::types::IsBaseType_V<TYPEOF(type::t)>)

#define DK_CHECK_BASE_TYPE1(type, t, ...)\
DK_POINT_MEMBER_BASE0(__VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>)

#define DK_CHECK_BASE_TYPE_BASE2(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE1(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE3(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE2(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE4(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE3(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE5(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE4(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE6(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE5(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE7(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE6(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE8(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE7(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE9(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE8(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE10(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE9(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE11(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE10(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE12(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE11(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE13(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE12(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE14(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE13(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE15(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE14(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE16(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE15(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE17(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE16(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE18(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE17(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE19(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE18(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE20(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE19(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE21(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE20(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE22(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE21(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE23(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE22(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE24(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE23(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE25(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE24(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE26(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE25(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE27(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE26(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE28(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE27(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE29(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE28(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE30(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE29(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE31(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE30(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))

#define DK_CHECK_BASE_TYPE_BASE32(type, t, ...)\
DK_EXPAND(DK_CHECK_BASE_TYPE_BASE31(type, __VA_ARGS__, drak::types::IsBaseType_V<TYPEOF(type::t)>))


#define DK_GETTER_METADATA_IMPL(varArray, N)\
if (!strcmp(str, ##varArray[N]))	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<N>(s_var))), sizeof(std::get<N>(s_var)));

#define DK_GETTER_METADATA0 return std::make_tuple<void*, size_t>(nullptr, 0);
#define DK_GETTER_METADATA1(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 0)	\
DK_GETTER_METADATA0

#define DK_GETTER_METADATA2(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 1)	\
DK_EXPAND(DK_GETTER_METADATA1(varArray))

#define DK_GETTER_METADATA3(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 2)	\
DK_EXPAND(DK_GETTER_METADATA2(varArray))

#define DK_GETTER_METADATA4(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 3)	\
DK_EXPAND(DK_GETTER_METADATA3(varArray))

#define DK_GETTER_METADATA5(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 4)	\
DK_EXPAND(DK_GETTER_METADATA4(varArray))

#define DK_GETTER_METADATA6(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 5)	\
DK_EXPAND(DK_GETTER_METADATA5(varArray))

#define DK_GETTER_METADATA7(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 6)	\
DK_EXPAND(DK_GETTER_METADATA6(varArray))

#define DK_GETTER_METADATA8(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 7)	\
DK_EXPAND(DK_GETTER_METADATA7(varArray))

#define DK_GETTER_METADATA9(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 8)	\
DK_EXPAND(DK_GETTER_METADATA8(varArray))

#define DK_GETTER_METADATA10(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 9)	\
DK_EXPAND(DK_GETTER_METADATA9(varArray))

#define DK_GETTER_METADATA11(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 10)	\
DK_EXPAND(DK_GETTER_METADATA10(varArray))

#define DK_GETTER_METADATA12(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 11)	\
DK_EXPAND(DK_GETTER_METADATA11(varArray))

#define DK_GETTER_METADATA13(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 12)	\
DK_EXPAND(DK_GETTER_METADATA12(varArray))

#define DK_GETTER_METADATA14(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 13)	\
DK_EXPAND(DK_GETTER_METADATA13(varArray))

#define DK_GETTER_METADATA15(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 14)	\
DK_EXPAND(DK_GETTER_METADATA14(varArray))

#define DK_GETTER_METADATA16(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 15)	\
DK_EXPAND(DK_GETTER_METADATA15(varArray))

#define DK_GETTER_METADATA17(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 16)	\
DK_EXPAND(DK_GETTER_METADATA16(varArray))

#define DK_GETTER_METADATA18(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 17)	\
DK_EXPAND(DK_GETTER_METADATA17(varArray))

#define DK_GETTER_METADATA19(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 18)	\
DK_EXPAND(DK_GETTER_METADATA18(varArray))

#define DK_GETTER_METADATA20(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 19)	\
DK_EXPAND(DK_GETTER_METADATA19(varArray))

#define DK_GETTER_METADATA21(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 20)	\
DK_EXPAND(DK_GETTER_METADATA20(varArray))

#define DK_GETTER_METADATA22(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 21)	\
DK_EXPAND(DK_GETTER_METADATA21(varArray))

#define DK_GETTER_METADATA23(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 22)	\
DK_EXPAND(DK_GETTER_METADATA22(varArray))

#define DK_GETTER_METADATA24(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 23)	\
DK_EXPAND(DK_GETTER_METADATA23(varArray))

#define DK_GETTER_METADATA25(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 24)	\
DK_EXPAND(DK_GETTER_METADATA24(varArray))

#define DK_GETTER_METADATA26(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 25)	\
DK_EXPAND(DK_GETTER_METADATA25(varArray))

#define DK_GETTER_METADATA27(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 26)	\
DK_EXPAND(DK_GETTER_METADATA26(varArray))

#define DK_GETTER_METADATA28(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 27)	\
DK_EXPAND(DK_GETTER_METADATA27(varArray))

#define DK_GETTER_METADATA29(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 28)	\
DK_EXPAND(DK_GETTER_METADATA28(varArray))

#define DK_GETTER_METADATA30(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 29)	\
DK_EXPAND(DK_GETTER_METADATA29(varArray))

#define DK_GETTER_METADATA31(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 30)	\
DK_EXPAND(DK_GETTER_METADATA30(varArray))

#define DK_GETTER_METADATA32(varArray)	\
DK_GETTER_METADATA_IMPL(varArray, 31)	\
DK_EXPAND(DK_GETTER_METADATA31(varArray))

#define DK_SETTER_METADATA_IMPL(varArray, N)							\
if constexpr (!std::is_array_v<TYPEOF(t.*(std::get<N>(s_var)))>) {		\
	if (!strcmp(str, ##varArray[N])){									\
		memcpy(&(t.*(std::get<N>(s_var))), v, sizeof(t.*(std::get<N>(s_var))));\
	}																	\
}																		\
else {																	\
memcpy(&(t.*(std::get<N>(s_var))), v, sizeof(t.*(std::get<N>(s_var))));	\
}

#define DK_SETTER_METADATA0(varArray)
#define DK_SETTER_METADATA1(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 0)	\

#define DK_SETTER_METADATA2(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 1)	\
DK_EXPAND(DK_SETTER_METADATA1(varArray))

#define DK_SETTER_METADATA3(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 2)	\
DK_EXPAND(DK_SETTER_METADATA2(varArray))

#define DK_SETTER_METADATA4(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 3)	\
DK_EXPAND(DK_SETTER_METADATA3(varArray))

#define DK_SETTER_METADATA5(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 4)	\
DK_EXPAND(DK_SETTER_METADATA4(varArray))

#define DK_SETTER_METADATA6(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 5)	\
DK_EXPAND(DK_SETTER_METADATA5(varArray))

#define DK_SETTER_METADATA7(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 6)	\
DK_EXPAND(DK_SETTER_METADATA6(varArray))

#define DK_SETTER_METADATA8(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 7)	\
DK_EXPAND(DK_SETTER_METADATA7(varArray))

#define DK_SETTER_METADATA9(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 8)	\
DK_EXPAND(DK_SETTER_METADATA8(varArray))

#define DK_SETTER_METADATA10(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 9)	\
DK_EXPAND(DK_SETTER_METADATA9(varArray))

#define DK_SETTER_METADATA11(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 10)	\
DK_EXPAND(DK_SETTER_METADATA10(varArray))

#define DK_SETTER_METADATA12(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 11)	\
DK_EXPAND(DK_SETTER_METADATA11(varArray))

#define DK_SETTER_METADATA13(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 12)	\
DK_EXPAND(DK_SETTER_METADATA12(varArray))

#define DK_SETTER_METADATA14(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 13)	\
DK_EXPAND(DK_SETTER_METADATA13(varArray))

#define DK_SETTER_METADATA15(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 14)	\
DK_EXPAND(DK_SETTER_METADATA14(varArray))

#define DK_SETTER_METADATA16(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 15)	\
DK_EXPAND(DK_SETTER_METADATA15(varArray))

#define DK_SETTER_METADATA17(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 16)	\
DK_EXPAND(DK_SETTER_METADATA16(varArray))

#define DK_SETTER_METADATA18(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 17)	\
DK_EXPAND(DK_SETTER_METADATA17(varArray))

#define DK_SETTER_METADATA19(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 18)	\
DK_EXPAND(DK_SETTER_METADATA18(varArray))

#define DK_SETTER_METADATA20(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 19)	\
DK_EXPAND(DK_SETTER_METADATA19(varArray))

#define DK_SETTER_METADATA21(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 20)	\
DK_EXPAND(DK_SETTER_METADATA20(varArray))

#define DK_SETTER_METADATA22(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 21)	\
DK_EXPAND(DK_SETTER_METADATA21(varArray))

#define DK_SETTER_METADATA23(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 22)	\
DK_EXPAND(DK_SETTER_METADATA22(varArray))

#define DK_SETTER_METADATA24(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 23)	\
DK_EXPAND(DK_SETTER_METADATA23(varArray))

#define DK_SETTER_METADATA25(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 24)	\
DK_EXPAND(DK_SETTER_METADATA24(varArray))

#define DK_SETTER_METADATA26(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 25)	\
DK_EXPAND(DK_SETTER_METADATA25(varArray))

#define DK_SETTER_METADATA27(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 26)	\
DK_EXPAND(DK_SETTER_METADATA26(varArray))

#define DK_SETTER_METADATA28(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 27)	\
DK_EXPAND(DK_SETTER_METADATA27(varArray))

#define DK_SETTER_METADATA29(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 28)	\
DK_EXPAND(DK_SETTER_METADATA28(varArray))

#define DK_SETTER_METADATA30(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 29)	\
DK_EXPAND(DK_SETTER_METADATA29(varArray))

#define DK_SETTER_METADATA31(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 30)	\
DK_EXPAND(DK_SETTER_METADATA30(varArray))

#define DK_SETTER_METADATA32(varArray)	\
DK_SETTER_METADATA_IMPL(varArray, 31)	\
DK_EXPAND(DK_SETTER_METADATA31(varArray))

#define DK_CHECK_FOR_PTR_IMPL(fields, type, t)													\
( drak::types::IsBaseType_V<TYPEOF(type::t)> ?													\
std::is_array_v<TYPEOF(type::t)> : drak::serialization::MetaData<TYPEOF(type::t)>::fields::s_hasDynamiclyAllocatedMemory )

#define DK_CHECK_FOR_PTR0
#define DK_CHECK_FOR_PTR1(fields, type, t)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t)	\

#define DK_CHECK_FOR_PTR2(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR1(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR3(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR2(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR4(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR3(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR5(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR4(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR6(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR5(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR7(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR6(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR8(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR7(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR9(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR8(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR10(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR9(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR11(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR10(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR12(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR11(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR13(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR12(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR14(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR13(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR15(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR14(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR16(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR15(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR17(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR16(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR18(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR17(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR19(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR18(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR20(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR19(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR21(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR20(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR22(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR21(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR23(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR22(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR24(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR23(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR25(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR24(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR26(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR25(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR27(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR26(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR28(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR27(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR29(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR28(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR30(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR29(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR31(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR30(fields, type, __VA_ARGS__))

#define DK_CHECK_FOR_PTR32(fields, type, t, ...)\
DK_CHECK_FOR_PTR_IMPL(fields, type, t) && DK_EXPAND(DK_CHECK_FOR_PTR31(fields, type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS_IMPL(type, t)\
sizeof(TYPEOF(type::t))

#define DK_SIZEOF_VA_ARGS0
#define DK_SIZEOF_VA_ARGS1(type, t)\
DK_SIZEOF_VA_ARGS_IMPL(type, t)	\

#define DK_SIZEOF_VA_ARGS2(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS1(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS3(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS2(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS4(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS3(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS5(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS4(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS6(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS5(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS7(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS6(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS8(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS7(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS9(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS8(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS10(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS9(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS11(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS10(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS12(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS11(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS13(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS12(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS14(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS13(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS15(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS14(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS16(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS15(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS17(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS16(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS18(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS17(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS19(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS18(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS20(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS19(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS21(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS20(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS22(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS21(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS23(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS22(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS24(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS23(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS25(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS24(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS26(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS25(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS27(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS26(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS28(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS27(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS29(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS28(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS30(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS29(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS31(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS30(type, __VA_ARGS__))

#define DK_SIZEOF_VA_ARGS32(type, t, ...)\
DK_SIZEOF_VA_ARGS_IMPL(type, t) +	\
DK_EXPAND(DK_SIZEOF_VA_ARGS31(type, __VA_ARGS__))


#define DK_TYPE_NAME_IMPL(varArray, type, t, N)\
if (!strcmp(str, ##varArray[N]))	\
	return typeid(TYPEOF(type::t)).name();

#define DK_TYPE_NAME0 return "";
#define DK_TYPE_NAME1(varArray, type, t)\
DK_TYPE_NAME_IMPL(varArray, type, t, 0)	\
DK_TYPE_NAME0

#define DK_TYPE_NAME2(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME1(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME3(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME2(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME4(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME3(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME5(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME4(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME6(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME5(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME7(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME6(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME8(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME7(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME9(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME8(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME10(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME9(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME11(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME10(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME12(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME11(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME13(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME12(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME14(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME13(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME15(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME14(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME16(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME15(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME17(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME16(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME18(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME17(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME19(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME18(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME20(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME19(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME21(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME20(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME22(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME21(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME23(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME22(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME24(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME23(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME25(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME24(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME26(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME25(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME27(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME26(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME28(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME27(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME29(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME28(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME30(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME29(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME31(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME30(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME32(varArray, type, t, ...)					\
DK_TYPE_NAME_IMPL(varArray, type, t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME31(varArray, type, __VA_ARGS__))

#define DK_ADD_TAB(x)			\
for (int i = 0; i < x; ++i)		\
	os << "\t";

#define DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)							\
binary = fields::get(t, fields::s_varName[N]);								\
for (size_t i = 0; i < std::get<1>(binary); ++i) {							\
		os << ((const char*)std::get<0>(binary))[i];						\
}

#define DK_ALL_FIELDS_BINARY_DATA0(fields, N)\
os << "\n";					\
DK_ADD_TAB(recursionLevel)	\
os << "\tEnd " << #fields << "\n";

#define DK_ALL_FIELDS_BINARY_DATA1(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, 0)	\
DK_ALL_FIELDS_BINARY_DATA0(fields, 0)

#define DK_ALL_FIELDS_BINARY_DATA2(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA1(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA3(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA2(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA4(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA3(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA5(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA4(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA6(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA5(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA7(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA6(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA8(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA7(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA9(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA8(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA10(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA9(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA11(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA10(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA12(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA11(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA13(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA12(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA14(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA13(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA15(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA14(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA16(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA15(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA17(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA16(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA18(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA17(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA19(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA18(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA20(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA19(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA21(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA20(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA22(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA21(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA23(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
 DK_ALL_FIELDS_BINARY_DATA22(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA24(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA23(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA25(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA24(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA26(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA25(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA27(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA26(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA28(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA27(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA29(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA28(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA30(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA29(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA31(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA30(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA32(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA_IMPL(fields, N)	\
DK_ALL_FIELDS_BINARY_DATA31(fields, N - 1)

#define DK_ARGS_N(...) \
DK_ARGS_N_(__VA_ARGS__, DK_ARGS_INV_N_IMPL)

#define DK_ARGS_N_(...) \
DK_EXPAND(DK_ARGS_N_IMPL(__VA_ARGS__))

#define DK_ARGS_N_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16,	\
_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, N, ...) N
#define DK_ARGS_INV_N_IMPL																		\
32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,									\
16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define DK_SERIALIZE_FUNC_BEGIN(type)															\
static std::stringstream& serialize( std::stringstream& os, type& t, int recursionLevel = 0) {	\
DK_ADD_TAB(recursionLevel)																		\
os << "Class " << #type << "\n";

#define DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(type)				\
std::stringstream& type::serialize(std::stringstream& os) {			\
return drak::serialization::MetaData<type>::serialize(os, *this, 0);\
}

#define DK_EMPTY_SERIALIZE_FUNCTION_IN_SERIALIZED_OBJECT(type) \
std::stringstream& type::serialize(std::stringstream& os) {};

#define DK_SERIALIZE_ALL(type, N)				\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)			\
	DK_SERIALIZE_LOOP(PublicFields, N)	\
DK_ADD_TAB(recursionLevel)				\
os << "End Class " << #type << "\n";	\
	return os;							\
DK_END

#define DK_SERIALIZE_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)			\
	DK_SERIALIZE_LOOP(PrivateFields, N)	\
DK_ADD_TAB(recursionLevel)				\
os << "End Class " << #type << "\n";	\
	return os;							\
DK_END

#define DK_SERIALIZE_STATIC_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_STATIC_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)			\
	DK_SERIALIZE_LOOP(PublicFields, N)	\
	DK_SERIALIZE_LOOP(PrivateFields, N)	\
DK_ADD_TAB(recursionLevel)				\
os << "End Class " << #type << "\n";	\
	return os;							\
DK_END

#define DK_SERIALIZE_STATIC_PUBLIC_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
for(int i = 0; i < recursionLevel;++i)			\
	os << "\t";									\
os << "End Class " << #type << "\n";			\
	return os;									\
DK_END

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS_AND_PRIVATE_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PublicFields, N)			\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
DK_ADD_TAB(recursionLevel)						\
	os << "End Class " << #type << "\n";		\
	return os;									\
DK_END

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS(type,  N)\
DK_SERIALIZE_FUNC_BEGIN(type)					\
	DK_SERIALIZE_LOOP(PrivateFields, N)			\
	DK_SERIALIZE_LOOP(PrivateStaticFields, N)	\
	DK_SERIALIZE_LOOP(PublicStaticFields, N)	\
DK_ADD_TAB(recursionLevel)						\
	os << "End Class " << #type << "\n";		\
	return os;									\
DK_END

#define DK_SERIALIZE_LOOP(fields, argN)												\
DK_ADD_TAB(recursionLevel)															\
os << "\t" << #fields << "\n";														\
if constexpr (fields::s_hasDynamiclyAllocatedMemory) {								\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_LOOP_IMPL, argN)(fields))							\
}																					\
else {																				\
	DK_ADD_TAB(recursionLevel)														\
	os << "\t\t" << #fields << " Size " << fields::s_totalSizeAllVar <<				\
		" Binary Data ";															\
	std::tuple<void*, size_t> binary;												\
	DK_ALL_FIELDS_BINARY_DATA(fields, argN)											\
}

#define DK_SERIALIZE_LOOP_IMPL0(fields)\
DK_ADD_TAB(recursionLevel)	\
os << "\tEnd " << #fields << "\n";

#define DK_SERIALIZE_LOOP_IMPL1(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 0)	\
DK_SERIALIZE_LOOP_IMPL0(fields)

#define DK_SERIALIZE_LOOP_IMPL2(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 1)	\
DK_SERIALIZE_LOOP_IMPL1(fields)

#define DK_SERIALIZE_LOOP_IMPL3(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 2)	\
DK_SERIALIZE_LOOP_IMPL2(fields)

#define DK_SERIALIZE_LOOP_IMPL4(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 3)	\
DK_SERIALIZE_LOOP_IMPL3(fields)

#define DK_SERIALIZE_LOOP_IMPL5(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 4)	\
DK_SERIALIZE_LOOP_IMPL4(fields)

#define DK_SERIALIZE_LOOP_IMPL6(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 5)	\
DK_SERIALIZE_LOOP_IMPL5(fields)

#define DK_SERIALIZE_LOOP_IMPL7(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 6)	\
DK_SERIALIZE_LOOP_IMPL6(fields)

#define DK_SERIALIZE_LOOP_IMPL8(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 7)	\
DK_SERIALIZE_LOOP_IMPL7(fields)

#define DK_SERIALIZE_LOOP_IMPL9(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 8)	\
DK_SERIALIZE_LOOP_IMPL8(fields)

#define DK_SERIALIZE_LOOP_IMPL10(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 9)	\
DK_SERIALIZE_LOOP_IMPL9(fields)

#define DK_SERIALIZE_LOOP_IMPL11(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 10)	\
DK_SERIALIZE_LOOP_IMPL10(fields)

#define DK_SERIALIZE_LOOP_IMPL12(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 11)	\
DK_SERIALIZE_LOOP_IMPL11(fields)

#define DK_SERIALIZE_LOOP_IMPL13(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 12)	\
DK_SERIALIZE_LOOP_IMPL12(fields)

#define DK_SERIALIZE_LOOP_IMPL14(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 13)	\
DK_SERIALIZE_LOOP_IMPL13(fields)

#define DK_SERIALIZE_LOOP_IMPL15(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 14)	\
DK_SERIALIZE_LOOP_IMPL14(fields)

#define DK_SERIALIZE_LOOP_IMPL16(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 15)	\
DK_SERIALIZE_LOOP_IMPL15(fields)

#define DK_SERIALIZE_LOOP_IMPL17(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 16)	\
DK_SERIALIZE_LOOP_IMPL16(fields)

#define DK_SERIALIZE_LOOP_IMPL18(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 17)	\
DK_SERIALIZE_LOOP_IMPL17(fields)

#define DK_SERIALIZE_LOOP_IMPL19(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 18)	\
DK_SERIALIZE_LOOP_IMPL18(fields)

#define DK_SERIALIZE_LOOP_IMPL20(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 19)	\
DK_SERIALIZE_LOOP_IMPL19(fields)

#define DK_SERIALIZE_LOOP_IMPL21(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 20)	\
DK_SERIALIZE_LOOP_IMPL20(fields)

#define DK_SERIALIZE_LOOP_IMPL22(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 21)	\
DK_SERIALIZE_LOOP_IMPL21(fields)

#define DK_SERIALIZE_LOOP_IMPL23(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 22)	\
DK_SERIALIZE_LOOP_IMPL22(fields)

#define DK_SERIALIZE_LOOP_IMPL24(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 23)	\
DK_SERIALIZE_LOOP_IMPL23(fields)

#define DK_SERIALIZE_LOOP_IMPL25(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 24)	\
DK_SERIALIZE_LOOP_IMPL24(fields)

#define DK_SERIALIZE_LOOP_IMPL26(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 25)	\
DK_SERIALIZE_LOOP_IMPL25(fields)

#define DK_SERIALIZE_LOOP_IMPL27(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 26)	\
DK_SERIALIZE_LOOP_IMPL26(fields)

#define DK_SERIALIZE_LOOP_IMPL28(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 27)	\
DK_SERIALIZE_LOOP_IMPL27(fields)

#define DK_SERIALIZE_LOOP_IMPL29(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 28)	\
DK_SERIALIZE_LOOP_IMPL28(fields)

#define DK_SERIALIZE_LOOP_IMPL30(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 29)	\
DK_SERIALIZE_LOOP_IMPL29(fields)

#define DK_SERIALIZE_LOOP_IMPL31(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 30)	\
DK_SERIALIZE_LOOP_IMPL30(fields)

#define DK_SERIALIZE_LOOP_IMPL32(fields)	\
DK_SERIALIZE_LOOP_IMPL(fields, 31)	\
DK_SERIALIZE_LOOP_IMPL31(fields)


#define DK_SERIALIZE_LOOP_IMPL(fields, N)																\
if constexpr (fields::s_isVarBaseType[N]) {																\
	std::tuple<void*, size_t> binary{ fields::get(t, fields::s_varName[N]) };							\
	DK_ADD_TAB(recursionLevel)																			\
	os << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " << fields::s_varName[N]				\
	<< " Size " << std::get<1>(binary) <<" Binary Data ";												\
	for (size_t i = 0; i < std::get<1>(binary); ++i) {													\
			os << ((const char*)std::get<0>(binary))[i];												\
	}																									\
	os << "\n";																							\
}																										\
else {																									\
	DK_ADD_TAB(recursionLevel)																			\
	os << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<									\
	fields::s_varName[N] << ":\n";																		\
	TYPEOF(t.*(std::get<N>(fields::s_var))) obj{ t.*(std::get<N>(fields::s_var)) };						\
	MetaData<TYPEOF(obj)>::serialize																	\
		(os, *(TYPEOF(obj)*)std::get<0>(fields::get(t, fields::s_varName[N])), recursionLevel + 2);		\
}

#define DK_NON_SERIALIZED_OBJECT(type)\
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(type)						\
friend drak::serialization::MetaData<type>;				\
static constexpr bool s_serialized = true;				\
public:													\
inline std::stringstream& serialize(std::stringstream& os);

#define DK_METADATA(type)									\
template<>													\
struct drak::serialization::MetaData<type> {				\
static constexpr const char* typeName() { return #type; };	\
static type Create() { return type(); };					\
static type* CreateNew() { return new type; };

#define DK_METADATA_FIELDS(fieldName, type, ...)										\
struct fieldName {																		\
static constexpr std::array<constexpr char*, DK_ARGS_N(__VA_ARGS__)> s_varName =		\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };								\
static constexpr std::array<constexpr bool, DK_ARGS_N(__VA_ARGS__)> s_isVarBaseType =	\
{ DK_REVERSE_VA_ARGS(DK_CHECK_BASE_TYPE(type, __VA_ARGS__)) };							\
static constexpr auto s_var =															\
std::make_tuple(DK_REVERSE_VA_ARGS(DK_POINT_MEMBER(type, __VA_ARGS__)));				\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);								\
static constexpr size_t s_totalSizeAllVar = DK_SIZEOF_VA_ARGS(type, __VA_ARGS__);		\
static constexpr bool s_hasDynamiclyAllocatedMemory =									\
DK_CHECK_FOR_PTR(fieldName, type, __VA_ARGS__);											\
static std::tuple<void*, size_t> get(type& t, const char* str){							\
	DK_GETTER_METADATA(s_varName, DK_ARGS_N(__VA_ARGS__))								\
}																						\
static void set(type& t, const char* str, void* v){										\
	DK_SETTER_METADATA(s_varName, DK_ARGS_N(__VA_ARGS__))								\
}																						\
static const char* typeNameOf(const char* str){											\
	DK_TYPE_NAME(s_varName, type, __VA_ARGS__)											\
}																						\
};

#define DK_PUBLIC_MEMBERS(type, ...)\
DK_METADATA_FIELDS(PublicFields, type, __VA_ARGS__)

#define DK_PRIVATE_MEMBERS(type, ...)\
DK_METADATA_FIELDS(PrivateFields, type, __VA_ARGS__)

#define DK_PUBLIC_STATIC_MEMBERS(type, ...)\
DK_METADATA_FIELDS(PublicStaticFields, type, __VA_ARGS__)

#define DK_PRIVATE_STATIC_MEMBERS(type, ...)\
DK_METADATA_FIELDS(PrivateStaticFields, type, __VA_ARGS__)

#define DK_PUBLIC_METHODE(type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_publicMethodeName =		\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };




#define DK_PRIVATE_METHODE(type, ...)															\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_privateMethodeName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };





#define DK_PUBLIC_STATIC_METHODE(type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPublicMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };




#define DK_PRIVATE_STATIC_METHODE(type, ...)													\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPrivateMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };

#define DK_FAKE_FIELDS_FOR_COMPILER								\
struct PublicFields {												\
static constexpr bool s_hasDynamiclyAllocatedMemory = false;		\
};																	\
struct PrivateFields {												\
	static constexpr bool s_hasDynamiclyAllocatedMemory = false;	\
};																	\
struct PublicStaticFields {											\
	static constexpr bool s_hasDynamiclyAllocatedMemory = false;	\
};																	\
struct PrivateStaticFields {										\
	static constexpr bool s_hasDynamiclyAllocatedMemory = false;	\
};

#define DK_FAKE_METADATA_FOR_COMPILER(type)												\
template<>																				\
struct drak::serialization::MetaData<type>{												\
DK_FAKE_FIELDS_FOR_COMPILER																\
static std::stringstream& serialize(std::stringstream& ss, type, int) { return ss; };	\
};																						\
template<>																				\
struct drak::serialization::MetaData<type[]> {											\
DK_FAKE_FIELDS_FOR_COMPILER																\
static std::stringstream& serialize(std::stringstream& ss, type t[], int) { return ss; };\
};																						\
template<size_t X>																		\
struct drak::serialization::MetaData<type[X]> {											\
DK_FAKE_FIELDS_FOR_COMPILER																\
static std::stringstream& serialize(std::stringstream& ss, type t[X], int) { return ss; };\
};


DK_FAKE_METADATA_FOR_COMPILER(bool)
DK_FAKE_METADATA_FOR_COMPILER(U8)
DK_FAKE_METADATA_FOR_COMPILER(I8)
DK_FAKE_METADATA_FOR_COMPILER(U16)
DK_FAKE_METADATA_FOR_COMPILER(I16)
DK_FAKE_METADATA_FOR_COMPILER(U32)
DK_FAKE_METADATA_FOR_COMPILER(I32)
DK_FAKE_METADATA_FOR_COMPILER(U64)
DK_FAKE_METADATA_FOR_COMPILER(I64)
DK_FAKE_METADATA_FOR_COMPILER(F32)
DK_FAKE_METADATA_FOR_COMPILER(F64)
