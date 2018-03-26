#pragma once

namespace drak {
namespace serialization {

template<typename T>
struct MetaData {};

} // namespace serialization
} // namespace drak


#define DK_STRINGIZE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_STRINGIZE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_PASTE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_PASTE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_POINT_MEMBER(type, ...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_BASE, DK_ARGS_N(__VA_ARGS__))(type, __VA_ARGS__))

#define DK_CHECK_BASE_TYPE(type, ...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_BASE_TYPE_BASE, DK_ARGS_N(__VA_ARGS__))(type, __VA_ARGS__))

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
#define DK_REVERSE_VA_ARGS4(t1, t2, t3, t4)
#define DK_REVERSE_VA_ARGS5(t1, t2, t3, t4, t5)
#define DK_REVERSE_VA_ARGS6(t1, t2, t3, t4, t5, t6)
#define DK_REVERSE_VA_ARGS7(t1, t2, t3, t4, t5, t6, t7)
#define DK_REVERSE_VA_ARGS8(t1, t2, t3, t4, t5, t6, t7, t8)
#define DK_REVERSE_VA_ARGS9(t1, t2, t3, t4, t5, t6, t7, t8, t9)
#define DK_REVERSE_VA_ARGS10(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10)
#define DK_REVERSE_VA_ARGS11(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11)
#define DK_REVERSE_VA_ARGS12(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12)
#define DK_REVERSE_VA_ARGS13(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13)
#define DK_REVERSE_VA_ARGS14(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14)
#define DK_REVERSE_VA_ARGS15(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15)
#define DK_REVERSE_VA_ARGS16(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16)
#define DK_REVERSE_VA_ARGS17(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17)
#define DK_REVERSE_VA_ARGS18(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18)
#define DK_REVERSE_VA_ARGS19(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19)
#define DK_REVERSE_VA_ARGS20(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20)
#define DK_REVERSE_VA_ARGS21(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21)
#define DK_REVERSE_VA_ARGS22(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22)
#define DK_REVERSE_VA_ARGS23(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23)
#define DK_REVERSE_VA_ARGS24(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24)
#define DK_REVERSE_VA_ARGS25(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25)
#define DK_REVERSE_VA_ARGS26(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26)
#define DK_REVERSE_VA_ARGS27(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27)
#define DK_REVERSE_VA_ARGS28(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28)
#define DK_REVERSE_VA_ARGS29(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29)
#define DK_REVERSE_VA_ARGS30(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30)
#define DK_REVERSE_VA_ARGS31(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31)
#define DK_REVERSE_VA_ARGS32(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32)


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

#define DK_POINT_MEMBER_BASE0(...)				__VA_ARGS__
#define DK_POINT_MEMBER_BASE1(type, t)			DK_POINT_MEMBER_BASE0(&type::t)
#define DK_POINT_MEMBER1(type, t, ...)			DK_POINT_MEMBER_BASE0(__VA_ARGS__, &type::t)
#define DK_POINT_MEMBER_BASE2(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER1(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE3(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE2(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE4(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE3(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE5(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE4(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE6(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE5(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE7(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE6(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE8(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE7(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE9(type, t, ...)		DK_EXPAND(DK_POINT_MEMBER_BASE8(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE10(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE9(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE11(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE10(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE12(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE11(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE13(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE12(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE14(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE13(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE15(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE14(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE16(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE15(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE17(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE16(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE18(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE17(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE19(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE18(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE20(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE19(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE21(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE20(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE22(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE21(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE23(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE22(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE24(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE23(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE25(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE24(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE26(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE25(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE27(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE26(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE28(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE27(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE29(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE28(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE30(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE29(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE31(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE30(type, __VA_ARGS__, &type::t))
#define DK_POINT_MEMBER_BASE32(type, t, ...)	DK_EXPAND(DK_POINT_MEMBER_BASE31(type, __VA_ARGS__, &type::t))

