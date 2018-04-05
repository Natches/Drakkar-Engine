#include <Serialization/Serializer.hpp>
#include <fstream>

namespace drak {
namespace serialization {

void Serializer::FileDescriptor::writeToFile(std::fstream& file) {
	file.seekp(0, std::ios::beg);
	int size = (int)m_descriptor.size();
	m_endPos = sizeof(int) * 2;
	for (auto& x : m_descriptor)
		m_endPos += (int)(x.first.first.size() + 1  + 2 * sizeof(int));
	file.write((const char*)&(m_endPos), sizeof(int));
	file.write((const char*)&(size), sizeof(int));
	for (auto& x : m_descriptor) {
		file << x.first.first << " ";
		file.write((const char*)&(x.first.second), sizeof(int));
		file.write((const char*)&(x.second), sizeof(int));
	}
}

void Serializer::FileDescriptor::loadFromFile(std::fstream& file) {
	file.seekg(0, std::ios::beg);
	int size;
	file.read((char*)&m_endPos, sizeof(int));
	file.read((char*)&size, sizeof(int));
	for (int i = 0; i < size; ++i) {
		std::string str;
		int instanceN, position;
		file >> str;
		file.seekg(1, std::ios::cur);
		file.read((char*)&(instanceN), sizeof(int));
		file.read((char*)&(position), sizeof(int));
		m_descriptor[{str, instanceN}] = position;
	}
}

void Serializer::FileDescriptor::seekToBeginingOfClass(std::fstream& file) {
	file.seekg(m_endPos, std::ios::beg);
}

} // namespace serialization
} // namepsace drak