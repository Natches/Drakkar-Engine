#include <ResourceManager/Resource.hpp>

namespace drak {

Resource::Resource()
:	m_filename("") {}

Resource::Resource(const std::string& filename)
:	m_filename(filename) {

}


} // namespace drak