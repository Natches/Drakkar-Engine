#pragma once

#define LOG_FILE "Serialization.log"

namespace drak {
namespace serialization {

template<typename T>
struct MetaData {};

template<typename T>
struct IFields {
	virtual const char* varName(int idx) = 0;
	virtual int varN() = 0;
	virtual size_t totalSizeAllVar() = 0;
	virtual bool hasDynamiclyAllocatedMemory() = 0;
	virtual std::tuple<void*, size_t> getVar(T& t, const char* str) = 0;
};

} // namespace serialization
} // namespace drak

#define TYPEOF(x) std::remove_reference_t<decltype(x)>

#define DK_STRINGIZE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_STRINGIZE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_PASTE_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_PASTE_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_POINT_MEMBER(...)	\
DK_EXPAND(DK_CONCAT(DK_POINT_MEMBER_BASE, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_CHECK_FOR_PTR(...)	\
DK_EXPAND(DK_CONCAT(DK_CHECK_FOR_PTR, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS(...)	\
DK_EXPAND(DK_CONCAT(DK_SIZEOF_VA_ARGS, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

#define DK_ALL_FIELDS_BINARY_DATA(fields, N)\
DK_EXPAND(DK_CONCAT(DK_ALL_FIELDS_BINARY_DATA, N)(fields, N - 1))

#define DK_GETTER_METADATA( N)	\
DK_EXPAND(DK_CONCAT(DK_GETTER_METADATA, N)( N - 1))

#define DK_SETTER_METADATA(varArray, N)	\
DK_EXPAND(DK_CONCAT(DK_SETTER_METADATA, N)(varArray))

#define DK_TYPE_NAME(...)	\
DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))

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
#define DK_POINT_MEMBER_BASE1(t)\
DK_POINT_MEMBER_BASE0(&type::t)

#define DK_POINT_MEMBER1(t, ...)\
DK_POINT_MEMBER_BASE0(__VA_ARGS__, &type::t)

#define DK_POINT_MEMBER_BASE2(t, ...)\
DK_EXPAND(DK_POINT_MEMBER1(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE3(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE2(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE4(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE3(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE5(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE4(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE6(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE5(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE7(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE6(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE8(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE7(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE9(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE8(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE10(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE9(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE11(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE10(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE12(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE11(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE13(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE12(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE14(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE13(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE15(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE14(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE16(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE15(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE17(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE16(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE18(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE17(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE19(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE18(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE20(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE19(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE21(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE20(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE22(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE21(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE23(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE22(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE24(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE23(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE25(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE24(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE26(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE25(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE27(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE26(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE28(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE27(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE29(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE28(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE30(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE29(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE31(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE30(__VA_ARGS__, &type::t))

#define DK_POINT_MEMBER_BASE32(t, ...)\
DK_EXPAND(DK_POINT_MEMBER_BASE31(__VA_ARGS__, &type::t))


#define DK_GETTER_METADATA_IMPL															\
template<typename T, int N>																\
static std::tuple<void*, size_t> getData(type& t) {										\
if constexpr (!std::is_array_v<T>){														\
	return std::make_tuple<void*, size_t>												\
	(&(t.*(std::get<N>(s_var))), sizeof(std::get<N>(s_var)));							\
}																						\
else if constexpr(drak::types::IsBaseType_V<std::remove_all_extents_t<T>>) {			\
	return std::make_tuple<void*, size_t>												\
	((void*)(t.*(std::get<N>(s_var))), sizeof(t.*(std::get<N>(s_var))));				\
}																						\
else {																					\
	return std::make_tuple<void*, size_t>												\
	((void*)(t.*(std::get<N>(s_var))), sizeof(t.*(std::get<N>(s_var))));				\
}																						\
}

#define DK_CALL_GETTER( N)							\
if (!strcmp(str, s_varName[N]))						\
return getData<TYPEOF(t.*(std::get<N>(s_var))), N>(t);

#define DK_GETTER_METADATA0 return std::make_tuple<void*, size_t>(nullptr, 0);
#define DK_GETTER_METADATA1( N)\
DK_CALL_GETTER( N)	\
DK_GETTER_METADATA0

#define DK_GETTER_METADATA2( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA1( N - 1))

#define DK_GETTER_METADATA3( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA2( N - 1))

#define DK_GETTER_METADATA4( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA3( N - 1))

#define DK_GETTER_METADATA5( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA4( N - 1))

#define DK_GETTER_METADATA6( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA5( N - 1))

#define DK_GETTER_METADATA7( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA6( N - 1))

#define DK_GETTER_METADATA8( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA7( N - 1))

#define DK_GETTER_METADATA9( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA8( N - 1))

#define DK_GETTER_METADATA10(N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA9( N - 1))

#define DK_GETTER_METADATA11( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA10( N - 1))

#define DK_GETTER_METADATA12( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA11( N - 1))

#define DK_GETTER_METADATA13( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA12( N - 1))

#define DK_GETTER_METADATA14( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA13( N - 1))

#define DK_GETTER_METADATA15( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA14( N - 1))

#define DK_GETTER_METADATA16( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA15( N - 1))

#define DK_GETTER_METADATA17( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA16( N - 1))

#define DK_GETTER_METADATA18( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA17( N - 1))

#define DK_GETTER_METADATA19( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA18( N - 1))

#define DK_GETTER_METADATA20( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA19( N - 1))

#define DK_GETTER_METADATA21( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA20( N - 1))

#define DK_GETTER_METADATA22( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA21( N - 1))

#define DK_GETTER_METADATA23( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA22( N - 1))

#define DK_GETTER_METADATA24( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA23( N - 1))

#define DK_GETTER_METADATA25( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA24( N - 1))

#define DK_GETTER_METADATA26( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA25( N - 1))

#define DK_GETTER_METADATA27( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA26( N - 1))

#define DK_GETTER_METADATA28( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA27( N - 1))

#define DK_GETTER_METADATA29( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA28( N - 1))

#define DK_GETTER_METADATA30( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA29( N - 1))

#define DK_GETTER_METADATA31( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA30( N - 1))

#define DK_GETTER_METADATA32( N)\
DK_CALL_GETTER( N)	\
DK_EXPAND(DK_GETTER_METADATA31( N - 1))

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

#define DK_CHECK_FOR_PTR_IMPL(fields)															\
template<typename T>																			\
static constexpr bool CheckForPTR() {															\
 if constexpr (drak::types::IsBaseType_V<std::remove_pointer_t<std::remove_all_extents_t<T>>>)	\
	return std::is_pointer_v<T>;																\
 else																							\
	return drak::serialization::MetaData<std::remove_pointer_t<std::remove_all_extents_t<T>>>::	\
	s_hasDynamiclyAllocatedMemory;																\
}

#define DK_CHECK_FOR_PTR0
#define DK_CHECK_FOR_PTR1(t)\
CheckForPTR<TYPEOF(type::t)>()	\

#define DK_CHECK_FOR_PTR2(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR1(__VA_ARGS__))

#define DK_CHECK_FOR_PTR3(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR2(__VA_ARGS__))

#define DK_CHECK_FOR_PTR4(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR3(__VA_ARGS__))

#define DK_CHECK_FOR_PTR5(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR4(__VA_ARGS__))

#define DK_CHECK_FOR_PTR6(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR5(__VA_ARGS__))

#define DK_CHECK_FOR_PTR7(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR6(__VA_ARGS__))

#define DK_CHECK_FOR_PTR8(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR7(__VA_ARGS__))

#define DK_CHECK_FOR_PTR9(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR8(__VA_ARGS__))

#define DK_CHECK_FOR_PTR10(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR9(__VA_ARGS__))

#define DK_CHECK_FOR_PTR11(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR10(__VA_ARGS__))

#define DK_CHECK_FOR_PTR12(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR11(__VA_ARGS__))

#define DK_CHECK_FOR_PTR13(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR12(__VA_ARGS__))

#define DK_CHECK_FOR_PTR14(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR13(__VA_ARGS__))

#define DK_CHECK_FOR_PTR15(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR14(__VA_ARGS__))

#define DK_CHECK_FOR_PTR16(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR15(__VA_ARGS__))

#define DK_CHECK_FOR_PTR17(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR16(__VA_ARGS__))

#define DK_CHECK_FOR_PTR18(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR17(__VA_ARGS__))

#define DK_CHECK_FOR_PTR19(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR18(__VA_ARGS__))

#define DK_CHECK_FOR_PTR20(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR19(__VA_ARGS__))

#define DK_CHECK_FOR_PTR21(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR20(__VA_ARGS__))

#define DK_CHECK_FOR_PTR22(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR21(__VA_ARGS__))

#define DK_CHECK_FOR_PTR23(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR22(__VA_ARGS__))

#define DK_CHECK_FOR_PTR24(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR23(__VA_ARGS__))

#define DK_CHECK_FOR_PTR25(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR24(__VA_ARGS__))

#define DK_CHECK_FOR_PTR26(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR25(__VA_ARGS__))

#define DK_CHECK_FOR_PTR27(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR26(__VA_ARGS__))

#define DK_CHECK_FOR_PTR28(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR27(__VA_ARGS__))

#define DK_CHECK_FOR_PTR29(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR28(__VA_ARGS__))

#define DK_CHECK_FOR_PTR30(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR29(__VA_ARGS__))

#define DK_CHECK_FOR_PTR31(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR30(__VA_ARGS__))

#define DK_CHECK_FOR_PTR32(t, ...)\
CheckForPTR<TYPEOF(type::t)>() | DK_EXPAND(DK_CHECK_FOR_PTR31(__VA_ARGS__))

#define DK_SIZEOF_SERIALIZED_TYPE_IMPL																\
template<typename T>																				\
static constexpr size_t SizeOfSerializedType(){														\
if constexpr(drak::types::IsBaseType_V<std::remove_all_extents_t<T>>)								\
return sizeof(T);																					\
else if constexpr(std::is_array_v<T>)																\
return MetaData<std::remove_all_extents_t<T>>::s_totalSize * drak::types::SizeOfArray_V<T>;			\
else if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<T>> && T::s_serialized)		\
return MetaData<T>::s_totalSize;																	\
else{																								\
Logbook::Log(Logbook::EOutput::BOTH, LOG_FILE,														\
"Cannot get the size of a non serialized object, your object is of type : %s", typeid(T).name());	\
exit(1);																							\
return 0;																							\
}																									\
}

#define DK_SIZEOF_VA_ARGS0
#define DK_SIZEOF_VA_ARGS1(t)\
SizeOfSerializedType<TYPEOF(type::t)>();\

#define DK_SIZEOF_VA_ARGS2(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS1(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS3(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS2(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS4(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS3(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS5(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS4(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS6(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS5(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS7(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS6(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS8(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS7(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS9(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS8(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS10(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS9(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS11(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS10(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS12(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS11(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS13(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS12(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS14(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS13(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS15(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS14(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS16(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS15(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS17(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS16(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS18(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS17(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS19(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS18(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS20(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS19(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS21(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS20(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS22(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS21(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS23(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS22(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS24(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS23(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS25(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS24(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS26(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS25(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS27(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS26(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS28(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS27(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS29(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS28(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS30(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS29(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS31(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS30(__VA_ARGS__))

#define DK_SIZEOF_VA_ARGS32(t, ...)\
SizeOfSerializedType<TYPEOF(type::t)>()	 +\
DK_EXPAND(DK_SIZEOF_VA_ARGS31(__VA_ARGS__))


#define DK_TYPE_NAME_IMPL(t, N)\
if (!strcmp(str, s_varName[N]))	\
	return typeid(TYPEOF(type::t)).name();

#define DK_TYPE_NAME0 return "";
#define DK_TYPE_NAME1(t)\
DK_TYPE_NAME_IMPL(t, 0)	\
DK_TYPE_NAME0

#define DK_TYPE_NAME2(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME1(__VA_ARGS__))

#define DK_TYPE_NAME3(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME2(__VA_ARGS__))

#define DK_TYPE_NAME4(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME3(__VA_ARGS__))

#define DK_TYPE_NAME5(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME4(__VA_ARGS__))

#define DK_TYPE_NAME6(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME5(__VA_ARGS__))

#define DK_TYPE_NAME7(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME6(__VA_ARGS__))

#define DK_TYPE_NAME8(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME7(__VA_ARGS__))

#define DK_TYPE_NAME9(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME8(__VA_ARGS__))

#define DK_TYPE_NAME10(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME9(__VA_ARGS__))

#define DK_TYPE_NAME11(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME10(__VA_ARGS__))

#define DK_TYPE_NAME12(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME11(__VA_ARGS__))

#define DK_TYPE_NAME13(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME12(__VA_ARGS__))

#define DK_TYPE_NAME14(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME13(__VA_ARGS__))

#define DK_TYPE_NAME15(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME14(__VA_ARGS__))

#define DK_TYPE_NAME16(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME15(__VA_ARGS__))

#define DK_TYPE_NAME17(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME16(__VA_ARGS__))

#define DK_TYPE_NAME18(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME17(__VA_ARGS__))

#define DK_TYPE_NAME19(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME18(__VA_ARGS__))

#define DK_TYPE_NAME20(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME19(__VA_ARGS__))

#define DK_TYPE_NAME21(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME20(__VA_ARGS__))

#define DK_TYPE_NAME22(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME21(__VA_ARGS__))

#define DK_TYPE_NAME23(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME22(__VA_ARGS__))

#define DK_TYPE_NAME24(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME23(__VA_ARGS__))

#define DK_TYPE_NAME25(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME24(__VA_ARGS__))

#define DK_TYPE_NAME26(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME25(__VA_ARGS__))

#define DK_TYPE_NAME27(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME26(__VA_ARGS__))

#define DK_TYPE_NAME28(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME27(__VA_ARGS__))

#define DK_TYPE_NAME29(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME28(__VA_ARGS__))

#define DK_TYPE_NAME30(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME29(__VA_ARGS__))

#define DK_TYPE_NAME31(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME30(__VA_ARGS__))

#define DK_TYPE_NAME32(t, ...)					\
DK_TYPE_NAME_IMPL(t, DK_ARGS_N(__VA_ARGS__))	\
DK_EXPAND(DK_TYPE_NAME31(__VA_ARGS__))

#define DK_ADD_TAB(x)			\
for (int i = 0; i < x; ++i)		\
	ss << "\t";

#define DK_ALL_FIELDS_BINARY_DATA_FUNC(fields)							\
template<typename T, int N>\
static void AllFieldBinaryData##fields(std::stringstream& ss, type& t) {\
if constexpr (drak::types::IsBaseType_V<std::remove_all_extents_t<T>>) {\
std::tuple<void*, size_t> binary = fields::get(t, fields::s_varName[N]);								\
for (size_t i = 0; i < std::get<1>(binary); ++i) {							\
		ss << ((const char*)std::get<0>(binary))[i];						\
}																			\
}																			\
else if constexpr (!drak::types::IsBaseType_V<std::remove_all_extents_t<T>> && !std::is_array_v<T>){						\
std::tuple<void*, size_t> binary;\
T obj = t.*(std::get<N>(fields::s_var));						\
for(auto f : MetaData<T>::s_fields) {							\
		for(int idxVar = 0, varN = f->varN(); idxVar < varN; ++idxVar)	{							\
			binary = f->getVar(obj, f->varName(idxVar));											\
			for (size_t i = 0, size = std::get<1>(binary); i < size; ++i)							\
				ss << ((const char*)std::get<0>(binary))[i];										\
		}																							\
	}																								\
}																									\
else {\
std::tuple<void*, size_t> binary;\
for(size_t idx = 0, arraySize = drak::types::SizeOfArray_V<T>; idx < arraySize; ++idx) {	\
	std::remove_all_extents_t<T>& obj = (t.*(std::get<N>(fields::s_var)))[idx];\
	for(auto f : MetaData<std::remove_all_extents_t<T>>::s_fields) {				\
		for(int idxVar = 0, varN = f->varN(); idxVar < varN; ++idxVar)	{							\
			binary = f->getVar(obj, f->varName(idxVar));			\
			for (size_t i = 0, size = std::get<1>(binary); i < size; ++i)							\
				ss << ((const char*)std::get<0>(binary))[i];										\
		}																							\
	}																								\
}																									\
}																									\
}

#define DK_ALL_FIELDS_BINARY_DATA0(fields)\
ss << "\n";					\
DK_ADD_TAB(recursionLevel)	\
ss << "\tEnd " << #fields << "\n";

#define DK_ALL_FIELDS_BINARY_DATA1(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA0(fields)

#define DK_ALL_FIELDS_BINARY_DATA2(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA1(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA3(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA2(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA4(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA3(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA5(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA4(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA6(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA5(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA7(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA6(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA8(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA7(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA9(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA8(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA10(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA9(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA11(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA10(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA12(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA11(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA13(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA12(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA14(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA13(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA15(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA14(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA16(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA15(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA17(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA16(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA18(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA17(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA19(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA18(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA20(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA19(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA21(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA20(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA22(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA21(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA23(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
 DK_ALL_FIELDS_BINARY_DATA22(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA24(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA23(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA25(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA24(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA26(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA25(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA27(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA26(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA28(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA27(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA29(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA28(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA30(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA29(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA31(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
DK_ALL_FIELDS_BINARY_DATA30(fields, N - 1)

#define DK_ALL_FIELDS_BINARY_DATA32(fields, N)	\
AllFieldBinaryData##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N>(ss, t);\
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

#define DK_SERIALIZE_FUNC_BEGIN																	\
template<bool completeDisplay = false>															\
static std::stringstream& serialize(std::stringstream& ss, type& t, int recursionLevel = 0) {	\
DK_ADD_TAB(recursionLevel)																		\
ss << "Class " << typeName() << "\n";

#define DK_SERIALIZE_FUNC_END				\
DK_ADD_TAB(recursionLevel)					\
ss << "End Class " << typeName() << "\n";	\
return ss;									\
}

#define DK_SERIALIZE_FUNC_IN_SERIALIZED_OBJECT(type)									\
template<bool completeDisplay>															\
std::stringstream& type::serialize(std::stringstream& ss) {								\
return drak::serialization::MetaData<type>::serialize<completeDisplay>(ss, *this, 0);	\
}

#define DK_EMPTY_SERIALIZE_FUNCTION_IN_SERIALIZED_OBJECT(type) \
std::stringstream& type::serialize(std::stringstream& ss) {};

#define DK_SERIALIZE_1_FIELDS(fields1)												\
static constexpr std::array<IFields<type>*, 1> s_fields								\
{ (IFields<type>*)&s_fields1 };														\
static constexpr bool s_hasDynamiclyAllocatedMemory =								\
fields1::s_hasDynamiclyAllocatedMemory;												\
static constexpr size_t s_totalSize =													\
fields1::s_totalSize;																	\
DK_SERIALIZE_FUNC_BEGIN																\
serializeLoopPublicFields<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);		\
DK_SERIALIZE_FUNC_END

#define DK_SERIALIZE_2_FIELDS(fields1, fields2)										\
static constexpr std::array<IFields<type>*, 2> s_fields								\
{ (IFields<type>*)&s_fields1, (IFields<type>*)&s_fields2 };				\
static constexpr bool s_hasDynamiclyAllocatedMemory = \
fields1::s_hasDynamiclyAllocatedMemory || \
fields2::s_hasDynamiclyAllocatedMemory; 										\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize;														\
DK_SERIALIZE_FUNC_BEGIN																\
serializeLoopPublicFields<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);	\
serializeLoopPrivateFields<type, fields2::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END

#define DK_SERIALIZE_3_FIELDS(fields1, fields2, fields3)								\
static constexpr std::array<IFields<type>*, 3> s_fields									\
{ (IFields<type>*)&s_fields1, (IFields<type>*)&s_fields2, \
(IFields<type>*)&s_fields3 };												\
static constexpr bool s_hasDynamiclyAllocatedMemory = \
fields1::s_hasDynamiclyAllocatedMemory || \
fields2::s_hasDynamiclyAllocatedMemory || \
fields3::s_hasDynamiclyAllocatedMemory;										\
static constexpr size_t s_totalSize = \
fields1::s_totalSize + \
fields2::s_totalSize + \
fields3::s_totalSize;														\
DK_SERIALIZE_FUNC_BEGIN																	\
serializeLoopPublicFields<type, fields1::s_varN, completeDisplay>(ss, t, recursionLevel);		\
serializeLoopPrivateStaticFields<type, fields2::s_varN, completeDisplay>(ss, t, recursionLevel);	\
serializeLoopPublicStaticFields<type, fields3::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END

#define DK_SERIALIZE_ALL																\
static constexpr std::array<IFields<type>*, 4> s_fields									\
{ (IFields<type>*)&s_PublicFields, (IFields<type>*)&s_PrivateFields,					\
(IFields<type>*)&s_PublicStaticFields, (IFields<type>*)&s_PrivateStaticFields };		\
static constexpr bool s_hasDynamiclyAllocatedMemory =									\
PublicFields::s_hasDynamiclyAllocatedMemory ||											\
PrivateFields::s_hasDynamiclyAllocatedMemory ||											\
PublicStaticFields::s_hasDynamiclyAllocatedMemory ||									\
PrivateStaticFields::s_hasDynamiclyAllocatedMemory;										\
static constexpr size_t s_totalSize =													\
PublicFields::s_totalSize +																\
PrivateFields::s_totalSize +															 \
PublicStaticFields::s_totalSize +														\
PrivateStaticFields::s_totalSize;														\
DK_SERIALIZE_FUNC_BEGIN																	\
	serializeLoopPublicFields<type, PublicFields::s_varN, completeDisplay>(ss, t, recursionLevel);		\
	serializeLoopPrivateFields<type, PrivateFields::s_varN, completeDisplay>(ss, t, recursionLevel);		\
	serializeLoopPublicStaticFields<type, PublicStaticFields::s_varN, completeDisplay>(ss, t, recursionLevel);	\
	serializeLoopPrivateStaticFields<type, PrivateStaticFields::s_varN, completeDisplay>(ss, t, recursionLevel);	\
DK_SERIALIZE_FUNC_END

#define DK_SERIALIZE_PUBLIC_FIELDS													\
DK_SERIALIZE_1_FIELDS(PublicFields)

#define DK_SERIALIZE_PRIVATE_FIELDS													\
DK_SERIALIZE_1_FIELDS(PrivateFields)

#define DK_SERIALIZE_STATIC_PUBLIC_FIELDS												\
DK_SERIALIZE_1_FIELDS(PublicStaticFields)

#define DK_SERIALIZE_STATIC_PRIVATE_FIELDS												\
DK_SERIALIZE_1_FIELDS(PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_PRIVATE_FIELDS											\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateFields)

#define DK_SERIALIZE_STATIC_PUBLIC_PRIVATE_FIELDS										\
DK_SERIALIZE_2_FIELDS(PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS								\
DK_SERIALIZE_2_FIELDS(PublicFields, PublicStaticFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS							\
DK_SERIALIZE_2_FIELDS(PrivateFields, PublicStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS							\
DK_SERIALIZE_2_FIELDS(PublicFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_PRIVATE_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PrivateFields, PrivateStaticFields)

#define DK_SERIALIZE_PUBLIC_FIELDS_AND_STATIC_PUBLIC_FIELDS_AND_PRIVATE_FIELDS			\
DK_SERIALIZE_3_FIELDS(PublicFields, PublicStaticFields, PrivateFields)

#define DK_SERIALIZE_PRIVATE_FIELDS_AND_STATIC_PRIVATE_FIELDS_AND_STATIC_PUBLIC_FIELDS	\
DK_SERIALIZE_3_FIELDS(PrivateFields, PrivateStaticFields, PublicStaticFields)

#define DK_SERIALIZE_LOOP_FUNC(fields, argN)											\
template<typename T, int N, bool completeDisplay = false>								\
static void serializeLoop##fields(std::stringstream& ss, type& t, int recursionLevel) {	\
DK_ADD_TAB(recursionLevel)																\
ss << "\t" << #fields << "\n";															\
if constexpr (!drak::types::IsBaseType_V<T>){											\
if constexpr (MetaData<T>::fields::s_hasDynamiclyAllocatedMemory || completeDisplay) {	\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_LOOP_IMPL, argN)(fields, N - 1))						\
}																						\
else {																					\
DK_ADD_TAB(recursionLevel)																\
ss << "\t\t" << #fields << " Size " << fields::s_totalSize <<							\
" Binary Data ";																		\
DK_ALL_FIELDS_BINARY_DATA(fields, argN)													\
}																						\
}																						\
}

#define DK_SERIALIZE_LOOP_IMPL0(fields)\
DK_ADD_TAB(recursionLevel)	\
ss << "\tEnd " << #fields << "\n";

#define DK_SERIALIZE_LOOP_IMPL1(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL0(fields)

#define DK_SERIALIZE_LOOP_IMPL2(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL1(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL3(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL2(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL4(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL3(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL5(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL4(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL6(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL5(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL7(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL6(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL8(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL7(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL9(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL8(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL10(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL9(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL11(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL10(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL12(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL11(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL13(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL12(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL14(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL13(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL15(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL14(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL16(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL15(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL17(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL16(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL18(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL17(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL19(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL18(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL20(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL19(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL21(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL20(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL22(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL21(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL23(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL22(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL24(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL23(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL25(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL24(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL26(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL25(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL27(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL26(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL28(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL27(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL29(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL28(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL30(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL29(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL31(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL30(fields, N - 1)

#define DK_SERIALIZE_LOOP_IMPL32(fields, N)\
serializeLoopImpl##fields<TYPEOF(t.*(std::get<N>(fields::s_var))), N, completeDisplay>(ss, t, recursionLevel);\
DK_SERIALIZE_LOOP_IMPL31(fields, N - 1)


#define DK_SERIALIZE_LOOP_IMPL_FUNC(fields)															\
template<typename T, int N, bool completeDisplay>													\
static void serializeLoopImpl##fields(std::stringstream& ss, type& t, int recursionLevel) {			\
if constexpr (drak::types::IsBaseType_V<T> ||														\
		(std::is_array_v<T> &&																		\
		drak::types::IsBaseType_V<T>)) {															\
	 std::tuple<void*, size_t> binary{ fields::get(t, fields::s_varName[N]) };						\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " << fields::s_varName[N]			\
	<< " Size " << std::get<1>(binary) <<" Binary Data ";											\
	for (size_t i = 0; i < std::get<1>(binary); ++i) {												\
			ss << ((const char*)std::get<0>(binary))[i];											\
	}																								\
	ss << "\n";																						\
}																									\
else if constexpr (!drak::types::IsBaseType_V<T> &&	std::is_array_v<T>){							\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<								\
	fields::s_varName[N] << " :\n";																	\
for(size_t i = 0, size = drak::types::SizeOfArray_V<T> ; i < size; ++i ) {							\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << "[" << i << "] : \n";															\
	MetaData<std::remove_all_extents_t<T>>::serialize<completeDisplay>								\
		(ss, (t.*(std::get<N>(fields::s_var)))[i], recursionLevel + 2);								\
}																									\
}																									\
else {																								\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<								\
	fields::s_varName[N] << ":\n";																	\
	T  obj{ t.*(std::get<N>(fields::s_var)) };														\
	MetaData<T>::serialize<completeDisplay>															\
		(ss, *(T*)std::get<0>(fields::get(t, fields::s_varName[N])), recursionLevel + 2);			\
}																									\
}

#define DK_NON_SERIALIZED_OBJECT \
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(type)						\
friend drak::serialization::MetaData<type>;				\
static constexpr bool s_serialized = true;				\
public:													\
using MetaData = MetaData<type>;						\
template<bool completeDisplay = false>					\
inline std::stringstream& serialize(std::stringstream& ss);

#define DK_METADATA_BEGIN(ty)								\
template<>													\
struct drak::serialization::MetaData<ty> {					\
using type = ty;											\
static constexpr const char* typeName() { return #ty; };	\
static ty create() { return ty(); };						\
static ty* createNew() { return new ty; };					\
DK_SIZEOF_SERIALIZED_TYPE_IMPL

#define DK_METADATA_FIELDS(fieldName, ...)												\
struct fieldName : public drak::serialization::IFields<type> {							\
DK_GETTER_METADATA_IMPL																	\
DK_CHECK_FOR_PTR_IMPL(fieldName)														\
static constexpr std::array<constexpr const char*, DK_ARGS_N(__VA_ARGS__)> s_varName =	\
{ DK_REVERSE_VA_ARGS(DK_STRINGIZE_VA_ARGS(__VA_ARGS__)) };								\
static constexpr auto s_var =															\
std::make_tuple(DK_REVERSE_VA_ARGS(DK_POINT_MEMBER(__VA_ARGS__)));						\
static constexpr int s_varN = DK_ARGS_N(__VA_ARGS__);									\
static constexpr size_t s_totalSize = DK_SIZEOF_VA_ARGS(__VA_ARGS__);				\
static constexpr bool s_hasDynamiclyAllocatedMemory =									\
DK_CHECK_FOR_PTR(__VA_ARGS__);															\
virtual const char* varName(int idx)override{											\
	return s_varName[idx];																\
};																						\
virtual int varN() override {															\
	return s_varN;																		\
};																						\
virtual size_t totalSizeAllVar() override {												\
	return s_totalSize;															\
};																						\
virtual bool hasDynamiclyAllocatedMemory() override {									\
	return s_hasDynamiclyAllocatedMemory;												\
};																						\
virtual std::tuple<void*, size_t> getVar(type& t, const char* str)override {			\
	DK_GETTER_METADATA(DK_ARGS_N(__VA_ARGS__))											\
}																						\
static std::tuple<void*, size_t> get(type& t, const char* str) {						\
	DK_GETTER_METADATA(DK_ARGS_N(__VA_ARGS__))											\
}																						\
static void set(type& t, const char* str, void* v) {									\
	DK_SETTER_METADATA(s_varName, DK_ARGS_N(__VA_ARGS__))								\
}																						\
static const char* typeNameOf(const char* str){											\
	DK_TYPE_NAME(__VA_ARGS__)															\
}																						\
};																						\
DK_ALL_FIELDS_BINARY_DATA_FUNC(fieldName)												\
DK_SERIALIZE_LOOP_IMPL_FUNC(fieldName)													\
DK_SERIALIZE_LOOP_FUNC(fieldName,  DK_ARGS_N(__VA_ARGS__))								\
static constexpr fieldName s_##fieldName = fieldName();

#define DK_PUBLIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicFields, __VA_ARGS__)

#define DK_PRIVATE_FIELDS(...)\
DK_METADATA_FIELDS(PrivateFields, __VA_ARGS__)

#define DK_PUBLIC_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicStaticFields, __VA_ARGS__)

#define DK_PRIVATE_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PrivateStaticFields, __VA_ARGS__)

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

#define DK_METADATA_END };


#define DK_DESERIALIZE_FUNC_BEGIN							\
static type& deserialize(std::stringstream& ss, type& t) {	\
DK_CHECK_CLASS

#define DK_DESERIALIZE_FUNC1_BEGIN				\
static type deserialize(std::stringstream& ss) {\
DK_CHECK_CLASS




#define DK_CHECK_CLASS															\
std::string str;																\
while (str << ss) {																\
if (str == "Class") {															\
str << ss;																		\
if (str == typeName())															\
break;																			\
else {																			\
Logbook::Log(Logbook::EOutput::BOTH,											\
"Serialization.log",															\
"Bad type passed to MetaData : %s passed but %s should be passed instead !!",	\
str, typeName());																\
exit(1);																		\
}																				\
}																				\
}

#define DK_DESERIALIZE_FUNC_END	\
return t;						\
}

#define DK_DESERIALIZE_LOOP_IMPL(fields, N)															\
if constexpr (drak::types::IsBaseType_V<TYPEOF(t.*(std::get<N>(fields::s_var)))> ||					\
		std::is_array_v<TYPEOF(t.*(std::get<N>(fields::s_var)))>) {									\
	 std::tuple<void*, size_t> binary{ fields::get(t, fields::s_varName[N]) };						\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " << fields::s_varName[N]			\
	<< " Size " << std::get<1>(binary) <<" Binary Data ";											\
	for (size_t i = 0; i < std::get<1>(binary); ++i) {												\
			ss << ((const char*)std::get<0>(binary))[i];											\
	}																								\
	ss << "\n";																						\
}																									\
else {																								\
	DK_ADD_TAB(recursionLevel)																		\
	ss << "\t\t" << fields::typeNameOf(fields::s_varName[N]) << " " <<								\
	fields::s_varName[N] << ":\n";																	\
	TYPEOF(t.*(std::get<N>(fields::s_var))) obj{ t.*(std::get<N>(fields::s_var)) };					\
	MetaData<TYPEOF(obj)>::serialize<completeDisplay>												\
		(ss, *(TYPEOF(obj)*)std::get<0>(fields::get(t, fields::s_varName[N])), recursionLevel + 2);	\
}