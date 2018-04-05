#pragma once

#include <Core/Engine/Error.hpp>
#include <Serialization/SerializationUtils.hpp>
#include <map>

namespace drak {
namespace serialization {

struct Serializer {
	template<class T>
	static void SerializeToFile(const T& t, const char* path, const char* filename);

	template<class T>
	static void SerializeToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<class T, class...VArgs>
	static void SerializeToFile(const char* path, const char* filename, const T& t, VArgs&&...args);

	template<class T>
	static void AddObjectToFile(const T& t, const char* path);

	template<class T>
	static void AddObjectToFile(const std::vector<T>& t, const char* path);

	template<class T, class...VArgs>
	static void AddObjectToFile(const char* path, const T& t, VArgs&&...args);

	template<class T>
	static std::tuple<T, drak::core::E_Error> LoadFromFile(const char* path);

	template<class T>
	static drak::core::E_Error LoadFromFile(const char* path, T& t);

	template<class T>
	static drak::core::E_Error LoadEveryFromFile(const char* path, std::vector<T>& t);

	template<class T>
	static std::tuple<std::vector<T>, drak::core::E_Error> LoadEveryFromFile(const char* path);

	template<class T, class...VArgs>
	static drak::core::E_Error LoadFromFile(const char* path, T& t, VArgs&&...args);

private:
	struct FileDescriptor {
		void writeToFile(std::fstream& file);
		void loadFromFile(std::fstream& file);
		void seekToBeginingOfClass(std::fstream& file);
		std::map<std::pair<std::string, int>, int> m_descriptor;
		int m_endPos;
	};

	template<class T, class...VArgs>
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr, FileDescriptor& desc, const T& t, VArgs&&...args);
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr, FileDescriptor& desc) {};
};

} // namespace serialization
} // namepsace drak
#include <Serialization/Serializer.inl>