#define DK_CHECK_BASE_TYPE_BASE0(...)			__VA_ARGS__
#define DK_CHECK_BASE_TYPE_BASE1(type, t)		DK_POINT_MEMBER_BASE0(drak::types::IsBaseType_V<decltype(type::t)>)
#define DK_CHECK_BASE_TYPE1(type, t, ...)		DK_POINT_MEMBER_BASE0(__VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>)
#define DK_CHECK_BASE_TYPE_BASE2(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE1(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE3(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE2(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE4(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE3(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE5(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE4(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE6(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE5(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE7(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE6(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE8(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE7(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE9(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE8(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE10(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE9(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE11(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE10(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE12(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE11(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE13(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE12(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE14(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE13(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE15(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE14(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE16(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE15(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE17(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE16(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE18(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE17(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE19(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE18(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE20(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE19(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE21(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE20(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE22(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE21(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE23(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE22(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE24(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE23(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE25(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE24(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE26(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE25(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE27(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE26(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE28(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE27(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE29(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE28(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE30(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE29(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE31(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE30(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))
#define DK_CHECK_BASE_TYPE_BASE32(type, t, ...)	DK_EXPAND(DK_CHECK_BASE_TYPE_BASE31(type, __VA_ARGS__, drak::types::IsBaseType_V<decltype(type::t)>))

