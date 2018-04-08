#pragma once

#include <Core/Engine/Types.hpp>
#include <Core/Engine/TypeTraits.hpp>
#include <Core/Utils/MacroUtils.hpp>

#include <tuple>

#include <Serialization/SerializationUtils.hpp>
#include <Serialization/ReflectionUtils.hpp>

namespace drak {
namespace serialization {

DK_ENUM_CLASS(EExtension, U8, BINARY, JSON, INI)

template<typename T>
struct MetaData {};

template<typename T>
struct IFields {
	virtual const char* varName(int idx) = 0;
	virtual int varN() = 0;
	virtual size_t totalSizeAllVar() = 0;
	virtual std::tuple<void*, size_t> getVar(T& t, const char* name) = 0;
	virtual bool setVar(T& t, const char* name, void* data) = 0;
};

template<typename T>
static constexpr size_t SizeOfSerializedType() {
	if constexpr(drak::types::IsBaseType_V<T> && !std::is_pointer_v<T>)
		return sizeof(T);
	else if constexpr (drak::types::IsBaseType_V<T> && std::is_pointer_v<T>)
		return sizeof(std::remove_pointer_t<T>) + 1;
	else if constexpr(std::is_array_v<T>)
		return MetaData<std::remove_all_extents_t<T>>::s_staticSize * drak::types::SizeOfArray_V<T>;
	else if constexpr (std::is_pointer_v<T>)
		return MetaData<std::remove_pointer_t<T>>::s_staticSize + 1;
	else if constexpr (std::is_same_v<T, std::string> || !std::is_same_v<T, drak::types::VectorType_T<T>>)
		return 0;
	else
		return MetaData<T>::s_staticSize;
}

template<typename T>
static size_t SizeOfDynamiclyAllocatedType(const T& t) {
	if constexpr (std::is_same_v<T, std::string>)
		return t.size() + sizeof(size_t);
	else if constexpr (!std::is_same_v<T, drak::types::VectorType_T<T>>) {
		size_t size = sizeof(size_t);
		for (auto& x : t) {
			size += SizeOfSerializedType<drak::types::VectorType_T<T>>() +
				SizeOfDynamiclyAllocatedType<drak::types::VectorType_T<T>>(x);
		}
		return size;
	}
	else
		return 0;
}

template<typename T>
static std::string ValueToString(const T& value) {
	if constexpr(drak::types::IsBaseType_V<T>)
		return std::to_string(value);
}

template<typename T>
static void StringToValue(const char* c_str, T& t) {
	if constexpr(std::is_same_v<T, bool>) {
		if (!strcmp(c_str, "true") || !strcmp(c_str, "True") || !strcmp(c_str, "1"))
			t = true;
		else
			t = false;
	}
	else if constexpr (std::is_same_v<T, std::string> ||
		std::is_same_v<std::remove_cv_t<T>, char*>) {
		t = T(c_str);
	}
	else if constexpr (std::is_same_v<T, U16>)
		t = T(std::stoul(c_str));
	else if constexpr (std::is_same_v<T, I16>)
		t = T(std::stoi(c_str));
	else if constexpr (std::is_same_v<T, U32>)
		t = T(std::stoul(c_str));
	else if constexpr (std::is_same_v<T, I32>)
		t = T(std::stoi(c_str));
	else if constexpr (std::is_same_v<T, U64>)
		t = T(std::stoull(c_str));
	else if constexpr (std::is_same_v<T, I64>)
		t = T(std::stoll(c_str));
	else if constexpr (std::is_same_v<T, F32>)
		t = T(std::stof(c_str));
	else if constexpr (std::is_same_v<T, F64>)
		t = T(std::stod(c_str));
}

} // namespace serialization
} // namespace drak

#define FACTORY_PATTERN										\
static type Create() { return type(); };					\
static type* CreateNew() { return new type(); };			\
static type Create(const char* c_str) {						\
	type t;													\
	SetBinary(t, c_str);									\
	return t;												\
}															\
static type* CreateNew(const char* c_str) {					\
	type* t = new type;										\
	SetBinary(*t, c_str);									\
	return t;												\
}

