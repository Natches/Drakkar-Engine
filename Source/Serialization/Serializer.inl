#include <Serialization/Serializer.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <fstream>

namespace drak {
namespace serialization {

template<EExtension ext, class T>
core::EError Serializer::SerializeToFile(const T& t, const char* path, const char* filename) {
	core::EError err;
	if ((err = drak::io::CreateDirectory(path)) == core::EError::NO_ERROR ||
		err == core::EError::DIRECTORY_ALREADY_EXIST) {
		if constexpr(ext == EExtension::INI)
			return SerializeToINI(t, path, filename);
		else if constexpr (ext == EExtension::JSON)
			return SerializeToJSON(t, path, filename);
		else if constexpr (ext == EExtension::BINARY)
			return SerializeToBinary(t, path, filename);
	}
	return err;
}

template<EExtension ext, class T>
core::EError Serializer::SerializeToFile(const std::vector<T>& t, const char* path, const char* filename) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	core::EError err;
	if ((err = drak::io::CreateDirectory(path)) == core::EError::NO_ERROR ||
		err == core::EError::DIRECTORY_ALREADY_EXIST) {
		if constexpr(ext == EExtension::INI)
			return SerializeToINI(t, path, filename);
		else if constexpr (ext == EExtension::BINARY)
			return SerializeToBinary(t, path, filename);
	}
	return err;
}

template<EExtension ext, class T, class ...VArgs>
core::EError Serializer::SerializeToFile(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	core::EError err;
	if ((err = drak::io::CreateDirectory(path)) == core::EError::NO_ERROR ||
		err == core::EError::DIRECTORY_ALREADY_EXIST) {
		if constexpr(ext == EExtension::INI)
			return SerializeToINI(path, filename, t, std::forward<VArgs>(args)...);
		else if constexpr (ext == EExtension::BINARY)
			return SerializeToBinary(path, filename, t, std::forward<VArgs>(args)...);
	}
	return err;
}

template<EExtension ext, class T>
core::EError Serializer::AddObjectToFile(const T& t, const char* path) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI)
		return AddToINI(t, std::string(path) + ".ini");
	else if constexpr (ext == EExtension::BINARY)
		return AddToBinary(t, std::string(path) + ".bin");
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T>
core::EError Serializer::AddObjectToFile(const std::vector<T>& t, const char* path) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI)
		return AddToINI(t, std::string(path) + ".ini");
	else if constexpr (ext == EExtension::BINARY)
		return AddToBinary(t, std::string(path) + ".bin");
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T, class ...VArgs>
core::EError Serializer::AddObjectToFile(const char* path, const T& t, VArgs&& ...args) {
	static_assert(!(ext == EExtension::JSON), "Cannot add multiple object in JSON file !!");
	if constexpr(ext == EExtension::INI)
		return AddToINI(std::string(path) + ".ini", t, std::forward<VArgs>(args)...);
	else if constexpr (ext == EExtension::BINARY)
		return AddToBinary(std::string(path) + ".bin", t, std::forward<VArgs>(args)...);
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T>
std::tuple<T, core::EError> Serializer::LoadFromFile(const char* path) {
	T t;
	return std::make_tuple(t, LoadFromFile<ext, T>(path, t));
}

template<EExtension ext, class T>
core::EError Serializer::LoadFromFile(const char* path, T& t) {
	if constexpr(ext == EExtension::INI)
		return LoadFromINI((std::string(path) + ".ini").c_str(), t);
	else if constexpr (ext == EExtension::JSON)
		return LoadFromJSON((std::string(path) + ".json").c_str(), t);
	else if constexpr (ext == EExtension::BINARY)
		return LoadFromBinary((std::string(path) + ".bin").c_str(), t);
}

template<EExtension ext, class T>
core::EError Serializer::LoadEveryFromFile(const char* path, std::vector<T>& t) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			int occurence = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName())
					++occurence;
			}
			if (occurence) {
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				for (int i = 0; i < occurence; ++i) {
					binary.seekg(desc.m_descriptor
						[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), i }], std::ios::beg);
					t.emplace_back(MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize(binary.str().c_str()));
				}
				return core::EError::NO_ERROR;
			}
			file.close();
			return core::EError::CLASS_NOT_FOUND;
		}
	}
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T>
std::tuple<std::vector<T>, core::EError> Serializer::LoadEveryFromFile(const char* path) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			int occurence = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName())
					++occurence;
			}
			if (occurence) {
				std::vector<T> res;
				res.reserve(occurence);
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				for (int i = 0; i < occurence; ++i) {
					binary.seekg(desc.m_descriptor
						[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), i }], std::ios::beg);
					res.emplace_back(MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize(binary.str().c_str()));
				}
				return std::make_tuple(res, core::EError::NO_ERROR);
			}
			file.close();
			return std::make_tuple(std::vector<T>(), core::EError::CLASS_NOT_FOUND);
		}
	}
	return std::make_tuple(std::vector<T>(), core::EError::FILE_NOT_FOUND);
}