#define DK_GETTER_METADATA0(varArray) return std::make_tuple<void*, size_t>(nullptr, 0);
#define DK_GETTER_METADATA1(varArray)																\
if (!strcmp(str, ##varArray[0]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<0>(s_var))), sizeof(std::get<0>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA0(varArray))

#define DK_GETTER_METADATA2(varArray)																\
if (!strcmp(str, ##varArray[1]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<1>(s_var))), sizeof(std::get<1>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA1(varArray))

#define DK_GETTER_METADATA3(varArray)																\
if (!strcmp(str, ##varArray[2]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<2>(s_var))), sizeof(std::get<2>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA2(varArray))

#define DK_GETTER_METADATA4(varArray)																\
if (!strcmp(str, ##varArray[3]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<3>(s_var))), sizeof(std::get<3>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA3(varArray))

#define DK_GETTER_METADATA5(varArray)																\
if (!strcmp(str, ##varArray[4]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<4>(s_var))), sizeof(std::get<4>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA4(varArray))

#define DK_GETTER_METADATA6(varArray)																\
if (!strcmp(str, ##varArray[5]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<5>(s_var))), sizeof(std::get<5>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA5(varArray))

#define DK_GETTER_METADATA7(varArray)																\
if (!strcmp(str, ##varArray[6]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<6>(s_var))), sizeof(std::get<6>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA6(varArray))

#define DK_GETTER_METADATA8(varArray)																\
if (!strcmp(str, ##varArray[7]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<7>(s_var))), sizeof(std::get<7>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA7(varArray))

#define DK_GETTER_METADATA9(varArray)																\
if (!strcmp(str, ##varArray[8]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<8>(s_var))), sizeof(std::get<8>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA8(varArray))

#define DK_GETTER_METADATA10(varArray)																\
if (!strcmp(str, ##varArray[9]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<9>(s_var))), sizeof(std::get<9>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA9(varArray))

#define DK_GETTER_METADATA11(varArray)																\
if (!strcmp(str, ##varArray[10]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<10>(s_var))), sizeof(std::get<10>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA10(varArray))

#define DK_GETTER_METADATA12(varArray)																\
if (!strcmp(str, ##varArray[11]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<11>(s_var))), sizeof(std::get<11>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA11(varArray))

#define DK_GETTER_METADATA13(varArray)																\
if (!strcmp(str, ##varArray[12]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<12>(s_var))), sizeof(std::get<12>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA12(varArray))

#define DK_GETTER_METADATA14(varArray)																\
if (!strcmp(str, ##varArray[13]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<13>(s_var))), sizeof(std::get<13>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA13(varArray))

#define DK_GETTER_METADATA15(varArray)																\
if (!strcmp(str, ##varArray[14]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<14>(s_var))), sizeof(std::get<14>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA14(varArray))

#define DK_GETTER_METADATA16(varArray)																\
if (!strcmp(str, ##varArray[15]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<15>(s_var))), sizeof(std::get<15>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA15(varArray))

#define DK_GETTER_METADATA17(varArray)																\
if (!strcmp(str, ##varArray[16]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<16>(s_var))), sizeof(std::get<16>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA16(varArray))

#define DK_GETTER_METADATA18(varArray)																\
if (!strcmp(str, ##varArray[17]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<17>(s_var))), sizeof(std::get<17>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA17(varArray))

#define DK_GETTER_METADATA19(varArray)																\
if (!strcmp(str, ##varArray[18]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<18>(s_var))), sizeof(std::get<18>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA18(varArray))

#define DK_GETTER_METADATA20(varArray)																\
if (!strcmp(str, ##varArray[19]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<19>(s_var))), sizeof(std::get<19>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA19(varArray));

#define DK_GETTER_METADATA21(varArray)																\
if (!strcmp(str, ##varArray[20]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<20>(s_var))), sizeof(std::get<20>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA20(varArray))

#define DK_GETTER_METADATA22(varArray)																\
if (!strcmp(str, ##varArray[21]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<21>(s_var))), sizeof(std::get<21>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA21(varArray))

#define DK_GETTER_METADATA23(varArray)																\
if (!strcmp(str, ##varArray[22]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<22>(s_var))), sizeof(std::get<22>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA22(varArray))

#define DK_GETTER_METADATA24(varArray)																\
if (!strcmp(str, ##varArray[23]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<23>(s_var))), sizeof(std::get<23>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA23(varArray))

#define DK_GETTER_METADATA25(varArray)																\
if (!strcmp(str, ##varArray[24]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<24>(s_var))), sizeof(std::get<24>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA24(varArray))

#define DK_GETTER_METADATA26(varArray)																\
if (!strcmp(str, ##varArray[25]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<25>(s_var))), sizeof(std::get<25>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA25(varArray))

#define DK_GETTER_METADATA27(varArray)																\
if (!strcmp(str, ##varArray[26]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<26>(s_var))), sizeof(std::get<26>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA26(varArray))

#define DK_GETTER_METADATA28(varArray)																\
if (!strcmp(str, ##varArray[27]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<27>(s_var))), sizeof(std::get<27>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA27(varArray))

#define DK_GETTER_METADATA29(varArray)																\
if (!strcmp(str, ##varArray[28]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<28>(s_var))), sizeof(std::get<28>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA28(varArray))

#define DK_GETTER_METADATA30(varArray)																\
if (!strcmp(str, ##varArray[29]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<29>(s_var))), sizeof(std::get<29>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA29(varArray))

#define DK_GETTER_METADATA31(varArray)																\
if (!strcmp(str, ##varArray[30]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<30>(s_var))), sizeof(std::get<30>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA30(varArray))

#define DK_GETTER_METADATA32(varArray)																\
if (!strcmp(str, ##varArray[31]))																	\
	return std::make_tuple<void*, size_t>(&(t.*(std::get<31>(s_var))), sizeof(std::get<31>(s_var)));\
DK_EXPAND(DK_GETTER_METADATA31(varArray))


#define DK_SETTER_METADATA0(varArray)
#define DK_SETTER_METADATA1(varArray)																\
if (!strcmp(str, ##varArray[0]))													\
	t.*(std::get<0>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<0>(s_var))))>*>(v);	\

#define DK_SETTER_METADATA2(varArray)																\
if (!strcmp(str, ##varArray[1]))													\
	t.*(std::get<1>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<1>(s_var))))>*>(v); 	\
DK_EXPAND(DK_SETTER_METADATA1(varArray))

#define DK_SETTER_METADATA3(varArray)																\
if (!strcmp(str, ##varArray[2]))													\
	t.*(std::get<2>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<2>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA2(varArray))

#define DK_SETTER_METADATA4(varArray)																\
if (!strcmp(str, ##varArray[3]))													\
	t.*(std::get<3>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<3>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA3(varArray))

#define DK_SETTER_METADATA5(varArray)																\
if (!strcmp(str, ##varArray[4]))													\
	t.*(std::get<4>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<4>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA4(varArray))

#define DK_SETTER_METADATA6(varArray)																\
if (!strcmp(str, ##varArray[5]))													\
	t.*(std::get<5>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<5>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA5(varArray))

#define DK_SETTER_METADATA7(varArray)																\
if (!strcmp(str, ##varArray[6]))													\
	t.*(std::get<6>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<6>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA6(varArray))

#define DK_SETTER_METADATA8(varArray)															\
if (!strcmp(str, ##varArray[7]))													\
	t.*(std::get<7>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<7>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA7(varArray))

#define DK_SETTER_METADATA9(varArray)																\
if (!strcmp(str, ##varArray[8]))													\
	t.*(std::get<8>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<8>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA8(varArray))

#define DK_SETTER_METADATA10(varArray)															\
if (!strcmp(str, ##varArray[9]))													\
	t.*(std::get<9>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<9>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA9(varArray))

#define DK_SETTER_METADATA11(varArray)															\
if (!strcmp(str, ##varArray[10]))													\
	t.*(std::get<10>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<10>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA10(varArray))

#define DK_SETTER_METADATA12(varArray)															\
if (!strcmp(str, ##varArray[11]))													\
	t.*(std::get<11>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<11>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA11(varArray))

#define DK_SETTER_METADATA13(varArray)															\
if (!strcmp(str, ##varArray[12]))													\
	t.*(std::get<12>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<12>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA12(varArray))

#define DK_SETTER_METADATA14(varArray)															\
if (!strcmp(str, ##varArray[13]))													\
	t.*(std::get<13>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<13>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA13(varArray))

#define DK_SETTER_METADATA15(varArray)															\
if (!strcmp(str, ##varArray[14]))													\
	t.*(std::get<14>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<14>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA14(varArray))

#define DK_SETTER_METADATA16(varArray)															\
if (!strcmp(str, ##varArray[15]))													\
	t.*(std::get<15>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<15>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA15(varArray))

#define DK_SETTER_METADATA17(varArray)															\
if (!strcmp(str, ##varArray[16]))													\
	t.*(std::get<16>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<16>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA16(varArray))

#define DK_SETTER_METADATA18(varArray)															\
if (!strcmp(str, ##varArray[17]))													\
	t.*(std::get<17>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<17>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA17(varArray))

#define DK_SETTER_METADATA19(varArray)															\
if (!strcmp(str, ##varArray[18]))													\
	t.*(std::get<18>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<18>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA18(varArray))

#define DK_SETTER_METADATA20(varArray)															\
if (!strcmp(str, ##varArray[19]))													\
	t.*(std::get<19>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<19>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA19(varArray))

#define DK_SETTER_METADATA21(varArray)															\
if (!strcmp(str, ##varArray[20]))													\
	t.*(std::get<20>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<20>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA20(varArray))

#define DK_SETTER_METADATA22(varArray)															\
if (!strcmp(str, ##varArray[21]))													\
	t.*(std::get<21>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<21>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA21(varArray))

#define DK_SETTER_METADATA23(varArray)															\
if (!strcmp(str, ##varArray[22]))													\
	t.*(std::get<22>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<22>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA22(varArray))

#define DK_SETTER_METADATA24(varArray)															\
if (!strcmp(str, ##varArray[23]))													\
	t.*(std::get<23>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<23>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA23(varArray))

#define DK_SETTER_METADATA25(varArray)															\
if (!strcmp(str, ##varArray[24]))													\
	t.*(std::get<24>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<24>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA24(varArray))

#define DK_SETTER_METADATA26(varArray)															\
if (!strcmp(str, ##varArray[25]))													\
	t.*(std::get<25>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<25>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA25(varArray))

#define DK_SETTER_METADATA27(varArray)															\
if (!strcmp(str, ##varArray[26]))													\
	t.*(std::get<26>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<26>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA26(varArray))

#define DK_SETTER_METADATA28(varArray)															\
if (!strcmp(str, ##varArray[27]))													\
	t.*(std::get<27>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<27>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA27(varArray))

#define DK_SETTER_METADATA29(varArray)															\
if (!strcmp(str, ##varArray[28]))													\
	t.*(std::get<28>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<28>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA28(varArray))

#define DK_SETTER_METADATA30(varArray)															\
if (!strcmp(str, ##varArray[29]))													\
	t.*(std::get<29>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<29>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA29(varArray))

#define DK_SETTER_METADATA31(varArray)															\
if (!strcmp(str, ##varArray[30]))													\
	t.*(std::get<30>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<30>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA30(varArray))

#define DK_SETTER_METADATA32(varArray)															\
if (!strcmp(str, ##varArray[31]))													\
	t.*(std::get<31>(s_var)) =															\
*reinterpret_cast<std::remove_reference_t<decltype((t.*(std::get<31>(s_var))))>*>(v);	\
DK_EXPAND(DK_SETTER_METADATA31(varArray))

#define DK_TYPE_NAME0 return "";
#define DK_TYPE_NAME1(varArray, type, t)					\
if (!strcmp(str, ##varArray[0]))			\
	return typeid(decltype(type::t)).name();	\
DK_TYPE_NAME0

#define DK_TYPE_NAME2(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[1]))			\
	return typeid(decltype(type::t)).name(); 	\
DK_EXPAND(DK_TYPE_NAME1(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME3(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[2]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME2(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME4(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[3]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME3(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME5(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[4]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME4(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME6(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[5]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME5(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME7(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[6]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME6(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME8(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[7]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME7(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME9(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[8]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME8(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME10(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[9]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME9(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME11(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[10]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME10(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME12(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[11]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME11(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME13(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[12]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME12(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME14(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[13]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME13(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME15(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[14]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME14(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME16(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[15]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME15(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME17(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[16]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME16(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME18(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[17]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME17(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME19(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[18]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME18(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME20(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[19]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME19(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME21(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[20]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME20(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME22(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[21]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME21(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME23(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[22]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME22(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME24(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[23]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME23(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME25(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[24]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME24(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME26(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[25]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME25(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME27(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[26]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME26(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME28(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[27]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME27(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME29(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[28]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME28(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME30(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[29]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME29(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME31(varArray, type, t, ...)			\
if (!strcmp(str, ##varArray[30]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME30(varArray, type, __VA_ARGS__))

#define DK_TYPE_NAME32(varArray, type, t, ...)	\
if (!strcmp(str, ##varArray[31]))			\
	return typeid(decltype(type::t)).name();	\
DK_EXPAND(DK_TYPE_NAME31(varArray, type, __VA_ARGS__))

#define DK_ARGS_N(...) \
DK_ARGS_N_(__VA_ARGS__, DK_ARGS_INV_N_IMPL)

#define DK_ARGS_N_(...) \
DK_EXPAND(DK_ARGS_N_IMPL(__VA_ARGS__))

#define DK_ARGS_N_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16,	\
_17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, N, ...) N
#define DK_ARGS_INV_N_IMPL																	\
32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17,									\
16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define DK_SERIALIZE_FUNC_BEGIN(type, returnType)					\
static returnType& serialize(returnType& os, type& t, int recursionLevel = 0) {		\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "Class " << #type << "\n";

#define DK_SERIALIZE_ALL(type, returnType, N)							\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)				\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)				\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)	\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)	\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS(type, returnType, N)				\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)				\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_PRIVATE_MEMBERS(type, returnType, N)				\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)				\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_STATIC_PUBLIC_MEMBERS(type, returnType, N)		\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)	\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_STATIC_PRIVATE_MEMBERS(type, returnType, N)		\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)	\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_PUBLIC_PRIVATE_MEMBERS(type, returnType, N)		\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)				\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)				\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_STATIC_PUBLIC_PRIVATE_MEMBERS(type, returnType, N)\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)							\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)	\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)	\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;														\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS_AND_STATIC_PUBLIC_MEMBERS(type, returnType, N)	\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)										\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)							\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)				\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																	\
DK_END

#define DK_SERIALIZE_PRIVATE_MEMBERS_AND_STATIC_PRIVATE_MEMBERS(type, returnType, N)	\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)											\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)								\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)					\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																		\
DK_END

#define DK_SERIALIZE_PRIVATE_MEMBERS_AND_STATIC_PUBLIC_MEMBERS(type, returnType, N)\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)										\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)							\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)				\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																	\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS_AND_STATIC_PRIVATE_MEMBERS(type, returnType, N)\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)										\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)							\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)				\
for(int i = 0; i < recursionLevel;++i)											\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																	\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS_AND_STATIC_PRIVATE_MEMBERS_AND_STATIC_PUBLIC_MEMBERS(type, returnType, N)	\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)																	\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)														\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)											\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)											\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																								\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS_AND_STATIC_PRIVATE_MEMBERS_AND_PRIVATE_MEMBERS(type, returnType, N)\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)															\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)												\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)									\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)												\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
os << "End Class " << #type << "\n";																	\
	return os;																						\
DK_END

#define DK_SERIALIZE_PUBLIC_MEMBERS_AND_STATIC_PUBLIC_MEMBERS_AND_PRIVATE_MEMBERS(type, returnType, N)	\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)															\
	DK_SERIALIZE_IMPL(PublicMembers, s_publicVarName, N)												\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)									\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)												\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
	os << "End Class " << #type << "\n";																	\
	return os;																						\
DK_END

#define DK_SERIALIZE_PRIVATE_MEMBERS_AND_STATIC_PRIVATE_MEMBERS_AND_STATIC_PUBLIC_MEMBERS(type, returnType, N)	\
DK_SERIALIZE_FUNC_BEGIN(type, returnType)																	\
	DK_SERIALIZE_IMPL(PrivateMembers, s_privateVarName, N)														\
	DK_SERIALIZE_IMPL(StaticPrivateMembers, s_staticPrivateVarName, N)											\
	DK_SERIALIZE_IMPL(StaticPublicMembers, s_staticPublicVarName, N)											\
for(int i = 0; i < recursionLevel;++i)													\
	os << "\t";																		\
	os << "End Class " << #type << "\n";																	\
	return os;																								\
DK_END

#define DK_SERIALIZE_IMPL(membersType, varName, argN)	\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "\t" << #membersType << "\n";								\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_IMPL, argN)(membersType, varName))

#define DK_SERIALIZE_IMPL0(membersType)	\
for(int i = 0; i < recursionLevel;++i)												\
	os << "\t";																		\
os << "\tEnd " << #membersType << "\n";

#define DK_SERIALIZE_IMPL1(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 0)		\
DK_SERIALIZE_IMPL0(membersType)

#define DK_SERIALIZE_IMPL2(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 1)		\
DK_SERIALIZE_IMPL1(membersType, varName)

#define DK_SERIALIZE_IMPL3(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 2)		\
DK_SERIALIZE_IMPL2(membersType, varName)

#define DK_SERIALIZE_IMPL4(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 3)		\
DK_SERIALIZE_IMPL3(membersType, varName)

#define DK_SERIALIZE_IMPL5(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 4)		\
DK_SERIALIZE_IMPL4(membersType, varName)

#define DK_SERIALIZE_IMPL6(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 5)		\
DK_SERIALIZE_IMPL5(membersType, varName)

#define DK_SERIALIZE_IMPL7(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 6)		\
DK_SERIALIZE_IMPL6(membersType, varName)

#define DK_SERIALIZE_IMPL8(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 7)		\
DK_SERIALIZE_IMPL7(membersType, varName)

#define DK_SERIALIZE_IMPL9(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 8)		\
DK_SERIALIZE_IMPL8(membersType, varName)

#define DK_SERIALIZE_IMPL10(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 9)		\
DK_SERIALIZE_IMPL9(membersType, varName)

#define DK_SERIALIZE_IMPL11(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 10)	\
DK_SERIALIZE_IMPL10(membersType, varName)

#define DK_SERIALIZE_IMPL12(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 11)	\
DK_SERIALIZE_IMPL11(membersType, varName)

#define DK_SERIALIZE_IMPL13(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 12)	\
DK_SERIALIZE_IMPL12(membersType, varName)

#define DK_SERIALIZE_IMPL14(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 13)	\
DK_SERIALIZE_IMPL13(membersType, varName)

#define DK_SERIALIZE_IMPL15(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 14)	\
DK_SERIALIZE_IMPL14(membersType, varName)

#define DK_SERIALIZE_IMPL16(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 15)	\
DK_SERIALIZE_IMPL15(membersType, varName)

#define DK_SERIALIZE_IMPL17(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 16)	\
DK_SERIALIZE_IMPL16(membersType, varName)

#define DK_SERIALIZE_IMPL18(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 17)	\
DK_SERIALIZE_IMPL17(membersType, varName)

#define DK_SERIALIZE_IMPL19(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 18)	\
DK_SERIALIZE_IMPL18(membersType, varName)

#define DK_SERIALIZE_IMPL20(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 19)	\
DK_SERIALIZE_IMPL19(membersType, varName)

#define DK_SERIALIZE_IMPL21(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 20)	\
DK_SERIALIZE_IMPL20(membersType, varName)

#define DK_SERIALIZE_IMPL22(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 21)	\
DK_SERIALIZE_IMPL21(membersType, varName)

#define DK_SERIALIZE_IMPL23(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 22)	\
 DK_SERIALIZE_IMPL22(membersType, varName)

#define DK_SERIALIZE_IMPL24(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 23)	\
DK_SERIALIZE_IMPL23(membersType, varName)

#define DK_SERIALIZE_IMPL25(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 24)	\
DK_SERIALIZE_IMPL24(membersType, varName)

#define DK_SERIALIZE_IMPL26(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 25)	\
DK_SERIALIZE_IMPL25(membersType, varName)

#define DK_SERIALIZE_IMPL27(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 26)	\
DK_SERIALIZE_IMPL26(membersType, varName)

#define DK_SERIALIZE_IMPL28(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 27)	\
DK_SERIALIZE_IMPL27(membersType, varName)

#define DK_SERIALIZE_IMPL29(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 28)	\
DK_SERIALIZE_IMPL28(membersType, varName)

#define DK_SERIALIZE_IMPL30(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 29)	\
DK_SERIALIZE_IMPL29(membersType, varName)

#define DK_SERIALIZE_IMPL31(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 30)	\
DK_SERIALIZE_IMPL30(membersType, varName)

#define DK_SERIALIZE_IMPL32(membersType, varName)	\
DK_SERIALIZE_LOOP_IMPL(membersType, varName, 31)	\
DK_SERIALIZE_IMPL31(membersType, varName)


#define DK_SERIALIZE_LOOP_IMPL(membersType, varName, N)																					\
if constexpr (membersType::s_isVarBaseType[N]) {																						\
	std::tuple<void*, size_t> binary{ membersType::get(t, membersType::varName[N]) };													\
	for(int i = 0; i < recursionLevel;++i)																								\
		os << "\t";																														\
	os << "\t\t" << membersType::typeNameOf(membersType::varName[N]) << " " << membersType::varName[N]									\
	<< " Binary Data ";																													\
	for (size_t i = 0; i < std::get<1>(binary); ++i) {																					\
			os << ((const char*)std::get<0>(binary))[i];																				\
	}																																	\
	os << "\n";																															\
}																																		\
else {																																	\
	for (int i = 0; i < recursionLevel; ++i)																							\
		os << "\t";																														\
	os << "\t\t" << membersType::typeNameOf(membersType::varName[N]) << " " << membersType::varName[N] << ":\n";						\
	decltype(t.*(std::get<N>(membersType::s_var))) obj{ t.*(std::get<N>(membersType::s_var)) };											\
	MetaData<std::remove_reference_t<decltype(obj)>>::serialize																			\
		(os, *(std::remove_reference_t<decltype(obj)>*)std::get<0>(membersType::get(t, membersType::varName[N])), recursionLevel + 2);						\
}

#define DK_NON_SERIALIZED_OBJECT(Type)		\
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(Type)			\
friend drak::serialization::MetaData<Type>;	\
static constexpr bool s_serialized = true;	\
static std::ostream& Type::serialize(std::ostream& os, Type& t);

#define DK_METADATA(Type)																	\
template<>																					\
struct drak::serialization::MetaData<Type> {												\
static constexpr const char* typeName() { return #Type; };


#define DK_PUBLIC_MEMBERS(Type, ...)														\
struct PublicMembers {																		\
static constexpr std::array<constexpr char*, DK_ARGS_N(__VA_ARGS__)> s_publicVarName =		\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr std::array<constexpr bool, DK_ARGS_N(__VA_ARGS__)> s_isVarBaseType =		\
{ DK_CHECK_BASE_TYPE(Type, __VA_ARGS__) };													\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static std::tuple<void*, size_t> get(Type& t, const char* str){								\
	DK_GETTER_METADATA(s_publicVarName, DK_ARGS_N(__VA_ARGS__))								\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_publicVarName, DK_ARGS_N(__VA_ARGS__))								\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_publicVarName, Type, __VA_ARGS__)										\
}																							\
};																							\

#define DK_PRIVATE_MEMBERS(Type, ...)														\
struct PrivateMembers {																		\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_privateVarName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static std::tuple<void*, size_t> get(Type& t, const char* str){								\
	DK_GETTER_METADATA(s_privateVarName, DK_ARGS_N(__VA_ARGS__))							\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_privateVarName, DK_ARGS_N(__VA_ARGS__))							\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_privateVarName, Type, __VA_ARGS__)										\
}																							\
};																							\

#define DK_PUBLIC_STATIC_MEMBERS(Type, ...)													\
struct StaticPublicMembers {																\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_staticPublicVarName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static std::tuple<void*, size_t> get(Type& t, const char* str){								\
	DK_GETTER_METADATA(s_staticPublicVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_staticPublicVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_staticPublicVarName, Type, __VA_ARGS__)									\
}																							\
};																							\

#define DK_PRIVATE_STATIC_MEMBERS(Type, ...)												\
struct StaticPrivateMembers {																\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_staticPrivateVarName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static std::tuple<void*, size_t> get(Type& t, const char* str){								\
	DK_GETTER_METADATA(s_staticPrivateVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_staticPrivateVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_staticPrivateVarName, Type, __VA_ARGS__)									\
}																							\
};																							\

#define DK_PUBLIC_METHODE(Type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_publicMethodeName =		\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };




#define DK_PRIVATE_METHODE(Type, ...)															\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_privateMethodeName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };





#define DK_PUBLIC_STATIC_METHODE(Type, ...)														\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPublicMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };




#define DK_PRIVATE_STATIC_METHODE(Type, ...)													\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> m_staticPrivateMethodeName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };

DK_METADATA(bool)
static std::stringstream& serialize(std::stringstream& ss, bool, int) { return ss; };
DK_END;

DK_METADATA(U8)
static std::stringstream& serialize(std::stringstream& ss, U8, int) { return ss; };
DK_END;

DK_METADATA(I8)
static std::stringstream& serialize(std::stringstream& ss, I8, int) { return ss; };
DK_END;

DK_METADATA(U16)
static std::stringstream& serialize(std::stringstream& ss, U16, int) { return ss; };
DK_END;

DK_METADATA(I16)
static std::stringstream& serialize(std::stringstream& ss, I16, int) { return ss; };
DK_END;

DK_METADATA(U32)
static std::stringstream& serialize(std::stringstream& ss, U32, int) { return ss; };
DK_END;

DK_METADATA(I32)
static std::stringstream& serialize(std::stringstream& ss, I32, int) { return ss; };
DK_END;

DK_METADATA(U64)
static std::stringstream& serialize(std::stringstream& ss, U64, int) { return ss; };
DK_END;

DK_METADATA(I64)
static std::stringstream& serialize(std::stringstream& ss, I64, int) { return ss; };
DK_END;

DK_METADATA(F32)
static std::stringstream& serialize(std::stringstream& ss, F32, int) { return ss; };
DK_END;

DK_METADATA(F64)
static std::stringstream& serialize(std::stringstream& ss, F64, int) { return ss; };
DK_END;
