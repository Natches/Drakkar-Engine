#pragma once

#include <Core/Engine/Error.hpp>
#include <Serialization/MetaData.hpp>

namespace drak {
namespace serialization {

struct Serializer {
	template<EExtension ext, class T, bool addExtension = true>
	static core::EError SerializeToFile(const T& t, const char* path, const char* filename);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError SerializeToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<EExtension ext, bool addExtension, class T, class...VArgs>
	static core::EError SerializeToFile(const char* path, const char* filename, const T& t, VArgs&&...args);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError AddObjectToFile(const T& t, const char* path);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError AddObjectToFile(const std::vector<T>& t, const char* path);

	template<EExtension ext, bool addExtension, class T, class...VArgs>
	static core::EError AddObjectToFile(const char* path, const T& t, VArgs&&...args);

	template<EExtension ext, class T, bool addExtension = true>
	static std::tuple<T, core::EError> LoadFromFile(const char* path);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError LoadFromFile(T& t, const char* path);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError LoadEveryFromFile(std::vector<T>& t, const char* path);

	template<EExtension ext, class T, bool addExtension = true>
	static std::tuple<std::vector<T>, core::EError> LoadEveryFromFile(const char* path);

	template<EExtension ext, bool addExtension, class T, class...VArgs>
	static core::EError LoadFromFile(const char* path, T& t, VArgs&&...args);

	template<EExtension ext, class T, bool addExtension = true>
	static core::EError Contain(const char* path, U32& count);

private:
	struct FileDescriptor {
		void writeToFile(std::fstream& file);
		void loadFromFile(std::fstream& file);
		void seekToBeginingOfClass(std::fstream& file);
		std::map<std::pair<std::string, int>, int> m_descriptor;
		int m_endPos;
	};

	template<EExtension ext, class T, class...VArgs>
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr,
		FileDescriptor& desc, const T& t, VArgs&&...args);
	static void SerializeToFile(std::fstream& file, std::stringstream& sstr,
		FileDescriptor& desc) {};

	template<EExtension ext, class T, class...VArgs>
	static void SerializeToFileNoDesc(std::fstream& file, std::stringstream& sstr,
		const T& t, VArgs&&...args);
	static void SerializeToFileNoDesc(std::fstream& file, std::stringstream& sstr) {};

	template<EExtension ext, class T, class...VArgs>
	static void LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
		std::map<std::string, int>& occurence,  T& t, VArgs&&...args);
	static void LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
		std::map<std::string, int>& occurence) {};

	template<class T, class...VArgs>
	static void Occurence(std::map<std::string, int>& occurence, const T& t, VArgs&&...args);
	static void Occurence(std::map<std::string, int>& occurence) {};

	template<class T>
	static core::EError SerializeToINI(const T& t, const char* path, const char* filename);
	template<class T>
	static core::EError SerializeToINI(const std::vector<T>& t, const char* path, const char* filename);
	template<class T, class...VArgs>
	static core::EError SerializeToINI(const char* path, const char* filename, const T& t, VArgs&&...args);
	template<class T>
	static core::EError AddToINI(const T& t, const char* path);
	template<class T>
	static core::EError AddToINI(const std::vector<T>& t, const char* path);
	template<class T, class...VArgs>
	static core::EError AddToINI(const char* path, const T& t, VArgs&&...args);
	template<class T>
	static core::EError LoadFromINI(T& t, const char* path);
	template<class T>
	static core::EError LoadFromINI(std::vector<T>& t, const char* path);
	template<EExtension ext, class T, class...VArgs>
	static core::EError LoadFromINI(const char* path, T& t, VArgs&&...args);

	template<class T>
	static core::EError SerializeToJSON(const T& t, const char* path, const char* filename);
	template<class T>
	static core::EError LoadFromJSON(T& t, const char* path);

	template<class T>
	static core::EError SerializeToBinary(const T& t, const char* path, const char* filename);
	template<class T>
	static core::EError SerializeToBinary(const std::vector<T>& t, const char* path, const char* filename);
	template<class T, class...VArgs>
	static core::EError SerializeToBinary(const char* path, const char* filename, const T& t, VArgs&&...args);
	template<class T>
	static core::EError AddToBinary(const T& t, const char* path);
	template<class T>
	static core::EError AddToBinary(const std::vector<T>& t, const char* path);
	template<class T, class...VArgs>
	static core::EError AddToBinary(const char* path, const T& t, VArgs&&...args);
	template<class T>
	static core::EError LoadFromBinary(T& t, const char* path);
	template<class T>
	static core::EError LoadFromBinary(std::vector<T>& t, const char* path);
	template<EExtension ext, class T, class...VArgs>
	static core::EError LoadFromBinary(const char* path, T& t, VArgs&&...args);

	template<typename T>
	static core::EError ContainBinary(const char* path, U32& count);

	template<typename T>
	static core::EError ContainJSON(const char* path);

	template<typename T>
	static core::EError ContainINI(const char* path, U32& count);
};

} // namespace serialization
} // namespace drak
#include <Serialization/Serializer.inl>