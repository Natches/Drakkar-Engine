#pragma once

#define LOG_FILE "Serialization.log"

#include <Core/Utils/VA_ArgsUtils.hpp>
#include <Log/Log.hpp>
#include <string>
#include <sstream>
#include <vector>

#define DK_ADD_TAB(x)			\
for (int i = 0; i < x; ++i)		\
  sstr << "\t";


#define DK_DATA_STRUCT()																		\
template<typename T>																			\
struct BaseType {																				\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		sstr.read((char*)&t, sizeof(T));														\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		std::string str;																		\
		str.reserve(sizeof(T));																	\
		return str.insert(0, (char*)&(t), sizeof(T));											\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		return std::string("\"") + ValueToString<T>(t) + "\"";									\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		std::string str;																		\
		sstr >> str;																			\
		str.erase(std::remove(str.begin(), str.end(), '"'), str.end());							\
		StringToValue<T>(str.c_str(), t);														\
	}																							\
	static std::string SerializeToINI(const T& t) {												\
		return ValueToString<T>(t);																\
	}																							\
	static void DeserializeINI(T& t, std::stringstream& sstr) {									\
		std::string str;																		\
		sstr >> str;																			\
		StringToValue<T>(str.c_str(), t);														\
	}																							\
};																								\
template<typename Type, size_t N>																\
struct BaseType<Type[N]> {																		\
	using T = Type[N];																			\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		sstr.read((char*)t, sizeof(T));															\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		std::string str;																		\
		str.reserve(sizeof(T));																	\
		str.insert(0, (char*)t, sizeof(T));														\
		return str;																				\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		std::string str("[\n");																	\
		for(size_t i = 0; i < N; ++i){															\
			for(int i2 = 0; i2 < indent; ++i2)													\
				str += '\t';																	\
			str += BaseType<Type>::SerializeToJSON(t[i], indent + 1);							\
			str += ",\n";																		\
		}																						\
		str.erase(str.end() - 2);																\
		indent -= 1;																			\
		for(int i = 0; i < indent; ++i)															\
			str += '\t';																		\
		str += "]";																				\
		return str;																				\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		std::string str;																		\
		while (str != std::string("["))sstr >> str;												\
		for(size_t i = 0; i < N; ++i) {															\
			sstr >> str;																		\
			str.erase(std::remove(str.begin(), str.end(), '"'), str.end());						\
			StringToValue<Type>(str.c_str(), t[i]);												\
		}																						\
		sstr >> str;																			\
	}																							\
	static std::string SerializeToINI(const T& t) {												\
		std::string str("{ ");																	\
		for(size_t i = 0; i < N; ++i){															\
			str += BaseType<Type>::SerializeToINI(t[i]);										\
			str += ", ";																		\
		}																						\
		str.erase(str.end() - 2);																\
		str += " }";																			\
		return str;																				\
	}																							\
	static void DeserializeINI(T& t, std::stringstream& sstr) {									\
		std::string str;																		\
		sstr >> str;																			\
		for(size_t i = 0; i < N; ++i) {															\
			sstr >> str;																		\
			str.erase(std::remove(str.begin(), str.end(), ','), str.end());						\
			StringToValue<Type>(str.c_str(), t[i]);												\
		}																						\
		sstr >> str;																			\
	}																							\
};																								\
template<typename Type>																			\
struct BaseType<Type*> {																		\
	using T = Type*;																			\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		char isAllocated;																		\
		sstr.read(&isAllocated, sizeof(char));													\
		if(isAllocated){																		\
			t = new Type();																		\
			sstr.read((char*)t, sizeof(Type));													\
		}																						\
		else																					\
			t = nullptr;																		\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		if (static_cast<bool>(t)) {																\
			std::string str;																	\
			str.reserve(sizeof(Type) + 1);														\
			str.append(static_cast<char>(1), sizeof(char));										\
			str.append((const char*)t, sizeof(Type));											\
			return str;																			\
		}																						\
		else																					\
			return std::string("\0", 1);														\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		if(t)																					\
			return std::string("\"") + ValueToString<Type>(*t) + "\"";							\
		else																					\
			return std::string("\"null\"");														\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		std::string str;																		\
		sstr >> str;																			\
		str.erase(std::remove(str.begin(), str.end(), '"'), str.end());							\
		str.erase(std::remove(str.begin(), str.end(), ','), str.end());							\
		StringToValue<T>(str.c_str(), t);														\
	}																							\
	static std::string SerializeToINI(const T& t) {												\
		if(t)																					\
			return ValueToString<Type>(*t);														\
		else																					\
			return std::string("null");															\
	}																							\
	static void DeserializeINI(T& t, std::stringstream& sstr) {									\
		std::string str;																		\
		sstr >> str;																			\
		StringToValue<T>(str.c_str(), t);														\
	}																							\
};																								\
template<typename T>																			\
struct ComplexType {																			\
	using MetaData = MetaData<T>;																\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		MetaData::Deserialize<EExtension::BINARY>(t, sstr);										\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		std::string str;																		\
		str.reserve(MetaData::ComputeTotalSize(t));												\
		std::stringstream sstr;																	\
		str.append(MetaData::Serialize<EExtension::BINARY>(t, sstr).str());						\
		return str;																				\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		std::stringstream sstr;																	\
		return MetaData::Serialize<EExtension::JSON>(t, sstr, indent).str();					\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		MetaData::Deserialize<EExtension::JSON>(t, sstr);										\
	}																							\
};																								\
template<typename Type, size_t N>																\
struct ComplexType<Type[N]> {																	\
	using T = Type[N];																			\
	using MetaData = MetaData<Type>;															\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		for(int i = 0, size = drak::types::SizeOfArray_V<T>; i < size; ++i)						\
			MetaData::Deserialize<EExtension::BINARY>(t[i], sstr);								\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		std::string str;																		\
		size_t totalArraySize = 0;																\
		for (auto& x : t)																		\
			totalArraySize += MetaData::ComputeTotalSize(x);									\
		str.reserve(totalArraySize);															\
		std::stringstream sstr;																	\
		for(int i = 0, size = SizeOfArray_V<T>; i < size; ++i)									\
			str.append																			\
				(MetaData::Serialize<EExtension::BINARY>(t[i], sstr).str());					\
		return str;																				\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		std::string str("[\n");																	\
		for(size_t i = 0; i < N; ++i){															\
			for(int i2 = 0; i2 < indent; ++i2)													\
				str += '\t';																	\
			std::stringstream sstr;																\
			str += MetaData::Serialize<EExtension::JSON>										\
				(t[i], sstr, indent + 1);														\
			str += ",\n";																		\
		}																						\
		str.erase(str.end() - 2);																\
		indent -= 1;																			\
		for(int i = 0; i < indent; ++i)															\
			str += '\t';																		\
		str += "]";																				\
		return str;																				\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		std::string str;																		\
		for(size_t i = 0; i < N; ++i) {															\
			MetaData::Deserialize<EExtension::JSON>(t[i], sstr);								\
		}																						\
		sstr >> str;																			\
	}																							\
};																								\
template<typename Type>																			\
struct ComplexType<Type*> {																		\
	using T = Type*;																			\
	using MetaData = MetaData<Type>;															\
	static void DeserializeBinary(T& t, std::stringstream& sstr) {								\
		char isAllocated;																		\
		sstr.read(&isAllocated, sizeof(char));													\
		if (isAllocated) {																		\
			t = new Type();																		\
			MetaData::Deserialize<EExtension::BINARY>(*t, sstr);								\
		}																						\
		else																					\
			t = nullptr;																		\
	}																							\
	static std::string SerializeToBinary(const T& t) {											\
		if(static_cast<bool>(t)) {																\
			std::string str;																	\
			str.reserve(MetaData::ComputeTotalSize(*t) + 1);									\
			str.append(static_cast<char>(1), sizeof(char));										\
			std::stringstream sstr;																\
			str.append(MetaData::Serialize<EExtension::BINARY>(*t, sstr).str());				\
			return str;																			\
		}																						\
		else																					\
			return std::string("\0", 1);														\
	}																							\
	static std::string SerializeToJSON(const T& t, int indent) {								\
		if(static_cast<bool>(t)) {																\
		std::stringstream sstr;																	\
			return MetaData::Serialize<EExtension::JSON>										\
				(*t, sstr, indent).str();														\
		}																						\
		else																					\
			return std::string("\"null\"");														\
	}																							\
	static void DeserializeJSON(T& t, std::stringstream& sstr) {								\
		std::string str;																		\
		sstr >> str;																			\
		if(str != "\"null\"" && str != "\"nill\"" &&											\
			str != "\"null\"," && str != "\"nill\",")	{										\
			sstr.seekg(-(int)str.size(), std::ios::cur);										\
			t = new Type();																		\
			MetaData::Deserialize<EExtension::JSON>(*t, sstr);									\
		}																						\
		else																					\
			t = nullptr;																		\
	}																							\
};

