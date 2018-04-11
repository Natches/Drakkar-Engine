#pragma once

#include <string>

namespace drak {

class Resource {
public:
	Resource();

protected:
	Resource(const std::string& filename);

protected:
	std::string	m_filename;

friend class ResourceManager;
};

} // namespace drak