#define DK_METADATA_BEGIN(ty)								\
template<>													\
struct drak::serialization::MetaData<ty> {					\
using type = ty;											\
static constexpr const char* TypeName() { return #ty; };

#define DK_METADATA_END																			\
FACTORY_PATTERN																					\
static bool AreEqual(const type& t1, const type& t2) {											\
std::tuple<char*, size_t> binary1 = GetBinary(t1), binary2 = GetBinary(t2);						\
bool res = std::get<1>(GetBinary(t1)) == std::get<1>(GetBinary(t2)) &&							\
!strcmp(std::get<0>(GetBinary(t1)), std::get<0>(GetBinary(t2)));								\
delete[] std::get<0>(GetBinary(t1));															\
delete[] std::get<0>(GetBinary(t2));															\
return res;																						\
}																								\
static bool AreNotEqual(const type& t1, const type& t2) {										\
return !AreEqual(t1, t2);																		\
}																								\
};

#define DK_METADATA_FIELDS(fieldName, ...)												\
struct fieldName : public drak::serialization::IFields<type> {							\
private:																				\
DK_DATA_STRUCT()																		\
DK_SET_DATA()																			\
DK_GET_DATA()																			\
public:																					\
DK_EXPAND(DK_NAME_ARRAY(__VA_ARGS__))													\
DK_EXPAND(DK_MEMBER_TUPLE(__VA_ARGS__))													\
DK_EXPAND(DK_STATIC_SIZE(__VA_ARGS__))													\
DK_EXPAND(DK_TOTAL_SIZE(__VA_ARGS__))													\
DK_EXPAND(DK_GET_BY_NAME(__VA_ARGS__))													\
DK_EXPAND(DK_SET_BY_NAME(__VA_ARGS__))													\
DK_EXPAND(DK_GET_SIZE_BY_NAME(__VA_ARGS__))												\
DK_EXPAND(DK_GET_TYPENAME_BY_NAME(__VA_ARGS__))											\
DK_EXPAND(DK_SET_EVERY_DATA_FUNC(__VA_ARGS__))											\
DK_EXPAND(DK_FIELD_BINARY_FUNC(__VA_ARGS__))											\
DK_EXPAND(DK_FIELD_TO_JSON_FUNC(__VA_ARGS__))											\
DK_FIELD_SERIALIZATION																	\
static constexpr int s_varN = DK_ARGS_N(__VA_ARGS__);									\
virtual const char* varName(int idx)override{											\
	return s_varName[idx];																\
};																						\
virtual int varN() override {															\
	return s_varN;																		\
};																						\
virtual size_t totalSizeAllVar() override {												\
	return s_staticSize;																\
};																						\
virtual std::tuple<void*, size_t> getVar(type& t, const char* str)override {			\
	DK_EXPAND(DK_CONCAT(DK_GET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
}																						\
virtual bool setVar(type& t, const char* name, void* data) override {					\
	DK_EXPAND(DK_CONCAT(DK_SET_DATA, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))				\
	return false;																		\
}																						\
};																						\
public :																				\
static constexpr fieldName s_##fieldName = fieldName();

#define DK_PUBLIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicFields, __VA_ARGS__)

#define DK_PRIVATE_FIELDS(...)\
DK_METADATA_FIELDS(PrivateFields, __VA_ARGS__)

#define DK_PUBLIC_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PublicStaticFields, __VA_ARGS__)

#define DK_PRIVATE_STATIC_FIELDS(...)\
DK_METADATA_FIELDS(PrivateStaticFields, __VA_ARGS__)

#define DK_PUBLIC_FIELD_COMPLEMENT					\
DK_METADATA_FIELD_SERIALIZATION(PublicFields)		\
DK_METADATA_GET_BY_NAME(PublicFields)				\
DK_METADATA_SET_BY_NAME(PublicFields)				\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields)

#define DK_PRIVATE_FIELD_COMPLEMENT						\
DK_METADATA_FIELD_SERIALIZATION(PrivateFields)			\
DK_METADATA_GET_BY_NAME(PrivateFields)					\
DK_METADATA_SET_BY_NAME(PrivateFields)					\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PrivateFields)

#define DK_PUBLIC_STATIC_FIELD_COMPLEMENT					\
DK_METADATA_FIELD_SERIALIZATION(PublicStaticFields)			\
DK_METADATA_GET_BY_NAME(PublicStaticFields)					\
DK_METADATA_SET_BY_NAME(PublicStaticFields)					\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicStaticFields)

#define DK_PRIVATE_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PrivateStaticFields)

#define DK_PUBLIC_AND_PRIVATE_FIELD_COMPLEMENT					\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PrivateFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PrivateFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PrivateFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PrivateFields)

#define DK_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PublicStaticFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicStaticFields, PrivateStaticFields)

#define DK_PUBLIC_AND_PUBLIC_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PublicStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PublicStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PublicStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PublicStaticFields)

#define DK_PRIVATE_AND_PRIVATE_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PrivateFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PrivateFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PrivateFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PrivateFields, PrivateStaticFields)

#define DK_PRIVATE_AND_PUBLIC_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PrivateFields, PublicStaticFields)	\
DK_METADATA_GET_BY_NAME(PrivateFields, PublicStaticFields)			\
DK_METADATA_SET_BY_NAME(PrivateFields, PublicStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PrivateFields, PublicStaticFields)

#define DK_PUBLIC_AND_PRIVATE_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PrivateStaticFields)

#define DK_PUBLIC_AND_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELD_COMPLEMENT					\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PublicStaticFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PublicStaticFields, PrivateStaticFields)

#define DK_PUBLIC_AND_PRIVATE_AND_PRIVATE_STATIC_FIELD_COMPLEMENT					\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PrivateFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PrivateFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PrivateFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PrivateFields, PrivateStaticFields)

#define DK_PUBLIC_AND_PUBLIC_STATIC_AND_PRIVATE_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PublicStaticFields, PrivateFields)\
DK_METADATA_GET_BY_NAME(PublicFields, PublicStaticFields, PrivateFields)		\
DK_METADATA_SET_BY_NAME(PublicFields, PublicStaticFields, PrivateFields)		\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PublicStaticFields, PrivateFields)

#define DK_PRIVATE_AND_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELD_COMPLEMENT				\
DK_METADATA_FIELD_SERIALIZATION(PrivateFields, PublicStaticFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PrivateFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PrivateFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PrivateFields, PublicStaticFields, PrivateStaticFields)

#define DK_PUBLIC_PRIVATE_AND_PUBLIC_STATIC_AND_PRIVATE_STATIC_FIELD_COMPLEMENT							\
DK_METADATA_FIELD_SERIALIZATION(PublicFields, PrivateFields, PublicStaticFields, PrivateStaticFields)	\
DK_METADATA_GET_BY_NAME(PublicFields, PrivateFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_SET_BY_NAME(PublicFields, PrivateFields, PublicStaticFields, PrivateStaticFields)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(PublicFields, PrivateFields, PublicStaticFields, PrivateStaticFields)

#define DK_FIELD_COMPLEMENT(...)				\
DK_METADATA_FIELD_SERIALIZATION(__VA_ARGS__)	\
DK_METADATA_GET_BY_NAME(__VA_ARGS__)			\
DK_METADATA_SET_BY_NAME(__VA_ARGS__)			\
DK_METADATA_FIELD_ADDITIONAL_INFORMATION(__VA_ARGS__)