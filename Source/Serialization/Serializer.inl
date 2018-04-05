#include <Serialization/Serializer.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <fstream>

namespace drak {
namespace serialization {

template<class T>
void Serializer::SerializeToFile(const T& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		desc.m_descriptor[{ MetaData<T>::typeName(), 0 }] = 0;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
	}
}

template<class T>
void Serializer::SerializeToFile(const std::vector<T>& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (int i = 0, size = (int)t.size(); i < size; ++i) {
			desc.m_descriptor[{ MetaData<T>::typeName(), i}] = (int)binary.str().size();
			MetaData<T>::serialize(binary, t[i]);
		}
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
	}
}

template<class T, class ...VArgs>
void Serializer::SerializeToFile(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), 0 }] = 0;
		MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::serialize(binary, t);
		if constexpr (static_cast<bool>(sizeof...(VArgs)))
			SerializeToFile(file, binary, std::forward<VArgs>(args)...);
		file << binary.rdbuf();
		file.flush();
		file.close();
	}
}

template<class T>
void Serializer::AddObjectToFile(const T& t, const char* path) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			int max = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName() && x.first.second > max)
					max = x.first.second;
			}
			desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), max + 1 }] = (int)binary.str().size();
			MetaData<T>::serialize(binary, t);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
	}
}

template<class T>
void Serializer::AddObjectToFile(const std::vector<T>& t, const char* path) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			for (auto& x : t) {
				int max = 0;
				for (auto& x2 : desc.m_descriptor) {
					if (x2.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName() && x2.first.second > max)
						max = x2.first.second;
				}
				desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), max + 1 }] = (int)binary.str().size();
				MetaData<T>::serialize(binary, x);
			}
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
	}
}

template<class T, class ...VArgs>
void Serializer::AddObjectToFile(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), max + 1 }] = (int)binary.str().size();
			MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::serialize(binary, t);
			if constexpr (static_cast<bool>(sizeof...(VArgs)))
				SerializeToFile(file, binary, desc, std::forward<VArgs>(args)...);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
	}
}

template<class T>
std::tuple<T, drak::core::E_Error> Serializer::LoadFromFile(const char* path) {
	DK_IMPORT(drak::core)
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			if (desc.m_descriptor.find({ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), 0 }) !=
				desc.m_descriptor.end()) {
				file.seekg(std::ios::beg, 0);
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), 0 }] + desc.m_endPos);
				std::stringstream sstr;
				sstr << file.rdbuf();
				if constexpr (!std::is_pointer_v<T>)
					return std::make_tuple
					(MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::deserialize(sstr),
						E_Error::NO_ERROR);
			}
			return std::make_tuple(T(), E_Error::CLASS_NOT_FOUND);
		}
	}
	return std::make_tuple(T(), E_Error::FILE_NOT_FOUND);
}

template<class T>
drak::core::E_Error Serializer::LoadFromFile(const char* path, T& t) {
}

template<class T>
drak::core::E_Error Serializer::LoadEveryFromFile(const char* path, std::vector<T>& t) {
}

template<class T>
std::tuple<std::vector<T>, drak::core::E_Error> Serializer::LoadEveryFromFile(const char* path) {
	return std::vector<T>();
}

template<class T, class ...VArgs>
drak::core::E_Error Serializer::LoadFromFile(const char* path, T& t, VArgs&& ...args) {
}

template<class T, class ...VArgs>
void Serializer::SerializeToFile(std::fstream& file, std::stringstream& sstr,
	FileDescriptor& desc, const T& t, VArgs&& ...args) {
	int max = 0;
	for (auto& x : desc.m_descriptor) {
		if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName() && x.first.second > max)
			max = x.first.second;
	}
	desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::typeName(), max + 1 }] = (int)binary.str().size();
	MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::serialize(binary, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile(file, sstr, desc, std::forward<VArgs>(args)...);
}

} // namespace serialization
} // namepsace drak
