#pragma once

#include <Serialization/SerializationUtils.hpp>

namespace drak {
namespace serialization {

struct Serializer {
	template<class T>
	static void SerializeToFile(T& t, const char* path, const char* filename);

	template<class T>
	static void SerializeToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<class T, class...VArgs>
	static void SerializeToFile(const char* path, const char* filename, T& t, VArgs&&...args);

	template<class T>
	static void AddObjectToFile(T& t, const char* path, const char* filename);

	template<class T>
	static void AddObjectToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<class T, class...VArgs>
	static void AddObjectToFile(const char* path, const char* filename, T& t, VArgs&&...args);

	template<class T>
	static T LoadFromFile(const char* path, const char* filename, const char* className);

	template<class T>
	static void LoadFromFile(const char* path, const char* filename, T& t);

	template<class T>
	static void LoadEveryFromFile(const char* path, const char* filename, std::vector<T>& t);

	template<class T>
	static std::vector<T> LoadEveryFromFile(const char* path, const char* filename, const char* className);

	template<class T, class...VArgs>
	static void LoadFromFile(const char* path, const char* filename, T& t, VArgs&&...args);

private:
	template<class T, class...VArgs>
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr, T& t, VArgs&&...args);
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr) {};
	static void SerializeToFile(const char* path, const char* filename) {};

	template<class T, class...VArgs>
	static void AddObjectToFile(std::fstream& file, std::stringstream& sstr, T& t, VArgs&&...args);
	static void AddObjectToFile(std::fstream& file, std::stringstream& sstr) {};
	static void AddObjectToFile(const char* path, const char* filename) {};
};

} // namespace serialization
} // namepsace drak
#include <Serialization/Serializer.inl>