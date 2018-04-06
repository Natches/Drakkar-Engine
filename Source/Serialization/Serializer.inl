#include <Serialization/Serializer.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <fstream>

namespace drak {
namespace serialization {

template<class T>
drak::core::E_Error Serializer::SerializeToFile(const T& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		desc.m_descriptor[{ MetaData<T>::TypeName(), 0 }] = 0;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		MetaData<T>::serialize(binary, t);
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return drak::core::E_Error::NO_ERROR;
	}
	return drak::core::E_Error::NO_ERROR;
}

template<class T>
drak::core::E_Error Serializer::SerializeToFile(const std::vector<T>& t, const char* path, const char* filename) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		for (int i = 0, size = (int)t.size(); i < size; ++i) {
			desc.m_descriptor[{ MetaData<T>::TypeName(), i}] = (int)binary.tellp();
			MetaData<T>::serialize(binary, t[i]);
		}
		desc.writeToFile(file);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return drak::core::E_Error::NO_ERROR;
	}
	return drak::core::E_Error::NO_ERROR;
}

template<class T, class ...VArgs>
drak::core::E_Error Serializer::SerializeToFile(const char* path, const char* filename, const T& t, VArgs&& ...args) {
	drak::io::CreateDirectory(path);
	std::fstream file(std::string(path) + filename, std::ios::out | std::ios::binary);
	if (file.is_open()) {
		FileDescriptor desc;
		std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
		SerializeToFile(file, binary, std::forward<VArgs>(args)...);
		file << binary.rdbuf();
		file.flush();
		file.close();
		return drak::core::E_Error::NO_ERROR;
	}
	return drak::core::E_Error::NO_ERROR;
}

template<class T>
drak::core::E_Error Serializer::AddObjectToFile(const T& t, const char* path) {
	if (drak::io::FileExists(path)) {
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
			MetaData<T>::serialize(binary, t);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return drak::core::E_Error::NO_ERROR;
		}
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T>
drak::core::E_Error Serializer::AddObjectToFile(const std::vector<T>& t, const char* path) {
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
					if (x2.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x2.first.second > max)
						max = x2.first.second;
				}
				desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
				MetaData<T>::serialize(binary, x);
			}
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
			return drak::core::E_Error::NO_ERROR;
		}
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
drak::core::E_Error Serializer::AddObjectToFile(const char* path, const T& t, VArgs&& ...args) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::out | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
			binary << file.rdbuf();
			SerializeToFile(file, binary, desc, t, std::forward<VArgs>(args)...);
			desc.writeToFile(file);
			file << binary.rdbuf();
			file.flush();
			file.close();
		}
		return drak::core::E_Error::NO_ERROR;
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T>
std::tuple<T, drak::core::E_Error> Serializer::LoadFromFile(const char* path) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			if (desc.m_descriptor.find({ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }) !=
				desc.m_descriptor.end()) {
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				if constexpr (!std::is_pointer_v<T>)
					return std::make_tuple
					(MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize(binary.str().c_str()),
						E_Error::NO_ERROR);
			}
			file.close();
			return std::make_tuple(T(), drak::core::E_Error::CLASS_NOT_FOUND);
		}
	}
	return std::make_tuple(T(), drak::core::E_Error::FILE_NOT_FOUND);
}

template<class T>
drak::core::E_Error Serializer::LoadFromFile(const char* path, T& t) {
	if (drak::io::FileExists(path)) {
		std::fstream file(path, std::ios::in | std::ios::binary);
		if (file.is_open()) {
			FileDescriptor desc;
			desc.loadFromFile(file);
			if (desc.m_descriptor.find({ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }) !=
				desc.m_descriptor.end()) {
				file.seekg(desc.m_descriptor
					[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), 0 }] + desc.m_endPos, std::ios::beg);
				std::stringstream binary(std::ios::in | std::ios::out | std::ios::binary);
				binary << file.rdbuf();
				file.close();
				MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::Deserialize(binary.str().c_str(), t);
				return drak::core::E_Error::NO_ERROR;
			}
			file.close();
			return drak::core::E_Error::CLASS_NOT_FOUND;
		}
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T>
drak::core::E_Error Serializer::LoadEveryFromFile(const char* path, std::vector<T>& t) {
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
				return drak::core::E_Error::NO_ERROR;
			}
			file.close();
			return drak::core::E_Error::CLASS_NOT_FOUND;
		}
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T>
std::tuple<std::vector<T>, drak::core::E_Error> Serializer::LoadEveryFromFile(const char* path) {
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
				return std::make_tuple(res, drak::core::E_Error::NO_ERROR);
			}
			file.close();
			return std::make_tuple(std::vector<T>(), drak::core::E_Error::CLASS_NOT_FOUND);
		}
	}
	return std::make_tuple(std::vector<T>(), drak::core::E_Error::FILE_NOT_FOUND);
}

template<class T, class ...VArgs>
drak::core::E_Error Serializer::LoadFromFile(const char* path, T& t, VArgs&& ...args) {
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
			return drak::core::E_Error::NO_ERROR;
		}
	}
	return drak::core::E_Error::FILE_NOT_FOUND;
}

template<class T, class ...VArgs>
void Serializer::SerializeToFile(std::fstream& file, std::stringstream& sstr,
	FileDescriptor& desc, const T& t, VArgs&& ...args) {
	int max = 0;
	for (auto& x : desc.m_descriptor) {
		if (x.first.first == MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName() && x.first.second > max)
			max = x.first.second;
	}
	desc.m_descriptor[{ MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::TypeName(), max + 1 }] = (int)binary.tellp();
	MetaData<REMOVE_ALL_TYPE_MODIFIER(T)>::serialize(binary, t);
	if constexpr (static_cast<bool>(sizeof...(VArgs)))
		SerializeToFile(file, sstr, desc, std::forward<VArgs>(args)...);
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

} // namespace serialization
} // namepsace drak
