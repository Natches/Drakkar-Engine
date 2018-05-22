#include <PrecompiledHeader/pch.hpp>
#include <Video/Graphics/Geometry/Base/AMesh.hpp>

namespace drak {
namespace geom {

AMesh::AMesh(std::string&& name, I32 attributeN)
	: m_name(std::move(name)), m_attributeNumber(attributeN) {
}

} // namespace geom
} // namespace drak