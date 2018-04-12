#pragma once

#include <Core/Engine/Error.hpp>
#include <Serialization/MetaData.hpp>
#include <map>

namespace drak {
namespace serialization {

struct Serializer {
	template<EExtension ext, class T>
	static core::EError SerializeToFile(const T& t, const char* path, const char* filename);

	template<EExtension ext, class T>
	static core::EError SerializeToFile(const std::vector<T>& t, const char* path, const char* filename);

	template<EExtension ext, class T, class...VArgs>
	static core::EError SerializeToFile(const char* path, const char* filename, const T& t, VArgs&&...args);

	template<EExtension ext, class T>
	static core::EError AddObjectToFile(const T& t, const char* path);

	template<EExtension ext, class T>
	static core::EError AddObjectToFile(const std::vector<T>& t, const char* path);

	template<EExtension ext, class T, class...VArgs>
	static core::EError AddObjectToFile(const char* path, const T& t, VArgs&&...args);

	template<EExtension ext, class T>
	static std::tuple<T, core::EError> LoadFile(const char* path);

	template<EExtension ext, class T>
	static core::EError LoadFile(T& t, const char* path);

	template<EExtension ext, class T>
	static core::EError LoadEveryFile(std::vector<T>& t, const char* path);

	template<EExtension ext, class T>
	static std::tuple<std::vector<T>, core::EError> LoadEveryFile(const char* path);

	template<EExtension ext, class T, class...VArgs>
	static core::EError LoadFile(const char* path, T& t, VArgs&&...args);

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

	template<class T, class...VArgs>
	static void LoadFile(std::stringstream& sstr, FileDescriptor& desc,
		std::map<std::string, int>& occurence,  T& t, VArgs&&...args);
	static void LoadFile(std::stringstream& sstr, FileDescriptor& desc,
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
	static core::EError AddSerializeToINI(const T& t, const char* path);
	template<class T>
	static core::EError AddSerializeToINI(const std::vector<T>& t, const char* path);
	template<class T, class...VArgs>
	static core::EError AddSerializeToINI(const char* path, const T& t, VArgs&&...args);
	template<class T>
	static core::EError LoadINI(T& t, const char* path);
	template<class T>
	static core::EError LoadINI(std::vector<T>& t, const char* path);
	template<EExtension ext, class T, class...VArgs>
	static core::EError LoadINI(const char* path, T& t, VArgs&&...args);

	template<class T>
	static core::EError SerializeToJSON(const T& t, const char* path, const char* filename);
	template<class T>
	static core::EError LoadJSON(T& t, const char* path);

	template<class T>
	static core::EError SerializeToBinary(const T& t, const char* path, const char* filename);
	template<class T>
	static core::EError SerializeToBinary(const std::vector<T>& t, const char* path, const char* filename);
	template<class T, class...VArgs>
	static core::EError SerializeToBinary(const char* path, const char* filename, const T& t, VArgs&&...args);
	template<class T>
	static core::EError AddSerializeToBinary(const T& t, const char* path);
	template<class T>
	static core::EError AddSerializeToBinary(const std::vector<T>& t, const char* path);
	template<class T, class...VArgs>
	static core::EError AddSerializeToBinary(const char* path, const T& t, VArgs&&...args);
	template<class T>
	static core::EError LoadBinary(T& t, const char* path);
	template<class T>
	static core::EError LoadBinary(std::vector<T>& t, const char* path);
	template<EExtension ext, class T, class...VArgs>
	static core::EError LoadBinary(const char* path, T& t, VArgs&&...args);
};

} // namespace serialization
} // namespace drak
#include <Serialization/Serializer.inl>