#define DK_SET_DATA()																			\
template<typename T>																			\
static void DeserializeBinaryToVector(std::vector<T>& t, std::stringstream& sstr) {				\
	size_t size;																				\
	sstr.read((char*)&size, sizeof(size_t));													\
	t.reserve(size);																			\
	for(int i = 0; i < size; ++i) {																\
		T data;																					\
		DeserializeBinary(data, sstr);															\
		t.emplace_back(data);																	\
	}																							\
}																								\
template<typename T>																			\
static void DeserializeJSONToVector(std::vector<T>& t, std::stringstream& sstr) {				\
	std::string str;																			\
	sstr >> str;																				\
	sstr >> str;																				\
	while (str != "]" && str != "],") {															\
		sstr.seekg(-(int)str.size(), std::ios::cur);											\
		T data;																					\
		DeserializeJSON(data, sstr);															\
		t.emplace_back(data);																	\
		sstr >> str;																			\
	}																							\
}																								\
static void DeserializeBinaryToString(std::string& t, std::stringstream& sstr) {				\
	t.clear();																					\
	size_t size;																				\
	sstr.read((char*)&size, sizeof(size_t));													\
	t.insert(0, sstr.str().c_str() + sstr.tellg(), size);										\
	sstr.seekg(size, std::ios::cur);															\
}																								\
static std::stringstream& DeserializeJSONToString(std::string& t, std::stringstream& sstr) {	\
	sstr >> t;																					\
	t.erase(std::remove(t.begin(), t.end(), '"'), t.end());										\
	t.erase(std::remove(t.begin(), t.end(), ','), t.end());										\
	return sstr;																				\
}																								\
template<typename T, typename U>																\
static void DeserializeJSONToIntrin(T& t, std::stringstream& sstr) {							\
	U arr[sizeof(T) / 4] = {};																	\
	BaseType<U[sizeof(T) / 4]>::DeserializeJSON(arr, sstr);										\
	memcpy(&t, arr, sizeof(T));																	\
}																								\
template<typename T, typename U>																\
static void DeserializeINIToIntrin(T& t, std::stringstream& sstr) {								\
	U arr[sizeof(T) / 4] = {};																	\
	BaseType<U[sizeof(T) / 4]>::DeserializeINI(arr, sstr);										\
	memcpy(&t, arr, sizeof(T));																	\
}																								\
template<typename T>																			\
static void DeserializeBinaryToPair(T& p, std::stringstream& sstr) {							\
	DeserializeBinary(p.first, sstr);															\
	DeserializeBinary(p.second, sstr);															\
}																								\
template<typename T, typename U>																\
static void DeserializeBinaryToMap(std::map<T, U>& m, std::stringstream& sstr) {				\
	size_t size;																				\
	sstr.read((char*)&size, sizeof(size_t));													\
	std::pair<T, U> p;																			\
	for(size_t i = 0; i < size; ++i) {															\
		DeserializeBinaryToPair(p, sstr);														\
		m.insert(p);																			\
	}																							\
}																								\
template<typename T, typename U>																\
static void DeserializeBinaryToUnorderedMap														\
	(std::unordered_map<T, U>& um, std::stringstream& sstr) {									\
	size_t size;																				\
	sstr.read((char*)&size, sizeof(size_t));													\
	std::pair<T, U> p;																			\
	for(size_t i = 0; i < size; ++i) {															\
		DeserializeBinaryToPair(p, sstr);														\
		um.insert(p);																			\
	}																							\
}																								\
template<typename T>																			\
static void DeserializeJSONToPair(T& p, std::stringstream& sstr) {								\
	std::string str;																			\
	while (str != "{") sstr >> str;																\
	while (str != "}" && str != "},") {															\
		DeserializeJSON(p.first, sstr);															\
		DeserializeJSON(p.second, sstr);														\
		sstr >> str;																			\
	}																							\
}																								\
template<typename T, typename U>																\
static void DeserializeJSONToMap(std::map<T, U>& m, std::stringstream& sstr) {					\
	std::string str;																			\
	std::pair<T, U> p;																			\
	sstr >> str;																				\
	sstr >> str;																				\
	while (str != "]" && str != "],") {															\
		sstr.seekg(-(int)str.size(), std::ios::cur);											\
		DeserializeJSONToPair(p, sstr);															\
		m.insert(p);																			\
		sstr >> str;																			\
	}																							\
}																								\
template<typename T, typename U>																\
static void DeserializeJSONToUnorderedMap														\
	(std::unordered_map<T, U>& um, std::stringstream& sstr) {									\
	std::string str;																			\
	std::pair<T, U> p;																			\
	sstr >> str;																				\
	sstr >> str;																				\
	while (str != "]" && str != "],") {															\
		sstr.seekg(-(int)str.size(), std::ios::cur);											\
		DeserializeJSONToPair(p, sstr);															\
		um.insert(p);																			\
		sstr >> str;																			\
	}																							\
}																								\
template<typename T>																			\
static void DeserializeBinary(T& t, std::stringstream& sstr) {									\
	if constexpr (drak::types::IsBaseType_V<T>)													\
		BaseType<T>::DeserializeBinary(t, sstr);												\
	else if constexpr (drak::types::IsVector_V<T>)												\
		DeserializeBinaryToVector(t, sstr);														\
	else if constexpr (std::is_same_v<T, std::string>)											\
		DeserializeBinaryToString(t, sstr);														\
	else if constexpr (drak::types::IsMap_V<T>)													\
		DeserializeBinaryToMap(t, sstr);														\
	else if constexpr (drak::types::IsUnorderedMap_V<T>)										\
		DeserializeBinaryToUnorderedMap(t, sstr);												\
	else if constexpr (drak::types::IsPair_V<T>)												\
		DeserializeBinaryToPair(t, sstr);														\
	else if constexpr(!drak::types::IsBaseType_V<T>)											\
		ComplexType<T>::DeserializeBinary(t, sstr);												\
}																								\
template<typename T>																			\
static void DeserializeJSON(T& t, std::stringstream& sstr) {									\
	if constexpr (drak::types::IsBaseType_V<T> && !drak::types::IsIntrinType_V<T>)				\
		BaseType<T>::DeserializeJSON(t, sstr);													\
	else if constexpr (drak::types::IsIntrinType_V<T>) {										\
		if constexpr (std::is_same_v<T, __m64> ||												\
			std::is_same_v<T, __m128> || std::is_same_v<T, __m256>)								\
			DeserializeJSONToIntrin<T, F32>(t, sstr);											\
		else if constexpr (std::is_same_v<T, __m128i> ||										\
			std::is_same_v<T, __m256i>)															\
			DeserializeJSONToIntrin<T, I32>(t, sstr);											\
	}																							\
	else if constexpr (drak::types::IsVector_V<T>)												\
		DeserializeJSONToVector(t, sstr);														\
	else if constexpr (std::is_same_v<T, std::string>)											\
		DeserializeJSONToString(t, sstr);														\
	else if constexpr (drak::types::IsMap_V<T>)													\
		DeserializeJSONToMap(t, sstr);															\
	else if constexpr (drak::types::IsUnorderedMap_V<T>)										\
		DeserializeJSONToUnorderedMap(t, sstr);													\
	else if constexpr (drak::types::IsPair_V<T>)												\
		DeserializeJSONToPair(t, sstr);															\
	else if constexpr(!drak::types::IsBaseType_V<T>)											\
		ComplexType<T>::DeserializeJSON(t, sstr);												\
}																								\
template<typename T>																			\
static void DeserializeINI(T& t, std::stringstream& sstr) {										\
	if constexpr (drak::types::IsBaseType_V<T> && !drak::types::IsIntrinType_V<T>) {			\
		BaseType<T>::DeserializeINI(t, sstr);													\
	}																							\
	else if constexpr (drak::types::IsIntrinType_V<T>) {										\
		if constexpr (std::is_same_v<T, __m64> ||												\
			std::is_same_v<T, __m128> || std::is_same_v<T, __m256>)								\
			DeserializeINIToIntrin<T, F32>(t, sstr);											\
		else if constexpr (std::is_same_v<T, __m128i> ||										\
			std::is_same_v<T, __m256i>)															\
			DeserializeINIToIntrin<T, I32>(t, sstr);											\
	}																							\
	else if constexpr (std::is_same_v<T, std::string>) {										\
		sstr >> t;																				\
	}																							\
}

