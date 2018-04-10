#pragma once

#include <string>

namespace drak {

class AResourceManager;

class AResource {
public:
	AResource(const std::string& name);

protected:
	AResourceManager*	m_pManager;
	std::string			m_name;
};


} // namespace drak