template<EExtension ext, class T, class ...VArgs>
core::EError Serializer::LoadFromFile(const char* path, T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::map<std::string, int> occurence;
			Occurence(occurence, t, std::forward<VArgs>(args)...);
			file.seekg(desc.m_descriptor
				[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			file.close();
			LoadFromFile(binary, desc, occurence, t, std::forward<VArgs>(args)...);
			return core::EError::NO_ERROR;
		}
	}
	return core::EError::FILE_NOT_FOUND;
}

template<EExtension ext, class T, class ...VArgs>
void Serializer::SerializeToFile(std::fstream& file, std::stringstream& sstr,
	FileDescriptor& desc, const T& t, VArgs&& ...args) {
	int max = 0;
	for (auto& x : desc.m_descriptor) {
		if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x.first.second > max)
			max = x.first.second;
	}
	desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
	MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Serialize<ext>(binary, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile(file, sstr, desc, std::forward<VArgs>(args)...);
}

template<EExtension ext, class T, class ...VArgs>
void Serializer::SerializeToFileNoDesc(std::fstream& file, std::stringstream& sstr, const T& t, VArgs&& ...args) {
	MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Serialize<ext>(binary, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFileNoDesc(file, sstr, std::forward<VArgs>(args)...);
}

template<class T, class ...VArgs>
void Serializer::LoadFromFile(std::stringstream& sstr, FileDescriptor& desc,
	std::map<std::string, int>& occurence, T& t, VArgs&& ...args) {
	sstr.seekg(desc.m_descriptor
		[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 
		occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName()] }], std::ios::beg);
	MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize(binary.str().c_str(), t);
	++occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName()];
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile(sstr, desc, occurence, std::forward<VArgs>(args)...);

}

template<class T, class ...VArgs>
void Serializer::Occurence(std::map<std::string, int>& occurence, const T& t, VArgs&& ...args) {
	occurence[MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName()] = 0;
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		Occurence(occurence, std::forward<VArgs>(args)...);
}

template<class T>
core::EError Serializer::SerializeToINI(const T& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename) + ".ini", std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		MetaData<T>::Serialize<EExtension::INI>(ini, t);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::SerializeToINI(const std::vector<T>& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename) + ".ini", std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		for (int i = 0, size = (int)t.size(); i < size; ++i) 
			MetaData<T>::Serialize<EExtension::INI>(ini, t[i]);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T, class ...VArgs>
