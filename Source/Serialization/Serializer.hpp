#pragma once

#include <Serialization/SerializationUtils.hpp>
#include <vector>

namespace drak {
namespace serialization {

enum  E_FileOpeningMethod : U8 {
	READ,
	WRITE,
	READ_WRITE,
	APPEND,
	BINARY
};

template<class T>
void SerializeToFile(T& t, const char* path, const char* filename,
	E_FileOpeningMethod method = E_FileOpeningMethod(E_FileOpeningMethod::BINARY | E_FileOpeningMethod::WRITE)));

template<class T>
void SerializeToFile(const std::vector<T>& t, const char* path, const char* filename,
	E_FileOpeningMethod method = E_FileOpeningMethod(E_FileOpeningMethod::BINARY | E_FileOpeningMethod::WRITE));

template<class T, class...VArgs>
void SerializeToFile(const char* path, const char* filename, E_FileOpeningMethod method, T& t, VArgs&&...args);

template<class T>
void AddObjectToFile(const char* path, const char* filename, T& t);

template<class T>
void AddObjectToFile(const char* path, const char* filename, const std::vector<T>& t);

template<class T, class...VArgs>
void AddObjectToFile(const char* path, const char* filename,  T& t, VArgs&&...args);

template<class T>
T LoadFromFile(const char* path, const char* filename, const char* className);

template<class T>
void LoadFromFile(const char* path, const char* filename, T& t);

template<class T>
void LoadEveryFromFile(const char* path, const char* filename, std::vector<T>& t);

template<class T>
std::vector<T> LoadEveryFromFile(const char* path, const char* filename, const char* className);

template<class T, class...VArgs>
void LoadFromFile(const char* path, const char* filename, T& t, VArgs&&...args);

} // namespace serialization
} // namepsace drak