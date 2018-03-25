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

#define DK_GETTER_METADATA(varArray, N)	\
DK_EXPAND(DK_CONCAT(DK_GETTER_METADATA, N)(varArray))

#define DK_SETTER_METADATA(varArray, N)	\
DK_EXPAND(DK_CONCAT(DK_SETTER_METADATA, N)(varArray))

#define DK_TYPE_NAME(varArray, type, ...)	\
DK_EXPAND(DK_CONCAT(DK_TYPE_NAME, DK_ARGS_N(__VA_ARGS__))(varArray, type, __VA_ARGS__))

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

#define DK_GETTER_METADATA0(varArray) return nullptr;
#define DK_GETTER_METADATA1(varArray)				\
if (!strcmp(str, ##varArray[0]))		\
	return &(t.*(std::get<0>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA0(varArray))

#define DK_GETTER_METADATA2(varArray)				\
if (!strcmp(str, ##varArray[1]))	\
	return &(t.*(std::get<1>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA1(varArray))

#define DK_GETTER_METADATA3(varArray)				\
if (!strcmp(str, ##varArray[2]))	\
	return &(t.*(std::get<2>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA2(varArray))

#define DK_GETTER_METADATA4(varArray)				\
if (!strcmp(str, ##varArray[3]))	\
	return &(t.*(std::get<3>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA3(varArray))

#define DK_GETTER_METADATA5(varArray)				\
if (!strcmp(str, ##varArray[4]))	\
	return &(t.*(std::get<4>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA4(varArray))

#define DK_GETTER_METADATA6(varArray)				\
if (!strcmp(str, ##varArray[5]))	\
	return &(t.*(std::get<5>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA5(varArray))

#define DK_GETTER_METADATA7(varArray)				\
if (!strcmp(str, ##varArray[6]))	\
	return &(t.*(std::get<6>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA6(varArray))

#define DK_GETTER_METADATA8(varArray)				\
if (!strcmp(str, ##varArray[7]))	\
	return &(t.*(std::get<7>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA7(varArray))

#define DK_GETTER_METADATA9(varArray)				\
if (!strcmp(str, ##varArray[8]))	\
	return &(t.*(std::get<8>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA8(varArray))

#define DK_GETTER_METADATA10(varArray)			\
if (!strcmp(str, ##varArray[9]))	\
	return &(t.*(std::get<9>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA9(varArray))

#define DK_GETTER_METADATA11(varArray)			\
if (!strcmp(str, ##varArray[10]))	\
	return &(t.*(std::get<10>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA10(varArray))

#define DK_GETTER_METADATA12(varArray)			\
if (!strcmp(str, ##varArray[11]))	\
	return &(t.*(std::get<12>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA11(varArray))

#define DK_GETTER_METADATA13(varArray)			\
if (!strcmp(str, ##varArray[12]))	\
	return &(t.*(std::get<12>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA12(varArray))

#define DK_GETTER_METADATA14(varArray)			\
if (!strcmp(str, ##varArray[13]))	\
	return &(t.*(std::get<13>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA13(varArray))

#define DK_GETTER_METADATA15(varArray)			\
if (!strcmp(str, ##varArray[14]))	\
	return &(t.*(std::get<14>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA14(varArray))

#define DK_GETTER_METADATA16(varArray)			\
if (!strcmp(str, ##varArray[15]))	\
	return &(t.*(std::get<15>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA15(varArray))

#define DK_GETTER_METADATA17(varArray)			\
if (!strcmp(str, ##varArray[16]))	\
	return &(t.*(std::get<16>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA16(varArray))

#define DK_GETTER_METADATA18(varArray)			\
if (!strcmp(str, ##varArray[17]))	\
	return &(t.*(std::get<17>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA17(varArray))

#define DK_GETTER_METADATA19(varArray)			\
if (!strcmp(str, ##varArray[18]))	\
	return &(t.*(std::get<18>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA18(varArray))

#define DK_GETTER_METADATA20(varArray)			\
if (!strcmp(str, ##varArray[19]))	\
	return &(t.*(std::get<19>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA19(varArray))

#define DK_GETTER_METADATA21(varArray)			\
if (!strcmp(str, ##varArray[20]))	\
	return &(t.*(std::get<20>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA20(varArray))

#define DK_GETTER_METADATA22(varArray)			\
if (!strcmp(str, ##varArray[21]))	\
	return &(t.*(std::get<21>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA21(varArray))

#define DK_GETTER_METADATA23(varArray)			\
if (!strcmp(str, ##varArray[22]))	\
	return &(t.*(std::get<22>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA22(varArray))

#define DK_GETTER_METADATA24(varArray)			\
if (!strcmp(str, ##varArray[23]))	\
	return &(t.*(std::get<23>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA23(varArray))

#define DK_GETTER_METADATA25(varArray)			\
if (!strcmp(str, ##varArray[24]))	\
	return &(t.*(std::get<24>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA24(varArray))

#define DK_GETTER_METADATA26(varArray)			\
if (!strcmp(str, ##varArray[25]))	\
	return &(t.*(std::get<25>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA25(varArray))

#define DK_GETTER_METADATA27(varArray)			\
if (!strcmp(str, ##varArray[26]))	\
	return &(t.*(std::get<26>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA26(varArray))

#define DK_GETTER_METADATA28(varArray)			\
if (!strcmp(str, ##varArray[27]))	\
	return &(t.*(std::get<27>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA27(varArray))

#define DK_GETTER_METADATA29(varArray)			\
if (!strcmp(str, ##varArray[28]))	\
	return &(t.*(std::get<28>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA28(varArray))

#define DK_GETTER_METADATA30(varArray)			\
if (!strcmp(str, ##varArray[29]))	\
	return &(t.*(std::get<29>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA29(varArray))

#define DK_GETTER_METADATA31(varArray)			\
if (!strcmp(str, ##varArray[30]))	\
	return &(t.*(std::get<30>(s_var)));	\
DK_EXPAND(DK_GETTER_METADATA30(varArray))

#define DK_GETTER_METADATA32(varArray)			\
if (!strcmp(str, ##varArray[31]))	\
	return &(t.*(std::get<31>(s_var)));	\
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

#define DK_TYPE_NAME0
#define DK_TYPE_NAME1(varArray, type, t)					\
if (!strcmp(str, ##varArray[0]))			\
	return typeid(decltype(type::t)).name();	\

#define DK_TYPE_NAME2(varArray, type, t, ...)				\
if (!strcmp(str, ##varArray[1]))			\
	return typeid(decltype(type::t)).name(); 	\
DK_TYPE_NAME1(varArray, type, __VA_ARGS__)

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

#define DK_TYPE_NAME29	(varArray, type, t, ...)			\
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

#define DK_NON_SERIALIZED_OBJECT(Type)		\
static constexpr bool s_serialized = false;

#define DK_SERIALIZED_OBJECT(Type)			\
friend drak::serialization::MetaData<Type>;	\
static constexpr bool s_serialized = true;

#define DK_METADATA(Type)																	\
template<>																					\
struct drak::serialization::MetaData<Type> {												\
static constexpr const char* typeName() { return #Type; };

#define DK_PUBLIC_MEMBERS(Type, ...)														\
struct PublicMembers {																		\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_publicVarName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static void* get(Type& t, const char* str){													\
	DK_GETTER_METADATA(s_publicVarName, DK_ARGS_N(__VA_ARGS__))								\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_publicVarName, DK_ARGS_N(__VA_ARGS__))								\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_publicVarName, Type, __VA_ARGS__)										\
}																							\
};																							\
static constexpr bool hasPublicMembers = false;

#define DK_PRIVATE_MEMBERS(Type, ...)														\
struct PrivateMembers {																		\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_privateVarName =			\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static void* get(Type& t, const char* str){													\
	DK_GETTER_METADATA(s_privateVarName, DK_ARGS_N(__VA_ARGS__))							\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_privateVarName, DK_ARGS_N(__VA_ARGS__))							\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_privateVarName, Type, __VA_ARGS__)										\
}																							\
};																							\
static constexpr bool hasPrivateMembers = true;

#define DK_PUBLIC_STATIC_MEMBERS(Type, ...)													\
struct StaticPublicMembers {																\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_staticPublicVarName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static void* get(Type& t, const char* str){													\
	DK_GETTER_METADATA(s_staticPublicVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_staticPublicVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_staticPublicVarName, Type, __VA_ARGS__)									\
}																							\
};																							\
static constexpr bool hasStaticPublicMembers = true;

#define DK_PRIVATE_STATIC_MEMBERS(Type, ...)												\
struct StaticPrivateMembers {																\
static constexpr std::array<const char*, DK_ARGS_N(__VA_ARGS__)> s_staticPrivateVarName =	\
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };														\
static constexpr auto s_var = std::make_tuple(DK_POINT_MEMBER(Type, __VA_ARGS__));			\
static constexpr size_t s_varNb = DK_ARGS_N(__VA_ARGS__);									\
static void* get(Type& t, const char* str){													\
	DK_GETTER_METADATA(s_staticPrivateVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static void set(Type& t, const char* str, void* v){											\
	DK_SETTER_METADATA(s_staticPrivateVarName, DK_ARGS_N(__VA_ARGS__))						\
}																							\
static const char* typeNameOf(const char* str){												\
	DK_TYPE_NAME(s_staticPrivateVarName, Type, __VA_ARGS__)									\
}																							\
};																							\
static constexpr bool hasStaticPrivateMembers = true;

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


#define DK_EMPTY_METADATA(Type)																\
template<>																					\
struct drak::serialization::MetaData<Type> {												\
static constexpr const char* typeName() { return #Type; };									\
DK_EMPTY_PUBLIC_MEMBERS																		\
DK_EMPTY_PRIVATE_MEMBERS																	\
DK_EMPTY_PUBLIC_STATIC_MEMBERS																\
DK_EMPTY_PRIVATE_STATIC_MEMBERS																\
DK_EMPTY_PUBLIC_METHODE																		\
DK_EMPTY_PRIVATE_METHODE																	\
DK_EMPTY_PUBLIC_STATIC_METHODE																\
DK_EMPTY_PRIVATE_STATIC_METHODE																\
};

#define DK_EMPTY_PUBLIC_MEMBERS																\
static constexpr bool hasPublicMembers = false;
#define DK_EMPTY_PRIVATE_MEMBERS															\
static constexpr bool hasPrivateMembers = false;
#define DK_EMPTY_PUBLIC_STATIC_MEMBERS														\
static constexpr bool hasStaticPublicMembers = false;
#define DK_EMPTY_PRIVATE_STATIC_MEMBERS														\
static constexpr bool hasStaticPrivateMembers = false;
#define DK_EMPTY_PUBLIC_METHODE																\
static constexpr bool hasPublicMethode = false;
#define DK_EMPTY_PRIVATE_METHODE															\
static constexpr bool hasPrivateMethode = false;
#define DK_EMPTY_PUBLIC_STATIC_METHODE														\
static constexpr bool hasStaticPublicMethode = false;
#define DK_EMPTY_PRIVATE_STATIC_METHODE														\
static constexpr bool hasStaticPrivateMethode = false;
