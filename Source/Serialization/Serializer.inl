#include <Serialization/Serializer.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <fstream>

namespace drak {
namespace serialization {

template<class T>
void Serializer::SerializeToFile(T& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		std::map<std::string, std::pair<int, int>> fileDescriptor;
		fileDescriptor[MetaData<T>::typeName] = { 1, 0 };
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T>
void Serializer::SerializeToFile(const std::vector<T>& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (auto& x : t)
			MetaData<T>::serialize(binary, t);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T, class ...VArgs>
void Serializer::SerializeToFile(const char* path, const char* filename, T& t, VArgs&& ...args) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		if constexpr (static_cast<bool>(sizeof...(VArgs)))
			SerializeToFile(file, binary, std::forward<VArgs>(args)...);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T>
void Serializer::AddObjectToFile(T& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary | std::ios::app);
	if (file.is_open()) {
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T>
void Serializer::AddObjectToFile(const std::vector<T>& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary | std::ios::app);
	if (file.is_open()) {
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (auto& x : t)
			MetaData<T>::serialize(binary, t);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T, class ...VArgs>
void Serializer::AddObjectToFile(const char* path, const char* filename, T& t, VArgs&& ...args) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary | std::ios::app);
	if (file.is_open()) {
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		if constexpr (static_cast<bool>(sizeof...(VArgs)))
			AddObjectToFile(file, binary, std::forward<VArgs>(args)...);
		file << binary.rdbuf();
		file.close();
	}
}

template<class T>
T Serializer::LoadFromFile(const char* path, const char* filename, const char* className) {
	return T();
}

template<class T>
void Serializer::LoadFromFile(const char* path, const char* filename, T& t) {
}

template<class T>
void Serializer::LoadEveryFromFile(const char* path, const char* filename, std::vector<T>& t) {
}

template<class T>
std::vector<T> Serializer::LoadEveryFromFile(const char* path, const char* filename, const char* className) {
	return std::vector<T>();
}

template<class T, class ...VArgs>
void Serializer::LoadFromFile(const char* path, const char* filename, T& t, VArgs&& ...args) {
}

template<class T, class ...VArgs>
void Serializer::SerializeToFile(std::fstream& file, std::stringstream& sstr, T& t, VArgs&& ...args) {
	MetaData<T>::serialize(sstr, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile(file, sstr, std::forward<VArgs>(args)...);
}

template<class T, class ...VArgs>
void Serializer::AddObjectToFile(std::fstream& file, std::stringstream& sstr, T& t, VArgs&& ...args) {
	MetaData<T>::serialize(binary, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		AddObjectToFile(file, sstr, std::forward<VArgs>(args)...);
}

} // namespace serialization
} // namepsace drak
