#pragma once

#include <Core/Engine/Error.hpp>
#include <Serialization/MetaData.hpp>
#include <map>

namespace drak {
namespace serialization {

struct Serializer {
	template<class T, EExtension ext>
	static drak::core::E_Error SerializeToFile(const T& t, const char* path, const char* filename);

	template<class T, EExtension ext>
	static drak::core::E_Error SerializeToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<EExtension ext, class T, class...VArgs>
	static drak::core::E_Error SerializeToFile(const char* path, const char* filename, const T& t, VArgs&&...args);

	template<class T, EExtension ext>
	static drak::core::E_Error AddObjectToFile(const T& t, const char* path);

	template<class T, EExtension ext>
	static drak::core::E_Error AddObjectToFile(const std::vector<T>& t, const char* path);

	template<EExtension ext, class T, class...VArgs>
	static drak::core::E_Error AddObjectToFile(const char* path, const T& t, VArgs&&...args);

	template<class T, EExtension ext>
	static std::tuple<T, drak::core::E_Error> LoadFromFile(const char* path);

	template<class T, EExtension ext>
	static drak::core::E_Error LoadFromFile(const char* path, T& t);

	template<class T, EExtension ext>
	static drak::core::E_Error LoadEveryFromFile(const char* path, std::vector<T>& t);

	template<class T, EExtension ext>
	static std::tuple<std::vector<T>, drak::core::E_Error> LoadEveryFromFile(const char* path);

	template<EExtension ext, class T, class...VArgs>
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
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr,
		FileDescriptor& desc, const T& t, VArgs&&...args);
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr,
		FileDescriptor& desc) {};
	template<class T, class...VArgs>
	static void LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
		std::map<std::string, int>& occurence,  T& t, VArgs&&...args);
	static void LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
		std::map<std::string, int>& occurence) {};
	template<class T, class...VArgs>
	static void Occurence(std::map<std::string, int>& occurence, const T& t, VArgs&&...args);
	static void Occurence(std::map<std::string, int>& occurence) {};
};

} // namespace serialization
} // namepsace drak
#include <Serialization/Serializer.inl>