#define DK_GET_DATA()															\
static std::string SerializeStringToBinary(const std::string& s) {				\
	size_t size = s.size();														\
	std::string temp = s;														\
	temp.insert(0, (char*)&size, sizeof(size_t));								\
	return temp;																\
}																				\
static std::string SerializeStringToJSON(const std::string& s) {				\
	return std::string("\"") + s + "\"";										\
}																				\
template<typename T>															\
static std::string SerializeVectorToBinary(const T& t) {						\
	size_t size = t.size(), size2 = 0;											\
	std::string data;															\
	data.reserve(t.size() + sizeof(size_t));									\
	data.insert(0, (char*)&size, sizeof(size_t));								\
	for(auto& x : t)															\
		data.append(SerializeToBinary<TYPEOF(x)>(x));							\
	return data;																\
}																				\
template<typename T>															\
static std::string SerializeVectorToJSON(const T& t, int indent) {				\
	std::string str("[\n");														\
	str.reserve(SizeOfDynamiclyAllocatedType<T>(t));							\
	for(auto& x : t) {															\
		for (int i = 0; i < indent; ++i)										\
			str += '\t';														\
		str += SerializeToJSON(x, indent + 1);									\
		str += ",\n";															\
	}																			\
	if(t.size())																\
		str.erase(str.end() - 2);												\
	indent -= 1;																\
	for(int i = 0; i < indent; ++i)												\
		str += '\t';															\
	str += "]";																	\
	return str;																	\
}																				\
template<typename T, typename U>												\
static std::string SerializeIntrinToJSON(const T& t, int indent) {				\
	std::string str("[\n");														\
	for (int i = 0, size = sizeof(T) / 4; i < size; ++i) {						\
		for (int i2 = 0; i2 < indent; ++i2)										\
			str += '\t';														\
		str += BaseType<U>::SerializeToJSON(*((U*)(&t) + i), indent);			\
		str += ",\n";															\
	}																			\
	str.erase(str.end() - 2);													\
	indent -= 1;																\
	for (int i = 0; i < indent; ++i)											\
		str += '\t';															\
	str += "]";																	\
	return str;																	\
}																				\
template<typename T, typename U>												\
static std::string SerializeIntrinToINI(const T& t) {							\
	std::string str("{ ");														\
	for (int i = 0, size = sizeof(T) / 4; i < size; ++i) {						\
		str += BaseType<U>::SerializeToINI(*((U*)(&t) + i));					\
		str += ", ";															\
	}																			\
	str.erase(str.end() - 2);													\
	str += " }\n";																\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializePairToBinary(const T& p) {							\
	std::string str;															\
	str.append(SerializeToBinary(p.first));										\
	str.append(SerializeToBinary(p.second));									\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializeMapToBinary(const T& m) {							\
	std::string str;															\
	size_t size = m.size();														\
	str.append((char*)&size, sizeof(size_t));									\
	for(auto& pair : m)															\
		str.append(SerializePairToBinary(pair));								\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializeUnorderedMapToBinary								\
	(const T& m) {																\
	std::string str;															\
	size_t size = m.size();														\
	str.append((char*)&size, sizeof(size_t));									\
	for(auto& pair : m)															\
		str.append(SerializePairToBinary(pair));								\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializePairToJSON(const T& p, int indent) {				\
	std::string str(typeid(T).name());											\
	str.append(": {\n");														\
	for (int i = 0; i < indent; ++i)											\
		str += '\t';															\
	str.append(SerializeToJSON(p.first, indent));								\
	str.append(",\n");															\
	for (int i = 0; i < indent; ++i)											\
		str += '\t';															\
	str.append(SerializeToJSON(p.second, indent));								\
	str.append("\n");															\
	for (int i = 0; i < indent - 1; ++i)										\
		str += '\t';															\
	str.append("}");															\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializeMapToJSON(const T& m, int indent) {					\
	std::string str("[\n");														\
	for(auto& pair : m)	{														\
		for (int i = 0; i < indent; ++i)										\
		str += '\t';															\
		str.append(SerializePairToJSON(pair, indent + 1));						\
		str.append(",\n");														\
	}																			\
	str.erase(str.end() - 2);													\
	for (int i = 0; i < indent - 1; ++i)										\
		str += '\t';															\
	str.append("]");															\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializeUnorderedMapToJSON									\
	(const T& m, int indent) {													\
	std::string str("[\n");														\
	for(auto& pair : m)	{														\
		for (int i = 0; i < indent; ++i)										\
		str += '\t';															\
		str.append(SerializePairToJSON(pair, indent + 1));						\
		str.append(",\n");														\
	}																			\
	str.erase(str.end() - 2);													\
	for (int i = 0; i < indent - 1; ++i)										\
		str += '\t';															\
	str.append("]");															\
	return str;																	\
}																				\
template<typename T>															\
static std::string SerializeToBinary(const T& t) {								\
	if constexpr (drak::types::IsBaseType_V<T>)									\
		return BaseType<T>::SerializeToBinary(t);								\
	else if constexpr(std::is_same_v<T, std::string>)							\
		return SerializeStringToBinary(t);										\
	else if constexpr (drak::types::IsVector_V<T>)								\
		return SerializeVectorToBinary(t);										\
	else if constexpr (drak::types::IsMap_V<T>)									\
		return SerializeMapToBinary(t);											\
	else if constexpr (drak::types::IsUnorderedMap_V<T>)						\
		return SerializeUnorderedMapToBinary(t);								\
	else if constexpr (drak::types::IsPair_V<T>)								\
		return SerializePairToBinary(t);										\
	else if constexpr(!drak::types::IsBaseType_V<T>)							\
		return ComplexType<T>::SerializeToBinary(t);							\
}																				\
template<typename T>															\
static std::string SerializeToJSON(const T& t, int indent) {					\
	if constexpr (drak::types::IsBaseType_V<T> &&								\
		!drak::types::IsIntrinType_V<T>)										\
		return BaseType<T>::SerializeToJSON(t, indent);							\
	else if constexpr (drak::types::IsIntrinType_V<T>) {						\
		if constexpr (std::is_same_v<T, __m64> ||								\
			std::is_same_v<T, __m128> || std::is_same_v<T, __m256>)				\
			return SerializeIntrinToJSON<T, F32>(t, indent);					\
		else if constexpr (std::is_same_v<T, __m128i> ||						\
			std::is_same_v<T, __m256i>)											\
			return SerializeIntrinToJSON<T, I32>(t, indent);					\
	}																			\
	else if constexpr(std::is_same_v<T, std::string>)							\
		return SerializeStringToJSON(t);										\
	else if constexpr (drak::types::IsVector_V<T>)								\
		return SerializeVectorToJSON(t, indent);								\
	else if constexpr (drak::types::IsMap_V<T>)									\
		return SerializeMapToJSON(t, indent);									\
	else if constexpr (drak::types::IsUnorderedMap_V<T>)						\
		return SerializeUnorderedMapToJSON(t, indent);							\
	else if constexpr (drak::types::IsPair_V<T>)								\
		return SerializePairToJSON(t, indent);									\
	else if constexpr(!drak::types::IsBaseType_V<T>)							\
		return ComplexType<T>::SerializeToJSON(t, indent);						\
}																				\
template<typename T>															\
static std::string SerializeToINI(const T& t) {									\
	if constexpr (drak::types::IsBaseType_V<T> &&								\
		!drak::types::IsIntrinType_V<T>) {										\
		return BaseType<T>::SerializeToINI(t);									\
	}																			\
	else if constexpr (drak::types::IsIntrinType_V<T>) {						\
		if constexpr (std::is_same_v<T, __m64> ||								\
			std::is_same_v<T, __m128> || std::is_same_v<T, __m256>)				\
			return SerializeIntrinToINI<T, F32>(t);								\
		else if constexpr (std::is_same_v<T, __m128i> ||						\
			std::is_same_v<T, __m256i>)											\
			return SerializeIntrinToINI<T, I32>(t);								\
	}																			\
	else if constexpr(std::is_same_v<T, std::string>) {							\
		return t;																\
	}																			\
	else																		\
		return "";																\
}

#define DK_FIELD_SERIALIZATION																	\
static std::stringstream& SerializeToBinary(const type& t, std::stringstream& sstr) {			\
	std::string data = SerializeToBinary(t);													\
	sstr.write(data.c_str(), data.size());														\
	return sstr;																				\
}																								\
static std::stringstream& SerializeToJSON(const type& t, std::stringstream& sstr,				\
	int indent = 1) {																			\
	sstr << SerializeToJSON(t, indent);															\
	return sstr;																				\
}																								\
static std::stringstream& SerializeToINI(const type& t, std::stringstream& sstr) {				\
	sstr << SerializeToINI(t);																	\
	return sstr;																				\
}																								\
template<EExtension ext>																		\
static std::stringstream& Serialize(const type& t, std::stringstream& sstr, int indent = 0) {	\
	switch (ext) {																				\
		case EExtension::BINARY :																\
			SerializeToBinary(t, sstr);															\
			break;																				\
		case EExtension::JSON :																	\
			SerializeToJSON(t, sstr, indent);													\
			break;																				\
		case EExtension::INI :																	\
			SerializeToINI(t, sstr);															\
			break;																				\
		default:																				\
			break;																				\
	}																							\
return sstr;																					\
}																								\
template<EExtension ext>																		\
static type& Deserialize(type& t, std::stringstream& sstr) {									\
switch (ext) {																					\
		case EExtension::BINARY :																\
			DeserializeBinary(t, sstr);															\
			break;																				\
		case EExtension::JSON :																	\
			DeserializeJSON(t, sstr);															\
			break;																				\
		case EExtension::INI :																	\
			DeserializeINI(t, sstr);															\
			break;																				\
		default:																				\
			break;																				\
	}																							\
	return t;																					\
}																								\

#define DK_DESERIALIZE_JSON_TO_FIELD_FUNC(...)													\
static type& DeserializeJSON(type& t, std::stringstream& sstr) {								\
	std::string name;																			\
	sstr >> name;																				\
	while (name != "}" && name != "},") {														\
		name.erase(std::remove(name.begin(), name.end(), '"'), name.end());						\
		name.erase(std::remove(name.begin(), name.end(), ':'), name.end());						\
		DK_EXPAND(DK_CONCAT(DK_DESERIALIZE_JSON_TO_FIELD, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
		sstr >> name;																			\
	}																							\
	return t;																					\
}

#define DK_DESERIALIZE_INI_TO_FIELD_FUNC(...)													\
static type& DeserializeINI(type& t, std::stringstream& sstr) {									\
	std::string str;																			\
	sstr >> str;																				\
	while (str[0] != ';' && !sstr.eof()) {														\
		std::string name;																		\
		int postEqual = 0;																		\
		for(; str[postEqual] != '=' ; ++postEqual)												\
			name += str[postEqual];																\
		++postEqual;																			\
		DK_EXPAND(DK_CONCAT(DK_DESERIALIZE_INI_TO_FIELD, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
		sstr >> str;																			\
	}																							\
	if(!sstr.eof())																				\
		sstr.seekg(-(int)str.size(), std::ios::cur);											\
	return t;																					\
}

#define DK_SERIALIZED_OBJECT(type)												\
friend drak::serialization::MetaData<type>;										\
static constexpr bool s_serialized = true;										\
public:																			\
using MetaData = drak::serialization::MetaData<type>;							\
template<drak::serialization::EExtension OutType>								\
std::stringstream& Serialize(std::stringstream& sstr) {							\
return MetaData::Serialize<OutType>(*this, sstr);								\
}																				\
template<drak::serialization::EExtension OutType>								\
std::stringstream Serialize() {													\
std::stringstream sstr;															\
return MetaData::Serialize<OutType>(*this, sstr);								\
}																				\
template<drak::serialization::EExtension OutType>								\
void Deserialize(std::stringstream& sstr) {										\
	 MetaData::Deserialize<OutType>(*this, sstr);								\
}

#define DK_DESERIALIZE_FUNC_END	\
return t;						\
}

#define DK_DESERIALIZE_BINARY_TO_FIELD_FUNC(...)											\
static void DeserializeBinary(type& t, std::stringstream& sstr) {							\
DK_EXPAND(DK_CONCAT(DK_DESERIALIZE_BINARY_TO_FIELD, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
}

#define DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)	\
DeserializeBinary<TYPEOF(t.ty)>(t.ty, sstr);

#define DK_DESERIALIZE_BINARY_TO_FIELD0
#define DK_DESERIALIZE_BINARY_TO_FIELD1(ty)					\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)

#define DK_DESERIALIZE_BINARY_TO_FIELD2(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD1(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD3(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD2(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD4(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD3(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD5(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD4(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD6(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD5(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD7(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD6(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD8(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD7(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD9(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD8(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD10(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD9(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD11(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD10(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD12(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD11(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD13(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD12(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD14(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD13(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD15(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD14(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD16(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD15(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD17(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD16(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD18(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD17(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD19(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD18(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD20(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD19(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD21(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD20(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD22(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD21(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD23(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD22(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD24(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD23(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD25(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD24(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD26(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD25(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD27(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD26(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD28(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD27(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD29(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD28(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD30(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD29(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD31(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD30(__VA_ARGS__))

#define DK_DESERIALIZE_BINARY_TO_FIELD32(ty, ...)			\
DK_DESERIALIZE_BINARY_TO_FIELD_IMPL(ty)						\
DK_EXPAND(DK_DESERIALIZE_BINARY_TO_FIELD31(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_FUNC(...)												\
static std::string SerializeToBinary(const type& t) {										\
	std::string data;																		\
	data.reserve(ComputeTotalSize(t));														\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_FIELD_TO_BINARY_IMPL, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))\
	return data;																			\
}

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL(ty)				\
data.append(SerializeToBinary<TYPEOF(t.ty)>(t.ty));

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL0

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL1(t)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL2(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL1(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL3(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL2(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL4(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL3(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL5(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL4(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL6(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL5(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL7(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL6(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL8(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL7(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL9(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL8(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL10(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL9(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL11(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL10(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL12(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL11(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL13(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL12(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL14(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL13(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL15(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL14(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL16(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL15(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL17(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL16(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL18(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL17(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL19(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL18(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL20(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL19(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL21(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL20(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL22(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL21(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL23(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL22(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL24(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL23(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL25(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL24(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL26(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL25(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL27(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL26(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL28(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL27(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL29(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL28(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL30(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL29(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL31(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL30(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_BINARY_IMPL32(t, ...)\
DK_SERIALIZE_FIELD_TO_BINARY_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_BINARY_IMPL31(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON_FUNC(...)											\
static std::string SerializeToJSON(const type& t, int indent) {							\
std::string str;																		\
for(int i = 0; i < indent; ++i)															\
		str += '\t';																	\
(str  += FieldName) += ": {\n";															\
indent += 1;																			\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_FIELD_TO_JSON, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))	\
for(int i = 0; i < indent - 1; ++i)														\
		str += '\t';																	\
str += "}\n";																			\
return str;																				\
}

#define DK_SERIALIZE_FIELD_TO_JSON_IMPL(ty)					\
for(int i = 0; i < indent; ++i)						\
		str += '\t';								\
str += "\""#ty"\": ";								\
str += SerializeToJSON<TYPEOF(t.ty)>(t.ty, indent + 1) + ",\n";	\

#define DK_SERIALIZE_FIELD_TO_JSON0

#define DK_SERIALIZE_FIELD_TO_JSON1(ty)				\
for(int i = 0; i < indent; ++i)				\
		str += '\t';						\
str += "\""#ty"\": ";						\
str += SerializeToJSON<TYPEOF(t.ty)>(t.ty, indent + 1) + '\n';

#define DK_SERIALIZE_FIELD_TO_JSON2(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON1(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON3(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON2(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON4(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON3(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON5(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON4(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON6(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON5(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON7(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON6(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON8(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON7(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON9(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON8(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON10(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON9(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON11(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON10(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON12(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON11(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON13(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON12(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON14(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON13(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON15(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON14(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON16(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON15(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON17(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON16(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON18(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON17(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON19(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON18(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON20(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON19(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON21(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON20(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON22(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON21(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON23(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON22(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON24(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON23(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON25(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON24(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON26(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON25(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON27(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON26(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON28(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON27(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON29(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON28(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON30(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON29(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON31(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON30(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_JSON32(t, ...)\
DK_SERIALIZE_FIELD_TO_JSON_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_JSON31(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD_IMPL(ty)					\
if(name == std::string(#ty))						\
	DeserializeJSON(t.ty, sstr);						\
else

#define DK_DESERIALIZE_JSON_TO_FIELD0	\
Logbook::Log(Logbook::EOutput::CONSOLE, nullptr, (name + "is not a variable of this Class !!\n").c_str());

#define DK_DESERIALIZE_JSON_TO_FIELD1(t)				\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)					\
DK_DESERIALIZE_JSON_TO_FIELD0

#define DK_DESERIALIZE_JSON_TO_FIELD2(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD1(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD3(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD2(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD4(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD3(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD5(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD4(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD6(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD5(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD7(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD6(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD8(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD7(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD9(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD8(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD10(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD9(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD11(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD10(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD12(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD11(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD13(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD12(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD14(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD13(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD15(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD14(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD16(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD15(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD17(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD16(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD18(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD17(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD19(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD18(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD20(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD19(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD21(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD20(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD22(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD21(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD23(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD22(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD24(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD23(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD25(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD24(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD26(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD25(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD27(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD26(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD28(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD27(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD29(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD28(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD30(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD29(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD31(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD30(__VA_ARGS__))

#define DK_DESERIALIZE_JSON_TO_FIELD32(t, ...)\
DK_DESERIALIZE_JSON_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_JSON_TO_FIELD31(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI_FUNC(...)													\
static std::string SerializeToINI(const type& t) {											\
std::string str;																	\
((str  += ";") += FieldName) += '\n';												\
bool atLeastOne = false;															\
DK_EXPAND(DK_CONCAT(DK_SERIALIZE_FIELD_TO_INI, DK_ARGS_N(__VA_ARGS__))(__VA_ARGS__))			\
return str;																			\
}

#define DK_SERIALIZE_FIELD_TO_INI_IMPL(ty)										\
if constexpr (drak::types::IsBaseType_V<TYPEOF(t.ty)> ||				\
std::is_same_v<TYPEOF(t.ty), std::string>){								\
	atLeastOne = true;													\
	str += #ty"=";														\
	str += SerializeToINI<TYPEOF(t.ty)>(t.ty) + "\n";							\
}
#define DK_SERIALIZE_FIELD_TO_INI0	\
if(!atLeastOne)				\
	return "";

#define DK_SERIALIZE_FIELD_TO_INI1(t)				\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)					\
DK_SERIALIZE_FIELD_TO_INI0

#define DK_SERIALIZE_FIELD_TO_INI2(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI1(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI3(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI2(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI4(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI3(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI5(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI4(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI6(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI5(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI7(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI6(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI8(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI7(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI9(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI8(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI10(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI9(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI11(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI10(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI12(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI11(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI13(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI12(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI14(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI13(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI15(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI14(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI16(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI15(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI17(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI16(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI18(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI17(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI19(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI18(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI20(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI19(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI21(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI20(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI22(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI21(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI23(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI22(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI24(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI23(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI25(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI24(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI26(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI25(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI27(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI26(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI28(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI27(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI29(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI28(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI30(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI29(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI31(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI30(__VA_ARGS__))

#define DK_SERIALIZE_FIELD_TO_INI32(t, ...)\
DK_SERIALIZE_FIELD_TO_INI_IMPL(t)	\
DK_EXPAND(DK_SERIALIZE_FIELD_TO_INI31(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD_IMPL(ty)								\
if(name == std::string(#ty)){									\
	sstr.seekg(-((int)(str.size()) - postEqual), std::ios::cur);\
	DeserializeINI(t.ty, sstr);										\
}																\
else

#define DK_DESERIALIZE_INI_TO_FIELD0	\
Logbook::Log(Logbook::EOutput::CONSOLE, nullptr, (name + "is not a variable of this Class !!\n").c_str());

#define DK_DESERIALIZE_INI_TO_FIELD1(t)				\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)					\
DK_DESERIALIZE_INI_TO_FIELD0

#define DK_DESERIALIZE_INI_TO_FIELD2(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD1(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD3(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD2(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD4(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD3(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD5(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD4(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD6(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD5(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD7(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD6(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD8(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD7(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD9(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD8(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD10(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD9(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD11(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD10(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD12(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD11(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD13(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD12(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD14(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD13(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD15(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD14(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD16(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD15(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD17(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD16(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD18(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD17(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD19(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD18(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD20(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD19(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD21(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD20(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD22(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD21(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD23(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD22(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD24(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD23(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD25(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD24(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD26(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD25(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD27(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD26(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD28(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD27(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD29(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD28(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD30(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD29(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD31(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD30(__VA_ARGS__))

#define DK_DESERIALIZE_INI_TO_FIELD32(t, ...)\
DK_DESERIALIZE_INI_TO_FIELD_IMPL(t)	\
DK_EXPAND(DK_DESERIALIZE_INI_TO_FIELD31(__VA_ARGS__))

/*
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
{ DK_STRINGIZE_VA_ARGS(__VA_ARGS__) };*/