core::EError Serializer::SerializeToINI(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	std::fstream file((std::string(path) + filename) + ".ini", std::ios::out);
	if (file.is_open()) {
		std::stringstream ini(std::ios::in | std::ios::out);
		SerializeToFileNoDesc<EExtension::INI>(file, ini, std::forward<VArgs>(args)...);
		file << ini.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::AddToINI(const T& t, const char* path) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path,  std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			MetaData<T>::Serialize<EExtension::INI>(ini, t);
			file << ini.rdbuf();
			file.flush();
			file.close();
			return core::EError::NO_ERROR;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
inline core::EError Serializer::AddToINI(const std::vector<T>& t, const char * path) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			for (auto& x : t)
				MetaData<T>::Serialize<EExtension::INI>(ini, x);
			file << ini.rdbuf();
			file.flush();
			file.close();
			return core::EError::NO_ERROR;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
core::EError Serializer::AddToINI(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::app);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out | std::ios::binary);
			SerializeToFileNoDesc<EExtension::INI>(file, ini, t, std::forward<VArgs>(args)...);
			file << ini.rdbuf();
			file.flush();
			file.close();
		}
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromINI(const char* path, T& t) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream ini(std::ios::in | std::ios::out);
			ini << file.rdbuf();
			file.close();
			size_t it = ini.str().find((std::string("[") + MetaData<T>::TypeName()) + "]");
			if (it != std::string::npos) {
				ini.seekg(it, std::ios::beg);
				MetaData<T>::Deserialize<EExtension::INI>(t, ini);
				return core::EError::NO_ERROR;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::SerializeToJSON(const T& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename) + ".json", std::ios::out);
	if (file.is_open()) {
		std::stringstream json(std::ios::in | std::ios::out);
		MetaData<T>::Serialize<EExtension::JSON>(json, t);
		file << json.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::LoadFromJSON(const char* path, T& t) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in);
		if (file.is_open()) {
			std::stringstream json(std::ios::in | std::ios::out);
			json << file.rdbuf();
			file.close();
			size_t it = json.str().find(std::string(MetaData<T>::TypeName()) + ":");
			if (it != std::string::npos) {
				json.seekg(it, std::ios::beg);
				MetaData<T>::Deserialize<EExtension::JSON>(t, json);
				return core::EError::NO_ERROR;
			}
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::SerializeToBinary(const T& t, const char* path, const char* filename) {
	std::fstream file(std::string(path) + filename + ".bin", std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		desc.m_descriptor[{ MetaData<T>::TypeName(), 0 }] = 0;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::Serialize<EExtension::BINARY>(binary, t);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::SerializeToBinary(const std::vector<T>& t, const char* path, const char* filename) {
	std::fstream file((std::string(path) + filename) + ".bin", std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (int i = 0, size = (int)t.size(); i < size; ++i) {
			desc.m_descriptor[{ MetaData<T>::TypeName(), i}] = (int)binary.tellp();
			MetaData<T>::Serialize<EExtension::BINARY>(binary, t[i]);
		}
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T, class ...VArgs>
core::EError Serializer::SerializeToBinary(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	std::fstream file((std::string(path) + filename) + ".bin", std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		SerializeToFile<EExtension::BINARY>(file, binary, std::forward<VArgs>(args)...);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_OPENED;
}

template<class T>
core::EError Serializer::AddToBinary(const T& t, const char* path) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			int max = 0;
			for (auto& x : desc.m_descriptor) {
				if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x.first.second > max)
					max = x.first.second;
			}
			desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
			MetaData<T>::Serialize<EExtension::BINARY>(binary, t);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return core::EError::NO_ERROR;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::AddToBinary(const std::vector<T>& t, const char* path) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			for (auto& x : t) {
				int max = 0;
				for (auto& x2 : desc.m_descriptor) {
					if (x2.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x2.first.second > max)
						max = x2.first.second;
				}
				desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
				MetaData<T>::Serialize<EExtension::BINARY>(binary, x);
			}
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return core::EError::NO_ERROR;
		}
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
core::EError Serializer::AddToBinary(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			SerializeToFile<EExtension::BINARY>(file, binary, desc, t, std::forward<VArgs>(args)...);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
		return core::EError::NO_ERROR;
	}
	return core::EError::FILE_NOT_FOUND;
}

template<class T>
core::EError Serializer::LoadFromBinary(const char* path, T& t) {
	if (drak::io::FileExists(path) == core::EError::NO_ERROR) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			if (desc.m_descriptor.find({ MetaData<T>::TypeName(), 0 }) !=
				desc.m_descriptor.end()) {
				file.seekg(desc.m_descriptor
					[{ MetaData<T>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				MetaData<T>::Deserialize<EExtension::BINARY>(t, binary);
				return core::EError::NO_ERROR;
			}
			file.close();
			return core::EError::CLASS_NOT_FOUND;
		}
		return core::EError::FILE_NOT_OPENED;
	}
	return core::EError::FILE_NOT_FOUND;
}

} // namespace serialization
} // namespace drak
